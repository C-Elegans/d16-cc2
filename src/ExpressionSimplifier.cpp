//
//  ExpressionSimplifier.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/2/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "ExpressionSimplifier.hpp"
#include "Operator.hpp"
#include "NumNode.hpp"
ExpressionSimplifier::ExpressionSimplifier(){
	
}
void recurse(ASTNode* parent, ASTNode* child){
	for(int i=0;i<child->children.size();i++){
		recurse(child, child->children[i]);
	}
	if(Operator* op = dynamic_cast<Operator*>(child)){
		if(op->children.size() == 2){
			if(NumNode* num1 = dynamic_cast<NumNode*>(op->children[0])){
				if(NumNode* num2 = dynamic_cast<NumNode*>(op->children[1])){
					int result = 0;
					int val1 = num1->value;
					int val2 = num2->value;
					switch (op->type) {
						case Operator_type::ADD:
							result = val1 + val2;
							break;
						case Operator_type::SUBTRACT:
							result = val1 - val2;
							break;
						case Operator_type::MUL:
							result = val1 * val2;
							break;
						case Operator_type::DIV:
							result = val1 / val2;
							break;
                        case Operator_type::CMP_EQ:
                            result = val1 == val2;
                            break;
                        case Operator_type::CMP_NE:
                            result = val1!= val2;
                            break;
                        case Operator_type::CMP_GT:
                            result = val1 > val2;
                            break;
                        case Operator_type::CMP_GE:
                            result = val1 >= val2;
                            break;
                        case Operator_type::CMP_LE:
                            result = val1 <= val2;
                            break;
                        case Operator_type::CMP_LT:
                            result = val1 < val2;
                            break;
                        case Operator_type::O_AND:
                            result = val1 & val2;
                            break;
                        case Operator_type::O_XOR:
                            result = val1 ^ val2;
                            break;
                        case Operator_type::O_OR:
                            result = val1 | val2;
                            break;
					}
					NumNode* newNode = new NumNode(result);
					parent->replace_child(op, newNode);
				}
			}
		}
	}
}
void ExpressionSimplifier::runPass(ASTNode *ast){
	for(int i=0;i<ast->children.size();i++){
		recurse(ast,ast->children[i]);
	}
}

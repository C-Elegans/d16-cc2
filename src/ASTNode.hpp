//
//  ASTNode.hpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#ifndef ASTNode_hpp
#define ASTNode_hpp

#include <stdio.h>
#include <vector>
#include <memory>
#include "MachineInstruction.hpp"
class ASTNode {
	public:
		std::vector<ASTNode* > children;


public:
	ASTNode();
	ASTNode(ASTNode* child1);
	ASTNode(ASTNode* child1,ASTNode* child2);
	ASTNode(ASTNode* child1,ASTNode* child2,ASTNode* child3);
	~ASTNode();
	
	void add_child(ASTNode*);
	void replace_child(ASTNode* from, ASTNode* to);

	void print(int level);
	virtual void printElem(void);
	virtual std::unique_ptr<MachineInstruction> assemble(void);

};
typedef ASTNode* AST_ptr;
template<typename Base, typename T>
inline bool instanceOf(const T *ptr){
	return dynamic_cast<const Base*>(ptr) != nullptr;
}
#endif /* ASTNode_hpp */

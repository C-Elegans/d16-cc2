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

class ASTNode {
	protected:
		std::vector<std::shared_ptr<ASTNode>> children;


public:
	ASTNode();
	ASTNode(ASTNode& child1);
	ASTNode(ASTNode& child1,ASTNode& child2);
	ASTNode(ASTNode& child1,ASTNode& child2,ASTNode& child3);
	~ASTNode();
	
	void add_child(std::shared_ptr<ASTNode>);
	virtual void print(int level);
};
typedef std::shared_ptr<ASTNode> AST_ptr;

#endif /* ASTNode_hpp */

//
//  List.cpp
//  d16-cc2
//
//  Created by Michael Nolan on 7/1/16.
//  Copyright © 2016 Michael Nolan. All rights reserved.
//

#include "List.hpp"
List::List(){
	
}
List::List(std::string _name){
	name = _name;
}
void List::printElem(){
	if(!name.empty()){
		printf("%s\n",name.c_str());
	}else{
		printf("List\n");
	}
}
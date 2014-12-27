#include "Exceptions.h"
#include <iostream>

//			PopOfEmpty

//		Constuructor
PopOfEmpty::PopOfEmpty(){
}
//		Destructor
PopOfEmpty::~PopOfEmpty(){
}
//		Methods
const char *PopOfEmpty::what() const{
	return "Delete of empty list";
};

//			NonExistentElement		

//		Constuructor
NonExistentElement::NonExistentElement(){
}
//		Destructor
NonExistentElement::~NonExistentElement(){
}
//		Methods
const char *NonExistentElement::what() const{
	return "Access to a non-existent element";
};
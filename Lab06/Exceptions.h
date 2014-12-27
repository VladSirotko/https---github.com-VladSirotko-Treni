#include <exception>
#include <iostream>

class PopOfEmpty:public std::exception{
//		Method
	public:
//		Constructor
		PopOfEmpty();
//		Destructor
		virtual~PopOfEmpty();
//		Methods
		const char *what() const;
};

class NonExistentElement:public std::exception{
//		Method
	public:
//		Constructor
		NonExistentElement();
//		Destructor
		virtual~NonExistentElement();
//		Methods
		const char *what() const;
};
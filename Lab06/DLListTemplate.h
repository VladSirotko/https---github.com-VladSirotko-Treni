#include <iostream>
#include "ListIterator.h"
#include "Exceptions.h"


template <typename T>
class List{
	struct Node{
		T x;
        Node *prev,*next;
	};
    Node *first,*last;
	typedef ListIterator<Node,T> Iterator;
    friend Iterator;
	public:
		List();
		List(T x);
		List(const List &rhs);
		~List();
//		Methods
		void pushFirst(T x);
		void pushLast(T x);
        void pop(int n);
		void pop(int n,int k);
		void clear();
        void show() const;
		bool empty() const;		
//		Operators
		T & operator[](int i) const;
		List & operator=(const List<T> &rhs);
		Iterator begin() const{
			return Iterator(first);
		}
		Iterator end() const{
			return Iterator(last);
		}
};


//		Constructors

template <typename T>
List<T>::List():first(nullptr),last(nullptr){
}

template <typename T>
List<T>::List(T x):first(new Node),last(nullptr){
	first->next=nullptr;
	first->prev=nullptr;
	first->x=x;
	last=first;
}

template <typename T>
List<T>::List(const List &rhs):first(nullptr),last(nullptr){
    Node *temp=rhs.first;
    while(temp){
		List::pushLast(temp->x);
		temp=temp->next;
	}
}

//		Destructor

template <typename T>
List<T>::~List(){
    while(first){
		last=first->next;
		first=last;
	}
	first=nullptr;
	last=nullptr;
}

//		Methods

template <typename T>
void List<T>::pushFirst(T x){
    Node *temp=new Node;
	temp->prev=nullptr;
	temp->x=x;
    if(first){
		temp->next=first;
		first->prev=temp;
		first=temp;
	}
	else{
		temp->next=nullptr;
		first=temp;
		last=temp;
	}
}

template <typename T>
void List<T>::pushLast(T x){
    Node *temp=new Node;
	temp->next=nullptr;
	temp->x=x;
    if(last){
		temp->prev=last;
		last->next=temp;
		last=temp;
	}
	else{
		temp->prev=nullptr;
		first=temp;
		last=temp;
	}
}


template <typename T>
void List<T>::pop(int n){
	if(!empty()){
		if(n==0){
            if(first->next){
				first=first->next;
				first->prev=nullptr;
			}
			else{
				first=nullptr;
			}
		}
		else{
            Node *temp=first->next;
			int count=1;
            while(temp){
				if(n==count){
					temp->prev->next=temp->next;
                    if(temp->next){
						temp->next->prev=temp->prev;
					}
					else{
						last=temp->prev;
					}
					break;
				}
				temp=temp->next;
				count++;
			}
		}
	}
	else{
		throw PopOfEmpty();
	}
}

template <typename T>
void List<T>::pop(int n,int k){
	for(int i=k;i>=n;i--){
		List::pop(i);
	}	
}

template <typename T>
void List<T>::clear(){
    Node *iter=first;
	int i=0;
    while(iter){
		i++;
		iter=iter->next;
	}
	List::pop(0,i-1);
}


template <typename T>
void List<T>::show() const{
    Node *temp=first;
    while(temp){
		cout<<temp->x<<endl;
		temp=temp->next;
	}
}

template <typename T>
bool List<T>::empty() const{
    return !first;
}

//		Operators

template <typename T>
T & List<T>::operator[](int i) const{
    Node *temp=first;
	int count=0;
    while(temp){
		if(i==count){
			return temp->x;
		}
		temp=temp->next;
		count++;
	}
	if(i>count || i<0){
		throw NonExistentElement();
	}
}

template <typename T>
List<T> & List<T>::operator=(const List<T> &rhs){
    if(this!=&rhs){
		List::clear();
        Node *temp=rhs.first;
        while(temp){
			List::pushLast(temp->x);
			temp=temp->next;
		}
	}
	return *this;
}

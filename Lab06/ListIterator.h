template <typename Node, typename T>
class ListIterator{
    Node *curNode;
//		Method

	public:
//		Constuctors
		ListIterator();
        ListIterator(Node * curNode);
		ListIterator(const ListIterator &rhs);
//		Destructor
		~ListIterator();
//		Operators
		void operator++();
        void operator--();
		T operator*() const;
		T operator->() const;
        bool operator!=(const ListIterator<Node,T> &rhs) const;
};

//		Constructor

template <typename Node, typename T>
ListIterator<Node,T>::ListIterator():curNode(nullptr){
}

template <typename Node, typename T>
ListIterator<Node,T>::ListIterator(Node * curNode):curNode(curNode){
}

template <typename Node, typename T>
ListIterator<Node,T>::ListIterator(const ListIterator &rhs):curNode(rhs.curNode){
}

//		Destructor

template <typename Node, typename T>
ListIterator<Node,T>::~ListIterator(){
}

//		Operators

template <typename Node, typename T>
void ListIterator<Node,T>::operator++(){
    if(curNode->next){
		curNode=curNode->next;
	}
}



template <typename Node, typename T>
void ListIterator<Node,T>::operator--(){
    if(curNode->prev){
		curNode=curNode->prev;
	}
}


template <typename Node, typename T>
T ListIterator<Node,T>::operator*() const{
	return curNode->x;
}

template <typename Node, typename T>
T ListIterator<Node,T>::operator->() const{
	return curNode->x;
}


template <typename Node, typename T>
bool ListIterator<Node,T>::operator!=(const ListIterator<Node,T> &rhs) const{
	return curNode!=rhs.curNode;
}

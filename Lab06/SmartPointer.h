template <typename T>
class SmartPointer{
	T *ptr;
	int *count;
//		Method

	public:
//		Constuctors
		SmartPointer();
		SmartPointer(T *ptr);
		SmartPointer(const SmartPointer<T> &rhs);
//		Destructor
		~SmartPointer();
//		Operators
		SmartPointer<T> & operator=(const SmartPointer<T> &rhs);
		T * operator->() const;
		T & operator* () const;
        bool operator!=(const SmartPointer &rhs) const;
//		Methods
		bool isNullptr() const;
		
};

//		Constructors

template <typename T>
SmartPointer<T>::SmartPointer():ptr(nullptr),count(nullptr){
}

template <typename T>
SmartPointer<T>::SmartPointer(T *ptr):ptr(ptr){
	count=new int;
	*count++;
}

template <typename T>
SmartPointer<T>::SmartPointer(const SmartPointer<T> &rhs):ptr(rhs.ptr),count(rhs.count){
	*count++;
}

template <typename T>
SmartPointer<T>::~SmartPointer(){
	if(*count==1){
		*count=0;
		delete count;
		delete ptr;
		count=nullptr;		
		ptr=nullptr;		
	}
	else{
		*count--;
	}
}

//		Operators

template <typename T>
SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer<T> &rhs){
	ptr=rhs.ptr;
	count=rhs.count;
	*count++;
	return *this;
}

template <typename T>
T * SmartPointer<T>::operator->() const{
	return ptr;
}

template <typename T>
T & SmartPointer<T>::operator*() const{
	return *ptr;
}


template <typename T>
bool SmartPointer<T>::operator!=(const SmartPointer &rhs) const{
	return ptr!=rhs.ptr;
}

//		Methods

template <typename T>
bool SmartPointer<T>::isNullptr() const{
	return ptr?true:false;
}


template <class T>
class Node{
	
public:
	Node<T>(T _data, Node<T> *_next);
	~Node<T>();

private:	
	T		data;
	Node<T>	*next;

public:
	void 	set_data(T _data);
	T		get_data();
	void		set_next(Node<T> *_next);
	Node<T>*	get_next();
};

template <class T>
Node<T>::Node(T _data, Node<T> *_next){
	data = _data;
	next = _next;
}

template <class T>
Node<T>::~Node(){
	
}

template <class T>
void Node<T>::set_data(T _data){
	data = _data;
}

template <class T>
T Node<T>::get_data(){
	return data;
}

template <class T>
void Node<T>::set_next(Node<T> *_next){
	next = _next;
}

template <class T>
Node<T>* Node<T>::get_next(){
	return next;
}





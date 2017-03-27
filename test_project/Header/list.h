
#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>

template <class T>
class list{

public:
	list<T>();
	~list<T>();

private:
	Node<T>		*head;
 
public:
	//Gets the length of the list by iterating through it until a NULL next pointer
	unsigned int	length();
	//Returns whether or not head pointer is equal to NULL
	bool			empty();
	//Returns whether or not *_pos* is out of range
	bool			valid_pos(unsigned int _pos);
	/*Iterates through the list until finding the node at position *_pos* and makes the next pointer in the previous node point to a new node
	/while making the new node's next pointer point to the following node (given the next node is not NULL and that *_pos* is NOT greater than
	/length()*/
	void 		insert(unsigned int _pos, T _data);
	/*Acts in the same manner as insert() except freeing the node at *_pos* and making the previous node's next pointer point to the following 
	/node of the node that was just freed*/
	//NEEDS WORKED ON!!!!
	void 		remove(unsigned int _pos);
	void			remove(T _data);
	T			get(unsigned int _pos);
	void			push_node(T _data);
	void			pop_node(T _data);
	void			clear();

private:
	Node<T>*	create_node(T _data);
};

template <class T>
list<T>::list() : head(0){
	
}

template <class T>
list<T>::~list(){
	printf("-*Running list desctructor*-\n");
	clear();
}

template <class T>
unsigned int list<T>::length(){
	unsigned int length = 0;
	Node<T> *current_node;
	current_node = head;
	
	if(!empty()){
		length++;

		while(current_node->get_next() != 0){
			current_node = current_node->get_next();
			length++;
		}//end while
	}//end if
	return length;
}

template <class T>
bool list<T>::empty(){
	return (head == 0);
}

template <class T>
bool list<T>::valid_pos(unsigned int _pos){
	return (_pos < length());
}

template <class T>
void list<T>::insert(unsigned int _pos, T _data){
	Node<T> *current_node;
	Node<T> *previous_node;
	Node<T> *new_node;
	current_node = head;

	if(!empty()){
		if((_pos == 0 ? !valid_pos(_pos) : !valid_pos(_pos - 1))){
			throw std::out_of_range("position exceeds list length");
		}
	
		if(_pos == 0){
			head = create_node(_data);
			head->set_next(current_node);
		}else{
			unsigned int current_pos = 0;
			while(current_pos != _pos){
				previous_node = current_node;
				current_node = current_node->get_next();
				current_pos++;
			}
			
		new_node = create_node(_data);
		previous_node->set_next(new_node);
		new_node->set_next(current_node);
		}
	}else if(empty() && _pos == 0){
		head = create_node(_data);
	}else if(empty() && _pos > 0){
		throw std::out_of_range("List is empty, insert at the front please");
	}
}

//NEEDS WORKED ON!!!!!
template <class T>
void list<T>::remove(unsigned int _pos){
	Node<T> *current_node;
	Node<T> *previous_node;
	current_node = head;
	
	if(!empty()){
		if(!valid_pos(_pos)){
			throw std::out_of_range("Attempting to remove an element that doesn't exist");
		}
		
		unsigned int current_pos = 0;
		while(current_pos != _pos){
			previous_node = current_node;
			current_node = current_node->get_next();
		}
		
		
		if(current_node->get_next() != 0){
			if(previous_node != 0){
				previous_node.set_next(current_node->get_next());
			}

			if(_pos == 0){
				head = current_node->get_next();
			}
		}
		
		free(current_node);
	}
}

template <class T>
void list<T>::remove(T _data){
	
}

template <class T>
T list<T>::get(unsigned int _pos){
	if(!valid_pos(_pos)){
		throw std::out_of_range("Getting data: position exceeds list length");
	}

	Node<T> *current_node;
	current_node = head;

	unsigned int current_pos = 0;

	while(current_pos != _pos){
		current_node = current_node->get_next();
		current_pos++;
	}

	return current_node->get_data();
}

template <class T>
void list<T>::push_node(T _data){
	Node<T> *current_node;
	current_node = head;

	if(!empty()){
		while(current_node->get_next() != 0){
			current_node = current_node->get_next();
		}

		current_node->set_next(create_node(_data));
		
	}else{
		head = create_node(_data);
	}
}

template <class T>
void list<T>::pop_node(T _data){
	
}

template <class T>
void list<T>::clear(){
	Node<T> *current_node;
	Node<T> *previous_node;
	current_node = head;
	
	if(!empty()){
		while(current_node->get_next() != 0){
			previous_node = current_node;
			current_node = current_node->get_next();
			free(previous_node);
		}
	}
}	

template <class T>
Node<T>* list<T>::create_node(T _data){
	Node<T> *new_node = (Node<T>*)malloc(sizeof(Node<T>));
	new_node->set_data(_data);
	new_node->set_next(0);
	return new_node;
}

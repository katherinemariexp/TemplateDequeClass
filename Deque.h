#ifndef DEQUE_H
#define DEQUE_H

#include <bits/stdc++.h> 
#include <iostream>


using namespace std;

template<class T>
class Node  { 
public:
	T data; 
	Node<T> *prev, *next; 
	static Node<T>* getnode(int data) { 
		Node<T>* n = new Node<T>; 
		n->data = data; 
		n->prev = n->next = nullptr; 
		return n; 
	} 
}; 

// A doubly linked list deque 
template<class T>
class Deque { 
	Node<T> *head, *tail, *copy; 
	int size; 
	
	// deep copy helper, this private helper creates a local duplicated Deque pointed by *copy
	void deepCopy( const Deque<T> & rhs );
public: 
	Deque():head(nullptr), tail(nullptr), size(0) { } 
	Deque( const Deque<T> & rhs ); // copy constructor
	Deque( Deque<T> && rhs );		// move constructor
	
	Deque<T> & operator= ( Deque<T> & rhs ); // copy operator=
	Deque<T> & operator= ( Deque<T> && rhs ); // move operator=
	
	// Operations on Deque 
	void pushHead(T data); 
	void pushTail(T data); 
	void popHead(); 
	void popTail(); 

	void erase();
	T getFront();
	T getRear();
	int _size() { return size; }
	bool isEmpty() { return !head; }
	T& operator[] (const int &sub);
}; 

template<class T>
void Deque<T>::deepCopy( const Deque<T> & rhs ) {
	Node<T> *newNode = new Node<T>; 
	Node<T> *current = rhs.head; //current points to the list to be copied
	size = rhs.size;//copy the head node
	copy = newNode; //create the node
	copy->data = current->data; //copy the info
	copy->next = current->next; //set the link field of the node to nullptr
	copy->prev = current->prev;
	tail = head; //make tail point to the head node

	current = current->next; //make current point to the next node
	//copy the remaining list
	while (current != nullptr) {
		newNode = new Node<T>; //create a node
		newNode->data = current->data; //copy the info
		newNode->next = current->next;
		newNode->prev = current->prev;
		tail->next = newNode;
		tail = newNode;
		current = current->next;
	}
}
// complete the rest of definitions below

#endif
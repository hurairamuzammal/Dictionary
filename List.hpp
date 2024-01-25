#pragma once

// Assistive LIST ADT to be used later in the project

typedef unsigned int uint;



template<class T>
class ListNode {
public:
	T m_data;
	ListNode<T>* m_next;


	ListNode(const T& initData = T());
};



// List ADT
// with Linked List implementation

template<class T>
class List {
public:
	List();
	// preCondition: size has  avalid value
	// postCondition: returns the size of the current initialized list
	uint getSize() const;

	// postCondition: pushes the given data into the list
	void push(const T& elm);

	// postCondition: removes the value at the last from the list
	// and also returns the poped value
	T pop();

	// postCondition: removes the value at the first from the list
	T shift();
	bool isEmpty() const;

	void clear();

	void operator = (const List<T>& rhs);

private:
	uint size;
	ListNode<T>* head, *rear;
};

// include the declaration file too when separating template definition over multiple files (requirement) 
#include "List.cpp"


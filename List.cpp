#pragma once

// List.cpp
#include "List.hpp"
#include <iostream>
using namespace std;


// ListNode
// constructor
template<class T>
ListNode<T>::ListNode(const T& initData) {
	m_data = initData;
	m_next = nullptr;
}



// List

// default constructor

template <class T>
List<T>::List() {
	size = 0;
	head = nullptr;
	rear = nullptr;
}

template<class T>
uint List<T>::getSize() const {
	return size;
}

template<class T>
void List<T>::push(const T& elm) {
	// Implementation of push
	// insert at the end of the list

	// if list is empty
	if (head == nullptr) {
		head = new ListNode<T>(elm);
		rear = head;
	}
	else {
		rear->m_next = new ListNode<T>(elm);
		rear = rear->m_next;
	}

	size++;
}

template<class T>
T List<T>::pop() {
	// Implementation of pop
	// remove from the end of the list

	// if list is empty
	if (head == nullptr) {
		cout << "List is empty" << endl;
		return T();
	}
	else {
		ListNode<T>* curr = head;
		ListNode<T>* prev = nullptr;

		// traverse the list until we reach the end
		while (curr->m_next != nullptr) {
			prev = curr;
			curr = curr->m_next;
		}

		// if there is only one element in the list
		if (prev == nullptr) {
			head = nullptr;
			rear = nullptr;
		}
		else {
			prev->m_next = nullptr;
			rear = prev;
		}

		size--;
		return curr->m_data;
	}
}

template <class T>
T List<T>::shift() {
	// Implementation of shift
	// remove from the beginning of the list

	// if list is empty
	if (head == nullptr) {
		cout << "List is empty" << endl;
		return T();
	}
	//


	else {
		ListNode<T>* curr = head;
		head = head->m_next;
		size--;
		T temp = curr->m_data;
		delete curr;
		return temp;
	}
}

template<class T>
bool List<T>::isEmpty() const {
	// Implementation of isEmpty
	// check if the list is empty

	// if list is empty
	return (head == nullptr);
}

template<class T>
void List<T>::clear() {
	// Implementation of clear
	// remove all elements from the list

	// if list is empty
	if (head == nullptr) {
		cout << "List is empty" << endl;
	}
	else {
		ListNode<T>* curr = head;
		ListNode<T>* prev = nullptr;

		// traverse the list until we reach the end
		while (curr != nullptr) {
			prev = curr;
			curr = curr->m_next;
			delete prev;
		}

		head = nullptr;
		rear = nullptr;
		size = 0;
	}
}


template<class T>
void List<T>::operator = (const List<T>& rhs) {
	// Implementation of operator =
	// copy the contents of rhs into this list

	// if rhs is empty
	if (rhs.head == nullptr) {
		head = nullptr;
		rear = nullptr;
		size = 0;
	}
	else {
		ListNode<T>* curr = rhs.head;
		ListNode<T>* prev = nullptr;

		// traverse the list until we reach the end
		while (curr != nullptr) {
			// if there is only one element in the list
			if (prev == nullptr) {
				head = new ListNode<T>(curr->m_data);
				rear = head;
			}
			else {
				rear->m_next = new ListNode<T>(curr->m_data);
				rear = rear->m_next;
			}

			prev = curr;
			curr = curr->m_next;
		}

		size = rhs.size;
	}
}
#pragma once
#ifndef _COLLECTION_H_
#define _COLLECTION_H_
#include "Collection.h"
#endif
template<class T>
class LinkedList : public List<T> {
	class node {
	public:
		node* next;
		node* prev;
		T data;
		node() {
			next = nullptr;
			prev = nullptr;
		}
	};
	node* first;
	node* last;
public:
	LinkedList() {
		list_size = 0;
		first = last = nullptr;
	}
	LinkedList(T& elem) {
		first = last = new node;
		first->next = first->prev = nullptr;
		last->next = last->prev = nullptr;
		first->data = last->data = elem;
		list_size = 1;
	}
	int size() {
		return list_size;
	}
	bool is_empty() {
		if (list_size != 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void add(T& elem) {//Adding to thge end of the list
		if (list_size == 0) {
			first = last = new node;
			first->next = first->prev = nullptr;
			last->next = last->prev = nullptr;
			first->data = last->data = elem;
			++list_size;
		}
		else {
			node* tmp = new node;
			tmp->data = elem;
			tmp->prev = first;
			tmp->next = nullptr;
			last->next = tmp;
			last = tmp;
			++list_size;
		}
	}
	void push_forward(T& elem) {
		if (list_size == 0) {
			first = last = new node;
			first->next = first->prev = nullptr;
			last->next = last->prev = nullptr;
			first->data = last->data = elem;
			++list_size;
		}
		else {
			node* tmp = new node;
			tmp->data = elem;
			tmp->next = first;
			tmp->prev = nullptr;
			first->prev = tmp;
			first = tmp;
			++list_size;
		}
	}
};

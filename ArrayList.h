#pragma once
#ifndef _COLLECTION_H_
#define _COLLECTION_H_
#include "Collection.h"
#endif

const int init_ArrayList_size = 100;
const double realloc_coef = 1.5;

template<class T>
class ArrayList : public List<T> {
	T* array_list;
	int reserved_memory;
public:
	int size() {
		return list_size;
	}
	bool is_empty() {
		if (list_size == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	ArrayList() {
		reserved_memory = init_ArrayList_size;
		array_list = new T[reserved_memory];
		list_size = 0;
	}
	ArrayList(T& elem) {
		reserved_memory = init_ArrayList_size + 1;
		array_list = new T[reserved_memory];
		array_list[0] = elem;
		list_size = 1;
	}
	void add(T& elem) {
		soft_realloc_mem();
		array_list[list_size] = elem;
		list_size++;
	}
	//May be optimised by reserving free space at begin of array_list for adding elems to the begin
	void push_forward(T& elem) {
		int new_mem_size = reserved_memory + 1;
		T* new_mem = new T[new_mem_size];
		for (int i = 0; i < list_size; i++) {
			new_mem[i + 1] = array_list[i];
		}
		delete array_list;
		array_list = new_mem;
		reserved_memory = new_mem_size;
		new_mem[0] = elem;
		return;
	}
	//Reallocs mem if it's needed and returns new memory size
	int soft_realloc_mem() {
		if (reserved_memory > list_size) {
			return 0;
		}
		else {
			return hard_realloc_mem();
		}
	}
	//Always reallocs memory (and returns new memory size)
	int hard_realloc_mem() {
		int new_mem_size = reserved_memory*realloc_coef;
		T* new_mem = new T[new_mem_size];
		for (int i = 0; i < list_size; i++) {
			new_mem[i] = array_list[i];
		}
		delete array_list;
		array_list = new_mem;
		reserved_memory = new_mem_size;
		return reserved_memory;
	}
	T operator[](int index){
		if ((index >= 0) && (index < list_size)) {
			return array_list[index];
		}
		else {
			return 0;
		}
	}
};

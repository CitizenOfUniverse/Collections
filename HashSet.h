#pragma once
#ifndef _COLLECTION_H_
#define _COLLECTION_H_
#include "Collection.h"
#endif

static const int init_hashset_size = 16;

template<class T>
class HashSet : public Set<T> {
	T** bucket_table;
	int hashset_size;
	HashSet() {
		hashset_size = init_hashset_size;
		bucket_table = new T*[hashset_size];
		for (int i = 0; i < hashset_size; i++) {
			bucket_table[i] = nullptr;
		}
	}
	int size() {
		return set_size;
	}
	bool is_empty() {
		if (set_size != 0) {
			return true;
		}
		else {
			return false;
		}
	}
	void add(T& elem) {//Adding to the end of the list
		
	}
	int realloc_table
};

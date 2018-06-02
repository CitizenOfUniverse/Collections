#pragma once
#ifndef _COLLECTION_H_
#define _COLLECTION_H_
#include "Collection.h"
#endif
#ifndef _CRC32_H_
#define _CRC32_H_
#include "crc32.h"
#endif

//Number of buckets in bucket_table
static const int init_buckets_num = 16;
//Minimal (set_size/buckets_num) ratio to realloc bucket_table with full_realloc_coef
static const double fullness_det = 0.8;
//Coefficient of allocated memory incrementation on fullness
static const double full_realloc_coef = 1.5;
//Coefficient of allocated memory incrementation in case bucket_table is not full,
//but it is needed on realloc
static const double standart_realloc_coef = 1.2;

template<class T>
class HashSet : public Set<T> {
	T** buckets_table;
	int buckets_num;
	uint32_t hash(T& elem) {
		crc32 hash_obj;
		hash_obj.ProcessCRC(&elem, sizeof(elem));
		return (hash_obj.m_crc32)% buckets_num;
	}
	int realloc_table() {
		int new_buckets_num;
		if ((double)set_size / (double)buckets_num >= fullness_det) {
			new_buckets_num = buckets_num * full_realloc_coef;
		}
		else {
			new_buckets_num = buckets_num * standart_realloc_coef;
		}
		T** new_buckets_table = new T*[new_buckets_num];
		for (int i = 0; i < new_buckets_num; i++) {
			new_buckets_table[i] = nullptr;
		}
		for (int i = 0; i < buckets_num; i++) {
			if (buckets_table[i] != nullptr) {
				new_buckets_table[hash(*(buckets_table[i]))] = buckets_table[i];
				//delete buckets_table[i];
			}
		}
		delete buckets_table;
		buckets_table = new_buckets_table;
		buckets_num = new_buckets_num;
		return buckets_num;
	}
public:
	HashSet() {
		buckets_num = init_buckets_num;
		buckets_table = new T*[buckets_num];
		for (int i = 0; i < buckets_num; i++) {
			buckets_table[i] = nullptr;
		}
		set_size = 0;
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
		int elem_hash_old = hash(elem);
		if (buckets_table[elem_hash_old] != nullptr) {
			realloc_table();
			buckets_table[hash(elem)] = new T;
			//Copying constructor of T is needed here
			*(buckets_table[hash(elem)]) = elem;
		}
		else {
			buckets_table[elem_hash_old] = new T;
			//Copying constructor of T is needed here
			*(buckets_table[elem_hash_old]) = elem;
		}
		set_size++;
		return;
	}
};

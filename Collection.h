#pragma once
template<class T>
class Collection {
public:
	//virtual void clear() = 0;
	virtual int size() = 0;
	virtual bool is_empty() = 0;
	virtual void add(T&) = 0;
};
template<class T>
class List : public Collection<T>{
public:
	int list_size;
	virtual void push_forward(T& elem) = 0;
};
template<class T>
class Set : public Collection<T> {
public:
	int set_size;
	//virtual void push_forward(T& elem) = 0;
};
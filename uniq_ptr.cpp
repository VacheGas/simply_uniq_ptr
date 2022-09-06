//
//  uniq_ptr.cpp
//  uniq_ptr
//
//  Created by Vache Gasparyan on 06.09.22.
//

#include <iostream>
#include <memory>
template <typename T>
class uniq_ptr {

public:
	uniq_ptr(const uniq_ptr&) = delete;
	
	uniq_ptr() {
		ptr = nullptr;
	}
	
	uniq_ptr(T arg) : ptr(new T(arg)) {}
	
	uniq_ptr(uniq_ptr&& arg) : ptr(arg.ptr) { arg.ptr = nullptr; }
	
	~uniq_ptr() {
		if (ptr) {
			delete ptr;
			ptr = nullptr;
		}
	}
	
	T &operator [](int idx){
		return ptr[idx];
	}
	
	T& operator *() {
		return  *ptr;
	}
	
	T* operator-> () {
		return  ptr;
	}
	
private:
	T *ptr;
};

#ifndef INCLUDE_CUSTOMSTACK_H_
#define INCLUDE_CUSTOMSTACK_H_

#include <stdio.h>
#include <string>

using namespace std;

template <class T>
class CustomStack {
private:
	T* data;
	int Top;
	int size;
public:
	CustomStack() {
		data = new T[200];
		size = 200;
		Top = -1;
	}
	CustomStack(int size) {
		size < 1 ? throw string("Negative value") : NULL;
		data = new T[size];
		this.size = size;
		Top = -1;
	}

	CustomStack<T>& operator=(const CustomStack<T>& stk) {
		data = stk.data;
		size = stk.size;
		Top = stk.Top;

		return *this;
	}

	T& operator[] (int index) {
		return data[index];
	}

	void push(T value) {
		if (isFull()) {
			T* newData = new T[size + 1];
			for (int i = 0; i < size; i++) {
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
			size++;
		}
		Top++;
		data[Top] = value;
	}

	T pop() {
		isEmpty() ? throw string("Stack is empty") : NULL;
		T tmp = data[Top];
		T* newData = new T[size - 1];
		for (int i = 0; i < size - 1; i++) {
			newData[i] = data[i];
		}
		Top--;
		size--;
		delete[] data;
		data = newData;
		return tmp;
	}

	bool isFull() {
		return Top == size - 1;
	}

	bool isEmpty() {
		return Top == -1;
	}

	T top() {
		return data[Top];
	}
};

#endif
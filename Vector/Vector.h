#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

template<class T>
class Vector {
public:

	class iterator {
	private:

		T* valPtr;

	public:
		
		iterator(T* value) {
			this->valPtr = value;
		}

		bool operator==(const iterator& other) const {
			return valPtr == other.valPtr;
		}

		bool operator!=(const iterator& other) const {
			return valPtr != other.valPtr;
		}

		T operator*() {
			return *valPtr;
		}

		iterator& operator++() {
			valPtr++;
			return *this;
		}

		iterator operator++(int) {
			iterator ptr(valPtr);
			valPtr++;
			return ptr;
		}
	};

	iterator begin() {
		return iterator(arr);
	}

	iterator end() {
		return iterator(arr + size);
	}

private:

	T* arr;
	size_t size;
	size_t capacity;

public:

	// Constructor default
	Vector() : arr(nullptr),capacity(0), size(0) {};

	// Copy constructor
	Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
		arr = new T[other.capacity];

		for (size_t i = 0; i < size; i++) {
			arr[i] = other.arr[i];
		};
	};

	// operator= overload
	Vector& operator=(Vector& other) {
		if (this == &other)
			return *this;

		clear();
		reserve(other.capacity);
		size = other.size;

		for (size_t i = 0; i < size; i++) {
			arr[i] = other.arr[i];
		}

		return *this;
	}

	int getSize() {
		return size;
	}

	int getCapacity() {
		return capacity;
	}

	bool empty() {
		return size == 0;
	}

	// Use only when capacity of vector should be increased
	void reserve(size_t newCapacity) {
		if (newCapacity > capacity) {
			T* newArr = new T[newCapacity];

			for (size_t i = 0; i < size; i++) {
				newArr[i] = this->arr[i];
			}

			delete[] this->arr;
			this->arr = newArr;
			this->capacity = newCapacity;
		}
	}

	void push_back(T value) {
		if (size >= capacity) {
			size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
			reserve(newCapacity);
			arr[size] = value;
			size++;
		}
	}

	// operator[] overload
	T& operator[](size_t index) {
		if (index >= size) {
			throw out_of_range("Vector::index out of range");
		}

		return arr[index];
	}

	// deletes the arr inside the vector and sets apropriate size, capacity.
	void clear() {
		delete[] arr;
		arr = nullptr;
		size = 0;
		capacity = 0;
	}

	// Member function to swap the contents of two vectors
	void swap(Vector& other) noexcept {
		swap(size, other.size);
		swap(capacity, other.capacity);
		swap(data, other.data);
	};

	// Destructor
	~Vector() {
		delete[] arr;
	}
};

#endif // !VECTOR_H

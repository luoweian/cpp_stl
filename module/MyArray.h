#pragma once
#include<iostream>

template<typename T>
class MyArray
{
public:
	MyArray(int capacity) {
		this->mCapacity = capacity;
		this->mSize = 0;
		this->pAddr = new T[this->mCapacity];
	}
	MyArray(const MyArray<T>& arr) {
		this->mSize = arr.mSize;
		this->mCapacity = arr.mCapacity;
		this->pAddr = new T[this->mCapacity];
		for (int i = 0; i < mSize; i++) {
			this->pAddr[i] = arr.pAddr[i];
		}
	}
	T& operator[](int index) {
		return this->pAddr[index];
	}
	MyArray<T> operator=(const MyArray<T>& arr) {
		if (this->pAddr != NULL) {
			delete[] this->pAddr;
		}
		this->mSize = arr.mSize;
		this->mCapacity = arr.mCapacity;
		this->pAddr = new T[this->mCapacity];
		for (int i = 0; i < mSize; i++) {
			this->pAddr[i] = arr.pAddr[i];
		}

		return *this;
	}
	void PushBack(T& data) {
		if (this->mSize >= this->mCapacity) return;
		// 这里的 = 调用 拷贝构造或 =操作符
		// 1. 对象元素必须能够被拷贝
		// 2. 容器都是值语义，而非引用语义  向容器中放元素，都是放的元素的拷贝
		// 3. 如果元素成员有指针，注意深拷贝和浅拷贝问题
		this->pAddr[this->mSize] = data;
		this->mSize++;
	}

	void PushBack(T&& data) {
		if (this->mSize >= this->mCapacity) return;
		this->pAddr[this->mSize] = data;
		this->mSize++;
	}

	~MyArray() {
		if (this->pAddr != NULL) {
			delete[] this->pAddr;
		}
	}

public:
	int mCapacity;
	int mSize;
	T* pAddr; // 保存数据的首地址

};



void test_my_array() {
	MyArray<int> marray(20);
	int a = 10, b = 20, c = 30, d = 40;
	marray.PushBack(a);
	marray.PushBack(b);
	marray.PushBack(c);
	marray.PushBack(d);
	marray.PushBack(100);

	for (int i = 0; i < marray.mSize; i++) {
		std::cout << marray[i] << " " << std::endl;
	}
}


class Person{};

void test_my_array_02() {
	Person p1, p2;
	MyArray<Person> arr(10);
	arr.PushBack(p1);
	arr.PushBack(p2);
}

int main() {
	test_my_array();
	test_my_array_02();
}
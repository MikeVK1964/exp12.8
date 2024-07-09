#pragma once
#include <iostream>

using namespace std;

//using List_int = MkList<int>;  // Страуструп 7.4.2 Псевдонимы
template <class T>
class MkList {

public:
		class ListNode {
		public:
			T data;
			ListNode* nextPtr;

		};

	void Insert( T value) {
		ListNode* newPtr;
		ListNode* previosPtr = nullptr;
		try {
			newPtr = new ListNode();
			newPtr->data = value;
		}
		catch (...) {
			cout << "Ошибка создания элемента";
			return;
		}
		ListNode* curPtr = StartPtr; //элемент, у которого значение больше

		while (curPtr!=nullptr &&  value > curPtr->data) {
			previosPtr = curPtr;
			curPtr = curPtr->nextPtr;
		}
		if (previosPtr == nullptr) {
			StartPtr = newPtr;
			newPtr->nextPtr= curPtr;
		}
		else {
			previosPtr->nextPtr = newPtr;
			newPtr->nextPtr = curPtr;
		}
		count++;
	};
	void Delete(T value) {
		if (count == 0) return;
		ListNode* curPtr = StartPtr;
		ListNode* previosPtr = nullptr;

		if (curPtr != nullptr && curPtr->data != value)
		{
			previosPtr = curPtr;
			curPtr = curPtr->nextPtr;
		}
		if (curPtr != nullptr) {
			if (previosPtr != nullptr) previosPtr->nextPtr = curPtr->nextPtr;
			delete curPtr;
			count--;
			if (count==0) StartPtr = nullptr;
		}

	}
	void PrintList() {
		ListNode* curPtr = StartPtr;
		if (curPtr == nullptr) {
			cout << "Список пуст";
			return;
		}
		while (curPtr != nullptr) {
			cout << curPtr->data << " ";
			curPtr = curPtr->nextPtr;
		}
	}
	void concatenate(ListNode* curPtr) {
		while (curPtr != nullptr) {
			Insert(curPtr->data);
			curPtr = curPtr->nextPtr;
		}

	}
	ListNode* StartPtr=nullptr;
	size_t count = 0; 
};

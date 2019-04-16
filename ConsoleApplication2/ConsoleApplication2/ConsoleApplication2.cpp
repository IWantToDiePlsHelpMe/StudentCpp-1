#include "pch.h"
#include <iostream>
#include <string.h>

using namespace std;

template<typename T>
class List {
public:
	void addFirst(T book) {
		Node<T> *temp = new Node<T>;
		temp->data = book;
		temp->next = NULL;
		//temp->prev = NULL;

		if (head == NULL) {
			head = temp;
			return;
		}
		temp->next = head;
		//head->prev = temp;
		head = temp;
	}
	void print() {
		Node<T> *temp = head;
		while (temp != nullptr) {
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
	//void clear() {
	//	while(head != nullptr) {
	//		delete[] head->data.name;
	//		Node* temp = head;
	//		head = head->next;
	//		delete temp;
	//	}
	//}
private:
	template<typename T>
	class Node {
	public:
		T data;
		Node* next;
		//Node* prev;
	};
	Node<T>* head = nullptr;
};

void main()
{
	int size = 2;
	List<int> list;
	for (int i = 0; i < size; i++) {
		int book;


		cout << "Book " << i << ". Year: ";
		cin >> book;

		list.addFirst(book);
	}
	list.print();
	//list.clear();
}
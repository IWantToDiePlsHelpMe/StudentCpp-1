#include "pch.h"
#include <iostream>
#include <string.h>

using namespace std;


class Book {
public:
	char* name;
	unsigned int year;
};
template<typename T>
class List {
public:
	~List() {
		while (head != nullptr) {
			Node<T>* next = head->next;
			delete head;
			head = next;
		}
	}
	void addFirst(T book) {
		Node<T> *temp = new Node<T>;
		temp->data = book;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			return;
		}
		temp->next = head;
		head = temp;
	}
	void getNode() {

	}
	void print() {
		Node<T> *temp = head;
		while (temp != nullptr) {
			cout << temp->data.name << " (" << temp->data.year << ")" << endl;
			temp = temp->next;
		}
	}
private:
	template<typename T>
	class Node {
	public:
		T data;
		Node* next;
	};
	Node<T>* head = nullptr;
};

int main()
{
	int size = 2;
	List<Book> list;
	for (int i = 0; i < size; i++) {
		Book book;

		char* in = new char[10];
		cout << "Book " << i << ". Name: ";
		cin >> in;

		book.name = new char[strlen(in) + 1];
		strcpy_s(book.name, 11, in);
		book.name[strlen(in)] = '\0';
		cout << "Book " << i << ". Year: ";
		cin >> book.year;

		list.addFirst(book);
	}
	list.print();
	return 0;
}
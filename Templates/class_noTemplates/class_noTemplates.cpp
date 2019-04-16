#include "pch.h"
#include <iostream>
#include <string.h>

using namespace std;

class Book {
public:
	char* name;
	unsigned int year;
};

class List {
public:
	void addFirst(Book book) {
		Node* temp = new Node;
		temp->data = book;
		temp->next = NULL;

		if (head == NULL) {
			head = temp;
			return;
		}
		temp->next = head;
		head = temp;
	}
	void print() {
		Node *temp = head;
		while (temp != nullptr) {
			cout << temp->data.name << " (" << temp->data.year << ")" << endl;
			temp = temp->next;
		}
	}
	void clear() {
		while (head != nullptr) {
			delete[] head->data.name;
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
private:

	class Node {
	public:
		Book data;
		Node* next;
	};
	Node* head = nullptr;
};

int main()
{
	int size = 3;
	List list;
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
}
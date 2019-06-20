#include "pch.h"
#include <iostream> 
#include <string>
#include <fstream>

using namespace std;

class Node {
	string name;
	string year;
	string city;
public:
	Node() {
		name = "";
		year = "";
		city = "";
	}
	Node(string name, string year, string city) : name(name), year(year), city(city) {
	}
	friend ostream& operator<<(ostream& os, Node& n)
	{
		return os << "Name - " << n.name << " Year - " << n.year << " City - " << n.city;
	}
};


template<class T>
class Queue {
	struct Elem {
		T obj;
		unsigned int prior;
		Elem* next;
	};
	Elem* head1;
	Elem* head;
	Elem* last;
	Elem* iterator;
public:
	Queue() : head(nullptr) {}

	void push(T val, unsigned int prior) {
		if (head == nullptr) {
			head = new Elem;
			head->obj = val;
			head->prior = prior;
			head->next = nullptr;
			last = head;
		}
		else {
			head1 = head;
			if (prior > head->prior) {
				head = new Elem;
				head->next = head1;
				head->next->obj = head1->obj;
				head->next->prior = head1->prior;
				head->obj = val;
				head->prior = prior;
			}
			else {
				if (prior <= last->prior) {
					last->next = new Elem;
					last->next->obj = val;
					last->next->prior = prior;
					last->next->next = nullptr;
					last = last->next;
				}
			}
		}
	}
	void pop() {
		if (head == nullptr) {
			cout << "Queue is empty";
		}
		else {
			head = head->next;
		}
	}
	void begin() {
		iterator = head;
	}
	void next()
	{
		iterator = iterator->next;
	}
	unsigned int showprior() {
		return iterator->prior;
	}
	T& getCurrent()
	{
		return iterator->obj;
	}
	bool isEnd()
	{
		return iterator == nullptr;
	}
};

int main()
{
	Queue<Node> q;
	int choice;
	string name, city, year;
	unsigned int prior;
	fstream fout;
	ifstream file_check("file.txt", ios::in);
	if (file_check.peek() != ifstream::traits_type::eof()) {
		while (true) {
			file_check >> name;
			file_check >> year;
			file_check >> city;
			file_check >> prior;
			if (file_check.eof()) break;
			q.push(Node(name, year, city), prior);
		}
	}
	do {
		cout << "Choose what you want to do 1) Push 2) Pop 3) Show 4) Save and Exit : ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter application" << endl;
			fout.open("file.txt", ios::out | ios::app);
			cout << "Name - "; cin >> name;
			cout << "Year - "; cin >> year;
			cout << "City - "; cin >> city;
			cout << "Priority(1-4) - "; cin >> prior;
			cout << endl;
			fout << name << endl
				<< year << endl
				<< city << endl
				<< prior << endl;
			q.push(Node(name, year, city), prior);
			fout.close();
			break;
		case 2:
			q.pop();
			choice = 3;
			break;
		case 3:
			for (q.begin(); !q.isEnd(); q.next()) cout << q.getCurrent() << " Priority - " << q.showprior()  << endl;
			break;
		case 4:
			return 0;
		}
	} while (choice !=  4);
}
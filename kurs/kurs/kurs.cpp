#include "pch.h"
#include <iostream> 
#include <string>
#include <fstream>

using namespace std;

class Node {
	string name;
	string year;
	string city;
	unsigned int prior;
public:
	Node() {
		name = "";
		year = "";
		city = "";
		prior = 0;
	}
	Node(string name, string year, string city, unsigned int prior) : name(name), year(year), city(city), prior(prior) {
	}
	friend ostream& operator<<(ostream& os, Node& n)
	{
		return os << "FIO - " << n.name << " Year - " << n.year << " City - " << n.city << " Prior - " << n.prior;
	}
};


template<class T>
class Queue {
	struct Elem {
		T obj;
		Elem* next;
	};
	Elem* head;
	Elem* last;
	Elem* iterator;
public:
	Queue() : head(nullptr) {}

	void push(T val) {
		if (head == nullptr) {
			head = new Elem;
			head->obj = val;
			head->next = nullptr;
			last = head;
		}
		else {
			last->next = new Elem;
			last->next->obj = val;
			last->next->next = nullptr;
			last = last->next;
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
	bool f = true;
	string name, city, year, str;
	unsigned int  prior;
	fstream fout;
	ifstream file_check("file.txt", ios::in);
	if (file_check.peek() != ifstream::traits_type::eof()) { //возможно нужно изменить доработать для считывания строки но не слова
		while (!file_check.eof()) {
			file_check >> name;
			file_check >> year;
			file_check >> city;
			file_check >> prior;
			q.push(Node(name, year, city, prior));
		}
		
	}
	cout << "Choose what you want to do 1add 2delete 3show 4break: ";
	do {
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Enter application" << endl;
			fout.open("file.txt", ios::out | ios::app);
			cin >> name;
			cin >> year;
			cin >> city;
			cin >> prior;
			cout << endl;
			fout << name << endl << year << endl << city << endl << prior << endl;
			q.push(Node(name, year, city, prior));
			fout.close();
			break;
		case 2:
			q.pop();
			break;
		case 3:
			for (q.begin(); !q.isEnd(); q.next()) cout << q.getCurrent() << endl;
			break;
		case 4:
			return 0;
		}
	} while (choice !=  4);
}

#include "pch.h"
#include <iostream> 
#include <string>
//#include <queue>

using namespace std;

class Node {
	string name;
	unsigned int year;
	string city;
	unsigned int prior;
public:
	Node() {
		name = "";
		year = 0;
		city = "";
		prior = 0;
	}
	Node(string name, unsigned int year, string city, unsigned int prior) : name(name), year(year), city(city), prior(prior) {
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
	q.push(Node("p", 123, "a", 2));
	q.push(Node("q", 124, "b", 2));
	q.push(Node("w", 125, "c", 2));
	for (q.begin(); !q.isEnd(); q.next()) {
		cout << q.getCurrent() << endl;
	}
	q.pop();
	cout << endl;
	for (q.begin(); !q.isEnd(); q.next()) {
		cout << q.getCurrent() << endl;
	}
}

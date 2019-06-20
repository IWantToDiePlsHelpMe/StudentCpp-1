#include "pch.h"
#include <iostream> 
#include <string>
#include <fstream>

using namespace std;

class Node {
	string name;
	string year;
	string city;
	string str = name + year + city;
public:
	Node() {
		name = "";
		year = "";
		city = "";
	}
	Node(string name, string year, string city) : name(name), year(year), city(city) {}

	string get_str() {
		return str;
	}

	friend ostream& operator<<(ostream& os, Node& n)
	{
		return os << "Name - " << n.name << " Year - " << n.year << " City - " << n.city;
	}
	friend bool operator== (Node& x, Node& y);

};

bool operator== (Node& x, Node& y) {
	return (x.name == y.name && x.year == y.year && x.city == y.city);
}

template<class T>
class Queue {
	struct Elem {
		T obj;
		unsigned int prior;
		Elem* next;
	};
	int delete_iterator = 0;
	Elem* tmp;
	Elem* tmp1;
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
				else {
					for (tmp = head; tmp != last; tmp = tmp->next) {
						if (prior >= tmp->next->prior) {
							tmp1 = new Elem;
							tmp1->next = tmp->next;
							tmp->next = tmp1;
							tmp1->obj = val;
							tmp1->prior = prior;
							break;
						}
					}
				}
			}
		}
	}
	void delete_app(T value) {
		for (tmp = head; tmp != last; tmp = tmp->next) {
			if (value == tmp->next->obj) {
				tmp->next = tmp->next->next;
				delete_iterator++;
			}
		}
	}
	int get_di() {
		return delete_iterator;
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
	string namefd, yearfd, cityfd;
	string name, city, year;
	unsigned int prior;
	fstream fout;
	ifstream file_check("file.txt", ios::in);
	if (file_check.peek() != ifstream::traits_type::eof()) {
		while (true) {
			getline(file_check, name);
			getline(file_check, year);
			getline(file_check, city);
			file_check >> prior;
			file_check.ignore();
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
			cout << "Name - ";
			cin.ignore();
			getline(cin, name);
			cout << "Year - ";
			getline(cin, year);
			cout << "City - ";
			getline(cin, city);
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
			cin.ignore();
			getline(cin, namefd);
			getline(cin, yearfd);
			getline(cin, cityfd);
			q.delete_app(Node(namefd,yearfd,cityfd));

			break;
		case 3:
			for (q.begin(); !q.isEnd(); q.next()) cout << q.getCurrent() << " Priority - " << q.showprior()  << endl;
			break;
		case 4:
			return 0;
		}
	} while (choice !=  4);
}
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Kandidat {
private:
	string name;
	int birth;
	string place;
	int index;
public:
	Kandidat(string name, int birth, string place) {
		this->name = name;
		this->birth = birth;
		this->place = place;
	}
};

int main()
{
	//Kandidat kand("popov", 1945, "cantina");
	
}
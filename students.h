#pragma once
#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

void SolveCorrectlyEquation(const double& a, const double& b, const double& c, double& root1, double& root2, int& countOfRoot);

class Student {
public:
	int countOfRoot = 0;
	double root1 = 0, root2 = 0;
	string firstName;
	string lastName;
	Student(string name, string surname) : firstName(name), lastName(surname){
	}

	virtual void SolveEquation(const double& a, const double& b, const double& c);

	friend ostream& operator<<(ostream& os, const Student& dt);
};


class GoodStudent : public Student {
public:
	GoodStudent(string name, string surname) : Student(name, surname) {
	}
	void SolveEquation(const double& a, const double& b, const double& c);
};

class AverageStudent : public Student {
public:
	AverageStudent(string name, string surname) : Student(name, surname) {
	}
	void SolveEquation(const double& a, const double& b, const double& c);
};

class BadStudent : public Student {
public:
	BadStudent(string name, string surname) : Student(name, surname) {
	}
	void SolveEquation(const double& a, const double& b, const double& c);
};

class Teacher {
public:
	string name;
	map<string, int> results;

	void CheckEquations();

	void PrintResults();
};
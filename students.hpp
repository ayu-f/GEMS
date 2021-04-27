#pragma once
#include "EquationSolver.hpp"
#include <fstream>
#include <string>

using namespace std;

class Student {
protected:
	EquationSolver solver;
public:
	int countOfRoot = 0;
	double root1 = 0, root2 = 0;
	string firstName;
	string lastName;
	Student(string name, string surname) : firstName(name), lastName(surname){
	}

	virtual void SolveEquation(const double& a, const double& b, const double& c);

	void WriteAnswersToFile(ofstream& file, const double& a, const double& b, const double& c);

	friend ostream& operator<<(ostream& os, const Student& dt);
};


class GoodStudent : public Student {
public:
	GoodStudent(string name, string surname) : Student(name, surname) {
	}
	virtual void SolveEquation(const double& a, const double& b, const double& c);
	
};

class AverageStudent : public Student {
public:
	AverageStudent(string name, string surname) : Student(name, surname) {
	}
	virtual void SolveEquation(const double& a, const double& b, const double& c);
};

class BadStudent : public Student {
public:
	BadStudent(string name, string surname) : Student(name, surname) {
	}
	virtual void SolveEquation(const double& a, const double& b, const double& c);
};

#pragma once
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include "EquationSolver.hpp"

using namespace std;

class Teacher {
private:
	EquationSolver solver;
public:
	string name;
	map<string, int> results;

	void CheckEquations();

	void PrintResults();
};
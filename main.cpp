#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

void SolveCorrectlyEquation(double a, double b, double c, double& root1, double& root2, int &countOfRoot) {
	double D = b* b - 4 * a * c;
	if (D < 0) {
		countOfRoot = 0;
	}
	else if (D > 0) {
		root1 = (-b + sqrt(D)) / (2 * a);
		root2 = (-b - sqrt(D)) / (2 * a);
		countOfRoot = 2;
	}
	else {
		root1 = -b / (2 * a);
		root2 = root1;
		countOfRoot = 1;
	}
}

class Teacher {
public:
	string name;
	map<string, int> results;

	void CheckEquations() {
		ifstream ansOfStudents("answers.txt");
		double a, b, c, root1, root2, rootsFromStudent[2];
		int countOfRoots, countRootsSt;
		string nameSt, surnameSt;

		while (ansOfStudents >> a >> b >> c >> countRootsSt >> rootsFromStudent[0] >> rootsFromStudent[1] >> nameSt >> surnameSt) {
			SolveCorrectlyEquation(a, b, c, root1, root2, countOfRoots);
			if (results.count(nameSt + surnameSt) == 0) {
				results.emplace(nameSt + " " + surnameSt, 0);
			}
			if (root1 == rootsFromStudent[0] && root2 == rootsFromStudent[1] && countOfRoots == countRootsSt) {
				results.at(nameSt + " " + surnameSt)++;
			}
		}
		ansOfStudents.close();
	}

	void PrintResults() {
		cout << "| Name of student - Score \n";
		for (auto result : results) {
			cout << "| " << result.first << " - " << result.second << endl;
		}
	}
};

class Student {
public:
	int countOfRoot = 0;
	double root1 = 0, root2 = 0;
	string firstName;
	string lastName;
	Student(string name, string surname) : firstName(name), lastName(surname)
	{
	}

	virtual void SolveEquation(double a, double b, double c) {
		root1 = 0;
		root2 = 0;
		countOfRoot = 1;
	}
	friend ostream& operator<<(ostream& os, const Student& dt);
};
ostream& operator<<(ostream& os, const Student& st)
{
	os << st.firstName + " " + st.lastName;
	return os;
}

class GoodStudent : public Student {
public:
	GoodStudent(string name, string surname) : Student(name, surname) {
	}
	void SolveEquation(double a, double b, double c) {
		SolveCorrectlyEquation(a, b, c, root1, root2, countOfRoot);
	}
};

class AverageStudent : public Student {
public:
	AverageStudent(string name, string surname) : Student(name, surname) {
	}
	void SolveEquation(double a, double b, double c) {
		if (rand() % 2 == 0) {
			SolveCorrectlyEquation(a, b, c, root1, root2, countOfRoot);
		}
		else {
			Student::SolveEquation(a, b, c);
		}
	}
};

class BadStudent : public Student {
public:
	BadStudent(string name, string surname) : Student(name, surname) {
	}
	void SolveEquation(double a, double b, double c) {
		root1 = 0;
		countOfRoot = 1;
	}
};

void WriteAnswersToFile(ofstream &file, Student st, double a, double b, double c) {
	file << a << " " << b << " " << c << " ";
	file << st.countOfRoot << " " << st.root1 << " " << st.root2 << " " << st << "\n";
}

int main(void) {
	ifstream equations("equations.txt");
	ofstream answers("answers.txt");
	double a, b, c;
	Student st("A", "A");
	GoodStudent A("Alex", "Alex");
	AverageStudent B("Bob", "Bob"), D("Ben", "Ben");
	BadStudent C("Cat", "Cat");

	while (equations >> a >> b >> c) {
		A.SolveEquation(a, b, c);
		B.SolveEquation(a, b, c);
		C.SolveEquation(a, b, c);
		D.SolveEquation(a, b, c);
		WriteAnswersToFile(answers, A, a, b, c);
		WriteAnswersToFile(answers, B, a, b, c);
		WriteAnswersToFile(answers, C, a, b, c);
		WriteAnswersToFile(answers, D, a, b, c);
	}

	answers.close();
	Teacher t;
	t.CheckEquations();
	t.PrintResults();
	equations.close();
	return 0;
}
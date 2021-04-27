#include "students.hpp"
#include "teacher.hpp"
using namespace std;

void StartSolveFromStudents(ifstream &equations, ofstream &answers) {
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
		A.WriteAnswersToFile(answers, a, b, c);
		B.WriteAnswersToFile(answers, a, b, c);
		C.WriteAnswersToFile(answers, a, b, c);
		D.WriteAnswersToFile(answers, a, b, c);
	}
}

int main(void) {
	ifstream equations("equations.txt");
	ofstream answers("answers.txt");

	StartSolveFromStudents(equations, answers);

	answers.close();
	Teacher t;
	t.CheckEquations();
	t.PrintResults();
	equations.close();
	return 0;
}
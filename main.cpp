#include "students.h"
using namespace std;

void WriteAnswersToFile(ofstream &file, const Student &st, const double& a, const double& b, const double& c) {
	file << a << " " << b << " " << c << " ";
	file << st.countOfRoot << " " << st.root1 << " " << st.root2 << " " << st << "\n";
}

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
		WriteAnswersToFile(answers, A, a, b, c);
		WriteAnswersToFile(answers, B, a, b, c);
		WriteAnswersToFile(answers, C, a, b, c);
		WriteAnswersToFile(answers, D, a, b, c);
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
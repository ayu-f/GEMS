#include "students.h"

ostream& operator<<(ostream& os, const Student& st)
{
	os << st.firstName + " " + st.lastName;
	return os;
}

void SolveCorrectlyEquation(const double& a, const double& b, const double& c, double& root1, double& root2, int& countOfRoot) {
	double D = b * b - 4 * a * c;
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

void Student::SolveEquation(const double& a, const double& b, const double& c) {
	root1 = 0;
	root2 = 0;
	countOfRoot = 1;
}

void GoodStudent::SolveEquation(const double& a, const double& b, const double& c) {
	SolveCorrectlyEquation(a, b, c, root1, root2, countOfRoot);
}

void AverageStudent::SolveEquation(const double& a, const double& b, const double& c) {
	if (rand() % 2 == 0) {
		SolveCorrectlyEquation(a, b, c, root1, root2, countOfRoot);
	}
	else {
		Student::SolveEquation(a, b, c);
	}
}

void BadStudent::SolveEquation(const double& a, const double& b, const double& c) {
	root1 = 0;
	countOfRoot = 1;
}

void Teacher::CheckEquations() {
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

void Teacher::PrintResults() {
	cout << "| Name of student - Score \n";
	for (auto result : results) {
		cout << "| " << result.first << " - " << result.second << endl;
	}
}
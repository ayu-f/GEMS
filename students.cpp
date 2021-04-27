#include "students.hpp"

ostream& operator<<(ostream& os, const Student& st)
{
	os << st.firstName + " " + st.lastName;
	return os;
}

void Student::SolveEquation(const double& a, const double& b, const double& c) {
	root1 = 0;
	root2 = 0;
	countOfRoot = 1;
}

void Student::WriteAnswersToFile(ofstream& file, const double& a, const double& b, const double& c) {
	file << a << " " << b << " " << c << " ";
	file << countOfRoot << " " << root1 << " " << root2 << " " << firstName + " " + lastName << endl;
}

void GoodStudent::SolveEquation(const double& a, const double& b, const double& c) {
	solver.SolveCorrectlyEquation(a, b, c, root1, root2, countOfRoot);
}

void AverageStudent::SolveEquation(const double& a, const double& b, const double& c) {
	if (rand() % 2 == 0) {
		solver.SolveCorrectlyEquation(a, b, c, root1, root2, countOfRoot);
	}
	else {
		Student::SolveEquation(a, b, c);
	}
}

void BadStudent::SolveEquation(const double& a, const double& b, const double& c) {
	root1 = 0;
	countOfRoot = 1;
}

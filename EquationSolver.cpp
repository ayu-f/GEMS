#include "EquationSolver.hpp"

void EquationSolver::SolveCorrectlyEquation(double a,double b, double c, double& root1, double& root2, int& countOfRoot) {
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
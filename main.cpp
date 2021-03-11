#include <iostream>
#include <string>
#include <math.h>

#define size 12
#define INVALID 1
#define FALSE 0
#define NOROOTS 2
using namespace std;

void ReadData(double* coefs) {
	int i = 0;
	while (i < 3) {
		cin >> coefs[i];
		i++;
	}
}

void Solve(double* coefs, double &root1, double &root2, int &error) {
	double a = coefs[0], b = coefs[1], c = coefs[2], D;
	D = b * b - 4 * a * c;
	if (D < 0) {
		error = NOROOTS;
		return;
	}
	else if (D > 0) {
		root1 = (-b + sqrt(D)) / (2 * a);
		root2 = (-b - sqrt(D)) / (2 * a);
	}
	else {
		root1 = -b / (2 * a);
		root2 = root1;
	}
}

int main(void) {
	int error = FALSE;
	double coefs[3], root1, root2;

	cout << "Enter the coefficients a b c in the form \"a b c\"\n";
	ReadData(coefs);

	Solve(coefs, root1, root2, error);
	if (error == FALSE) {
		cout << "The fisrt root " << root1 << endl;
		cout << "The second root "<< root2 << endl;
	}
	else if (error == NOROOTS) {
		cout << "There are no solutions!\n";
	}
	return 0;
}
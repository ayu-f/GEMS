#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#pragma warning(disable:4996)
#define size 12
#define INVALID 1
#define FALSE 0
#define NOROOTS 2

void ReadCoefficient(double *coef, int *error) {
	char buffer, str[size]; 
	int i = 0;
	do
	{
		buffer = (char)getchar();
		if (buffer < '0' || buffer > '9') {
			(*error) = INVALID;
			return;
		}
		str[i] = buffer;
		i++;
	} while (buffer != ' ' && buffer != '\n');
	(*coef) = atof(str);
}

void PrintError() {
	scanf("%*[^\n]");
	printf("Invalid input!\n");
}

void ReadData(double* coefs, int *error) {
	int i = 0;
	while (i < 3 && (*error) == FALSE) {
		ReadCoefficient(&coefs[i], error);
		i++;
	}
}

void Solve(double* coefs, double* root1, double* root2, int *error) {
	double a = coefs[0], b = coefs[1], c = coefs[2], D;
	D = b * b - 4 * a * c;
	if (D < 0) {
		(*error) = NOROOTS;
		return;
	}
	else if (D > 0) {
		(*root1) = (-b + sqrt(D)) / (2 * a);
		(*root2) = (-b - sqrt(D)) / (2 * a);
	}
	else {
		(*root1) = -b / (2 * a);
		(*root2) = (*root1);
	}
}

void Run() {
	int error = FALSE;
	double coefs[3], root1, root2;

	printf("Enter the coefficients a b c in the form \"a b c\"\n");
	ReadData(coefs, &error);
	if (error == INVALID) {
		PrintError();
		return;
	}

	Solve(coefs, &root1, &root2, &error);
	if (error == FALSE) {
		printf("The fisrt root %g\n", root1);
		printf("The second root %g\n", root2);
	}
	else if (error == NOROOTS) {
		printf("There are no solutions!\n");
	}
}

int main(void) {
	Run();
	return 0;
}
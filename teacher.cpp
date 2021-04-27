#include "teacher.hpp"

void Teacher::CheckEquations() {
	ifstream ansOfStudents("answers.txt");
	double a, b, c, root1, root2, rootsFromStudent[2];
	int countOfRoots, countRootsSt;
	string nameSt, surnameSt;

	while (ansOfStudents >> a >> b >> c >> countRootsSt >> rootsFromStudent[0] >> rootsFromStudent[1] >> nameSt >> surnameSt) {
		solver.SolveCorrectlyEquation(a, b, c, root1, root2, countOfRoots);
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
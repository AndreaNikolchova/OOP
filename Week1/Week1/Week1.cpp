#include <iostream>
//1
void print(int** matrix, size_t N, size_t M) {
	for (size_t row = 0; row < N; row++)
	{
		for (size_t col = 0; col < M; col++)
		{
			std::cout << matrix[row][col] << " ";
		}
		std::cout << std::endl;
	}

}
void deleteMatrix(int** matrix, size_t N) {
	for (size_t i = 0; i < N; i++)
		delete[] matrix[i];
	delete matrix;
}
int** initializeMatrixFromConsole(size_t N, size_t M) {
	int** matrix = new int* [N];
	for (size_t row = 0; row < N; row++)
	{
		matrix[row] = new int[M];
		for (size_t col = 0; col < M; col++)
		{
			std::cin >> matrix[row][col];
		}
	}
	return matrix;
}
int** initializeMatrix(size_t N, size_t M) {
	int** matrix = new int* [N];
	for (size_t row = 0; row < N; row++)
	{
		matrix[row] = new int[M];
	}
	return matrix;
}
int** transponate(int** matrix, size_t N, size_t M) {
	int** transponateMatrix = initializeMatrix(M, N);
	for (size_t row = 0; row < M; row++)
	{
		for (size_t col = 0; col < N; col++)
		{
			transponateMatrix[row][col] = matrix[col][row];
		}
	}
	return transponateMatrix;
}
void switchRows(int** matrix, size_t N, size_t M, size_t rowIndex1, size_t rowIndex2) {
	if (rowIndex1 < 0 || rowIndex1 >= N || rowIndex2 < 0 || rowIndex2 >= N) {
		return;
	}
	for (size_t i = 0; i < M; i++)
	{
		std::swap(matrix[rowIndex1][i], matrix[rowIndex2][i]);
	}

}
//2
struct ComplexNumber {
	int a;
	int b;
};
ComplexNumber sumTwoNumbers(const ComplexNumber& lcn, const ComplexNumber& rcn) {
	ComplexNumber sum;
	sum.a = lcn.a + rcn.a;
	sum.b = lcn.b + rcn.b;
	return sum;
}
ComplexNumber multiplyTwoComplexNumbers(const ComplexNumber& lcn, const ComplexNumber& rcn) {
	ComplexNumber multiply;
	multiply.a = lcn.a * rcn.a - lcn.b * rcn.b;
	multiply.b = lcn.a * rcn.b + lcn.b * rcn.a;
	return multiply;
}
//3
enum class Major {
	СИ, ИС, КН, ПМ, М, ИНФ
};
struct Student {
	double grade;
	Major major;
	char facultyNumber[10];
};
struct Group {
	double averageGrade;
	size_t n;
	Student* students;
};
double avgGrades(Student* students, size_t size) {
	double sum = 0;
	for (size_t i = 0; i < size; i++)
		sum += students[i].grade;
	return sum / size;
}
Group initializeGroupAndStudents(size_t n) {
	Student* students = new Student[n];
	for (size_t i = 0; i < n; i++) {
		std::cout << "Enter grade for student: ";
		std::cin >> students[i].grade;

		std::cout << "Enter faculty number for student: ";
		std::cin >> students[i].facultyNumber;

		char majorLine[3];
		std::cout << "Enter major (abbreviation) for student: ";
		std::cin >> majorLine;

		switch (majorLine[0]) {
		case 'S':
			students[i].major = Major::СИ;
			break;
		case 'I':
			students[i].major = Major::ИС;
			break;
		case 'K':
			students[i].major = Major::КН;
			break;
		case 'P':
			students[i].major = Major::ПМ;
			break;
		case 'M':
			students[i].major = Major::М;
			break;
		case 'IN':
			students[i].major = Major::ИНФ;
			break;
		}
	}
	Group gr = { avgGrades(students,n),n,students };
	return gr;
}
int findCountOfPeopleWithScolarship(Group& gr, double scolarshipGrade) {
	int count = 0;
	for (size_t i = 0; i < gr.n; i++)
	{
		if (gr.students[i].grade >= scolarshipGrade) {
			count++;
		}
	}
	return count;

}
Student* getStudentsWhoWillHaveScolarship(Group& gr, double scolarshipGrade) {
	int numberOfStudents = findCountOfPeopleWithScolarship(gr, scolarshipGrade);
	Student* studentsWithScolarship = new Student[numberOfStudents];
	int count = 0;
	for (size_t i = 0; i < gr.n; i++)
	{
		if (gr.students[i].grade >= scolarshipGrade) {
			studentsWithScolarship[count] = gr.students[i];
			count++;
		}
	}
	return studentsWithScolarship;
}
bool compareStudentsByFacultyNumber(const Student& a, const Student& b) {
	return std::strcmp(a.facultyNumber, b.facultyNumber) > 0;
}
Group sortedStudentsWhoWillHaveScolarship(Group& gr, double scolarshipGrade) {
	size_t size = findCountOfPeopleWithScolarship(gr, scolarshipGrade);
	Student* studentsWithScolarship = getStudentsWhoWillHaveScolarship(gr, scolarshipGrade);

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (compareStudentsByFacultyNumber(studentsWithScolarship[j], studentsWithScolarship[j + 1])) {
				std::swap(studentsWithScolarship[j], studentsWithScolarship[j + 1]);
			}
		}
	}

	Group group = { avgGrades(studentsWithScolarship,size),size,studentsWithScolarship };
	return group;
}
//4
struct Point {
	int x;
	int y;
};
Point readPoint() {
	int x, y;
	std::cin >> x >> y;
	Point point = { x,y };
	return point;
}
void printPoint(Point& point) {
	std::cout << "(" << point.x << ";" << point.y << ")" << std::endl;
}
int main()
{

}
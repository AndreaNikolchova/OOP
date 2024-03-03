#include <iostream>
#include <fstream>

void readThreeNumbers() {

	int a, b, c;
	std::cin >> a >> b >> c;
	int sum = a + b + c;
	int mult = a * b * c;

	std::ofstream outFile("result.txt");

	if (!outFile.is_open()) {
		std::cout << "Error opening file!" << std::endl;
		return;
	}
	outFile << sum << " " << mult << std::endl;
	outFile.close();
}
int subtractNumbersFromFile() {
	std::ifstream inFile("result.txt");

	if (!inFile.is_open()) {
		std::cout << "Error opening file!" << std::endl;
		return -1;
	}
	int sum, mult;
	inFile >> sum >> mult;

	inFile.close();
	return sum - mult;
}

int main()
{
	//readThreeNumbers();
	std::cout<<subtractNumbersFromFile();
}


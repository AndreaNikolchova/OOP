#include <iostream>
#include <fstream>
//1
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
//2
const int REALTION_MAX_SIZE = 25;
struct Pair {
	int a;
	int b;
};
struct Relation {
	int size;
	Pair pairs[REALTION_MAX_SIZE];
};
void writeRelationToFile(const char* fileName,const Relation& relation) {
	std::ofstream ofs(fileName);
	if (!ofs.is_open()) {
		std::cout << "Error opening file!" << std::endl;
		return;
	}
	for (size_t i = 0; i < relation.size; i++)
	{
		ofs << '<' << relation.pairs[i].a << ';' << relation.pairs[i].b << '>'<< std::endl;
	}
	ofs.close();
}
Relation readRelationFromFile(const char* fileName) {
	std::ifstream ifs(fileName);
	if (!ifs.is_open()) {
		std::cout << "Error opening file!" << std::endl;
		return {0,0};
	}
	
	Relation relation;
	relation.size = 0;
	while (true) {

		if (ifs.eof()) {
			break;
		}
		char open, bettween , close ;
		int a , b ;
		ifs >> open >> a >> bettween >> b >> close;
		Pair currentPair = {a,b};
		relation.pairs[relation.size++] = currentPair;
	}
	ifs.close();
	return relation;
}
void addPairToRelation(const Pair& pair, Relation& relation) {
	if (relation.size + 1 > 25) {
		std::cout << "Can't add pair, because the size of the relation is already 25" << std::endl;
		return;
	}
	relation.size++;
	relation.pairs[relation.size] = pair;
 }

int main()
{
	Relation rl = readRelationFromFile("relation.txt");
}


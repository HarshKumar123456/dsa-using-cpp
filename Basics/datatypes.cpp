#include <iostream>
using namespace std;

int main() {
	int integerType = 10;
	char characterType = 'H';
	bool booleanType = true;
	float floatingPointIntegerType = 10.10;
	double doubleType = 10.100;

	cout << "Integer: " << integerType << " Size is : "<< sizeof( integerType ) << endl;
	cout << "Character: " << characterType << " Size is : "<< sizeof( characterType ) << endl;
	cout << "Boolean: " << booleanType << " Size is : "<< sizeof( booleanType ) << endl;
	cout << "Float: " << floatingPointIntegerType << " Size is : "<< sizeof( floatingPointIntegerType) << endl;
	cout << "Double: " << doubleType << " Size is : "<< sizeof( doubleType ) << endl;

	return 0;
}

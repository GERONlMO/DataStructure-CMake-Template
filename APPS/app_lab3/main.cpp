#include "../../LIBS/lib_parser/parser.h"

void main() {
	string expression;

	cout << "Enter expression: " << endl;
	cin >> expression;

	Parser parser(expression);
	parser.printPostfix();

	cout << endl;

	cout << "Result : " << parser.calculate() << endl;
}
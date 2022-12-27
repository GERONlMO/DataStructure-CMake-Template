#ifndef INCLUDE_PARSER_H_
#define INCLUDE_PARSER_H_

#include <map>
#include <stack>
#include <iostream>
#include "../lib_stack/customStack.h"

class Parser {
private:
	string infixExpression;
	string postfixExpression;
	map<char, int> operationsPriority = {
		{'(', 0},
		{'+', 1},
		{'-', 1},
		{'*', 2},
		{'/', 2},
		{'^', 3},
		{'~', 4}
	};

	bool isDigit(char c) {
		if ('0' <= c && c <= '9') return true;
		else return false;
	}

	bool containsKey(char c) {
		for (pair<char, int> pair : operationsPriority) {
			if (pair.first == c) return true;
		}
		return false;
	}

	bool isCorrect() {
		CustomStack<char> brackets;
		for (char c : infixExpression) {
			if (c != '(' && c != ')') continue;
			else if (c == '(') brackets.push(c);
			else if (brackets.isEmpty()) return false;
			else brackets.pop();
		}
		return brackets.isEmpty() ? true : false;
	}


	string parseNumber(string expression, int* position) {
		string number = "";
		for (; (*position) < expression.length(); (*position)++) {
			char expressionChar = expression[(*position)];
			if (isDigit(expressionChar))
				number += expressionChar;
			else {
				(*position)--;
				break;
			}
		}
		return number;
	}

	double execute(char operation, double first, double second) {
		switch (operation) {
		case '+':
			return first + second;
		case '-':
			return first - second;
		case '*':
			return first * second;
		case '/':
			return first / second;
		}
	}
public:
	Parser(string expression) {
		infixExpression = expression;
		postfixExpression = toPostfix();
	}

	int getOperationPriority(char operation) {
		for (pair<char, int> pair : operationsPriority) {
			if (pair.first == operation) return pair.second;
		}
	}

	string toPostfix() {
		string tempPostfixExpression = "";
		CustomStack<char>  stack;
		if (isCorrect()) {
			for (int i = 0; i < infixExpression.length(); i++) {
				char expressionChar = infixExpression[i];
				if (isDigit(expressionChar))
					tempPostfixExpression += parseNumber(infixExpression, &i) + " ";
				else if (expressionChar == '(')
					stack.push(expressionChar);
				else if (expressionChar == ')') {
					while (!stack.isEmpty() && stack.top() != '(') {
						tempPostfixExpression += stack.top();
						stack.pop(); // удаление всего между (**)
					}
					stack.pop(); //удаление (
				}
				else if (containsKey(expressionChar)) {
					char operation = expressionChar;
					while (!stack.isEmpty() && getOperationPriority(stack.top()) >= getOperationPriority(operation)) {
						tempPostfixExpression += stack.top();
						stack.pop();
					}
					stack.push(operation);
				}
			}
			while (!stack.isEmpty()) {
				tempPostfixExpression += stack.top();
				stack.pop();
			}
		}
		else {
			cout << "incorrect expression" << endl;
			exit(15);
		}
		return tempPostfixExpression;
	}

	double calculate() {
		CustomStack<double> numbers;
		int counter = 0;
		for (int i = 0; i < postfixExpression.length(); i++) {
			char expressionChar = postfixExpression[i];
			if (isDigit(expressionChar)) {
				string number = parseNumber(postfixExpression, &i);
				numbers.push(stol(number));
			}
			else if (containsKey(expressionChar)) {
				counter++;
				double second = numbers.isEmpty() ? 0 : numbers.top();
				numbers.pop();
				double first = numbers.isEmpty() ? 0 : numbers.top();
				numbers.pop();
				numbers.push(execute(expressionChar, first, second));

				cout << counter << ") " << first << " " << expressionChar << " " << second << " = " << numbers.top() << endl;
			}

		}
		return numbers.top();
	}

	string getPostfix() {
		return postfixExpression;
	}

	void printPostfix() {
		cout << postfixExpression << endl;
	}
};

#endif
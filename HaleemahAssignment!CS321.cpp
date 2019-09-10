#include "pch.h"
#include <iostream>
#include "Haleemah.h"
using namespace std;
using namespace savage;

bool isoperator(char o)
{
	return (o == '+' || o == '*' || o == '-' || o == '/');
}

int precedence(char op)
{
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	return 0;
}

void EvaluateStackTop(stack<double>& numbers, stack<char>& operators)
{
	double operand1, operand2;

	operand2 = numbers.top();
	numbers.pop();
	operand1 = numbers.top();
	numbers.pop();
	switch (operators.top())
	{
	case '+':
		numbers.push(operand1 + operand2);
		break;
	case '-':
		numbers.push(operand1 - operand2);
		break;
	case '*':
		numbers.push(operand1 * operand2);
		break;
	case '/':
		numbers.push(operand1 / operand2);
		break;
	}
	operators.pop();
}

double calculate(istream& input)
{
	char DECIMAL = '.';
	double num;
	char symbol;
	stack<double> numbers;
	stack<char> operations;

	while (input && input.peek() != '\n')
	{
		if (isdigit(input.peek()) || (input.peek() == DECIMAL))
		{
			input >> num;
			numbers.push(num);
		}
		else if (input.peek() == '(')
		{
			input >> symbol;
			operations.push(symbol);
		}
		else if (input.peek() == ')')
		{
			while (operations.top() != '(')
			{
				EvaluateStackTop(numbers, operations);
			}
			input >> symbol;
			operations.pop();
		}
		else if (isoperator(input.peek()))
		{
			while (!operations.empty() && (precedence(operations.top()) >= precedence(input.peek())))
			{
				EvaluateStackTop(numbers, operations);
			}
			input >> symbol;
			operations.push(symbol);
		}
		else
			input.ignore();
	}
	while (!operations.empty())
	{
		EvaluateStackTop(numbers, operations);
	}
	return numbers.top();
}


int main()
{
	char response;

	do
	{
		cout << "Write an expression to be calculated";
		cout << endl;
		cout << "The answer is " << calculate(cin) << endl;
		cout << endl;
		cout << "Do you want to Evaluate another expression?(y/n): ";
		cin >> response;
		cin.ignore();
	} while (response == 'y' || response == 'Y');

	system("pause");
	return 0;
}
	
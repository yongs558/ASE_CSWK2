#include <iostream>

#include "../headers/rational.h"

using namespace ExactArithmetic;

using std::cout;
using std::cin;
using std::endl;

int main()
{

	Rational result;

	result = Rational(1.25) + Rational(2.25);
	cout << "result (+): " << result << endl;

	result = Rational(1.25) - Rational(6,4);
	cout << "result (-): " << result << endl;

	result = Rational(1.25) * Rational(6,12);
	cout << "result (*): " << result << endl;

	result = Rational(1.25) / Rational(2.25);
	cout << "result (/): " << result << endl; 
	
	
	
    /*cout << "Enter the left operand (e.g. 1/3): ";
    Rational x;
	cin >> x;
	cin.clear();
	cin.ignore(10000, '\n');

	cout << "x value: " << x << endl;

    cout << "Enter the operator (+, -, * or /): ";
	std::string op;
    std::getline(cin, op);

    cout << "Enter the right operand (e.g. 4/9): ";
    Rational y;
    cin >> y; 

    Rational result;
    if (op == "+")
    {
        result = x + y;
    }
    else if (op == "-")
    {
        result = x - y;
    }
    else if (op == "*")
    {
        result = x * y;
    }
    else if (op == "/")
    {
        result = x / y;
    }
    else
    {
        cout << "Unrecognised operator" << endl;
        return -1;
    }
    cout << result << endl;
	*/

	system("pause");

    return 0;
}

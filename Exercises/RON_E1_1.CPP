#include <iostream.h>
#include <conio.h>
//Exerise 1.1 Calculator
int num1, num2, total;
char opt;
void main() {
	a:
	clrscr();
	cout << "-------BASIC ARITHMETIC CALCULATOR-------" << endl;
	cout << "First Number: ";
	cin >> num1;
	cout << "Second Number: ";
	cin >> num2;
	cout << "Operation to use (+, -, *, /): ";
	cin >> opt;

	switch(opt){
		case '+': total = num1 + num2; break;
		case '-': total = num1 - num2; break;
		case '*': total = num1 * num2; break;
		case '/': total = num1 / num2; break;
		default: goto a;
	}
	cout << "total: " << total;

	getch();
}
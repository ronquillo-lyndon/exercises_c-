#include <iostream.h>
#include <conio.h>
//exercise 1.5: highest and lowest + n numbers
int num, high, low, n_of_num;
void main(){
	clrscr();
	cout << "------ highest and lowest 2.0 -------" << endl;
	cout << "Numbers to be inputted: ";
	cin >> n_of_num;
	cout << "number: ";
	cin >> num;
	high = num;
	low = num;
	for(int i = 1; i < n_of_num; i++){
		cout << "number: ";
		cin >> num;
		if(num > high) high = num;
		if(num < low) low = num;
	}
	cout << endl;
	cout << "Highest: " << high << endl;
	cout << "Lowest: " << low << endl;
	getch();
}
#include <iostream.h>
#include <conio.h>
// exercise 4.1: rectangle *
int row, col;
void main() {
	clrscr();
	cout << "Row: ";
	cin >> row;
	cout << "Col: ";
	cin >> col;

	for(int i = 0; i < row; i++){
	  for(int j = 0; j < col; j++){
		cout << "*";
	  }
	  cout << endl;
	}
	getch();
}
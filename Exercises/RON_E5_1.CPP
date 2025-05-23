#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <stdio.h>
// exercise 5.1: void and array - insert, view, search index, number, add

void insert();
void view();
void index_return_num();
void num_return_index();
void add();

int num[100];
int count = 0, opt = 0;

void main() {
	clrscr();
	cout << "----------------------------" << endl;
	cout << "1. Insert a number. " << endl;
	cout << "2. View all the numbers. " << endl;
	cout << "3. Look for a number using index. " << endl;
	cout << "4. Look for the index of a number. " << endl;
	cout << "5. Add a number. " << endl;
	cout << "6. exit. " << endl;
	cout << "choose option: ";
	cin >> opt;
	switch(opt){
		case 1: insert(); break;
		case 2: view(); break;
		case 3: index_return_num(); break;
		case 4: num_return_index(); break;
		case 5: add(); break;
		case 6: cout << "Porgram is terminating in 3";
			delay(500); cout << " 2";
			delay(500); cout << " 1";
			delay(500); cout << ".";
			delay(100); cout << ".";
			delay(100); cout << ".";
			delay(100); exit(0);
		default: cout << "invalid input!";
			getch();
			main();

	}
	getch();
}

void insert(){
	clrscr();
	cout << "\n input [" << count << "] number: ";
	cin >> num[count];
	count++;
	cout << "number is added";
	cout << "\n press any key to go back...";
	getch();
	main();
}
void view(){
	clrscr();
	cout << "Showing " << count << " numbers" << endl;
	for(int x = 0; x < count; x++){
		cout<<"index:["<<x<<"] - "<< num[x] << endl;
	}
	cout << "\n press any key to go back...";
	getch();
	main();
}
void index_return_num(){
	clrscr();
	int index;
	cout << "\n look for number through index [0 - " << count - 1 << "]:";
	cin >> index;
	if(index >= count)  {cout << "Error! Out of indexing..."; delay(1500); index_return_num();}
	cout << "the number in the index of " << index << " is " << num[index];
	cout << "\n press any key to go back...";
	getch();
	main();
}

void num_return_index(){
	int number;
	clrscr();
	cout << "Look for a Number: ";
	cin >> number;
	for(int i = 0; i < count; i++){
		if(number == num[i]) cout << "This number is at the index of: " << i << endl;
	}
	cout << "\n press any key to go back...";
	getch();
	main();
}

void add(){
	clrscr();
	int index1 = 0, index2 = 0;
	cout << "Add two numbers based on their indexing." << endl;
	for(int x = 0; x < count; x++){
		cout<<"["<<x<<"]-"<< num[x] << endl;
	}
	cout << "First Index: ";
	cin >> index1;
	if(index1 >= count)  {cout << "Error! Out of indexing..."; delay(500);  add();}
	cout << "Second Index: ";
	cin >> index2;
	if(index2 >= count)  {cout << "Error! Out of indexing..."; delay(500);  add();}


	cout << num[index1] << " + " << num[index2] << " = " << num[index1] + num[index2] << endl;
	cout << "\n press any key to go back...";
	getch();
	main();
}
#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
//add number (only numbers between 0-100)
//view all numbers
//search a number via index
//search inputted number
//output the largest number
//output the smallest number
//serach numbers in between 2 numbers
//output divisible number

void add_numbers();
void view_all_numbers();
void search_via_index();
void search_via_input();
void search_largest();
void search_smallest();
void search_inbetween();
void divisible_number();

int choice;
int arr_num[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int count = 10;
void main() {
	a:
	clrscr();
	cout << "****************************" << endl;
	cout << "1. Add a number. " << endl;
	cout << "2. View all numbers. " << endl;
	cout << "3 Search via index. " << endl;
	cout << "4. Search via input. " << endl;
	cout << "5. Search largest. " << endl;
	cout << "6. Search Smalest. " << endl;
	cout << "7. Search numbers in between two number. " << endl;
	cout << "8. Look for numbers divisible by n. " << endl;
	cout << "9. Exit " << endl;
	cout << "Choice: ";
	cin >> choice;
	switch(choice){
		case 1: add_numbers(); break;
		case 2:
			clrscr();
			cout << "List of All numbers Added: " << count << endl;
			view_all_numbers();
			cout << "Press anykey togo main navigation.";
			getch();
			main(); break;
		case 3: search_via_index(); break;
		case 4: search_via_input(); break;
		case 5: search_largest(); break;
		case 6: search_smallest(); break;
		case 7: search_inbetween(); break;
		case 8: divisible_number(); break;
		case 9: cout << "exiting in 3 ";
			delay(200); cout << "2";
			delay(200); cout << " 1";
			delay(200); exit(0);
		default: cout<< "\n!!!Wrong input!!!"; delay(1000); goto a;
	}
	getch();
}
void add_numbers(){
      int num;
      if(count > 100){
	 cout << "Already reach the maximum number!" << endl;
	 getch();
	 main();
      }
      clrscr();
      cout << "Add number. available space: "  << 100 - count << endl;
      cout << "Number to be added: ";
      cin >> num;
      arr_num[count] = num;
      count++;
      cout << "Number has been added!" << endl;
      cout << "Press anykey togo main navigation.";
      getch();
      main();
}
void view_all_numbers(){
    if(count == 0) cout << "There is no numbers added"  << endl;
    for(int i = 0; i < count; i++){
	cout << "At index[" << i <<"] - " << arr_num[i] << endl;
    }
    cout << "Press anykey togo main navigation.";
    getch();
    main();
}
void search_via_index(){
    int index = 0;
    clrscr();
    cout << "Search for number by index at: ";
    cin >> index;
    if(index > count){
	cout << "Out of indexing." << endl;
	cout << "Press Any key to try again.." << endl;
	getch();
	search_via_index();
    }
    cout << "The number in the index " << index << " is " << arr_num[index] <<endl;
    cout << "Press anykey togo main navigation.";
    getch();
    main();
}
void search_via_input(){
    clrscr();
    int num, counter = 0;
    cout << "Search number: ";
    cin >> num;
    for(int i = 0; i < count; i++){
	if(arr_num[i] == num) {
	counter++;
	cout << "This number is At " << i << endl;}
    }
    if(counter == 0) cout << "This number doesn't exist in this List. " << endl;
    cout << "Press anykey togo main navigation.";
    getch();
    main();
}
void search_largest(){
    clrscr();
    cout << "The largest in the List of Number is: ";
    int largest = arr_num[0];
    for(int i = 0; i < count; i++){
	if(arr_num[i] > largest) largest = arr_num[i];
    }
    cout << largest << endl;
    cout << "Press anykey togo main navigation.";
    getch();
    main();
}
void search_smallest(){
    clrscr();
    cout << "The Smallest in the List of Number is: ";
    int smallest = arr_num[0];
    for(int i = 0; i < count; i++){
	if(arr_num[i] < smallest) smallest = arr_num[i];
    }
    cout << smallest << endl;
    cout << "Press anykey togo main navigation.";
    getch();
    main();
}
void search_inbetween(){
	clrscr();
	int index1, index2, temp;
	cout << "Look for the numbers in between indexes. " << endl;
	s_a:
	cout << "first index: ";
	cin >> index1;
	if(!(index1 > 0 && index1 < count)){
		cout << "Out of indexing." << endl;
		cout << "Press Any key to try again.." << endl;
		getch();
		goto s_a;
	}
	s_b:
	cout << "second index: ";
	cin >> index2;
	if(!(index2> 0 && index2 < count)){
		cout << "Out of indexing." << endl;
		cout << "Press Any key to try again.." << endl;
		getch();
		goto s_b;
	}
	if(index1 > index2){
		temp = index1;
		index1 = index2;
		index2 = temp;
	}
	cout <<"\n Here are the list of number in the range of index " << index1 << " - " << index2 << endl;

	for(int i = index1; i < index2; i++) {
		cout << " " << arr_num[i];
	}
	cout << endl;
	cout << "Press anykey togo main navigation.";
	getch();
	main();
}
void divisible_number(){
    clrscr();
    int num, counter=0;
    cout << "Look in the list which is divisble by n. " << endl;
    cout << "divisible by: ";
    cin >> num;
    for(int i = 0; i < count; i++){
	if(arr_num[i]%2 == 0) {cout << "The number " << arr_num[i] << " at the index of " << i << " is divisible by "  << num << endl;
	counter++;
	}
    }
    if(counter == 0) cout << "There is no number in the list that is visible by " << num << endl;
    cout << "Press anykey togo main navigation.";
    getch();
    main();
}
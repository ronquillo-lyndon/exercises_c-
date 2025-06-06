#include <iostream.h>
#include <conio.h>
#include <fstream.h>
#include <stdlib.h>

void buffer_data();
char column_name[4][20] = {"account_no", "name", "pin", "initial_money"};
int table_row = 0;
int opt = 0;
char names[20][20];
int list_pin[20];
int i_money[20];

void temporary_save_data();
void view_accounts();
void add_account();
int open_file = 1;
void main(){
	//to reload the file first, kasi trip ko
	if(open_file == 1){
		temporary_save_data();
		open_file = 0;
	}
	a:
	clrscr();
	cout << "====  Account Manager ====" << endl;
	cout << "1. Add Account. " << endl;
	cout << "2. View Accounts. " << endl;
	cout << "3. exit." << endl;
	cout << "Option: ";
	cin >> opt;

	switch(opt){
	case 1:
		cout << "Register account: " << endl;
		add_account();
		cout << "-------------------------" << endl;
		cout << "1. Go back to main" << endl;
		cout << "2. exit" << endl;
		cin >> opt;
		if(opt == 1){
			main();
		}else{
		 exit(0);
		}
		break;
	case 2:
		cout << "All of the acounts: " << endl;
		view_accounts();
		cout << "-------------------------" << endl;
		cout << "1. Go back to main" << endl;
		cout << "2. exit" << endl;
		cin >> opt;
		if(opt == 1){
			main();
		}else{
		 exit(0);
		}
		break;
	case 3:
		exit(0);
	default:
		goto a;

	}


	add_account();
	view_accounts();
	getch();

}

//temporarily storing all of the data, kasi trip ko lang
void temporary_save_data(){
	ifstream fileread;
	fileread.open("account.txt");
	//just to ignore the tables column_name
	for(int i = 0; i < 4; i++){
		fileread >> column_name[i];
	}
	int temp_account_no = 0; // to ignore it, since auto_increment naman pag write at read
	int temp_table_row = 0;
	while(!fileread.eof()){
	       fileread >> temp_account_no; //column_1
	       fileread >> names[temp_table_row]; //column_2
	       fileread >> list_pin[temp_table_row]; //column_3
	       fileread >> i_money[temp_table_row]; //column_4
	       temp_table_row++;
	}
	table_row = temp_table_row - 1;
	fileread.close();
	//NOTE:
	//each of fileread >> is considered as one word, so 1 fileread = 1 word
}

void view_accounts(){
	temporary_save_data();
	clrscr();
	cout << "account_no\tname\t\tPIN\t\tinitial_money" << endl;
	for(int i = 0; i < table_row; i++){
		cout << i << "\t\t";
		cout << names[i] << "\t\t";
		cout << list_pin[i] << "\t\t";
		cout << i_money[i] << endl;
	}
}
void add_account(){
      ofstream filewrite;
      temporary_save_data();
      clrscr();
      filewrite.open("account.txt");
      //reasignment so that it will not be deleted hehe
      filewrite << "account_no\tname\t\tPIN\t\tinitial_money" << endl;
      for(int i = 0; i < table_row; i++){
		filewrite << i << "\t\t";
		filewrite << names[i] << "\t\t";
		filewrite << list_pin[i] << "\t\t";
		filewrite << i_money[i] << endl;
      }
      char name[20];
      int PIN;
      int money;
      //column_1
      filewrite << table_row <<"\t\t";
      //column_2
      cout << "Enter Name: ";
      cin >> name ;
      filewrite << name << "\t\t";
      //column_3
      cout << "PIN: ";
      cin >>  PIN;
      filewrite << PIN << "\t\t";
      //column_4
      cout << "Initizal Money: ";
      cin >> money;
      filewrite << money << endl;

      cout << "The account has been added!" << endl;
      filewrite.close();
}

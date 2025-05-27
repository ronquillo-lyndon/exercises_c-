#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

/*NOTE: for better readibility of data

	PLEASE CHANGE YOUR "NOTEPAD" OR TEXT EDITOR's 
		font : COURIER NEW, BOLD, 6
	
	PLEASE CHANGE YOUR "TERMINALS DEFAULT" screen and font:
		font:
		- size = 14
		Layout:
		- Screen buffer Size
			width = 180-250
			height = preference
		- Window Size 
			width = 180-250
			height = preference
			
	
*/

const int TEXT_DISPLAY = 20, NUM_DISPLAY = 10, POPULATION = 1000;

string l_name[POPULATION],  f_name[POPULATION],  m_name[POPULATION],  suffix[POPULATION];
long int balance[POPULATION], identity[POPULATION];
int PIN[POPULATION];

int population_index = 0;
//stores data temporarily 
void store_database_temp();

//write the data in database
void save_data();

//display data in the terminal
void display_data();

void add_data();

void display_line();

int main(int argc, char** argv) {
	store_database_temp();
	add_data();
	save_data();
	display_data();
	return 0;
}

void display_line(){
	for(int i = 1; i <= 140; i++){
		cout << "-";
	}
	cout << endl;
}

void store_database_temp(){
	ifstream fileread("database.txt");
	string header_line = "";
	int ignore_data_number = 0;
	//to ignore the columns' title
	getline(fileread, header_line);
	getline(fileread, header_line);
	
	population_index = 0;
	while (fileread >> ignore_data_number 
              >> identity[population_index]
              >> l_name[population_index]
              >> f_name[population_index]
              >> m_name[population_index]
              >> suffix[population_index]
              >> PIN[population_index]
              >> balance[population_index]) 
			  {
    population_index++;
	}
	
	fileread.close();
}

void save_data(){
	store_database_temp();
	ofstream filewrite("database.txt");
	for(int i = 1; i <= 55; i++){
		filewrite << "-";
	}
	filewrite << "  List of accounts + balance  ";
	for(int i = 1; i <= 55; i++){
		filewrite << "-";
	}
	filewrite << endl;
    filewrite << left << setw(NUM_DISPLAY) << "No."
    		  << setw(TEXT_DISPLAY) << "Identifier."
              << setw(TEXT_DISPLAY) << "L_Name"
              << setw(TEXT_DISPLAY) << "F_Name"
              << setw(TEXT_DISPLAY) << "M_Name"
              << setw(TEXT_DISPLAY) << "Suffix"
              << setw(TEXT_DISPLAY) << "PIN"
              << setw(TEXT_DISPLAY) << "Balance" << endl;
              
	for (int index = 0; index <= population_index; index++){
		filewrite << left << setw(NUM_DISPLAY) << index
    		<< setw(TEXT_DISPLAY) << identity[index]
            << setw(TEXT_DISPLAY) << l_name[index]
            << setw(TEXT_DISPLAY) << f_name[index]
            << setw(TEXT_DISPLAY) << m_name[index]
            << setw(TEXT_DISPLAY) << suffix[index]
            << setw(TEXT_DISPLAY) << PIN[index]
            << setw(TEXT_DISPLAY) << balance[index] << endl;
	}
    filewrite.close();
    
    cout << "Successfully stored in the database." << endl;
}

void display_data(){
	for(int i = 1; i <= 55; i++){
		cout << "-";
	}
	cout << "  List of accounts + balance  ";
	for(int i = 1; i <= 55; i++){
		cout << "-";
	}
	cout << endl;
	display_line();
	cout << left << setw(NUM_DISPLAY) << "No."
    		<< setw(TEXT_DISPLAY) << "Identifier."
            << setw(TEXT_DISPLAY) << "L_Name"
            << setw(TEXT_DISPLAY) << "F_Name"
            << setw(TEXT_DISPLAY) << "M_Name"
            << setw(TEXT_DISPLAY) << "Suffix"
            << setw(TEXT_DISPLAY) << "PIN"
            << setw(TEXT_DISPLAY) << "Balance" << endl;
    display_line();
	for (int index = 0; index <= population_index; index++){
		cout << left << setw(NUM_DISPLAY) << index
    		<< setw(TEXT_DISPLAY) << identity[index]
            << setw(TEXT_DISPLAY) << l_name[index]
            << setw(TEXT_DISPLAY) << f_name[index]
            << setw(TEXT_DISPLAY) << m_name[index]
            << setw(TEXT_DISPLAY) << suffix[index]
            << setw(TEXT_DISPLAY) << PIN[index]
            << setw(TEXT_DISPLAY) << balance[index] << endl;
	}
	display_line();
}

void add_data(){
	store_database_temp();
	cout << "first name: ";
	cin >>  f_name[population_index];
	cout << "Middle name: ";
	cin >>  m_name[population_index];
	cout << "Last name: ";
	cin >>  l_name[population_index];
	cout << "Suffix name: ";
	cin >>  suffix[population_index];
	cout << "Balance: ";
	cin >>  balance[population_index];
	cout << "PIN: ";
	cin >>  PIN[population_index];
	cout << "ID: ";
	cin >> identity[population_index];
	cout << "Successfully added." << endl;
	population_index++;
	
}

#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

class Student{
	public:
		Student * next;
		int class_id;
		int student_no;
		int mark;
		Student(int c, int s, int m){
	    next = NULL;
		class_id = c;
		student_no = s;
		mark = m;
		}
};

class Classroom{
	public:
		Student * head;
		Classroom(){
			head = NULL;
		}
		void insert(int c, int s, int m){
			Student * newStudent = new Student(c, s, m);
			if(head == NULL){
				head = newStudent;
				return;
			}
			Student * temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newStudent;
		}
		int exist(int student_no){
			Student * temp = head;
			while(temp != NULL){
				if(temp->student_no == student_no) return 1;
				temp = temp->next;
			}
			 return 0;
		}
		void display(int class_id){
			Student * temp = head;
			cout << "---------------------------------" << endl;
			cout << "Students in Classroom " << class_id << ": " << endl;
			cout << "---------------------------------" << endl;
			cout << "Student No. \t | \t Marks " << endl;
			cout << "---------------------------------" << endl;
			while(temp != NULL){
				if(class_id == temp->class_id){
					cout << temp->student_no << "\t\t | \t " << temp->mark << endl;
					cout << "---------------------------------" << endl;
				}
				temp = temp->next;
			}	
		}
		void top(int class_id){
			Student * temp = head;
			cout << "Top Student in classroom " << class_id << ": ";
			int top_student = temp->mark; 
			while(temp != NULL){
				if((top_student < temp->mark) && temp->class_id){
					top_student = temp->mark;
				}
				temp = temp->next;
			}
			temp = head;
			while(temp != NULL){
				if((top_student == temp->mark) && temp->class_id){
					cout << "No. " << temp->student_no << "(Grade: " << temp->mark << ")" << endl;
				}
				temp = temp->next;
			}	
		}
		void remove_students_via_class(int class_id){
			Student * temp = head;
			Student * prev = NULL;
			while(temp != NULL){
				if(class_id == temp->class_id){
					if(prev == NULL){
						//Logic copied from chatgpt
						head = temp->next;
						cout << "Student no. " << temp->student_no << " removed due to no Classroom. " << endl; 
						delete temp;
						temp = head;
					}else {
						//Logic copied from chatgpt
						prev->next = temp->next;
						cout << "Student no. " << temp->student_no << " removed due to no Classroom. " << endl; 
                		delete temp;
                		temp = prev->next;
					}
				} else {
					prev = temp;
					temp = temp->next;
				}	
			}	
		}
		
};

int main(){
	Classroom CvSU;
	int opt, class_id, student_no, mark, no_class = 0;
	int class_exist;
	int counter;
	int classr[100];
	a:
		system("cls");
	cout << "SCHOOL MANAGEMENT SYTEM" << endl;
	cout << "1. Add Classroom" << endl;
	cout << "2. Add Student " << endl;
	cout << "3. Display Class" << endl;
	cout << "4. Find Top Student" << endl;
	cout << "5. Remove Classroom" << endl;
	cout << "6. Exit" << endl;
	cout << "Enter Choice: ";
	cin >> opt;
	switch(opt){
		case 1:
			check_exist_class:
			cout << "Enter Classsroom ID to add: ";
			cin >> class_exist;
			for(int i = 0; i < no_class; i++){
				if(class_exist == classr[i]){
					cout << "Classroom with roll no. [" << classr[i] << "] Already exist." << endl;
					cout << "1. Again 2. To main: ";
					cin >> opt;
					if(opt == 1){
						goto check_exist_class;
					} else {
						goto a;
					}
				}
			}
			classr[no_class] = class_exist;
			no_class++;
			cout << "Classroom " <<  class_exist << " added" << endl;
			break;
		case 2:		
			cout << "Enter Classroom ID, Student Number, and Marks" << endl;
			enter_class:
			cout << "Enter Classsroom ID: ";
			cin >> class_id;
			counter = 0;
			for(int i = 0; i < no_class; i++){
				if(class_id == classr[i]){
					counter++;
				}
			}
			if(counter == 0){
				cout << "No room found!" << endl;
				cout << "1. Again 2. To main: ";
				cin >> opt;
				if(opt == 1){
					goto enter_class;
				} else {
					goto a;
				}
			}
			check_student_not_exist:
			cout << "Enter Student number: ";
			cin >> student_no;
			if(CvSU.exist(student_no)){
				cout << "Student with roll no. [" << student_no << "] Already exist." << endl;
				goto check_student_not_exist;
			}
			cout << "Enter Grade of the Student: ";
			cin >> mark;
			CvSU.insert(class_id, student_no, mark);
			cout << "Student " << student_no << " added to classroom " << class_id << endl;
			break;
		case 3:
			enter_class_to_display:
			cout << "Enter Classsroom ID to display: ";
			cin >> class_id;
			counter = 0;
			for(int i = 0; i < no_class; i++){
				if(class_id == classr[i]){
					counter++;
				}
			}
			if(counter == 0){
				cout << "No room found!" << endl;
				cout << "1. Again 2. To main: ";
				cin >> opt;
				if(opt == 1){
					goto enter_class_to_display;
				} else {
					goto a;
				}
			}
			CvSU.display(class_id);
			break;
		case 4:
			enter_class_to_top:
			cout << "Enter Classsroom ID to find top student: ";
			cin >> class_id;
			counter = 0;
			for(int i = 0; i < no_class; i++){
				if(class_id == classr[i]){
					counter++;
				}
			}
			if(counter == 0){
				cout << "No room found!" << endl;
				cout << "1. Again 2. To main: ";
				cin >> opt;
				if(opt == 1){
					goto enter_class_to_top;
				} else {
					goto a;
				}
			}
			CvSU.top(class_id);
			break;
		case 5:
			enter_class_to_remove:
			cout << "Enter Classsroom ID to remove: ";
			cin >> class_id;
			counter = 0;
			for(int i = 0; i < no_class; i++){
				if(class_id == classr[i]){
					classr[i] = NULL;
					counter++;
				}
			}
			if(counter == 0){
				cout << "No room found!" << endl;
				cout << "1. Again 2. To main: ";
				cin >> opt;
				if(opt == 1){
					goto enter_class_to_remove;
				} else {
					goto a;
				}
			}else {
				cout << "Classroom " << class_id << " removed." << endl;
			}    
			CvSU.remove_students_via_class(class_id);
			break;
		case 6:
			exit(0);
			break;
		default:
			goto a;
	}
	
	cout << "1. Go back 2. No: ";
	cin >> opt;
	if(opt == 1){
		goto a;
	}
	
	return 0;

}


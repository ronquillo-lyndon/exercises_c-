#include <iostream>
#include <stdlib.h>
using namespace std;


class Node{
	public:
	Node * next;
	int cla;
	int r_no;
	int marks;
	Node(int cla, int r_no, int marks){
		cla = cla;
		r_no = r_no;
		marks = marks;
		next = NULL;
	}	
};

class Students{
	public:
		Node * head;
		Students(){
			head = NULL;
		}
		void insert(int cla, int r_no, int marks){
			Node * newNode = new Node(cla, r_no, marks);
			if(head == NULL){
				head = newNode;
				return;
			}
			Node * temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newNode;
		}
		void display_class(int c){
			Node * temp = head;
			int count = 0;
			cout << "Student No. \t Marks" << endl;
			while(temp != NULL){
				if(temp->cla == c){
					cout << temp->r_no << "\t" << temp->marks << endl;
					count++;
				}
				temp = temp->next;
			}
			if(count == 0){
				cout << "No student in Classroom " << c << endl;
			}
		}
		void display_top(int cla){
			Node * temp = head;
			int top = 0;
			int id = 0;
			cout << "Top student in classroom" << cla;
			while(temp != NULL){
				if(top < temp->marks){
					top = temp->marks;
					id = temp->r_no;
				}
				temp = temp->next;
			}
			cout << "Student No. " << id << " (Grade" << top << ")";
		}
		
};
int main(){
	Students bscos;
	int opt, size, cla, marks, r_no;
	cout << "Number of classroom: ";
	cin >> size;
	int class_room[size];
	int count = 0;
	int counter = 0;
	a:
	system("cls");
	cout << "1. Add Classroom" << endl;
	cout << "2. Add Student" << endl;
	cout << "3. Display Class" << endl;
	cout << "4. Find Top Student" << endl;
	cout << "5. Remove Classroom" << endl;
	cout << "6. Exit" << endl;
	cout << "Option: ";
	cin >> opt;
	
	switch(opt){
		case 1:
			cout << "Enter Classroom ID: ";
			cin >> cla;
			class_room[count] = cla;
			count++;
			cout << "Class room has been added" << endl;
			break;
		case 2:
			cout << "Enter Classroom ID, Student Number, and Marks" << endl;
			cout << "Enter Classroom ID: ";
			cin >> cla;
			cout << "Student number: ";
			cin >> r_no;
			cout << "Grade of Student: ";
			cin >> marks;
			break;
		case 3:
			cout << "Enter Classroom ID to display: ";
			cin >> cla;
			counter = 0;
			for(int i = 0; i < count; i++){
				if(cla == class_room[i])counter++;
			}
			if(counter == 0){
				cout << "No Classroom has been found." << endl;
			}
			bscos.display_class(cla);
			break;
		case 4:
			cout << "Enter Classroom ID to find top student: ";
			cin >> cla;
		    counter = 0;
			for(int k = 0; k < count; k++){
				if(cla == class_room[k])counter++;
			}
			if(count == 0){
				cout << "No Classroom has been found." << endl;
			}
			bscos.display_top(cla);
			break;
		case 5:
			cout << "Enter Classroom ID to remove: ";
			cin >> cla;
			for(int j = 0; j < count; j++){
				if(cla == class_room[j]){
					cout << "CLassroom" << class_room[j] << "Removed" << endl;
				}
			}
			break;
		case 6:
			return 0;
			break;
		default:
			goto a;
	
	}
	
	cout << "1. Go back 2. No";
	cin >> opt;
	if(opt == 1){
		goto a;
	}
	
	return 0;
}





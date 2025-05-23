#include <iostream>
#include <stdlib.h>
using namespace std;


class Node{
	public: 
		Node * next;
		int id;
		Node(int val){
			next = NULL;
			id = val;
		}	
};

class Library{
	public: 
		Node * head;
		Library(){
			head = NULL;
		}
		void insert(int val){
			Node * newNode = new Node(val);
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
		void display(){
			Node * temp = head;
			cout << "Books in the library: ";
			while(temp != NULL){
				if(temp->id != NULL) cout << temp->id << " ";
				temp = temp->next;
			}
			cout << endl;
		}
		void search(int id){
			Node * temp = head;
			int count = 0;
			while(temp != NULL){
				if(temp->id == id) {
					count++;
				}
				temp = temp->next;
			}
			if(count == 0){
				cout << "No book has been found. " << endl;
			}else {
				cout << "Book " << id << " found in node " << count + 1 << endl;
			}
			cout << endl;
		}
		void return_book(int id){
			Node * temp = head;
			int count = 0;
			while(temp != NULL){
				if(temp->id == id) {
					temp->id = NULL;
					count++;
				}
				temp = temp->next;
			}
			if(count == 0){
				cout << "No book has been found. " << endl;
			}else {
				cout << "Book has been returned. " << endl;
			}
			cout << endl;
		}
		
};

int main(){
	Library lib;
	int opt, size, ID; 
	a:
	cout << "1. Add Book" << endl;
	cout << "2. Search Book" << endl;
	cout << "3. Return Book" << endl;
	cout << "4. Display Book" << endl;
	cout << "5. Exit" << endl;
	cout << "Option: ";
	cin >> opt;
	switch(opt){
		case 1:
			cout << "Quantity of books you want to add: ";
			cin >> size;
			for(int i = 0; i < size; i++){
				cout << "Enter Book " << i+1 << " ID: ";
				cin>> ID;
				lib.insert(ID);
			}
			break;
		case 2:
			cout <<  "Enter Book ID to search: ";
			cin>> ID;
			lib.search(ID);
			break;
		case 3:
			cout <<  "Enter Book ID to return: ";
			cin>> ID;
			lib.return_book(ID);
			break;
		case 4:
			lib.display();
			break;
		case 5:
			return 0;
			break;
		default:
			goto a;	
	}
	cout << "1. Go to back 2. No: ";
	cin >> opt;
	
	if(opt == 1) goto a;
	
	
	return 0;
}
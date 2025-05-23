#include <iostream>
#include <stdlib.h>

using namespace std;

class Node{
	public:
		Node * next;
		double dep;
		double wid;
		Node(double val, int opt){
			next = NULL;
			dep = 0; 
			wid = 0;
			if(opt == 1){
				dep = val;
			}
			if(opt == 0){
				wid = val;
			}
		}
		
};

class Trans{
	public:
		Node * head;
		Trans(){
			head = NULL;
		}
		void insert(double val, int opt){
			Node * newNode = new Node(val, opt);
			if(head == NULL){
				head = newNode;
				return;
			}
			Node* temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newNode;
		}
		void largest_dep(){
			Node* temp = head;
			double largest = temp->dep;
			while(temp->next != NULL){
				if(largest < temp->dep){
					largest = temp->dep;
				}
				temp = temp->next;
			}
			cout << "Largest Deposit: " << largest;
		}
		void largest_wid(){
			Node* temp = head;
			double largest = temp->wid;
			while(temp->next != NULL){
				if(largest > temp->wid){
					largest = temp->wid;
				}
				temp = temp->next;
			}
			cout << "Largest Widthdrawal: " << largest;
		}
		
};

int main(){
	Trans trans;
	double amount = 0, balance = 0;
	int opt;
	a:
		system("cls");
	cout << "1. Add Transaction" << endl;
	cout << "2. Check Balance" << endl;
	cout << "3. Check Negative" << endl;
	cout << "4. Largset Deposit" << endl;
	cout << "5. Largset Widthdrawal" << endl;
	cout << "6. Exit" << endl;
	cout << "Enter option: ";
	cin >> opt;
	
	switch(opt){
		case 1:
			cout << "Enter amount (+ for deposit, - for withdrawal): ";
			cin >> amount;
			balance += amount;
			if(amount >= 0){
				trans.insert(amount, 1);
			}
			if(amount < 0){
				trans.insert(amount, 0);
			}
			break;
		case 2:
			cout << "Current Balance: " << balance << endl;
			break;
		case 3:
			if(balance >= 0){
				cout << "No negative Balance detected." << endl;
			}else {
				cout << "Negative Balance: " << balance << endl;
			}
			break;
		case 4:
			trans.largest_dep();
			break;
		case 5:
			trans.largest_wid();
			break;
		case 6:
			return 0;
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
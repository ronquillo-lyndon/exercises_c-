#include <iostream.h>
#include <conio.h>
// exercise 4.2: resort front desk ticketing
int opt, t_price, qty;
int child = 0;
int adult = 0;
int senior = 0;
void main(){
	a:
	clrscr();
	cout << "------- Desk Ticketing -------" << endl;
	cout << "For every 5 ticket, 1 is free. " << endl;
	cout << "1. Child \t\t - 50" << endl;
	cout << "2. Adult \t\t - 100" << endl;
	cout << "3. Senior \t\t - 75" << endl;
	cout << "choose option: ";
	cin >> opt;

	cout << "How many ticket?: ";
	cin >> qty;
	switch(opt){
		case 1: child += qty; break;
		case 2: adult += qty; break;
		case 3: senior += qty; break;
		default: goto a;
	}

	cout << "Do you want to buy another ticket?: \n 1. yes \n Any#. no" << endl;
	cout << "choose option: ";
	cin >> opt;
	if(opt == 1) goto a;

	int child_disc = child/5;
	int adult_disc = adult/5;
	int senior_disc = senior/5;

	clrscr();
	cout << "---------- Your Receipt  ----------" << endl;
	if(child != 0) cout << " " << child << " Child Ticket \t - " << child * 50 << endl;
	if(adult != 0) cout << " " << adult << " Adult Ticket \t - " << adult * 100 << endl;
	if(senior != 0) cout << " " << senior << " Senior Ticket \t - " << senior * 75 << endl;
	cout << "discount: " << endl;
	if(child_disc != 0) cout << " " << child_disc << " Child Ticket \t - " << child_disc * 50 << endl;
	if(adult_disc != 0) cout << " " << adult_disc << " Adult Ticket \t - " << adult_disc * 100 << endl;
	if(senior_disc != 0) cout << " " << senior_disc << " Senior Ticket \t - " << senior_disc * 75 << endl;
	cout << "total price: ";
	t_price = ((child * 50) + (adult * 100) + (senior * 75)) -
		  ((child_disc * 50) + (adult_disc * 100) + (senior_disc * 75));
	cout << " \t\t - " << t_price << endl;
	cout << "-----------------------------------" << endl;
	getch();
}
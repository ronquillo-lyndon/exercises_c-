#include <iostream.h>
#include <conio.h>
//exercise 3.1  Ice cream shop
int opt, scoops, money, cone, total;
int chocolate = 0;
int mocha = 0;
int pistachio = 0;
int rock_road = 0;
int fudge = 0;

void main() {
	a:
	clrscr();
	cout << "------- Ice Cream Shop -------" <<endl;
	cout << "1. Chocolate \t\t - 10" << endl;
	cout << "2. Mocha \t\t - 10" << endl;
	cout << "3. Pitachio \t\t - 15" << endl;
	cout << "4. RockyRoad \t\t - 20" << endl;
	cout << "5. Fudge \t\t - 20" << endl;
	cout << "choose option: ";
	cin >> opt;

	cout << "How many scoops?: ";
	cin >> scoops;

	switch(opt){
		case 1: chocolate += scoops; break;
		case 2: mocha += scoops; break;
		case 3: pistachio += scoops; break;
		case 4: rock_road += scoops; break;
		case 5: fudge += scoops; break;
		default: goto a;
	}
	clrscr();
	cout << "List of flavors choosen: ";
	if(chocolate != 0) cout << "\n" << chocolate <<" scoops of Chocolate flavor. amount: " <<  chocolate * 10;
	if(mocha != 0) cout << "\n" << mocha <<" scoops of Mocha flavor. amount: " <<  mocha * 10;
	if(pistachio != 0) cout << "\n" << pistachio <<" scoops of Pistachio flavor. amount: " <<  pistachio * 15;
	if(rock_road != 0) cout << "\n" << rock_road <<" scoops of RockRoad flavor. amount: " <<  rock_road * 20;
	if(fudge != 0) cout << "\n" << fudge <<" scoops of Fudge flavor. amount: " <<  fudge * 20;
	cout << endl;
	cout << "Want another flavor? \n 1. yes \n Any. no" << endl;
	cout << "choose option: ";
	cin >> opt;
	if(opt == 1) goto a;

	b:
	cout << "What kind of cone?: " << endl;
	cout << "1. Normal \t\t - free" << endl;
	cout << "2. Sweet cone \t\t - 5" << endl;
	cout << "3. Cup \t\t\t - 2" << endl;
	cout << "choose option: ";
	cin >> opt;

	switch(opt){
		case 1: cone = 0; break;
		case 2: cone = 5; break;
		case 3: cone = 2; break;
		default: goto b;
	}

	cout << "Money: ";
	cin >> money;
	total = (chocolate * 10) +
		(mocha * 10) +
		(pistachio * 15) +
		(rock_road * 20) +
		(fudge * 20) +
		cone
	;
	clrscr();
	if(money < total){
		cout << "Insuffficient money";
	}else{
		cout << "------ Your Ice Cream Receipt -------";
		if(chocolate != 0) cout << "\n" << chocolate << " Chocolate * 10 \t\t - "<< chocolate * 10;
		if(mocha != 0) cout << "\n" << mocha << " Mocha * 10 \t\t\t - "<< mocha * 10;
		if(pistachio != 0) cout << "\n" << pistachio << " Pistachio * 15 \t\t - "<< pistachio * 15;
		if(rock_road != 0) cout << "\n" << rock_road << " RockRoad * 20 \t\t - "<< rock_road * 20;
		if(fudge != 0) cout << "\n" << fudge << " Fudge * 20 \t\t\t - "<< fudge * 20;
		cout << "\n-------------------------"<<endl;
		cout << "cone: \t\t\t\t - " <<  cone << endl;
		cout << "Total: \t\t\t\t - "  << total << endl;
		cout << "Payment: \t\t\t - " << money << endl;
		cout << "Change : \t\t\t - " << money - total << endl;
	}

	getch();
}

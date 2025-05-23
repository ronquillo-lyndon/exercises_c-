#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
//exercise 1.4: school supply
int opt, qty, money, total, change;
int pencil = 0;
int ballpen = 0;
int bond_p = 0;
int index_c = 0;
int yellow_p = 0;
void main(){
	 a:
	 clrscr();
	 cout << "------ School Supply Store ------" << endl;
	 cout << "1. Pencil \t\t - 10 php per peice" << endl;
	 cout << "2. Ballpen \t\t - 15 php per peice" << endl;
	 cout << "3. Bond Paper \t\t - 2 php per peice" << endl;
	 cout << "4. Index Card \t\t - 2 php per peice" << endl;
	 cout << "5. Yellow Paper \t - 1 php per peice" << endl;
	 cout << "6. exit." << endl;
	 cout << "choose option: ";
	 cin >> opt;
	 if(opt == 6) exit(0);
	 cout << "quantity: ";
	 cin >> qty;

	 switch(opt){
		case 1: pencil += qty; break;
		case 2: ballpen += qty; break;
		case 3: bond_p += qty; break;
		case 4: index_c += qty; break;
		case 5: yellow_p += qty; break;
		default: goto a;
	 }
	 clrscr();
	 cout << "List of all item to buy: " << endl;
	 if(pencil != 0) cout << "1. [" << pencil << "]" << " Pencil * 10 \t\t = " << pencil * 10 <<  endl;
	 if(ballpen != 0) cout << "2. [" << ballpen << "]" << " Ballpen * 15 \t\t = " << ballpen * 15 <<  endl;
	 if(bond_p != 0) cout << "3. [" << bond_p << "]"  << " Bond Paper  * 2 \t\t = " << bond_p * 2 <<  endl;
	 if(index_c != 0) cout << "4. [" << index_c << "]" << " Index Card * 2 \t\t = " << index_c * 2 <<  endl;
	 if(yellow_p != 0) cout << "5. [" << yellow_p << "]" << " Yellow Pad * 1 = " << yellow_p * 1 <<  endl;
	 total = (pencil * 10) + (ballpen * 15) + (bond_p * 2) + (index_c * 2) + (yellow_p * 1);
	 cout << "Total: \t\t\t\t = " << total << endl;
	 cout << "\n 1. add \n 2. buy" << endl;
	 cout << "choose option: ";
	 cin >> opt;
	 if(opt == 1) goto a;
	 cout << "money: ";
	 cin >> money;
	 change = money - total;
	 if(change < 0){
		cout << "Insufficient money" << endl;
	 } else {
		clrscr();
		cout << "Thank you for buying our products. " << endl;
		cout << "Your total amount: " << total << endl;
		cout << "Your change: " << change << endl;
	 }
	 getch();
}
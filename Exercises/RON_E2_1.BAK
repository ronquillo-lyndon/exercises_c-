#include <iostream.h>
#include <conio.h>
// exerice 2.1: school supply
int qty = 0, price = 0, opt = 0, budget = 0, change = 0, total = 0;
int pen = 0, bpen = 0, bpaper = 0, ind = 0, ypaper = 0;
void main() {
	a:
	clrscr();
	cout << "------- SCHOO SUPPLY STORE -------" << endl;
	cout << "1. Pencil \t\t - 10 php"  << endl;
	cout << "2. Ballpen \t\t - 15 php"  << endl;
	cout << "3. Bond Paper \t\t - 2 php"  << endl;
	cout << "4. Index \t\t - 2 php"  << endl;
	cout << "5. Y. Paper \t\t - 1 php"  << endl;
	cin >> opt;
	cout << "How many: ";
	cin >> qty;
	switch(opt){
		case 1: pen += qty; break;
		case 2: bpen += qty; break;
		case 3: bpaper += qty; break;
		case 4: ind += qty; break;
		case 5: ypaper += qty; break;
		default: cout << "Invalid Input!";
		getch();
		goto a;
	}
	if(pen>0) cout << "Pencil\t" << pen << "pcs * 10 = " << pen * 10 << endl;
	if(bpen>0) cout << "Ballpen\t" << bpen << "pcs * 15 = " << bpen * 15 << endl;
	if(bpaper>0) cout << "Bond Paper\t" << bpaper << "pcs * 2 = " << bpaper * 2 << endl;
	if(ind>0) cout << "Index\t" << ind << "pcs * 2 = " << ind * 2 << endl;
	if(ypaper>0) cout << "Y. Paper\t" << ypaper << "pcs * 1 = " << ypaper * 1 << endl;
	price = (pen*10) +
		(bpen*15) +
		(bpaper*2) +
		(ind * 2) +
		ypaper;
	cout << "Total is: " << price << endl;

	cout << endl;
	cout << "1. add item \n 2. checkout\n opt: ";
	cin >> opt;

	switch(opt){
		case 1: main(); break;
		case 2: cout << "enter your money: ";
			cin >> budget;
			if(budget >= price) cout << "change is: " << budget-price;
			else cout << "insufficient funds!";
			break;
		default: cout << "Invalid choice!";
			getch();
			cout << "program will exit!";

	}



	getch();
}
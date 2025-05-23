#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	int size;
	double avg;
	cout << "Enter number of rating: ";
	cin >> size;
	int rate[size];
	int star[size];
	cout << "Enter rating (1-5): " << endl;
	for(int i = 0; i < size; i++){
		star[i] = 0;
	}
	for(int i = 0; i < size; i++){
		cout << "User " << 1 + i << ": ";
		int num;
		cin >> num;
		rate[i] = num;
		avg += num;
		star[num-1] += 1; 
	}
	avg = avg / size;
	cout << "Average rating: " << avg << endl;
	cout << "Rating Distribution: " << endl;
	for(int i = 0; i < size; i++){
		cout << 1 + i << "- star: " << star[i] << endl;
		
	}
	
	
	
	return 0;
}
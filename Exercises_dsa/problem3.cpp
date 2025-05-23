#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	int size = 7;
	double avg;
	cout << "Enter steps for 7 days: " << endl;
	int steps[size];
	
	for(int i = 0; i < size; i++){
		cout << "Day " << 1 + i << ": ";
		int num;
		cin >> num;
		steps[i] = num;
		avg += num;
	}
	cout << "Total Steps: " << avg << endl;
	int highest = steps[0], lowest = steps[0];
	for(int i = 0; i < size; i++){
		if(highest < steps[i]) highest = steps[i];
		if(lowest > steps[i]) lowest = steps[i];
	}
	avg = avg / size;
	cout << "Average Steps: " << avg << endl;
	
	for(int i = 0; i < size; i++){
		if(highest == steps[i]){
			cout << "Most Active Day (Day " << i+1 << "): " <<  steps[i] << endl;
		}
		if(lowest == steps[i]){
			cout << "Least Active Day (Day " << i+1 << "): " <<  steps[i] << endl;
		}
	}
	
	int count = 0;
	for(int i = 0; i < size; i++){
		if(steps[i] >= 10000){
			count++;
		}
	}
	cout << "Days Goal Met (>= 10,000 steps): " << count << endl;
	
	
	
	return 0;
}
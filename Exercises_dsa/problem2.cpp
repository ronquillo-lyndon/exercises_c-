#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	int size;
	double avg;
	cout << "Enter number of students: ";
	cin >> size;
	int student[size];
	cout << "Enter grades: " << endl;
	for(int i = 0; i < size; i++){
		cout << "Student " << 1 + i << ": ";
		int num;
		cin >> num;
		student[i] = num;
		avg += num;
	}
	int highest = student[0], lowest = student[0];
	for(int i = 0; i < size; i++){
		if(highest < student[i]) highest = student[i];
		if(lowest > student[i]) lowest = student[i];
	}
	avg = avg / size;
	cout << "Average Grade: " << avg << endl;
	cout << "Highest Grade: " << highest << endl;
	cout << "Lowest Grade: " << lowest << endl;
	int count = 0;
	for(int i = 0; i < size; i++){
		if(student[i] >= 70){
			count++;
		}
	}
	cout << "Number of Passing Students: " << count << endl;
	if(count == 0){
		cout << "No student pass." << endl;
	}  
	
	
	return 0;
}
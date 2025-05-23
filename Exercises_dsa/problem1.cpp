#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	int size = 3;
	int arr_num[size];
	int num;
	double avg = 0;
	cout << "Enter the temperatures for 7 days: " << endl;
	for(int i = 0; i < size; i++){
		cout << "Day " << i+1 << ": ";
		cin >> num;
		arr_num[i] = num; 
	}
	
	int hotest = arr_num[0], coldest = arr_num[0];
	for(int i = 0; i < size; i++){
		if(hotest < arr_num[i]) hotest = arr_num[i];
		if(coldest > arr_num[i]) coldest = arr_num[i];
		avg += arr_num[i];
	}
	avg = avg / size;
	cout << "Average Temperature: " << avg << endl;
	
	for(int i = 0; i < size; i++){
		if(hotest == arr_num[i]){
			cout << "Hotest Day (Day " << i + 1 << "): " << hotest << endl;
		}
		if(coldest == arr_num[i]){
			cout << "Coldest Day (Day " << i + 1 << "): " << coldest << endl;
		}
	}
	int thresh = 0;
	int count = 0;
	cout << "Enter Threshold temperature: ";
	cin >> thresh;
	cout << "Days above threshhold temperature: ";
	for(int i = 0; i < size; i++){
		if(thresh < arr_num[i]) count++;
	}
	cout << count;
	return 0;
}
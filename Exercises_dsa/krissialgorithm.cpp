#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


// function - converting the inputs into an array
// funciton - converting the array back to an int
// create a function that will minus the real input to its sorted one
// size 


int size(int num){
	int i = 0;
	int n = num;
	while(n > 0){
		n /= 10;
		i++;
	}
	return i;
}

int reverse(int num, int size){
	return 0;	
}

int *numToArr(int num, int size){
	int n = num;
	int *arr = new int[size];
	int i = 0;
	while(n > 0){
		arr[i] = n % 10;
		n /= 10;
		i++;
	}
	return arr;
}
int arrToNum(int *arr, int size){
	
	int num = 0; 
	int mult = 1;
	for(int i = size - 1; i >= 0; i--){
		num += arr[i] * mult;
		mult *= 10;
	}
	
	return num;
}


void sort(int *arr, int size){
	
	int temp = 0;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size - i - 1; j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
}

 
int main(int argc, char** argv) {
	int num;
	cout << "Please enter a number: ";
	cin >> num;
	
	int diff = num;
	while(diff > 0){
		int s = size(diff);
		int *array = numToArr(diff, s);
		sort(array, s);
		int newNum = arrToNum(array, s);
		cout << "the difference of " << diff << " and " << newNum << " is ";
		diff = diff - newNum;
		cout << diff << endl;
	}
	
	
	return 0;
}


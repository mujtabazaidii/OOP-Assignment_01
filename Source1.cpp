#include<iostream>
using namespace std;
int** fillArr(int r) {
	int c = 0;
	int** p = new int* [r]; // filling of array 
	int size = 0;
	for (int i = 0; i < r; i++) {
		cout << "Enter Values: " << endl;
		for (int j = 0; j < c; j++) {
			// input 2-D array
		}
	}
	return p;
}

int* twoDimToOneDim(int** p, int& r, int& c, int& c_size) {// takes these initials to perform operation

	int* s = new int[c_size];
	int k = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {//2d to 1d
			s[i * c + j] = p[i][j]; // converted to 1_d
		}
	}
	return s;
}
int* SortArr(int* p, int& size) {//takes an array to sort it 
	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)   // bubble sorting easy way to sort
		{
			if (*(p + i) > *(p + j))// sorting in ascending order
			{
				temp = *(p + i);//store in a variable and change its position one by one 
				*(p + i) = *(p + j);
				*(p + j) = temp;
			}
		}
	}
	int* l = new int[size];
	for (int i = 0; i < size; i++) { // copying the sorted array 
		*(l + i) = *(p + i);
	}
	return l; // to take output from show function
}
void ShowArr(int* t, int& size) {

	for (int i = 0; i < size; i++) { // simple way to show array
		cout << *(t + i);
		cout << " ";
	}
}
void DeallocateArr(int* t, int& size) {

	delete[] t;
}
int main1() {
	int r, c = 0;
	cout << "Enter Rows: ";
	cin >> r;
	int** p = new int* [r]; // filling of array 
	int size = 0;
	for (int i = 0; i < r; i++) {
		cout << "Enter Coulomns of " << i << " rows: ";// input coloumns
		cin >> c;
		p[i] = new int[c];// initialize array
		cout << endl;
		size += c;
		cout << "Enter Values: " << endl;
		for (int j = 0; j < c; j++) {
			cin >> p[i][j];// input 2-D array
		}
	}
	cout << endl;
	int* n = twoDimToOneDim(p, r, c, size); // call the funtion to perform task
	cout << endl;
	int* m = SortArr(n, size); // for sorting of array 
	cout << endl;
	cout << "Given Array in 1-D is : " << endl << endl;
	ShowArr(m, size); // output of the array 
	cout << endl;
	DeallocateArr(m, size);
	cout << endl << endl << endl << endl << endl;

	return 0;
}
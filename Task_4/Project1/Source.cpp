#include <iostream>
#include <ctime>
#include <algorithm>

const int a = 20;// переменные для заполнения матрицы
const int b = 10;
const int z = 20;// переменные для заполнения массива 
const int x = 10;
using namespace std;


int** matrixСreation(int rows, int cols);
void fillingMatrix(int** matrix, int rows, int cols);
void printMatrix(int** matrix, int rows, int cols);
void deleteMatrix(int** matrix, int rows, int cols);
int sumMatrix(int** matrix, int rows, int cols);
int** matrixXmatrix1(int** matrix, int** matrix1, int rows, int rows1, int cols, int cols1);
int* arrCreationAndFilling(int size);
void printArr(int* arr, int size);
void replacement(int* arr, int size, int* c);
double medianArr(int* arr, int size);
int* matrixToArr(int** matrix, int rows, int cols);



int main() {
	srand(time(NULL));
	
	int rows, cols, rows1, cols1;
	cout << "enter rows ";
	cin >> rows;
	cout << "enter cols ";
	cin >> cols;
	int** matrix = matrixСreation(rows, cols);
	fillingMatrix(matrix, rows, cols);
	printMatrix(matrix, rows, cols);
	cout << sumMatrix(matrix,rows, cols)<<endl;
	cout << sumMatrix(matrix, rows, cols) / ((rows * cols)/1.) << endl; // sumMatrix() отработает 2 раза ну и ладно 
	cout << "enter rows1 ";
	cin >> rows1;
	cout << "enter cols1 ";
	cin >> cols1;
	int** matrix1 = matrixСreation(rows1, cols1);
	fillingMatrix(matrix1, rows1, cols1);
	printMatrix(matrix1, rows1, cols1);
	int** matrix2 = matrixXmatrix1(matrix, matrix1, rows, rows1, cols, cols1);
	printMatrix(matrix2, rows, cols1);
	deleteMatrix(matrix2, rows, cols1);
	deleteMatrix(matrix1, rows1, cols1); 

	int size, c = 0;
	cout << "enter size ";
	cin >> size;
	int* arr = arrCreationAndFilling(size);
	printArr(arr, size);
	sort(arr, arr + size);
	replacement(arr, size,&c);
	sort(arr, arr + size);
	size -= c;
	printArr(arr, size);
	cout << medianArr(arr, size);
	delete[] arr;

	
	int *arr = matrixToArr(matrix, rows, cols);
	int s = rows * cols-1;
	printArr(arr, s);
	sort(arr, arr + s);
	printArr(arr, s);
	cout << medianArr(arr, s)<<endl;
	cout << "min = " << arr[0]<<endl;
	cout << "max = " << arr[s]<<endl;

	
	deleteMatrix(matrix, rows, cols);


	return 0;
}



int** matrixСreation(int rows, int cols) {
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}
	return matrix;

}

void fillingMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = rand() %a - b;
		}
	}
	
}

void printMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << std::endl;
	}
}

void deleteMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

 int sumMatrix(int** matrix, int rows, int cols) {
	int a=0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			a += matrix[i][j];
		}
	}
	return a;
}

 int** matrixXmatrix1(int** matrix, int** matrix1, int rows, int rows1, int cols, int cols1) {
	 int** matrix2 = matrixСreation(rows, cols1);
	 for (int i = 0; i < rows; i++) 
	 {
		 for (int j = 0; j < cols1; j++)
		 {
			 for (int k = 0; k < rows1; k++) 
			 {
				 matrix2[i][j] = matrix[i][k] * matrix1[k][j];
			 }
		 }
	 }
	 return matrix2; 
 }

 int* arrCreationAndFilling(int size) {
	 int* arr = new int[size];
	 for (int i = 0; i < size; i++)
	 {
		 arr[i] = rand() % z - x;
	 }
	 return arr;
 }
 

 void replacement(int* arr, int size, int* c) {
	 int j = 1;
	 for (int i = 0; i < size; i++)
	 {
		 if (arr[i] == arr[j]) {
			 arr[i] = z - x;
			 (*c)++;
		 }
		 j++;
	 }
 }

 void printArr(int* arr, int size){
	 for (int i = 0; i < size; i++)
	 {
		cout << arr[i]<<" ";
	 }
	 cout << endl;
 }

 double medianArr(int* arr, int size) {
	 if (size % 2 == 1) {
		 return arr[(size / 2)];
	}
	 else {
		 return (arr[(size / 2) - 1] + arr[size / 2]) / 2.;
	 }

 }

int* matrixToArr(int** matrix, int rows, int cols) {
	int* arr = new int[rows*cols];
	int k = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[k] = matrix[i][j];
			k++;
		}
	}
	return arr;
 }

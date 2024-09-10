#include <iostream>
#include <fstream> 

//function declaration
int indexPresent(int arr[], int file_size, int num);
void modifyValue(int value, int new_value, int arr[], int file_size);
void addValue(int*& arr, int& file_size, int value);
void removeValue(int arr[], int file_size, int index); 


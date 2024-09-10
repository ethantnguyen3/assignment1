#include <iostream>
#include <fstream> 
#include "assignment1.h" 

//PRE: Takes in an array, the size of the array, and a value to search for
//POST: Returns the index of the value if it is in the array, otherwise returns -1
int indexPresent(int arr[], int file_size, int num) {
  //Finds the index of the value to be modified and prints error if the index is out of range
  if (num < 0 || num >= file_size) {
      throw std::out_of_range("Index is out of range.");
  }
    for (int j = 0; j < file_size; ++j) {
        if (arr[j] == num)
            return j;
    }
    return -1;
}
//PRE: Takes in the index of the value to be modified, the new value, the array, and the size of the array 
//POST: Modifies the value at the given index to the new value
void modifyValue(int value, int new_value, int arr[], int file_size) {
    //Finds the index of the value to be modified and prints error if the index is out of range
    if (value < 0 || value >= file_size) {
        throw std::out_of_range("Index is out of range.");
    }
    //Block of code that modifies the value at the given index
    int old_value; 
    old_value = arr[value]; 
    arr[value] = new_value; 
    std::cout << old_value << " has been replaced with " << new_value << " at index " << value << std::endl;
}
//PRE: Takes in the array, the size of the array, and the value to be added 
//POST: Adds the value to the end of the array and increases the size of the array
void addValue(int*& arr, int& file_size, int value) {
    try {
    // Allocate new memory for the new array
    int* new_arr = new int[file_size + 1];

    // Copy existing elements to the new array
    for (int i = 0; i < file_size; ++i) {
        new_arr[i] = arr[i];
    }

    // Add the new value
    new_arr[file_size] = value;

    // Delete old array and point to the new array
    delete[] arr;
    arr = new_arr;

    // Update file_size
    file_size++;
    } 
    catch (const std::bad_alloc& e) {
            throw; // Re-throw the memory allocation failure
        }
}
//PRE: Takes in the array, the size of the array, and the index of the value to be removed 
//POST: Removes the value at the given index and decreases the size of the array
void removeValue(int arr[], int file_size, int index) {
  //Finds the index of the value to be modified and prints error if the index is out of range
  if (index < 0 || index >= file_size) {
      throw std::out_of_range("Index is out of range.");
  }
    int i;
    //locates the index of the value to be removed 
    for(i = 0; i < file_size; i++) {
        if (i == index) 
            break;
    }
    //Block of code that removes the value at the index and shifts the remaining values to the left before decreasing the array size
    if (i < file_size) {

        for (int j = i; j < file_size; j++) 
            arr[j] = arr[j + 1]; 
        file_size--; 

    }
}



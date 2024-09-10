// NAME: Ethan Nguyen DATE: 9/9/2024 ASSIGNMENT 1
#include <iostream>
#include <fstream> 
#include "assignment1.h"
//function declaration

int main() {
    //variable declarations
    bool fileRead = false; 
    std::string fileName;  
    std::ifstream inputFile;
    try {
    //prompt user for file name and sends an error message if file does not exist before continuing
    while (fileRead == false) {
        std::cout << "Name an existing file: " << std::endl; 
        std::cin >> fileName;
        inputFile.open(fileName);
        if (!inputFile) {
            std::cerr << "Error opening file!" << std::endl;
            continue;
        
        }
        fileRead = true;
    }
    // Initial array size
    int file_size = 0;
    int* arr = nullptr;

    // Read data from file to populate the array
    int i;
    while (inputFile >> i) {
        addValue(arr, file_size, i);
    }
    inputFile.close();
    
    int choice = 0; 
    //present options for user to choose from
    while (choice != 5) {
        std::cout << "\nWhat would you like to do with the array?" << std::endl; 
        std::cout << "0. See if value is in the array" << std::endl;
        std::cout << "1. Add a value" << std::endl; 
        std::cout << "2. Remove a value" << std::endl; 
        std::cout << "3. Modify a value" << std::endl; 
        std::cout << "4. Print the array" << std::endl; 
        std::cout << "5. Quit" << std::endl; 
        std::cin >> choice; 
        if (choice > 5 || choice < 0) { //error message if user enters invalid choice
            std::cout << "Invalid choice. Please try again." << std::endl; 
            continue;
        } 
        else if (choice == 0) { 
            //check if value is in array and prints out result
            int num; 
            std::cout << "\nEnter a value to search for: " << std::endl; 
            std::cin >> num;
            int index = indexPresent(arr, file_size, num); 
            //error message if value does not exist in array
            if (index != -1)
                std::cout << "\nThe value " << num << " is at index " << index << std::endl; 
            else  
                std::cout << "\nThe value " << num << " is not in the array" << std::endl;
        } 
        else if (choice == 1) {
            //add value to array and prints what value has been added
            int addNum;
            std::cout << "\nEnter a value to add: " << std::endl; 
            std::cin >> addNum; 
            addValue(arr, file_size, addNum);    
            std::cout << "\nThe value " << addNum << " has been added to the array." << std::endl;
        } 
        else if (choice == 2) {
            //remove value from array based on index and prints what value has been removed
            int removeNum; 
            std::cout << "\nEnter an index to remove the corresponding value: " << std::endl; 
            std::cin >> removeNum; 
            int old_value = arr[removeNum];
            removeValue(arr, file_size, removeNum);
            std::cout << "\nThe value " << old_value << " has been removed from the array." << std::endl;
            file_size--;
        }
        else if (choice == 3) { 
            //modify value in array based on index and prints the old and new value
            int value, new_value; 
            std::cout << "\nEnter an index to modify: " << std::endl;  
            std::cin >> value; 
            int index = indexPresent(arr, file_size, value); 
            std::cout << "\nEnter a new value: " << std::endl; 
            std::cin >> new_value; 
            modifyValue(arr[index], new_value, arr, file_size);
            
        }     
        else if (choice == 4) { 
            //prints the whole array
            for (int i = 0; i < file_size; i++) {
                std::cout << arr[i] << " ";
            } 
            std::cout << std::endl;
        }
    }
    
    
    // Clean up to prevent memory leaks
    delete[] arr;
    std::cout << "Thank you for using the program!" << std::endl;
    }
    //error messages notifying user what went wrong based on their input in the given functions
    catch (const std::bad_alloc& e) {
        std::cerr << "Memory Allocation Error: " << e.what() << std::endl;
    } 
    catch (const std::out_of_range& e) {
        std::cerr << "Out of Range Error: " << e.what() << std::endl;
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Invalid Argument: " << e.what() << std::endl;
    } 
    catch (...) {
        std::cerr << "Error" << std::endl;
    }
    
    return 0;
    
}

#include "GroceryTracker.h"

using namespace std;

void GroceryTracker::readInputFile(const string& filename) {
    // Reading the inputfile
    ifstream inputFile(filename);
    string item;
   // If input file is not avaialbe 
    if (!inputFile) {
        // Throw error 
        throw runtime_error("Error opening input file.");
    }

    while (inputFile >> item) {
        itemFrequency[item]++;
    }

    inputFile.close();
}
// Writing the frequencies in backup file
void GroceryTracker::writeBackupFile(const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile) {
        throw runtime_error("Error creating backup file.");
    }

    for (const auto& pair : itemFrequency) {
        outputFile << pair.first << " " << pair.second << endl;
    }

    outputFile.close();
}
// Searching the item and displaying
void GroceryTracker::searchForItem() {
    cout << "Enter the item to search for: ";
    string searchItem;
    cin >> searchItem;
    cout << searchItem << " " <<  itemFrequency[searchItem] << endl;
}
// Printing the them item 
void GroceryTracker::printItemList() {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " " << pair.second << endl;
    }
}
// Prints the histogram of items frequencies using asterisks
void GroceryTracker::printHistogram() {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}

void GroceryTracker::displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Search for an item." << endl;
    cout << "2. Print the list of items." << endl;
    cout << "3. Print histogram of items." << endl;
    cout << "4. Exit the program." << endl;
    cout << "Enter your choice: ";
}
// Displaying the main menu
void GroceryTracker::run() {
    try {
        readInputFile("input.txt");

        int choice;
        do {
            displayMenu();
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid option." << endl;
                continue;
            }

            switch (choice) {
                case 1:
                    searchForItem();
                    break;
                case 2:
                    printItemList();
                    break;
                case 3:
                    printHistogram();
                    break;
                case 4:
                    cout << "Exiting the program." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please enter a valid option." << endl;
            }

            // Clear the remaining input in the buffer
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');

        } while (choice != 4);

        writeBackupFile("frequency.dat");
    } catch (const exception& e) {
        cout << "An error occurred: " << e.what() << endl;
    } catch (...) {
        cout << "An Error has occurred." << endl;
    }
}


#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <limits>

using namespace std;

class GroceryTracker {
private:
    // // Map to store item frequencies.
    map<std::string, int> itemFrequency;
    // Declaration of private member 
    void readInputFile(const string& filename);
    void writeBackupFile(const string& filename);
    void searchForItem();
    void printItemList();
    void printHistogram();
    void displayMenu();

public:
   // Declaration of private member to run the code. 
    void run();
};

#endif

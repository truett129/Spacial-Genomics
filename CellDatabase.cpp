#include <iostream>
#include <string>
#include <sstream>
#include "CellDatabase.h"
#include "CellData.h"
#include <fstream>

using std::cout;
using std::string;
using std::fstream;
using std::ofstream;
using std::endl;
using std::ifstream;
using std::istringstream;

// Default constructor/destructor. Modify them if you need to.
CellDatabase::CellDatabase() {}
CellDatabase::~CellDatabase() {}


void CellDatabase::loadData(const string& filename) 
{
    // Implement this function
    ifstream fin(filename);
    if (!fin.is_open()) {
        cout << "Error: Unable to open";
    } 
    string line = "";

    getline(fin,line);
    istringstream sin(line);
}

// Do not modify
void CellDatabase::outputData(const string& filename) {
    ofstream dataout("sorted." + filename);

    if (!dataout.is_open()) 
    {
        cout << "Error: Unable to open " << filename << endl;
        exit(1);
    }
    dataout << records.print();
}

void CellDatabase::performQuery(const string& filename) 
{
    // Implement this function
}

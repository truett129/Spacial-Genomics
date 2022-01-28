#include <iostream>
#include "CellDatabase.h"
#include "string"

using std::endl;
using std::cout;
using std::string;

int main(int argc, char** argv) 
{
    /*
    LinkedList list;
    list.insert("123", 0, 1, 2, 3, 4, 5, 6, 7);
    list.insert("122", 1, 1, 4, 7, 6, 5, 4, 3);
    list.insert("22", 2, 9, 8, 7, 6, 5, 4, 3);
    string hell;
    list.remove("123", 0, 1, 2, 3, 4, 5, 6, 7);
    //list.remove("122", 1, 1, 4, 7, 6, 5, 4, 3);
    //list.remove("22", 2, 9, 8, 7, 6, 5, 4, 3);
    hell = list.print();
    cout << hell;
    
    LinkedList list2(list);
    
    string hello;
    hello = list2.print();
    cout << hello << endl;
    */
   
    
    
    if (argc < 3) 
    {
        cout << "Usage: " << argv[0] << " data_file query_file" << endl;
		    return 1;
    } 
    else 
    {
        CellDatabase database;
        database.loadData(argv[1]);
		    database.performQuery(argv[2]); 
	  	  database.outputData(argv[1]); 
    }
    

    return 0;
}

#include "file_systems.h"
#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <map>
#include <stdlib.h> //random

//#include <stdlib.h>
//#include <utility>

using namespace std;
int main(){
    
    ofstream ofs("drive.txt");
    ofs << "test test" << endl;
    ofs.close();
    
    /*
    cout << "Type 'exit' to close the terminal." << endl;
    cout << "Type 'help' for help." << endl;

    string input;
    while(true){
        cin >> input;
        if(input == "exit"){
            break;
        }
        else if(input == "help"){
            help();
        }
    }

    */
   //cout << "Enter the name of your file." << endl;
  // getline(cin, FILE_NAME);
  createLinkedList();
   cout << "Enter the content of your file: " << endl;
   getline(cin, FILE_CONTENT);
   TEMP_DATA = convertFileContentIntoBlocks(FILE_CONTENT);
   for(int i=0;i<TEMP_DATA.size();i++){
       cout<<TEMP_DATA[i] << endl;
   }
   randomlyAssignFileContent(TEMP_DATA);
   return 0;
}
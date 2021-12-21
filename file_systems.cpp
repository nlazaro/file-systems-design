#include "file_systems.h"
#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <map>
#include <stdlib.h>
#include <cctype>

//#include <stdlib.h>
//#include <utility>

using namespace std;
int main(){
    string input;
    // Checks for allocation type
    while(ALLOCATION_TYPE_ACCEPT != 1){
        cout << "What type of allocation type would you like to use?\n Type 'Linked List' or 'Index list': " << endl;
        getline(cin, input);
        ALLOCATION_TYPE = makeLowerCase(input);
        if(ALLOCATION_TYPE == "linked list"){
            cout << "You have chosen linked list, and your disk will be called 'drive1.txt'.\n";
            ALLOCATION_TYPE_ACCEPT = 1;
                }
        else if(ALLOCATION_TYPE == "index list"){
            cout << "You have chosen index list and your disk will be called 'drive2.txt'.\n";
            ALLOCATION_TYPE_ACCEPT = 1;
                }
        else{
            cout << "Invalid entry, try again.\n";
            ALLOCATION_TYPE = "";
                }
            }
    cout << "'root' is your root directory." << endl;
    // The main area of the terminal
    while(true){
        cout << "Type 'exit' to close the terminal." << endl;
        cout << "Type 'help' for help." << endl;
        input = "";
        getline(cin, input);
        input = makeLowerCase(input);
        if(input == "exit") return 0;
        else if(input == "help") help();
        /*else if(input == "ls")
        else if(input == "cd")
        else if(input == "du")
        else if(input == "mkdir")
        else if(input == "rmdir")
        else if(input == "create")
        else if(input == "write")
        else if(input == "read")
        else if(input == "delete")
        */
    }
   cout << "Enter the name of your file." << endl;
   /*getline(cin, FILE_NAME);
   createLinkedList();
   cout << "Enter the content of your file: " << endl;
   getline(cin, FILE_CONTENT);
   TEMP_DATA = convertFileContentIntoBlocks(FILE_CONTENT);
   for(int i=0;i<TEMP_DATA.size();i++){
       cout<<TEMP_DATA[i] << endl;
   }
   randomlyAssignFileContent(TEMP_DATA);
   */
   return 0;
}
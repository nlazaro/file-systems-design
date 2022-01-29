//#include "file_systems.h"
#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <map>
#include <stdlib.h>
#include <cctype>
#include <filesystem>
#include <cstdint>
#include <iterator>

//#include <stdlib.h>
//#include <utility>

using namespace std;
int main(){
    string input;
    bool tree = true;
    // Checks for allocation type
    while(tree == true){
        cout << "What type of allocation type would you like to use?\n Type 'Linked List' or 'Index list': " << endl;
        getline(cin, input);
        ALLOCATION_TYPE = makeLowerCase(input);
        if(ALLOCATION_TYPE == "linked list"){
            cout << "You have chosen linked list, and your disk will be called 'drive1.txt'.\n";
            ALLOCATION_TYPE_ACCEPT = 1;
            tree = false;
                }
        else if(ALLOCATION_TYPE == "index list"){
            cout << "You have chosen index list and your disk will be called 'drive1.txt'.\n";
            ALLOCATION_TYPE_ACCEPT = 2;
            tree = false;
                }
        else{
            cout << "Invalid entry, try again.\n";
            ALLOCATION_TYPE = "";
                }
    }
    cout << "'root' is your root directory." << endl;
    // The main area of the terminal
    tree = true;
    LinkedList obj1;
    //creates brand new 'drive' file and closes it
    ofstream obj2("drive.txt", ios::trunc);
    obj2.close();
    while(tree == true){
        cout << "Type 'exit' to close the terminal." << endl;
        cout << "Type 'help' for help." << endl;
        input = "";
        getline(cin, input);
        input = makeLowerCase(input);
        if(input == "exit") return 0;
        else if(input == "help") help();
        else if(input == "ls")ls();
        else if(input == "cd")cd();
        else if(input == "du"){
            uintmax_t size = filesystem::file_size("drive.txt");
            cout << "Current size of drive: " << size << endl;
            cout << "Current size of inodes: " << INODE.size() << endl;
            cout << "Current amount of data blocks used: " << ((FAT.size() / 2) + 1) << " " << "out of 5120 total blocks." << endl;
            //cout << "Current size of file " << 
        }
        else if(input == "mkdir"){
            cout << "Enter name of new directory: " << endl;
            getline(cin, NEW_DIRECTORY);
            updateDirectory(CURRENT_DIRECTORY, NEW_DIRECTORY);
            cout << "Directory created.\n";
        }
        else if(input == "rmdir"){
            cout << "Are you sure you want to delete the current directory: " << CURRENT_DIRECTORY << endl;
            deleteDirectory(CURRENT_DIRECTORY);
            cout << "Directory deleted.\n"
        }
        else if(input == "create"){
            cout << "Enter the name of your file." << endl;
            getline(cin, FILE_NAME);
            cout << "File created.\n";
        }
        else if(input == "write"){
            cout << "Enter the content of your file: " << endl;
            getline(cin, FILE_CONTENT);
            //Converts content into blocks and places them into inode and FAT
            TEMP_DATA = obj1.convertFileContentIntoBlocks(FILE_CONTENT);
            obj1.randomlyAssignFileContent(FILE_NAME, TEMP_DATA);
            cout << "File closed.\n";
        }
        else if(input == "read"){

        }
        else if(input == "delete"){
            deleteFile(FILE_NAME);
            cout << "File deleted.\n";
        }
    }

   return 0;
}
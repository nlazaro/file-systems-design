#ifndef FILE_SYSTEMS
#define FILE_SYSTEMS

#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <map>
#include <stdlib.h> //random


using namespace std;

const int BLOCK_LIMIT = 8;
const int MAX_MEMORY = 5120;
string FILE_NAME;
string FILE_CONTENT;
vector<string> TEMP_DATA = {};
map<int,int> FAT;

// Creates the node class for linked lists
class Node{
    public:
    int BLOCK_NUMBER;
    string DATA;
    bool FREE_NODE = 0;
    Node* NEXT_PTR;
};

// Displays the help commands on the terminal
void help(){
    cout << "Avaliable commands: \n"
        << "pwd                         Displays full path of current directory.\n"
        << "ls                          Displays all filesin current directory.\n"
        << "cd                          Moves current directory.\n"
        << "du                          Displays memory of specified file.\n"
        << "mkdir                       Creates directory.\n"
        << "rmdir                       Deletes directory.\n"
        << "create                      Creates file.\n"
        << "write                       Writes inside of the file.\n"
        << "read                        Reads inside of the file.\n"
        << "help                        Shows this command list.\n"
        << "exit                        Exits this terminal screen.\n";
}

// Converts user input for file content into 8 byte blocks
vector<string> convertFileContentIntoBlocks(string file_content){
    string TEMP_HOLDER = "";
    vector<string> data = {};
    int position = 0;
    int block_limit_copy = BLOCK_LIMIT - 1;
    // loops through file content
    for(position; position < file_content.size(); position++){
        TEMP_HOLDER += file_content[position];
        // adds into blocks using vector
        if(block_limit_copy == position){
            data.push_back(TEMP_HOLDER);
            TEMP_HOLDER = "";
            block_limit_copy += 7;
            }
        }
        // adds remiaining contents
        data.push_back(TEMP_HOLDER);
        return data;
    }

// Creates a linked list limit of 5,120 blocks
void createLinkedList(){
    // Creates head node
    Node* head_ptr = new Node;
    Node* temp_ptr;
    Node* last_ptr;

    head_ptr->BLOCK_NUMBER=0;
    head_ptr->NEXT_PTR = nullptr;
    last_ptr = head_ptr;

    //Creates the remaining 5,119 nodes
    for(int i = 1; i < MAX_MEMORY - 1; i++){
        // Creates new node
        temp_ptr = new Node;
        // Places data into node
        temp_ptr->BLOCK_NUMBER = i;
        temp_ptr->NEXT_PTR = nullptr;
        // Last_ptr's next pointer points to the new node
        last_ptr->NEXT_PTR = temp_ptr;
        last_ptr = temp_ptr;
    }
    /*
    //TESTING//
    //prints out all nodes
    Node* p = head_ptr;
    while(p!= nullptr){
        cout << p->BLOCK_NUMBER << " " << p->FREE_NODE << " ";
        p = p->NEXT_PTR;
        cout << "->";
    delete p;
    */
}

// Randomly Assigns blocks towards file content and saves on FAT table
void randomlyAssignFileContent(vector<string> data){
    int assigned_block_number;
    int following_block_number;
    for(int i = 0; i < data.size(); i++){
        assigned_block_number = rand() % 5120; //excludes the final node on purpose
        following_block_number = rand() % 5120;
        updateFAT
    }
    
}

// Updates FAT table
void updateFAT(int start_address, int pointer_towards_next_block){
    FAT.insert(pair<int,int>(start_address, pointer_towards_next_block));
}

// Checks FAT for unused blocks
bool checkFAT(int address){

}
    /* maps
    map<int,int> fat;
    fat.insert(pair<int,int>(1,3));
    fat.insert(pair<int,int>(3,2));
    fat.insert(pair<int,int>(2,-1));

    map<int,int>::iterator itr;
    for(itr=fat.begin();itr!=fat.end();itr++){
        cout<<itr->first<<" "<<itr->second<<endl;
    }
    */
#endif
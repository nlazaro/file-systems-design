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
bool ALLOCATION_TYPE_ACCEPT = 0;
string input;
string ALLOCATION_TYPE;
string FILE_NAME;
string FILE_CONTENT;
vector<string> TEMP_DATA = {};
map<string,int> INODE;
map<int,int> FAT;

// Creates the node class for linked lists
class Node{
public:
    int BLOCK_NUMBER;
    string DATA;
    bool FREE_NODE = 0;
    Node* NEXT_PTR;
};

class LinkedList{
private:
    Node* head_ptr;
    Node* last_ptr;
    Node* temp_ptr;
public:
    LinkedList();
    vector<string> convertFileContentIntoBlocks(string file_contents);
    void updateInode(string fileName, int startingAddress);
    void updateFAT(int start_address, int pointer_towards_next_block);
    int checkNode(Node *n, int key);
    int RandomBlock(int data);
    void randomlyAssignFileContent(string fileName, vector<string> data);
    ~LinkedList();
    
};

// Creates a linked list limit of 5,120 blocks
LinkedList::LinkedList(){
    head_ptr = new Node;
    head_ptr->BLOCK_NUMBER = 0;
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

LinkedList::~LinkedList(){
    Node* p = head_ptr;
    while(head_ptr){
        head_ptr = head_ptr->NEXT_PTR;
        delete p;
        p = head_ptr;
    }
}

// Converts user input for file content into 8 byte blocks
vector<string> LinkedList::convertFileContentIntoBlocks(string file_content){
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

void LinkedList::updateInode(string fileName, int startingAddress){
    INODE.insert(pair<string,int>(fileName, startingAddress));
}

// Updates FAT table
void LinkedList::updateFAT(int start_address, int pointer_towards_next_block){
    FAT.insert(pair<int,int>(start_address, pointer_towards_next_block));
}

// Checks nodes for unused blocks
int LinkedList::checkNode(Node *n, int key){
    while(n!=NULL){
        if(key==n->BLOCK_NUMBER){
          n->FREE_NODE;
          if(0==n->FREE_NODE){ //node is free to use
            n->FREE_NODE=1; //change to used
            return 1; //success
        }
        else{
          return 0; //node is in use;
          }
        }
        n=n->NEXT_PTR;
    }
    return 0;
}

// Assign random avalible block unit
int LinkedList::RandomBlock(int random_data){
    random_data = rand() % 5120;
    if(checkNode(head_ptr, random_data) == 0){
       RandomBlock(random_data);
    }
    return random_data;
}

// Randomly Assigns blocks towards file content and saves on FAT table
void LinkedList::randomlyAssignFileContent(string fileName, vector<string> data){
    int starting_block_number;
    int following_block_number;
    int temp;
    starting_block_number = RandomBlock(0);
    updateInode(fileName, starting_block_number);
    for(int i=1; i < data.size(); i++){
        starting_block_number = RandomBlock(i);
        if(data.size() > 0){
            following_block_number = RandomBlock(i+1);
            i++;
            updateFAT(starting_block_number, following_block_number);
            }
        }
    following_block_number = -1;
    updateFAT(starting_block_number, following_block_number);
}

/////////////////////
// returns input in lower case
string makeLowerCase(string word){
    string temp = "";
    for(int i = 0; i < word.length(); i++){
        temp += tolower(word[i]);
        }
    return temp;
}

// Displays the help commands on the terminal
void help(){
    cout << "Avaliable commands: \n"
        << "pwd                         Displays full path of current directory.\n"
        << "ls                          Displays all files in current directory.\n"
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
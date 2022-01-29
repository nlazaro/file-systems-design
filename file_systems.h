#ifndef FILE_SYSTEMS
#define FILE_SYSTEMS

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


using namespace std;

const int BLOCK_LIMIT = 8;
const int MAX_MEMORY = 5120;
int ALLOCATION_TYPE_ACCEPT = 0;
string input;
string ALLOCATION_TYPE;
string FILE_NAME;
string FILE_CONTENT;
string NEW_DIRECTORY;
string CURRENT_DIRECTORY;
vector<string> TEMP_DATA = {};
map<string,int> INODE;
map<int,int> FAT;
unordered_map<string, string> DIRECTORY;
multimap<string, string> DIRECTORY;

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
    void updateFAT2(int start, int next);
    int checkNode(Node *n, int key);
    int RandomBlock(int data);
    void randomlyAssignFileContent(string fileName, vector<string> data);
    void deleteNodes(int key);
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

// Keeps track of file and their starting block address
void LinkedList::updateInode(string fileName, int startingAddress){
    INODE.insert(pair<string,int>(fileName, startingAddress));
}

//linked allocation
// Keeps track of linked blocks for a file
void LinkedList::updateFAT(int start_address, int pointer_towards_next_block){
     FAT.insert(pair<int,int>(start_address, pointer_towards_next_block));
    }
}

//index allocation
void LinkedList::updateFAT2(int start, int next){
    FAT.insert(pair<int,int>(start, next));
    Node* n->next;
    Node* last2->
}

void LinkedList(){
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
    int secondary_block_number;
    starting_block_number = RandomBlock(0);
    //Creates listing for file name and starting address
    updateInode(fileName, starting_block_number);
    following_block_number = RandomBlock(1);
    //Creates lising for starting address and following blocks
    if(ALLOCATION_TYPE == 1){
        updateFAT(starting_block_number, following_block_number);
    }
    else{
        updateFAT2(starting_block_number, following_block_number);
    }
    /////
    for(int i=2; i < data.size(); i++){
        secondary_block_number = RandomBlock(i);
        i++;
        updateFAT(following_block_number, secondary_block_number);
        following_block_number = secondary_block_number;
        }
    secondary_block_number = -1;
    if(ALLOCATION_TYPE == 1){
        updateFAT(following_block_number, secondary_block_number);
    }
    else{
        updateFAT2(following_block_number, secondary_block_number);
    }
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

// Keeps track of directory
void updateDirectory(string location, string files){
    DIRECTORY.insert(pair<string, string> (location, files));
}

// Deletes directory and files within them
void deleteDirectory(string location){
    for(auto x : DIRECTORY)
        if(x.first == location){

        }
}

// Deletes current file
void deleteFile(string fileName){
    for (auto itr = INODE.begin(); itr != INODE.end(); itr++) {
        if(fileName == itr->first){
            deleteFAT(itr->second);
            INODE.erase(fileName);
        }
}
}
// Deletes file blocks and frees blocks
void LinkedList::deleteNodes(Node *n){
    while(n!=NULL){
        if(key==n->BLOCK_NUMBER){
            n->DATA=NULL;
            n->FREE_NODE=0;
            }
        n->NEXT_PTR;
        }
}


// Deletes records from FAT table & Inode table

void deleteFAT(Node *n){
    for(auto x: FAT){
        if(x.second != -1){
            deleteNodes(n->BLOCK_NUMBER);
            x == x.second;
        }
    }
}

map<int,int>::iterator itr{
    for(itr=FAT.begin();itr!=FAT.end();itr++){
        cout << itr->first << " " << itr->second << endl;
    }
    cout << "FIRST DONE" << endl;
    int num = 123, erase_num, temp;
    while(bool tree = 1){
    for (itr = FAT.begin(); itr != FAT.end(); ++itr) {
        if(num==itr->first){
            temp = itr->second;
            erase_num = FAT.erase(num);
            if(temp == -1){
                tree = 0;
            }
        }
    }
    num = temp;
    }
    for(itr=FAT.begin();itr!=FAT.end();itr++){
        cout << itr->first << " " << itr->second << endl;
    }
}

void deleteInode(string location){
    for (auto itr = INODE.begin(); itr != INODE.end(); itr++) {
        if(fileName == itr->first){
            deleteFAT(itr->second);
            INODE.erase(fileName);
        }
        }
}

// writes data to drive.txt file
void writeToFile(data){
    ofstream my_file;
    my_file.open("drive.txt", ofstream::app);
    my_file << data;
    my_file.close();
}

//spilts data from drive.txt into four parts: superblock, inodes, FAT table, and all data blocks with "*!*!" being splitter
void spiltString(){
    int pos;
    string spilt = "!*!*", temp, temp_file, temp_file_1, temp_file_2, temp_file_3, temp_file_4;
    ifstream my_file("drive.txt", ifstream::app);
    getline(my_file, temp_file);
    pos = temp_file.find(spilt);
    temp_file_1 = temp_file.substr(0, pos); //hello world
    temp = temp_file.substr(pos + 1);

    pos = temp.find(spilt);
    temp_file_2 = temp.substr(3, pos);
    temp_file = temp.substr(pos + 1);

    pos = temp_file.find(spilt);
    temp_file_3 = temp_file.substr(3, pos);
    temp_file_4 = temp_file.substr(pos + 1);

     cout << "1" << temp_file_1 << endl;
     cout <<  "2" << temp_file_2 << endl;
     cout << "3" << temp_file_3 << endl;
     cout << "4" << temp_file_4 << endl;
     
     my_file.close();
}

void freeLink(string table, int lhead, lsize){
    int ltail=gettail(table);
    int ntail=getLinkTail(lhead,lsize);
    return;
}

void createFile(string fileName, string content) {
    fstream fs;
    content += EOF_;
    fs.open(SYSTEM_FILE_NAME_);
    string table;
    getline(fs, table);
    int s = table.find('~') + 1;
    table = table.substr(s);
    if (fileName.find("/") != npos || fileName.find("-") != npos || fileName.find(" ") != npos) {
            cout << "Invalid symbol entered." << endl;
            fs.close();
            return;
        }
    int size = int(content.size() / BLOCK_SIZE_) + (content.size() % BLOCK_SIZE_ != 0);
    fs.close();
    vector<string> c = splitToBlocks(content);
    if (c.size() > getFreeBlocks(table)) {
        cout << "Not Enough Space" << endl;
        return;
        }
        return;
}

 string readBlock(int pos, int ptr) {
        fstream fs;
        fs.open(SYSTEM_FILE_NAME_);
        string return_ = "";
        fs.seekg(pos + ptr * (BLOCK_SIZE_ + PTR_LEN_L_));
        char c;
        for (size_t i = 0; i < BLOCK_SIZE_; i++) {
            fs.get(c);
            outp += c;
            if (c == EOF_) {
                fs.close();
                return return_;
            }
        }
        fs.close();
        return return_;
    }
}
map<int,int> fat{
    fat.insert(pair<int,int>(1,3));
    fat.insert(pair<int,int>(3,2));
    fat.insert(pair<int,int>(2,-1));

    map<int,int>::iterator itr;
    for(itr=fat.begin();itr!=fat.end();itr++){
        cout<<itr->first<<" "<<itr->second<<endl;
    }
}
#endif
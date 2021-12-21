#include <iostream>
#include <vector>
#include <map>
#include <forward_list>
#include <string>
using namespace std;

class Node{
public:
    string data;
    Node* next;
};
 
int main() {

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
 
    vector<string> A={"hello", "hello2", "hello3"};
 
    Node* head = new Node;
 
    Node* temp;
    Node* last;
 
    head->data = A[0];
    head->next = nullptr;
    last = head;
 
    // Create a Linked List
    for (int i=1; i< A.size(); i++){
        
        // Create a temporary Node
        temp = new Node;
 
        // Populate temporary Node
        temp->data = A[i];
        temp->next = nullptr;
 
        // last's next is pointing to temp
        last->next = temp;
        last = temp;
        
    }
 
    // Display Linked List
    Node* p = head;
 
    while (p != nullptr){
        cout << p->data << " -> " << flush;
        p = p->next;
    }
 
    return 0;
}

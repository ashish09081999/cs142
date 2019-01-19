#include <iostream>
using namespace std;


class Node{
    public:
    // Data
    int data;
    // Pointer to the next Node and previous node
    Node * next;
    Node * prev;
    // Construct that makes the ptr to NULL
    Node(int value){
        next = NULL;
        prev = NULL;
        data = value;
    }
};

class DLL{
    public:
    Node * head;
    DLL(){
        head = NULL;
    }
    void insert(int value){
        // Create a new node
        Node * temp = new Node(value);
        // CHeck if empty list
        if(head == NULL){
            head = temp;
        }
        else{ // If not empty list.
            Node * current = head;
            //adjusting the pointers to insert the element
            while(current->next != NULL)
                current = current->next;
            current->next = temp;
            temp->prev = current;
        }
    }
    void display(){
        Node *current = head;
        Node *last;
        cout << "Print in   order : ";
        while(current!=NULL){
            cout <<current->data<< " -> ";
            // Store the current in last (to catch the tail to print in reverse)
            last = current;
            // Move Forward
            current = current->next;
        }
        cout<<"NULL";
        cout << endl;
        cout << "Print in Reverse order : ";
        while(last!=NULL){
            cout <<last->data<< " -> ";
            // Move backwards
            last = last->prev;
        }
        cout<<"NULL";
        cout << endl;
    }
    void InsertAt(int value, int pos){
        //checking that if the required position input is correct or not
        if(countItems()<(pos-1))
        {
            cout<<"Linked List does not have that many elements"<<endl;
        }
        else
        {
        // Reach the place before the position
        Node * current = head;
        int i =1;
        while(i < pos-1){
            i++;
            current = current->next;
        }
        // Create a node
        Node * temp = new Node(value);


        // Moving ptrs to the required position to insert the element
        temp->next = current->next;
        current->next->prev=temp;
        current->next = temp;
        temp->prev=current;
        }
    }
    void DeleteAt(int pos){
        //condition to check if the required position input to delete is correct or not
        if(countItems()<pos){
            cout<<"Element does not exist"<<endl;
        }
        else
        {
            //deleting at the position 1
            if(pos==1){
                Node * current = head;
                //moving the ptrs
                head= current->next;
                current->next->prev=NULL;
                //deleting the current
                delete current;
            }
            else
            {
        //finding element to delete at the specific position inputed
        Node * current = head;
        int i =1;
        while(i < pos){
            i++;
            current = current->next;
        }
        //shifting pointer to the before Node
        //finding element before delete element
        Node * current1 = head;
        int j =1;
        while(j < pos-1){
            j++;
            current1 = current1->next;
        }
        //shifting
        current1->next = current->next;
        current->next->prev=current1;
        //delete current
        delete current;
            }
        }
    }
    void Del(){
        // Deletes the last element.
        Node * current= head;
        Node * current1;
        while((current->next)->next != NULL){
            current = current->next;
        }
        //adding one more ptr to point to the last element of the linkedlist
        current1=current->next;
        current->next=NULL;
        current1->prev=NULL;
        //deleting the last element
        delete current1;
    }
    int countItems(){
        // Counts the Number of items.
        int i=1;
        // before tail has to point to null
        Node * current = head;
        while(current->next != NULL){
            current = current->next;
            i++;
        }
        return i;
    }


};

int main(){
    DLL dl;          //declaring a new double linkedlist
    for(int i= 1; i < 11; i++){
        dl.insert(i);
    }
    dl.display();
    dl.InsertAt(3,4);
    dl.display();
    dl.Del();
    dl.display();
    dl.DeleteAt(1);
    dl.display();
    dl.DeleteAt(3);
    dl.display();
    dl.Del();
    dl.display();
    cout<<endl;
    cout<<dl.countItems()<<endl;
}

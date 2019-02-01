#include <iostream>
using namespace std;

class Node{
    public:
    // Data
    int data;
    // Pointer to the next Node
    Node * next;
    // Construct that makes the ptr to NULL
    Node(){
        next = NULL;
    }

};

class LinkedList{

    public:
    // head & tail Node type ptr
    Node * head;
    Node * tail;

    // Constructor
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    // Rules how circles will be linked
    //1. Insertion
    void insert(int value){
       // first new Node is created
       Node * temp = new Node;
       // Insert value in the node
       temp->data = value;
       //if new Node is 1st Node.
       if(head == NULL){
            head = temp;
       }
       //for Any other Node only.
       else{
            tail->next = temp;
       }
       tail = temp;
    }
        //insertion at some position
    void insertAt(int pos, int value){
        //checking that if the required position input is correct or not

            Node * temp = new Node;
                temp->data=value;

            if (pos==1)
            {
                if(head==NULL)
                {
                    head=temp;
                    tail=temp;
                }
                else{

                Node * current = head;
                temp->next=current;
                head=temp;}
            }

    }

    // Deletion of last element
    void delet(){
        // store the tail in temp
        Node * temp = tail;
        // before tail has to point to null
        Node * current = head;
        while(current->next != tail){
            current = current->next;
        }
        current->next = NULL;

        // update tail
        tail = current;
        // delete temp
         delete temp;
    }
    //Deletion at some position
    void deletAt(int pos){
        //condition to check if the required position input to delete is correct or not
        if(countItems()<pos){
            cout<<"Element does not exist"<<endl;
        }
        else
        {
            //deleting at the position 1
            if(pos==1){
                Node * current = head;
                head= current->next;
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
        //delete current
        delete current;
            }
        }
    }
    //count items
    int countItems(){
        int i=1;
        // before tail has to point to null
        Node * current = head;
        while(current->next != NULL){
            current = current->next;
            i++;
        }
        return i;
    }
    // Display
    void display(){
        Node * current = head;
        while(current != NULL){
            cout << current->data << "->";
            current = current->next;
        }
        cout <<"NULL"<<endl;
    }
};




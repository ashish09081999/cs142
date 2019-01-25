#include <iostream>
using namespace std;


class Node{
    public:
    // Data
    int data;
    // Pointer to the next Node
    Node * next;
    // Construct that makes the ptr to NULL
    Node(int value){
        next = NULL;
        data = value;
    }
};

class CSLL{
    public:
    Node * head;
    CSLL(){
        head = NULL;
    }
    // Inserts to the end of the linked list.
    void insert(int value){

        // Create a new node
        Node * temp = new Node(value);
        // CHeck if empty list
        if(head == NULL){
            head = temp;
        }
        else{ // If not empty list.
            Node * current = head;
            while(current->next != head)
                {current = current->next;}
            current->next = temp;
        }
        temp->next = head;
    }
    // Displays the linked list.
    void display(){
        Node * current = head;
        if(current == NULL) {
            cout << "No elements " << endl;
            return;
        }
        while(current->next != head){ // Stopping at head
            cout << current -> data << "->";
            current = current -> next;
        }
        // Printing the last element
        cout << current -> data ;
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

        // Moving ptrs to the required position
        temp->next = current->next;
        current->next = temp;
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
                Node * current1 = head;
                //moving the ptrs
                head= current->next;
                while((current1->next)->next != head){
                    current1 = current1->next;
                }
                current1 -> next = head;
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
            //delete current
            delete current;
            }
        }

    }
    void Delet(){
        // Deletes the last element.
        Node * current= head;
        Node * current1;
        while((current->next)->next != head){
            current = current->next;
        }
        //adding one more ptr to point to the last element of the linkedlist
        current1=current->next;
        current->next=head;
        current1->next=NULL;
        //deleting the last element
        delete current1;
    }
    int  countItems(){
        int i=1;
        Node * current= head;
        while(current->next != head)
        {
            i++;
            current=current->next;
        }

        return i;
    }

};

int main(){
    CSLL csll1;
    //inserting the elements 1 to 10
    for(int i= 1; i < 11; i++){
       csll1.insert(i);
    }
    csll1.display();
    // inserting at a intermediate position
    csll1.InsertAt(2,3);
    csll1.display();
    // deleting the element at the last position
    csll1.Delet();
    csll1.display();
    // deleting the element at the 1st position
    csll1.DeleteAt(1);
    csll1.display();
    // deleting the element at any other position
    csll1.DeleteAt(3);
    csll1.display();
    // counting the no of elements in the linkedlist
    cout<<"The no. of elements in the Circular Linkedlist is : "<<csll1.countItems();
}


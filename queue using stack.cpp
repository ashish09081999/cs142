//queue using stacks
#include <iostream>
using namespace std;
class Node
{
    public:
    int data;//stores the data
    Node* next;//pointer to the next node
    public:
    Node()//default constructor
    {
        data=0;//data inilialized to 0
        next=NULL;//pointer initialized to null
    }
};
class Stack
{
    public:
    Node* top;//top is a node type pointer to the first element of the stack
    public:
    Stack()//default constructor
    {
        top=NULL;//initializes top to null
    }
    void push(int value)//function to push an elemnt into the stack
    {
        Node* temp=new Node;//new node created of Node type
        temp->data=value;//data stores the value to be stored in the node
        if(isEmpty()==true)//if the stack is empty
        top=temp;//add first element
        else
        {
            temp->next=top;//ptr to pushed at the top of the list
            top=temp;
        }
    }
    int pop()//function to pop an element into the stack
    {
        int del=0;//stores the value of the popped one
        if(isEmpty()==true)//if the stack is empty
        return -9999;
        else
        {
            Node* temp=top;
            del=temp->data;//the value at the topmost node is stored
            top=top->next;//top is moved to the next element in the stack
            temp->next=NULL;  //the first element is removed from the stack
            delete temp;
            return del;//the deleted value is returned
        }
    }
    bool isEmpty()//function to check if a stack is empty or not
    {
        if(top==NULL)//if top is null
        return true;
        else
        return false;
    }
    int size()//function to count the number of elements in the stack
    {
        int count=0;
        Node* temp=top;//pointer to traverse the list
        while(temp!=NULL)//till bottom is reached
        {
            temp=temp->next;//pointer moves forward
            count++;//number of elements incremented
        }
        return count;
    }
    void display()//display function
    {
        Node* temp=top;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";//the data is printed
            temp=temp->next;//the pointer is moved forward
        }
        cout<<endl;
    }
    void displayRev()//displays the stack in the reverse order
    {
        displayRev(top);
    }
    void displayRev(Node* temp)//method to print the elements of the stack in the reverse order
    {
        if(temp->next==NULL)//when the end of the stack is reached
        cout<<temp->data<<", ";//the element is displayed
        else
        {
            displayRev(temp->next);//using recursion
            cout<<temp->data<<", ";//the value of the element in stack is printed
        }
    }
    int topValue()//function to return the value at the top of the stack
    {
        if(isEmpty()==true)//if the stack is empty
        return -9999;
        else
        return top->data;//the first element is returned
    }
};
//definr a class as queuefromstack
class QueueFromStack
{
    public:
    Stack s1;
    public:
    void enqueue(int num)
    {
	s1.push(num);// pushed into the stack
    }
    void dequeue()
    {
		if(s1.size()==0)//if the queue is empty then there is nothing to dequeue
        cout<<"Stack Underflow.\n";
		else if(s1.size()==1)//else the last element is popped from the stack
		cout<<s1.pop()<<" has been dequened.\n";
       	else
		{
	    int poppedValue=s1.pop();//each element is popped from the stack and stored
	    dequeue();//the next element is dequeued
            s1.push(poppedValue);//the stored element is later pushed back into the stack
		}
    }
    void display()
    {
        s1.displayRev();//the stack is displayed from bottom to top
    }
};
int main()
{
    cout<<"Quene Object."<<endl;
    QueueFromStack queue1;//object of Queue class created
    int choice=0;
    int val=0;
    cout<<"Enter 1 to enqueue an element."<<endl;
    cout<<"Enter 2 to dequeue an element."<<endl;
    cout<<"Enter 3 to display the elements of the queue."<<endl;
    cout<<"Enter 0 to exit.";
    do
    {
    	cout<<endl;
        cout<<"Enter your choice."<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1 :cout<<"Enter the value to be enqueued."<<endl;
                    cin>>val;
                    queue1.enqueue(val);
		    cout<<val<<" has been enqueued."<<endl;
                    break;
            case 2 :queue1.dequeue();
                    break;
            case 3 :cout<<endl;
			        queue1.display();
                    break;
            case 0 :break;
            default:cout<<"Enter a valid integer."<<endl;
        }
    }while(choice!=0);
    return 0;
}

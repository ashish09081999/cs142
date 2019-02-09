#include<iostream>
#include "class3.cpp"

using namespace std;

class queue{
public:
    Node * front;
    Node * end;
    LinkedList l1;
    queue()
    {
        front=NULL;
        end=NULL;
    }
    void enqueue(int value)
    {
        l1.insertAt(1,value);
        front=l1.head;
        end=l1.tail;
    }
    void dequeue()
    {


        l1.delet();
        front=l1.head;
        end=l1.tail;

    }
    bool isEmpty()
    {
        if(front == NULL)
            return true;
        return false;
    }
    int size()
    {
        l1.countItems();
    }
    void display()
    {
        l1.display();
    }
    void frontDisplay()
    {
	if(l1.head==NULL)
	{	cout<<"The Queue has no element"<<endl;
	}
	else
	{	cout<<"The front element is "<<l1.head->data<<endl;
	}
    }
    void endDisplay()
    {
	if(l1.tail==NULL)
	{	cout<<"The Queue has no element"<<endl;
	}
	else
	{	cout<<"The front element is "<<l1.tail->data<<endl;
	}
    }


};

int main()
{
    queue q1;
    for(int i=0;i<4;i++)
    {
        q1.enqueue(i);
    }
    q1.display();
    q1.dequeue();
    q1.display();
    q1.dequeue();
    q1.display();
    q1.dequeue();
    q1.display();
    q1.dequeue();
    q1.display();


    cout<<q1.isEmpty()<<endl;
    cout<<q1.size()<<endl;
    q1.frontDisplay();
    q1.endDisplay();

}

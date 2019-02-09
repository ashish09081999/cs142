#include<iostream>
using namespace std;

class Node
{
    public:
    int data;//stores the data
    Node* next;//pointer to the next node
    public:
    Node(int value)//default constructor
    {
        data=value;//data inilialized to 0
        next=NULL;//pointer initialized to null
    }
};

class queue
{
public:
    Node * front;
    Node *end;
    queue()
    {
        front=NULL;
        end=NULL;
    }
    void enqueue(int value)
    {
        Node * temp=new Node(value);
        if(front==NULL)
        {
            front=temp;
        }
        else
        {
            end->next=temp;
        }
        end=temp;
    }
    int dequeue()
    {
        int del=0; //initaialising the value which will be deleted
        if(front==NULL && front==end)
        {
            return -9999;
        }
        else
        {
            Node * temp=front;
            del=temp->data;
            front=front->next;
            temp->next=NULL;
            delete temp;
            return del;
        }
        //return del;
    }
    bool isEmpty()
    {
        if(front == NULL)
            return true;
        return false;
    }
    int size()
    {
        if(isEmpty()==true)
        return 0;
        else
        {
            int counter=1;//variable to store the number of elements in the queue
            Node* temp=front;//pointer to traverse the list
            do//till the end of the queue is reached
            {
                temp=temp->next;//pointer moves forward
                counter++;//number of elements incremented
            }while(temp!=end);
            return counter;//number of elements returned
        }
    }
    void display()
    {
        if(front==NULL)
        {
            cout<<"The stack is empty"<<endl;
        }
        else
        {
            Node *current=front;
            while(current != NULL)
            {
                cout<<current->data<<"->";
                current=current->next;
            }
            cout<<"NULL"<<endl;
        }
    }
    int frontDisplay()
    {
        if(isEmpty()==true)
        {
            return -9999;
        }
        else
        {
            return front->data;
        }
    }
    int endDisplay()
    {
        if(isEmpty()==true)
        return -9999;
        else
        return end->data;
    }
};

class stackfromqueue
{
public:
    queue q1;
    queue q2;
    void push(int value)
    {
        q1.enqueue(value);
        while(q1.frontDisplay() != value)
        {
            q1.enqueue(q1.dequeue());
        }
    }
    void pop()
    {
         q1.dequeue();
    }
    void display()
    {
        q1.display();
    }
    bool isEmpty()
    {
        q1.isEmpty();
    }
    int size()
    {
        return q1.size();
    }
    int topDisplay()
    {
        return q1.frontDisplay();
    }
};

int main()
{
    stackfromqueue s1;
    for(int i=0;i<6;i++)
    {
        s1.push(i);
    }
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();        //poping element
    s1.display();
    cout<<s1.isEmpty();      //displaying if empty or nt
    cout<<endl;
    cout<<s1.size();     //displaying the size
    cout<<endl;
    cout<<s1.topDisplay();    //displaying the top element
}

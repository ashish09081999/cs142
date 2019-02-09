#include<iostream>
#include "class3.cpp"

using namespace std;
class stack{
    public:
    Node * top;
    LinkedList l1;
    stack()
    {
        top=l1.head;
    }
    //pushes on top
    void push (int value)
    {
        //void insertAt(int pos, int value)
        l1.insertAt( 1, value);
        top=l1.head;
        //top = new _head;
    }
    //pops the top
    void pop()
    {
        //void deletAt(int pos)
        l1.deletAt(1);
        top=l1.head;
        //top = new_head;
    }
    bool isEmpty()
    {
        if(top==NULL)
            return true;
        return false;
    }
    int size()
    {
       return l1.countItems();
    }
    void topDisplay()
    {
	if(l1.head==NULL)
	{	cout<<"The stack has no element"<<endl;
	}
	else
	{	cout<<"The top element is "<<l1.head->data<<endl;
	}


    }
    void display()
    {
        l1.display();
    }

};

int main()
{
    stack s1;
    for(int i=1;i<3;i++)
    {
        s1.push(i);

    }
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();
    s1.pop();
    s1.display();

    cout<<s1.isEmpty()<<endl;
    cout<<s1.size()<<endl;
    s1.topDisplay();
}

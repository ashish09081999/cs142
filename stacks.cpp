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
    int topDisplay()
    {

    }
    void display()
    {
        l1.display();
    }

};

int main()
{
    stack s1;
    for(int i=0;i<15;i++)
    {
        s1.push(i);

    }
    s1.display();
    s1.pop();
    s1.display();
    cout<<s1.isEmpty()<<endl;
    cout<<s1.size()<<endl;
}

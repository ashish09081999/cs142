#include<iostream>
using namespace std;

class stack
{
    int stk[100];   //declaring an array of size100
    int top;
    public:
    stack()
    {
        top=-1;          //initialising top
    }
    //function for insert of element
    void push(int value)
    {
        if(top >  99)
            {
                cout <<"No more place left in array to fill elements";
            }
        stk[++top]=value;
    }
    //function for deleting element
    void pop()
    {
        if(top <0)
        {
            cout<<"stack under flow";       //if no more element present to delete
            return;
        }
        else
        {
            stk[top--];
        }
    }
    //display function
    void display()
    {
        if(top<0)
        {
            return;
        }
        else{
            for(int i=top;i>=0;i--)
            cout <<stk[i] <<"->";}
    }
    //function to check if stack is empty
    bool isEmpty()
    {
        if(top<0)
            return true;
        return false;
    }
    //function to check no of elements
    int countItems()
    {
        return top+1;
    }
};

int main()
{

     stack s1;
     for(int i=0;i<2;i++)
     {
            s1.push(i);
     }
     s1.display();
     cout<<endl;
     s1.pop();
     s1.display();
     s1.pop();
     s1.display();
     cout<<endl;
     //if more elements are deleted than present
     s1.pop();
     s1.display();
     cout<<endl;
     cout<<s1.isEmpty();
     cout<<endl;
     cout<<s1.countItems();
     cout<<endl;
}

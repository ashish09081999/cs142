#include<iostream>
using namespace std;

class queue
{
    int arr[100];
    int front;
    int end;
    public:
    queue()
    {
        front=-1;       //initialising front and end
        end=-1;
    }
    //function for insert of element
    void enqueue(int value)
    {
        if(end>99)
        {
            cout<<"No more space in array to enter the element"<<endl;
            front=end=-1;
        }
        else
        {
            arr[++end]=value;
        }
    }
    //display function
    void display()
    {
        if(front==end)
        {
            return;
        }
        else
        {
            for(int i=front+1;i<=end;i++)
            {
                cout<<arr[i]<<"->";
            }
            cout<<endl;
        }
    }
    //function for deleting element
    void dequeue()
    {
        if(front==end)
        {
            cout<<"No element present to delete it";     //if no more element present to delete
        }
        else
        {
            arr[++front];
        }
    }
    //function to check if stack is empty
     bool isEmpty()
        {
            if(front==end)
                return true;
            return false;
        }
    //function to check no of elements
    int countItems()
        {
            return end;
        }
};

int main()
{
    queue q1;
    for(int j=0;j<2;j++)
    {
        q1.enqueue(j);
    }
    q1.display();
    q1.dequeue();
    q1.display();
    q1.dequeue();
    q1.display();
    //if more elements are deleted than present
    q1.dequeue();
    q1.display();
    cout<<endl;
    cout<<q1.isEmpty();
    cout<<endl;
    cout<<q1.countItems();
    cout<<endl;
}

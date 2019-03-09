#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    //children
    Node * left;
    Node * right;
    Node(int value)
    {
        data=value;
        left=NULL;
        right=NULL;
    }
};

class BinarySearchTree
{
public:
    Node * root;
    BinarySearchTree()
    {
        root=NULL;
    }

    void insert(int value)
    {
        //helper function to help in inserting
        inserthelper(root,value);
    }

    void inserthelper(Node * current, int value)
    {
        //base case if current is NULL ,insert there
        if(current==NULL)
        {
            Node * temp=new Node(value);
            if(root==NULL)
            {
                root=temp;
            }
            return;
        }
        //if value is less than the data of current
        if(value<current->data)
        {
            //if left is null
            if(current->left == NULL)
                current->left=new Node(value);
            //otherwise insert in it
            else
                inserthelper(current->left,value);
        }
        //if value is bigger
        else
        {
            //if right is null
            if(current->right  == NULL)
                current->right=new Node(value);
            //otherwise insert in it
            else
                inserthelper(current->right,value);
        }
    }

    void display()
    {
        //helper function to help in display
        display2(root);
        cout<<endl;
    }

    void display2(Node * current)
    {
        //base condition
        if(current==NULL)
            return;
        //display left
        display2(current->left);
        //display current
        cout<<current->data<<" , ";
        //display current
        display2(current->right);
    }

    Node * search(int value)
    {
        //helper function
        search2(root,value);
    }

    Node * search2(Node * current,int value)
    {
        //if value found or reached end of tree
        if(current==NULL || current->data==value)
            return current;
        if(value<current->data)
            search2(current->left,value);
        else
            search2(current->right,value);
    }
};
//driver function
int main()
{
    BinarySearchTree b1;
    b1.insert(3);
    b1.insert(34);
    b1.insert(45);
    b1.insert(37);
    b1.insert(8);
    b1.insert(2);
    b1.insert(99);
    b1.display();
    int n;
    cout<<"Enter the number you want to find in the tree"<<endl;
    cin>>n;
    if(b1.search(n) != NULL)
        cout<<"The entered value "<<n<<" is FOUND"<<endl;
    else
        cout<<"The entered value "<<n<<" is NOT FOUND"<<endl;
}

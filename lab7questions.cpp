#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    //children
    Node * left;
    Node * right;
    Node * parent;
    Node(int value)
    {
        data=value;
        left=NULL;
        right=NULL;
        parent=NULL;
    }
};

class BinarySearchTree
{
public:
    Node * root;
    //initialising the count
    int count=0;
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
                //increasing the count whenever new node is inserted
                count++;
            }
            return;
        }
        //if value is less than the data of current
        if(value<current->data)
        {
            //if left is null
            if(current->left == NULL) {
                Node * temp=new Node(value);
                current->left=temp;
                temp->parent=current;
                count++;
            }
            //otherwise insert in it
            else
                inserthelper(current->left,value);
        }
        //if value is bigger
        else
        {
            //if right is null
            if(current->right == NULL)
            {   Node * temp=new Node(value);
                current->right=temp;
                temp->parent=current;
                count++;
            }
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
     // count function
     int Count()
     {
         cout<<"The total no of nodes in the Binary search tree is "<<count<<endl;
         //returning the total count
         //return count;
     }

    void print2DUtil(Node *root, int space)
    {
        // Base case
        if (root == NULL)
            return;
        // Increase distance between levels
        space += 5;
        // Process right child first
        print2DUtil(root->right, space);

        // Print current node after space
        // count
        cout<<endl;
        for (int i = 5; i < space; i++)
            cout<<" ";
        cout<<root->data<<"\n";

        // Process left child
        print2DUtil(root->left, space);
    }

    // Wrapper over print2DUtil()
    void print2D()
    {
        cout << "******************************" << endl;
        // Pass initial space count as 0
        print2DUtil(root, 0);
        cout << "******************************" << endl;

    }
    //finding minimum of the tree
    Node * find_min(Node * current)
    {
        //starting the loop till the last element is reached on the left side which is the minimum value
        while(current->left != NULL)
        {
            current=current->left;
        }
        //checking if it is minimum value or not

        //returning the pointer at the minimum value
        return current;
    }

    int height()
    {
        //initialising to zero
		int a=0;
		heighthelper(root,1,a);
		cout<<"The height of the binary search tree is "<<a<<endl;
		return a;
	}
	//helper function to measure the height
	void heighthelper(Node*current,int i,int &p)
	{
	    //if nothing is parent
		if(current==NULL){
			if(p<i-1)
                p=i-1;
			else
                return;
		}
		else
        {
            //going to left side of the tree
			heighthelper(current->left,i+1,p);
            //going to right of the tree
			heighthelper(current->right,i+1,p);
		}
	}


    //function for replacing two different nodes
    void replaceatparent(Node * a,Node * b)
    {
        //for the left side
        if(a->parent->left==a)
        {
            a->parent->left=b;
        }
        //for the right side
        if(a->parent->right==a)
        {
            a->parent->right=b;
        }
        //if b is not empty then exchanging to a
        if(b != NULL)
        {
            b->parent=a->parent;
        }
        //if b is empty
        else
        {
            a->parent=NULL;
        }
    }
    //function to delete
   void delet(int value)
   {
       //making the returned node fro helper function to root
       root=delet(root,value);
       if(search(value) != NULL){
       cout<<"The value deleted from binary search tree is "<<value<<endl;}
   }

   Node * delet(Node * current, int value)
   {
       //if nothing is present in  the tree
       if(current == NULL)
       {
           cout<<"The value you want to delete is not present in the Binary Search Tree"<<endl;
           return current;
       }
       //if current data is same as value
       if(current->data==value)
       {
           //pointers
           Node * temp1=current->left;
           Node * temp2=current->right;
           //if no children
           if(temp1==NULL && temp2==NULL)
           {
               delete current;
               count--;
               return NULL;
           }
           //if right chilren only
           if(temp1==NULL)
           {
               delete current;
               count--;
               return temp2;
           }
           //if left children only
           if(temp2==NULL)
           {
               delete current;
               count--;
               return temp1;
           }
           //if both children
           else
           {
               //the minimum of the right subtree is moved to the current position with its left subtree being the current left subtree
               find_min(temp2)->left=temp1;
               delete current;
               count--;
               //the right subtree is attached to the current node
               return temp2;
           }
       }
       //if the value to the deleted is lesser than the value at the current node
       if(value<current->data)
           current->left=delet(current->left,value);//the node to be deleted might be on the left subtre
       //if the value to the deleted is greater than the value at the current node
       if(value>current->data)
           current->right=delet(current->right,value);//the node to be deleted might be on the right subtree
       //the current node is returned to be attached to the tree
       return current;
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
    else{
        cout<<"The entered value "<<n<<" is NOT FOUND"<<endl;}

    b1.Count();
    b1.print2D();
    b1.height();
    cout<<"The minimum of above tree is "<<b1.find_min(b1.root)->data<<endl;
    b1.delet(3);
    b1.print2D();
    cout<<"The minimum of above tree is "<<b1.find_min(b1.root)->data<<endl;
    b1.height();
    b1.Count();
    b1.delet(34);
    b1.print2D();
    cout<<"The minimum of above tree is "<<b1.find_min(b1.root)->data<<endl;
    b1.height();
    b1.Count();


}

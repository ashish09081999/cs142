
/*Binary heap*/
//the parent should be smaller or greater than all the children but not both
//for min parent<{l,r} and for max parent>{l,r}
//the next generation of node will come after filling the current generation
//
#include<iostream>
using namespace std;
//class Heap
class Heap{
	public:
	//pointer to array elements
	int *hArr;
	//maximum no of elements
	int mSize;
	//current size of array
	int cSize;
	//constructor
	Heap(int mSize){
		//create a new array
		hArr=new int[mSize];
		this->mSize=mSize;
		cSize=-1;
	}
	//getting parent
	int parent(int i){return (i-1)/2;}
	//getting left child
	int leftchild(int i){return 2*i+1;}
	//getting right child
	int rightchild(int i){return 2*i+2;}
	//swap function that swaps the values
	void swap(int &a,int &b){
		int t=a;
		a=b;
		b=t;
	}
	//insertions
	void insert(int value){
		cSize++;
		//if it is the first element
		if(cSize==0){hArr[cSize]=value;}
		else if(cSize==mSize) cout<<"There is no space to store the value."<<endl;
		else
        {
			//first insert at last
			hArr[cSize]=value;
			//find the value which is just smaller than this
			//compare for prop 2
			comparetoproperty(cSize);
		}
	}
		//prop_2_compare function that compares with the parent and swaps if needed
		void comparetoproperty(int i){
			//stoping condition
			//cout<<i<<"-,"<<endl;
			if(i==0) return;
			//it does in the way like if the parent is bigger than this child then it swaps
			else if(hArr[(i-1)/2]>hArr[i]) {
				swap(hArr[(i-1)/2],hArr[i]);
				//do recursion
				comparetoproperty((i-1)/2);
			}
			else return;
		}
		//MinHeapify function that swap with the child having minimum value
		void MinHeapify(int i){
			//stoping condition
			if(i>cSize) return;
			if(hArr[i]<hArr[2*i+1] and hArr[i]<hArr[2*i+2]) return;
			else if(2*i+1>cSize) return;
			else if(2*i+2>cSize and 2*i+1<=cSize) swap(hArr[i],hArr[2*i+1]);
			//compare with the children and replace accordingly
			else if(hArr[2*i+1]>hArr[2*i+2]) {
				swap(hArr[2*i+2],hArr[i]);
				MinHeapify(2*i+2);
			}
			else {
				swap(hArr[2*i+1],hArr[i]);
				MinHeapify(2*i+1);
			}
		}
		//getMin function that returns the value of the minimum
		int getMin(){
			return hArr[0];
		}
		//extract_min function that deletes the minimum function
		int extract_min(){
			return Delete(0);
		}
	//display function that displays the values
	void display(){
		for(int i=0;i<=cSize;i++){
			cout<<hArr[i]<<"->";
		}
		cout<<"NULL"<<endl;
	}
	//Delete function that deletes the value at that position
	int Delete(int a){
		if(a>cSize) cout<<"This position is not available"<<endl;
		else{
			int b=hArr[a];
			//if it is the the last element
			if(a==cSize) cSize--;
			else{
				//swap the values
				swap(hArr[a],hArr[cSize]);
				cSize--;
				MinHeapify(a);
			}
			return b;
		}
	}
	//when the value of an element is decreased at a given index
	void decreaseKey(int i,int new_value){
		//if the given value is greater than the older value
		if(hArr[i]<new_value)
            cout<<"The given value is greater than the older value."<<endl;
		else{
			hArr[i]=new_value;
			comparetoproperty(i);
		}
	}
};
//driver function
int main(){
    Heap bh1(20);
    for(int i = 10; i >0 ; i--){
        cout << "Inserting " << i << endl;
        bh1.insert(i);
        bh1.display();
    }
    bh1.extract_min();
    bh1.display();
    bh1.Delete(3);
    bh1.display();
    cout << endl;
    bh1.decreaseKey(4,11);
    bh1.display();
    bh1.decreaseKey(4,1);
    bh1.display();
}


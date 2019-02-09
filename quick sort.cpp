#include<iostream>
using namespace std;

//swapping function
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
//partition function
int part(int arr[],int low, int high)
{
    int pivot=arr[high]; //the pivot element for partitioning
    int i=(low-1);//indexing the smaller element
    for(int j=low;j<=high-1;j++)
    {
        if(arr[j]<=pivot)        //comparing the jth element with the pivot
        {
            i++;                 //incrementing i
            swap(&arr[i],&arr[j]);//swapping the jth element with the ith
        }
    }
    swap(&arr[i+1],&arr[high]);   //swapping i+1th element with pivot
    return i+1;                   //returning position of pivot

}
//quicksort function
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int a=part(arr,low,high);
        quicksort(arr,low,a-1);
        quicksort(arr,a+1,high);
    }
    if(low==high)
    {

    }
}

void display(int arr[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        cout<<arr[i]<<"->";
    }
    cout<<endl;
}

//driver function
int main()
{
    int arr[]={3,4,7,6,5,1,2,8,10,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    cout<<"The quicksorted array is"<<endl;
    display(arr,n);
    cout<<endl;

}

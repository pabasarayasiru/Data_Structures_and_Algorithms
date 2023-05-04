#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
    int maximum_Num = root;    //root
    int left_child = 2*root+1;   // left child
    int right_child = 2*root+2;  // right child


    if ( arr[left_child] > arr[maximum_Num]&& left_child < n)   // checking if left child is larger than root
    {
        maximum_Num =left_child;
    }

    if ( arr[right_child] > arr[maximum_Num] && right_child < n ) // checking if right child is larger than root
        maximum_Num= right_child;


    if (maximum_Num != root)   // checking if maximum number is not root
    {
        swap(arr[root], arr[maximum_Num]); // swap root and maximum number
        heapify(arr, n, maximum_Num);   // heapify operation for sub-tree
    }
}



// implementing heap sort
void heapSort(int arr[], int n)
{   int i;
   // build heap
   for (i = n/2-1; i >= 0;){
        heapify(arr, n, i);
        i--;
   }

    // extracting elements from heap one by one
    for (i = n-1; i >= 0;) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
        i--;
    }
}

/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
   int n;
   cout << "Enter your array length : ";
   cin>> n;
   cout<<endl;
   int heap_arr[n];
   cout << "Enter numbers in you array separated by space : ";
   for (int i=0; i < n;){        // get inputs
    cin>>heap_arr[i];
    i++;
   }
   cout<<endl;
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);

   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}

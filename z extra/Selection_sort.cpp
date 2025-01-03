#include <iostream>    
    
using namespace std;    
    
void selection(int arr[], int n)    
{    
    int i, j, small;    
        
    for (i = 0; i < n-1; i++) 
    {    
        small = i;      
        for (j = i+1; j < n; j++)    
        if (arr[j] < arr[small]){    
            small = j;
        }
        int temp = arr[small];    
        arr[small] = arr[i];    
        arr[i] = temp;    
    }    
}    
    
void printArr(int a[], int n)  
{    
    int i;    
    for (i = 0; i < n; i++)    
        cout<< a[i] <<" ";    
}    
    
int main()    
{    
    int a[] = { 80, 10, 29, 11, 8, 30, 15 };    
    int n = sizeof(a) / sizeof(a[0]);    
    cout<< "Before sorting array elements are - "<<endl;    
    printArr(a, n);    
    selection(a, n);    
    cout<< "\nAfter sorting array elements are - "<<endl;      
    printArr(a, n);    
    
    return 0;    
}  
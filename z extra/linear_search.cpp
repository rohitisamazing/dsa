#include<iostream>
using namespace std;

int ls(int a[], int n, int key) {
    for(int i=0; i=n-1;i++){
        if(a[i] == key){
            return i;
        }
        else {
            return -1;
        }
    }
}

int main(){
    int a[]={23,45,67,89,42};
    int n = sizeof(a)/sizeof(a[0]);
    int key = 42;
    int result=ls(a,n,key);
    if (result!=-1){
        cout<<"Element is present at index "<<result<<endl;
    }else{
        cout<<"Element is not present in array"<<endl;
    }
    return 0;
}
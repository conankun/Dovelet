#include<iostream> 
using namespace std; 
bool tobin(int n) { 
    int arr1[100]={0}; 
    int arr2[100]={0}; 
    int index=0; 
    while(n != 0) { 
        arr1[index++] = n%2; 
        n/=2; 
    } 
    int in=0; 
    for(int i=index-1;i>=0;i--) arr2[in++]=arr1[i]; 
    for(int i=0;i<index;i++) { 
        if(arr1[i] != arr2[i]) return false; 
    } 
    return true; 
} 
int main() { 
    for(int i=1;i<=100000;i++) { 
        if(tobin(i)) cout<<i<<endl; 
    } 
} 
 

#include<iostream> 
using namespace std; 
int main() { 
    int arr[7]; 
    int max=0; 
    int maxindex; 
    for(int i=0;i<7;i++)  
    { 
        cin>>arr[i]; 
        if(arr[i] > max)   
        {    
        max = arr[i]; 
        maxindex = i; 
        } 
  
    } 
  
    cout<<maxindex+1; 
  
    return 0; 
} 
 

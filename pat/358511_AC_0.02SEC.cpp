#include<iostream> 
using namespace std; 
int arr[31]={0}; 
int n,k; 
void bt(int index,int count) { 
    if(count == k) { 
        for(int i=0;i<n;i++) cout<<arr[i]; 
        cout<<endl; 
    } else { 
        for(int i=index+1;i<n;i++) { 
            arr[i]=1; 
            bt(i,count+1); 
            arr[i]=0; 
        } 
    } 
} 
int main() { 
    cin>>n>>k; 
    bt(-1,0); 
} 
 

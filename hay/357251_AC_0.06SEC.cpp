#include<iostream> 
using namespace std; 
int main() { 
    int n,q; 
    int arr[1001]; 
    cin>>n>>q; 
    for(int i=0;i<n;i++) { 
        cin>>arr[i]; 
    } 
    for(int i=0;i<q;i++) { 
        int a,b,s=0; 
        cin>>a>>b; 
        for(int i=a-1;i<=b-1;i++) s+=arr[i]; 
        cout<<s<<endl; 
    } 
} 
 

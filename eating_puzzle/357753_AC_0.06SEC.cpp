#include<iostream> 
#include<algorithm> 
using namespace std; 
  
int c,b,minc; 
int arr[21]; 
  
void bt(int i,int sum) { 
    sum+=arr[i]; 
    if(c-sum <= c-minc && sum<=c) minc=sum; 
    for(int j=i+1;j<b;j++) { 
        if(arr[i]+arr[j] <= c) { 
            bt(j,sum); 
        } else break; 
    } 
    return; 
} 
  
int main() { 
    cin>>c>>b; 
    minc=0; 
    for(int i=0;i<b;i++) cin>>arr[i]; 
    sort(arr,arr+b); 
    for(int i=0;i<b-1;i++) { 
        if(i <= c) 
        bt(i,0); 
    } 
    cout<<minc; 
} 
 

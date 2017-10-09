#include<iostream> 
using namespace std; 
int n; 
int arr[300]; 
int outputarr[300]; 
int in=99999; 
void bt(int index,int now) { 
    if(now == n) { 
        if(index < in) { 
            in = index; 
            for(int i=0;i<=index;i++) outputarr[i]=arr[i]; 
            return; 
        } 
    } else { 
        for(int i=index;i>=0;i--) { 
            if(arr[i]+now <= n && index+1 <= in) { 
                arr[index+1]=arr[i]+now; 
                bt(index+1,arr[i]+now); 
                arr[index+1]=0; 
            } 
        } 
    } 
} 
int main() { 
    cin>>n; 
    arr[0]=1; 
    bt(0,1); 
    for(int i=0;i<=in;i++) cout<<outputarr[i]<<" "; 
} 
 

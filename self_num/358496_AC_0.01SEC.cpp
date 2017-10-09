#include<iostream> 
using namespace std; 
int selfnum(int n) { 
    int sum=n; 
    while(n > 0) { 
        sum+=n%10; 
        n/=10; 
    } 
    return sum; 
} 
int vis[10001]={0}; 
int main() { 
    for(int i=1;i<=10000;i++) { 
        vis[selfnum(i)]=1; 
    } 
    for(int i=1;i<=10000;i++) { 
        if(vis[i] == 0) cout<<i<<endl; 
    } 
} 
 

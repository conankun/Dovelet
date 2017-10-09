#include<iostream> 
using namespace std; 
int a[100]; 
int b[100]; 
int dy[10001]={0}; 
int main() { 
    int w; 
    int n; 
    cin>>w>>n; 
    for(int i=0;i<n;i++) cin>>a[i]>>b[i]; 
    dy[0]=1; 
    int mx=0; 
    for(int i=0;i<n;i++) { 
        for(int j=w;j>=0;j--) { 
            if(dy[j] != 0) { 
                dy[j+a[i]]=max(dy[j]+b[i],dy[j+a[i]]); 
                if(dy[j+a[i]] > mx && j+a[i]<=w) mx = dy[j+a[i]]; 
            } 
        } 
    } 
    cout<<mx-1; 
} 
 

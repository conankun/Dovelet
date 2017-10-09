#include<iostream> 
using namespace std; 
int n,b,k; 
int map[1000][1000]={0}; 
int main() { 
    cin>>n>>b>>k; 
    for(int i=1;i<=n;i++) { 
        for(int j=1;j<=n;j++) { 
            cin>>map[i][j]; 
        } 
    } 
    for(int i=0;i<k;i++) { 
        int a,c; 
        cin>>a>>c; 
        int mx=0,mn=999999; 
        for(int i=a;i<a+b;i++) { 
            for(int j=c;j<c+b;j++) { 
                if(map[i][j] < mn) mn = map[i][j]; 
                if(map[i][j] > mx) mx = map[i][j]; 
            } 
        } 
        cout<<mx-mn<<endl; 
    } 
} 
 

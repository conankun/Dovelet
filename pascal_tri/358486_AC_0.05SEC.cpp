#include<iostream> 
using namespace std; 
int tri[1001][1001]={0}; 
int main() { 
    int n; 
    cin>>n; 
    tri[1][1]=1; 
  
    cout<<tri[1][1]<<endl; 
    for(int i=2;i<=n;i++) { 
        for(int j=1;j<=i;j++) { 
            tri[i][j]=tri[i-1][j]+tri[i-1][j-1]; 
            cout<<tri[i][j]<<" "; 
        } 
        cout<<endl; 
    } 
      
} 
 

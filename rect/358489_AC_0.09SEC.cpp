#include<iostream> 
using namespace std; 
int arr[1001][1001]={0}; 
int main() { 
    int a,b,c,d; 
    cin>>a>>b>>c>>d; 
    for(int j=b+1;j<=d;j++) { 
    for(int i=a+1;i<=c;i++) { 
        arr[i][j]=1; 
    } 
    } 
    cin>>a>>b>>c>>d; 
    for(int j=b+1;j<=d;j++) { 
    for(int i=a+1;i<=c;i++) { 
        arr[i][j]=1; 
    } 
    } 
    cin>>a>>b>>c>>d; 
    for(int j=b+1;j<=d;j++) { 
    for(int i=a+1;i<=c;i++) { 
        arr[i][j]=1; 
    } 
    } 
    cin>>a>>b>>c>>d; 
    for(int j=b+1;j<=d;j++) { 
    for(int i=a+1;i<=c;i++) { 
        arr[i][j]=1; 
    } 
    } 
    int t=0; 
    for(int i=0;i<1001;i++) { 
        for(int j=0;j<1001;j++) { 
            t+=arr[i][j]; 
        } 
    } 
    cout<<t; 
} 
 

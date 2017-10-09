#include<iostream> 
using namespace std; 
int s[101]={0}; 
int t[101]={0}; 
double abc[101]={0}; 
int main() { 
    int n,m; 
    cin>>n>>m; 
    for(int i=0;i<n;i++) { 
        int a,b; 
        cin>>a>>b; 
        int sum=0; 
        int arr[101]={0}; 
        for(int j=0;j<b;j++) { 
            int c,d; 
            cin>>c>>d; 
            arr[c]=d; 
            sum+=d; 
        } 
        for(int j=1;j<=100;j++) { 
            abc[j]+=(double)arr[j]/a; 
        } 
          
    } 
      
    double mx=0; 
    int in=1; 
    for(int i=1;i<=m;i++) { 
        if(abc[i] > mx) { 
            in = i; 
            mx = abc[i]; 
        } 
    } 
    cout<<in; 
} 
 

#include<iostream> 
using namespace std; 
int main() { 
    int r,s; 
    int arr[31][31]={0,}; 
    cin>>r>>s; 
    for(int i=0;i<r;i++) { 
        for(int j=0;j<=i;j++) { 
            if(s%10 == 0) s++; 
            arr[j][i] = s%10; 
            s++; 
        } 
    } 
      
    for(int i=0;i<r;i++) { 
        for(int j=0;j<r;j++) { 
            if(j!=0 && j != r) cout<<" "; 
            if(arr[i][j] == 0) cout<<" "; 
            else
            cout<<arr[i][j];   
        } 
        cout<<endl; 
    } 
  
} 
 

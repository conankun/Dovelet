#include<iostream> 
using namespace std; 
int main() { 
    int r,s; 
    int arr[101][101]={-1,}; 
    cin>>r>>s; 
  
    for(int i=1;i<=r;i++) { 
        if(s%10 ==0) s++; 
        arr[i][i]=s; 
        s++; 
    } 
      
    for(int i=2;i<=r;i++) { 
        for(int j=1;j<=r;j++) { 
            arr[j][i+(j-1)] = (arr[j+1][i+(j-1)]+arr[j][i+(j-1)-1])%10; 
        } 
    } 
  
  
    for(int i=1;i<=r;i++) { 
        bool a=false; 
        for(int j=1;j<=r;j++) { 
            if(j != 1) cout<<" "; 
            if(arr[i][j] == 0 && !a) cout<<" "; 
            else { 
            a=true; 
            cout<<arr[i][j]%10; 
            } 
        } 
        cout<<endl; 
    } 
  
} 
 

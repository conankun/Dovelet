#include <iostream> 
using namespace std; 
int main() { 
    int arr[501][101]; 
    int a,b; 
    cin>>a>>b; 
    for(int i=0;i<b;i++) for(int j=0;j<a;j++) cin>>arr[i][j]; 
      
    bool c=false; 
    for(int i=0;i<a;i++) { //행 
        int j; 
        int cc=0; 
        for(j=0;j<b;j++) { //열 
            if(arr[j][i] != 1) break; 
            else cc++; 
        } 
        if(cc == b) { 
            c=true; 
            break; 
        } 
    } 
  
    c==true?cout<<"yes":cout<<"no"; 
} 
 

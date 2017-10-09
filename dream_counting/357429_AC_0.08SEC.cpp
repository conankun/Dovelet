#include <iostream> 
using namespace std; 
  
int arr[10]={0,}; 
  
void jarisu(int n) { 
    for(;;){ 
        if(n<1) break; 
        else { 
        arr[n%10]++; 
        n/=10; 
        } 
    } 
} 
  
int main() { 
    int a,b; 
    cin>>a>>b; 
    for(int i=a;i<=b;i++) { 
        jarisu(i); 
    } 
  
    for(int i=0;i<10;i++) cout<<arr[i]<<" "; 
      
} 
 

#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
  
    int miles=0; 
    int lasttime=0; 
    int input; 
    int input2; 
    for(int i=0;i<n;i++) { 
        cin>>input>>input2; 
        miles += input * (input2-lasttime); 
        lasttime = input2; 
    } 
  
    cout<<miles<<" miles"; 
    return 0; 
} 
 

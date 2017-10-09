#include <iostream> 
using namespace std; 
int main() { 
    int a,b; 
    cin>>a>>b; 
      
    cout<<a*(b%10); 
    cout<<endl; 
    cout<<a*(b%100-b%10)/10; 
    cout<<endl; 
    cout<<a*(b/100); 
    cout<<endl; 
    cout<<a*b; 
    return 0; 
} 
 

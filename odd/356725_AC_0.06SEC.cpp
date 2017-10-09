#include <iostream> 
using namespace std; 
int main () { 
    int a; 
    int min = 2147483647; 
    int sum=0; 
    for(int i=0;i<7;i++) { 
        cin>>a; 
        if(a % 2 == 1) { 
            if(a < min) min = a; 
            sum+=a; 
        } 
    } 
      
    if(sum != 0) 
    cout<<sum<<endl<<min; 
    else
        cout<<sum-1; 
    return 0; 
} 
 

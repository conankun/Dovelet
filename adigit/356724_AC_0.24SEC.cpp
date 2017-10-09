#include <iostream> 
using namespace std; 
int main () { 
    int a; 
    int sum1=0; 
    int sum2=0; 
    int sum3=0; 
    for(int i=0;i<7;i++) { 
        cin>>a; 
        if(a / 100 > 0) sum3 +=a; 
            else if(a / 10 > 0) sum2 +=a; 
                else sum1+=a; 
    }  
      
    cout<<sum1<<" "<<sum2<<" "<<sum3; 
      
    return 0; 
} 
 

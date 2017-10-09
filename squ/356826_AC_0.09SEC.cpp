#include <iostream>  
using namespace std;  
int main() {  
        
     unsigned long long t,a,b;  
    cin>>a>>b;  
     unsigned long long aa=a,bb=b;  
     unsigned long long c;  
          
    unsigned long long gob = aa*bb;  
        
    if(a < b) {  
        do {  
            c = b%a;  
            b = a;  
            a = c;  
        }while(c!=0);  
        cout<<((gob/b)/aa) * ((gob/b)/bb);  
    } else {  
        do {  
            c = a%b;  
            a = b;  
            b = c;  
        }while(c!=0);  
        printf("%lld",((gob/a)/aa) * ((gob/a)/bb));  
    }  
        
    return 0;  
} 
 

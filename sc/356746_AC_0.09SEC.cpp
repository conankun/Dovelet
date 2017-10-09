#include <iostream> 
  
using namespace std; 
  
int main() { 
    int n; 
    int t=0; 
    int a=0,b=0,c=0,d=0,f=0; 
    for(;;) { 
        cin>>n; 
        if(n == -1) break; 
        else
        { 
            t++; 
            if(n <=100 && n >= 90) a++; 
            else if(n <=89 && n >= 80) b++; 
            else if(n <=79 && n >= 70) c++; 
            else if(n <=69 && n >= 60) d++; 
            else f++; 
        } 
  
    } 
    cout<<t<<endl; 
    cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl<<f<<endl; 
    return 0; 
} 
 

#include <iostream> 
using namespace std; 
int main () { 
    int a,b,c; 
    cin>>a>>b>>c; 
    if(a <= 168) printf("CRASH %d",a); 
    else if(b <= 168) printf("CRASH %d",b); 
    else if(c <= 168) printf("CRASH %d",c); 
    else cout<<"NO CRASH"; 
    return 0; 
} 
 

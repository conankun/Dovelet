#include <iostream> 
using namespace std; 
int main () { 
    int a,b,c,d; 
    float ab,cd; 
    cin>>a>>b>>c>>d; 
    ab = (float)a/(float)b; 
    cd = (float)c/(float)d; 
      
    if(ab > cd) cout<<1; 
    else if(ab == cd) cout<<0; 
    else if(ab<cd) cout<<-1; 
      
    return 0; 
} 
 

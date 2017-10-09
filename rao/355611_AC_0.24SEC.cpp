#include <iostream> 
using namespace std; 
int main () { 
    int a,b,c; 
    int max; 
    int oo,ot; 
    cin>>a>>b>>c; 
      
    if(a > b && a > c) { max = a; oo = b; ot = c; } 
    else if(b > a && b > c) { max = b; oo = a; ot = c; } 
    else { max = c; oo = a; ot = b; } 
      
      
    if(oo*oo+ot*ot == max*max) { 
        cout<<"right"; 
    } else if(oo*oo + ot*ot > max*max) { 
        cout<<"acute"; 
    } else if(oo*oo + ot*ot < max * max) { 
        cout<<"obtuse"; 
    } 
      
    return 0; 
} 
 

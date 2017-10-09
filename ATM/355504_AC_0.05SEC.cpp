#include <iostream> 
using namespace std; 
int main () { 
    int o; 
    float m; 
    cin>>o>>m; 
      
      
      
    if(o % 5 != 0.00) { 
        printf("%.2f",m); 
    } else if(o > m || o+0.5 > m) { 
        printf("%.2f",m); 
    } else { 
        printf("%.2f",m-o-0.5); 
    } 
      
      
      
    return 0; 
} 
 

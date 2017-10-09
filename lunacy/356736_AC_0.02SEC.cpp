#include <iostream> 
using namespace std; 
int main () { 
    float n; 
    for(;cin>>n,n!=-1.0;) { 
        printf("Objects weighing %.2f on Earth will weigh %.2f on the moon.\n",n,n*0.167); 
    } 
    return 0; 
} 
 

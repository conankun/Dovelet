#include <iostream> 
using namespace std; 
  
int main() { 
    for(int i=100;i<=999;i++) { 
        if(((i/100) * (i/100) * (i / 100)) + (((i-((i/100)*100))/10) * ((i-((i/100)*100))/10) * ((i-((i/100)*100))/10)) + ((i%10) * (i%10) * (i%10)) == i) { 
            cout<<i<<endl; 
        } 
    } 
    return 0; 
} 
 

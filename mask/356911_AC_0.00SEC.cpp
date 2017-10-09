#include <iostream> 
  
using namespace std; 
  
int main() { 
    for(int i=319;i<=399;i++) { 
  
          
        if(i+(i%10)*100+(i%10)*10 + i/100 == 1*1000+i/100*100+(i%100)/10*10+2) { 
            cout<<i<<endl; 
        } 
    } 
} 
 

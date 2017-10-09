#include <iostream> 
using namespace std; 
int main () { 
    int count=0; 
    for(int i=100;i<=999;i++) { 
        int one=i-((i/10)*10); 
        int two=i/10-((i/100)*10); 
        int three=i/100; 
        //cout<<three<<"-"<<two<<"-"<<one<<endl; 
        if(one > two && two > three) { 
            if(count % 5 == 0 && count !=0) cout<<endl; 
            if(count % 5 == 4) cout<<i; 
            else
            cout<<i<<" "; 
            count++; 
        } 
    } 
      
    return 0; 
} 
 

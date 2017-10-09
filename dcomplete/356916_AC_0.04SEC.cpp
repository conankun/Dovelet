#include <iostream> 
#include <cmath> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
    for(int i=1;i<n;i++){ 
        int sum=0; 
        for(int j=1;j<=sqrt(i);j++) { 
            if(j == i) break; 
              
            if(j == 1) sum+=j; 
            else { 
                if(i%j == 0) { 
                sum+=j; 
                sum+=i/j; 
                } 
            } 
        } 
          
        if(sum == i) cout<<i<<endl; 
    } 
    return 0; 
} 
 

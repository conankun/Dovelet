#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
    int max=0; 
    int maxsu; 
    for(int i=0;i<n;i++) { 
        int maxsoin=0; 
        int a; 
        int b; 
        cin>>a; 
        b=a; 
        for(int j=2;b>1;j==2?j++:j+=2) { 
            if(b%j == 0) { 
                while(b%j == 0) { 
                if(j > maxsoin) maxsoin = j; 
                b/=j; 
                } 
            } else continue; 
        } 
  
        if(maxsoin > max) { 
            maxsu = a; 
            max = maxsoin; 
        } 
  
    } 
  
    cout<<maxsu; 
} 
 

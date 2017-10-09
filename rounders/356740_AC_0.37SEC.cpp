#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    int jari; 
    cin>>n; 
    for(int i=1;;i*=10) { 
        if(n / i >= 1) { 
            jari = i; 
            continue; 
        } else break; 
    } 
      
      
    for(int i=10;i<=jari;i*=10) { 
        if(n-((n/i)*i) >= i/2) { 
            n-=n-((n/i)*i); 
            n+=i; 
        } 
    } 
    if(n % jari >= jari/2 && jari != 1) { 
        cout<<(n/jari)*jari+jari; 
    } else { 
        cout<<(n/jari)*jari; 
    } 
      
    return 0; 
} 
 

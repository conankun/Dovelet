#include <iostream> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
    for(int i=0;i<n;i++) { 
        int k; 
        cin>>k; 
        int a,hap=0; 
        for(int j=0;j<k;j++) { 
            cin>>a; 
            if(j == 0) { 
                hap+=a; 
            } else { 
                hap+=(a-1); 
            } 
        } 
  
        cout<<hap<<endl; 
    } 
} 
 

#include<iostream> 
using namespace std; 
void pTp(int h) { 
    if(h == 1) { 
        cout<<h; 
        return; 
    } else { 
        pTp(h-1); 
        cout<<h; 
        pTp(h-1); 
    } 
} 
int main() { 
    int n; 
    cin>>n; 
    pTp(n); 
} 
 

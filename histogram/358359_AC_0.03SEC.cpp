#include <iostream> 
using namespace std; 
int main() { 
    char a[200]={NULL,},b[200]={NULL,},c[200]={NULL,},d[200]={NULL,}; 
    int alpha[100]={0,}; 
    gets(a); 
    gets(b); 
    gets(c); 
    gets(d); 
      
    for(int i=0;i<200;i++) { 
        if(a[i] >='A' && a[i] <='Z') { 
            alpha[(int)a[i]-65]++; 
        } 
        if(b[i] >='A' && b[i] <='Z') { 
            alpha[(int)b[i]-65]++; 
        } 
        if(c[i] >='A' && c[i] <='Z') { 
            alpha[(int)c[i]-65]++; 
        } 
        if(d[i] >='A' && d[i] <='Z') { 
            alpha[(int)d[i]-65]++; 
        } 
    } 
  
    int max=0; 
    for(int i=0;i<26;i++) { 
        if(alpha[i] > max) max = alpha[i]; 
    } 
      
    for(int i=max;i>=1;i--) { 
        for(int j=0;j<26;j++) { 
        if(alpha[j] >= i) cout<<"*"; 
        else cout<<" "; 
        cout<<" "; 
        } 
  
        cout<<endl; 
    } 
    for(int i=0;i<26;i++) { 
        cout<<(char)('A'+i); 
        if((char)('A'+i) < 'Z') cout<<" "; 
    } 
} 
 

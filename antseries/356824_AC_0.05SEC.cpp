#include<iostream> 
using namespace std; 
int look[10000]={0}; 
int main() { 
    int cc=0; 
    for(int i=0;;i++) { 
        cin>>look[i]; 
        if(look[i] == 0) break; 
        cc++; 
    } 
    int c = look[0]; 
    int cnt=0; 
    for(int i=0;i<cc;i++) { 
        if(look[i+1] != c) { 
            cout<<++cnt<<" "<<c<<" "; 
            cnt = 0; 
            c = look[i+1]; 
        } else cnt++; 
    } 
} 
 

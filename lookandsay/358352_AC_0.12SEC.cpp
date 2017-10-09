#include<iostream> 
#include<string.h> 
using namespace std; 
char look[10000]={0}; 
int main() { 
    cin>>look; 
    char c = look[0]; 
    int cnt=0; 
    for(int i=0;i<strlen(look);i++) { 
        if(look[i+1] != c) { 
            cout<<++cnt<<c; 
            cnt = 0; 
            c = look[i+1]; 
        } else cnt++; 
    } 
} 
 

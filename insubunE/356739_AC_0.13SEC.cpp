#include<iostream> 
#include<stdlib.h> 
using namespace std; 
int main() { 
    int a,b; 
    cin>>a>>b; 
    for(int p=1;p<=a;p++) { 
        for(int q=p;q<=a;q++) { 
            if(abs(-q-p) == a && p*q == b) { 
                printf("(x-%d)(x-%d)",p,q); 
                return 0; 
            } 
        } 
    } 
    cout<<"impossible"; 
} 
 

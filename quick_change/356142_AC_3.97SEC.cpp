#include<iostream> 
int main(){ 
    int c; 
    int q=0,d=0,n=0,p=0; 
    std::cin>>c; 
    while(c > 0) { 
        if(c >= 25) { 
            c-=25; 
            q++; 
        } else if(c >= 10) { 
            c-=10; 
            d++; 
        } else if(c >= 5) { 
            c-=5; 
            n++; 
        } else { 
            c-=1; 
            p++; 
        } 
    } 
    printf("%d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)",q,d,n,p); 
  
}
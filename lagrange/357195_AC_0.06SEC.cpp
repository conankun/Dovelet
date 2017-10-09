#include<iostream> 
#include<cmath> 
using namespace std; 
int main() { 
    int n; 
    cin>>n; 
    int s=sqrt((double)n); 
    int cnt=0; 
    for(int i=1;i<=s;i++) { 
        for(int j=i;j<=s;j++) { 
            for(int k=j;k<=s;k++) { 
                if(i*i+j*j+k*k <= n) { 
                int a = n-(i*i+j*j+k*k); 
                int b= (a != 0 ? (int)(sqrt((double)a) * (int)sqrt((double)a)) : 0); 
                if((i*i+j*j+k*k + b) ==  n && b >= k*k) { 
                    cnt++; 
                } 
            } 
            } 
        } 
    } 
  
    for(int j=1;j<=s;j++) { 
        for(int k=j;k<=s;k++) { 
            if(j*j+k*k <= n) { 
            int a = n-(j*j+k*k); 
            int b= (a != 0 ? (int)(sqrt((double)a) * (int)sqrt((double)a)) : 0); 
            if((j*j+k*k + b) ==  n && (b >= k*k)) { 
                cnt++; 
            } 
        } 
    } 
} 
    for(int k=1;k<=s;k++) { 
            if(k*k <= n) { 
            int a = n-(k*k); 
            int b= (a != 0 ? (int)(sqrt((double)a) * (int)sqrt((double)a)) : 0); 
            if((k*k + b) ==  n && (b >= k*k)) { 
                cnt++; 
            } 
        } 
    } 
  
    if(s*s == n) cnt++; 
  
    cout<<cnt; 
} 
 

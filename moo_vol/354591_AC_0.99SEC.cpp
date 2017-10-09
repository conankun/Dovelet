#include<iostream> 
#include<stdlib.h> 
using namespace std; 
long long arr[10000]={0}; 
int main() { 
    int n; 
    cin>>n; 
    for(int i=0;i<n;i++) scanf("%lld",&arr[i]); 
    long long sum=0; 
    for(int i=0;i<n;i++) { 
        for(int j=0;j<n;j++) { 
            if(i!=j) { 
                sum+=abs(arr[i]-arr[j]); 
            } 
        } 
    } 
    printf("%lld",sum); 
} 
 

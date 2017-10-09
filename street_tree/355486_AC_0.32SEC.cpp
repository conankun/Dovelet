#include<iostream> 
using namespace std; 
int n; 
int arr[100000]; 
int gcds[100000]; 
int gcd(int a,int b) { 
    int gob=a*b; 
    int c; 
    do { 
        c = a%b; 
        a=b; 
        b=c; 
    }while(c != 0); 
    return a; 
} 
int main() { 
    cin>>n; 
    int min=2147483647,max=0; 
    for(int i=0;i<n;i++)  { 
        cin>>arr[i]; 
        if(arr[i] < min) min = arr[i]; 
        else if(arr[i] > max) max = arr[i]; 
    } 
    for(int i=0;i<n-1;i++) { 
        gcds[i] = arr[i+1]-arr[i]; 
    } 
      
    int _gcd = gcd(gcds[0],gcds[1]); 
    for(int i=2;i<n-1;i++) { 
        _gcd = gcd(_gcd,gcds[i]); 
    } 
    cout<<(max-min)/_gcd-n+1; 
} 
 

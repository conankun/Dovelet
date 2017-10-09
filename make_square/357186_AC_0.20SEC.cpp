#include <iostream> 
#include <cmath> 
using namespace std; 
int main() { 
    double n; 
    cin>>n; 
    for(int i=1;;i++) { 
        if(sqrt(n*i) - (int)(sqrt(n*i)) != 0.00) { 
            continue; 
        } 
        if(sqrt(n*i) * sqrt(n*i) == n*i) { 
            cout<<i; 
            break; 
        } 
    } 
} 
 

#include<iostream> 
#include<float.h> 
#include<cmath> 
using namespace std; 
int main() { 
    double a,b; 
    cin>>a>>b; 
    double c=fabs(a/b); 
    for(int i=1;fabs(c)>DBL_EPSILON;i++) { 
        double t=fabs((1.00/i)); 
        double cc=fabs(c); 
        if(cc >= t || fabs(t-cc) <= DBL_EPSILON) { 
            c-=(1.00/i); 
            cout<<1<<"/"<<i<<" "; 
        } 
    } 
} 
 

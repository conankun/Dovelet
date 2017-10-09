#include<iostream>
#include<cmath>
using namespace std;
int main() {
    int a,b;
    double d=0.0;
    cin>>a>>b;
    d+=a*3.14159;
    d+=b*3.14159;
    d+=sqrt((double)(a*a+a*a));
    d+=sqrt((double)(b*b+b*b));
    printf("%.3f",d);
}
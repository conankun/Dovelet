#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double sum=0.00f;
    for(int i=0;i<12;i++) {
        double a;
        cin>>a;
        sum+=a;
    }printf("$%.2f",(double)sum/12.00);}
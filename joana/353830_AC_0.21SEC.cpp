#include <iostream>
using namespace std;
int main () {
    long long n;
    long long lastNumber;
     
    scanf("%lld",&n);
     
    lastNumber = n*(n/2+1)+((1+n)/2 - 1);
     
    printf("%lld",lastNumber+lastNumber-2+lastNumber-4);
     
     
    return 0;
}
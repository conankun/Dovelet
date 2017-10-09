#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;
int *ptr;
int index=0;
int jarihap(int n) {
    int sum=0;
    while(n > 0) {
        sum+= n%10;
        n = n/10;
    }
    return sum;
}
 
bool isPrime(int n) {
    int i;
    for(i=2;i*i<=n;i==2?i+=1:i+=2) {
        if(n % i == 0) return false;
    }
    return true;
}
 
int gcdlcd(int n) {
    int sum=0;
    int n2=n;
    int ok=1;
    while(ok==1) {
        ok=0;
        if(n2 == 1) break;
        for(int j=0;j<index;j++) {
            if(n2 % ptr[j] == 0) {
                n2 = n2/ptr[j];
                sum+=jarihap(ptr[j]);
                ok=1;
                break;
            }
        }
        if(ok==0) {
            if(isPrime(n2) == true) {
                sum+=jarihap(n2);
                break;
            }
        }
         
    }
    return sum;
}
 
int main() {
    int n;
    ptr = (int *)malloc(sizeof(int) * 350000);
    for(int i=2;i<1000000;i++) {
        if(isPrime(i) == true) {
            ptr[index]=i;
            index++;
        }
    }
 
    while(cin>>n) {
        if(n == 0) break;
        for(int i=n+1;;i++) {
        if(jarihap(i) == gcdlcd(i)) {
            if(!isPrime(i)) {
            cout<<i<<endl;
            break;
            }
        }
        }
 
    }
}
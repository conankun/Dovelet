#include<iostream>
using namespace std;
int main() {
    double c;
    cin>>c;
    double s=0;
    int co=0;
    for(int i=2;;i++) {
        co++;
        s+=(1.00/i);
        if(s >= c) break;
    }
    printf("%d card(s)",co);
}
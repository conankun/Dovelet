#include<stdio.h>
#include<iostream>
using namespace std;
int main() {
int a,b,c;
scanf("%d%d%d",&a,&b,&c);
printf("%d",max(b-a-1,c-(b+1)));
}
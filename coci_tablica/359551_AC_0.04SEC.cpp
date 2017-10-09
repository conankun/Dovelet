#include<iostream>
using namespace std;
double table[4];
int i,j;
int main() {for(i=0;i<4;i++) cin>>table[i];double mx=0;int t=0;for(i=0;i<4;i++) {double c = (table[0]/table[2])+(table[1]/table[3]);if(c > mx) {mx = c;t = i;}int t1=table[0];int t2=table[1];int t3=table[2];int t4=table[3];table[0]=t3;table[1]=t1;table[2]=t4;table[3]=t2;}cout<<t;}
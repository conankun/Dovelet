#include<iostream>
#include<string>
using namespace std;
string arr[2]={"even","odd"};
int main(){int a,b;cin>>a>>b;cout<<arr[a%2]<<"+"<<arr[b%2]<<"="<<arr[(a+b)%2]<<endl;cout<<arr[a%2]<<"*"<<arr[b%2]<<"="<<arr[(a*b)%2];}
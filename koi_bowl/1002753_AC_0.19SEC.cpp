#include<iostream>
#include<string>
using namespace std;
string s;
char c[100000];
int main()
{
    cin>>s;
    int i;
    int sum=0;
    for(i=0;i<s.size();i++) {
        if(c[i]!=s[i]) {
            sum+=10;
        } else sum+=5;
        c[i+1]=s[i];
    }
    cout<<sum;
}

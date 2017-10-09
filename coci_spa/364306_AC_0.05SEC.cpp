#include<iostream>
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;
	if(n == 0) n = 24;
	int time = n*60+m;
	time-=45;
	cout<<time/60<<" "<<time%60;
}
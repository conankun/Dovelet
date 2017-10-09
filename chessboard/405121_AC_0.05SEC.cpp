#include<iostream>
using namespace std;
int n;
int y,x;
int main() {
	cin>>n;
	int i;
	int m;
	for(m=1;m*m<n;m++);
	if(m*m > n) m--;
	if(m%2 == 1) {
		x = 1;
		y = m;
	} else {
		x = m;
		y = 1;
	}
	if(m*m == n) {
		cout<<x<<" "<<y;
		return 0;
	}
	if(m%2 == 1) y++;
	else x++;
	if(m*m+1 == n) {
		cout<<x<<" "<<y;
		return 0;
	}
	if(m*m+m+1 >= n) {
		if(m%2 == 1) cout<<x+(n-(m*m+1))<<" "<<y;
		else cout<<x<<" "<<y+(n-(m*m+1));
		return 0;
	}
	if(m%2 == 1) x+=m;
	else y+=m;
	if(m*m+2*m >= n) {
		if(m%2 == 1) cout<<x<<" "<<y-(n-(m*m+1+m));
		else cout<<x-(n-(m*m+1+m))<<" "<<y;
		return 0;
	}
}
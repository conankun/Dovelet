#include<iostream>
using namespace std;
int a,b,c;
int s[4][4];
int divs(int n,int m) {
	if(m == 0) return 0;
	return n/m;
}
int per(int n,int m) {
	if(m == 0) return 0;
	return n%m;
}
int main() {
	int i,j,k;
	cin>>a>>b>>c;
	for(i=1;i<=3;i++) cin>>s[i][1]>>s[i][2]>>s[i][3];
	for(i=0;i<=100;i++) {
		for(j=0;j<=100;j++) {
			for(k=0;k<=100;k++) {
				int sum3[4]={0};
				sum3[1]+=s[1][1]*i;
				sum3[1]+=s[2][1]*j;
				sum3[1]+=s[3][1]*k;
				sum3[2]+=s[1][2]*i;
				sum3[2]+=s[2][2]*j;
				sum3[2]+=s[3][2]*k;
				sum3[3]+=s[1][3]*i;
				sum3[3]+=s[2][3]*j;
				sum3[3]+=s[3][3]*k;
				int aa = per(sum3[1],a);
				int bb = divs(sum3[1],a);
				int cc = divs(sum3[2],b);
				int dd = per(sum3[2],b);
				int ee = divs(sum3[3],c);
				int ff = per(sum3[3],c);
				//per(sum3[1],a) == 0
				//divs(sum3[1],a) == divs(sum3[2],b)
				//per(sum3[2],b) == 0
				//divs(sum3[2],b) == divs(sum3[3],c)
				//per(sum3[3],c) == 0
				if(aa == 0 && (bb == cc || (cc == 0 && b == 0) || (bb == 0 && a == 0)) && dd == 0 && (cc == ee || (ee == 0 && c == 0)|| (cc == 0 && b == 0))  && ff == 0 && a*bb == sum3[1] && b*cc == sum3[2] && c*ee == sum3[3] && sum3[1]/a*a >= a) {
					cout<<i<<" "<<j<<" "<<k<<" "<<sum3[1]/a;
					return 0;
				}
			}
		}
	}
	cout<<"NONE";
}
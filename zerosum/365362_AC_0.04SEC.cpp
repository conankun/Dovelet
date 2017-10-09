#include<iostream>
#include<string>
using namespace std;
int n;
//공백 : 0, + : 1 , - : 2
void dfs(int level,int sum,string s,int code) {
	//공백부터 처리.
	int i;
	if(level == n) {
		if(sum == 0)
		cout<<s<<endl;
		return;
	}
	if(code == 2) { //-일때
		int sum2=sum+level;
		string s2=s;
		int g=level;
		for(i=level+1;i<=n;i++) {
		if(i > level+1)	sum2+=g;
			g=g*10+i;
			sum2-=g;
			s2+=" ";
			s2+=i+48;
			dfs(i,sum2,s2,0);
		}
	} else if(code == 1) {
		int sum2=sum-level;
		string s2=s;
		int g=level;
		for(i=level+1;i<=n;i++) {
		if(i > level+1) sum2-=g;
			g=g*10+i;
			sum2+=g;
			s2+=" ";
			s2+=i+48;
			dfs(i,sum2,s2,0);
		}
	} else if(level == 1) {
		int sum2=sum-level;
		string s2=s;
		int g=level;
		for(i=level+1;i<=n;i++) {
		if(i > level+1) sum2-=g;
			g=g*10+i;
			sum2+=g;
			s2+=" ";
			s2+=i+48;
			dfs(i,sum2,s2,0);
		}
	}
	int sum3=sum;
	string s3 = s;
	sum3+=level+1;
	s3+="+";
	s3+=level+1+48;
	dfs(level+1,sum3,s3,1);

	sum3=sum;
	s3=s;
	sum3-=level+1;
	s3+="-";
	s3+=level+1+48;
	dfs(level+1,sum3,s3,2);
}
int main() {
	cin>>n;
	dfs(1,1,"1",0);
}
#include<iostream>
#include<deque>
using namespace std;
int t;
int n,r,k;
int main() {
	cin>>t;
	int d,i,j,k;
	for(d=1;d<=t;d++) {
		cin>>r>>k>>n;
		deque<int> coaster;
		coaster.resize(n);
		for(i=0;i<n;i++) cin>>coaster[i];
		int total=0;
		for(i=1;i<=r;i++) {
			int sum=0;
			for(j=1;j<=n;j++) {
				if(sum+coaster.front() <= k) {
					sum+=coaster.front();
					coaster.push_back(coaster.front());
					coaster.pop_front();
				} else break;
			}
			total+=sum;
		}
		cout<<"Case #"<<d<<": "<<total<<endl;
	}
}
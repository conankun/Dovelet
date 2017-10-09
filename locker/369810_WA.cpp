#include<iostream>
#include<deque>
using namespace std;
int n;
deque<int> locker;
int main() {
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++) {
		int g;
		cin>>g;
		locker.push_back(g);
	}
	for(i=1;i<=n-1;i++) { //i칸 만큼 뒤로 밈.
		int r = locker.back();
		locker.pop_back();
		locker.push_front(r);
		int s = 0;
		int si=0,ei=0;
		bool tr=false; //구간에 들어섬.
		int cnt=0;
		bool ok=true;
		for(j=1;j<n;j++) {
			int cc = locker[j];
			if(tr && (locker[j] == s+1||(locker[j-1] == n && locker[j] != 1))) {
				ei = j;
				int a = locker[si];
				int b = locker[j+1];
				if(a+1 == b || (a == n && b == 1)) {

				} else {
					ok=false;
				}
				locker[ei] = locker[si];
				break;
			} else if(tr) {
				if(locker[j] != locker[j-1]-1 || (locker[j-1] == 1 && locker[j] != n)) {
					ok=false;
					break;
				}
			} else if(!tr && (locker[j] != locker[j-1]+1 || (locker[j-1] == n && locker[j] != 1))) {
				cnt++;
				s = locker[j-1];
				si = j;
				tr=true;
			}
		}
		for(j=ei+1;j<=n;j++) {
			if(locker[j] != locker[j-1]+1 || (locker[j-1] == n && locker[j] != 1))  {
				ok=false;
				break;
			}
		}
		if(ok) {
			cout<<n-ei+1<<endl;
			cout<<si+1<<" "<<ei+1<<endl;
			cout<<i;
			return 0;
		}
	}
}
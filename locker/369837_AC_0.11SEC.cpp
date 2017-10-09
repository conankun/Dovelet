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
	int si=0,ei=n-1;
	for(i=1;i<=n-1;i++) { //i칸 만큼 뒤로 밈.
		int r = locker.back();
		locker.pop_back();
		locker.push_front(r);
		int s = 0;
		si=0;
		ei=n-1;
		bool tr=false; //구간에 들어섬.
		int cnt=0;
		bool ok=true;
		int aa = locker[0];
		int bb = locker[1];
		int gg=0;
		for(j=1;j<n;j++) {
			int cc = locker[j];
			if(tr && locker[j] == s+1) {
				if(locker[j-1] == n && locker[j] != 1) continue;
				ei = j;
				int a = locker[si];
				int b = locker[j+1];
				if(a+1 == b || (a == n && b == 1)) {

				} else {
					ok=false;
				}
				gg = locker[ei];
				locker[ei] = locker[si];
				break;
			} else if(tr) {
				if(locker[j] != locker[j-1]-1) {
					if((locker[j-1] == 1 && locker[j] == n)) continue;
					ok=false;
					break;
				}
			} else if(!tr && (locker[j] != locker[j-1]+1)) {
				if((locker[j-1] == n && locker[j] == 1)) continue;
				cnt++;
				s = locker[j-1];
				si = j;
				tr=true;
			}
		}
		for(j=ei+1;j<n;j++) {
			if(locker[j] != locker[j-1]+1 || (locker[j-1] == n && locker[j] != 1))  {
				locker[ei] = gg;
				ok=false;
				break;
			}
		}
		if(ok) {
			locker[ei] = gg;
			int cc = locker[0];
			if(n-(n-locker[0])-1 == 0) continue;
			cout<<n-(n-locker[0])-1<<endl;
			cout<<si+1<<" "<<ei+1<<endl;
			cout<<i;
			return 0;
		}
	}
	cout<<n-(n-locker[0])-1<<endl;
	cout<<1<<" "<<n<<endl;
	cout<<n-1;
}
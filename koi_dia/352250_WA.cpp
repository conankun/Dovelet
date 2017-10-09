#include<fstream>
using namespace std;
ifstream in("INPUT.TXT");
ofstream out("OUTPUT.TXT");
struct A {
	int x,y;
};
int n,m,t,k;
int i,j;
A pos[10000]={0};
A posarr[100000]={0};
int ind=0;
int main() {
	in>>n>>m>>t>>k;
	for(i=0;i<t;i++) in>>pos[i].x>>pos[i].y;
	for(i=0;i<t;i++) {
		for(j=0;j<t;j++) {
			//if(pos[j].y >= k && m-pos[i].x >= k) {
				posarr[ind].x = pos[i].x;
				posarr[ind++].y = pos[j].y;
			//}
		}
		for(j=0;j<t;j++) {
			//if(pos[i].y >= k && m-pos[j].x >= k) {
				posarr[ind].y = pos[i].y;
				posarr[ind++].x = pos[j].x;
			//}
		}
		//if(pos[i].y+k <= n && pos[j].x+k <= m) {
			posarr[ind].y = pos[i].y;
			posarr[ind++].x = pos[i].x;
		//}
	}
	posarr[ind].y = n;
	posarr[ind++].x = 0;
	A rectpos;
	int c=0;
	for(i=0;i<ind;i++) {
		int cnt=0;
		for(j=0;j<t;j++) {
			if(pos[j].x - posarr[i].x >= 0 && pos[j].x - posarr[i].x <= k) {
				if(posarr[i].y - pos[j].y >= 0 && posarr[i].y - pos[j].y <= k) {
					cnt++;
				}
			}
		}
		if(cnt >= c) {
			rectpos.x = posarr[i].x;
			rectpos.y = posarr[i].y;
			c=cnt;
		}
	}
	out<<rectpos.x<<" "<<rectpos.y<<endl;
	out<<c;
}
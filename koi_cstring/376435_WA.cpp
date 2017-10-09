#include<iostream>
#include<string.h>
using namespace std;
char a[1000000],b[1000000],c[1000000];
char center[1000000];
int d[3];
int mx=0;
int vis[10000000];
int cc;
void refresh() {
	int i;
	bool t=true;
	while(t) {
		t=false;
		for(i=0;i<cc;i++) {
			//a를 취할때
			int aa = center[i] == a[i] ? d[0] : d[0]-1;
			int bb,cc;
			if(center[i] == b[i] && a[i] != b[i]) bb = d[1]+1;
			else if(center[i] != b[i] && a[i] == b[i]) bb = d[1]-1;
			else bb = d[1];
			if(center[i] == c[i] && a[i] != c[i]) cc = d[2]+1;
			else if(center[i] != c[i] && a[i] == c[i]) cc = d[2]-1;
			else cc = d[2];
			if(max(aa,max(bb,cc)) < mx || (max(aa,max(bb,cc)) == mx && (d[0] > aa || d[1] > bb || d[2] > cc))) {
				center[i] = a[i];
				d[0] = aa;
				d[1] = bb;
				d[2] = cc;
				if(max(aa,max(bb,cc)) < mx && vis[i] == 0) t=true;
				vis[i]=1;
				mx = max(aa,max(bb,cc));
			}
			//b를 취할 때
			bb = center[i] == b[i] ? d[1] : d[1]-1;
			if(center[i] == a[i] && b[i] != a[i]) aa = d[0]+1;
			else if(center[i] != a[i] && b[i] == a[i]) aa = d[0]-1;
			else aa = d[0];
			if(center[i] == c[i] && b[i] != c[i]) cc = d[2]+1;
			else if(center[i] != c[i] && b[i] == c[i]) cc = d[2]-1;
			else cc = d[2];
			if(max(aa,max(bb,cc)) < mx || (max(aa,max(bb,cc)) == mx && (d[0] > aa || d[1] > bb || d[2] > cc))) {
				center[i] = b[i];
				d[0] = aa;
				d[1] = bb;
				d[2] = cc;
				if(max(aa,max(bb,cc)) < mx && vis[i] == 0) t=true;
				vis[i]=1;
				mx = max(aa,max(bb,cc));
			}
			//c를 취할 때
			cc = center[i] == c[i] ? d[2] : d[2]-1;
			if(center[i] == a[i] && c[i] != a[i]) aa = d[0]+1;
			else if(center[i] != a[i] && c[i] == a[i]) aa = d[0]-1;
			else aa = d[0];
			if(center[i] == b[i] && c[i] != b[i]) bb = d[1]+1;
			else if(center[i] != b[i] && c[i] == b[i]) bb = d[1]-1;
			else bb = d[1];
			if(max(aa,max(bb,cc)) < mx || (max(aa,max(bb,cc)) == mx && (d[0] > aa || d[1] > bb || d[2] > cc))) {
				center[i] = c[i];
				d[0] = aa;
				d[1] = bb;
				d[2] = cc;
				if(max(aa,max(bb,cc)) < mx && vis[i] == 0) t=true;
				vis[i]=1;
				mx = max(aa,max(bb,cc));
			}
		}
	}
}
int main() {
	//cin>>a>>b>>c;
	fgets(a,1000000,stdin);
	fgets(b,1000000,stdin);
	fgets(c,1000000,stdin);
	d[0]=strlen(a);
	d[1]=strlen(b);
	d[2]=strlen(c);
	int i;
	//일단 빈도수가 많은것부터 채워넣는다.
	cc = strlen(a);
	for(i=0;i<cc;i++) {
		if(a[i] == b[i] && b[i] == c[i]) {
			d[0]--;
			d[1]--;
			d[2]--;
			center[i] = a[i];
		} else if(a[i] == b[i]) {
			d[0]--;
			d[1]--;
			center[i] = a[i];
		} else if(a[i] == c[i]) {
			d[0]--;
			d[2]--;
			center[i] = a[i];
		} else if(b[i] == c[i]) {
			d[1]--;
			d[2]--;
			center[i] = b[i];
		} else { //반경이 최대인걸 넣는다.
			if(d[0] > d[1] && d[0] > d[2]) { //a를 취함.
				center[i] = a[i];
				d[0]--;
			} else if(d[1] > d[0] && d[1] > d[2]) { //b를 취함.
				center[i] = b[i];
				d[1]--;
			} else if(d[2] > d[0] && d[2] > d[1]) { //c를 취함.
				center[i] = c[i];
				d[2]--;
			} else { // 아무거나 취함.
				center[i] = a[i];
				d[0]--;
			}
		}
	}
	mx = max(d[0],max(d[1],d[2]));
	//처리
	refresh();
	fprintf(stdout,"%d\n",mx);
	fprintf(stdout,"%s",center);
}
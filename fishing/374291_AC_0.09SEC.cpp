#include<iostream>
using namespace std;
int n=5;
int map[10][10];
int main() {
	int a,b,c,d,e,f;
	for(a=1;a<=n;a++) {
		for(b=1;b<=n;b++) {
			cin>>map[a][b];
		}
	}
	int mx=-99999999;
	int px,py,ppx,ppy;
	for(a=1;a<=n;a++) {
		for(b=1;b<=n;b++) {
			for(c=a;c<=n;c++) {
				for(d=b;d<=n;d++) {
					int sum=0;
					for(e=a;e<=c;e++) for(f=b;f<=d;f++) sum+=map[e][f];
					if(sum > mx) {
						mx = sum;
						px = a;
						py = b;
						ppx = c;
						ppy = d;
					}
				}
			}
		}
	}
	cout<<mx<<endl<<px<<" "<<py<<" "<<ppx<<" "<<ppy;
}
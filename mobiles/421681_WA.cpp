#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
struct A {
	int parent;
	int left,right;
	int level;
	int ind;
	bool operator<(const A &a) const {
		return level > a.level;
	}
};
struct B {
	int mx,mn;
};
int max(int a,int b) {
	if(a > b) return a;
	return b;
}
int min(int a,int b) {
	if(a < b) return a;
	return b;
}
A mobiles[100010];
A sortmobiles[100010];
B maxmin[100010];
int n;//막대 갯수.
int count;//모빌포함.
FILE *in = stdin;
FILE *out = stdout;
int main() {
	fscanf(in,"%d",&n);
	int i;
	count=n;
	for(i=1;i<=n;i++) {
		int a,b;
		fscanf(in,"%d%d",&a,&b);
		if(a == -1) {
			mobiles[i].left = ++count;
			mobiles[count].parent = i;
			mobiles[count].level = mobiles[i].level+1;
		} else {
			mobiles[i].left = a;
			mobiles[a].parent = i;
			mobiles[a].level = mobiles[i].level+1;
		}
		if(b == -1) {
			mobiles[i].right = ++count;
			mobiles[count].parent = i;
			mobiles[count].level = mobiles[i].level+1;
		} else {
			mobiles[i].right = b;
			mobiles[b].parent = i;
			mobiles[b].level = mobiles[i].level+1;
		}
	}
	for(i=1;i<=count;i++) mobiles[i].ind = i;
	for(i=1;i<=count;i++) sortmobiles[i]=mobiles[i];
	std::sort(sortmobiles+1,sortmobiles+1+count);
	int cnt=0;
	for(i=1;i<=count;i++) {
		if(sortmobiles[i].ind > n) { // 모빌인 경우
			maxmin[sortmobiles[i].ind].mx=sortmobiles[i].level;
			maxmin[sortmobiles[i].ind].mn=sortmobiles[i].level;
		} else { //막대인 경우
			if(maxmin[sortmobiles[i].left].mn < maxmin[sortmobiles[i].right].mx) {
				if(maxmin[sortmobiles[i].right].mn < maxmin[sortmobiles[i].left].mx) {
					fprintf(out,"-1");
					return 0;
				}
				cnt++;
			}
			maxmin[sortmobiles[i].ind].mx=max(maxmin[sortmobiles[i].left].mx,maxmin[sortmobiles[i].right].mx);
			maxmin[sortmobiles[i].ind].mn=min(maxmin[sortmobiles[i].left].mn,maxmin[sortmobiles[i].right].mn);
		}
	}
	int mn=2147483647;
	for(i=n+1;i<=count;i++) {
		if(mn > mobiles[i].level) mn=mobiles[i].level;
		if(abs(mn-mobiles[i].level) > 1) {
			fprintf(out,"%d",-1);
			return 0;
		}
	}
	fprintf(out,"%d",cnt);
}
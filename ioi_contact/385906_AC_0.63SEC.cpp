#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
using namespace std;
FILE *in = fopen("contact2.in","r");
FILE *out = fopen("contact.out","w");
int A,B,n;
char s[10000010];
int len;
struct AA {
	char c[22];
	int cnt;
	int value;
	int i;
};
AA map[30][5000];
int vis[3000000];
vector<AA> ve[2000001];
vector<int> list;
int convert(AA a) {
	int l = strlen(a.c);
	int i;
	int sum=0;
	int g=1;
	for(i=l-1;i>=0;i--) {
		if(a.c[i] == '0' || a.c[i] == '1') {
			sum+=(a.c[i]-48)*g;
			g*=2;
		}
	}
	return sum;
}
bool cmp(AA a,AA b) {
	if(a.i == b.i) return a.value > b.value;
	return a.i > b.i;
}
int main() {
	fscanf(stdin,"%d%d%d",&A,&B,&n);
	getc(stdin);
	fgets(s,10000000,stdin);
	len = strlen(s);
	int i,j,k;
	int ind=0;
	int g,sum,size;
	for(i=0;i<len;i++) {
		char c[22]={0};
		ind=0;
		g=1;
		sum=0;
		size=0;
		for(j=1;j<=B;j++) {
			if(i+j-1 < len-1) {
				if(s[i+j-1] == '2') break;
				c[ind++]=s[i+j-1];
				sum+=(s[i+j-1]-48)*g;
				g*=2;
				size++;
				if(j < A) continue;
				if(map[size][sum].cnt == 0) {
					strcpy(map[size][sum].c,c);
				}
				map[size][sum].cnt++;
			}
		}
	}
	for(i=1;i<=30;i++) {
		for(j=0;j<=4096;j++) {
			if(map[i][j].cnt > 0) {
				if(vis[map[i][j].cnt]) {
					map[i][j].value = convert(map[i][j]);
					map[i][j].i = i;
					ve[map[i][j].cnt].push_back(map[i][j]);
				} else {
					list.push_back(map[i][j].cnt);
					vis[map[i][j].cnt]=1;
					map[i][j].i = i;
					map[i][j].value = convert(map[i][j]);
					ve[map[i][j].cnt].push_back(map[i][j]);
				}
			}
		}
	}
	sort(list.begin(),list.end());
	int cc=0;
	for(i=list.size()-1;i>=0;i--) {
		cc++;
		fprintf(stdout,"%d ",list[i]);
		sort(ve[list[i]].begin(),ve[list[i]].end(),cmp);
		int length = ve[list[i]].size();
		for(j=0;j<length;j++) {
			int length2 = strlen(ve[list[i]][j].c);
			bool t=false;
			for(k=0;k<length2;k++)
			{
				if(ve[list[i]][j].c[k] == '0' || ve[list[i]][j].c[k] == '1') {
					t=true;
					fprintf(stdout,"%c",ve[list[i]][j].c[k]);
				}
			}
			if(t) fprintf(stdout," ");
		}
		fprintf(stdout,"\n");
		if(cc >= n) break;
	}
}
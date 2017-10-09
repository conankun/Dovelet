#include<iostream>
#include<string.h>
using namespace std;
char W[5000000];
char S[5000000];
int Wfreq[200]; //각각 문자에 대한 빈도수(W)
int Sfreq[200]; //각각 문자에 대한 빈도수(S)
int w,s; //사이즈
int cnt;
int main() {
	int i,j;
	scanf("%d%d",&w,&s);
	scanf("%s\n",W);
	scanf("%s",S);
	for(i=0;i<w;i++) {
		Wfreq[W[i]]++;
		Sfreq[S[i]]++;
	}
	bool t=true;
	bool t2=true;
	for(i='A';i<='Z';i++) {
		if(Wfreq[i] != Sfreq[i]) {
			t=false;
			break;
		}
	}
	for(i='a';i<='z';i++) {
		if(Wfreq[i] != Sfreq[i]) {
			t2=false;
			break;
		}
	}
	if(t && t2) cnt++;
	for(i=1;i<s-w;i++) {
		t=true;
		t2=true;
		Sfreq[S[i-1]]--;
		Sfreq[S[i+w-1]]++;
		for(j='A';j<='Z';j++) {
			if(Wfreq[j] != Sfreq[j]) {
				t=false;
				break;
			}
		}
		for(j='a';j<='z';j++) {
			if(Wfreq[j] != Sfreq[j]) {
				t2=false;
				break;
			}
		}
		if(t && t2) {
			cnt++;
		}
	}
	printf("%d",cnt);
}
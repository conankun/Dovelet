#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
map<string,string> mp;
char list[100][100];
string backarr;
string s;
string arrs[100001];
int cnt;
void back(int level) {
	if(level==s.length()) {
		map<string,string>::iterator it = mp.find(backarr);
		if(it==mp.end()) {
			return;
		} else {
			cnt++;
			arrs[cnt]=backarr;
		}
		return;
	} else {
		int i;
		string backar=backarr;
		for(i=1;i<=3;i++) {
			//list[s[level]-'0'][i];
			backarr+=list[s[level]-'0'][i];
			back(level+1);
			backarr=backar;
		}
	}
}
int main() {
	list[2][1]='A';
	list[2][2]='B';
	list[2][3]='C';

	list[3][1]='D';
	list[3][2]='E';
	list[3][3]='F';

	list[4][1]='G';
	list[4][2]='H';
	list[4][3]='I';

	list[5][1]='J';
	list[5][2]='K';
	list[5][3]='L';

	list[6][1]='M';
	list[6][2]='N';
	list[6][3]='O';

	list[7][1]='P';
	list[7][2]='R';
	list[7][3]='S';

	list[8][1]='T';
	list[8][2]='U';
	list[8][3]='V';

	list[9][1]='X';
	list[9][2]='X';
	list[9][3]='Y';

	cin>>s;
	int i;
	string tmp;
	freopen("dict.txt","r",stdin);
	char a[1000];
	while(gets(a)) {
		tmp = string(a);
		mp.insert(make_pair(tmp,tmp));
	}
	back(0);
	for(i=1;i<=cnt;i++) cout<<arrs[i]<<endl;
	if(cnt==0) printf("NONE");
}
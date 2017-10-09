#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,int> mp;
int main() {
	int cnt=0;
	char i,j,k,l,z;
	string s;
	s.resize(1);
	for(i='a';i<='z';i++) {
		s[0] = i;
		mp.insert(pair<string,int>(string(s),++cnt));	
	}
	s.resize(2);
	for(i='a';i<='z';i++) {
		s[0] = i;
		for(j=i+1;j<='z';j++) {
			s[1] = j;
			mp.insert(pair<string,int>(string(s),++cnt));
		}
	}
	s.resize(3);
	for(i='a';i<='z';i++) {
		s[0] = i;
		for(j=i+1;j<='z';j++) {
			s[1] = j;
			for(k=j+1;k<='z';k++) {
				s[2] = k;
				mp.insert(pair<string,int>(string(s),++cnt));
			}
		}
	}
	s.resize(4);
	for(i='a';i<='z';i++) {
		s[0] = i;
		for(j=i+1;j<='z';j++) {
			s[1] = j;
			for(k=j+1;k<='z';k++) {
				s[2] = k;
				for(l=k+1;l<='z';l++) {
					s[3] = l;
					mp.insert(pair<string,int>(string(s),++cnt));
				}
			}
		}
	}
	s.resize(5);
	for(i='a';i<='z';i++) {
		s[0] = i;
		for(j=i+1;j<='z';j++) {
			s[1] = j;
			for(k=j+1;k<='z';k++) {
				s[2] = k;
				for(l=k+1;l<='z';l++) {
					s[3] = l;
					for(z=l+1;z<='z';z++) {
						s[4] = z;
						mp.insert(pair<string,int>(string(s),++cnt));
					}
				}
			}
		}
	}
	string ss;
	while(cin>>ss) {
		if(mp.find(ss) == mp.end()) {
			cout<<0;
		} else {
			map<string,int>::iterator it = mp.find(ss);
			cout<< it->second << endl;
		}
		
	}
}
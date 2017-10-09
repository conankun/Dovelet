#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string A[100]={"AA","AO"};
string B[100]={"BB","BO"};
string AB[100]={"AB","AB"};
string O[100]={"OO","OO"};
string rhp[100]={"++","+-"};
string rhm[100]={"--","--"};
string a,b,c,d;
string abook[1000];
int allabo=0;
string rhok[1000];
int allrh=0;
void back(string one,string two,int ind1,int ind2) {//abo
	string s;
	if(one[ind1]=='O'&&two[ind2]!='O') {
		s+=two[ind2];
		s+=one[ind1];
	} else {
		if(one[ind1]<=two[ind2]) {
			s+=one[ind1];
			s+=two[ind2];
		} else {
			s+=two[ind2];
			s+=one[ind1];
		}
	}
	if(s=="AO") s="AA";
	if(s=="BO") s="BB";
	abook[++allabo]=s;
}
void back2(string one,string two,int ind1,int ind2) {//abo
	string s;
	if(one[ind1] <= two[ind2]) {
		s+=one[ind1];
		s+=two[ind2];
	} else {
		s+=two[ind2];
		s+=one[ind1];
	}
	rhok[++allrh]=s;
}
int main() {
	srand(time(NULL));
	int k;
		allabo=0,allrh=0;
		cin>>a>>b>>c>>d;//a,c --> rh, b,d-->ABO
		string grouprh1[10];
		string grouprh2[10];
		string groupabo1[10];
		string groupabo2[10];
		if(a=="Rh+") {
			grouprh1[0]=rhp[0];
			grouprh1[1]=rhp[1];
		} else {
			grouprh1[0]=rhm[0];
			grouprh1[1]=rhm[1];
		}
		if(c=="Rh+") {
			grouprh2[0]=rhp[0];
			grouprh2[1]=rhp[1];
		} else {
			grouprh2[0]=rhm[0];
			grouprh2[1]=rhm[1];
		}
		if(b=="A") {
			groupabo1[0]=A[0];
			groupabo1[1]=A[1];
		} else if(b=="B") {
			groupabo1[0]=B[0];
			groupabo1[1]=B[1];
		} else if(b=="AB") {
			groupabo1[0]=AB[0];
			groupabo1[1]=AB[1];
		} else {
			groupabo1[0]=O[0];
			groupabo1[1]=O[1];
		}
		if(d=="A") {
			groupabo2[0]=A[0];
			groupabo2[1]=A[1];
		} else if(d=="B") {
			groupabo2[0]=B[0];
			groupabo2[1]=B[1];
		} else if(d=="AB") {
			groupabo2[0]=AB[0];
			groupabo2[1]=AB[1];
		} else {
			groupabo2[0]=O[0];
			groupabo2[1]=O[1];
		}
		int i,j,l,ma;
		for(i=0;i<=1;i++) {
			for(j=0;j<=1;j++) {
				for(l=0;l<=1;l++) {
					for(ma=0;ma<=1;ma++) {
						back(groupabo1[i],groupabo2[j],l,ma);
						back2(grouprh1[i],grouprh2[j],l,ma);
					}
				}
			}
		}
		sort(abook+1,abook+allabo+1);
		sort(rhok+1,rhok+allrh+1);
		for(i=1;i<=allrh;i++) if(i==1||rhok[i][0]!=rhok[i-1][0]) printf("Rh%c\n",rhok[i][0]);
		for(i=1;i<=allabo;i++) if(i==1||abook[i]!=abook[i-1]) {
			if(abook[i] != "AB") {
				if(i==1||abook[i][0] != abook[i-1][0]||abook[i-1]=="AB") 
					{
						printf("%c\n",abook[i][0]);
					}
			}
			else {
				printf("%s\n",abook[i].c_str());
			}
		}
 
}

#include<stdio.h>
int R,C;
char map[100][100];
int willvanish[100][100];
int main() {
	scanf("%d%d\n",&R,&C);
	int i,j;
	for(i=1;i<=R;i++) {
		for(j=1;j<=C;j++) scanf("%c",&map[i][j]);
		scanf("\n");
	}
	for(i=1;i<=R;i++) {
		for(j=1;j<=C;j++) {
			if(map[i][j]=='.') continue;
			int cnt=0;
			if(map[i+1][j]=='.' || map[i+1][j]==0) cnt++;
			if(map[i-1][j]=='.' || map[i-1][j]==0) cnt++;
			if(map[i][j+1]=='.' || map[i][j+1]==0) cnt++;
			if(map[i][j-1]=='.' || map[i][j-1]==0) cnt++;
			if(cnt>=3) willvanish[i][j]=1;
		}
	}
	for(i=1;i<=R;i++) {
		for(j=1;j<=C;j++) {
			if(willvanish[i][j]==1) map[i][j]='.';
		}
	}
	int notprint1=1,notprint2=R;
	int notprint3=1,notprint4=C;
	for(i=1;i<=R;i++) {
		bool tr=true;
		for(j=1;j<=C;j++) {
			if(map[i][j]=='X') {
				tr=false;
				break;
			}
		}
		if(!tr) {
			notprint1=i;
			break;
		}
	}
	for(i=R;i>=1;i--) {
		bool tr=true;
		for(j=1;j<=C;j++) {
			if(map[i][j]=='X') {
				tr=false;
				break;
			}
		}
		if(!tr) {
			notprint2=i;
			break;
		}
	}

	for(j=1;j<=C;j++) {
		bool tr=true;
		for(i=1;i<=R;i++) {
			if(map[i][j]=='X') {
				tr=false;
				break;
			}
		}
		if(!tr) {
			 notprint3=j;
			break;
		}
	}

	for(j=C;j>=1;j--) {
		bool tr=true;
		for(i=1;i<=R;i++) {
			if(map[i][j]=='X') {
				tr=false;
				break;
			}
		}
		if(!tr) {
			  notprint4=j;
			 break;
		}
	}
	for(i=notprint1;i<=notprint2;i++) {
		for(j=notprint3;j<=notprint4;j++) {
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
	
}
#include<iostream>
#include<algorithm>
using namespace std;
int starte, goale, totale;
int grapho[1000][1000];
int dista[1000];
int visit[1000];
int main(void){
	int i, j;
	scanf("%d %d %d", &totale, &starte, &goale);
	for (i = 1; i <= totale; i++){
		for (j = 1; j <= totale; j++){
			scanf("%d", &grapho[i][j]);
		}
	}
	for (i = 1; i <= totale; i++){
		dista[i] = 99999;
	}
	int st = starte;
	dista[st] = 0;
	for (j = 1; j <= totale; j++){
		dista[j] = min(dista[j], dista[st] + grapho[st][j]);
	}
	
	for (i = 1; i <= totale; i++){
		visit[st] = 1;
		int tempo = -1;
		int mndis = 999999999;
		for (j = 1; j <= totale; j++){
			if (mndis > dista[j] && !visit[j]){
				tempo = j;
				mndis = dista[j];
			}
		}
		st = tempo;
		for (j = 1; j <= totale; j++){
			if (visit[j] == 0)
			dista[j] = min(dista[j], dista[st] + grapho[st][j]);
		}
	}
	printf("%d", dista[goale]);
}
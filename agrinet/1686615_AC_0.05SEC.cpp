#include<iostream>
#include<algorithm>
int min(int a, int b){
	if (a - b > 0){
		return b;
	}

	return a;
}
int total_house;
int town[111][111];
int dis[111];
int from[111];
int main(void){
	int i, j, sum=0;
	scanf("%d", &total_house);
	for (i = 1; i <= total_house; i++){
		for (j = 1; j <= total_house; j++){
			scanf("%d", &town[i][j]);
		}
	}
	for (i = 1; i <= total_house; i++){
		dis[i] = 999999999;
	}
	int node = 1;
	dis[node] = -1;
	for (j = 1; j <= total_house;j++){
		if (dis[j] != -1){
			dis[j] = min(dis[j], town[node][j]);
		}
	}
	for (i = 1; i <= total_house; i++){
		int mn = 99999999;
		for (j = 1; j <= total_house; j++){
			if (mn > dis[j]&& dis[j]!=-1){
				node = j;
				mn = dis[j];
			}
		}
		sum += dis[node];
		dis[node] = -1;
		for (j = 1; j <= total_house;j++){
			if (dis[j] != -1){
				dis[j] = min(dis[j], town[node][j]);
			}
		}
	}
	printf("%d", sum+1);
}
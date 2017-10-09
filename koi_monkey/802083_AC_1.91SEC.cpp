#include<iostream>
using namespace std;
int n;
int animosity[1000000][3];
int inverseanimosity[1000000][3];
int group1[1000000];
int group2[1000000];
int wheregroup[1000000];
int main() {
    cin>>n;
    int i,j,c;
    for(i=1;i<=n;i++) {
        cin>>c;
		for(j=1;j<=c;j++) {
			cin>>animosity[i][j];
			
		}
    }
	int cnt1=0;
	for(i=1;i<=n/2;i++) {
		cnt1++;
		group1[i]=i;
		wheregroup[i]=1;
	}
	int cnt2=0;
	for(i=n/2+1;i<=n;i++) {
		cnt2++;
		group2[cnt2]=i;
		wheregroup[i]=2;
	}
	bool t=true;
	while(t) {
		t=false;
		for(i=1;i<=cnt1;i++) {
			if(group1[i]==-1) continue;
			int violation = (wheregroup[group1[i]]==wheregroup[animosity[group1[i]][1]])+(wheregroup[group1[i]]==wheregroup[animosity[group1[i]][2]])+(wheregroup[group1[i]]==wheregroup[animosity[group1[i]][3]]);
			if(violation > 1) {
				wheregroup[group1[i]]=2;
				group2[++cnt2]=group1[i];
				group1[i]=-1;
				t=true;
			}
		}

		for(i=1;i<=cnt2;i++) {
			if(group2[i]==-1) continue;
			int violation = (wheregroup[group2[i]]==wheregroup[animosity[group2[i]][1]])+(wheregroup[group2[i]]==wheregroup[animosity[group2[i]][2]])+(wheregroup[group2[i]]==wheregroup[animosity[group2[i]][3]]);
			if(violation > 1) {
				wheregroup[group2[i]]=1;
				group1[++cnt1]=group2[i];
				group2[i]=-1;
				t=true;
			}
		}

	}
	for(i=1;i<=cnt1;i++) {
		if(group1[i]==-1) continue;
		cout<<group1[i]<<" ";
	}
	cout<<endl;
	for(i=1;i<=cnt2;i++) {
		if(group2[i]==-1) continue;
		cout<<group2[i]<<" ";

	}

}
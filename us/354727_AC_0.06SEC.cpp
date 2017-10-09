#include<iostream>
#include<algorithm>
using namespace std;
struct A {
    int value,index;
};
A data[200000]={0};
int indexed[200000]={0};
A oneroot[200000]={0};
A indextree[200000]={0};
int imsi[200000]={0};
int back[200000]={0};
int arr[200000]={0};
int ind2=0;
int n;
int i;
int size=1;
bool cmp(A a,A b) {
    return a.value < b.value;
}
int main() {
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        scanf("%d",&data[i].value);
        data[i].index = i;
        oneroot[i] = data[i];
    }
    for(size=1;size<n;size*=2); //완전 이진트리가 되어야하므로 인덱스를 셋팅한다.
    sort(data+1,data+n+1,cmp); // 오름차순으로 정렬해서 차근차근 push한다. 어쩌피 Indexed tree에서는 인덱스가 3이면 1-3 구간만 봄으로..
    for(i=0;i<n;i++) {
        imsi[i+1] = (data[i].value == data[i+1].value ? 0 : 1)+imsi[i]; //삼항연산자가 들어가는 이유는 중복이 생길 수 있기 때문..
    }
    for(i=1;i<=n;i++) indexed[data[i].index] = imsi[i];
    int length=0;
    int f=0;
    //indexed --> 트리에서의 인덱스
    //data[i].index = 배열인덱스
    for(i=1;i<=n;i++) {
        int l=size,r=size+indexed[i]-2; // -1하는 이유는 깊이가 n인 완전이진트리의 노드 갯수는 2^n-1이기 때문 또 -1은 이전노드까지이기 때문
        bool t = true;
        int mx=0;
        int ind=0;
        while(l<=r && t) {
            if(l == r) t = false;
            if(l % 2 == 1) {
                if(indextree[l].value > mx) {
                    mx = indextree[l].value;
                    ind = indextree[l].index;
                }
                l++;
            }
            if(r % 2 == 0) { 
                if(indextree[r].value > mx) {
                    mx = indextree[r].value;
                    ind = indextree[r].index;
                }
                r--;
            }
            l/=2; //루트노드 이동
            r/=2; //루트노드 이동
        }
        mx++;
        if(mx > length) {
            length = mx;
            f = i;
        }
        back[i] = ind;
        int rw = size+indexed[i]-1;
        while(rw > 0) {
            if(indextree[rw].value < mx) {
                indextree[rw].value = mx;
                indextree[rw].index = i;
            }
            rw/=2; //루트노드 이동.
        }
    }
    printf("%d\n",length);
    int tt=f;
    arr[ind2++] = f;
    while(tt != 0) {
        tt = back[tt];
        if(tt == 0) break;
        arr[ind2++] = tt;
    }
    for(int i=ind2-1;i>=0;i--) {
        printf("%d ",oneroot[arr[i]].value);
    }
}
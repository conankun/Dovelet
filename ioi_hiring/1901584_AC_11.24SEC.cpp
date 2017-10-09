#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
int N; ll W;
struct employee {
    ll S, Q;
    int ind,ind2;
    bool operator<(const employee& ee) const {
        return Q > ee.Q;
    }
}arr[555555];
struct employee2 {
    ll S, Q;
    int ind;
    bool operator<(const employee2& ee) const {
        return  ee.ind > ind;
    }
};
bool cmp(employee a, employee b) {
    return (double)a.S /a.Q < (double)b.S / b.Q;
}
bool cmp2(employee a, employee b) {
    return a.ind < b.ind;
}
priority_queue<employee> qu;
priority_queue<employee2> ans;
int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    scanf("%d%lld",&N,&W);
    int i;
    for (i = 1; i <= N; i++) {
        scanf("%lld%lld",&arr[i].S,&arr[i].Q);
        arr[i].ind = i;
    }
    sort(arr + 1, arr + 1 + N,cmp);
    ll total = 0;
    double cost = -1;
    int mx = 0, ansind=0;
    for (i = 1; i <= N; i++) {
        arr[i].ind2 = i;
        qu.push(arr[i]);
    }
    for (i = N; i >= 1; i--) {
        while (!ans.empty()) {
            employee2 tt = ans.top();
            if (tt.ind > i) {
                total -= tt.Q;
                ans.pop();
            }
            else break;
        }

        while (!qu.empty()) {
            employee tt = qu.top();
            if (tt.ind2 > i) {
                qu.pop();
            } else if ((total + tt.Q) * arr[i].S <= W * arr[i].Q) {
                total += tt.Q;
                employee2 emp;
                emp.ind = tt.ind2;
                emp.Q = tt.Q;
                emp.S = tt.S;
                ans.push(emp);
                qu.pop();
            }
            else break;
        }
        if (ans.size() > mx || (mx == ans.size() && (arr[i].S/(double)arr[i].Q)*total < cost)) {
            cost = (arr[i].S / (double)arr[i].Q)*total;
            mx = ans.size();
            ansind = i;
        }
    }
    printf("%d\n",mx);
   // cout << mx << endl;
    priority_queue<employee> pq;
    vector<int> ve;
    for (i = 1; i <= ansind; i++) pq.push(arr[i]);
    total = 0;
    while (!pq.empty()) {
        if ((total + pq.top().Q) * arr[ansind].S <= W * arr[ansind].Q) {
            total += pq.top().Q;
            ve.push_back(pq.top().ind);
            pq.pop();
        }
        else break;
    }
    for (i = 0; i < ve.size(); i++) printf("%d\n",ve[i]);// << endl;
}
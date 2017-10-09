#include <iostream>
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
	cin >> N >> W;
	int i;
	for (i = 1; i <= N; i++) {
		cin >> arr[i].S >> arr[i].Q;
		arr[i].ind = i;
	}
	sort(arr + 1, arr + 1 + N,cmp);
	ll total = 0;
	int mx = 0, ansind=0;
	for (i = 1; i <= N; i++) {
		arr[i].ind2 = i;
		qu.push(arr[i]);
	}
	for (i = N; i >= 1; i--) {
		while (!ans.empty()) {
			if (ans.top().ind > i) {
				total -= ans.top().Q;
				ans.pop();
			}
			else break;
		}

		while (!qu.empty()) {
			if (qu.top().ind2 > i) {
				qu.pop();
			} else if ((total + qu.top().Q) * arr[i].S <= W * arr[i].Q) {
				total += qu.top().Q;
				employee2 emp;
				emp.ind = qu.top().ind2;
				emp.Q = qu.top().Q;
				emp.S = qu.top().S;
				ans.push(emp);
				qu.pop();
			}
			else break;
		}
		if (ans.size() >= mx) {
			mx = ans.size();
			ansind = i;
		}
	}

	cout << mx << endl;
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
	sort(ve.begin(), ve.end());
	for (i = 0; i < ve.size(); i++) cout << ve[i] << endl;
}
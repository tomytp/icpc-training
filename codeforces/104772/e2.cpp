#include <bits/stdc++.h>
 
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector < pair <int, int> > a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	if (n == 1) {
		cout << "YES\n";
		// cout << a[0].first << " " << a[0].second;
		return;
	}
	int add = 0;
	unordered_map < int, int > cnt;
	for (int i = 1; i < n; i++) {
		if (a[0].first == a[i].first) {
			add++;
		} else {
			cnt[a[i].second]++;
			cnt[a[i].second - abs(a[0].first - a[i].first)]++;
			cnt[a[i].second + abs(a[0].first - a[i].first)]++;
		}
	}
	for (auto x : cnt) {
		if (x.second + add == n - 1) {
			cout << "YES\n";
			// cout << a[0].first << " " << x.first;
			return;
		}
	}
	add = 0;
	cnt.clear();
	for (int i = 1; i < n; i++) {
		if (a[0].second == a[i].second) {
			add++;
		} else {
			cnt[a[i].first]++;
			cnt[a[i].first - abs(a[0].second - a[i].second)]++;
			cnt[a[i].first + abs(a[0].second - a[i].second)]++;
		}
	}
	for (auto x : cnt) {
		if (x.second + add == n - 1) {
			cout << "YES\n";
			// cout << x.first << " " << a[0].second;
			return;
		}
	}
	cnt.clear();
	add = 0;
	for (int i = 1; i < n; i++) {
		if (a[0].first - a[0].second == a[i].first - a[i].second) {
			add++;
		} else {
			cnt[a[i].first - (a[0].first - a[0].second)]++;
			cnt[a[i].second]++;
			int val = ((a[0].first - a[0].second) + (a[i].first + a[i].second));
			if (val % 2 == 0) {
				cnt[a[i].first + a[i].second - val / 2]++;
			}
		}
	}
	for (auto x : cnt) {
		if (x.second + add == n - 1) {
			cout << "YES\n";
			// cout << a[0].first - a[0].second + x.first << " " << x.first;
			return;
		}
	}
	cnt.clear();
	add = 0;
	for (int i = 1; i < n; i++) {
		if (a[0].first + a[0].second == a[i].first + a[i].second) {
			add++;
		} else {
			cnt[(a[0].first + a[0].second) - a[i].first]++;
			cnt[a[i].second]++;
			int val = (a[0].first + a[0].second) + (a[i].first - a[i].second);
			if (val % 2 == 0) {
				cnt[a[0].first + a[0].second - val / 2]++;
			}
		}
	}
	for (auto x : cnt) {
		if (x.second + add == n - 1) {
			cout << "YES\n";
			// cout << a[0].first + a[0].second - x.first << " " << x.first;
			return;
		}
	}
	cout << "NO\n";
}

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
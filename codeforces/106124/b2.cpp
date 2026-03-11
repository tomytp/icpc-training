#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define sz(x) (int)x.size()
#define se second
#define fi first
#define sq(x) ((x) * (x))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;

#define N 105
#define MAXLOG 35

// 100 600 | 100
int n, h, w;
int hs[N + 1], ts[N + 1];
int DP[N + 1][610][500][4];
int tot = 0;

int dp(int i, int th, int hg, int state) {
  if (i == n) {
    if (state != 3) return 0;
    if (w - th < hg) return 0;
    if (h < tot - th) return 0;
    if (th > w) return 0;
    return 1;
  }

  if (DP[i][th][hg][state] != -1) return DP[i][th][hg][state];

  if (hs[i] > h) {
    return DP[i][th][hg][state] =
               dp(i + 1, th, max(hg, hs[i]), state | (1 << 1));
  }

  return DP[i][th][hg][state] =
             max(dp(i + 1, th, max(hg, hs[i]), state | (1 << 1)),
                 dp(i + 1, th + ts[i], hg, state | (1 << 0)));
}

vector<int> ans[2];

void rec(int i, int th, int hg, int state) {
  if (i == n) {
    return;
  }

  if (hs[i] > h) {
    ans[1].push_back(i);
    rec(i + 1, th, max(hg, hs[i]), state | (1 << 1));
    return;
  }

  if (dp(i + 1, th, max(hg, hs[i]), state | (1 << 1)) >
      dp(i + 1, th + ts[i], hg, state | (1 << 0))) {
    ans[1].push_back(i);
    rec(i + 1, th, max(hg, hs[i]), state | (1 << 1));
    return;
  }

  ans[0].push_back(i);
  rec(i + 1, th + ts[i], hg, state | (1 << 0));
}

void solve() {
  cin >> n >> h >> w;
  for (int i = 0; i < n; i++) {
    cin >> hs[i] >> ts[i];
    tot += ts[i];
  }

  memset(DP, -1, sizeof(DP));

  if (dp(0, 0, 0, 0)) {
    rec(0, 0, 0, 0);
    if (ans[0].empty() || ans[1].empty()) {
      cout << "impossible" << endl;
      return;
    }
    cout << "upright ";
    for (int i : ans[0]) cout << i + 1 << " ";
    cout << endl;
    cout << "stacked ";
    sort(ans[1].begin(), ans[1].end(),
         [&](int i, int j) { return hs[i] > hs[j]; });
    for (int i : ans[1]) cout << i + 1 << " ";
    cout << endl;
  } else {
    cout << "impossible" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}
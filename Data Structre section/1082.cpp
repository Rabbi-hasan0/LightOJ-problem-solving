#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

const int N = 1e5 + 9;
int a[N + 1];
struct ST {
  #define lc (n << 1)   //define rig
  #define rc ((n << 1) + 1)
  int t[4 * N], lazy[4 * N];
  static const int inf = 1e9;
  ST() {
    memset(t, 0, sizeof(t));
    memset(lazy, 0, sizeof(lazy));
  }
  inline void pull(int n) {
    t[n] = min(t[lc], t[rc]);
  }
  inline int combine(int a,int b) { 
    return min(a, b);
  }
  inline void push(int n, int b, int e) {
    if(lazy[n] == 0) return;
    t[n] = t[n] + lazy[n] * (e - b + 1);
    if(b != e) {
      lazy[lc] = lazy[lc] + lazy[n];
      lazy[rc] = lazy[rc] + lazy[n];
    }
    lazy[n] = 0;
  }
  void build(int n, int b, int e) { // Ekhan theke n jacce macro lc and rc te😁😁😁
    lazy[n] = 0;
    if (b == e) {
      t[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }

  void update(int n, int b, int e, int i, int j, int val) {
    push(n, b, e);
    if(j < b || e < i) {
      return;
    }
    if(i <= b && e <= j) {
      lazy[n] = val;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    update(lc, b, mid, i, j, val);
    update(rc, mid + 1, e, i, j, val);
    pull(n);
  }

  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(j < b || e < i) {
      return 1e9;
    }
    if(i <= b && e <= j) {
      return t[n];
    }
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
  }
}st;

void solved() {
    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    st.build(1, 1, n);
    while(q--) {
        int l, r; cin >> l >> r;
        int x = st.query(1, 1, n, l, r);
        cout << x << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i <<": \n";
        solved();
    }
    return 0;
}

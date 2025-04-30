#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;
const int N = 1e6;
const int MOD = 1e9 + 7;

void solved() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &i: a) {
        cin >> i;
    }

    int cnt = 0;
    vector<int> vis(n + 1, false);
    for(int i = 0; i < n; ++i) {
        if(vis[i + 1]) continue;
        int next = i + 1;
        while(!vis[next]) {
            vis[next] = true;
            next = a[next - 1];
        }
        cnt++;
    }
    cout << n - cnt << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i <<": ";
        solved();
    }
    return 0;
}

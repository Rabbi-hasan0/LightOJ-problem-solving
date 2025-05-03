#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;
const int N = 1e6;
const int MOD = 1e9 + 7;

void solved() {
    int n; cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for(auto &i: a) {
        cin >> i;
        mp[i]++;
    }

    int ans = 0;
    for(auto [x, y]: mp) {
        int val = (y + x)/ (x + 1);
        ans += val * (x + 1);
    }
    cout << ans << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i <<": ";
        solved();
    }
    return 0;
}

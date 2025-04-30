#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;
const int N = 1e6;
const int MOD = 1e9 + 7;

bool check(vector<int> &a, int mid, int k) {
    int n = a.size(), cnt = 1;
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        if(sum + a[i] <= mid) {
            sum += a[i];
        } else {
            cnt++;
            sum = a[i];
        }
    }
    return (cnt <= k);
}
void solved() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    int mx = 0;
    for(auto &i: a) {
        cin >> i;
        mx = max(mx, i);
    }

    int l = mx, r = 1e13, ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(a, mid, k)){
            ans = mid;
            r = mid - 1;
        } else{
            l = mid + 1;
        }
    }
    cout << ans << '\n';
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

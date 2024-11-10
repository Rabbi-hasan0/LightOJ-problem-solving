#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

void solved() {
    int n, k; cin >> n >> k; n++;
    vector<int> a(n); int mx = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    vector<int> ans_v;
    auto check = [&](int mid) {
        int sum = 0, cnt = 0; 
        vector<int> temp;
        for(int i = 0; i < n; i++) {
            if(sum + a[i] <= mid) {
                sum += a[i];
            } else {
                temp.push_back(sum);
                sum = a[i];
                cnt++;
            }
        }
        temp.push_back(sum);
        ans_v = temp;
        return cnt <= k;
    };
    int l = mx, r = 1e18, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) { 
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    check(ans);
    int baki = k + 1 - ans_v.size();
    vector<int> res;
    while(baki > 0) {
        ans_v.back() -= a.back();
        res.push_back(a.back());
        a.pop_back();
        if(ans_v.back() == 0) {
            ans_v.pop_back();
        } else {
            baki--;
        }
    }
    reverse(res.begin(), res.end());
    for(auto &i: res) {
        ans_v.push_back(i);
    }
    cout << ans << '\n';
    for(auto &i: ans_v) {
        cout << i << '\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for(int i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solved();
    }
    return 0;
}

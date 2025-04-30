
#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;
const int N = 1e6;

void solved() {
    int n, w; cin >> n >> w;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a.push_back(y);
    }
    sort(a.begin(), a.end());
    int trac = a[0], ans = 1; 
    for(int i = 0; i < n; i++) {
        if(trac + w < a[i]) {
            ans++;
            trac = a[i];
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

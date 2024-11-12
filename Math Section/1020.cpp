#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;
const int N = 1e6;
const int MOD = 1e9 + 7;

void solved() {
    int n; cin >> n;
    string s; cin >> s;
    if(s == "Alice") {
        print((n % 3 == 1 ? "Bob": s));
    }
    else {
        print((n % 3 == 0 ? "Alice": s));
    }
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

#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;
const int N = 1e6;
const int MOD = 1e9 + 7;

void solved() {
    int n, d; cin >> n >> d;
    int temp = d, cnt = 1, cal = d * 10;
    for(int i = 0; i < n; i++) {
        if(temp % n == 0) break;
        cnt++;
        temp += cal;
        cal *= 10; 
        cal %= n;
    }
    print(cnt);
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

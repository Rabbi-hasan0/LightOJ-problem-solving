#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;
const int N = 1e6;
const int MOD = 1e9 + 7;

bool check(int a, int b, int c) {
    if(a == 6) {
        if(b == 3 and c == 0) {
            return true;
        }
        if(b == 1 and c == 1) {
            return true;
        }
    }
    if(a == 4) {
        if(b == 3 and c == 1) {
            return true;
        } 
        if(b == 2 and c == 1) {
            return true;
        }
        if(b == 4 and c == 0) {
            return true;
        }
    }
    if(a == 3 and b == 3 and  c == 3) {
        return true;
    }
    if(a == 2 and b == 2 and c == 2) {
        return true;
    }
    return false;
}
void solved() {
    int n = 3;
    vector<int> a(n); 
    for(int &i: a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    if(check(a[2], a[1], a[0])) {
        cout << "perfectus\n";
    } else {
        cout << "invalidum\n";
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

#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;
void solved() {
    string s; int n;
    cin >> s >> n;
    int x = 0;
    if(s[0] == '-') x++;
    int val = s[x] - '0'; 
    for (int i = x + 1; i < s.size(); i++) {
        int rem = val % n;
        val = rem * 10 + (s[i] - '0');
    }
    if(val % n == 0) {
        print("divisible");
    } else print("not divisible");
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

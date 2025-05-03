#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;
const int mod = 1000003;
const int N = 2e6;
int factorial[N];
void factorial_precal() {
    factorial[1] = factorial[0] = 1;
    for(int i = 2; i < N; i++) {
        factorial[i] = i * factorial[i - 1];
        factorial[i] %= mod;
    }
}

int power(long long n, long long k, int mod) { // n^k % mod --> mod <= 10^9 [O(log(k))];
  int ans = 1 % mod; 
  n %= mod; 
  if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}

int cal(int n) {
    return power(factorial[n], mod - 2, mod);
}
int ncr(int n, int r) {
    return factorial[n] * cal(r) % mod * cal(n - r) % mod;
}

void solved() {
    int n, r; cin >> n >> r;
    if (r > n) {
        cout << 0 << '\n';
        return;
    }
    cout << ncr(n, r) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    factorial_precal();
    int t = 1; cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i <<": ";
        solved();
    }
    return 0;
}

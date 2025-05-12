#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;
const int mod = 1000000007;
const int N = 3e6 + 5;
// int pref[N], a[N];

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
int inv(int n) {
    return power(n, mod - 2, mod);
}
int fact[N], inv_fact[N];
void factorial_precal() {
    fact[1] = fact[0] = 1;
    inv_fact[0] = inv_fact[1] = inv(fact[1]) % mod;
    for(int i = 2; i < N; i++) {
        fact[i] = i * fact[i - 1];
        fact[i] %= mod;
        inv_fact[i] = inv(fact[i]) % mod;
    }
}
int ncr(int n, int r) {
    // cout << inv_fact[r] << ' ' << inv(fact[r]) << '\n';
    // cout << inv_fact[n - r] << ' ' << inv(fact[n - r]) << '\n';
    int res = fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
    return res;
}
void solved() {
    int n, k; cin >> n >> k;
    cout << ncr(n + k - 1, k - 1) << '\n';
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(fact, 1, sizeof fact);
    memset(inv_fact, 0, sizeof inv_fact);
    factorial_precal();
    int t = 1;cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case " << i <<": ";
        solved();
    }
    return 0;
}

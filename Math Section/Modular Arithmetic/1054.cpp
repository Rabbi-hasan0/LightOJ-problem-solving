#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;
const int mod = 1000000007;
// int pref[N], a[N];
unordered_map<int, int> cnt;
vector<int> factorization(long long n) {
    vector<int> primes;
    if (n % 2 == 0) {
        primes.push_back(2);
        while (n % 2 == 0) {
            cnt[2]++;
            n /= 2;
        }
    }
    for (long long d = 3; d * d <= n; d += 2) { 
        if (n % d == 0) {
        primes.push_back(d);
            while (n % d == 0) {
                cnt[d]++;
                n /= d;
            }
        }
    }
    if (n > 1) {
        if (!cnt[n])
            primes.push_back(n);
        cnt[n]++;
    }
    return primes;
}

int power(long long n, long long k, int mod) { 
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
void solved() {
    int n, m; cin >> n >> m;
    cnt.clear();
    vector<int> primes = factorization(n);
    int ans = 1;
    for(auto i: primes) {
        int p = i;
        int e = cnt[i] * m;
        int up = power(p, e + 1, mod);
        up -= 1;
        if(up < 0) {
            up += mod;
        }
        int dw = inv(p - 1) % mod;
        ans = (ans % mod * up % mod * dw % mod) % mod;
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

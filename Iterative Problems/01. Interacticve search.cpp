/* Solved By: Rabbi Hasan */
/* Dept. of CSE
/* Bangladesh University of Business and Technology */

#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

int32_t main() {
    int t = 1; //cin >> t;
    while(t--){
        int n; cin >> n;
        int l = 1, r = n, ans = 0;
        while (l <= r and ans <= 30) {
            ans++;
            int mid = (l + r) / 2;
            cout << "guess " << mid << '\n';
            string s; cin >> s;
            if(s == "correct") {
                break;
            }
            if (s == "low"){
                l = mid + 1;
            } else{
                r = mid - 1;
            }
        }
        if(ans > 30) print("too many tries");
    }
    return 0;
}

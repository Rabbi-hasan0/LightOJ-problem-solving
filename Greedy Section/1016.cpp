/*
Explaination: 
-------------
Ycoordinates = {100,3,131,5,99}
Brush width = 3
Sort(Ycoordinates) = {3,5,99,100,131}

1st inclusive range
= [Sort(Ycoordinates)'s 1st element,
   (Sort(Ycoordinates)'s 1st element
    + Brush's width)
  ]
= [3,3+3] = [3,6]

Up to 5, {3,5} falls in the inclusive range [3,6]

Next inclusive range
= [Which element did not meet the last inclusive range
   (Which element did not meet the last inclusive range +Brushe's width)]
= [99,102]
So, {99,100} will be covered now.

We keep going like this and increment the inclusive range and number of moves each time.
*/

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

#include <bits/stdc++.h>
#define print(x) cout << x << '\n'
#define int long long
using namespace std;

void call_nai() {
    cout << "Ignored\n";
}

void solved() {
    string task; 
    stack<string> st;
    stack<string> st1;
    st1.push("http://www.lightoj.com/");
    while(cin >> task) {
        string s;
        if(task == "VISIT") {
            cin >> s;
            st1.push(s);
            while(!st.empty()) st.pop();
            cout << st1.top() << '\n';
        } 
        else if(task == "BACK") {
            if(st1.size() > 1) {
                st.push(st1.top());
                st1.pop();
                cout << st1.top() << '\n';
            } else {
                call_nai();
            }
        }
        else if(task == "FORWARD") {
            if(!st.empty()) {
                st1.push(st.top());
                cout << st.top() << '\n';
                st.pop();
            } else {
                call_nai();
            }
        }
        else if(task == "QUIT") {
            return;
        }
    }
}

int32_t main() {
    int t; cin >> t;
    cin.ignore();
    for(int i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";
        solved();
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    vector<int> vals;
    int x;
    while (cin >> x) vals.push_back(x);
    if (vals.empty()) return 0;

    int n = vals.size();

    
    vector<int> seen(n+1,0);
    for (int v : vals) {
        if (v < 1 || v > n) { cout << "No\n"; return 0; }
        seen[v]++;
        if (seen[v] > 1) { cout << "No\n"; return 0; }
    }

    queue<int> q;
    for (int v : vals) q.push(v);
    stack<int> st;
    int expected = 1;

    while (!q.empty()) {
        if (q.front() == expected) {
            q.pop();
            ++expected;
        } else if (!st.empty() && st.top() == expected) {
            st.pop();
            ++expected;
        } else {
            st.push(q.front());
            q.pop();
        }
    }

    while (!st.empty() && st.top() == expected) {
        st.pop();
        ++expected;
    }

    cout << (expected == n + 1 ? "Yes" : "No") << '\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    string line;
    if (!getline(cin, line) || line.empty()) return 0;

    istringstream iss(line);
    vector<int> a;
    int v;
    while (iss >> v) a.push_back(v);

    int n = (int)a.size();
    if (n <= 1) { 
        for (int x : a) cout << x << ' ';
        cout << '\n';
        return 0;
    }

    int half = n / 2;               
    queue<int> q1, q2;
    for (int i = 0; i < half; ++i) q1.push(a[i]);
    for (int i = half; i < n; ++i) q2.push(a[i]);

    
    bool firstTurn = true;
    vector<int> out;
    while (!q1.empty() && !q2.empty()) {
        out.push_back(q1.front()); q1.pop();
        out.push_back(q2.front()); q2.pop();
    }
    
    while (!q2.empty()) { out.push_back(q2.front()); q2.pop(); }
    while (!q1.empty()) { out.push_back(q1.front()); q1.pop(); }

    
    for (size_t i = 0; i < out.size(); ++i) {
        if (i) cout << ' ';
        cout << out[i];
    }
    cout << '\n';
    return 0;
}

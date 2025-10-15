#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> freq(256, 0);
    queue<char> q;
    string token;

    
    while (cin >> token) {
        char ch = token[0];
        ++freq[(unsigned char)ch];
        q.push(ch);

       
        while (!q.empty() && freq[(unsigned char)q.front()] > 1) q.pop();

        if (q.empty()) cout << "-1";
        else cout << q.front();

       
        if (!cin.eof()) cout << ' ';
    }
    cout << '\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void generateBinary(int n) {
    if (n <= 0) return;
    queue<string> q;
    q.push("1");
    while (n--) {
        string s = q.front();
        q.pop();
        cout << s;
        if (n > 0) cout << ", ";
        q.push(s + "0");
        q.push(s + "1");
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    generateBinary(n);
    return 0;
}

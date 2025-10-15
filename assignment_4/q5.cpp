
a part

#include <bits/stdc++.h>
using namespace std;

class StackTwoQueues {
    queue<int> q1, q2; 
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) { q2.push(q1.front()); q1.pop(); }
        swap(q1, q2);
    }
    void pop() {
        if (!q1.empty()) q1.pop();
    }
    int top() const {
        if (q1.empty()) throw runtime_error("stack empty");
        return q1.front();
    }
    bool empty() const { return q1.empty(); }
};

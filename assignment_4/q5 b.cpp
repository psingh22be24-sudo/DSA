class StackOneQueue {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int sz = q.size();     
        for (int i = 0; i < sz - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (!q.empty()) q.pop();
    }
    int top() const {
        if (q.empty()) throw runtime_error("stack empty");
        return q.front();
    }
    bool empty() const { return q.empty(); }
};

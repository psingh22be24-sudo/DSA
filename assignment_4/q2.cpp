#include <iostream>
#include <vector>
using namespace std;

class CircularQueue {
    vector<int> buf;
    int frontIdx = 0;
    int size_ = 0;
public:
    CircularQueue(int capacity = 10) : buf(capacity) {}

    bool isEmpty() const { return size_ == 0; }
    bool isFull()  const { return size_ == (int)buf.size(); }

    bool enqueue(int x) {
        if (isFull()) return false;
        int pos = (frontIdx + size_) % buf.size();
        buf[pos] = x;
        ++size_;
        return true;
    }

    bool dequeue(int &out) {
        if (isEmpty()) return false;
        out = buf[frontIdx];
        frontIdx = (frontIdx + 1) % buf.size();
        --size_;
        return true;
    }

    bool peek(int &out) const {
        if (isEmpty()) return false;
        out = buf[frontIdx];
        return true;
    }

    void display() const {
        if (isEmpty()) { cout << "Queue is empty\n"; return; }
        cout << "Front -> ";
        for (int i = 0; i < size_; ++i) {
            if (i) cout << " -> ";
            cout << buf[(frontIdx + i) % buf.size()];
        }
        cout << " <- Rear\n";
    }
};

int main() {
    int cap;
    cout << "Enter queue capacity: ";
    if (!(cin >> cap) || cap <= 0) return 0;

    CircularQueue q(cap);
    while (true) {
        cout << "\nMenu:\n"
             << "1. enqueue()\n"
             << "2. dequeue()\n"
             << "3. isEmpty()\n"
             << "4. isFull()\n"
             << "5. peek()\n"
             << "6. display()\n"
             << "0. exit\n"
             << "Choice: ";

        int choice; if (!(cin >> choice)) break;
        if (choice == 0) break;

        int x;
        switch (choice) {
            case 1:
                cout << "Value to enqueue: ";
                if (!(cin >> x)) { cout << "Invalid input\n"; cin.clear(); cin.ignore(1e9,'\n'); break; }
                cout << (q.enqueue(x) ? "Enqueued\n" : "Queue is full\n");
                break;
            case 2:
                if (q.dequeue(x)) cout << "Dequeued: " << x << '\n';
                else cout << "Queue is empty\n";
                break;
            case 3:
                cout << (q.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
                break;
            case 4:
                cout << (q.isFull() ? "Queue is full\n" : "Queue is not full\n");
                break;
            case 5:
                if (q.peek(x)) cout << "Front element: " << x << '\n';
                else cout << "Queue is empty\n";
                break;
            case 6:
                q.display();
                break;
            default:
                cout << "Invalid choice\n";
        }
    }

    cout << "Exiting.\n";
    return 0;
}

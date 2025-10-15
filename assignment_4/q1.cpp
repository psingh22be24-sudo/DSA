#include <bits/stdc++.h>
using namespace std;

struct CircularQueue {
    vector<int> a; int front=0, sz=0;
    CircularQueue(int cap=10){ a.resize(cap); }
    bool isEmpty() const { return sz==0; }
    bool isFull() const { return sz==(int)a.size(); }
    bool enqueue(int x){ if(isFull()) return false; a[(front+sz)%a.size()]=x; ++sz; return true; }
    bool dequeue(int &x){ if(isEmpty()) return false; x=a[front]; front=(front+1)%a.size(); --sz; return true; }
    bool peek(int &x) const { if(isEmpty()) return false; x=a[front]; return true; }
    void display() const {
        if(isEmpty()){ cout<<"Queue empty\n"; return; }
        for(int i=0;i<sz;++i){ if(i) cout<<" -> "; cout<<a[(front+i)%a.size()]; } cout<<"\n";
    }
};

int main(){
    int cap; cout<<"Capacity: "; if(!(cin>>cap) || cap<=0) return 0;
    CircularQueue q(cap);
    for(;;){
        cout<<"\n1:enqueue 2:dequeue 3:isEmpty 4:isFull 5:peek 6:display 0:exit\n> ";
        int ch; if(!(cin>>ch)) break;
        if(ch==0) break;
        int x;
        switch(ch){
            case 1: cout<<"val: "; cin>>x; cout<<(q.enqueue(x)? "enqueued\n":"full\n"); break;
            case 2: cout<<(q.dequeue(x)? (cout<<"dequeued: "<<x<<"\n", true):(cout<<"empty\n",false)); break;
            case 3: cout<<(q.isEmpty()? "empty\n":"not empty\n"); break;
            case 4: cout<<(q.isFull()? "full\n":"not full\n"); break;
            case 5: cout<<(q.peek(x)? (cout<<"front: "<<x<<"\n", true):(cout<<"empty\n",false)); break;
            case 6: q.display(); break;
            default: cout<<"invalid\n";
        }
    }
    return 0;
}

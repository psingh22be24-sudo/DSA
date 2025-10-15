#include <bits/stdc++.h>
using namespace std;
int countUnable(vector<int>& students, vector<int>& sandwiches){
    int c0 = 0, c1 = 0;
    for(int x: students) (x==0?++c0:++c1);
    for(int s: sandwiches){
        if(s==0){
            if(c0>0) --c0;
            else break;
        } else {
            if(c1>0) --c1;
            else break;
        }
    }
    return c0 + c1;
}
int main(){
    vector<int> students{1,1,0,0}, sandwiches{0,1,0,1};
    cout << countUnable(students, sandwiches) << '\n'; // 0
}


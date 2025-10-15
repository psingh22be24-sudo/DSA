#include <bits/stdc++.h>
using namespace std;


int getMinIndex(queue<int>& q, int sortedIndex) {
    int minIndex = -1;
    int minValue = INT_MAX;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int current = q.front();
        q.pop();

        
        if (current <= minValue && i <= sortedIndex) {
            minIndex = i;
            minValue = current;
        }

        q.push(current);
    }
    return minIndex;
}

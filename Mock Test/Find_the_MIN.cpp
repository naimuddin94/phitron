#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    // Min-heap to get the minimum element efficiently
    priority_queue<int, vector<int>, greater<int>> minHeap;
    unordered_map<int, int> countMap;  // To track the count of each element

    while (Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int X;
            cin >> X;
            // Insert X into the heap and update the count
            minHeap.push(X);
            countMap[X]++;
        } 
        else if (type == 2) {
            if (minHeap.empty()) {
                cout << "empty\n";
            } else {
                // Remove stale elements from the heap if necessary
                while (!minHeap.empty()) {
                    int minVal = minHeap.top();
                    // If this value is still valid, process it
                    if (countMap[minVal] > 0) {
                        cout << minVal << "\n";
                        // Erase all occurrences of this value
                        countMap[minVal] = 0;
                        break;
                    }
                    // Pop stale element from heap
                    minHeap.pop();
                }
            }
        }
    }

    return 0;
}

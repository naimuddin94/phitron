#include <iostream>
#include <vector>
#include <string>
using namespace std;

int min_operations_to_erase(const string& s) {
    int n = s.size();
    if (n == 0) return 0; // If the string is empty, 0 operations are needed

    int operations = 1; // At least one operation is needed to start

    // Traverse the string and count blocks of consecutive characters
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            operations++; // We found a new block of different characters
        }
    }

    return operations;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Number of test cases

    while (T--) {
        int n;
        string s;
        cin >> n >> s; // Read string length and string

        cout << min_operations_to_erase(s) << "\n"; // Print the result for the current test case
    }

    return 0;
}

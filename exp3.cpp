#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {10, 20, 20, 10, 10, 20, 5, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    unordered_map<int, int> freq;

    // Count frequencies in O(n)
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Display frequencies
    for (auto it : freq) {
        cout << it.first << "  " << it.second << endl;
    }

    return 0;
}

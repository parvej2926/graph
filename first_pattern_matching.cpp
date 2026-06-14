#include <iostream>
using namespace std;
int main() {
    string text, pattern;
    // Example input:
    // text = "ababcabcab"
    // pattern = "abc"
    cin >> text >> pattern;
    int n = text.size();
    int m = pattern.size();
    for (int i = 0; i <= n - m; i++) {
        // substring
        string sub = text.substr(i, m);
        // compare
        if (sub == pattern) {
            cout << "Pattern found at index " << i+1 << endl;
        }
    }
    return 0;
}

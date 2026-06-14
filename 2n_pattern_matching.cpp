#include <iostream>
#include <vector>
using namespace std;

int main() {
    string text = "ababcabcab";
    string pattern = "aabaaba";
    // text:
    // a b a b c a b c a b

    // pattern:
    // a a b a a b a
    // 0 1 2 3 4 5 6
    int n = text.size();
    int m = pattern.size();
    vector<int> lps(m, 0);
    int len = 0;   // longest prefix suffix length
    int i = 1;
    // pattern: a a b a a b a
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            // MATCH FOUND
            len++;
            lps[i] = len;
            // Example step:
            // i=1: a == a → lps[1]=1
            // i=4: a == a → lps[4]=2
            // i=5: b == b → lps[5]=3
            // i=6: a == a → lps[6]=4
            i++;
        }
        else {
            // mismatch case
            if (len != 0) {
                // fallback using previous LPS
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    // FINAL LPS:
    // [0, 1, 0, 1, 2, 3, 4]
    i = 0; // text index
    int j = 0; // pattern index
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            // Example flow:

            // text:  a b a b c a b c a b
            // pattern: a a b a a b a

            // matching starts at i=2
        }
        if (j == m) {
            cout << "Pattern found at index " << (i - j) << endl;
            j = lps[j - 1];
        }
        else if (i < n && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++; // move text forward
            }
        }
    }
    return 0;
}

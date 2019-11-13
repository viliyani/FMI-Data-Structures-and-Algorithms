#include <iostream>
using namespace std;

int main() {
    // Variables
    int n; // max length of two words
    string word1;
    string word2;
    int len1, len2; // lengths for word1 and word2
    int lettersCounter1[26] = {0}; // for word1
    int lettersCounter2[26] = {0}; // for word2
    char c; // helper
    bool flag = true; // final result

    // Input
    cin >> n;
    cin >> word1;
    cin >> word2;

    // Lengths
    len1 = word1.size();
    len2 = word2.size();

    // Check
    if (len1 != len2) {
        // Two words have different lengths => no way one to be permutation of other
        cout << "no";
        return 0;
    }

    // # We will use a "Counting Sort" algorithm

    // 1. Count letters in word1
    for (int i = 0; i < n; i++) {
        c = word1.at(i);
        if (c >= 'a' && c <= 'z') {
            lettersCounter1[c-'a']++;
        }
    }

    // 2. Count letters in word2
    for (int i = 0; i < n; i++) {
        c = word2.at(i);
        if (c >= 'a' && c <= 'z') {
            lettersCounter2[c-'a']++;
        }
    }

    // 3. Check if two words have equal letters
    for (int i = 0; i < 26; i++) {
        if (lettersCounter1[i] != lettersCounter2[i]) {
            flag = false;
            break;
        }
    }

    // 4. Print result
    if (flag) {
        cout << "yes";
    } else {
        cout << "no";
    }

    return 0;
}

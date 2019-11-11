#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string str;
    int len;
    int startFrom = 0;
    char lastChar;

    cin >> str;
    len = str.size();

    if (len == 1) {
        cout << "1" << str[0];
    } else {
        lastChar = str[0];
        int i;
        for (i = 1; i < len; i++)
        {
            if (str[i] != str[i-1]) {
                cout << (i-startFrom) << lastChar;
                startFrom = i;
                lastChar = str[i];
            }
        }
        cout << (i-startFrom) << lastChar;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

string s;

int main() {

    // 개행문자 띄어쓰기 까지 입력을 받아야함
    getline(cin, s);

    for (int i = 0; i < s.size(); i++) {
        
        if (s[i] >= 65 && s[i] <= 90) {
            // 대문자인 경우
            if (s[i] + 13 > 90)
                s[i] = s[i] + 13 - 26;
            else
                s[i] = s[i] + 13;
        } else if (s[i] >= 97 && s[i] <= 122) {
            // 소문자인 경우
            if (s[i] + 13 > 122)
                s[i] = s[i] + 13 - 26;
            else
                s[i] = s[i] + 13;
        }
        cout << s[i];
    }

    cout << "\na";
    return 0;
}
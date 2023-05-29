#include <bits/stdc++.h>
using namespace std;

string str;
int cnt[26]; // 전역변수 자동 0으로 초기화
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;
    for (char c : str) {
        cnt[c - 'a']++;
    }

    for (int i = 0; i < 26; i++)
        cout << cnt[i] << " ";

    return 0;
}
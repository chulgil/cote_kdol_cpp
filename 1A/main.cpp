#include <bits/stdc++.h>

using namespace std;

string name = "chulgil";

int main() {

    // 앞에서 부터 3개 출력
    cout << name.substr(0, 3) << '\n';

    // 거꾸로
    reverse(name.begin(), name.end());
    cout << name << '\n';

    // lee 추가하기
    cout << name + "lee" << '\n';
    return 0;
}
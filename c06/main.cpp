#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char W[MAX], H[MAX];
    cin.getline(W, MAX);
    cin.getline(H, MAX);

    cout << W << '\n';
    cout << H << '\n';

    int mx = strlen(W) + 1;
    vector<int> dp(mx, 0);

    for (int i = 1; i <= strlen(W); i++) {
        for (int j = 1; j <= strlen(H); j++) {
            if (W[i] == H[j]) {
                dp[i] = dp[i] + 1;
            } else {
                dp[i] = max(dp[i - 1], dp[i]);
            }
        }
    }

    cout << dp.back() << '\n';

    return 0;
}
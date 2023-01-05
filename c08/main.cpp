#include <bits/stdc++.h>
using namespace std;

int minInsertions(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    s += '#';
    s += rev;

    int n = s.size(), lps[n], p = 0;
    lps[0] = 0;
    int i = 1;

    while (i < n) {
        if (s[i] == s[p]) {
            p++;
            lps[i++] = p;
        } else {
            if (p == 0) {
                lps[i++] = 0;
            } else {
                p = lps[p - 1];
            }
        }
    }
    return n / 2 - lps[n - 1];
}

int minInsertions2(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }
    }

    return dp[0][n - 1];
}

int minInsertions3(string s) {
    int n = s.size();
    vector<int> dp(n, 0);

    int temp = 0;
    for (int i = n - 2; i >= 0; i--) {
        int pre = 0; // dp[i+1][i-1] 기록
        for (int j = i + 1; j < n; j++) {
            temp = dp[j];
            if (s[i] == s[j]) {
                // dp[i][j] = dp[i + 1][j - 1];
                dp[j] = pre;
            } else {
                // dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                dp[j] = min(dp[j], dp[j - 1]) + 1;
            }
        }
        pre = temp;
    }

    return dp[n - 1];
}

int main(void) {

    string s = "ACBABCADE";

    int res = minInsertions(s);

    cout << res << '\n';
}

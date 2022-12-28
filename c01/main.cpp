#include <algorithm>
#include <iostream>

#define X 5000
#define TRIVIAL 64

int main() {
    int n = 0;
    std::cin >> n;

    int max_arr = std::max(TRIVIAL, n + 1);

    int *dp{new int[max_arr]{0, X, X, 1, X, 1}};

    for (int i = 6; i <= n; i++) {
        dp[i] = std::min(dp[i - 3] + 1, dp[i - 5] + 1);
    }

    if (dp[n] >= X) {
        std::cout << -1;
        return 0;
    }

    std::cout << dp[n];

    return 0;
}
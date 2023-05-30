#include <bits/stdc++.h>
using namespace std;

// N : 2 ~ 100,000 (10만)
// K : 1 ~ 100,000 - 1
// O : -100 ~ 100
// 연속된 온도 O의 합이 최대가 되는 값
// 구간합 prefix sum , psum[i] = psum[i - 1] + a[i]
// 문제에서 최소값 구하라 : 최대값 부터 최소값을 구하라
// 문제에서 최대값 구하라 : 최소값 부터 최대값을 구하라
// ret = max(ret, value)
// ret = min(ret, value)
// 문제에서 최소값은 ? -100 * (10만번) = -1000만

int n, k, temp, psum[1000001], ret = -10000004;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> temp;
        psum[i] = psum[i - 1] + temp;
    }
    for (int i = k; i <= n; i++) {
        ret = max(ret, psum[i] - psum[i - k]);
    }

    cout << ret << "\n";
    return 0;
}
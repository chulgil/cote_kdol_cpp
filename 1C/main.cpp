#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {1, 2, 3};
    do {
        for (int i : a)
            cout << i << " ";
        cout << '\n';
    } while (next_permutation(&a[0], &a[0] + 3));

    int b[] = {1, 2, 3};
    do {
        for (int i : b)
            cout << i << " ";
        cout << '\n';
    } while (next_permutation(b, b + 3));

    vector<int> v = {1, 2, 3};
    do {
        for (int i : v)
            cout << i << " ";
        cout << '\n';
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}
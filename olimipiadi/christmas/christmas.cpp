/*
 * Dynamic Programming solution: f(i, S) represents the minimum total
 * money needed in order to spend at least S in the [i, N) subarray.
 */

#include <bits/stdc++.h>
using namespace std;

int N, B;
vector<int> v;
vector<unordered_map<int, int>> dp;

int f(int idx, int spent) {
    // return the minimum money spent that is >= B

    if (idx == N) {
        if (spent < B) {
            // invalid: can't spend less than B
            return numeric_limits<int>::max();
        } else {
            return spent;
        }
    }

    auto it = dp[idx].find(spent);
    if (it != dp[idx].end())
        return it->second;

    int result = min(
        f(idx + 1, spent + v[idx]),  // first case: take it
        f(idx + 1, spent)  // second case: don't take it
    );

    dp[idx][spent] = result;
    return result;
}

int main() {
    cin >> N >> B;
    v.resize(N);
    dp.resize(N);

    int sum = 0;
    for (int i=0; i<N; i++) {
        cin >> v[i];
        sum += v[i];
    }

    if (sum >= B)
        cout << f(0, 0) << endl;
    else
        cout << sum << endl;
}

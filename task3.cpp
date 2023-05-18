#include <iostream>
#include <vector>

using namespace std;

int countWaysToTile(int n) {
    vector<int> dp(n + 1);

    // Базові випадки
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
    }

    return dp[n];
}

int main() {
    vector<int> values;
    int n;

    while (true) {
        cin >> n;
        if (n == -1)
            break;

        values.push_back(n);
    }

    for (int n : values) {
        int ways = countWaysToTile(n);
        cout << ways << endl;
    }

    return 0;
}

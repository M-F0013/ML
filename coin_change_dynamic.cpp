#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main() {
    int n, amount;
    cout << "Enter number of coin types: ";
    cin >> n;
    vector<int> coins(n);   
    cout << "Enter coin denominations:\n";
    for(int i = 0; i < n; i++)
        cin >> coins[i];
    cout << "Enter amount: ";
    cin >> amount;
    vector<int> dp(amount + 1, INT_MAX);   
    dp[0] = 0;
    for(int i = 1; i <= amount; i++) {
        for(int j = 0; j < n; j++) {
            if(coins[j] <= i && dp[i - coins[j]] != INT_MAX)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }
    cout << "Minimum coins required: " << dp[amount];
    return 0;
}
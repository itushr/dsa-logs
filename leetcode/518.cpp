class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);

        for(int coin: coins) {
            if(coin <= amount) {
                dp[coin] = 1;
            }
        }

        for(int i=1; i<=amount; i++) {
            for(int coin: coins) {
                if(i <= coin) continue;
                dp[i] += dp[i-coin];
                for(int coinx: coins) {
                    if(i-coin == coinx && i-coin < coin) {
                        dp[i] -= dp[i-coin];
                    }
                }
            }
        }

        return dp[amount];
    }
};
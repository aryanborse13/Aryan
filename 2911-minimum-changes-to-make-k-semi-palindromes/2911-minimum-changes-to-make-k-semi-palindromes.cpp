#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        
        // 1. Precompute all proper divisors for every possible substring length
        vector<vector<int>> divisors(n + 1);
        for (int len = 2; len <= n; ++len) {
            for (int d = 1; d * 2 <= len; ++d) {
                if (len % d == 0) {
                    divisors[len].push_back(d);
                }
            }
        }

        // 2. Precompute cost[i][j]: min changes to make s[i..j] a semi-palindrome
        const int INF = 1e9;
        vector<vector<int>> cost(n, vector<int>(n, INF));
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                int min_changes = INF;
                
                for (int d : divisors[len]) {
                    int changes = 0;
                    int group_size = len / d;
                    
                    // Check each modulo group r (from 0 to d - 1)
                    for (int r = 0; r < d; ++r) {
                        int left = i + r;
                        int right = i + r + (group_size - 1) * d;
                        while (left < right) {
                            if (s[left] != s[right]) {
                                ++changes;
                            }
                            left += d;
                            right -= d;
                        }
                    }
                    min_changes = min(min_changes, changes);
                }
                cost[i][j] = min_changes;
            }
        }

        // 3. DP to partition prefix s[0..i-1] into j semi-palindromes
        // dp[i][j] = min changes for first i characters using j partitions
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;

        for (int j = 1; j <= k; ++j) {
            // Each semi-palindrome has length >= 2, so j parts need at least 2*j chars
            for (int i = 2 * j; i <= n; ++i) {
                // Previous partition ends at p (needs at least 2*(j-1) chars)
                for (int p = 2 * (j - 1); p <= i - 2; ++p) {
                    if (dp[p][j - 1] != INF) {
                        dp[i][j] = min(dp[i][j], dp[p][j - 1] + cost[p][i - 1]);
                    }
                }
            }
        }

        return dp[n][k];
    }
};
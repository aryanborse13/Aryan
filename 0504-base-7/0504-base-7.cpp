class Solution {
public:
    string convertToBase7(int num) {
        int ans = 0;
        int mul = 1;
        while (num != 0) {
            int rem = num % 7;
            ans = rem * mul + ans;
            num /= 7;
            mul *= 10;
        }
        string str = to_string(ans);
        return str;
    }
};
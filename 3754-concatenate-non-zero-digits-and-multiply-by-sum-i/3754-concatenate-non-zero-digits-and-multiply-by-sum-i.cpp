class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0){
            return 0;
        }
        string digits = "";
        long long dig_sum = 0;
        string s = to_string(n);
        for(char c: s){
            if(c!= '0'){
                digits += c;
                dig_sum += (c-'0');
            }
        }
        if (digits.empty()) {
            return 0;
        }
        long long x = stoll(digits);
        return x * dig_sum;
    }
};
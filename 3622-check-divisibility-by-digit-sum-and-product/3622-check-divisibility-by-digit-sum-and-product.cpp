class Solution {
public:
    bool checkDivisibility(int n) {
       int  digSum = 0;
       int digMu = 1;
       int num = n;
        while(n){
             digSum += n%10;
             digMu *= n%10;
             n /=10;
        }
        int sum = digSum + digMu;
        if(sum==0) return false;
        return num%sum == 0;
    }
};
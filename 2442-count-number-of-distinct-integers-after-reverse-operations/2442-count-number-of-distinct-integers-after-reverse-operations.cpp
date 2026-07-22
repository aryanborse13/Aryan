class Solution {
public:
    int reverse(int num){
        int r = 0;
        while(num>0){
            r *= 10;
            r += (num%10);
            num /= 10;
        }
        return r;
    }
    
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int rev = reverse(nums[i]);
            s.insert(nums[i]);
            s.insert(rev);
        }
        return s.size();
    }
};
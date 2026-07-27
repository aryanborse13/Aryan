class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
            int pro = (nums[i]-1)*(nums[j]-1);
            ans.push_back(pro);
            }
        }
        sort(ans.begin(),ans.end());
        int sz = ans.size();
        return ans[sz-1];
    }
};
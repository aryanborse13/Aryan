class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;
        int mid = 0; // 1. Declared here so it's accessible everywhere below

        while (st <= end) {
            mid = st + (end - st) / 2; // 2. Calculate mid inside the loop

            if (nums[mid] == target) {
                return mid; 
            } else if (nums[mid] < target) {
                st = mid + 1; // Look right
            } else {
                end = mid - 1; // Look left
            }
        } // <-- The while loop should close HERE, after the logic

        // 3. Now 'mid' is perfectly valid here!
        return (target > nums[mid]) ? mid + 1 : mid;
    }
};
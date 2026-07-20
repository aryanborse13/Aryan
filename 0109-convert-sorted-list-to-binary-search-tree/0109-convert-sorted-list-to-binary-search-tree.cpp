
class Solution {
public:
    TreeNode* buildBst(vector<int> nums, int left, int right){
        if(left >right){
            return NULL;
        }

        int mid = left + (right-left)/2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = buildBst(nums,left,mid-1);
        root->right = buildBst(nums,mid+1,right);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head = head->next;
        }
        return buildBst(nums,0,nums.size()-1);
    }
};
class Solution {
public:
 TreeNode* first = NULL;
 void makeParent(TreeNode* root,unordered_map<TreeNode*, TreeNode*>& parent){
        if(root == NULL) return;
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;
        makeParent(root->left,parent);
        makeParent(root->right,parent);
    }
      void find(TreeNode* root, int start){
        if(root == NULL) return ;
        if(root->val == start) {
            first = root;
            return;
        }
        find(root->left,start);
        find(root->right,start);
    }

    int amountOfTime(TreeNode* root, int start) {
        find(root, start);
        unordered_map<TreeNode*, TreeNode*> parent;
        makeParent(root, parent);
        unordered_set<TreeNode*> s;
        s.insert(first);
        queue<pair<TreeNode*,int>> q;
        q.push({first,0});
        int maxLevel = 0;
        //bfs
        while(q.size()>0){
            pair<TreeNode*,int> p = q.front();
            q.pop();
            int level = p.second;
            maxLevel = max(maxLevel,level);
            TreeNode* temp = p.first;
            if(temp->left){//check weather the left,right, and parent of node exist
                 if(s.find(temp->left) == s.end()){
                    q.push({temp->left,level+1});//push Node and increase level
                    s.insert(temp->left);//the node is infected
                 }
            }
            if(temp->right){//check weather the left,right, and parent of node exist
                 if(s.find(temp->right) == s.end()){
                    q.push({temp->right,level+1});//push Node and increase level
                    s.insert(temp->right);//the node is infected
                 }
            }
            if(parent.find(temp) != parent.end()){
                if(s.find(parent[temp])== s.end()){
                    q.push({parent[temp],level+1});
                    s.insert(parent[temp]);
                }
            }
        }
        return maxLevel;
    }
};
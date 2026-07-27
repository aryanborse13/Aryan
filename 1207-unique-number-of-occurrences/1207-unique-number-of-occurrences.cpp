class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       vector<int> ans;
       int n = arr.size();
       sort(arr.begin(),arr.end());
       int i=0;
       while(i<n){
        int count = 1;
        while(i+1<n && arr[i]==arr[i+1]){
            count++;
            i++;
        }
        ans.push_back(count);
        i++;
       }
        sort(ans.begin(),ans.end());
        for(int j=0;j<ans.size()-1;j++){
            if(ans[j]==ans[j+1]){
                return false;
            }
         }
       return true;
    }
};
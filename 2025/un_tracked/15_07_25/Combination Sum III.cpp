class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        backtracking(ans,k,n,1,temp);
        return ans;
    }

    void backtracking(vector<vector<int>>& ans,int k , int n , int index,vector<int>&temp){
        if(n == 0 && temp.size() == k){
            ans.push_back(temp);
            return;
        }
        if(n < 0 || temp.size() > k ){
            return;
        }

        for(int i = index; i < 10 ; i++){
            temp.push_back(i);
            backtracking(ans,k,n-i,i + 1,temp);
            temp.pop_back();
        }
    }
};
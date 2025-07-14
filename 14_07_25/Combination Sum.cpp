class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>combination;
        backtracking(result,combination,candidates,target,0);
        return result;
    }

    void backtracking(vector<vector<int>>&result,vector<int>&combination,vector<int>& candidates, int target,int index){
        if(target == 0){
            result.push_back(combination);
            return;
        }

        for(int i = index;i<candidates.size();i++){
            if(candidates[i] > target) continue;

            combination.push_back(candidates[i]);
            backtracking(result,combination,candidates,target - candidates[i],i);
            combination.pop_back();
        }
    }
};
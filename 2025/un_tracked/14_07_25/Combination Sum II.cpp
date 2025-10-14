class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        vector<vector<int>>result;
        vector<int>combination;
        backtracking(result,combination,candidates,target,0);
        return result;
    }

    void backtracking(vector<vector<int>>&result,vector<int>&combination,vector<int>&candidates,int target,int index){
        if(target == 0){
            result.push_back(combination);
            return;
        }
        for(int i = index;i<candidates.size();i++){
            if(i > index && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] > target) break;
            combination.push_back(candidates[i]);
            backtracking(result,combination,candidates,target - candidates[i],i+1);
            combination.pop_back();
        }
    }
};
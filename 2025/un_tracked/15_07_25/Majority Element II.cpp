class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        vector<int>ans;
        sort(arr.begin(),arr.end());
        int count = 1;
        int min_votes = arr.size()/3;
        for(int i = 1 ; i< arr.size() ; i++){
            if( arr[i] == arr[i-1]){
                count++;
            }
            else{
                if(count > min_votes){
                    ans.push_back(arr[i - 1]);
                }
                count=1;
            }
        }
        
        if(count > min_votes){
            ans.push_back(arr[arr.size()-1]);
        }
        
        return ans;
    }
};
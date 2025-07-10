class Solution {
  public:
    string longestString(vector<string> &words) {
        // code here
        sort(words.begin(),words.end());
        string ans = "";
        unordered_set<string>WordSet(words.begin(),words.end());
        
        for(const string& word : words){
            bool valid = true;
            
            for(int i =1;i<word.length();i++){
                if(WordSet.find(word.substr(0,i)) == WordSet.end()){
                    valid  = false;
                    break;
                }
            }
            
            if (valid) {
                if (word.length() > ans.length()) {
                    ans = word;
                }
            }
        }
        return ans;
    }
};
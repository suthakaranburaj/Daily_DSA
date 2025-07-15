class Solution {
  public:
    bool divby13(string &s) {
        // code here
        long long num = 0;
        for(char c : s){
            num = (num * 10 + (c-'0'))%13;
        }
        
        return num == 0;
    }
};
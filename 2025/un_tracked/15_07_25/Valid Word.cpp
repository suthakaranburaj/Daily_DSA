class Solution {
public:
    bool isValid(string word) {
        int n = word.length();
        if(n < 3){
            return false;
        }
        bool contains_vowel = false;
        bool contains_consonant = false;

        for( char c : word){
            //1
            //if c is a special character then return false
            if(!isalnum(c)){
                return false;
            }
            //2
            //if c is a digit then continue
            if(isdigit(c)){
                continue;
            }
            char lower_c = tolower(c);
            //3 check is_vowel with the function created if is_vowel is true then contains_vowel will become true
            if(!contains_consonant || !contains_vowel){
                if(check_is_vowel(lower_c)){
                    contains_vowel = true;
                }
                else{
                    contains_consonant = true;
                }
            }
            //4 if is vowel is false then contains_consonant will be true;
        }
        return contains_consonant && contains_vowel;

    }
    bool check_is_vowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
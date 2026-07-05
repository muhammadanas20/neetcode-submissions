class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        
        
        for (char raw_c : s) {
            char c = tolower(raw_c);
            if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
                str += c;
            }
        }
        
        int left = 0;
        int n = str.length();
        int right = n - 1; 
        
        while(left < right){
            if(str[left] != str[right]){
                return false;
            }
            left++;
            right--; 
        }
        return true;
    }
};
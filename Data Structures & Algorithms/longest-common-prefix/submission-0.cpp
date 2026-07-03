class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix = "";
        int n = strs.size();
        int j = 0;
        for(auto str : strs[0]){
            char c = str;
            int flag = 1;
            for(int i=1;i<n;i++){
                if(j >= strs[i].size() || c != strs[i][j]){
                    flag = 0;
                }
            }
            if(flag){
                prefix += c;
                j++;
            }
            else{
                return prefix;
            }

        }
        return prefix;
    }
};
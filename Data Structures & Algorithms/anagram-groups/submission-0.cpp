class Solution {
    private:
     bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        std::sort(s.begin(),s.end());
        std::sort(t.begin(),t.end());

        return s == t;
    }
    public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> group;
        vector<bool> visited(n, false); // Tracks already grouped words
        
        for(int i=0;i<n;i++){
            if(visited[i]) continue;

            vector<string> current_row; // Create a fresh row
            current_row.push_back(strs[i]);
            visited[i] = true;
             for(int j = i + 1; j < n; j++) {
                if(!visited[j] && isAnagram(strs[i], strs[j])) {
                    current_row.push_back(strs[j]);
                    visited[j] = true; // Mark as grouped
                }
            }
            group.push_back(current_row);
        }
        return group;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 1. Insert all elements into a hash set for O(1) lookups
        unordered_set<int> count;
        for(int num: nums){
            count.insert(num); // FIX: unordered_set uses .insert(), not .push_back()
        }
        
        int longestSequence = 0;
        
        // 2. Scan the set to find the start of sequences
        for(int i : count){
            // Check if 'i' is the start of a sequence (i.e., 'i - 1' doesn't exist)
            if(count.find(i - 1) == count.end()) {
                int currentNum = i;
                int currentStreak = 1;
                
                // Count upward as long as the next consecutive numbers exist
                while(count.find(currentNum + 1) != count.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }
                
                // Keep track of the maximum length found so far
                longestSequence = max(longestSequence, currentStreak);
            }
        }
        
        return longestSequence;
    }
};
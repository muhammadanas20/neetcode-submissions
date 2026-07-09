class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        
        for (int num : nums) {
            // Step 1: Assign a new candidate if the counter hits zero
            if (count == 0) {
                candidate = num;
            }
            
            // Step 2: Add 1 for matching votes, subtract 1 for opposing votes
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        return candidate;
    }
};
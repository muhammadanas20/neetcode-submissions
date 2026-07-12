class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        for(int left = 0;left<=nums.size()-k;left++){
            int maximum = nums[left];
            for(int i = left;i<left+k;i++){
                maximum = max(maximum,nums[i]);
            }
            res.push_back(maximum);
        }
        return res;
    }
};

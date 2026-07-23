class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //buble sort
       int n = nums.size();
        for(int i=0;i<n-1;i++){
            int flag = 0;
            for(int j=0;j<n-i-1;j++){
                if(nums[j] > nums [j+1]){
                    swap(nums[j+1],nums[j]);
                    flag = 1;
                }
            }
            if(!flag) break;
        }
        return nums;
    }
};
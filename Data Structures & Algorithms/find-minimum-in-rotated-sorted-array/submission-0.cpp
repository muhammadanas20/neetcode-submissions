class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() -1;

        int res = nums[0];
        while( l <= r){
            if(nums[l] < nums[r]){
                //we found sorted sub array 
                //update if result is less than most left od sorted sub array
                res = min(res,nums[l]);
                break;
            }
            int mid = l + (r-l)/2;
            res = min(res,nums[mid]);
            //if mid is greater than left than move left to mid+1
            if(nums[mid] >= nums[l]){
                 l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return res;
    }
};

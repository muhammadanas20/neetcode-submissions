class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
          // Find the pivot point where the rotation happens
        int mid = 0; 
        for (int i = 0; i < (int)nums.size() - 1; i++) { 
            if (nums[i] > nums[i + 1]) { 
                mid = i; 
                break; 
            } 
        } 
        int idx = binarysearch(nums,target,0,mid);

        if( idx == -1){
            idx = binarysearch(nums,target,mid+1,nums.size()-1);
        }
        return idx;
    }
    int binarysearch(vector<int>& vec,int target,int l,int r){
        while(l <= r){
            int m = l + (r-l)/2;

            if(vec[m] == target){
                return m;
            }
            else if(vec[m] > target){
                r = m-1;   
            }
            else{
                l = m+1;
            }
        }
        return -1;
    }
};

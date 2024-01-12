class Solution {
public:
   int firstOcc(vector<int>& nums, int target){
        int l=0;
        int h= nums.size()-1;
        int ans =-1;
        
        while(l <= h){
            int mid = (l+h)/2;
            
            if(nums[mid] == target){
                ans = mid;
                h = mid-1;
            }else if(nums[mid]<target){
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        return ans;
    }
     int lastOcc(vector<int>& nums, int target){
        int l=0;
        int h= nums.size()-1;
        int ans =-1;
        
        while(l <= h){
            int mid = (l+h)/2;
            
            if(nums[mid] == target){
                ans = mid;
                l = mid+1;
            }else if(nums[mid]<target){
                l = mid+1;
            }else{
                h = mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
         vector<int>ans;
         ans.push_back(firstOcc(nums,target));
         ans.push_back(lastOcc(nums,target));
         return ans;

    }
};

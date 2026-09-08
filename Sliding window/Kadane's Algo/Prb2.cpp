53. Maximum Subarray

Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

CODE:
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN , sum=0;
        if(nums.size()==1) return nums[0];
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>maxi){
               maxi=max(maxi,sum);
            }
            if(sum<0){
               sum=0;
             }
        }
        return maxi;
    }
};

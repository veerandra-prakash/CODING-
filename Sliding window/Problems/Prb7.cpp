2461. Maximum Sum of Distinct Subarrays With Length K

You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.


Example 1:

Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions


CODE:

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum=0,maxSum=0;
        int left=0;
        unordered_map<int,int>mp;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            mp[nums[right]]++;
            while((right-left+1)>k){
                sum-=nums[left];
                mp[nums[left]]--;
                if(mp[nums[left]]==0){
                    mp.erase(nums[left]);
                }
                left++;
            }
            if(mp.size()==k){
                maxSum=max(maxSum,sum);
            }
        }
        return maxSum;
    }
};
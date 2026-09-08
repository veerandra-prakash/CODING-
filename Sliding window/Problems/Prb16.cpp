2799. Count Complete Subarrays in an Array


You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.

 

Example 1:

Input: nums = [1,3,1,2,2]
Output: 4
Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
Example 2:

Input: nums = [5,5,5,5]
Output: 10
Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.


CODE:
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
           unordered_map<int,int>mp1,mp2; int finalC=0;
           int left=0;
           for(int n : nums){
               mp1[n]++;
           }
           for(int right=0; right<nums.size();right++){
              mp2[nums[right]]++;
              while(mp1.size()==mp2.size()){
                  finalC+=nums.size()-right;
                  mp2[nums[left]]--;
                  if(mp2[nums[left]]==0){
                    mp2.erase(nums[left]);
                  }
                  left++;
              }
           }   
        return finalC;
    }
};
 
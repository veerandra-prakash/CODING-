643. Maximum Average Subarray I


You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75
Example 2:

Input: nums = [5], k = 1
Output: 5.00000

CODE:

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double final_ans = -999999;
        int left=0 ; double sum=0.0;
        for(int right=0;right<nums.size();right++){
            sum+=nums[right];
            if((right-left+1)==k){
                double avg = sum/k;
                final_ans= max(final_ans,avg);
                sum-=nums[left];
                left++;
            }
        }   
        return final_ans;
    }
};
485. Max Consecutive Ones

Given a binary array nums, return the maximum number of consecutive 1's in the array.


Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.



CODE:
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int final_len=INT_MIN,left=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt++;
            }else{
                cnt=0;
            }
            final_len=max(final_len,cnt);
        }
        return final_len;
    }
};
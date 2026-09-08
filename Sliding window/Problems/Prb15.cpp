1248. Count Number of Nice Subarrays


Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.

CODE:
class Solution {
public:
    int atmost(vector<int>&nums,int k){
         int count=0,left=0,ans=0;
        for(int right=0;right<nums.size();right++){
            if(nums[right]%2!=0){
                count++;
            }
            while(count>k){
                if(nums[left]%2!=0){
                    count--;
                }
                left++;
            }
            ans+=right-left+1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
         return atmost(nums,k)-atmost(nums,k-1);
    }
};

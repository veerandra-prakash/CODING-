525. Contiguous Array

Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 

Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.

CODE:
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       int maxLength=0,prefixSum=0;
       unordered_map<int,int>freq;
       freq[0]=-1;
       for(int i=0;i<nums.size();i++){
           if(nums[i]==0){
                prefixSum-=1;
           }else{
                prefixSum+=1;
           }
           if(freq.find(prefixSum)!=freq.end()){
                maxLength=max(maxLength,i-freq[prefixSum]);
           }else{
              freq[prefixSum]=i;
           }
       }
       return maxLength;
    }
};

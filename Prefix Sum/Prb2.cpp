930. Binary Subarrays With Sum

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]


CODE:

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        int count=0,sum=0;
        mp[0]=1;
        for(int i : nums){
            sum+=i;
            if(mp.find(sum-goal)!=mp.end()){
                count+=mp[sum-goal];
            }
            mp[sum]++;
        }
        return count;
    }
};
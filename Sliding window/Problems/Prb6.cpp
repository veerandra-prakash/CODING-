2537. Count the Number of Good Subarrays


Given an integer array nums and an integer k, return the number of good subarrays of nums.

A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].

A subarray is a contiguous non-empty sequence of elements within an array.


Example 1:

Input: nums = [1,1,1,1,1], k = 10
Output: 1
Explanation: The only good subarray is the array nums itself.



CODE:
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long final_count = 0;
        long long left = 0;
        long long cnt = 0;

        unordered_map<int, int> freq;

        for (int right = 0; right < nums.size(); right++) {

            // Add nums[right]
            freq[nums[right]]++;
            cnt += freq[nums[right]] - 1;

            // Shrink while we have at least k pairs
            while (cnt >= k) {

                freq[nums[left]]--;
                cnt -= freq[nums[left]];

                left++;
            }

            // Number of good subarrays ending at right
            final_count += left;
        }

        return final_count;
    }
};

 
3. Longest Substring Without Repeating Characters


Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

CODE:
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int left=0;
        unordered_map<char,int>freq;
        for(int right=0;right<s.size();right++){
             freq[s[right]]++;
             while(freq[s[right]] > 1){
                freq[s[left]]--;
                left++;
             }
             maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};

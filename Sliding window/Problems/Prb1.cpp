Leetcode - 424 
Longest Repeating Character Replacement

You are given a string s and an integer k.

You can choose any character in the string and replace it with any other uppercase English character. You can perform this replacement at most k times.

Return the length of the longest substring containing the same letter after performing at most k replacements.



CODE:

class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char, int> freq;

        int left = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            // Add current character
            freq[s[right]]++;

            // Update maximum frequency
            maxFreq = max(maxFreq, freq[s[right]]);

            // Invalid window
            while ((right - left + 1) - maxFreq > k) {

                // Remove left character
                freq[s[left]]--;

                // Remove character completely if frequency becomes 0
                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }

                left++;
            }

            // Valid window
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
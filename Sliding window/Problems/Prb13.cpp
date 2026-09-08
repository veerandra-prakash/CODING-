3090. Maximum Length Substring With Two Occurrences

Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
 

Example 1:

Input: s = "bcbbbcba"

Output: 4

Explanation:

The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
Example 2:

Input: s = "aaaa"

Output: 2

Explanation:

The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa"



CODE:

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int final_len=INT_MIN;
        int left=0;
        unordered_map<char,int>mp;
        for(int right=0;right<s.size();right++){
             mp[s[right]]++;
             while(mp[s[right]]>2){
                mp[s[left]]--;
                left++;
             }
             final_len=max(final_len,right-left+1);
        }
        return final_len;
    }

};
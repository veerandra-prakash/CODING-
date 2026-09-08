1358. Number of Substrings Containing All Three Characters


Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).

CODE:

class Solution {
public:
    int numberOfSubstrings(string s) {
        int final_count=0,left=0;
        unordered_map<char,int>mp;
        for(int right=0;right<s.size();right++){
            mp[s[right]]++;
            while(mp.size()==3){
                mp[s[left]]--;
                if(mp[s[left]]==0){
                    mp.erase(s[left]);
                }
                left++;
            }
            final_count+=left;
        }
        return final_count;
    }
};      
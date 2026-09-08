Pattern A — Find maximum/longest valid window

Example:

Longest substring with at most K distinct characters.

Logic:

Expand
↓
Add element
↓
If invalid
↓
Shrink
↓
Update maximum

Template:

int left = 0;
int ans = 0;

for (int right = 0; right < n; right++) {

    // add nums[right]

    while (window_is_invalid) {

        // remove nums[left]
        left++;
    }

    ans = max(ans, right - left + 1);
}

Mental model

Make the window valid, then maximize it.



9. Pattern B — Find minimum/shortest valid window

Example:

Minimum length subarray with sum ≥ target.

Logic:

Expand
↓
Become valid
↓
Shrink as much as possible
↓
Record minimum

Template:

int left = 0;
int ans = INT_MAX;

for (int right = 0; right < n; right++) {

    // add element

    while (window_is_valid) {

        ans = min(ans, right - left + 1);

        // remove left
        left++;
    }
}


Mental model

Make the window valid, then make it as small as possible.



10. Pattern C — Count valid windows

Sometimes the question isn't:

"What's the longest?"

or

"What's the shortest?"

Instead:

"How many subarrays/substrings satisfy the condition?"

Example:

Count subarrays with at most K distinct elements.

The logic becomes:

for (int right = 0; right < n; right++) {

    // expand

    while (invalid) {
        // shrink
    }

    ans += right - left + 1;
}

Why?

Suppose:

left = 2
right = 5

Then valid windows ending at right are:

[2...5]
[3...5]
[4...5]
[5...5]

That's:

right - left + 1
= 5 - 2 + 1
= 4

This is a very important advanced sliding-window trick.



Pattern D:

Exactly(k) =  atmost(k) - atmost(k-1);
This is the formula to calculate the exactly(k) of the problems 

Explanation:
 k=2
 atmost(k) = atmost(2) = 0,1,2
 atmost(k-1)= atmost(1) = 0,1
 
 The common values got canceled , then only the 2 remains
 SO,
   Proved



Pattern E:
Longest substring with the distinct character exactly k


Code:

class Solution {
public:
    int longestKSubstr(string &s, int k) {

        int left = 0;
        int res_len = -1;

        unordered_map<char, int> freq;

        for (int right = 0; right < s.size(); right++) {

            freq[s[right]]++;

            while (freq.size() > k) {

                freq[s[left]]--;

                if (freq[s[left]] == 0) {
                    freq.erase(s[left]);
                }

                left++;
            }

            if (freq.size() == k) {
                res_len = max(res_len, right - left + 1);
            }
        }

        return res_len;
    }
};
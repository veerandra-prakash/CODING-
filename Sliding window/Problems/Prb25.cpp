904. Fruit Into Baskets



You have trees in a line:

fruits = [1, 2, 1, 2, 3, 2, 2]
          ↑  ↑  ↑  ↑  ↑

Each number represents a fruit type.

For example:

1 = Apple
2 = Orange
3 = Banana

You have only 2 baskets.

🧺 What does each basket mean?

Each basket can contain only ONE type of fruit.

So you can have:

Basket 1 → Apples
Basket 2 → Oranges

That's perfectly fine.

And you can put unlimited amounts:

Basket 1 → 1, 1, 1, 1, 1
Basket 2 → 2, 2, 2, 2

But you cannot have:

Basket 1 → Apples + Bananas ❌

because one basket can hold only one type.

🚶 What are you actually looking for?

You choose some starting tree, then move only to the right.

You must take one fruit from every tree you pass.

You stop when you encounter a third fruit type.

So essentially:

Find the longest continuous subarray containing at most 2 different numbers.

That's the entire problem. 🔥

Example
fruits = [1, 2, 1, 2, 3]

Let's start from index 0:

1 → 2 → 1 → 2

We have:

1 type → 1
2 type → 2

Only 2 types, so this is valid.

Length:

4

Then we reach:

3

Now we have:

1
2
3

That's 3 different types.

We only have 2 baskets ❌

So we must stop before 3.

Therefore:

Answer = 4
🔥 Another example
fruits = [1, 2, 3, 2, 2]

Possible windows:

[1, 2]          → 2 types ✅

[2, 3, 2, 2]    → 2 types ✅

The second one has length:

4

So:

Answer = 4





Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].




CODE:
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int final_cnt=0,left=0;
        unordered_map<int,int>freq;
        for(int right=0;right<fruits.size();right++){
            freq[fruits[right]]++;
            while(freq.size()>2){
                freq[fruits[left]]--;
                if(freq[fruits[left]]==0){
                    freq.erase(fruits[left]);
                }
                left++;
            }
            final_cnt=max(final_cnt,right-left+1);
        }
        return final_cnt;
    }
};
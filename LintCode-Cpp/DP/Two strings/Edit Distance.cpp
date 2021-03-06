/* 
119. Edit Distance

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example
Example 1:

Input: 
"horse"
"ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: 
"intention"
"execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/
class Solution {
public:
    /**
     * @param word1: A string
     * @param word2: A string
     * @return: The minimum number of steps.
     */
    int minDistance(string &word1, string &word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        
        for(int i = 0; i <= word1.size(); i++)
        {
            dp[i][0] = i;
        }
        
        for(int i = 0; i <= word2.size(); i++)
        {
            dp[0][i] = i;
        }        
        
        for(int i = 1; i <= word1.size(); i++)
        {
            for(int j = 1; j <= word2.size(); j++)
            {

                dp[i][j] = min(dp[i][j-1], dp[i-1][j]);
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]) + 1;
                
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];

            }
        }
        
        return dp[word1.size()][word2.size()];
    }
};
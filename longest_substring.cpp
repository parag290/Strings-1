/**
 * 
 * Leetcode : https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 * 
*/

/**
 * Explaination : Window method is used
 * Also, hash set is used to store the current substring characters.
 * 
 * Time complexity : O(n)
 * Space complexity : O(1) .... maximum 26 letters will be stored in the hash set
 * 
*/



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int start = 0;
        int end = 0;
        set<char>hSet;

        while(end != s.size()){
            char ch = s[end];
            if(hSet.find(ch) == hSet.end()){
                hSet.insert(ch);
            } else {
                if(s[start] == s[end]){
                    start++;
                } else {
                    while(s[start] != ch){
                        char toRemove = s[start];
                        hSet.erase(toRemove);
                        start++;
                    }
                    start++;
                }
            }
            if(end - start + 1 > maxLen){
                maxLen = end-start+1;
            }
            end++;
        }

        return maxLen;
        
    }
};
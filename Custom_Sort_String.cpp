/**
 * 
 * Leetcode : https://leetcode.com/problems/custom-sort-string/description/
 * 
 * 
 * Video : https://www.youtube.com/watch?v=K59pm_uux1w
*/


/**
 * Explaination : 
 * 
 * store the frequency map for each character.
 * then add characters first from order string and remove them from hashMap once added to result.
 * Then add remaining character one by one.
 * 
 * Time Complexity : O(n)
 * Space complexity : O(1) .... hash map will have maximum 26 keys.
 * 
*/

class Solution {
public:
    string customSortString(string order, string s) {
        
        string result = "";
        unordered_map<char, int>hMap;
        for(auto ch : s){
            if(hMap.find(ch) == hMap.end()){
                hMap[ch] = 1;
            } else {
                hMap[ch]++;
            }
        }

        for(auto ch : order){
            int count = hMap[ch];
            while(count){
                result += ch;
                count--;
            }
            hMap.erase(ch);
        }

        for(auto &pair : hMap){
            int count = pair.second;
            int ch = pair.first;

            while(count){
                result += ch;
                count--;
            }
        }
        return result;
    }
};


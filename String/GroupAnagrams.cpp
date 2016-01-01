class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> map;
        for(string s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            map[temp].insert(s);
        }
        vector<vector<string>> vec;
        for(auto it = map.begin(); it != map.end(); it++) {
            vector<string> anagram(it->second.begin(), it->second.end());
            vec.push_back(anagram);
        }
        return vec;
    }
};

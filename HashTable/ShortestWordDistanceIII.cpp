class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        unordered_map<string, vector<int>>wordMap;
        for(int i = 0; i < words.size(); i++) {
            wordMap[words[i]].push_back(i);
        }
        int dis = INT_MAX;
        if(word1.compare(word2)) {
            int i = 0;
            int j = 0;
            while(i != wordMap[word1].size() && j != wordMap[word2].size()) {
                int temp = abs(wordMap[word1][i] - wordMap[word2][j]);
                if(temp < dis) {
                    dis = temp;
                }
                if (wordMap[word1][i] < wordMap[word2][j]) {
                    i++;
                }
                else {
                    j++;
                }
            }
        }
        else {
            if(wordMap[word1].size() == 1) {
                dis = 0;
            }
            else {
                for(int i = 0; i + 1 < wordMap[word1].size(); i++) {
                    int temp = abs(wordMap[word1][i] - wordMap[word1][i+1]);
                    if(temp < dis) {
                        dis = temp;
                    }
                }
            }
        }
        return dis;
    }
};

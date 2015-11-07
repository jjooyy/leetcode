class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int s = words.size();
        int pos1 = -1;
        int pos2 = -1;
        int dis = INT_MAX;
        for(int i=0; i<s; i++) {
            if(!word1.compare(words[i])) {
                pos1 = i;
                if(pos2!=-1) {
                    int t = abs(pos1 - pos2);
                    if(t<dis) {
                        dis = t;
                    }
                }
            }
            else if(!word2.compare(words[i])) {
                pos2 = i;
                if(pos1!=-1) {
                    int t = abs(pos1 - pos2);
                    if(t<dis) {
                            dis = t;
                    }
                }
            }
        }
        return dis;
    }
};

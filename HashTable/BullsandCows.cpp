class Solution {
public:
    string getHint(string secret, string guess) {
        string res;
        int acnt = 0, bcnt = 0;
        vector<int> snum(10, 0);
        vector<int> gnum(10, 0);
        for(int i = 0; i < secret.size(); i++) {
            if(secret[i] == guess[i]) {
                acnt++;
            }
        }
        for(int i = 0; i < secret.size(); i++) {
            snum[secret[i] - '0']++;
            gnum[guess[i] - '0']++;
        }
        for(int i = 0; i < 10; i++) {
            bcnt += min(snum[i], gnum[i]);
        }
        bcnt -= acnt;
        res = to_string(acnt) + 'A' + to_string(bcnt) + 'B';
        return res;
    }
};

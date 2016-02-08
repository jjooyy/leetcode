using namespace std;

class Solution {
    vector<int> strobo{0, 1, -1, -1, -1, -1, 9, -1, 8, 6};
public:
    bool isStrobogrammatic(string num) {
        if(!num.size()) {
            return false;
        }
        string rev;
        for(int i = num.size() - 1; i >= 0; i--) {
            if(strobo[num[i] - '0'] == -1) {
                return false;
            }
            rev.push_back(strobo[num[i] - '0'] + '0');
        }
        if(rev.compare(num) != 0) {
            return false;
        }
        else 
            return true;
    }
};

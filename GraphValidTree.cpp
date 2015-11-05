class Solution {
public:
    int findPath(vector<int>& p, int num) {
        if(p[num]!=-1) {
            return findPath(p, p[num]);
        }
        else
            return num;
    }
    bool validTree(int n, vector<pair<int, int>>& edges) {
        int size = edges.size();
        if(n==1&&size==0) {
            return true;
        }
        if(size<n-1) {
            return false;
        }
        vector<int>p(n, -1);
        for(auto e : edges) {
            int p1 = findPath(p, e.first);
            int p2 = findPath(p, e.second);
            if(p1==p2) {
                    return false;
            }
            p[p1] = p2;
        }
        return true;
    }
};

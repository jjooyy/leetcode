class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int, int>> myq;
        vector<pair<int, int>> dir={{1,0}, {-1,0}, {0,1}, {0, -1}};
        int row = rooms.size();
        if(!row) {
            return;
        }
        int col = rooms[0].size();
        pair<int, int> temp, dirp;
        int tx, ty, px, py;
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(!rooms[i][j]) {
                    temp.first = i;
                    temp.second = j;
                    myq.push(temp);
                }
            }
        }
        
        while(!myq.empty()) {
            temp = myq.front();
            tx = temp.first;
            ty = temp.second;
            myq.pop();
            for(int i=0; i < 4; i++) {
                dirp = make_pair(tx + dir[i].first, ty + dir[i].second);
                px = dirp.first;
                py = dirp.second;
                if(px<0||px>=row||py<0||py>=col
                    ||rooms[px][py]<=rooms[tx][ty]+1) {
                    continue;
                }
                rooms[px][py] = rooms[tx][ty]+1;
                myq.push(dirp);
            }
        }
    }
};

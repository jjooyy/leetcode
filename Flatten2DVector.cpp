class Vector2D {
    vector<vector<int>> vec;
    int x,y;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        vec = vec2d;
        x = 0;
        y = 0;
        if(vec.size()) {
            while((!vec[x].size())&&(x!=vec.size())) {
                x++;
            }
        }
    }

    int next() {
        int temp;
        while(!vec[x].size()) {
            x++;
            y = 0;
        }
        temp = vec[x][y];
        if(y==vec[x].size()-1) {
            x++;
            y = 0;
            while((!vec[x].size())&&(x!=vec.size())) {
                x++;
            }
        }
        else {
            y++;
        }
        return temp;
    }

    bool hasNext() {
        int size = vec.size();
        if(!size)
            return false;
        else {
            if(x<size-1) {
                return true;
            }
            else if(x==size-1) {
                int sizev = vec[x].size();
                if(!sizev)
                    return false;
                else {
                    if(y<=sizev-1)
                        return true;
                    else
                        return false;
                }
            }
            else {
                return false;
            }
        }
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

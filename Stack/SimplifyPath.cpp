class Solution {
public:
    string simplifyPath(string path) {
        path += "/";
        stack<string> pstk;
        string temp;
        string out;
        for(int i = 0; i < path.size(); i++) {
            if(path[i] == '/') {
                if(temp.size()) {
                    if(temp == "..") {
                        if(!pstk.empty()) {
                            pstk.pop();
                        }
                    }
                    else if (temp != ".") {
                        pstk.push(temp);
                    }
                    temp.clear(); 
                }
            }
            else {
                temp.push_back(path[i]);
            }
        }
        while(!pstk.empty()) {
            out = '/' + pstk.top() + out;
            pstk.pop();
        }
        if(!out.size()) {
            return "/";
        }
        else {
            return out;
        }
    }
};

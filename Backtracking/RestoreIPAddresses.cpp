class Solution {
public:
    void checkAddress(vector<string> &adlist, string s, string addr, int start, int len, int pos) {
        string ip = s.substr(start, len);
        //cout << ip << endl;
        int ipNum = stoi(ip);
        if(ipNum >= 0 && ipNum < 256 ) {
            if(len > 1 && s[start] == '0') {
                return;
                //not valid number
            }
            addr += ip;
            if(pos != 3) {
               addr += '.'; 
                for(int i = 1; i <= 3 && start + len + i <= s.size(); i++) {
                    checkAddress(adlist, s, addr, start + len, i, pos + 1);
                }               
            }
            else {
                if(start + len == s.size()) {
                    adlist.push_back(addr);
                }
                return;
            }
        }
        else {
            return;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> adlist;
        string temp;
        int start = 0; 
        int len;
        int pos = 0;
        if(!s.size()) {
            return adlist;
        }
        for(int i = 1; i <= 3; i++ ) {
            len = i;
            checkAddress(adlist, s, temp, 0, len, 0);
        }
        return adlist;
    }
};

class Solution {
public:
    void reverseWords(string &s) {
        int size = s.size();
        string str;
        int pos = 0;
        bool head = true;
        string temp = "";
        for(int i = 0; i < size; i++) {
            if(s[i] != ' ') {
                temp += s[i];
            }
            else {
                if(temp != "") {
                    if(pos != i) {
                        if(head == false) {
                            temp += ' ';
                        }
                        else {
                            head = false;
                        }
                        str.insert(0, temp);
                        pos = i + 1;
                        temp = "";
                    }
                }
            }
        }
        if (temp != "") {
			if (!head) {
				temp += ' ';
				str.insert(0, temp);
			}
			else {
				str.insert(0, temp);
			}
		}
            s = str;
    }
};

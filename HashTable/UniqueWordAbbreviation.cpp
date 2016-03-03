class ValidWordAbbr {
    unordered_map<string, unordered_set<string> > map;
    string getAbbr(string word) {
        string temp = "";
        temp += word[0];
        if(word.size() > 2) {
            temp += to_string(word.size() - 2);
        }
        temp += word[word.size()-1];
        return temp;       
    } 
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for(string s : dictionary) {
            string temp = getAbbr(s);
            map[temp].insert(s);
        }
    }

    bool isUnique(string word) {
        string temp = getAbbr(word);
        if(map.find(temp) != map.end()) {
            if(map[temp].size() > 1 ) {
                return false;
            }
            else if(map[temp].count(word)) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return true;
        }
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");

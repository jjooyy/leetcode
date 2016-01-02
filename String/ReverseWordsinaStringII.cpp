class Solution {
public:
	void reverseWords(string &s) {
		int size = s.size();
		string temp = "";
		bool head = true;
		int pos = 0;
		for (int i = 0; i < size; i++) {
			if (s[i] == ' ') {
				if (!head) {
					temp += ' ';
					s.erase(pos, i - pos);
					s.insert(0, temp);
				}
				else {
					head = false;
				}
				pos = i;
				temp = "";

			}
			else {
				temp += s[i];
			}
		}

		if (!head) {
			temp += ' ';
		}
		s.erase(pos, size - pos);
		s.insert(0, temp);

	}
};

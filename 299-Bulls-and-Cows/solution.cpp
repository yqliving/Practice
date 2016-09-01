class Solution {
public:
    // only contains digits 
    string getHint(string secret, string guess) {
        int aCnt = 0;
        int bCnt = 0;
        vector<int> Vec(10, 0); 
        if (secret.size() != guess.size() || secret.empty()) { return "0A0B"; }
        for (int i = 0; i < secret.size(); ++i) {
            char c1 = secret[i]; char c2 = guess[i];
            if (c1 == c2) {
                ++aCnt; 
            } else {
                if (Vec[c1-'0']++ < 0) bCnt++;
                if (Vec[c2-'0']-- > 0) bCnt++;
            }
        }
        
        return to_string(aCnt) + 'A' + to_string(bCnt) + 'B';
    }
};

/*
class Solution {
public:
    string getHint(string secret, string guess) {
	unordered_map<char, int> mp;
	int n = secret.size(), cA = 0, cB = 0;
	for (int i = 0; i < n; i++) {
		if (secret[i] == guess[i]) {
			cA++;
			continue;
		}
		mp[secret[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (secret[i] != guess[i] && mp[guess[i]] > 0) {
			mp[guess[i]]--;
			cB++;
		}
	}
	return to_string(cA) + 'A' + to_string(cB) + 'B';
}
};
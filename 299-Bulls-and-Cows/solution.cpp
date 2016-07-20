/*class Solution {
public:
string getHint(string secret, string guess) {
    unordered_map<char,int> map;
    unordered_map<char,int>::iterator it;
    int bulls = 0, cows = 0;
    for (int i = 0; i < secret.length(); i++) {
        if (guess[i] == secret[i]) {
            bulls++;
            secret.erase(i,1);
            guess.erase(i,1);
            i--;
        }
        else {
         it = map.find(secret[i]);
         if (it != map.end())
            it->second++;
        else
         map.insert(make_pair(secret[i],1));
        }
    }
    for (int i = 0; i < guess.length(); i++) {
            it = map.find(guess[i]);
            if (it != map.end() && it->second >0) {
                cows++;
               it->second--;
            }
    }
    
    return to_string(bulls) + "A" + to_string(cows) + "B";
}
};*/


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
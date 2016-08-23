class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> magazLetters;
        for(char m : magazine)
            magazLetters[m]++;
        for(char r : ransomNote)
            if(--magazLetters[r]<0) return false;
        return true;
    }
};

/*
class Solution {
public:
bool canConstruct(string ransomNote, string magazine) {
	for (auto i : ransomNote) {
		auto pos = magazine.find(i);
		if (pos == string::npos) {
			return false;
		}
		magazine.erase(pos, 1);
	}
	return true;
}
};
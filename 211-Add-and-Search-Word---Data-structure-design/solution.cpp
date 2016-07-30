
class TrieNode {
public:
	TrieNode *next[26] = {NULL};
	bool isend = false;
	TrieNode() {
		
	}
};
class WordDictionary {
public:
	TrieNode *root;
	WordDictionary() {
		root = new TrieNode();
	}
	
	void addWord(string word) {
		TrieNode *p = root;
		for (int i = 0; i < word.size(); i++) {
			if (p->next[word[i] - 'a'] == NULL)
				p->next[word[i] - 'a'] = new TrieNode();
			p = p->next[word[i] - 'a'];
		}
		p->isend = true;
	}
	
	bool search(string word) {
		return help(word, root);
	}
	
	bool help(string word, TrieNode *root) {
		TrieNode *p = root;
		for (int i = 0; i < word.size(); i++) {
			if (word[i] != '.') {
				if (p->next[word[i] - 'a'] == NULL)
					return false;
				p = p->next[word[i] - 'a'];
			}
			else {
				TrieNode *q = p;
				for (int j = 0; j < 26; j++) {
					if (q->next[j] != NULL && help(word.substr(i + 1), q->next[j]))
						return true;
				}
				return false;
			}
		}
		return p->isend;
	}
};
// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
// Shortest Unique Prefix for Every Word

struct TrieNode {
	char ch;
	vector<TrieNode*> children;
	int child;
	TrieNode(char c) {
		ch = c;
		children.resize(26);
		for (int i = 0; i<26; i++) {
			children[i] = nullptr;
		}
		child = 0;
	}
};
struct Trie {
	TrieNode* root;
	Trie() {
		root = new TrieNode('\0');
	}
	void insert(string& s) {
		TrieNode* temp = root;
		temp->child++;
		for (int i = 0; i<s.length(); i++) {
			if (temp->children[s[i]-'a'] == nullptr) {
				temp->children[s[i]-'a'] = new TrieNode(s[i]);
				temp->children[s[i]-'a']->child++;
				temp = temp->children[s[i]-'a'];
			} else {
				temp->children[s[i]-'a']->child++;
				temp = temp->children[s[i]-'a'];
			}
		}
	}
	string helper(string &s) {
		string a = "";
		TrieNode* temp = root;
		for (int i = 0; i<s.length(); i++) {
			if (temp->children[s[i]-'a'] && temp->children[s[i]-'a']->child>0) {
				a += s[i];
				temp = temp->children[s[i]-'a'];
				if (temp->child == 1)break;
			}
		}
		return a;
	}
};
class Solution {
	public:
	vector<string> findPrefixes(vector<string>& arr) {
		Trie root;
		int n = arr.size();
		for (int i = 0; i<n; i++) {
			root.insert(arr[i]);
		}
		vector<string> result;
		for (int i = 0; i<n; i++) {
			string a = root.helper(arr[i]);
			result.push_back(a);
		}
		return result;
	}
};

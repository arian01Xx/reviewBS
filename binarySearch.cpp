struct TrieNode{
	vector<TrieNode*> child{vector<TrieNode*>(26,nullptr)};
	string* word{};
};

void insert(TrieNode* root, string& word){
	for(char c: word){
		c -= 'a';
		//si no existe lo agrega
		if(root->child[c]==nullptr) root->child[c]=new TrieNode();
		root=root->child[c];
	}
	root->word= &word;
}

void dfs(TrieNode* root, int limit, vector<string>& result){
	if(root=nullptr) return;
	if(result.size()==limit) return;
	if(root->word != nullptr) result.push_back(*root->word);
	for(int i=0; i<26; ++i){
		dfs(root->child[i], limit, result);
	}
}

vector<string> getWords(TrieNode* root, int limit){
	vector<string> result;
	dfs(root, limit, result);
	return result;
}
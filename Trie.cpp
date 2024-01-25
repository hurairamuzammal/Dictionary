
#include "Trie.hpp"
#include <iostream>
#include <string>
using namespace std;

// TrieNode
TrieNode::TrieNode() {
	m_letter = '\0';
	isWord = false;
	leftmostChild = nullptr;
	rightSibling = nullptr;
}

TrieNode::TrieNode(const char& letter) {
	m_letter = letter;
	isWord = false;
	leftmostChild = nullptr;
	rightSibling = nullptr;
}


// Trie


Trie::Trie() {
	root = new TrieNode();
}


Trie::~Trie() {
	// Call the helper function to delete the tree
	deleteTree(root);
}

// There is going to be maximum 26 children for each node
// Traversing list of siblings is O(26)
void Trie::insert(const string& word) {

	TrieNode* curr = root;

	size_t len = word.length();

	for (size_t i = 0; i < len; i++) {
		char letter = word[i];
		// If there is no leftmost child, then create a new node
		if (curr->leftmostChild == nullptr) {
			curr->leftmostChild = new TrieNode(letter);
			curr = curr->leftmostChild;
		}
		else {
			curr = curr->leftmostChild;
			// Traverse list of siblings until we find the letter or reach the end of the list
			while (curr->rightSibling != nullptr && curr->m_letter != letter) {
				curr = curr->rightSibling;
			}
			// If we reach the end of the list of siblings and the letter is not found
			if (curr->m_letter != letter) {
				curr->rightSibling = new TrieNode(letter);
				curr = curr->rightSibling;
			}
		}
	}
	curr->isWord = true;


	
}

bool Trie::contains(const string& word) {
	TrieNode* curr = root;
	size_t len = word.length();
	for (size_t i = 0; i < len; i++) {
		char letter = word[i];
		// If there is no leftmost child, then the word is not in the trie
		if (curr->leftmostChild == nullptr) {
			return false;
		}
		else {
			curr = curr->leftmostChild;
			// Traverse list of siblings until we find the letter or reach the end of the list
			while (curr->rightSibling != nullptr && curr->m_letter != letter) {
				curr = curr->rightSibling;
			}
			// If we reach the end of the list of siblings and the letter is not found
			if (curr->m_letter != letter) {
				return false;
			}
		}
	}
	return curr->isWord;
}


bool Trie::deleteWord(const string& word) {
	TrieNode* curr = root;
	size_t len = word.length();
	for (size_t i = 0; i < len; i++) {
		char letter = word[i];
		// If there is no leftmost child, then the word is not in the trie
		if (curr->leftmostChild == nullptr) {
			return false;
		}
		else {
			curr = curr->leftmostChild;
			// Traverse list of siblings until we find the letter or reach the end of the list
			while (curr->rightSibling != nullptr && curr->m_letter != letter) {
				curr = curr->rightSibling;
			}
			// If we reach the end of the list of siblings and the letter is not found
			if (curr->m_letter != letter) {
				return false;
			}
		}
	}
	// If the word is not a word, then it is not in the trie
	if (!curr->isWord) {
		return false;
	}
	// If the word is a word, then we can delete it
	// by just setting the isWord flag to false
	else {
		curr->isWord = false;
		return true;
	}
}

List<string> Trie::keysWithPrefix(const string& prefix, const size_t& count) {
	List<string> keys;
	TrieNode* curr = root;
	size_t len = prefix.length();
	for (size_t i = 0; i < len; i++) {
		char letter = prefix[i];
		// If there is no leftmost child, then the word is not in the trie
		if (curr->leftmostChild == nullptr) {  
			return keys;
		}
		else {
			curr = curr->leftmostChild;
			// Traverse list of siblings until we find the letter or reach the end of the list
			while (curr->rightSibling != nullptr && curr->m_letter != letter) {
				curr = curr->rightSibling;
			}
			// If we reach the end of the list of siblings and the letter is not found
			if (curr->m_letter != letter) {
				return keys;
			}
		}
	}
	int locCount = 0;
	string word = prefix;
	keysWithPrefixHelper(curr, word, keys, count, locCount);
	return keys;
}


void Trie::keysWithPrefixHelper(TrieNode* node, const string& prefix, List<string>& list, const size_t& count, int& locCount) {
	// If the node is a word, then add it to the list
	if (node->isWord) {
		locCount = locCount + 1;
		list.push(prefix);
	}
	// If the node has a leftmost child, then traverse the subtree rooted at the leftmost child
	if (node->leftmostChild != nullptr) {
		TrieNode* curr = node->leftmostChild;
		// Traverse the list of siblings
		while (curr != nullptr) {
			// Add the letter to the prefix
			string word = prefix + curr->m_letter;
			// Recursively call the function
			(locCount != count) ? (keysWithPrefixHelper(curr, word, list, count, locCount)) : true;
			curr = curr->rightSibling;
		}
	}
}



List<string> Trie::collectAllWords() {
	List<string> words;
	string word = "";
	collectAllWordsHelper(root, word, words);
	return words;
}

void Trie::collectAllWordsHelper(TrieNode* node, string& word, List<string>& list) {
	// If the node is a word, then add it to the list
	if (node->isWord) {
		list.push(word);
	}
	// If the node has a leftmost child, then traverse the subtree rooted at the leftmost child
	if (node->leftmostChild != nullptr) {
		TrieNode* curr = node->leftmostChild;
		// Traverse the list of siblings
		while (curr != nullptr) {
			// Add the letter to the prefix
			word = word + curr->m_letter;
			// Recursively call the function
			collectAllWordsHelper(curr, word, list);
			curr = curr->rightSibling;
		}
	}
	// Remove the last letter from the word
	word = word.substr(0, word.length() - 1);



}


List<string> Trie::longestPrefixOf(const string& word, const size_t& count) {
	List<string> prefix;
	TrieNode* curr = root;
	size_t len = word.length();

	for (size_t i = 0; i < len; i++) {
		char letter = word[i];

		// If there is no leftmost child or the letter is not found in the siblings
		if (curr->leftmostChild == nullptr) {
			return prefix;
		}
		else {
			curr = curr->leftmostChild;

			// Traverse list of siblings until we find the letter or reach the end of the list
			while (curr != nullptr && curr->m_letter != letter) {
				curr = curr->rightSibling;
			}

			// If we reach the end of the list of siblings and the letter is not found
			if (curr == nullptr || curr->m_letter != letter) {
				return prefix;
			}
		}

		// If the node is a word and it's not the original word, then add it to the list
		if (curr->isWord && i < len - 1) {
			prefix.push(word.substr(0, i + 1));
		}
	}
	int locCount = 0;
	longestPrefixOfHelper(curr, word, prefix, count, locCount);
	return prefix;
}

void Trie::longestPrefixOfHelper(TrieNode* node, const string& word, List<string>& prefix, const size_t& count, int& locCount) {
	// If the node is a word, then add it to the list
	if (node->isWord) {
		locCount = locCount + 1;
		prefix.push(word);
	}

	// If the node has a leftmost child, then traverse the subtree rooted at the leftmost child
	if (node->leftmostChild != nullptr && locCount != count) {
		TrieNode* curr = node->leftmostChild;

		// Traverse the list of siblings
		while (curr != nullptr) {
			// Add the letter to the prefix
			string newWord = word + curr->m_letter;

			// Recursively call the function
			longestPrefixOfHelper(curr, newWord, prefix, count, locCount);
			curr = curr->rightSibling;
		}
	}
}



void Trie::clear() {
	// Call the helper function to delete the tree
	deleteTree(root);
	root = new TrieNode();
}

void Trie::deleteTree(TrieNode* node) {
	// If the node has a leftmost child, then traverse the subtree rooted at the leftmost child
	if (node->leftmostChild != nullptr) {
		TrieNode* curr = node->leftmostChild;
		// Traverse the list of siblings
		while (curr != nullptr) {
			// Recursively call the function
			TrieNode* next = curr->rightSibling;  // Store next sibling before deletion
			deleteTree(curr);
			curr = next;  // Move to the next sibling
		}
	}
	delete node;
	node = nullptr;  // Set the pointer to nullptr after deletion
}



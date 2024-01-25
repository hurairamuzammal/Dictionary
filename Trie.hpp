#pragma once

#include <iostream>
#include "List.hpp"
#include <string>

// Node for Trie ADT
class TrieNode {
	public:
	char m_letter;
	bool isWord;
	TrieNode* leftmostChild, *rightSibling;
	TrieNode();
	TrieNode(const char& letter);
};



// Trie ADT with leftmost child right sibling representation
class Trie {
	public:
		Trie();
				
		~Trie();

		// precondition: word is a string
		// postcondition: inserts word into the trie
		void insert(const std::string& word);

		// precondition: word is a string
		// postcondition: returns true if word is in the trie, false otherwise
		bool contains(const string& word);


		// precondition: word is a string
		// postcondition: deletes word from the trie
		bool deleteWord(const std::string& word);

		// precondition: prefix is a string
		// postcondition: returns a list of all words in the trie that start with prefix
		List<std::string> keysWithPrefix(const std::string& prefix, const size_t& count);


		List<std::string> collectAllWords();

		// precondition: word is a string
		// postcondition: returns the longest prefix of word that is in the trie
		List<std::string> longestPrefixOf(const std::string& word, const size_t& count);

		void clear();
private:
	TrieNode* root;
	// Helper functions

	// precondition: node is a TrieNode pointer
	// postcondition: deletes all nodes in the trie
	void deleteTree(TrieNode* node);

	void keysWithPrefixHelper(TrieNode* node, const std::string& prefix, List<std::string>& list, const size_t& count, int& locCount);
	void collectAllWordsHelper(TrieNode* node, std::string& word, List<std::string>& list);
	void longestPrefixOfHelper(TrieNode* node, const std::string& word, List<std::string>& prefix, const size_t& count, int& locCount);
};
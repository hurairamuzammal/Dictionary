#pragma once


// Dictionary.hpp


#include <iostream>
#include <string>
#include <Windows.h>
#include "Trie.hpp"
#include "List.hpp"
#include "HashMap.hpp"
class Dictionary {

public:
	static Dictionary& getInstance();
	~Dictionary();
	bool loadDictionary(const std::string& filename);
	bool contains(const std::string& word);
	bool insert(const std::string& word, const std::string& meaning);
	bool deleteWord(const std::string& word);
	List<std::string> collectAllWords();
	List <std::string> keysWithPrefix(const std::string& prefix, const size_t& count);
	List<std::string> longestPrefixOf(const std::string& word, const size_t& count);
	std::string& getMeaning(const std::string& word);
	// precondition: word is a string and isValid is a boolean variable
	// postCondition: returns a valid word and sets isValid to true if the word is valid
	string validWord(const string& word, bool& isValid);
	bool writeToFile(const std::string& word, const std::string& meaning, const std::string& fileName, std::streampos& offset);	
	void deleteFromFileData(const std::streampos& offset);
	
	bool editMeaning(const std::string& word, const std::string& newMeaning);
	HashMapEntry* getEntry(const std::string& word);
private:
	Trie words;
	HashMap meanings;	


	HANDLE fileHandle;
	HANDLE fileMapping;
	char* fileData;

	size_t fileSize;
};

// Dictionary.cpp


#include "Dictionary.hpp"
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace boost::algorithm;
using namespace std;


Dictionary& Dictionary::getInstance() {
	static Dictionary instance;
	return instance;
}

Dictionary::~Dictionary() {
	// clear the tree
	words.clear();


	
}

bool Dictionary::loadDictionary(const string& filename) {
	fileHandle = CreateFile(wstring(filename.begin(), filename.end()).c_str(),
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (fileHandle == INVALID_HANDLE_VALUE) {
		cerr << "Error: Could not open file " << filename << " (Error code: " << GetLastError() << ")" << endl;
		return false;
	}

	// Determine the size of the file
	fileSize = GetFileSize(fileHandle, NULL);
	if (fileSize == INVALID_FILE_SIZE) {
		cerr << "Error: Could not get file size (Error code: " << GetLastError() << ")" << endl;
		CloseHandle(fileHandle);
		return false;
	}

	fileMapping = CreateFileMapping(fileHandle, NULL, PAGE_READWRITE, 0, fileSize, NULL);
	if (fileMapping == NULL) {
		cerr << "Error: Could not create file mapping (Error code: " << GetLastError() << ")" << endl;
		CloseHandle(fileHandle);
		return false;
	}

	fileData = static_cast<char*>(MapViewOfFile(fileMapping, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, fileSize));
	if (fileData == NULL) {
		cerr << "Error: Could not map file into memory (Error code: " << GetLastError() << ")" << endl;
		CloseHandle(fileMapping);
		CloseHandle(fileHandle);
		return false;
	}

	
	
	
	// Use stringstream to process the file content (assuming each line contains a word and a meaning)
	istringstream iss(fileData);
	string row;
	streampos offset = 0;

	while (getline(iss, row)) {
		// Skip empty lines
		if (row.empty()) {
			continue;
		}

		// Use stringstream to split the line into words and meanings
		istringstream rowStream(row);
		string word, meaning;

		// Extract the word (first column)
		rowStream >> word;

		// Extract the meaning (rest of the line after skipping spaces)
		getline(rowStream >> ws, meaning);

		
		
		if (word[0] != '@') {

			words.insert(word);
			meanings.insert(move(word), move(meaning), offset);

		}
		
		// Update offset manually
		offset += row.size() + 1;  // +1 to account for the newline character
	}


	UnmapViewOfFile(fileData);

	CloseHandle(fileMapping);

	CloseHandle(fileHandle);

	fileData = nullptr;

	return true;
}


bool Dictionary::insert(const string& word, const string& meaning) {

	// checking for the uniqueness of the word
	if (words.contains(word)) {
		cout << "Word is already in the dictionary\n";
		return false;
	}

	words.insert(word);
	streampos offset;
	
	writeToFile(word, meaning, "dictionary.txt", offset);

	meanings.insert(word, meaning, offset);

	
	return true;
}

bool Dictionary::editMeaning(const string& word, const string& newMeaning) {
	HashMapEntry* editNode = meanings.getEntry(word);
	deleteFromFileData(editNode -> offset);
	writeToFile(word, newMeaning, "dictionary.txt", editNode->offset);
	
	return true;
}

bool Dictionary::writeToFile(const string& word, const string& meaning, const string& fileName, streampos& offset) {
	
	ofstream fout("dictionary.txt", ios::app | ios::binary);

	if (!fout.is_open()) {
		cerr << "Error: Could not open file for writing" << endl;
		return false;
	}
	else {
		fout << "\n" << word << " " << meaning;
		fout.close();
	}

	return true;
}

void Dictionary::deleteFromFileData(const streampos& offset) {
	
	fstream fileStream("dictionary.txt", ios::in | ios::out | ios::binary);

	if (!fileStream.is_open()) {
		cerr << "Error: Could not open file for writing" << endl;
	}

	char c = '\0';
	// calculating the length of file
	fileStream.seekg(0, ios::end);
	size_t len = fileStream.tellg();
	//

	// finding the end of the word
	fileStream.seekg(offset, ios::beg);
	while (true) {
		fileStream.get(c);
		if (c == ' ' || c == '\t') {
			break;
		}
	
	}
	size_t endInd = fileStream.tellg();
	//

	// replacing the word with @
	string replaceString(endInd - offset - 1, '@');
	fileStream.seekg(offset, ios::beg);
	fileStream.write(replaceString.c_str(), replaceString.length());

	// closing the file
	fileStream.close();
}

bool Dictionary::contains(const string& word) {
	return words.contains(word);
}

bool Dictionary::deleteWord(const string& word) {

	HashMapEntry* deletionNode = meanings.getEntry(word);
	cout << deletionNode->offset << "\n";
	return words.deleteWord(word);

}

List<string> Dictionary::collectAllWords() {
	List<string> allwords = words.collectAllWords();
	return allwords;
}

List<string> Dictionary::keysWithPrefix(const string& prefix, const size_t& count) {
	List<string> allwords = words.keysWithPrefix(prefix, count);
	return allwords;
}

List<string> Dictionary::longestPrefixOf(const string& word, const size_t& count) {
	List<string> allwords = words.longestPrefixOf(word, count);
	return allwords;
}

string& Dictionary::getMeaning(const string& word) {
	return meanings[word];
}



// helper function
string Dictionary::validWord(const string& word, bool& isValid) {
	string validWord = "";
	for (size_t i = 0; i < word.length(); i++) {
		if (isalpha(word[i])) {
			validWord += word[i];
		}
		else {
			isValid = false;
		}
	}
	return validWord;
}


HashMapEntry* Dictionary::getEntry(const string& word) {
	return meanings.getEntry(word);
}
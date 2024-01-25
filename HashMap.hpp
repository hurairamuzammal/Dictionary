#pragma once

#include <iostream>
#include <string>

class HashMapEntry {
public:
     std::string key;
     std::string value;
     std::streampos offset;   
     HashMapEntry* next;
     HashMapEntry();
     HashMapEntry(const std::string& k, const std::string& v, const std::streampos& offset);
};



class HashMap {
private:
     static const int TABLE_SIZE = 48647;
     HashMapEntry **entries;
     const int prime = 31; // A prime number used in the double hashing formula

     // First hash function
     size_t hashFunction1(const std::string& key);

     // Second hash function for double hashing
     size_t hashFunction2(const std::string& key);
     
public:
     HashMap();
     ~HashMap();

     // Insert a value into the HashMap using an external key
     void insert(const std::string& key, const std::string& value, const std::streampos& offset);
     

     // Retrieve the value using an external key
     std::string getValue(const std::string& key);
     HashMapEntry* getEntry(const std::string& key);
     
     std::string& operator [] (const std::string& key);

};



#include "HashMap.hpp"
using namespace std;

HashMapEntry::HashMapEntry() {
     key = "";
     value = "";
     offset = 0;
}

HashMapEntry::HashMapEntry(const string& k, const string& v, const streampos& offset) {
	key = k;
	value = v;
     next = nullptr;
     this->offset = offset;
}


HashMap::HashMap() {
	entries = new HashMapEntry*[TABLE_SIZE];

     // Initialize all entries to nullptr
     for (size_t i = 0; i < TABLE_SIZE; i++) {
		entries[i] = nullptr;
	}
}

HashMap::~HashMap() {
	// Delete all entries
     for (size_t i = 0; i < TABLE_SIZE; i++) {
		HashMapEntry* current = entries[i];
          while (current != nullptr) {
			HashMapEntry* next = current->next;
			delete current;
			current = next;
		}
	}

	// Delete the array
	delete[] entries;
}

size_t HashMap::hashFunction1(const string& key) {
     size_t hash = 0;
     for (char c : key) {
          hash = (hash * prime) + c; // Horner's rule
     }
     return hash % TABLE_SIZE;
}

size_t HashMap::hashFunction2(const string& key) {
     // Use a prime number smaller than TABLE_SIZE
     return (prime - (hashFunction1(key) % (prime - 1))) % TABLE_SIZE;
}



// Insert a key-value pair into the HashMap using chaining
void HashMap::insert(const string& key, const string& value, const streampos& offset) {
     size_t index = hashFunction1(key);

     // Check if the index is empty (no collision)
     if (entries[index] == nullptr) {
          entries[index] = new HashMapEntry(key, value, offset);
        
     }
     else {
          // Collision occurred, insert at the beginning of the linked list
          HashMapEntry* newEntry = new HashMapEntry(key, value, offset);
          newEntry->next = entries[index];
          entries[index] = newEntry;
     }
}

string HashMap::getValue(const string& key) {
     size_t index = hashFunction1(key);

     // Search for the key in the linked list at the index
     HashMapEntry* current = entries[index];
     while (current != nullptr) {
          if (current->key == key) {
               return current->value; // Return the value if the key is found
          }
          current = current->next;
     }

     return "Key not found"; // Return a default value if the key is not found
}

string& HashMap::operator [] (const string& key) {
	size_t index = hashFunction1(key);

	// Search for the key in the linked list at the index
	HashMapEntry* current = entries[index];
     while (current != nullptr) {
          if (current->key == key) {
			return current->value; // Return the value if the key is found
			
		}
		current = current->next;
	}

     throw exception("Key not found"); // Return a default value if the key is not found
}

HashMapEntry* HashMap::getEntry(const string& key)
{
	size_t index = hashFunction1(key);

	// Search for the key in the linked list at the index
	HashMapEntry* current = entries[index];
     while (current != nullptr) {
          if (current->key == key) {
			return current; // Return the value if the key is found
		}
		current = current->next;
	}

	return nullptr; // Return a default value if the key is not found
}
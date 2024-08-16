#include <iostream>
#include <vector>
#include <list>
#include <utility>  // For pair
#include <functional>  // For hash

using namespace std;

template <typename KeyType, typename ValueType>
class HashMap {

public:
    HashMap(size_t size = 100) : table(size) {}

    // Insert a key-value pair into the hashmap
    void insert(const KeyType& key, const ValueType& value) {
        size_t index = hashFunc(key) % table.size();
        for (auto& kv : table[index]) {
            if (kv.first == key) {
                kv.second = value; // Update existing key
                return;
            }
        }
        table[index].emplace_back(key, value); // Insert new key-value pair
    }

    // Get the value associated with a key
    bool get(const KeyType& key, ValueType& value) const {
        size_t index = hashFunc(key) % table.size();
        for (const auto& kv : table[index]) {
            if (kv.first == key) {
                value = kv.second;
                return true;
            }
        }
        return false; // Key not found
    }

    // Remove a key-value pair from the hashmap
    bool remove(const KeyType& key) {
        size_t index = hashFunc(key) % table.size();
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                return true; // Key found and removed
            }
        }
        return false; // Key not found
    }

private:
    vector<list<pair<KeyType, ValueType>>> table;
    hash<KeyType> hashFunc; // Hash function to map keys to bucket indices
};

int main() {
    HashMap<string, int> hashmap;

    // Insert some key-value pairs
    hashmap.insert("apple", 3);
    hashmap.insert("banana", 5);
    hashmap.insert("orange", 7);

    // Retrieve values
    int value;
    if (hashmap.get("apple", value)) {
        cout << "Value for 'apple': " << value << endl;
    } else {
        cout << "'apple' not found." << endl;
    }

    // Remove a key-value pair
    if (hashmap.remove("banana")) {
        std::cout << "'banana' removed." << std::endl;
    } else {
        std::cout << "'banana' not found." << std::endl;
    }

    return 0;
}

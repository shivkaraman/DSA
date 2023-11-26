//Separate chaining/Open hashing implimentation

#include <iostream>
#include <list>
#include <string>
using namespace std;

class hashTable{
    private :   
        static const int hashGroups = 10;
        list <pair<int, string>> table[hashGroups];
    public : 
        bool isEmpty();
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();
};

bool hashTable :: isEmpty(){
    int sum = 0;
    for(int i = 0; i < hashGroups; i++){
        sum += table[i].size();
    }
    return (sum == 0);
}

int hashTable :: hashFunction(int key){
    return key % hashGroups;    // k % n
}

void hashTable :: insertItem(int key, string value){ //Check if a key already existts, if yes replace its value
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto bitr = cell.begin();
    bool keyExists = false;
    for(; bitr != cell.end(); bitr++){
        if(bitr->first == key){
            keyExists = true;
            cout << "[WARNING] Key(" << key << ") already exists. Value replaced (" << bitr->second << " with " << value << ")" << endl;
            bitr->second = value;
            break;
        }
    }
    if(!keyExists){
        cell.emplace_back(key, value);
    }
}

void hashTable :: removeItem(int key){
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    auto bitr = cell.begin();
    bool keyExists = false;
    for(; bitr != cell.end(); bitr++){
        if(bitr->first == key){
            keyExists = true;
            bitr = cell.erase(bitr); //Returns an iterator to next of deleted element(To avoid any bug, we are capturing it in bitr)
            cout << "[INFO] Item deleted" << endl;
            break;
        }
    }
    if(!keyExists){
        cout << "[INFO] Item not found" << endl;
    }
}

void hashTable :: printTable(){
    for(int i = 0; i < hashGroups; i++){
        if(table[i].size() == 0)
            continue;
        for(auto &it : table[i]){
            cout << "Key : " << it.first << " Value : " << it.second << endl;
        }
    }
}
int main(){
    hashTable HT;
    if (HT.isEmpty()) 
        cout << "Correct answer. Good job." << endl;
    else 
        cout << "Oh oh. We need to check out code!" << endl;
    
    HT.insertItem (905, "Jim");
    HT.insertItem (201, "Tom");
    HT.insertItem (332, "Bob");
    HT.insertItem (124, "Sally");
    HT.insertItem(107, "Sandy");
    HT.insertItem (929, "Barb");
    HT.insertItem (928, "Rob");
    HT.insertItem (928, "Rick");

    HT.printTable();

    HT. removeItem (332);
    HT.removeItem(100);

    if (HT.isEmpty()) 
        cout << "Oh oh. We need to check out code!" << endl;
    else 
        cout << "Correct answer! Good job!" << endl;
    return 0;
}
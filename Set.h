#ifndef SET_H
#define SET_H

#include <string>

//using ItemType = std::string;
using ItemType = unsigned long;

class Set {
public:
    Set();
    // Create an empty set (i.e., one with no items).
    
    Set(const Set& other_s);
    // Copy constructor
    
    ~Set();
    // Destructor
    
    Set& operator=(const Set &other_s);
    // Assignment operator
    
    bool empty() const;
    // Return true if the set is empty, otherwise false.
    
    int size() const;
    // Return the number of items in the set.
    
    bool insert(const ItemType& value);
    // Insert value into the set if it is not already present.  Return
    // true if the value is actually inserted.  Leave the set unchanged
    // and return false if the value is not inserted (perhaps because it
    // was already in the set).
    
    bool erase(const ItemType& value);
    // Remove the value from the set if it is present.  Return true if the
    // value was removed; otherwise, leave the set unchanged and
    // return false.
    
    bool contains(const ItemType& value) const;
    // Return true if the value is in the set, otherwise false.
    
    bool get(int i, ItemType& value) const;
    // If 0 <= i < size(), copy into value the item in the set that is
    // strictly less than exactly i items in the set and return true.
    // Otherwise, leave value unchanged and return false.
    
    void swap(Set& other);
    // Exchange the contents of this set with the other one.
    
    void dump() const;
    // dumps out info via cerr
private:
    struct Node {
        ItemType m_value;
        Node* m_next;
        Node* m_last;
    };
    // doubly linked list
    // pointers to both next and last nodes
    
    Node* m_dummy;
    // dynamically allocated dummy node
    // acts as head pointer
    // don't need 2 ptrs to same location in memory
    
    int m_size;
    // size of set
};

void unite(const Set& s1, const Set& s2, Set& result);
// contains only values contained in s1, s2, or both

void difference(const Set& s1, const Set& s2, Set& result);
// contains only values contained in s1 or s2 but not contained in both!

#endif

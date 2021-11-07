#ifndef NEWSET_H
#define NEWSET_H

#include <string>

//using ItemType = std::string;
using ItemType = unsigned long;

const int DEFAULT_MAX_ITEMS = 150;

class Set {
public:
    Set(int size = DEFAULT_MAX_ITEMS);         // Create an empty set (i.e., one with no items).

    Set(const Set& other_s); // copy constructor

    ~Set(); // destructor

    Set& operator=(const Set &other_s); // assignment operator

    bool empty() const;  // Return true if the set is empty, otherwise false.

    int size() const;    // Return the number of items in the set.

    bool insert(const ItemType& value);
    // Insert value into the set if it is not already present.  Return
    // true if the value is actually inserted.  Leave the set unchanged
    // and return false if the value is not inserted (perhaps because it
    // was already in the set or because the set has a fixed capacity and
    // is full).

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
    ItemType* m_array;
    int m_max;
    int m_size;
};

#endif


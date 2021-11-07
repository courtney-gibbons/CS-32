#include "Set.h"
#include <iostream>

Set::Set() {
    // Create an empty set (i.e., one with no items).
    // Using doubly linked list w dummy node
    // Create head pointing to dummy and set dummy ptrs to nullptr
    
    m_dummy = new Node;
    m_dummy->m_next = m_dummy;
    m_dummy->m_last = m_dummy;
    
    m_size = 0;
}

Set::Set(const Set& other_s) {
    // Copy constructor
    
    // set up an empty set
    m_dummy = new Node;
    m_dummy->m_next = m_dummy;
    m_dummy->m_last = m_dummy;
    
    m_size = 0;
    
    // fill set with copies of nodes from the other set
    // loop through other set
    // use insert fn to add to set
    Node* p;
    for (p = other_s.m_dummy->m_next; p != other_s.m_dummy; p = p->m_next) {
        insert(p->m_value);
    }
}

Set::~Set() {
    // Destructor
    
    // create a ptr to loop through list
    Node* p = m_dummy;
    
    // have last node's next point to nullptr
    // helps us find the end of the list
    m_dummy->m_last->m_next = nullptr;
    
    // loop through array
    // create temp pointing to next so we dont lose the next item
    // then delete current item
    while (p != nullptr) {
        Node* temp = p->m_next;
        delete p;
        p = temp;
    }
}

Set& Set::operator=(const Set &other_s) {
    // Assignment operator
    
    // check if they're the same set
    if (this != &other_s) {
        // otherwise, create a temp set using copy constructor
        // use swap to copy to this set
        Set temp(other_s);
        swap(temp);
    }
    
    return *this;
}

bool Set::empty() const {
    // Return true if the set is empty, otherwise false.
    if (m_size == 0) {
        return (true);
    } else {
        return (false);
    }
}

int Set::size() const {
    // Return the number of items in the set.
    return( m_size );
}

bool Set::insert(const ItemType& value) {
    // Insert value into the set if it is not already present.  Return
    // true if the value is actually inserted.  Leave the set unchanged
    // and return false if the value is not inserted (perhaps because it
    // was already in the set).
    
    // check if set alrady contains value
    // loop through with pointer
    Node* p;
    for (p = m_dummy->m_next; p != m_dummy; p = p->m_next) {
        if (p->m_value == value) {
            return (false);
        }
    }
    
    // otherwise increment and insert in reverse alphabetical order
    m_size++;
    
    // find where in the array the new value belongs
    // loop through and check once it finds something it's greater than
    // else, it'll go at the end
    for (p = m_dummy->m_next; p != m_dummy && value < p->m_value; p = p->m_next) {
        ;
    }
    
    // p now pointing to head or the first element less than it
    // create new node, put in value, fix ptrs
    Node* newGuy = new Node;
    newGuy->m_value = value;
    newGuy->m_last = p->m_last;
    p->m_last->m_next = newGuy;
    newGuy->m_next = p;
    p->m_last = newGuy;
    
    return(true);
}

bool Set::erase(const ItemType& value) {
    // Remove the value from the set if it is present.  Return true if the
    // value was removed; otherwise, leave the set unchanged and
    // return false.
    
    // check if set contains value
    // loop through list w pointer
    Node* p;
    for (p = m_dummy->m_next; p != m_dummy; p = p->m_next) {
        if (p->m_value == value) {
            // if we find the value
            // move ptrs
            p->m_last->m_next = p->m_next;
            p->m_next->m_last = p->m_last;
            
            // delete
            delete p;
            
            // decrease size
            m_size--;
            
            return (true);
        }
    }
    
    return(false);
}

bool Set::contains(const ItemType& value) const {
    // Return true if the value is in the set, otherwise false.
    
    // loop through list with pointer
    Node* p;
    for (p = m_dummy->m_next; p != m_dummy; p = p->m_next) {
        if (p->m_value == value) {
            return (true);
        }
    }
    
    return(false);
}

bool Set::get(int i, ItemType& value) const {
    // If 0 <= i < size(), copy into value the item in the set that is
    // strictly less than exactly i items in the set and return true.
    // Otherwise, leave value unchanged and return false.
    
    // check if invalid input
    if ((i >= m_size) || (i < 0)) {
        return(false);
    }
    
    // because array is already sorted in reverse alphabetical order
    // just return value at that index
    // use for loop to increment pointer looping through list and
    // counter counting until the desired index
    Node* p;
    int j;
    for (j = 0, p = m_dummy->m_next; j < i; p = p->m_next, j++) {
        ;
    }

    // when we arrive at the index, assign value
    value = p->m_value;
    
    return(true);
}

void Set::swap(Set& other) {
    // Exchange the contents of this set with the other one.
    
    // exchange m_size
    int temp_size = other.m_size;
    other.m_size = m_size;
    m_size = temp_size;
    
    // exchange dummy nodes
    Node* temp_ptr = other.m_dummy;
    other.m_dummy = m_dummy;
    m_dummy = temp_ptr;
}

void Set::dump() const {
    // dumps out info via cerr
    for(Node* p = m_dummy->m_next; p != m_dummy; p = p->m_next) {
        std::cerr << p->m_value << ", ";
    }
    std::cerr << std::endl;
    for(Node* p = m_dummy->m_last; p != m_dummy; p = p->m_last) {
        std::cerr << p->m_value << ", ";
    }
    std::cerr << std::endl;
    std::cerr << m_size << std::endl;
}

void unite(const Set& s1, const Set& s2, Set& result) {
    // contains only values contained in s1, s2, or both
    
    // if results string isn't empty and it isn't the same as s1 or s2, empty it
    if (!result.empty() && &s1 != &result && &s2 != &result) {
        int i_max = result.size();
        // loop through result set, deleting each value using get and erase fns
        for (int i = 0; i < i_max; i++) {
            ItemType value;
            result.get(0, value);
            result.erase(value);
        }
    }
    
    // loop through s1, getting and inserting each value
    for (int i = 0; i <s1.size(); i++) {
        ItemType value;
        s1.get(i, value);
        result.insert(value);
    }
    
    // loop through s2, getting and inserting each value
    // insert takes care of duplicates for you :)
    for (int i = 0; i <s2.size(); i++) {
        ItemType value;
        s2.get(i, value);
        result.insert(value);
    }
}

void difference(const Set& s1, const Set& s2, Set& result) {
    // contains only values contained in s1 or s2 but not contained in both!
    
    // if results string isn't empty and it isn't the same as s1 or s2, empty it
    if (!result.empty() && &s1 != &result && &s2 != &result) {
        int i_max = result.size();
        // loop through result set, deleting each value using get and erase fns
        for (int i = 0; i < i_max; i++) {
            ItemType value;
            result.get(0, value);
            result.erase(value);
        }
    }
    
    // loop through s1, getting and inserting each value
    for (int i = 0; i < s1.size(); i++) {
        ItemType value;
        s1.get(i, value);
        result.insert(value);
    }
    
    // loop through s2, getting each value and attempting to insert
    for (int i = 0; i < s2.size(); i++) {
        ItemType value;
        s2.get(i, value);
        // if insert returns false (value not inserted bc already there)
        if (result.insert(value) == false) {
            // erase that value
            result.erase(value);
        }
    }
}

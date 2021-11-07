//#include <iostream>
//#include "Set.h"
//#include <algorithm>
//#include <typeinfo>
//using namespace std;
//
//Set::Set() {
//    // Create an empty set (i.e., one with no items).
//    m_size = 0;
//}
//
//bool Set::empty() const {
//    // Return true if the set is empty, otherwise false.
//    if (m_size == 0) {
//        return(true);
//    }
//    else {
//        return(false);
//    }
//}
//
//int Set::size() const {
//    // Return the number of items in the set.
//    return(m_size);
//}
//
//bool Set::insert(const ItemType& value) {
//    // Insert value into the set if it is not already present.  Return
//    // true if the value is actually inserted.  Leave the set unchanged
//    // and return false if the value is not inserted (perhaps because it
//    // was already in the set or because the set has a fixed capacity and
//    // is full).
//    
//    // check if set is full
//    if (m_size == DEFAULT_MAX_ITEMS) {
//        return(false);
//    }
//
//    // check if set alrady contains value
//    for (int i = 0; i < m_size; i++) {
//        if (m_array[i] == value) {
//            return(false);
//        }
//    }
//
//    // otherwise increment and insert in reverse alphabetical order
//    m_size++;
//
//    // find where in the array the new value belongs
//    // loop through and check once it finds something it's greater than
//    // else, it'll go at the end - initialize this
//    int new_position = m_size-1;
//    for (int i = 0; i < m_size-1; i++) {
//        if (value > m_array[i]) {
//            new_position = i;
//            break;
//        }
//    }
//
//    // go backwards through the array setting each value to the value before
//    // start at the new last entry, m_size - 1
//    for(int i = m_size-1; i > new_position; i--) {
//        m_array[i] = m_array[i - 1];
//    }
//
//    // insert the new value
//    m_array[new_position] = value;
//
//    return(true);
//    
//    // OR
//    
////    // check if set is full
////    if (m_size == DEFAULT_MAX_ITEMS) {
////        return(false);
////    }
////
////    // check if set alrady contains value
////    for (int i = 0; i < m_size; i++) {
////        if (m_array[i] == value) {
////            return(false);
////        }
////    }
////
////    // otherwise increment and insert
////    m_size++;
////    m_array[m_size-1] = value;
////
////    // sort in alphabetical order
////    sort(m_array, m_array+m_size);
////
////    return(true);
//}
//
//bool Set::erase(const ItemType& value) {
//    // Remove the value from the set if it is present.  Return true if the
//    // value was removed; otherwise, leave the set unchanged and
//    // return false.
//    
//    int index;
//
//    // check for value
//    for (int i = 0; i < m_size; i++) {
//        if (m_array[i] == value) {
//            index = i;
//
//            // once value is found, move everything forward 1
//            // don't touch last value - can't access outside array
//            for (int i = index; i < m_size-1; i++) {
//                m_array[i] = m_array[i+1];
//            }
//
//            // decrease size
//            m_size--;
//
//            return(true);
//        }
//    }
//
//    return(false);
//}
//
//bool Set::contains(const ItemType& value) const {
//    // Return true if the value is in the set, otherwise false.
//    for (int i = 0; i < m_size; i++) {
//        if (m_array[i] == value) {
//            return(true);
//        }
//    }
//    return(false);
//}
//
//bool Set::get(int i, ItemType& value) const {
//    // If 0 <= i < size(), copy into value the item in the set that is
//    // strictly less than exactly i items in the set and return true.
//    // Otherwise, leave value unchanged and return false.
//    
//    if ((i >= m_size) || (i < 0)) {
//        return(false);
//    }
//
//    // because array is already sorted in reverse alphabetical order
//    // just return value at that index
//    value = m_array[i];
//
//    return(true);
//    
//    // OR
//    
////    if ((i >= m_size) || (i < 0)) {
////        return(false);
////    }
////
////    // sorted in alphabetical order!
////    value = m_array[m_size-i-1];
////
////    return(true);
//}
//
//void Set::swap(Set& other) {
//    // Exchange the contents of this set with the other one.
//    
//    // swap m_size using temp
//    int temp = other.m_size;
//    other.m_size = m_size;
//    m_size = temp;
//
//    // loop through both arrays (whichever is larger)
//    int larger_index;
//    if (other.m_size > m_size) {
//        larger_index = other.m_size;
//    }
//    else {
//        larger_index = m_size;
//    }
//
//    // switch each entry using temp
//    for (int i = 0; i < larger_index; i++) {
//        ItemType temp = other.m_array[i];
//        other.m_array[i] = m_array[i];
//        m_array[i] = temp;
//    }
//    
//    // OR
//    
////    std::swap(*this, other);
//}
//
//void Set::dump() const {
//    // dumps out info via cerr
//    cerr << m_array[0];
//    for (int i = 1; i < m_size; i++) {
//        cerr << ", " << m_array[i];
//    }
//    cerr << endl << m_size << endl;
//}

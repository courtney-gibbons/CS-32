//#include "AccountSet.h"
//#include <iostream>
//using namespace std;
//
//AccountSet::AccountSet() {
//    // Create an empty account set.
//}
//
//bool AccountSet::add(unsigned long acctNum) {
//    // Add an account number to the AccountSet.  Return true if and
//    // only if the account number was actually added.
//
//    return(m_set.insert(acctNum));
//}
//
//int AccountSet::size() const {
//    // Return the number of account numbers in the AccountSet.
//
//    return(m_set.size());
//}
//
//void AccountSet::print() const {
//    // Write to cout every account number in the AccountSet exactly
//    // once, one per line.  Write no other text.
//
//    unsigned long value;
//    for (int i = 0; i < m_set.size(); i++) {
//        m_set.get(i, value);
//        cout << value << endl;
//    }
//}

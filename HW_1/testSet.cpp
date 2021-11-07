//using ItemType = std::string; tests

//#include "Set.h"
////#include "newSet.h"
//#include <iostream>
//#include <string>
//#include <cassert>
//using namespace std;
//
//void test()
//{
//    Set ss;
//    assert(ss.insert("pita"));
//    assert(ss.insert("roti"));
//    assert(ss.size() == 2);
//    assert(ss.contains("roti"));
//    ItemType x = "laobing";
//    assert(ss.get(0, x)  &&  x == "roti");
//    assert(ss.get(1, x)  &&  x == "pita");
//}
//
//int main()
//{
//    // smallberg tests
//
//    test();
//
//    Set s1;
//    assert(s1.empty());
//    ItemType x1 = "arepa";
//    assert( !s1.get(42, x1)  &&  x1 == "arepa"); // x unchanged by get failure
//    s1.insert("chapati");
//    assert(s1.size() == 1);
//    assert(s1.get(0, x1)  &&  x1 == "chapati");
//
//    Set s2;
//    s2.insert("lavash");
//    s2.insert("roti");
//    s2.insert("chapati");
//    s2.insert("injera");
//    s2.insert("roti");
//    s2.insert("matzo");
//    s2.insert("injera");
//    assert(s2.size() == 5);  // duplicate "roti" and "injera" were not added
//    string x2;
//    s2.get(0, x2);
//    assert(x2 == "roti");  // "roti" is less than exactly 4 items in ss
//    s2.get(4, x2);
//    assert(x2 == "chapati");  // "chapati" is less than exactly 0 items in ss
//    s2.get(2, x2);
//    assert(x2 == "lavash");  // "lavash" is less than exactly 2 items in ss
//
//    Set s3;
//    s3.insert("laobing");
//    Set s4;
//    s4.insert("matzo");
//    s4.insert("pita");
//    s3.swap(s4);
//    assert(s3.size() == 2  &&  s3.contains("matzo")  &&  s3.contains("pita")  &&
//           s4.size() == 1  &&  s4.contains("laobing"));
//
//    Set s5;
//    s5.insert("dosa");
//    assert(!s5.contains(""));
//    s5.insert("tortilla");
//    s5.insert("");
//    s5.insert("focaccia");
//    assert(s5.contains(""));
//    s5.erase("dosa");
//    assert(s5.size() == 3  &&  s5.contains("focaccia")  &&  s5.contains("tortilla")  &&
//           s5.contains(""));
//    string x5;
//    assert(s5.get(1, x5)  &&  x5 == "focaccia");
//    assert(s5.get(2, x5)  &&  x5 == "");
//
//    // my tests
//
//    // new set = empty, size = 0
//    Set s6;
//    s6.dump();
//    assert( s6.empty() == true );
//    assert( s6.size() == 0 );
//
//    // insert 3 strings, check alpha order
//    s6.insert("b");
//    s6.dump();
//    s6.insert("a");
//    s6.dump();
//    s6.insert("c");
//    s6.dump();
//
//    // check duplicates
//    s6.insert("b");
//    s6.insert("a");
//    s6.insert("c");
//    s6.dump();
//
//    // check empty = false
//    assert( s6.empty() == false );
//
//    // check size = 3
//    assert( s6.size() == 3 );
//
//    // try erasing something that isn't there
//    assert( s6.erase("z") == false );
//    s6.dump();
//    assert( s6.size() == 3 );
//
//    // erase
//    s6.erase("b");
//    s6.dump();
//    assert( s6.size() == 2 );
//
//    // add back
//    s6.insert("b");
//    s6.dump();
//    assert( s6.size() == 3 );
//
//    // check contains
//    assert( s6.contains("a") == true );
//    assert( s6.contains("b") == true );
//    assert( s6.contains("c") == true );
//
//    // check contains w something that isn't there
//    assert( s6.contains("z") == false );
//
//    // check get
//    string str;
//    assert( s6.get(0, str) == true );
//    assert( str == "c" );
//    assert( s6.get(1, str) == true );
//    assert( str == "b" );
//    assert( s6.get(2, str) == true );
//    assert( str == "a" );
//    assert( s6.get(3, str) == false );
//    assert( str == "a" );
//    assert( s6.get(-1, str) == false );
//    assert( str == "a" );
//
//    // swap
//    Set s7;
//    s7.insert("x");
//    s7.insert("y");
//    s7.dump();
//
//    s6.swap(s7);
//    s6.dump();
//    assert( s6.size() == 2 );
//    assert( s6.contains("x") == true );
//    assert( s6.contains("y") == true );
//    assert( s6.contains("a") == false );
//    assert( s6.contains("b") == false );
//    assert( s6.contains("c") == false );
//    s7.dump();
//    assert( s7.size() == 3 );
//    assert( s7.contains("x") == false );
//    assert( s7.contains("y") == false );
//    assert( s7.contains("a") == true );
//    assert( s7.contains("b") == true );
//    assert( s7.contains("c") == true );
//
//    // swap back
//    s6.swap(s7);
//    assert( s6.size() == 3 );
//    assert( s6.contains("x") == false );
//    assert( s6.contains("y") == false );
//    assert( s6.contains("a") == true );
//    assert( s6.contains("b") == true );
//    assert( s6.contains("c") == true );
//    s7.dump();
//    assert( s7.size() == 2 );
//    assert( s7.contains("x") == true );
//    assert( s7.contains("y") == true );
//    assert( s7.contains("a") == false );
//    assert( s7.contains("b") == false );
//    assert( s7.contains("c") == false );
//
//    cout << "Passed all tests" << endl;
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// using ItemType = unsigned long; tests

//#include "Set.h"
////#include "newSet.h"
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//void test()
//{
//    Set uls;
//    assert(uls.insert(10));
//    assert(uls.insert(20));
//    assert(uls.size() == 2);
//    assert(uls.contains(20));
//    ItemType x = 30;
//    assert(uls.get(0, x)  &&  x == 20);
//    assert(uls.get(1, x)  &&  x == 10);
//}
//
//int main()
//{
//    // smallberg tests
//
//    test();
//
//    Set s1;
//    assert(s1.empty());
//    ItemType x = 9876543;
//    assert( !s1.get(42, x)  &&  x == 9876543); // x unchanged by get failure
//    s1.insert(123456789);
//    assert(s1.size() == 1);
//    assert(s1.get(0, x)  &&  x == 123456789);
//
//    // my tests
//
//    // new set = empty, size = 0
//    Set s2;
//    s2.dump();
//    assert( s2.empty() == true );
//    assert( s2.size() == 0 );
//    assert( s2.contains(0) == false );
//
//    // insert 3 ints, check order
//    s2.insert(2);
//    s2.dump();
//    s2.insert(1);
//    s2.dump();
//    s2.insert(3);
//    s2.dump();
//
//    // check duplicates
//    s2.insert(2);
//    s2.insert(1);
//    s2.insert(3);
//    s2.dump();
//
//    // check empty = false
//    assert( s2.empty() == false );
//
//    // check size = 3
//    assert( s2.size() == 3 );
//
//    // try erasing something that isn't there
//    assert( s2.erase(4) == false );
//    s2.dump();
//    assert( s2.size() == 3 );
//
//    // erase
//    s2.erase(2);
//    s2.dump();
//    assert( s2.size() == 2 );
//
//    // add back
//    s2.insert(2);
//    s2.dump();
//    assert( s2.size() == 3 );
//
//    // check contains
//    assert( s2.contains(1) == true );
//    assert( s2.contains(2) == true );
//    assert( s2.contains(3) == true );
//
//    // check contains w something that isn't there
//    assert( s2.contains(4) == false );
//
//    // check get
//    unsigned long i;
//    assert( s2.get(0, i) == true );
//    assert( i == 3 );
//    assert( s2.get(1, i) == true );
//    assert( i == 2 );
//    assert( s2.get(2, i) == true );
//    assert( i == 1 );
//    assert( s2.get(3, i) == false );
//    assert( i == 1 );
//    assert( s2.get(-1, i) == false );
//    assert( i == 1 );
//
//    // swap
//    Set s3;
//    s3.insert(10);
//    s3.insert(11);
//    s3.dump();
//
//    s2.swap(s3);
//    s2.dump();
//    assert( s2.size() == 2 );
//    assert( s2.contains(10) == true );
//    assert( s2.contains(11) == true );
//    assert( s2.contains(1) == false );
//    assert( s2.contains(2) == false );
//    assert( s2.contains(3) == false );
//    s3.dump();
//    assert( s3.size() == 3 );
//    assert( s3.contains(10) == false );
//    assert( s3.contains(11) == false );
//    assert( s3.contains(1) == true );
//    assert( s3.contains(2) == true );
//    assert( s3.contains(3) == true );
//
//    // swap back
//    s2.swap(s3);
//    assert( s2.size() == 3 );
//    assert( s2.contains(10) == false );
//    assert( s2.contains(11) == false );
//    assert( s2.contains(1) == true );
//    assert( s2.contains(2) == true );
//    assert( s2.contains(3) == true );
//    s3.dump();
//    assert( s3.size() == 2 );
//    assert( s3.contains(10) == true );
//    assert( s3.contains(11) == true );
//    assert( s3.contains(1) == false );
//    assert( s3.contains(2) == false );
//    assert( s3.contains(3) == false );
//
//    Set s69;
//    s69.insert(-1);
//    s69.dump();
//
//    cout << "Passed all tests" << endl;
//}

#include "Table.h"
#include <iostream>
#include <cassert>
using namespace std;

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    cout << "DONE" << endl;
}

void test1() {
    vector<string> cols = {
        "customer", "product", "price", "location"
    };
    Table t("customer", cols);
    assert(t.good());
    assert(t.insert("Patel 12345 42.54 Westwood"));
    assert(t.insert("O'Reilly 34567     4.99 Westwood   "));
    assert(t.insert("   Hoang  12345 30.46 'Santa Monica' "));
    assert(t.insert("Patel\t67890\t142.75  \t \t\t  \tHollywood"));
    assert(!t.insert("Figueroa 54321 59.95"));
    vector<vector<string>> v;
    t.find("Patel", v);
    assert(v.size() == 2);
    vector<vector<string>> expected = {
        { "Patel", "12345", "42.54", "Westwood" },
        { "Patel", "67890", "142.75", "Hollywood" }
    };
    assert((v[0] == expected[0] && v[1] == expected[1]) ||
        (v[0] == expected[1] && v[1] == expected[0]));
    assert(t.select("price LT 40", v) == 0);
    assert(v.size() == 2);
    expected = {
        { "O'Reilly", "34567", "4.99", "Westwood" },
        { "Hoang", "12345", "30.46", "Santa Monica" }
    };
    assert((v[0] == expected[0] && v[1] == expected[1]) ||
        (v[0] == expected[1] && v[1] == expected[0]));
    cout << "Test 1 succeeded" << endl;
}

void test2() {
    vector<string> cols = { "N", "Z" };
    Table t("Z", cols);
    assert(t.good());
    assert(t.insert("UCLA 90095"));
    assert(t.insert("Caltech 91125"));
    vector<vector<string>> v;
    t.find("90095", v);
    assert(v.size() == 1);
    assert(v[0][0] == "UCLA" && v[0][1] == "90095");
    assert(t.select("Z > 90210", v) == 0);
    assert(v.size() == 1);
    assert(v[0][0] == "Caltech" && v[0][1] == "91125");
    assert(t.insert("DSAFds 91125"));
    assert(t.select("Z = 91125", v) == 0);
    assert(v.size() == 2);
    
    vector<string> cols_2 = { "N", "Z" };
    Table t_2("F", cols_2);
    assert(!t_2.good());
    
    cout << "Test 2 succeeded" << endl;
}

void test3() {
    vector<string> cols = {
        "customer", "product", "price", "location"
    };
    Table t("customer", cols);
    assert(t.good());
    assert(t.insert("Patel 12345 42.54 Westwood"));
    assert(t.insert("O'Reilly 34567     4.99 Westwood   "));
    assert(t.insert("   Hoang  12345 30.46 'Santa Monica' "));
    assert(t.insert("Patel\t67890\t142.75  \t \t\t  \tHollywood"));
    assert(!t.insert("Figueroa 54321 59.95"));
    vector<vector<string>> v;
    
    assert(t.select("customer = Courtney & customer = Patel | customer = Hoang", v) == 0);
    assert(v.size() == 1);
    assert(t.select("customer = Hoang | customer = Patel & customer = Courtney", v) == 0);
    assert(v.size() == 1);
    assert(t.select("customer < &", v) == 0);
    assert(v.size() == 0);
    assert(t.select("customer > &", v) == 0);
    assert(v.size() == 4);
    assert(t.select("customer < |", v) == 0);
    assert(v.size() == 4);
    assert(t.select("customer > |", v) == 0);
    assert(v.size() == 0);
    assert(t.select("customer < )", v) == 0);
    assert(v.size() == 0);
    assert(t.select("customer > )", v) == 0);
    assert(v.size() == 4);
    assert(t.select("customer < (", v) == 0);
    assert(v.size() == 0);
    assert(t.select("customer > (", v) == 0);
    assert(v.size() == 4);
    
    t.find("Patel", v);
    assert(v.size() == 2);
    vector<vector<string>> expected = {
        { "Patel", "12345", "42.54", "Westwood" },
        { "Patel", "67890", "142.75", "Hollywood" }
    };
    assert((v[0] == expected[0] && v[1] == expected[1]) ||
        (v[0] == expected[1] && v[1] == expected[0]));
    assert(t.select("customer = Courtney", v) == 0);
    assert(v.size() == 0);
    assert(t.select("customer = Courtney | price eq 2", v) == 0);
    assert(v.size() == 0);
    assert(t.select("customer = Courtney & customer = Courtney | customer = Courtney", v) == 0);
    assert(v.size() == 0);
    assert(t.select("customer = Patel & customer = Courtney ", v) == 0);
    assert(v.size() == 0);
    assert(t.select("customer = Patel | customer = Courtney ", v) == 0);
    assert(v.size() == 2);
    assert(t.select("customer = Patel | ", v) == -1);
    assert(v.size() == 0);
    assert(t.select("customer = Patel customer = Patel ", v) == -1);
    assert(v.size() == 0);
    assert(t.select("() ", v) == -1);
    assert(v.size() == 0);
    assert(t.select("customer = Patel ( customer = Patel | customer = Courtney )", v) == -1);
    assert(v.size() == 0);
    assert(t.select("customer = Patel ( | customer = Courtney )", v) == -1);
    assert(v.size() == 0);
    assert(t.select("( customer = Patel ( customer = Patel | customer = Courtney )", v) == -1);
    assert(v.size() == 0);
    assert(t.select("", v) == -1);
    assert(v.size() == 0);
    assert(t.select("( ( customer = Patel ) )", v) == 0);
    assert(v.size() == 2);
    assert(t.select("()", v) == -1);
    assert(v.size() == 0);
    assert(t.select("( ( ) ) customer = Patel ", v) == -1);
    assert(v.size() == 0);
    assert(t.select("( ( ) )", v) == -1);
    assert(v.size() == 0);
    assert(t.select("( ( customer = Patel ) ) | ( ( ( customer = Courtney ) ) )", v) == 0);
    assert(v.size() == 2);
    assert(t.select("( & )", v) == -1);
    assert(v.size() == 0);
    assert(t.select("     ", v) == -1);
    assert(v.size() == 0);
    assert(t.select("( ) ( )", v) == -1);
    assert(v.size() == 0);
    assert(t.select(") customer = Patel (", v) == -1);
    assert(v.size() == 0);
    assert(t.select("customer = Patel | ) customer = Courtney (", v) == -1);
    assert(v.size() == 0);

    vector<vector<string>> v1;
    assert(t.select("location < Westwood", v1) == 0);
    assert(v1.size() == 2);
    vector<vector<string>> expected1 = {
        { "Hoang", "12345", "30.46", "Santa Monica" },
        { "Patel", "67890", "142.75", "Hollywood" }
    };
    assert((v1[0] == expected1[0] && v1[1] == expected1[1]) ||
        (v1[0] == expected1[1] && v1[1] == expected1[0]));
    assert(t.select("     location     '<'  'Westwood'", v1) == 0);
    assert(v1.size() == 2);
    assert(t.select("'location' < 'Westwood'", v1) == 0);
    assert(v1.size() == 2);
    assert(t.select("customer != 'O''Reilly'", v1) == 0);
    assert(v1.size() == 3);
    assert(t.select("customer = Patel", v1) == 0);
    assert(v1.size() == 2);
    assert(t.select("product != 12345", v1) == 0);
    assert(v1.size() == 2);
    assert(t.select("location = 'Santa Monica'", v1) == 0);
    assert(v1.size() == 1);
    assert(t.select("product == 12345", v1) == 0);
    assert(v1.size() == 2);
    assert(t.select("product != 00012345", v1) == 0);
    assert(v1.size() == 4);
    assert(t.select("product EQ 12345", v1) == 0);
    assert(v1.size() == 2);
    assert(t.select("product EQ 00012345", v1) == 0);
    assert(v1.size() == 2);
    assert(t.select("product < 900", v1) == 0);
    assert(v1.size() == 4);
    assert(t.select("product GT 900 ", v1) == 0);
    assert(v1.size() == 4);
    assert(t.select("Hollywood = location", v1) == -1);
    assert(v1.size() == 0);
    assert(t.select("price is expensive", v1) == -1);
    assert(v1.size() == 0);
    assert(t.select("location = Santa Monica", v1) == -1);
    assert(v1.size() == 0);
    assert(t.select("price GT ''", v1) == -1);
    assert(v1.size() == 0);
    assert(t.select("price GT 100K", v1) == -1);
    assert(v1.size() == 0);

    vector<vector<string>> v2;
    assert(t.select("location != Westwood", v2) == 0);
    assert(v2.size() == 2);
    vector<vector<string>> expected2 = {
        { "Hoang", "12345", "30.46", "Santa Monica" },
        { "Patel", "67890", "142.75", "Hollywood" }
    };

    assert((v2[0] == expected2[0] && v2[1] == expected2[1]) ||
        (v2[0] == expected2[1] && v2[1] == expected2[0]));

    assert(t.select("(customer = Patel)", v) == -1);
    assert(v.size() == 0);
    assert(t.select("product = 12345 location != Westwood", v) == -1);
    assert(v.size() == 0);
    assert(t.select("location = ( Westwood | Hollywood )", v) == -1);
    assert(v.size() == 0);
    assert(t.select("customer = Patel", v) == 0);
    assert(v.size() == 2);
    assert(t.select("( customer = Patel ')'", v) == 0);
    assert(v.size() == 2);
    assert(t.select("( location == Westwood | location == Hollywood ) '&' price LT 100", v) == 0);
    assert(v.size() == 2);
    assert(t.select("price GE 20  &  location != Westwood", v) == 0);
    assert(v.size() == 2);
    cout << "Test 3 succeeded" << endl;
}

void test4() {
    vector<string> cols = { "item name", "price" };
    Table t("item name", cols);
    assert(t.good());
    assert(t.insert("'chocolate bar' 1.69"));
    assert(t.insert("coffee 7.99"));
    assert(t.insert("hummus 3.49"));
    vector<vector<string>> v;
    assert(t.select("price LT 5", v) == 0);
    assert(v.size() == 2);  // chocolate bar and hummus
    assert(t.select("price le 3.49", v) == 0);
    assert(v.size() == 2);
    assert(t.select("price lt 10", v) == 0);
    assert(v.size() == 3);
    assert(t.insert("pretzels 1.W9"));
    assert(t.select("price LT H", v) == -1);
    assert(v.size() == 0);
    assert(t.select("price LT 5", v) == 1);  // 1 because pretzels 1.W9
    assert(v.size() == 2);  // chocolate bar and hummus
    assert(t.insert("pretzels 1.0.9"));
    assert(t.select("price LT 5", v) == 2);  // 1 because pretzels 1.W9
    assert(v.size() == 2);  // chocolate bar and hummus
    assert(t.select("price LT ", v) == -1);  // 1 because pretzels 1.W9
    assert(v.size() == 0);  // chocolate bar and hummus
    assert(t.select("price LT ''", v) == -1);  // 1 because pretzels 1.W9
    assert(v.size() == 0);  // chocolate bar and hummus
    assert(t.select("price LT """, v) == -1);  // 1 because pretzels 1.W9
    assert(v.size() == 0);  // chocolate bar and hummus
    cout << "Test 4 succeeded" << endl;
}

void test5() {
    vector<string> cols = { "N", "Z" };
    Table t("Z", cols);
    assert(t.good());
    assert(t.insert("UCLA 90095"));
    assert(t.insert("Caltech 91125"));
    vector<vector<string>> v;
    t.find("90095", v);
    assert(v.size() == 1);
    assert(v[0][0] == "UCLA" && v[0][1] == "90095");
    assert(t.select("Z > 90210", v) == 0);
    assert(v.size() == 1);
    assert(v[0][0] == "Caltech" && v[0][1] == "91125");
    assert(t.select("Z > ''", v) == 0);
    assert(v.size() == 2);
    
    vector<string> uclacols = { "last name", "first name", "major", "UID", "GPA" };
    Table ucla("UID", uclacols);
    assert(ucla.good());
    assert(ucla.insert("Bruin Jose 'COG SCI' 304567890 3.4"));
    assert(ucla.insert("Bruin Josephine 'COM SCI' 605432109 3.8"));
    assert(ucla.insert("Trojan Tommy LOSING 000000000 1.7"));
    // Troy brought a wooden horse full of Greek soldiers inside the
    // city walls and lost the Trojan War.  How strange to look up to
    // gullible losers as role models.
    assert(ucla.select("GPA GE 3.2", v) == 0);
    assert(v.size() == 2);
    assert(v[0][0] == v[1][0] && v[0][1] != v[1][1]);
    assert(ucla.select("GPA nE 3.8", v) == 0);
    assert(v.size() == 2);
    vector<vector<string>> expected = {
        { "Bruin", "Jose", "COG SCI", "304567890", "3.4" },
        { "Trojan", "Tommy", "LOSING", "000000000", "1.7" }
    };
    assert((v[0] == expected[0] && v[1] == expected[1]) ||
        (v[0] == expected[1] && v[1] == expected[0]));

    assert(ucla.select("GPA lE 3.4", v) == 0);
    assert(v.size() == 2);
    vector<vector<string>> expected3 = {
        { "Bruin", "Jose", "COG SCI", "304567890", "3.4" },
        { "Trojan", "Tommy", "LOSING", "000000000", "1.7" }
    };
    assert((v[0] == expected3[0] && v[1] == expected3[1]) ||
        (v[0] == expected3[1] && v[1] == expected3[0]));

    vector<vector<string>> v1;
    assert(ucla.select("GPA EQ 1.7", v1) == 0);
    assert(v1.size() == 1);
    vector<vector<string>> expected1 = {
        { "Trojan", "Tommy", "LOSING", "000000000", "1.7" }
    };
    assert(v1[0] == expected1[0]);
    cout << "Test 5 succeeded" << endl;
}

void test6() {
    vector<string> cols = { "item name", "price" };
    Table t("item name", cols);
    assert(t.good());
    assert(t.insert("'chocolate bar' 1.69"));
    assert(t.insert("coffee 7.99"));
    assert(t.insert("hummus 3.49"));
    vector<vector<string>> v;
    assert(t.select("price LT 5", v) == 0);
    assert(v.size() == 2);  // chocolate bar and hummus
    assert(t.select("price LT 5 &", v) == -1);
    assert(v.size() == 0);
    assert(t.insert("pretzels 1.W9"));
    assert(t.select("price LT H", v) == -1);
    assert(v.size() == 0);
    assert(t.select("price ge H", v) == -1);
    assert(v.size() == 0);
    assert(t.select("price lE H", v) == -1);
    assert(v.size() == 0);
    assert(t.select("price Gt H", v) == -1);
    assert(v.size() == 0);
    assert(t.select("price LT 5", v) == 1);  // 1 because pretzels 1.W9
    assert(v.size() == 2);  // chocolate bar and hummus
    assert(t.insert("pretzels 1.y9"));
    assert(t.insert("pret 6.o9"));
    assert(t.insert("pret 6.u9"));
    assert(t.insert("pret 6.u9"));
    assert(t.select("price Le 5", v) == 5);  // this one
    assert(v.size() == 2);  // chocolate bar and hummus
    assert(t.select("price LT 5", v) == 5);  // this one
    assert(v.size() == 2);  // chocolate bar and hummus
    assert(t.select("price ge 5", v) == 5);  // this one
    assert(v.size() == 1);  // chocolate bar and hummus
    assert(t.select("price gT 5", v) == 5);  // this one
    assert(v.size() == 1);  // chocolate bar and hummus
    assert(t.select("price ne 5", v) == 5);  // this one
    assert(v.size() == 3);  // chocolate bar and hummus
    assert(t.select("price EQ 5", v) == 5);  // this one
    assert(v.size() == 0);  // chocolate bar and hummus
    assert(t.select("price eQ 7.99", v) == 5);  // this one
    assert(v.size() == 1);  // chocolate bar and hummus
    assert(t.select("price LT ", v) == -1);
    assert(v.size() == 0);
    assert(t.select("price  tru", v) == -1);
    assert(v.size() == 0);
    assert(t.select(" = tur", v) == -1);
    assert(v.size() == 0);
    assert(t.select("price LT 45 345", v) == -1);
    assert(v.size() == 0);
    assert(t.select("price LT H tru", v) == -1);
    assert(v.size() == 0);
    cout << "Test 6 succeeded" << endl;
}

void test7() {
    vector<string> cols = { "customer", "product", "price", "" };
    Table t("customer", cols);
    assert(!t.good());            //should not be good table because of empty string column

    vector<string> cols1 = { "price", "product", "price", "customer" };
    Table t1("customer", cols1);
    assert(!t1.good());            //should not be good table because of duplicate string columns

    vector<string> cols2 = { "customer", "product", "price", "''" };
    Table t2("customer", cols2);
    assert(t2.good());            //should be good table because '' is the name of the column
    
    vector<string> cols3 = { "customer", "product", "price", "&" };
    Table t3("customer", cols3);
    assert(!t3.good());
    
    vector<string> cols4 = { "customer", "product", "price", "|" };
    Table t4("customer", cols4);
    assert(!t4.good());
    
    vector<string> cols5 = { "customer", "product", "price", "(" };
    Table t5("customer", cols5);
    assert(!t5.good());
    
    vector<string> cols6 = { "customer", "product", "price", ")" };
    Table t6("customer", cols6);
    assert(!t6.good());
    assert(!t6.insert("Patel 12345 42.54 Westwood"));
    vector<vector<string>> v;
    t.find("Patel", v);
    assert(v.size() == 0);
    assert(t.select("location < Westwood", v) == -1);
    assert(v.size() == 0);
    cout << "Test 7 succeeded" << endl;
}

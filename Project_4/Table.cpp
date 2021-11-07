#include "Table.h"
#include <iostream>
#include <vector>
#include <cctype>
#include <stack>
#include <cstdlib>
using namespace std;

class StringParser
{
  public:
    StringParser(std::string text = "")
    {
        setString(text);
    }

    void setString(std::string text)
    {
        m_text = text;
        m_start = 0;
    }

    bool getNextField(std::string& field);

  private:
    std::string m_text;
    size_t m_start;
};

bool StringParser::getNextField(std::string& fieldText)
{
    m_start = m_text.find_first_not_of(" \t\r\n", m_start);
    if (m_start == std::string::npos)
    {
        m_start = m_text.size();
        fieldText = "";
        return false;
    }
    if (m_text[m_start] != '\'')
    {
        size_t end = m_text.find_first_of(" \t\r\n", m_start+1);
        fieldText = m_text.substr(m_start, end-m_start);
        m_start = end;
        return true;
    }
    fieldText = "";
    for (;;)
    {
        m_start++;
        size_t end = m_text.find('\'', m_start);
        fieldText += m_text.substr(m_start, end-m_start);
        m_start = (end != std::string::npos ? end+1 : m_text.size());
        if (m_start == m_text.size()  ||  m_text[m_start] != '\'')
            break;
        fieldText += '\'';
    }
    return true;
}

Table::Table(std::string keyColumn, const std::vector<std::string>& columns) {
    m_cols = columns.size();
    
    // check if columns are empty - return if it is
    if (m_cols == 0) {
        m_good = false;
        return;
    }
    
    // check for empty strings, &, |, (, ) in columns - return if so
    for (int i = 0; i < m_cols; i++) {
        if (columns[i] == "" || columns[i] == "&" || columns[i] == "|" || columns[i] == "(" || columns[i] == ")") {
            m_good = false;
            return;
        }
    }
    
    // check for duplicate strings in columns - return if so
    for (int i = 0; i < m_cols; i++) {
        for (int j = i+1; j < m_cols; j++) {
            if (columns[i] == columns[j]) {
                m_good = false;
                return;
            }
        }
    }
    
    // check for keyColumn in columns - return if we don't find it
    for (int i = 0; i < m_cols; i++) {
        if (columns[i] == keyColumn) {
            m_keyField = i;
            break;
        }
        if (i == m_cols-1) {
            m_good = false;
            return;
        }
    }
    
    // create a vector of column names
    for (int i = 0; i < m_cols; i++) {
        m_colNames.push_back(columns[i]);
    }
    
    // create empty BST
    m_root = nullptr;
    
    // good table
    m_good = true;
}

Table::~Table() {
    // return if the table isn't good
    if (good() == false) return;
    
    deleteHelper(m_root);
}

void Table::deleteHelper(Node* root) {
    // return if the table isn't good or the BST is empty
    if (good() == false) return;
    if (root == nullptr) return;
    
    // go through left and right subtrees and delete them first
    if (root->left != nullptr) deleteHelper(root->left);
    if (root->right != nullptr) deleteHelper(root->right);
    
    // then delete current node
    delete root;
}

bool Table::good() const {
    return m_good;
}

bool Table::insert(const std::string& recordString) {
    // return if the table isn't good
    if (good() == false) return false;
    
    // prepare to parse input string
    vector<string> v;
    StringParser parser(recordString);
    string s;
    
    // parse the string and push back into the vector
    // if we don't have enough data members for the number of columns, return false
    // if we have more data members than columns, return false
    for (int i = 0; i < m_cols; i++) {
        if (parser.getNextField(s) == false) return false;
        v.push_back(s);
    }
    if (parser.getNextField(s) == true) return false;
    
    // insert into BST
    insertHelper(m_root, v);
    
    return true;
}

void Table::insertHelper(Node*& root, const std::vector<std::string>& v) {
    // return if the table is not good
    if (good() == false) return;
    
    // if our BST is empty
    if (root == nullptr) {
        // create a new node, fill vector with table values, set child ptrs to nullptr
        Node* newGuy = new Node;
        for (int i = 0; i < m_cols; i++) {
            newGuy->m_vector.push_back(v[i]);
        }
        newGuy->left = nullptr;
        newGuy->right = nullptr;
        // set our BST root to the new node
        root = newGuy;
    }
    
    // organize BST by values for the key column so lookup for the key column is fast
    
    // put duplicates and lesser values to the left
    else if (v[m_keyField] <= root->m_vector[m_keyField]) {
        // if our current node has a null left child
        if (root->left == nullptr) {
            // create a new node, fill vector with table values, set child ptrs to nullptr
            Node* newGuy = new Node;
            for (int i = 0; i < m_cols; i++) {
                newGuy->m_vector.push_back(v[i]);
            }
            newGuy->left = nullptr;
            newGuy->right = nullptr;
            // set our current node's left child to the new node
            root->left = newGuy;
        }
        // otherwise keep looking for a place to insert
        else {
            insertHelper(root->left, v);
        }
    }
    
    // put greater values to the right
    else if (v[m_keyField] > root->m_vector[m_keyField]) {
        // if our current node has a null right child
        if (root->right == nullptr) {
            // create a new node, fill vector with table values, set child ptrs to nullptr
            Node* newGuy = new Node;
            for (int i = 0; i < m_cols; i++) {
                newGuy->m_vector.push_back(v[i]);
            }
            newGuy->left = nullptr;
            newGuy->right = nullptr;
            // set our current node's right child to the new node
            root->right = newGuy;
        }
        // otherwise keep looking for a place to insert
        else {
            insertHelper(root->right, v);
        }
    }
}

void Table::find(std::string key, std::vector<std::vector<std::string>>& records) const {
    // clear records vector
    records.clear();
    
    // return if the table isn't good
    if (good() == false) return;
    
    findHelper(m_root, key, records);
}

void Table::findHelper(Node* root, std::string key, std::vector<std::vector<std::string>>& records) const {
    if (good() == false) return;
    if (root == nullptr) return;
    // duplicates to the left
    else if (key <= root->m_vector[m_keyField]) {
        if (key == root->m_vector[m_keyField]) {
            records.push_back(root->m_vector);
        }
        return findHelper(root->left, key, records);
    }
    else if (key > root->m_vector[m_keyField]) {
        return findHelper(root->right, key, records);
    }
}

int Table::select(std::string query, std::vector<std::vector<std::string>>& records) const {
    // clear the records vector
    records.clear();
    
    // return if the table isn't good
    if (good() == false) return -1;
    
    // prepare to parse the input query
    vector<string> v;
    StringParser parser(query);
    string s;
    
    // push back values from input query into a vector
    while (true) {
        if (parser.getNextField(s) == true) {
            v.push_back(s);
        }
        else {
            break;
        }
    }
    // if the size of our vector isn't big enough for one comparison - too small so return
    if (v.size() < 3) {
        return -1;
    }
    
    // keep track of return value
    // create a vector to switch from infix => postfix
    // create a stack to hold operators while we switch from infix => postfix
    int returnValue = 0;
    vector<vector<vector<string>>> postfixV;
    stack<string> sta;
    
    // loop through our vector to convert from infix => postfix
    for (int i = 0; i < v.size();) {
        // if the current value is a |
        if (v[i] == "|") {
            // while the stack isn't empty and the top isn't (
            while (!sta.empty() && sta.top() != "(") {
                // create a 2D vector containing the top of the stack
                // push that into our 3D postfix vector
                // then pop the stack
                vector<string> tempV1;
                tempV1.push_back(sta.top());
                vector<vector<string>> tempV2;
                tempV2.push_back(tempV1);
                postfixV.push_back(tempV2);
                sta.pop();
            }
            // push our current value onto the stack and look at the next value
            sta.push(v[i]);
            i++;
        }
        // if the current value is an &
        else if (v[i] == "&") {
            // while the stack isn't empty and the top isn't ( or | (because | has lower precedence)
            while (!sta.empty() && sta.top() != "(" && sta.top() != "|") {
                // create a 2D vector containing the top of the stack
                // push that into our 3D postfix vector
                // then pop the stack
                vector<string> tempV1;
                tempV1.push_back(sta.top());
                vector<vector<string>> tempV2;
                tempV2.push_back(tempV1);
                postfixV.push_back(tempV2);
                sta.pop();
            }
            // push our current value onto the stack and look at the next value
            sta.push(v[i]);
            i++;
        }
        // if the current value is an (
        else if (v[i] == "(") {
            // check what can't come before (
            if (i > 0) {
                if (!(v[i-1] == "|" || v[i-1] == "&" || v[i-1] == "(")) return -1;
            }
            // check what can't come after (
            if (i < v.size()-1) {
                if (v[i+1] == "|" || v[i+1] == "&" || v[i+1] == ")") return -1;
            }
            // cant end with a (
            if (i == v.size()-1) {
                return -1;
            }
            // push our current value onto the stack and look at the next value
            sta.push(v[i]);
            i++;
        }
        // if the current value is a )
        else if (v[i] == ")") {
            // cant start with a )
            if (i == 0) {
                return -1;
            }
            // check what can't come before )
            if (i > 0) {
                if (v[i-1] == "|" || v[i-1] == "&" || v[i-1] == "(") return -1;
            }
            // check what can't come after )
            if (i < v.size()-1) {
                if (!(v[i+1] == "|" || v[i+1] == "&" || v[i+1] == ")")) return -1;
            }
            // while the stack isn't empty and the top isn't (
            while (!sta.empty() && sta.top() != "(") {
                // create a 2D vector containing the top of the stack
                // push that into our 3D postfix vector
                // then pop the stack
                vector<string> tempV1;
                tempV1.push_back(sta.top());
                vector<vector<string>> tempV2;
                tempV2.push_back(tempV1);
                postfixV.push_back(tempV2);
                sta.pop();
            }
            // pop the stack (which has a "(") and look at the next value
            sta.pop();
            i++;
        }
        // otherwise, it's likely a comparison
        else {
            // loop through the number of columns and check if the current value is a column
            int colToCompare = -1;
            for (int j = 0; j < m_colNames.size(); j++) {
                if (v[i] == m_colNames[j]) {
                    colToCompare = j;
                    break;
                }
            }
            // if the current value is not a column, return
            if (colToCompare == -1) return -1;
            
            // if we don't have space for the other 2 members of a comparison (column operator value), return
            if (i+2 >= v.size()) return -1;
            
            // create a 2D temprecords vector to use in our helper function
            vector<vector<string>> tempRecords;
            
            // enter our comparison helper function
            // if it returns invalid, return
            if (selectThree(v, i, tempRecords, colToCompare, returnValue) == -1) return -1;
            
            // push values from tempRecords into our 3D vector
            postfixV.push_back(tempRecords);
            
            // increment by 3 (since a comparison takes up 3 slots) to look at next section of the vector
            i += 3;
        }
    }
    // if the stack isn't empty
    while (!sta.empty()) {
        // create a 2D vector containing the top of the stack
        // push that into our 3D postfix vector
        // then pop the stack
        vector<string> tempV1;
        tempV1.push_back(sta.top());
        vector<vector<string>> tempV2;
        tempV2.push_back(tempV1);
        postfixV.push_back(tempV2);
        sta.pop();
    }
    
    // now that we have a postfix 3D vector, do comparisons
    for (size_t i = 0; i < postfixV.size();) {
        // check if entry in array isnt empty
        if (!postfixV.at(i).empty()) {
            // if the current value is & or |
            if (postfixV[i][0][0] == "&" || postfixV[i][0][0] == "|") {
                // if there aren't 2 vectors to compare before, return
                if (!(i >= 2)) return -1;
                // if either of the 2 vectors before it have & or |, return
                if (!postfixV[i-1].empty()) {
                    if (postfixV[i-1][0][0] == "&" || postfixV[i-1][0][0] == "|") return -1;
                }
                if (!postfixV[i-2].empty()) {
                    if (postfixV[i-2][0][0] == "&" || postfixV[i-2][0][0] == "|") return -1;
                }
            }
            // if the current value is an &
            if (postfixV[i][0][0] == "&") {
                // create a temp 2D vector and push back vectors from the two 2D vectors before
                // only push back duplicates
                vector<vector<string>> tempV;
                if (!postfixV[i-1].empty() && !postfixV[i-2].empty()) {
                    for (int j = 0; j < postfixV[i-1].size(); j++) {
                        for (int k = 0; k < postfixV[i-2].size(); k++) {
                            if (postfixV[i-1][j] == postfixV[i-2][k]) {
                                tempV.push_back(postfixV[i-1][j]);
                            }
                        }
                    }
                }
                // erase the two vector entries before
                postfixV.erase(postfixV.begin()+i-1);
                postfixV.erase(postfixV.begin()+i-2);
                // set what was & to our temp 2D vector
                postfixV[i-2] = tempV;
                // decrease i because we want to go to the next entry but we just lost 2 vector entries
                i--;
            }
            // if the current value is a |
            else if (postfixV[i][0][0] == "|") {
                // create a temp 2D vector and push back vectors from the two 2D vectors before
                // don't push back duplicates
                vector<vector<string>> tempV;
                if (!postfixV[i-1].empty() && postfixV[i-2].empty()) {
                    for (int j = 0; j < postfixV[i-1].size(); j++) {
                        tempV.push_back(postfixV[i-1][j]);
                    }
                }
                else if (postfixV[i-1].empty() && !postfixV[i-2].empty()) {
                    for (int k = 0; k < postfixV[i-2].size(); k++) {
                        tempV.push_back(postfixV[i-2][k]);
                    }
                }
                else if (!postfixV[i-1].empty() && !postfixV[i-2].empty()) {
                    for (int j = 0; j < postfixV[i-1].size(); j++) {
                        tempV.push_back(postfixV[i-1][j]);
                    }
                    for (int j = 0; j < postfixV[i-1].size(); j++) {
                        for (int k = 0; k < postfixV[i-2].size(); k++) {
                            if (postfixV[i-2][k] != postfixV[i-1][j]) {
                                tempV.push_back(postfixV[i-2][k]);
                            }
                        }
                    }
                }
                // erase the two vector entries before
                postfixV.erase(postfixV.begin()+i-1);
                postfixV.erase(postfixV.begin()+i-2);
                // set what was & to our temp 2D vector
                postfixV[i-2] = tempV;
                // decrease i because we want to go to the next entry but we just lost 2 vector entries
                i--;
            }
            else {
                i++;
            }
        }
        // check if entry in array is empty and increment
        else i++;
    }
    
    // if our postfix is empty, return our returnvalue
    if (postfixV.size() == 0) return returnValue;
    
    // if our postfix didn't evaluate correctly, return -1 because it must've been pooly formed
    if (postfixV.size() != 1) return -1;
    
    // if our postfix evaluated correctly, set records to our postfix result and return our returnvalue
    if (!postfixV.at(0).empty()) {
        records = postfixV.at(0);
    }
    return returnValue;
}

int Table::selectThree(std::vector<std::string>& v, int index, std::vector<std::vector<std::string>>& tempRecords, int colToCompare, int& returnValue) const {
    // return if the table isn't good
    if (good() == false) return -1;
    
    // make the comparison operator all uppercase
    // ex: eq, Eq, eQ => EQ
    string str;
    for (int i = 0; i < v[index+1].size(); i++) {
        str += toupper(v[index+1].at(i));
    }
    v[index+1] = str;

    // if the comparison operator is invalid, clear our temprecords vector and return
    if (v[index+1] != "<" && v[index+1] != "<=" && v[index+1] != ">" && v[index+1] != ">=" && v[index+1] != "!=" && v[index+1] != "==" && v[index+1] != "=" && v[index+1] != "LT" && v[index+1] != "LE" && v[index+1] != "GT" && v[index+1] != "GE" && v[index+1] != "NE" && v[index+1] != "EQ") {
        tempRecords.clear();
        return -1;
    }

    // if we're doing a numerical comparison
    if (v[index+1] == "LT" || v[index+1] == "LE" || v[index+1] == "GT" || v[index+1] == "GE" || v[index+1] == "NE" || v[index+1] == "EQ") {
        // if we're trying to compare against the empty string, clear our temprecords vector and return
        if (v[index+2] == "") {
            tempRecords.clear();
            return -1;
        }
        // check if the value we're comparing against is a double
        // make sure each value is a digit or a .
        // make sure we only have 1 . per number
        int periodCount = 0;
        for (int i = 0; i < v[index+2].size(); i++) {
            if (v[index+2].at(i) == '.' && periodCount == 0) periodCount++;
            else if (v[index+2].at(i) == '.' && periodCount != 0) {
                // if we have more than 1 . per number, clear our temprecords vector and return
                tempRecords.clear();
                return -1;
            }
            else if (!isdigit(v[index+2].at(i)) && v[index+2].at(i) != '.') {
                // if we have a value that isn't a digit or a ., clear our temprecords vector and return
                tempRecords.clear();
                return -1;
            }
        }
    }

    // helper function to traverse BST
    return selectHelper(m_root, v, index, tempRecords, colToCompare, returnValue);
}

int Table::selectHelper(Node* root, const std::vector<std::string>& v, int index, std::vector<std::vector<std::string>>& tempRecords, int colToCompare, int& returnValue) const {
    // return if the table isn't good or the root is nullptr
    if (good() == false) return -1;
    if (root == nullptr) return 0;
    
    // perform string comparisons on the corresponding value of the node's vector
    // if the string comparison is true, push the whole vector back into our 2D tempRecord vector
    if (v[index+1] == "<" && root->m_vector[colToCompare] < v[index+2]) tempRecords.push_back(root->m_vector);
    else if (v[index+1] == "<=" && root->m_vector[colToCompare] <= v[index+2]) tempRecords.push_back(root->m_vector);
    else if (v[index+1] == ">" && root->m_vector[colToCompare] > v[index+2]) tempRecords.push_back(root->m_vector);
    else if (v[index+1] == ">=" && root->m_vector[colToCompare] >= v[index+2]) tempRecords.push_back(root->m_vector);
    else if (v[index+1] == "!=" && root->m_vector[colToCompare] != v[index+2]) tempRecords.push_back(root->m_vector);
    else if (v[index+1] == "==" && root->m_vector[colToCompare] == v[index+2]) tempRecords.push_back(root->m_vector);
    else if (v[index+1] == "=" && root->m_vector[colToCompare] == v[index+2]) tempRecords.push_back(root->m_vector);
    
    // OR, if we're doing numerical comparisons
    else if (v[index+1] == "LT" || v[index+1] == "LE" || v[index+1] == "GT" || v[index+1] == "GE" || v[index+1] == "NE" || v[index+1] == "EQ") {
        // check if the corresponding value of the node's vector is a double
        // make sure each value is a digit or a .
        // make sure we only have 1 . per number
        int periodCount = 0;
        for (int i = 0; i < root->m_vector[colToCompare].size(); i++) {
            if (root->m_vector[colToCompare].at(i) == '.' && periodCount == 0) periodCount++;
            else if (root->m_vector[colToCompare].at(i) == '.' && periodCount != 0) {
                // if we have more than 1 . per number, increment return value and check the left and right subtrees
                returnValue++;
                return selectHelper(root->left, v, index, tempRecords, colToCompare, returnValue) + selectHelper(root->right, v, index, tempRecords, colToCompare, returnValue);
            }
            else if (!isdigit(root->m_vector[colToCompare].at(i)) && root->m_vector[colToCompare].at(i) != '.') {
                // if we have a value that isn't a digit or a ., increment return value and check the left and right subtrees
                returnValue++;
                return selectHelper(root->left, v, index, tempRecords, colToCompare, returnValue) + selectHelper(root->right, v, index, tempRecords, colToCompare, returnValue);
            }
        }
    }
    // perform numerical comparisons on the corresponding value of the node's vector
    // if the numerical comparison is true, push the whole vector back into our 2D tempRecord vector
    if (v[index+1] == "LT" && stod(root->m_vector[colToCompare]) < stod(v[index+2])) tempRecords.push_back(root->m_vector);
    else if (v[index+1] == "LE" && stod(root->m_vector[colToCompare]) <= stod(v[index+2])) tempRecords.push_back(root->m_vector);
    else if (v[index+1] == "GT" && stod(root->m_vector[colToCompare]) > stod(v[index+2])) tempRecords.push_back(root->m_vector);
    else if (v[index+1] == "GE" && stod(root->m_vector[colToCompare]) >= stod(v[index+2])) tempRecords.push_back(root->m_vector);
    else if (v[index+1] == "NE" && stod(root->m_vector[colToCompare]) != stod(v[index+2])) tempRecords.push_back(root->m_vector);
    else if (v[index+1] == "EQ" && stod(root->m_vector[colToCompare]) == stod(v[index+2])) tempRecords.push_back(root->m_vector);
    
    // check the left and right subtrees
    return selectHelper(root->left, v, index, tempRecords, colToCompare, returnValue) + selectHelper(root->right, v, index, tempRecords, colToCompare, returnValue);
}

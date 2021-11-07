#ifndef Database_hpp
#define Database_hpp

#include <iostream>
#include <string>
#include <vector>

class Table
{
public:
    Table(std::string keyColumn, const std::vector<std::string>& columns);
    ~Table();
    bool good() const;
    bool insert(const std::string& recordString);
    void find(std::string key, std::vector<std::vector<std::string>>& records) const;
    int select(std::string query, std::vector<std::vector<std::string>>& records) const;
    
    // We prevent a Table object from being copied or assigned by
    // making the copy constructor and assignment operator unavailable.
    Table(const Table&) = delete;
    Table& operator=(const Table&) = delete;
private:
    struct Node {
        Node* left;
        Node* right;
        std::vector<std::string> m_vector;
    };
    bool m_good;
    int m_keyField;
    int m_cols;
    Node* m_root;
    std::vector<std::string> m_colNames;
    void insertHelper(Node*& root, const std::vector<std::string>& v);
    void deleteHelper(Node* root);
    void findHelper(Node* root, std::string key, std::vector<std::vector<std::string>>& records) const;
    int selectThree(std::vector<std::string>& v, int index, std::vector<std::vector<std::string>>& tempRecords, int colToCompare, int& returnValue) const;
    int selectHelper(Node* root, const std::vector<std::string>& v, int index, std::vector<std::vector<std::string>>& tempRecords, int colToCompare, int& returnValue) const;
};

#endif /* Database_hpp */

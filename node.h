#ifndef NODE_H
#define NODE_H
#include <iostream>

template <typename T>
class Node
{
public:
    Node();
    Node(int data);
    int GetValue();
    void SetValue(int m_data);

Node* insert(Node* root, T m_data);
    void Delete(Node* root,int data);
    void preOrder(Node* root);
    void postOrder(Node* root);

    void PrintTree(Node* root);

    void PrintSubtree(Node* root, const std::string& prefix);

private:
    int m_data;
    Node* m_vsub;
    Node* m_hsub;
    Node* m_father;
};

// INLINE
#include "node.cpp"

#endif // NODE_H

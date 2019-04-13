#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "ItemType.h"
struct Node{
    ItemType key;
    Node *left;
    Node *right;
};
class BinaryTree{
public:
    /*
     Pre-Condition: none
     Post-Conditon: tree is initialized
     **/
    BinaryTree();
    /*
     Pre-Condition: tree has been initialzied
     Post-Conditon: all nodes are freed, root points to null length set to 0
     **/
    ~BinaryTree();
    /*
     Pre-Condition: tree and parameter tree has been initialized
     Post-Conditon: 
     **/
    void clearAll(Node* tree);
    /*
     Pre-Condition:
     Post-Conditon:
     **/
    void insert(ItemType &key);
    /*
     Pre-Condition:
     Post-Conditon:
     **/
    void deleteItem(ItemType &key);
    /*
     Pre-Condition:
     Post-Conditon:
     **/
    void retrieve(ItemType &item, bool &found);
    /*
     Pre-Condition:
     Post-Conditon:
     **/
    void getItem(Node* node, ItemType& item, bool&found);
    /*
     Pre-Condition:
     Post-Conditon:
     **/
    void putItem(ItemType item, Node*& node, bool& found);
    /*
     Pre-Condition:
     Post-Conditon:
     **/
    void preOrder();
    /*
     Pre-Condition:
     Post-Conditon:
     **/
    void inOrder();
    /*
     Pre-Condition:
     Post-Conditon:
     **/
    void printInOrder(Node* root);
    /*
     Pre-Condition:
     Post-Conditon:
     **/
    void printPreOrder(Node* root);
    /*
     Pre-Condition:
     Post-Conditon:
     **/
    void printPostOrder(Node* root);
    /*
     Pre-Condition:
     Post-Conditon:
     **/
    void getPredecessor(Node*& node, ItemType& data);
    /*
     Pre-Condition:
     Post-Conditon:
     **/
    void DeleteNode(Node*& tree);
    /*
     Pre-Condition:
     Post-Conditon:
     **/
    void Delete(Node*& root, ItemType& item);
    /*
     Pre-Condition:
     Post-Conditon:
     **/
    void postOrder();
    /*
     Pre-Condition:
     Post-Conditon:
     **/
    int getLength() const;
    /*
     Pre-Condition:
     Post-Conditon:
     **/
    int findLevel(ItemType& item, Node*& tree, int level);
    /*
     Pre-Condition:
     Post-Conditon:
     **/
    void printSameLevelNonSiblings(Node*& tree, ItemType& item, int level, bool&found);
    /*
     Pre-Condition:
     Post-Conditon:
     **/
    void getSameLevelNonSiblings(ItemType &key);
    
    Node *root;
private:
    int length;
};
#endif

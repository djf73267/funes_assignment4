//BinaryTree.cpp
#include "BinaryTree.h"
#include <cstdlib>
#include <iostream>
#include <math.h>
using namespace std;
/*
 Parameter: none
 Objective: to create a default constructor for the Binary Tree
 **/
BinaryTree::BinaryTree(){
    length = 0;
    root = NULL;
}
/*
 Parameter: none
 Objective: a recursive loop that calls Destroy
 **/
BinaryTree::~BinaryTree(){
    Destroy(root);
}
/*
 Parameter: Node* tree
 Objective: the recursive method that goes through the tree deleting each node
 **/
void BinaryTree::Destroy(Node *tree){
    if(tree == NULL)
        return;
    if(tree->left !=NULL)
        Destroy(tree->left);
    if(tree->right !=NULL)
        Destroy(tree->right);
    delete tree;
    return;
}
/*
 Parameter: ItemType &key
 Objective: inserts item within the tree as a leaf based on the node that is predessceor
 
 **/
void BinaryTree::insert(ItemType &key){
    bool found = false;
    putItem(key, root, found);
    if(found)
        length++;
}
/*
 Parameter: ItemType item, Node*& node, bool& found
 Objective: recusively calls putItem until it finds a spot where it can be put
 
 **/
void BinaryTree::putItem(ItemType item, Node*& node, bool& found){
    if(node==NULL){//base case
        node = new Node;
        node->right = NULL;
        node->left = NULL;
        node->key = item;
        found = true;
    }
    else if(item.getValue() < node->key.getValue()){
        putItem(item, node->left, found);
    }
    else if(item.getValue() > node->key.getValue()){
        putItem(item, node->right, found);
    } else{
        cout << "item already in tree." << endl;
        return;
        
    }
}
/**
 Parameter: ItemType &key
 Objective: deletes item within the tree and connects the child if any to the predessecor node
 
 **/
void BinaryTree::deleteItem(ItemType &key){
    bool found = false;
    retrieve(key, found);
    if(found){
        Delete(root, key);
        length--;
        
    }
}
/*
 Parameter: Node*& root, ItemType& item
 Objective: recursive call to delete items based on the item's given value
 **/
void BinaryTree::Delete(Node*& root, ItemType& item){
    if(item.getValue()<root->key.getValue())
        Delete(root->left, item);
    else if(item.getValue()>root->key.getValue())
        Delete(root->right, item);
    else
        DeleteNode(root);
}
/*
 Parameter: Node*& tree
 Objective: will create a temporary pointer that will establish the original tree value and tree will copy the next value and temp is deleted
 **/
void BinaryTree::DeleteNode(Node*& tree){
    ItemType data;
    Node* tempPtr;
    tempPtr = tree;
    if(tree->left==NULL){
        tree = tree->right;
        delete tempPtr;
    }
    else if(tree->right == NULL){
        tree = tree->left;
        delete tempPtr;
    }
    else{
        getPredecessor(tree->left, data);
        tree->key = data;
        Delete(tree->left, data);
    }
}
/*
 Parameter: Node*& node, ItemType& data)
 Objective: will retrieve the predecessor node used in the delete node method
 **/
void BinaryTree::getPredecessor(Node*& node, ItemType& data){
    while(node->right != NULL){
        node = node->right;
    }
    data = node->key;
}
/*
 Parameter:ItemType &key
 Objective: parameter is taken to compare with the recusive method if the value has non siblings on the same level
 **/
void BinaryTree::getSameLevelNonSiblings(ItemType &key){
    bool found = false;
  
    int val2 = findLevel(key, root, 0);
    printSameLevelNonSiblings(root, key, val2+1, found);
    if(!found)
    cout << "No same level non siblings found" << endl;
}
/*
 Parameter: Node*& tree, ItemType& item, int level, bool &found)
 Objective: a recusive call to determine if there are same level non siblings
 **/
void BinaryTree::printSameLevelNonSiblings(Node*& tree, ItemType& item, int level, bool &found){
    if(level < 2 || tree == NULL){
        return;
    }
    if(level ==2){
        if(tree->left == NULL)
            return;
        if(tree->right == NULL)
            return;
        if(tree->left->key.getValue() == item.getValue() || tree->right->key.getValue() == item.getValue())
            return;
        if(tree->left != NULL && tree->left->key.getValue() != item.getValue()){
            cout << tree->left->key.getValue() << " ";
            found = true;
        }
        if(tree->right != NULL && tree->right->key.getValue() != item.getValue()){
            cout << tree->right->key.getValue() << " ";
            found=true;
        }
    }
    else if(level >2){
        printSameLevelNonSiblings(tree->left, item, level-1, found);
        printSameLevelNonSiblings(tree->right, item, level-1, found);
    }
}
/*
 Parameter:
 Objective:
 **/
int BinaryTree::findLevel(ItemType& item, Node*& tree, int level){
    if(tree == NULL){
        return 0;
    }
    if(tree->key.getValue() == item.getValue())
        return level;
    int traverseLevel = findLevel(item, tree->left, level+1);
    if(traverseLevel !=0)
        return traverseLevel;
    else
        return findLevel(item, tree->right, level+1);
}
/**
 Parameter: ItemType &item, bool &found
 Objective: calls recusive method and establishes if the item is within the tree or not
 
 **/
void BinaryTree::retrieve(ItemType &item, bool &found) {
    getItem(root, item, found);
    if(found)
        cout << "Item found in tree." << endl;
    else
        cout << "Item not in tree." << endl;
}
/*
 Parameter: Node* node, ItemType& item, bool&found
 Objective: the recusive method that searches for item until it is found or not
 **/
void BinaryTree::getItem(Node* node, ItemType& item, bool&found) {
    if(node==NULL) //base case
        found = false;
    else if(item.getValue()< node->key.getValue())
        getItem(node->left, item, found);
    else if(item.getValue()>node->key.getValue())
        getItem(node->right, item, found);
    else { //another case where solution can be found
        item = node->key;
        found = true;
    }
}
/**
 Parameter: none
 Objective: prints the tree in pre o rder
 
 **/
void BinaryTree::preOrder(){
    printPreOrder(root);
}
void BinaryTree::printPreOrder(Node* root){
    if(root != NULL){
        cout << root->key.getValue() << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}
/**
 Parameter: none
 Objective: prints the tree in "in order"
 
 **/
void BinaryTree::inOrder(){
    printInOrder(root);
}
void BinaryTree::printInOrder(Node* root){
    if(root !=NULL){
        printInOrder(root->left);
        cout << root->key.getValue() << " ";
        printInOrder(root->right);
    }
}
/**
 Parameter: none
 Objective: prints the tree inpost order
 
 **/

void BinaryTree::postOrder(){
    printPostOrder(root);
}
void BinaryTree::printPostOrder(Node* root){
    if(root!=NULL){
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->key.getValue() << " ";
    }
}
/**
 Parameter: none
 Objective: returns length of the tree assuming this means height
 
 **/
int BinaryTree::getLength() const{
    return length;
}

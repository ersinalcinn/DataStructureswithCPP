/**
* @file Organ.cpp
* @description Organ
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @author Ersin Alçin - ersin.alcin@ogr.sakarya.edu.tr
*/
#include "Organ.hpp"
Organ::Organ(){
    this->root = NULL;
    this->postOrderIndex = 0;
}
void Organ::add(Tissue *&root, Tissue *tissue)
{
    if(root == NULL){
        root = tissue;
    }
    else if (tissue->middle < root->middle){
        add(root->left, tissue);
    }
    else if (tissue->middle == root->middle){
        add(root->left, tissue);
    }
    else if (tissue->middle > root->middle){
        add(root->right, tissue);
    }
}
void Organ::add(Tissue *tissue){
    add(root,tissue);
}
bool Organ::checkBalance(Tissue *root){
    if(root==NULL){return true;}
    int diff= abs(height(root->left) - height(root->right));
    if (diff>1){return false;}
    else{return (checkBalance(root->left) && checkBalance(root->right));}
}
bool Organ::checkBalance(){
    return(checkBalance(root));
}
int Organ::height(Tissue *root){
    if(root == NULL){return 0;}
    return(max(height(root->left), height(root->right)) + 1);
}
int Organ::returnRootval()
{
    return root->middle;
}
Tissue** Organ::mutants(){
    Tissue** mutants = new Tissue *[20];
    postOrder(root,mutants);
    this->postOrderIndex = 0;
    return (mutants);
}
void Organ::postOrder(Tissue *current,Tissue** mutants)
{
    if (current != NULL){
        postOrder(current->left,mutants);
        postOrder(current->right,mutants);
        mutants[postOrderIndex++] = current;
    }
}

void Organ::clear(Tissue *root)
{
    if (root != NULL){
        clear(root->left);
        clear(root->right);
        delete root;
    }
}

void Organ::clear()
{
    clear(root);
}

Organ::~Organ(){
    clear(root);
}
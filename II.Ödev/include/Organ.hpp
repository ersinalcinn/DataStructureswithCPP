/**
* @file Organ.hpp
* @description Organ
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @author Ersin Alçin - ersin.alcin@ogr.sakarya.edu.tr
*/
#ifndef Organ_hpp
#define Organ_hpp
#include <iostream>
#include "Tissue.hpp"
using namespace std;
class Organ{
    private:
    Tissue *root;
    int postOrderIndex;
    void    postOrder(Tissue *current,Tissue** mutants);
    bool    checkBalance(Tissue *root);
    void    add(Tissue *&root, Tissue *tissue);
    int     height(Tissue *root);
    void    clear(Tissue *root);
    public:
    Organ();
    ~Organ();
    void    add(Tissue *tissue);
    void    clear();
    bool    checkBalance();
    int    returnRootval();
    Tissue **mutants();
    
};
#endif
/**
* @file Tissue.hpp
* @description Doku
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @author Ersin Alçin - ersin.alcin@ogr.sakarya.edu.tr
*/
#ifndef Tissue_hpp
#define Tissue_hpp
#include <iostream>
#include "Cell.hpp"
using namespace std;
class Tissue{
    public:
    int size;
    int middle;
    Cell** cells;
    Tissue(int *nums, int size);
    ~Tissue();
    Tissue *right;
    Tissue *left;
};
#endif
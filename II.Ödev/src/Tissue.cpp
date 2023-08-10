/**
* @file Tissue.cpp
* @description Doku
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @author Ersin Alçin - ersin.alcin@ogr.sakarya.edu.tr
*/
#include "Tissue.hpp"
Tissue::Tissue(int *nums, int size){
    this->size = size;
    this->cells = new Cell *[size];
    int i = 0;
    while(i < size){
        int num = nums[i];
        Cell *cellToAdd = new Cell(num);
        this->cells[i] = cellToAdd;
        i++;
    }
    int middleIndex = (this->size - 1) / 2;
    this->middle = nums[middleIndex];
    this->right = NULL;
    this->left = NULL;
}

Tissue::~Tissue(){
     delete[] cells;
}
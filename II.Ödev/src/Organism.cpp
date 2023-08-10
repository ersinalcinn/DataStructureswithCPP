/**
* @file Organism.cpp
* @description Organizma
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @author Ersin Alçin - ersin.alcin@ogr.sakarya.edu.tr
*/
#include "Organism.hpp"

Organism::Organism(int size){
    this->systems = new System*[size];
    this->size = size;
}
Organism::~Organism(){
    for (int i = 0; i < size; i++)
    {
        delete systems[i];
    }
    delete systems;
}
/**
* @file Organism.hpp
* @description Organizma
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @author Ersin Alçin - ersin.alcin@ogr.sakarya.edu.tr
*/
#ifndef Organism_hpp
#define Organism_hpp
#include <iostream>
#include "System.hpp"
using namespace std;
class Organism{
    public:
    int size;
    System** systems;
    Organism(int size);
    ~Organism();
};
#endif
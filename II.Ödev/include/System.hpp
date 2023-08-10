/**
* @file System.hpp
* @description Sistem
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @author Ersin Alçin - ersin.alcin@ogr.sakarya.edu.tr
*/
#ifndef System_hpp
#define System_hpp
#include <iostream>
#include "Organ.hpp"
using namespace std;
class System{
    public:
    int index;
    Organ* organs[100];
    void add(Organ *organ);
    System();
    ~System();
};
#endif
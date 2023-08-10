/**
* @file System.cpp
* @description Sistem
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @author Ersin Alçin - ersin.alcin@ogr.sakarya.edu.tr
*/
#include "System.hpp"

System::System(){
    this->index = 0;
}
System::~System(){
    for (int i = 0; i < 100; i++)
    {
        delete organs[i];
    }
}
void System::add(Organ *organ){
    organs[index] = organ;
    index++;
}
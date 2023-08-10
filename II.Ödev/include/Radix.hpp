/**
* @file Radix.hpp
* @description Radix sort
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @author Ersin Alçin - ersin.alcin@ogr.sakarya.edu.tr
*/
#ifndef RADIX_HPP
#define RADIX_HPP

#include "Queue.hpp"
#include <cmath>

class Radix{
	private:	
		int* numbers;
		int length;
		Queue **queues;
		int maxStep;
		
		int MaxStepNumber();
		int power(int);
		int StepCount(int);
		int* QueueCurrentLengths();
	public:
		Radix(int*, int);
		int* Sort();
		~Radix();
};

#endif
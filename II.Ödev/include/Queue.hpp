/**
* @file Queue.hpp
* @description Kuyruk
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @author Ersin Alçin - ersin.alcin@ogr.sakarya.edu.tr
*/
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
using namespace std;

class Queue{
	private:
		int front;
		int back;
		int capacity;
		int length;

		int *items;
		
		void reserve(int newCapacity);
	public:
		Queue();
		void clear();
		int count() const;
		bool isEmpty() const;
		const int& peek();
		void enqueue(const int& item);
		void dequeue();
		~Queue();		
};
#endif
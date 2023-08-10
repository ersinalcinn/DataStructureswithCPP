/**
* @file SatirListesi.h
* @description Ba�l� listeye ait tan�mlamalar�n yap�ld��� dosya
* @course 1.��retim A Grubu
* @assignment �dev-1
* @date 23.11.2022
* @author Ersin Al�in - ersin.alcin@ogr.sakarya.edu.tr
*/
#include <iostream>

struct node_line {
	int data;
	node_line* next;

	node_line() {
		data = 0;
		next = NULL;
	}
};
class SatirListesi
{
public:
	node_line* InsertList(node_line*,int data);
	bool DeleteNode(node_line*, node_line*);
	float GetAvarage(node_line*);
	node_line* DeleteNode(node_line*, int);
	int gGetNodeNumber(node_line*);
	node_line* DeleteAllNodes(node_line*);
};


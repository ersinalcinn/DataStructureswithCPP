/**
* @file YoneticiListesi.h
* @description Baðlý listeye ait tanýmlamalarýn yapýldýðý dosya
* @course 1.Öðretim A Grubu
* @assignment Ödev-1
* @date 23.11.2022
* @author Ersin Alçin - ersin.alcin@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <vector>
#include "SatirListesi.h"
#include <iomanip>
#include <conio.h>
#include <string>
#include <ctime>

struct node_mng {
	float avarage;
	node_mng* next;
	node_mng* prev;
	node_line* root_child_list;
	int number_of_node_lise;

	node_mng() {
		avarage = 0;
		number_of_node_lise = 0;
		next = NULL;
		prev = NULL;

		root_child_list = NULL;
	}
};
class YoneticiListesi
{
private:
	SatirListesi* line_list;
	int current_display = 0;
	int current_node_number = 0;
	int current_selected_node = 0;
	int current_selectednode_child_selected = 0;
	int child_node_count = 0;

	bool press_first_k = false;
public:
	YoneticiListesi();
	~YoneticiListesi();
	node_mng* InsertList(node_mng*, std::vector<int>);
	node_mng* NewNoder(std::vector<int>);
	node_mng* ToShort(node_mng*,node_mng*);
	bool ToShortControl(node_mng*, node_mng*);
	void Processor(node_mng*);
	void WriteCurrentNodes(node_mng*,int);
	void WriterCurrentSelectedChildList(node_mng*, int);
	void SmallWriter(node_mng*, int);
	void SmallWriterChildList(node_line*,int, int);
	void ListInfo(node_mng*);
	node_mng* DeleteNode(node_mng*, int);
	node_mng* DeleteAllNodes(node_mng*);
};


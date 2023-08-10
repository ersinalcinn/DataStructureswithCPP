/**
* @file SatirListesi.cpp
* @description Baðlý listeye yönetimi. Ekleme,silme vb
* @course 1.Öðretim A Grubu
* @assignment Ödev-1
* @date 23.11.2022
* @author Ersin Alçin - ersin.alcin@ogr.sakarya.edu.tr
*/
#include "SatirListesi.h"

node_line * SatirListesi::InsertList(node_line* root,int data)
{
	// Kok dugum ise ilk dugumu ekle
	if (root == NULL) {
		root = new node_line();
		root->data = data;
		root->next = NULL;
		return root;
	}

	// sona kadar ilerler
	node_line* referance = NULL; // listenin son elemaný
	node_line* iter = root;
	do {
		referance = iter;
		iter = iter->next;
	} while (iter != NULL);
	referance->next = new node_line(); // ekleme iþlemi
	referance->next->next = NULL;
	referance->next->data = data;
	return root;
}

bool SatirListesi::DeleteNode(node_line* root,node_line * node)
{
	if (root == node) {
		delete node;
		root = NULL;
		return true; // silme baþarýlý
	}
	node_line* iter = root;
	while (iter->next!=NULL)
	{
		if (iter->next == node) {
			node_line* deleted = node;
			iter->next = node->next;
			delete node;
			return true;
		}
		iter = iter->next;
	}
	std::cout << "Silme basarisiz: Dugum yok\n";
	return false;
}

float SatirListesi::GetAvarage(node_line * root)
{
	float sum = 0.0;
	int count = 0;
	node_line* iter = root;
	if (root == NULL)
		return 0;
	do 
	{
		sum += iter->data;
		count++;
		iter = iter->next;
	} while ((iter != NULL));
	float avarage = sum / count;
	return avarage;
}

node_line* SatirListesi::DeleteNode(node_line * root, int index)
{
	node_line* iter = root;
	node_line* referance = NULL;
	int count = 0;
	while (iter->next != NULL)
	{
		if (count == index)
			break;
		count++;
		referance = iter;
		iter = iter->next;
	}
	if (iter == root) {
		node_line* temp = root;
		root = root->next;
		delete temp;
		return root;
	}
	node_line* temp = iter;
	referance->next = iter->next;
	delete temp;
	return root;
}

int SatirListesi::gGetNodeNumber(node_line* root)
{
	int number = 0;
	node_line* iter = root;
	while (iter!=NULL)
	{
		number++;
		iter = iter->next;
	}
	return number;
}

node_line * SatirListesi::DeleteAllNodes(node_line * root)
{
	node_line* iter = root;
	while (iter != NULL) {
		node_line* temp = iter;
		iter = iter->next;
		delete temp;
	}
	return NULL;
}

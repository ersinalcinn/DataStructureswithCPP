/**
* @file Source.cpp
* @description main dosyas�
* @course 1.��retim A Grubu
* @assignment �dev-1
* @date 23.11.2022
* @author Ersin Al�in - ersin.alcin@ogr.sakarya.edu.tr
*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "YoneticiListesi.h"

using namespace std;


vector<int> Parse(string line) {
	vector<int> data;
	std::string delimiter = " ";

	size_t pos = 0;
	std::string token;
	while ((pos = line.find(delimiter)) != std::string::npos) {
		token = line.substr(0, pos);
		//std::cout << token << std::endl;
		data.push_back(stoi(token));
		line.erase(0, pos + delimiter.length());
	}
	//std::cout << line << std::endl;

	if(line!="")
		data.push_back(stoi(line));
	return data;
	
}
node_mng* Reader(YoneticiListesi* mng,node_mng* root){
	string myText;

	// Dosyadan okuma
	ifstream MyReadFile("./doc/veriler.txt");

	// Sat�r sat�r okumak i�in while 
	while (getline(MyReadFile, myText)) {

		vector<int> data = Parse(myText);
		root = mng->InsertList(root, data);
	}

	// Dosya kapama
	MyReadFile.close();
	return root;
}

int main() {
	node_mng*root = NULL;
	YoneticiListesi* mng = new YoneticiListesi();
	root = Reader(mng,root); // dosya oku
	mng->WriteCurrentNodes(root, 0); // ekran� yazd�r
	mng->Processor(root); // i�lemi ba�lat
	root = mng->DeleteAllNodes(root);	// temizle

	delete mng;

	return 0;
}
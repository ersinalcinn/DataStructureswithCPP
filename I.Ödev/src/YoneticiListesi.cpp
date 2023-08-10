/**
* @file YoneticiListesi.cpp
* @description Baðlý listeye yönetimi. Bütün iþlemlerin yönetimi
* @course 1.Öðretim A Grubu
* @assignment Ödev-1
* @date 23.11.2022
* @author Ersin Alçin - ersin.alcin@ogr.sakarya.edu.tr
*/

#include "YoneticiListesi.h"

YoneticiListesi::YoneticiListesi() {
	line_list = new SatirListesi();
	srand(time(NULL));
}
YoneticiListesi::~YoneticiListesi()
{	
	delete line_list;
}

// gelen düðümü liste içinde ugyun yere yerleþtirir
node_mng* YoneticiListesi::ToShort(node_mng* root, node_mng * node)
{
	node_mng* iter = root;
	while (iter->next != NULL)// ilgili dugumu listeden cikart
	{
		if (iter->next == node) {
			iter->next = node->next;
			if(node->next!=NULL) // null ise hata verir
				node->next->prev = iter;
			break;
		}
		iter = iter->next;
	}
	iter = root;
	bool flag = false; // ekleme kontrolü
	while (iter!=NULL)
	{		
		if (node->avarage < iter->avarage) {
			if (iter == root) { // kökün yerine geçecekse
				node->prev = iter->prev;
				iter->prev = node;
				node->next = iter;
				root = node;
				break;
			}
			node->prev = iter->prev;
			iter->prev->next = node;
			iter->prev = node;
			node->next = iter;
			break;
		}
		iter = iter->next;
	}

	return root;
}

bool YoneticiListesi::ToShortControl(node_mng *root, node_mng *node)
{
	node_mng* iter2 = root;
	while (iter2->next != NULL)
	{
		if (iter2->next == node) {
			if (iter2->avarage > node->avarage) // ilgili düðümden küçükse
				return true;
			else if (node->next != NULL && node->avarage > node->next->avarage) // sonrakinden büyükse
				return true;
		}
		iter2 = iter2->next;
	}
	return false;
}

// Ekranýn ilk satýrýna düðümün devamýyla ilgili bilgileri yazar
// ilk,son,<--,-->
void YoneticiListesi::ListInfo(node_mng *begin)
{
	int count = 0;
	while (begin != NULL)
	{
		// baþtaki gösterge
		if (count == 0) {
			if (begin->prev == NULL) {
				std::cout << std::setw(3) << "ilk";
				std::cout << std::setw(7) << " ";
			}				
			else {
				std::cout << std::setw(3) << "<--";
				std::cout << std::setw(7) << " ";
			}
			std::cout << std::setw(2) << " ";
		}
		else if (begin->next == NULL || count == 8)// sondaki deðer
		{
			if (begin->next == NULL) { // sona gelindi ise
				std::cout << std::setw(7) << " ";
				std::cout << std::setw(3) << "son";
			}
			else { // devamý avr ise
				std::cout << std::setw(7) << " "; 
				std::cout << std::setw(3) << "-->";
			}
			break;
		}
		if ( count > 0 && begin!=NULL) {
			std::cout << std::setw(10) << " ";
			std::cout << std::setw(2) << " ";
		}
		count++;
		begin = begin->next;
	}	
	std::cout << "\n";
}

node_mng* YoneticiListesi::DeleteNode(node_mng * root, int index)
{
	node_mng* iter = root;
	int count = 0 ;
	while (iter !=NULL)
	{
		if (count == index)
			break;
		count++;
		iter = iter->next;
	}
	if (iter == root) {
		node_mng* temp = root;
		root = root->next;
		root->prev = NULL;
		delete temp;
		return root;
	}
	iter->prev->next = iter->next;
	if (iter->next != NULL)
		iter->next->prev = iter->prev;
	else {// liste sonunda siliniyorsa 
		if (current_selected_node % 8 == 0)//ve ekrandaki son düðüm ise önceki ekrana geç
			current_display--;
	}
	delete iter;	
	return root;
}

node_mng * YoneticiListesi::DeleteAllNodes(node_mng * root)
{
	node_mng* iter = root;
	while (iter != NULL) {
		node_mng* temp = iter;
		iter = iter->next;
		temp->root_child_list = line_list->DeleteAllNodes(temp->root_child_list);
		delete temp;
	}
	return NULL;
}

// Düðümün istenen verisini yazar
// 1 ise kendi adresi
// 2 ise önceki düðüm adresi
// 3 ise verisi
// 4 ise sonraki adresi
// 5 ise düz çizgi
// 6 ise ok
void YoneticiListesi::SmallWriter(node_mng * begin, int s)
{
	int count = 0;
	while (begin != NULL)
	{
		if (count < 8) { // anlýk ekrana ayzýlan ekran

			switch (s)
			{
				case 1: // düðümün kendi adresi
					std::cout << std::setw(9) << begin;
					std::cout << std::setw(3) << " ";
					break;
				case 2:// düðümün önceki düðümünün adresi
					std::cout << "|";
					std::cout << std::setw(8) << begin->prev;
					std::cout << "|";
					std::cout << std::setw(2) << " ";
					break;
				case 3: // düðümün verisi
					std::cout << "|";
					std::cout << std::setw(8) << begin->avarage;
					std::cout << "|";
					std::cout << std::setw(2) << " ";
					break;
				case 4: // düðümün sonraki düðümünün adresi
					std::cout << "|";
					std::cout << std::setw(8) << begin->next;
					std::cout << "|";
					std::cout << std::setw(2) << " ";
					break;
				case 5:// düz çizgi
					std::cout << std::setw(10) <<"----------";
					std::cout << std::setw(2) << " ";
					break;
				default:
					break;
			}			
		}
		else
			break;
		count++;
		begin = begin->next;
	}
	std::cout << "\n";
}

void YoneticiListesi::SmallWriterChildList(node_line* begin,int s, int space)
{
	// boþluklarý koyuyoruz
	for (int i = 0; i < space; i++) {
		std::cout << std::setw(10) << " ";
		std::cout << std::setw(2) << " ";
	}
	switch (s)
	{
	case 1: // düðümün kendi adresi
		std::cout << std::setw(9) << begin;
		std::cout << std::setw(3) << " ";
		break;
	case 2: // düðümün verisi
		std::cout << "|";
		std::cout << std::setw(8) << begin->data;
		std::cout << "|";
		if (child_node_count == current_selectednode_child_selected && press_first_k) {
			std::cout << " <--- silinecek";
		}
		break;
	case 3: // düðümün sonraki düðümünün adresi
		std::cout << "|";
		std::cout << std::setw(8) << begin->next;
		std::cout << "|";
		break;
	case 4:// düz çizgi
		std::cout << std::setw(10) << "----------";
		break;
	case 5: // yukarý ok (alt düðümler için)
		std::cout << std::setw(10) << "^^^^^^^^^^";
		break;
	default:
		break;
	}
	std::cout << "\n";
}
void YoneticiListesi::WriterCurrentSelectedChildList(node_mng * begin,int selected)
{
	int space = 0; // boþluk sayýsý
	for (int i = 0; i < selected; i++)
	{
		begin = begin->next; // düðüm bulunuyor
		space = i+1;
	}

	// içerdiði alt listeyi yazdýrýyoruz
	std::cout << "\n";
	SmallWriterChildList(begin->root_child_list, 5,space);//	 ^^^^^^^^^^
	node_line* iter = begin->root_child_list;
	while (iter != NULL)
	{		
		SmallWriterChildList(iter, 1,space);//	 00321F23
		SmallWriterChildList(iter, 4,space);//	----------
		SmallWriterChildList(iter, 2,space);//	|      25|
		SmallWriterChildList(iter, 4,space);//	----------
		SmallWriterChildList(iter, 3,space);//	|00D44F51|
		SmallWriterChildList(iter, 4,space);//	----------
		std::cout << "\n";
		iter = iter->next;
		child_node_count++;
	}
	std::cout << "\n";
}

void YoneticiListesi::WriteCurrentNodes(node_mng*root,int c) // istenen 8 düðümü ekrana basar
{
	node_mng* iter = root;
	int count = 0;
	while (true) // yazýlmnaya baþlanacak düðüme ilerle
	{
		if (count == c*8)
			break;
		count++;
		iter = iter->next;
	}

	system("cls");

	ListInfo(iter);// ilk satýr(ilk,son,<--,-->)
	SmallWriter(iter,1);//			 0213F238
	SmallWriter(iter, 5);//			----------
	SmallWriter(iter, 2);//			|02215DF2|
	SmallWriter(iter, 5);//			----------
	SmallWriter(iter, 3);//			|    56.5|
	SmallWriter(iter, 5);//			----------
	SmallWriter(iter, 4);//			|0231F12S|
	SmallWriter(iter, 5);//			----------

	WriterCurrentSelectedChildList(iter, current_selected_node%8);
	child_node_count = 0;
}

void YoneticiListesi::Processor(node_mng * root) // kullanýcý seçimine göre iþlemler yapar
{
	std::string secim = "";
	std::cin >> secim;
	if (secim == "a") {
		if (press_first_k)
			press_first_k = false;
		if (current_display > 0) {
			current_display--;
			current_selected_node -= 8;
		}			
		WriteCurrentNodes(root, current_display);
	}
	else if (secim == "d") {
		if (press_first_k) // önceden k basýlmýþ ise iptal et
			press_first_k = false;
		if (!((current_display + 1) * 8 >= current_node_number)) { // sýnýrý aþmýyorsa arttýr
			current_display++;
			current_selected_node += 8;
			if (current_selected_node >= current_node_number)
				current_selected_node = current_node_number - 1;
		}			
		WriteCurrentNodes(root, current_display);
	}
	else if (secim == "c") {
		if (press_first_k)
			press_first_k = false;
		int before = (current_selected_node) / 8;
		int after = -1;
		if (current_selected_node < current_node_number-1) {
			current_selected_node++;
			after = (current_selected_node) / 8;
		}
		// anlýk görünen düðümlerin sýnýrýný aþtýysa sonraki ekrana geç
		if (after != -1 && after > before) {
			if (!((current_display + 1) * 8 > current_node_number))
				current_display++;
		}
		
		WriteCurrentNodes(root, current_display);
	}
	else if (secim == "z") {
		if (press_first_k)
			press_first_k = false;
		int before = current_selected_node / 8;
		int after = -1;
		if (current_selected_node > 0) {
			current_selected_node--;
			after = current_selected_node / 8;
		}
		if (after != -1 && after < before) {
			if (current_display > 0)
				current_display--;
		}
		// anlýk görünen ekranýn sýnýrýný aþtýysa önceki ekrana geç
	/*	if (current_selected_node <= (current_display - 1) * 8) {
			if (current_display>0)
				current_display--;
		}*/
		WriteCurrentNodes(root, current_display);
	}
	else if (secim == "p") {
		if (press_first_k)
			press_first_k = false;
		root = DeleteNode(root, current_selected_node);
		current_node_number--;
		if (current_selected_node == current_node_number)
			current_selected_node--;
		WriteCurrentNodes(root, current_display);
	}
	else if (secim == "k") {
		if (!press_first_k) {
			node_mng* iter = root;
			int count = 0;

			for (int i = 0; i < current_selected_node; i++)
			{
				iter = iter->next; // düðüm bulunuyor
			}
			press_first_k = true;
			//current_selectednode_child_selected = rand() % line_list->gGetNodeNumber(iter->root_child_list);
		}
			
		else {
			node_mng* iter = root;
			int count = 0;
		
			for (int i = 0; i < current_selected_node; i++)
			{
				iter = iter->next; // düðüm bulunuyor
			}
			iter->root_child_list = line_list->DeleteNode(iter->root_child_list, current_selectednode_child_selected);
			if (line_list->gGetNodeNumber(iter->root_child_list) == 0) {
				root = DeleteNode(root, current_selected_node);
				current_node_number--;
				if (current_selected_node == current_node_number)
					current_selected_node--;
			}			
			else {
				iter->avarage = line_list->GetAvarage(iter->root_child_list);
				if (ToShortControl(root, iter))
					root = ToShort(root, iter);
			}
			press_first_k = false;
		}
		WriteCurrentNodes(root, current_display);
	}

	Processor(root);
}

node_mng * YoneticiListesi::NewNoder(std::vector<int> data)
{
	current_node_number++;
	node_mng* new_node = new node_mng(); // yeni dugum
	new_node->next = NULL;
	new_node->prev = NULL;
	for (int i = 0; i < data.size(); i++) // sayýlarý satýr listesne ekliyor
		new_node->root_child_list = line_list->InsertList(new_node->root_child_list, data[i]);
	new_node->avarage = line_list->GetAvarage(new_node->root_child_list); // ortalama getir
	return new_node;
}
node_mng * YoneticiListesi::InsertList(node_mng *root,std::vector<int> data)
{
	// Kok dugum ise ilk dugumu ekle
	if (root == NULL) {
		root = NewNoder(data);
		return root;
	}

	// sona kadar ilerler
	node_mng* referance = NULL; // listenin son elemaný
	node_mng* iter = root;
	do {
		referance = iter;
		iter = iter->next;
	} while (iter != NULL);
	referance->next = NewNoder(data); // ekleme iþlemi
	referance->next->prev = referance;
	// sýralama gerkiyormu diye kontrol ediyoruz
	// gerekiyor ise gönderiyoruz
	if (ToShortControl(root, referance->next))
		root = ToShort(root, referance->next);

	return root;
}


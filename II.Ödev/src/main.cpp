/**
* @file main.hpp
* @description main fonksiyon ve kontrol işlemleri
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @author Ersin Alçin - ersin.alcin@ogr.sakarya.edu.tr
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Queue.hpp"
#include "Radix.hpp"
#include "Cell.hpp"
#include "Tissue.hpp"
#include "Organ.hpp"
#include "System.hpp"
#include "Organism.hpp"

using namespace std;

int main(){
    ifstream    countfile("Veri.txt");
    string      countLine;
    
    int tissueCount = 0;
    while(getline(countfile,countLine)){
        tissueCount++;
    }

    Organism    *organism = new Organism(tissueCount / 2000);
    ifstream    textFile("Veri.txt");
    string      textLine;

    for (int i = 0; i < tissueCount / 2000; i++)
    {
        System *system = new System();

        for (int j = 0; j < 100; j++)
        {
            Organ *organ = new Organ();

            for (int s = 0; s < 20 ; s++)
            {
                
                getline(textFile, textLine);
                int size = 0;

                istringstream wcounter(textLine);
                istringstream initer(textLine);

                while(wcounter){
                    string num;
                    if(wcounter >> num){size++;}
                }

                int *nums = new int[size];

                int initindex = 0;
                while(initer){
                    string num;
                    if(initer >> num)
                    {
                        nums[initindex++] = stoi(num);
                    }
                }

                Radix *sorter = new Radix(nums, size);
                delete[] nums;
                nums = sorter->Sort();
                Tissue *tissue = new Tissue(nums, size);
                organ->add(tissue);
                delete[] nums;

                delete sorter;//delete sorter


            }
            
            system->add(organ);
        }
        
        organism->systems[i] = system;
    }


    system("cls");
    cout <<endl<<"ORGANIZMA"<<endl<<endl;
    for (int i = 0; i < tissueCount / 2000; i++){
        for (int j = 0; j < 100; j++){
            if (!(organism->systems[i]->organs[j]->checkBalance())){cout<<"#";}
            else{cout<<" ";}
        }
        cout<<endl;    
    }
    getchar();
    //MUTATION PART

    for (int i = 0; i < tissueCount / 2000; i++){
        for (int j = 0; j < 100; j++){
            if (organism->systems[i]->organs[j]->returnRootval() % 50 == 0){
                
                Tissue **mutants = organism->systems[i]->organs[j]->mutants();
                Organ *del = organism->systems[i]->organs[j];
                organism->systems[i]->organs[j] = new Organ();
                

                for (int ti = 0; ti < 20; ti++){
                    int *nums = new int[mutants[ti]->size];

                    for (int k = 0; k < mutants[ti]->size; k++)
                    {
                        nums[k] = mutants[ti]->cells[k]->length;

                        if (nums[k] % 2 == 0)
                        {
                            nums[k] = nums[k] / 2;
                        }
                    }

                    Radix *sorter = new Radix(nums,mutants[ti]->size);
                    delete[] nums;
                    nums = sorter->Sort();
                    Tissue *mutatedTissue = new Tissue(nums, mutants[ti]->size);
                    delete[] nums;
                    delete sorter;


                    organism->systems[i]->organs[j]->add(mutatedTissue);
                    
                    
                }

                delete del; //delete old organ
                
            }
        }
        cout<<endl;    
    }




    system("cls");
    cout <<endl<<"ORGANIZMA(MUTASYONA UGRADI)"<<endl<<endl;
    for (int i = 0; i < tissueCount / 2000; i++){
        for (int j = 0; j < 100; j++){
            if (!(organism->systems[i]->organs[j]->checkBalance())){cout<<"#";}
            else{cout<<" ";}
        }
        cout<<endl;    
    }
    getchar();
    
    delete organism;
    cout<<endl<<"deleted garbage an exiting program"<<endl;

    return (0);
    
}
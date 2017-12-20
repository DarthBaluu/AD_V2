/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Axel
 *
 * Created on 20. Dezember 2017, 11:12
 */

#include <cstdlib>
#include "EVKD/EVKD.h"
#include "TEXT.h"
#include <string>
#include <iostream>
#include <limits>
using namespace std;

/*
 * 
 */
int main(int argc, char* argv) {
    int choice = 0;
    TEXT* allgemein;
    int i;
    char* name[]={"Schmitz, Josef","Mueller, Josi","Schmitz, Anna", "Mueller, Josef","Schmitz, Josi","Mueller, Anna", "Meier, Josef","Zacher, Josi","Anker, Anna"};
    do{
    cout<< "(1) Listenobjekt erstellen\n";
    cout<< "(2) Liste anzeigen\n";
    cout<< "(3) Element anhaengen\n";
    cout<< "(4) Element Sortiert einfügen\n";
    cout<< "(5) Element Loeschen\n";
    cout<< "(6) Liste sortieren\n";
    cout<< "(12) Beenden\n";
    
    cin>> choice;
    //cin.ignore(numeric_limits<streamsize>::max(),'\n');
    switch(choice){
        case 1 :
        
            allgemein = new TEXT();
            /*for (i=0;i<sizeof(name);i++){
                allgemein->anhaenge(name[i]);
            }*/
            
            for (i=0;i<9;i++){
                allgemein->anhaenge(name[i]);
            }
            break;
        
        case 2 : 
            allgemein->zeigDich();
                break;
        case 3 : 
            char temp[50];
            cout<< "Bitte geben Sie den anzuhaengenden Text an\n";
            scanf("%s",&temp);
            allgemein->anhaenge(temp);
                break;
        case 4 : 
            
                break;
        case 5 : 
            int a;
            cout<< "Welche position soll geloescht werden\n";
            cin>> a;
            allgemein->loesche(a);
                break;
        case 6 : 
            allgemein->iSort();
                break;
        case 12 : 
                break;
        default:
            break;
    }
    
    }while(choice!=12);
    
    return 0;
}


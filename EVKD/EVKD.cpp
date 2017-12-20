/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EVKD.cpp
 * Author: Axel
 * 
 * Created on 20. Dezember 2017, 11:12
 */

#include "EVKD.h"
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;
using namespace std;

EVKD::EVKD() {
}

EVKD::EVKD(char* LPSZDaten, EVKD* N) {
    Next = N;
    int a=0,i;
    while(LPSZDaten[a]!='\0'){
        a++;
    }
    daten=new char[a+1];
    for (i=0;i<=a;i++){
        daten[i]=LPSZDaten[i];
    }
    anz=a;
}

EVKD::EVKD(const EVKD& orig) {
}

EVKD::~EVKD() {
}

int EVKD::GetAnz() {
    return anz;
}

char* EVKD::GetDaten() {
    int i;
    char* rueckgabe = new char[anz+1];
    for (i=0;i<anz;i++){
        rueckgabe[i]=daten[i];
    }
    rueckgabe[anz]='\0';
    return rueckgabe;
}

EVKD* EVKD::GetNext() {
    return Next;
}

void EVKD::SetNext(EVKD* in) {
    cout<<"Momentanes Next: "<<Next<<"\n\n\n";
    cout<<"Adresse in: "<<in<<"\n\n\n";
    this->Next = in;
}

bool EVKD::operator==(EVKD& in) {
    int a = strcmp(this->GetDaten(),in.GetDaten());
    if (a == 0){
        return true;
    }
    return false;
}

bool EVKD::operator>(EVKD& in) {
    int a = strcmp(this->GetDaten(),in.GetDaten());
    if (a > 0){
        return true;
    }
    return false;
}





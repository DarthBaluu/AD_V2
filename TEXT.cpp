/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TEXT.cpp
 * Author: Axel
 * 
 * Created on 20. Dezember 2017, 11:29
 */

#include "TEXT.h"
#include "EVKD/EVKD.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
using namespace std;
TEXT::TEXT() {
    this->Start=nullptr;
    this->anz=0;
}

TEXT::~TEXT() {
}

void TEXT::anhaenge(char* in) {
    cout << in <<"\n";
    EVKD* obj = new EVKD(in,nullptr);
    cout << obj <<"\n";
    EVKD* temp;
    if (Start==nullptr){
        Start = obj;
        cout << obj->GetDaten() << "\n";
    }else{
        temp = Start;
        while(temp->GetNext()!=nullptr){
            temp = temp->GetNext();
        }
        temp->SetNext(obj);
        cout << obj->GetDaten() << "\n";
    }
    anz++;
}

void TEXT::einfuegeSortiert(EVKD* in, int max) {
    int i;
    EVKD *temp, *temp_2;
    temp=Start;
    for(i=0;i<max;i++){
        if(*temp==*in){
            if(temp==Start){
                Start==in;
                in->SetNext(nullptr);
            }else{
                temp_2->SetNext(in);
                in->SetNext(temp);
            }
        }else{
                temp_2=temp;
                temp=temp->GetNext();
            }
    }
    anz++;
}

void TEXT::iSort() {
    int i;
    EVKD* sort= new EVKD[anz];
    EVKD* temp;
    temp = Start;
    for (i=0;i<anz;i++){
        sort[i] = *temp;
        temp = temp->GetNext();
    }
    for (i=0;i<anz;i++){
        loesche(1);
    }
    for (i=0;i<anz;i++){
        einfuegeSortiert(&sort[i],anz);
    }
}

EVKD* TEXT::loesche(int pos) {
    int i;
    EVKD *temp,*temp_2;
    temp=Start;
    if(pos==1){
        Start=Start->GetNext();
    }else{
        for(i=0;i<(pos-1);i++){
            temp_2=temp;
            temp=temp->GetNext();
        }
        temp_2->SetNext(temp->GetNext());
    }
}

void TEXT::zeigDich() {
    EVKD* temp;
    temp = Start;
    do{
        cout<< "Adresse: " << temp << " Wert: " << temp->GetDaten() <<"\n";
        temp = temp->GetNext();
    }while(temp!=nullptr);
}


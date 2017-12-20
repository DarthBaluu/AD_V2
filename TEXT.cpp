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
    //cout << in <<"\n";
    EVKD* obj = new EVKD(in,nullptr);
    //cout << obj <<"\n";
    EVKD* temp;
    if (Start==nullptr){
        Start = obj;
        //cout << obj->GetDaten() << "\n";
    }else{
        temp = Start;
        while(temp->GetNext()!=nullptr){
            temp = temp->GetNext();
        }
        temp->SetNext(obj);
        //cout << obj->GetDaten() << "\n";
    }
    anz++;
}

void TEXT::einfuegeSortiert(EVKD* in, int max) {
    int i;
    //cout<< "Daten von in: " << in->GetDaten() <<"\n\n\n";
    //cout<<"Adresse Start: "<<Start<<"\n\n\n";
    EVKD *temp, *temp_2;
    temp=Start;
    if(Start==nullptr){
        Start=in;
        in->SetNext(nullptr);
    }else{
        for(i=0;i<max;i++){
            if(temp!=nullptr){
            if(*temp>*in){
                if(i==0){
                    Start=in;
                    in->SetNext(temp);
                    break;
                }else{
                    temp_2->SetNext(in);
                    in->SetNext(temp);
                    break;
                }
            }else{
                    temp_2=temp;
                    temp=temp->GetNext();
                }
            }
        }
    if(temp==nullptr){
        temp_2->SetNext(in);
        in->SetNext(nullptr);
    }
    }
    anz ++;
    //cout<<"Anzahl Objekte: "<<anz<<"\n";
    //zeigDich();
    //cout<<"\n\n";
}

void TEXT::iSort() {
    int i,a;
    a=anz;
    EVKD* sort= new EVKD[anz];
    EVKD* temp;
    temp = Start;
    for (i=0;i<anz;i++){
        sort[i] = *temp;
        temp = temp->GetNext();
    }
    for (i=0;i<a;i++){
        //zeigDich();
        //cout<<"\n\n";
        loesche(1);
        
    }
    //cout<<"Anzahl: "<<anz<<"\n\n";
    //zeigDich();
    
    for (i=0;i<a;i++){
        this->einfuegeSortiert(&sort[i],anz);
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
    anz--;
}

void TEXT::zeigDich() {
    EVKD* temp;
    int a=1;
    temp = Start;
    do{
        cout<<"Nr: "<<a<< "\tAdresse: " << temp << "\tWert: " << temp->GetDaten()<<"\t" <<" Next: "<<temp->GetNext()<< "\n";
        temp = temp->GetNext();
        a++;
    }while(temp!=nullptr);
    cout<<"Anzahl gem. STAN: "<<anz<<"\n\n";
}


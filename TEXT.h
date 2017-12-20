/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TEXT.h
 * Author: Axel
 *
 * Created on 20. Dezember 2017, 11:29
 */

#ifndef TEXT_H
#define TEXT_H
#include "EVKD/EVKD.h"
class TEXT {
public:
    TEXT();
    virtual ~TEXT();
    
    int anz;
    
    void anhaenge(char* in);
    void einfuegeSortiert(EVKD* in, int max);
    EVKD* loesche(int pos);
    void zeigDich();
    void iSort();
    
private:
    EVKD* Start;

};

#endif /* TEXT_H */


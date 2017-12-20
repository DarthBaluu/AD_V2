/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   EVKD.h
 * Author: Axel
 *
 * Created on 20. Dezember 2017, 11:12
 */

#ifndef EVKD_H
#define EVKD_H

class EVKD {
public:
    EVKD();
    EVKD(char* LPSZDaten, EVKD* N);
    EVKD(const EVKD& orig);
    virtual ~EVKD();
    
    bool operator>(EVKD& in);
    bool operator==(EVKD& in);
    EVKD* GetNext();
    char* GetDaten();
    int GetAnz();
    void SetNext(EVKD* in);

    
private:
    char* daten;
    int anz;
    EVKD* Next;

};

#endif /* EVKD_H */


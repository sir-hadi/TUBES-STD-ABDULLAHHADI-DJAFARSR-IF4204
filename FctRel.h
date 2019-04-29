#ifndef FCTREL_H_INCLUDED
#define FCTREL_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include "Fct.h"
//#include "Fac.h" di comment ko bener ya

using namespace std;

#define FctRel(R) R->FctRel
#define nextFctRel(R) R->nextFctRel
#define firstFctRel(L) L.firstFctRel

typedef struct elmFctRel *adrFctRel;

struct elmFctRel
{
	adrFct FctRel;
	adrFctRel nextFctRel;
};

struct ListFctRel
{
	adrFctRel firstFctRel;
};

//procedur dan fungsi goes down here
void CreateListFctRel(ListFctRel &R);
//1st wave
adrFctRel AllocateRel(adrFct C);
void DeallocateRel(adrFctRel R);
void insertRel(ListFctRel &L, adrFctRel R);
adrFctRel deleteFirstRel(ListFctRel &L);
adrFctRel deleteAfterRel(ListFctRel &L, adrFctRel Prec);




#endif // FCTREL_H_INCLUDED

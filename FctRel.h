#ifndef FCTREL_H_INCLUDED
#define FCTREL_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include "Fct.h"
//#include "Fac.h" di comment ko bener ya

using namespace std;

#define FctRel(R) R->FctRel
#define nextFctRel(R) R->nextFctRel
#define prevFctRel(R) R->prevFctRel
#define firstFctRel(R) R.firstFctRel
#define lastFctRel(R) R.lastFctRel

typedef struct elmFctRel *adrFctRel;

struct elmFctRel
{
	ardFct FctRel;
	adrFctRel nextFctRel;
	adrFctRel prevFctRel;
};

struct ListFctRel
{
	adrFctRel firstFctRel;
	adrFctRel lastFctRel;
};

//procedur dan fungsi goes down here
void CreateListFctRel(ListFctRel &R);

#endif // FCTREL_H_INCLUDED

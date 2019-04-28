#ifndef FAC_H_INCLUDED
#define FAC_H_INCLUDED

#include <iostream>
#include <stdlib.h>

#include "FctRel.h"
#include "Fct.h"

using namespace std;

#define nextFac(P)	P->nextFac
#define prevFac(P)	P->prevFac
#define firstFac(U)	U.firstFac
#define lastFac(U)	U.firstFac
#define Facilities(P)	P->Facilities
#define IDFac(P)	P->IDFac
#define FacName(P)	P->FacName

typedef struct elmFaculties *adrFac;

struct elmFaculties
{
	string IDFac;
	string FacName;
	ListFctRel Facilities;
	adrFac nextFac;
	adrFac prevFac;
};

struct University
{
	adrFac firstFac;
	adrFac lastFac;
};

//first wave ADH
void CreateUniversity(University &U);
adrFac Allocate(University &U, string x, string id);
void insertFirstFac(University &U, adrFac P);
void printFac(University &U);
adrFac FindFacName(University U, string x);

//second wave ADH
void insertAfterFac(University &U, adrFac Prec, adrFac P);
void insertLastFac(University &U, adrFac P);
adrFac deleteFirstFac(University &U);
adrFac deleteAfterFac(University &U, adrFac Prec);
adrFac deleteLasrFac(University &U);
adrFac FindFacID(University &U, string ID);




#endif // FAC_H_INCLUDED

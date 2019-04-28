#ifndef FAC_H_INCLUDED
#define FAC_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include "FctRel.h"

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

//procedur dan fungsi goes down here
void CreateUniversity(University &U);
adrFac Allocate(University &U, string x, string id);
void insertFirstFac(University &U, adrFac P);
void printFac(University &U);
adrFac FindFacName(University U, string x);



#endif // FAC_H_INCLUDED

#ifndef FCT_H_INCLUDED
#define FCT_H_INCLUDED

#include <iostream>
#include <stdlib.h>
//#include "FctRel.h"


using namespace std;

#define firstFct(C)	C.firstFct
#define lastFct(C)	C.lastFct
#define infoFct(P)  P->infoFct
#define nextFct(P)  P->nextFct
#define prevFct(P)	P->prevFct

struct DataFct
{
    string IDFct;
	string FctName;
	bool IsBooked;
	string DataPenyewa;
};

typedef DataFct infotype;
typedef struct elmFacilities *adrFct;

struct elmFacilities
{

	infotype infoFct;
	adrFct nextFct;
	adrFct prevFct;

};

struct ListFacilities
{
	adrFct firstFct;
	adrFct lastFct;
};

//procedur dan fungsi goes down here
void CreateListFct(ListFacilities &L);
adrFct AllocateFct(infotype X);
void insertFirstFct(ListFacilities &C, adrFct P);
void printFct(ListFacilities &C);
adrFct FindFctName(ListFacilities C, string x);

void insertAfterFct(ListFacilities &C, adrFct Prec, adrFct P);
void insertLastFct(ListFacilities &C, adrFct P);
adrFct deleteFirstFct(ListFacilities &C);
adrFct deleteAfterFct(ListFacilities &C, adrFct Prec);
adrFct deleteLastFct(ListFacilities &C);
adrFct FindFctID(ListFacilities &C, string ID);

#endif // FCT_H_INCLUDED

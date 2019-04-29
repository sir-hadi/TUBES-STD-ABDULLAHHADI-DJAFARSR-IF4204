#ifndef FCT_H_INCLUDED
#define FCT_H_INCLUDED

#include <iostream>
#include <stdlib.h>
//#include "FctRel.h"


using namespace std;

#define firstFct(C)	C.firstFct
#define lastFct(C)	C.astFct
#define infoFct(C)  C->infoFct
#define IDFct(C)	C->IDFct
#define nextFct(C)  C->nextFct
#define prevFct(C)	C->lastFct

typedef struct elmFacilities *adrFct;

struct DataFct
{
	string FctName;
	bool IsBooked;
	string DataPenyewa;
};

struct elmFacilities
{

	DataFct infoFct;
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
adrFct AllocateFct(string ,bool Booked);

#endif // FCT_H_INCLUDED

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

typedef struct elmFacilities *ardFct;

struct DataFct
{
	string FctName;
	bool IsBooked;
	string DataPenyewa;
};

struct elmFacilities
{

	DataFct infoFct;
	ardFct nextFct;
	ardFct prevFct;

};

struct ListFacilities
{
	ardFct firstFct;
	ardFct lastFct;
};

//procedur dan fungsi goes down here

#endif // FCT_H_INCLUDED

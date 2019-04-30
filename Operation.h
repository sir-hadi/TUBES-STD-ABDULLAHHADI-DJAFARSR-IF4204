#ifndef OPERATION_H_INCLUDED
#define OPERATION_H_INCLUDED

#include "Fac.h"
#include "Fct.h"
#include "FctRel.h"

using namespace std;

void UserInsertFac(University &U);
bool ADuplicateFac(University &U, string id);
void UserInsertFct(ListFacilities &L);
bool ADuplicateFct(ListFacilities &L);
void Connect(University &U, ListFacilities L, string idFac, string idFct);
void CekConnection(University U, ListFacilities L, string idFac, string idFct);
void Disconnect(University &U, ListFacilities L, string idFac, string idFct);
void PrintAll(University U, ListFacilities L);
void PrintFctOfFac(University U, ListFacilities L);
void DeleteFct(University &U, ListFacilities &L);
void DeleteFac(University &U, ListFacilities &L);
void BookAFct(University &U, ListFacilities &L);
void ShowAvailable(University U,ListFacilities &L);












#endif // OPERATION_H_INCLUDED

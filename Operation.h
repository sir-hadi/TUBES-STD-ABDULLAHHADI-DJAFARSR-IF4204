#ifndef OPERATION_H_INCLUDED
#define OPERATION_H_INCLUDED

#include "Fac.h"
#include "Fct.h"
#include "FctRel.h"

using namespace std;

void UserInsertFac(University &U);// hadi
void UserInsertFct(ListFacilities &L);// hadi
void Link(University &U, ListFacilities L, string idFac, string idFct);//hadi
bool CekConnection(University U, ListFacilities L, string idFac, string idFct);//hadi
void Disconnect(University &U, ListFacilities L, string idFac, string idFct);//djafar
void PrintAll(University U, ListFacilities L);//djafar
void PrintFctOfFac(University U, ListFacilities L, string id);//djafar
void DeleteFct(University &U, ListFacilities &L);//Djafar and Hadi
void DeleteFac(University &U, ListFacilities &L);//Djafar and Hadi
void ShowAvailable(University U,ListFacilities &L);//djafar
void BookARoom(ListFacilities &L);//hadi












#endif // OPERATION_H_INCLUDED

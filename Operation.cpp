#include "Fct.h"
#include "FctRel.h"
#include "Fac.h"
#include "Operation.h"

void UserInsertFac(University &U){
    string nama;
    string id;
    cout<<"Nama Fakultas : ";
    cin>>nama;
    cout<<endl<<"ID : ";
    cin>>id;
    adrFac P = AllocateFac(U,nama,id);
    if(FindFacID(U,id) != NULL)){
        deallocateFac(P);
        cout<<"Error : theres another NODE with the same ID";
    }else{
        inserLastFac(U,P);
    }
};
//bool ADuplicateFac(University &U, string id);
void UserInsertFct(ListFacilities &L){

};
//bool ADuplicateFct(ListFacilities &L);
void Connect(University &U, ListFacilities L, string idFac, string idFct){
    adrFac Fac = FindFacID(U,idFac);
    adrFct Fct = FindFctID(L,idFct);
    if(Fac == NULL && Fct == NULL){
        cout<<"Error"
    }
};
void CekConnection(University U, ListFacilities L, string idFac, string idFct);
void Disconnect(University &U, ListFacilities L, string idFac, string idFct);
void PrintAll(University U, ListFacilities L);
void PrintFctOfFac(University U, ListFacilities L);
void DeleteFct(University &U, ListFacilities &L);
void DeleteFac(University &U, ListFacilities &L);
void BookAFct(University &U, ListFacilities &L);
void ShowAvailable(University U,ListFacilities &L);

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
    if(FindFacID(U,id) != NULL){
        deallocateFac(P);
        cout<<"Error : theres another NODE with the same ID";
    }else{
        insertLastFac(U,P);
    }
};
//bool ADuplicateFac(University &U, string id);
void UserInsertFct(ListFacilities &L){

};
//bool ADuplicateFct(ListFacilities &L);
void Connect(University U, ListFacilities &L, string idFac, string idFct){
    adrFac Fac = FindFacID(U,idFac);
    adrFct Fct = FindFctID(L,idFct);
    if(Fac == NULL && Fct == NULL){
        cout<<"Error : Node Not Found";
    }else{
        adrFctRel R = AllocateRel(Fct);
        insertRel(Facilities(Fac),R);

    }
};

//sublim

void CekConnection(University U, ListFacilities L, string idFac, string idFct){
    adrFac Fac = FindFacID(U,idFac);
    adrFct Fct = FindFctID(L,idFct);
    //alone alen walker kekenya yg bener all fal down  lagu
    if(Fac == NULL && Fct == NULL ){
        cout<<"Error : Connection does not exist ";
    }else{
        adrFctRel R = firstFctRel(Facilities(Fac));
        while(R!=NULL){
            if(Fct == FctRel(R));{
                cout<<"Connection Found! ";
            }
            R = nextFctRel(R);
        }
    }
};

void Disconnect(University &U, ListFacilities L, string idFac, string idFct){
        adrFac Fac = FindFacID(U,idFac);
        adrFct Fct = FindFctID(L,idFct);
        if(Fac == NULL || Fct == NULL)
            {
            cout<<"Error : Faculties or Facilities does not exist ";
            }
        else
            {
            adrFctRel R = firstFctRel(Facilities(Fac));
            if(FctRel(R) != Fct)
            {
                adrFctRel Q = R;
                while(Q != NULL && FctRel(nextFctRel(Q)) != Fct)
                {
                    Q = nextFctRel(Q);
                }
                R = deleteAfterRel(Facilities(Fac),Q);
                DeallocateRel(R);
            }
            else
            {
                R = deleteFirstRel(Facilities(Fac));
                DeallocateRel(R);
            }
        }
};

void PrintAll(University U, ListFacilities L){
    adrFac P = firstFac(U);
    adrFctRel R;
    int i = 0;
    int j;

    while(P != NULL)
    {
        ++i;
        cout<<i<<"."<<FacName(P)<<" || ID : "<<IDFac(P)<<endl;
        cout<<"-- Facilities --"<<endl;
        R = firstFctRel(Facilities(P));
        j = 0;
        //Fct print
        if (R != NULL)
        {
            while(R != NULL)
                {
                    ++j;
                    cout<<" "<<j<<". "<<infoFct(FctRel(R)).FctName<<endl;
                    cout<<"  "<<infoFct(FctRel(R)).IDFct<<endl;
                    if (infoFct(FctRel(R)).IsBooked)
                    {
                        cout<<"  "<<"Room is Not Available"<<endl;
                        cout<<"  "<<"Penyewa :"<<infoFct(FctRel(R)).DataPenyewa<<endl;
                    }
                    else
                    {
                        cout<<"Room Is Available"<<endl;
                    }
                    R = nextFctRel(R);
                }
        }
        else
        {
            cout<<"<EMPTY>";
        }
        P = nextFac(P);
    }
    cout<<endl;
};

void PrintFctOfFac(University U, ListFacilities L, string id){
    adrFac P = FindFacID(U,id);
    int j = 0;
    if (P != NULL)
    {
        cout<<FacName(P)<<endl;
        adrFctRel R = firstFctRel(Facilities(P));
        if (R != NULL)
        {
            while(R != NULL)
                {
                    ++j;
                    cout<<" "<<j<<". "<<infoFct(FctRel(R)).FctName<<endl;
                    cout<<"  "<<infoFct(FctRel(R)).IDFct<<endl;
                    if (infoFct(FctRel(R)).IsBooked)
                    {
                        cout<<"  "<<"Room is Not Available"<<endl;
                        cout<<"  "<<"Penyewa :"<<infoFct(FctRel(R)).DataPenyewa<<endl;
                    }
                    else
                    {
                        cout<<"Room Is Available"<<endl;
                    }
                    R = nextFctRel(R);
                }

        }
        else
        {
            cout<<"EMPTY";
        }
    }
};

void DeleteFct(University &U, ListFacilities &L){
    cout<<"test";
};
void DeleteFac(University &U, ListFacilities &L){
    cout<<"test";
};
void ShowAvailable(University U,ListFacilities &L){
    cout<<"test";
};
void BookARoom(University U, ListFacilities &L){
    cout<<"test";
};

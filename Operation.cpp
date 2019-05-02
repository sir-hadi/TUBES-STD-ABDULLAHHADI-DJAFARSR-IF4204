#include "Fct.h"
#include "FctRel.h"
#include "Fac.h"
#include "Operation.h"

void UserInsertFac(University &U)
{
    string nama;
    string id;
    cout<<"Nama Fakultas : ";
    cin>>nama;
    cout<<endl<<"ID : ";
    cin>>id;
    cin.ignore();
    adrFac P = AllocateFac(U,nama,id);
    if(FindFacID(U,id) != NULL)
    {
        deallocateFac(P);
        cout<<"Error : theres another NODE with the same ID";
    }
    else
    {
        insertLastFac(U,P);
        firstFctRel(Facilities(P)) = NULL;
        cout<<"Success";
    }
};

void UserInsertFct(ListFacilities &L)
{
    DataFct x;
    char trig;
    cout<<"ID : ";
    cin>>x.IDFct;
    cout<<"Name : ";
    cin>>x.FctName;
    do
    {
        cout<<"Is this Booked ? [y/n]";
        cin>>trig;
        if(trig == 'y' || trig == 'Y')
        {
            cout<<"\nBy who : ";
            cin>>x.DataPenyewa;
            x.IsBooked = true;
        }
        else if(trig == 'n' || trig == 'N')
        {
            x.IsBooked = false;
            x.DataPenyewa = "-";
        }
        else
        {
            cout<<"Wrong input!\n\n";
        }
    }
    while(trig!= 'y' && trig != 'Y' && trig != 'n' && trig != 'N');

    adrFct Fct = AllocateFct(x);
    if(FindFctID(L,infoFct(Fct).IDFct) == NULL)
    {
        insertLastFct(L,Fct);
        cout<<"Success";
    }
    else
    {
        cout<<"\nError : theres another NODE with the same ID";
    }
};


void Link(University &U, ListFacilities L, string idFac, string idFct)
{

    adrFac P = firstFac(U);
    bool trig = false;
    while(P != NULL && !trig)
    {
        trig = CekConnection(U,L,IDFac(P),idFct);
        P = nextFac(P);
    }

    if(!trig || 1>0) // the 1>0 is use for debugging
    {
        adrFac Fac = FindFacID(U,idFac);
        adrFct Fct = FindFctID(L,idFct);
        if(Fac == NULL && Fct == NULL)
        {
            cout<<"Error : Node Not Found \n";
        }
        else
        {
            adrFctRel R = AllocateRel(Fct);
            insertRel(Facilities(Fac),R);
            cout<<"Success \n";

        }
    }
    else
    {
        cout<<"Error link \n";
    }
};

bool CekConnection(University U, ListFacilities L, string idFac, string idFct)
{
    adrFac Fac = FindFacID(U,idFac);
    adrFct Fct = FindFctID(L,idFct);
    //the code below is similar with the main one, need but doesnt work fully (Hadi)
    /*
    if(Fac != NULL && Fct != NULL )
    {
        adrFctRel R = firstFctRel(Facilities(Fac));
        if(R != NULL){ //the if is for debugging
            while(R!=NULL)
            {
                if(Fct == FctRel(R));
                {
                    cout<<"Success Finding";
                    return true;
                }
                R = nextFctRel(R);
            }
        }
    }
    return false;
    */

    if(Fac == NULL && Fct == NULL ){
        cout<<"Error : Connection does not exist \n";
        return false;
    }else{
        adrFctRel R = firstFctRel(Facilities(Fac));
        while(R!=NULL){
            if(Fct == FctRel(R));{
                cout<<"Connection Found! \n";
                return true;
            }
            R = nextFctRel(R);
        }
    }
    return false;
};




void Disconnect(University &U, ListFacilities L, string idFac, string idFct)
{
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
        cout<<"Success \n";
    }
};

void PrintAll(University U, ListFacilities L)
{
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
                cout<<"\t"<<j<<". "<<infoFct(FctRel(R)).FctName;
                cout<<"\t"<<infoFct(FctRel(R)).IDFct<<endl;
                if (infoFct(FctRel(R)).IsBooked)
                {
                    cout<<"\t\tRoom is Not Available"<<endl;
                    cout<<"\t\tPenyewa :"<<infoFct(FctRel(R)).DataPenyewa<<endl;
                }
                else
                {
                    cout<<"\t\tRoom Is Available"<<endl;
                }
                R = nextFctRel(R);
            }
        }
        else
        {
            cout<<"<EMPTY>\n";
        }
        P = nextFac(P);
    }
    cout<<endl;
};

void PrintFctOfFac(University U, ListFacilities L, string id)
{
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
                cout<<"\t"<<j<<". "<<infoFct(FctRel(R)).FctName<<endl;
                cout<<"\t\t"<<infoFct(FctRel(R)).IDFct<<endl;
                if (infoFct(FctRel(R)).IsBooked)
                {
                    cout<<"\t\tRoom is Not Available"<<endl;
                    cout<<"\t\tPenyewa :"<<infoFct(FctRel(R)).DataPenyewa<<endl;
                }
                else
                {
                    cout<<"\t\tRoom Is Available"<<endl;
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

void DeleteFct(University &U, ListFacilities &L)
{
    string id;
    cout<<"ID : ";
    cin>>id;
    adrFct Fct = FindFctID(L,id);
    if(Fct != NULL)
    {
        adrFac Fac = firstFac(U);

        while(Fac != NULL)
        {
            adrFctRel R = firstFctRel(Facilities(Fac));
            adrFctRel dump = R;
            while(R != NULL)
            {
                if(FctRel(R) == Fct)
                {
                    R = nextFctRel(R);
                    dump = deleteFirstRel(Facilities(Fac));
                    DeallocateRel(dump);
                }
                else if(nextFctRel(R) != NULL && FctRel(nextFctRel(R)) == Fct)
                {
                    dump = deleteAfterRel(Facilities(Fac),R);
                    DeallocateRel(dump);
                }
                else
                {
                    R = nextFctRel(R);
                }
            }
            Fac = nextFac(Fac);
        }

        if(Fct == firstFct(L))
        {
            Fct = deleteFirstFct(L);
        }
        else if(Fct == lastFct(L))
        {
            Fct = deleteLastFct(L);
        }
        else
        {
            adrFct prev = prevFct(Fct);
            Fct = deleteAfterFct(L,prev);
        }
        deallocateFct(Fct);
        cout<<"Success \n";
    }
};

void DeleteFac(University &U, ListFacilities &L)
{
    string id;
    cout<<"ID : ";
    cin>>id;
    adrFac Fac = FindFacID(U,id);
    if(Fac != NULL)
    {
        adrFctRel R = firstFctRel(Facilities(Fac));
        adrFctRel dump;
        while(R != NULL)
        {
            dump = R;
            R = nextFctRel(R);
            dump = deleteFirstRel(Facilities(Fac));
            DeallocateRel(dump);
        }
        if(Fac == firstFac(U))
        {
            Fac = deleteFirstFac(U);
        }
        else if(Fac == lastFac(U))
        {
            Fac = deleteLastFac(U);
        }
        else
        {
            adrFac prev = prevFac(Fac);
            Fac = deleteAfterFac(U,prev);
        }
        deallocateFac(Fac);
        cout<<"Success \n";
    }
};
void ShowAvailable(University U,ListFacilities &L)
{
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
                if(!(infoFct(FctRel(R)).IsBooked))
                {
                    ++j;
                    cout<<" "<<j<<". "<<infoFct(FctRel(R)).FctName<<endl;
                    cout<<"  "<<infoFct(FctRel(R)).IDFct<<endl;
                }
                R=nextFctRel(R);

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
void BookARoom(ListFacilities &L)
{
    string id;
    cout<<"ID : ";
    cin>>id;
    adrFct Fct = FindFctID(L,id);
    if(Fct != NULL)
    {
        string name;
        cout<<endl<<"Insert your Name : ";
        cin>>name;
        infoFct(Fct).DataPenyewa = name;
        infoFct(Fct).IsBooked = true;
        cout<<"Success \n";
    }
};


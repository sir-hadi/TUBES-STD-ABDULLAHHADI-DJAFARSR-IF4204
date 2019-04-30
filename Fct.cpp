#include "Fct.h"

void CreateListFct(ListFacilities &L){
    firstFct(L) = NULL;
    lastFct(L) = NULL;
}

adrFct AllocateFct(infotype X){
    adrFct P = new elmFacilities;
    infoFct(P).IDFct = X.IDFct;
    infoFct(P).FctName = X.FctName;
    infoFct(P).IsBooked = X.IsBooked;
    infoFct(P).DataPenyewa = X.DataPenyewa;
    nextFct(P) = NULL;
    prevFct(P) = NULL;

    return P;
}

void insertFirstFct(ListFacilities &C, adrFct P){
    if (firstFct(C) = NULL){
        prevFct(firstFct(C)) = P;
        nextFct(P) = firstFct(C);
        firstFct(C) = P;
    } else {
        firstFct(C) = P;
    }
}

void printFct(ListFacilities &C){
    adrFct P = firstFct(C);
    int i  = 1;
    while (P != NULL){
        cout<<"\t\tData "<<i<<endl;
        cout<<"\t==============\n";
        cout<<"Kode Fakultas\t: "<<infoFct(P).IDFct<<endl;
        cout<<"Nama Fakultas\t: "<<infoFct(P).FctName<<endl;
        cout<<"Tersedia\t: ";
        if (infoFct(P).IsBooked) cout<<"No\n";
        else cout<<"Yes\n";
        cout<<"Data Penyewa\t: "<<infoFct(P).DataPenyewa<<endl;

        P = nextFct(P);
        i++;
    }
}

adrFct FindFctName(ListFacilities C, string x){
    adrFct P = firstFct(C);
    while (P != NULL){
        if (infoFct(P).FctName == x){
            return P;
        }
        P = nextFct(P);
    }

    return NULL;
}

void insertAfterFct(ListFacilities &C, adrFct Prec, adrFct P){
    if (nextFct(Prec) != NULL){
        nextFct(P) = nextFct(Prec);
        prevFct(P) = Prec;
        prevFct(nextFct(Prec)) = P;
        nextFct(Prec) = P;
    } else {
        prevFct(P) = Prec;
        nextFct(Prec) = P;
    }
}

void insertLastFct(ListFacilities &C, adrFct P){
    if (firstFct(C) != NULL){
        adrFct Q = firstFct(C);
        while (nextFct(Q) != NULL){
            Q = nextFct(Q);
        }
        nextFct(Q) = P;
        lastFct(C) = P;
    } else {
        insertFirstFct(C,P);
    }
}

adrFct deleteFirstFct(ListFacilities &C){
    adrFct P = firstFct(C);
    prevFct(nextFct(P)) = NULL;
    firstFct(C) = nextFct(P);
    nextFct(P) = NULL;

    return P;
}

adrFct deleteAfterFct(ListFacilities &C, adrFct Prec){
    adrFct P;
    if (nextFct(Prec) != NULL){
        P = nextFct(Prec);
        if (nextFct(P) != NULL){
            nextFct(Prec) = nextFct(P);
            prevFct(nextFct(P)) = Prec;
            nextFct(P) = NULL;
            prevFct(P) = NULL;
        } else {
            nextFct(Prec) = NULL;
            prevFct(P) = NULL;
        }

        return P;
    }

    return NULL;
}

adrFct deleteLastFct(ListFacilities &C){
    if (firstFct(C) != lastFct(C)){
        adrFct P;
        adrFct Q = firstFct(C);
        while (nextFct(nextFct(Q)) != NULL){
            Q = nextFct(Q);
        }
        P = nextFct(Q);
        nextFct(Q) = NULL;
        prevFct(P) = NULL;
        lastFct(C) = Q;

        return P;
    } else {
        deleteFirstFct(C);
    }
}

adrFct FindFctID(ListFacilities &C, string ID){
    adrFct P = firstFct(C);
    while (P != NULL){
        if (infoFct(P).IDFct == ID){
            return P;
        }
        P = nextFct(P);
    }

    return NULL;
}

void deallocateFct(adrFct &C){
    delete C;
};

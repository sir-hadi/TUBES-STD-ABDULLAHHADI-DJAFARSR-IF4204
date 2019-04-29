//nih cpp relasi

#include "FctRel.h"
#include "Fac.h"
#include "Fct.h"

void CreateListFctRel(ListFctRel &R){
	firstFctRel(R) = NULL;
};

//1st wave
adrFctRel AllocateRel(adrFct C){
    adrFctRel R = new elmFctRel;
    FctRel(R) = C;
    nextFctRel(R) = NULL;
};

void DeallocateRel(adrFctRel R){
    delete R;
};

void insertRel(ListFctRel &L, adrFctRel R){
    nextFctRel(R) = firstFctRel(L);
    firstFctRel(L) = R;
};

adrFctRel deleteFirstRel(ListFctRel &L){
    adrFctRel R = firstFctRel(L);
    firstFctRel(L) = nextFctRel(R);
    nextFctRel(R) = NULL;
    return R;
};
adrFctRel deleteAfterRel(ListFctRel &L, adrFctRel Prec){
    adrFctRel R = nextFctRel(Prec);
    nextFctRel(Prec) = nextFctRel(R);
    nextFctRel(R) = NULL;
    return R;
};




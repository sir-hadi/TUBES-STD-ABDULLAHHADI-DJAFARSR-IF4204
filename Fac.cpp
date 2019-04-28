#include "Fac.h"
#include "Fct.h"
#include "FctRel.h"


void CreateUniversity(University &U){
	firstFac(U) = NULL;
	lastFac(U) = NULL;
};

adrFac Allocate(University &U, string x, string id){
	adrFac P;
	P = new elmFaculties;
	FacName(P) = x;
	IDFac(P) = id;
	CreateListFctRel(Facilities(P));
	nextFac(P) = NULL;
	prevFac(P) = NULL;
	return P;
};

void insertFirstFac(University &U, adrFac P){
	if(firstFac(U) == NULL){
		firstFac(U) = P;
		lastFac(U) = P;
	} else {
		nextFac(P) = firstFac(U);
		prevFac(firstFac(U)) = P;
		firstFac(U) = P;
	}
};

void printFac(University &U){
	if (firstFac(U) != NULL)
	{
		adrFac P = firstFac(U);
		do{
			cout<<FacName(P)<<" "<<IDFac(P)<<endl;
			P = nextFac(P);
		}while(P != NULL);
	}
};

adrFac FindFac(University U, string x){
	if(firstFac(U) != NULL){
        adrFac P = firstFac(U);
        do{
            if(FacName(P) == x){
                return P;
            }
            P = nextFac(P);
        }while(P != NULL);
        return NULL;
	}
};

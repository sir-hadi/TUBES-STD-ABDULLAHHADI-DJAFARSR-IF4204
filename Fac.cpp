#include "Fac.h"
#include "Fct.h"
#include "FctRel.h"

//1st wave ADH
void CreateUniversity(University &U){
	firstFac(U) = NULL;
	lastFac(U) = NULL;
};

adrFac Allocate(University &U, string x, string id){
	adrFac P = new elmFaculties;
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
		int i = 0;
		do{
			cout<<++i<<"."<<FacName(P)<<" "<<IDFac(P)<<endl;
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

//2nd wave ADH
void insertAfterFac(University &U,adrFac Prec ,adrFac P){
	if((Prec != NULL) && (P != NULL)){
		if(nextFac(Prec) != NULL){
			nextFac(P) = nextFac(Prec);
			prevFac(P) = Prec;
			prevFac(nextFac(P)) = P;
			nextFac(Prec) = P;

		}else{
			insertFirstFac(U,P);
		}
	}
};

void insertLastFac(University &U, adrFac P){
	cout<<"test0";
	if(firstFac(U) != NULL){
        cout<<"test1";
		prevFac(P) = lastFac(U);
		nextFac(lastFac(U)) = P;
		lastFac(U) = P;
	}else{
        insertFirstFac(U,P);
	}

};

adrFac deleteFirstFac(University &U){
	if(firstFac(U) != NULL){
		adrFac P = firstFac(U);
		if (firstFac(U) != lastFac(U))
		{
			firstFac(U) = nextFac(P);
			prevFac(firstFac(U)) = NULL;
			nextFac(P) = NULL;
			return P;
		}else{
			firstFac(U) = NULL;
			lastFac(U) = NULL;
			return P;
		}
	}
	return NULL;
};

adrFac deleteAfterFac(University &U, adrFac Prec){
	if ((Prec != NULL) && (nextFac(Prec) != NULL))
	{
		adrFac P = nextFac(Prec);
		if (nextFac(P) != NULL)
		{
			nextFac(Prec) = nextFac(P);
			prevFac(nextFac(P)) = Prec;
			nextFac(P) = NULL;
			prevFac(P) = NULL;
			return P;
		}else{
			deleteLasrFac(U);
		}
	}
	return NULL;
};

adrFac deleteLasrFac(University &U){
	if (lastFac(U) != NULL)
	{
		adrFac P = lastFac(U);
		if(firstFac(U) != lastFac(U)){
			lastFac(U) = prevFac(P);
			nextFac(lastFac(U)) = NULL;
			prevFac(P) = NULL;
			return P;
		}else{
			firstFac(U) = NULL;
			lastFac(U) = NULL;
			return P;
		}
	}
	return NULL;
};

adrFac FindFacID(University &U, string ID){
	if(firstFac(U) != NULL){
        adrFac P = firstFac(U);
        do{
            if(IDFac(P) == ID){
                return P;
            }
            P = nextFac(P);
        }while(P != NULL);
        return NULL;
	}
};

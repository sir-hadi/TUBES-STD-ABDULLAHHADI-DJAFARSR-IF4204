#include <iostream>
#include "Fct.h"
#include "FctRel.h"
#include "Fac.h"
#include "Operation.h"

using namespace std;


int main()
{

    University Telkom;
    CreateUniversity(Telkom);
    /*
    adrFac P = Allocate(Telkom,"Informatika","IF");
    firstFac(Telkom) = P;
    lastFac(Telkom) = P;

    printFac(Telkom);
    cout<<FacName(firstFac(Telkom))<<" First"<<endl;
    cout<<FacName(lastFac(Telkom))<<" Last"<<endl<<endl;

    adrFac Q = Allocate(Telkom,"Industri Kreatif","IK");

    nextFac(P) = Q;
    prevFac(Q) = P;
    lastFac(Telkom) = Q;

    printFac(Telkom);
    cout<<FacName(firstFac(Telkom))<<" First"<<endl;
    cout<<FacN ame(lastFac(Telkom))<<" Last"<<endl<<endl;


    */
    insertFirstFac(Telkom,AllocateFac(Telkom,"Informatika","IF"));
    insertFirstFac(Telkom,AllocateFac(Telkom,"Industri Kreatif","IK"));
    insertFirstFac(Telkom,AllocateFac(Telkom,"Ilmu Terapan","IT"));
    insertFirstFac(Telkom,AllocateFac(Telkom,"Teknik Elektrororo","TE"));
    insertFirstFac(Telkom,AllocateFac(Telkom,"Ekonomi dan Bisnis","EB"));
    adrFac P = NULL;
    P = deleteFirstFac(Telkom);
    insertAfterFac(Telkom,FindFacID(Telkom,"IT"),P);
    insertLastFac(Telkom,AllocateFac(Telkom,"Komunikasi dan Bisnis","KB"));
    printFac(Telkom);
    cout<<endl;
    P = deleteAfterFac(Telkom,FindFacID(Telkom,"IK"));
    printFac(Telkom);
    cout<<endl;
    P = deleteLastFac(Telkom);
    P = deleteLastFac(Telkom);
    P = deleteLastFac(Telkom);
    P = deleteLastFac(Telkom);
    P = deleteLastFac(Telkom);
    printFac(Telkom);


    return 0;
}

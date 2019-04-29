#include <iostream>
#include "Fct.h"
#include "FctRel.h"
#include "Fac.h"

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
    insertFirstFac(Telkom,Allocate(Telkom,"Informatika","IF"));
    insertFirstFac(Telkom,Allocate(Telkom,"Industri Kreatif","IK"));
    insertFirstFac(Telkom,Allocate(Telkom,"Ilmu Terapan","IT"));
    insertFirstFac(Telkom,Allocate(Telkom,"Teknik Elektrororo","TE"));
    insertFirstFac(Telkom,Allocate(Telkom,"Ekonomi dan Bisnis","EB"));
    adrFac P = NULL;
    P = deleteFirstFac(Telkom);
    insertAfterFac(Telkom,FindFacID(Telkom,"IT"),P);
    insertLastFac(Telkom,Allocate(Telkom,"Komunikasi dan Bisnis","KB"));
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

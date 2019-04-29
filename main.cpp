#include <iostream>
#include "Fct.h"
#include "FctRel.h"
#include "Fac.h"

using namespace std;


int main()
{

    University Telkom;
    CreateUniversity(Telkom);
    adrFac P;
    insertLastFac(Telkom,Allocate(Telkom,"Informatika","IF"));
    insertLastFac(Telkom,Allocate(Telkom,"Industri Kreatif","IK"));
    insertLastFac(Telkom,Allocate(Telkom,"Ilmu Terapan","IT"));
    insertLastFac(Telkom,Allocate(Telkom,"Teknik Elektrororo","TE"));
    insertLastFac(Telkom,Allocate(Telkom,"Ekonomi dan Bisnis","EB"));
    //deleteFirstFac(Telkom, P);
    cout<<FacName(firstFac(Telkom))<<"pirts"<<endl;
    cout<<FacName(lastFac(Telkom))<<"pirts"<<endl<<endl;
    printFac(Telkom);
    return 0;
}

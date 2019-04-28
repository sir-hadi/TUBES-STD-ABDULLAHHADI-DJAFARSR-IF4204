#include <iostream>
#include "Fac.h"
#include"Fct.h"
#include "FctRel.h"

using namespace std;


int main()
{

    University Telkom;
    CreateUniversity(Telkom);
    insertFirstFac(Telkom,Allocate(Telkom,"Informatika / tempat wibu","IF"));
    insertFirstFac(Telkom,Allocate(Telkom,"Industri Kreatif / ini juga dikit","IK"));
    insertFirstFac(Telkom,Allocate(Telkom,"Ilmu Terapan","IT"));
    insertFirstFac(Telkom,Allocate(Telkom,"Teknik Elektrororo","TE"));
    insertFirstFac(Telkom,Allocate(Telkom,"Ekonomi dan Bisnis","EB"));
    printFac(Telkom);
    return 0;
}

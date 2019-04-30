#include <iostream>
#include "Fct.h"
#include "FctRel.h"
#include "Fac.h"
#include "Operation.h"


University Telkom;
ListFacilities C;

DataFct createFacilities(){
    DataFct F;

    cout<<"\t\tInsert Data\n";
    cout<<"\t\t===========";
    cout<<"\nFacility's ID\t\t: ";
    cin>>F.IDFct;
    cout<<"Facility's Name\t\t: ";
    cin>>F.FctName;
    F.IsBooked = false;
    F.DataPenyewa = "-";

    return F;
}

int insertFctChoice(ListFacilities C, infotype X){
    int iChoice;
    bool menuLoop = true;
    do {
        cout<<"Choose how you want to insert the data\n\n";
        cout<<"1. Insert First";
        cout<<"2. Insert After";
        cout<<"3. Insert Last";
        cout<<"0. Cancel";
        cout<<"Your choice\t: ";
        cin>>iChoice;
        switch(iChoice){
        case 1:
            insertFirstFct(C,AllocateFct(X));
            menuLoop = false;
            break;
        case 2:
        {
            string ID;
            cout<<"Insert ID\t: ";
            cin>>ID;
            if (FindFctID(C,ID) != NULL){
                adrFct Prec = FindFctID(C,ID);
                insertAfterFct(C,Prec,AllocateFct(X));
            } else {
                cout<<"Data doesn't exist, like your GF lol";
            }
            menuLoop = false;
            break;
        }
        case 3:
            insertLastFct(C,AllocateFct(X));
            menuLoop = false;
            break;
        case 0:
        {
            cout<<"Add facility canceled!\n";
            menuLoop = false;
            break;
        }
        default:
            cout<<"Wrong Input!\n\n";
            break;
        }
    }while(menuLoop == true);

    return 0;
}

int insertFacChoice(University U, string name, string id){
    int iChoice;
    bool menuLoop = true;
    do {
        cout<<"Choose how you want to insert the data\n\n";
        cout<<"1. Insert First";
        cout<<"2. Insert After";
        cout<<"3. Insert Last";
        cout<<"0. Cancel";
        cout<<"Your choice\t: ";
        cin>>iChoice;
        switch(iChoice){
        case 1:
            insertFirstFac(U,AllocateFac(U,name,id));
            menuLoop = false;
            break;
        case 2:
        {
            string ID;
            cout<<"Insert ID\t: ";
            cin>>ID;
            if (FindFacID(U,id) != NULL){
                adrFac Prec = FindFacID(U,id);
                insertAfterFac(U,Prec,AllocateFac(U,name,id));
            } else {
                cout<<"Data doesn't exist, like your GF lol";
            }
            menuLoop = false;
            break;
        }
        case 3:
            insertLastFac(U,AllocateFac(U,name,id));
            menuLoop = false;
            break;
        case 0:
        {
            cout<<"Add faculty canceled!\n";
            menuLoop = false;
            break;
        }
        default:
            cout<<"Wrong Input!\n\n";
            break;
        }
    }while(menuLoop == true);

    return 0;
}

int deleteFctChoice(ListFacilities C){
    int dChoice;
    bool menuLoop = true;
    do {
        cout<<"Choose how you want to insert the data\n\n";
        cout<<"1. Delete First";
        cout<<"2. Delete After";
        cout<<"3. Delete Last";
        cout<<"0. Cancel";
        cout<<"Your choice\t: ";
        cin>>dChoice;
        switch(dChoice){
        case 1:
            deleteFirstFct(C);
            menuLoop = false;
            break;
        case 2:
        {
            string ID;
            cout<<"Insert ID\t: ";
            cin>>ID;
            if (FindFctID(C,ID) != NULL){
                adrFct Prec = FindFctID(C,ID);
                deleteAfterFct(C,Prec);
            } else {
                cout<<"Data doesn't exist, like your GF lol";
            }
            menuLoop = false;
            break;
        }
        case 3:
            deleteLastFct(C);
            menuLoop = false;
            break;
        case 0:
        {
            cout<<"Delete faculty canceled!\n";
            menuLoop = false;
            break;
        }
        default:
            cout<<"Wrong Input!\n\n";
            break;
        }
    }while(menuLoop == true);

    return 0;
}

int deleteFacChoice(University U){
    int dChoice;
    bool menuLoop = true;
    do {
        cout<<"Choose how you want to insert the data\n\n";
        cout<<"1. Delete First";
        cout<<"2. Delete After";
        cout<<"3. Delete Last";
        cout<<"0. Cancel";
        cout<<"Your choice\t: ";
        cin>>dChoice;
        switch(dChoice){
        case 1:
            deleteFirstFac(U);
            menuLoop = false;
            break;
        case 2:
        {
            string ID;
            cout<<"Insert ID\t: ";
            cin>>ID;
            if (FindFacID(U,ID) != NULL){
                adrFac Prec = FindFacID(U,ID);
                deleteAfterFac(U,Prec);
            } else {
                cout<<"Data doesn't exist, like your GF lol";
            }
            menuLoop = false;
            break;
        }
        case 3:
            deleteLastFac(U);
            menuLoop = false;
            break;
        case 0:
        {
            cout<<"Delete faculty canceled!\n";
            menuLoop = false;
            break;
        }
        default:
            cout<<"Wrong Input!\n\n";
            break;
        }
    }while(menuLoop == true);

    return 0;
}

void mainMenu(){
    CreateUniversity(Telkom);
    CreateListFct(C);

    string id;  //ID Faculty
    string name;   //Name Faculty
    string facID,fctID; //for connection
    DataFct X;

    bool menuLoop = true;
    int choice;
    do {
        cout<<"Menu"<<endl;
        cout<<"1. Add Faculty"<<endl;
        cout<<"2. Add Facility"<<endl;
        cout<<"3. Connect Faculty and Facility"<<endl;
        cout<<"4. Check Faculty and Facility's Connection"<<endl;
        cout<<"5. Disconnect Faculty and Facility's Connection"<<endl;
        cout<<"6. Print All Data"<<endl;
        cout<<"7. Print Faculty's Facilities"<<endl;
        cout<<"8. Delete Facility"<<endl;
        cout<<"9. Delete Faculty"<<endl;
        cout<<"10.Book a Facility"<<endl;
        cout<<"11.Show Available Facilities"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Input choice: ";
        cin>>choice;
        switch(choice){
        case 1:
            cout<<"Insert Faculty's Data\n";
            cout<<"Faculty's ID\t\t: "<<endl;
            cin>>id;
            cout<<"Faculty's Name\t\t: "<<endl;
            cin>>name;
            insertFacChoice(Telkom,name,id);
            break;
        case 2:
            X = createFacilities();
            insertFctChoice(C,X);
            break;
        case 3:
        {
            string facID,fctID;
            cout<<"Connect Faculty and Facility\n";
            cout<<"Faculty's ID\t\t: ";
            cin>>facID;
            cout<<"\nFacility's ID\t\t: ";
            cin>>fctID;
            Connect(Telkom,C,facID,fctID);
            break;
        }
        case 4:
        {
            cout<<"Check Faculty's and Facility's connection\n";
            cout<<"Insert Faculty's ID\t\t: ";
            cin>>facID;
            cout<<"\nInsert Facility's ID\t\t: ";
            cin>>fctID;
            CekConnection(Telkom,C,facID,fctID);
            break;
        }
        case 5:
        {
            string facID,fctID;
            cout<<"Disconnect Faculty and Facility\n";
            cout<<"Insert Faculty's ID\t\t: ";
            cin>>facID;
            cout<<"\nInsert Facility's ID\t\t: ";
            cin>>fctID;
            Disconnect(Telkom,C,facID,fctID);
            break;
        }
        case 6:
            PrintAll(Telkom,C);
            break;
        case 7:
        {
            string id;
            cout<<"\nInsert Faculty's ID\t\t: ";
            cin>>id;
            PrintFctOfFac(Telkom,C,id);
            break;
        }
        case 8:
            deleteFctChoice(C);
            break;
        case 9:
            deleteFacChoice(Telkom);
            break;
        case 10:
            BookARoom(Telkom,C);
            break;
        case 0:
            cout<<"Thank You!\n\n";
            menuLoop = false;
            break;
        default:
            cout<<"Wrong input!\n\n";
            break;
        }
        cout<<endl;
    } while(menuLoop == true);
}

int main()
{
    mainMenu();
    return 0;
}
//    University Telkom;
//    CreateUniversity(Telkom);
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

    */

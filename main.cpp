#include <iostream>
#include "List_SequenceForm.h"
#include "List_LinkForm.h"


int main() {

    //Test : the basic function of SqList
    SqList SqList1;
    double test[6]={3.5,6.8,4.5,3.2,1.2,9.9};
    if(InitList_Sq(SqList1)&&ListEmpty_Sq(SqList1)){
        printf("%c",ListLength_Sq(SqList1));
        for(int i=1;i<=6;i++){
            ListInsert_Sq(SqList1,i,test[i-1]);
        }
        double DeletedElem=0;
        ListDelete_Sq(SqList1,5,DeletedElem);
        ListTraverse_Sq(SqList1);
    }


    //Test :Ths basic function of LinkList
    LinkList LkList1;
    InitList_Lk(LkList1);
    InsertElem_Lk(LkList1,3.86,1);
    InsertElem_Lk(LkList1,2.55,2);
    InsertElem_Lk(LkList1,8.99,3);
    InsertElem_Lk(LkList1,1.23,2);

    double DeletedElem=0;
    DlelteElme_Lk(LkList1,DeletedElem,2);
    //test :

    return 0;
}
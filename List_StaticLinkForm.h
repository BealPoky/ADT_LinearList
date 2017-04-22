//
// Created by wzj on 2017/4/20.
// construct a LinkList by Array,Logical LinkList

#ifndef SEQUENCEAP_LIST_STATICLINKFORM_H
#define SEQUENCEAP_LIST_STATICLINKFORM_H

#include "List_SequenceForm.h"

#define ElemType double
#define OK 1
#define SORRY 0
#define MAXSIZE 100
#define LISTINCRAMENT 10
typedef struct {
    int nextpos;
    ElemType data;
}component,SLinkList[MAXSIZE];

Status InitList_SLk(SLinkList &L){
    L->data=0;
    L->nextpos=0;
    return OK;
}

Status InsertElem_SLk(SLinkList &L,ElemType e,int i){
    if(i<1||sent int )
}





#endif //SEQUENCEAP_LIST_STATICLINKFORM_H

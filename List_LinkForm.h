//
// Created by wzj on 2017/4/18.

#ifndef SEQUENCEAP_LIST_LINKFORM_H
#define SEQUENCEAP_LIST_LINKFORM_H

#include "List_SequenceForm.h"

#define OK 1
#define SORRY 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1

#define ElemType double

typedef struct LNode{
    ElemType data;
    struct LNode* next;
}*Link,*Posiiton;          //  the proposal we defne other two names of the node.

typedef struct {
    Link head,tail;        // head : The gead pointer do not stored any data about the List,it next pointer point to the
                           //        first Elem of the List .
                           // tail:  The tail pointer is exactly the last elem.(the tail is the reference of the last Elem)
    int length;
}LinkList;


// Operation: Initialize a vacant List.
Status InitList_Lk(LinkList &L){
    L.head->data=L.tail->data=0;
    L.length=0;
    return OK;
}

//Operation: MakeNode
void MakeNode(Link &p,ElemType e){
    p->data=e;
    p->next=NULL;
}

// Operation: Insert a new Element to the List.
// Description: Insert a new elem whose value is equal to e on the given position i.
Status InsertElem_Lk(LinkList &L,ElemType e,int i){
    if(i<1||i>L.length+1) return OVERFLOW;
    Link insertelem =(Link) malloc(sizeof(LNode));       //  Solve a  very big problem how to apply a memory space in a
                                                         //  function that can be used outside.
    MakeNode(insertelem,e);
    if(i==1||i==L.length+1){
        if(i==1){
            if(L.head->next!=NULL){
                Link temp=L.head->next;
                L.head->next=insertelem;
                insertelem->next=temp->next;
            }//  this case is when the List is not empty list
            else {
                L.head->next = insertelem;
                L.tail=insertelem;
            }
        }
        else{
            L.tail->next=insertelem;
            L.tail=insertelem;
        }
        L.length++;
        return OK;
    }
    else{
        Link cursor= L.head;
        int k=0;
        do{
            cursor=cursor->next;
            k++;
        }while(k<(i-1));
        Link temp=cursor->next;
        cursor->next=insertelem;
        insertelem->next=temp;

        L.length++;
        return OK;
    }
}


//Operation;GetElem
Status GetElem_Lk(LinkList L,ElemType &e,int i){
    Link cursor= L.head;
    int k=0;
    while(k<i&&cursor){
        cursor=cursor->next;
        k++;
    }
    if(k>i||!cursor) return SORRY;
    e= cursor->data;
    return OK;
}

//Operation： Delete a Element.
Status DlelteElme_Lk(LinkList& L,ElemType &e,int i){
    if(i<1||i>L.length+1) return SORRY;
    if(i==1||i==(L.length)){
        if(i==1){
            Link temp= L.head->next;
            L.head->next=L.head->next->next;
            e=temp->data;
            free(temp);
            L.length--;
        }
        else{
            Link cursor= L.head;
            int k=0;
            while(k<(L.length-1)&&cursor){
                cursor=cursor->next;
                k++;
            }
            L.tail->next=cursor;
            e=cursor->next->data;
            free(cursor->next);
            cursor->next=NULL;
            L.length--;
        }
        return OK;
    }
    else{
        Link cursor= L.head;
        int k=0;
        while(k<(i-1)&&cursor){
            cursor=cursor->next;
            k++;
        }
        Link temp= cursor->next;
        cursor->next=cursor->next->next;
        e=temp->data;
        free(temp);
        L.length--;
        return OK;
    }
}












#endif //SEQUENCEAP_LIST_LINKFORM_H

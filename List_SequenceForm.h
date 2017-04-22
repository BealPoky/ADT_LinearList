// This File Manily show a ADT : LinearList Constructed by Sequence Structure.
// Notice that There exist two method to achieve a List : Link , Sequence.
// Want Know More About the Definition of List Please See "Describe the LinearList ".
// Created by wzj on 2017/4/16.


#ifndef SEQUENCEAP_LIST_SEQUENCEFORM_H
#define SEQUENCEAP_LIST_SEQUENCEFORM_H

#include<cstdlib>


#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OK 1
#define SORRY 0
#define OVERFLOW -1

typedef int Status;

//def SqList
typedef struct{
    double *elem;    // the base address of the List.
    int length;      // current list length
    int listsize;    //current allocated stored memory

}SqList;




//Operation:initSqList


Status InitList_Sq(SqList &L){
    // construct a vacant List
    L.elem=(double*) malloc(LIST_INIT_SIZE*sizeof(double));   // allocate 100 elems(type:double)space for the list.
    if(! L.elem)exit (OVERFLOW);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
}

//Opersation DestroyList
Status DestroyList_Sq(SqList &L){
    free(L.elem);
    L.elem=NULL;
    return OK;
}

//Operation: ClearList
Status ClearList_Sq(SqList &L){
    free(L.elem);
    if(InitList_Sq(L)) return OK;
    else return SORRY;
}

//Operation:ListEmpty
Status ListEmpty_Sq(SqList &L){
    if(L.length==0){
        return OK;
    }
    else
        return SORRY;
}

//Operation; ListLength

int ListLength_Sq(SqList L){
    return L.length;
}

//Opertion: GetElement
void GetElement_Sq(SqList L, double &e, int i){
    if(i>=1&&i<=(ListLength_Sq(L)))
        e= *(L.elem+i-1);
    else
        printf("the posion i is illigle");
}

//Operation :LocateElement
  //compare(a,b): if equal return OK,else SORRY.
Status compare(double a,double b){
    if(a==b)
        return OK;
    else
        return SORRY;
}

int LocateElem_Sq(SqList L, double e, Status (*)(double,double)){
    for(int i=1;i<=ListLength_Sq(L);i++){
        if(compare(e,*(L.elem+i-1))) {
            return i;
        }
    }
    return -1;
}
/*
 * Another method to implement this function
 * {
 *   int i=1;
 *   double* p=L.elme;
 *   while(i<=L.lenghth&&!(*compare)(*p++,e)){
 *         ++i;
 *   }
 *   if(i<=L.length){
 *         return i;
 *   }
 *   else{
 *         return SORRY;
 *   }
 * }
 * comment: no more if() but only once!, Amazing improvement in time compared with original function.
*/



//Operation:PriorElem
void PriorElme_Sq(SqList L,double cur_e,double* &pre_e){
    if(LocateElem_Sq(L,cur_e,compare)!=-1) {
        pre_e = L.elem + LocateElem_Sq(L, cur_e, compare) - 2;
    }
    else
        pre_e=NULL;
}
//Operation:NextElem
void NextElme_Sq(SqList L,double cur_e,double* &next_e){
    if(LocateElem_Sq(L,cur_e,compare)!=-1) {
        next_e = L.elem + LocateElem_Sq(L, cur_e, compare);
    }
    else
        next_e=NULL;
}

//Operation:ListInsert
Status ListInsert_Sq(SqList &L,int i,double e){
    if(i<1||i>(ListLength_Sq((L))+1)) {return SORRY;}
    if(ListLength_Sq(L)>=L.listsize){
        // the length of the List is get the maxmium value, must increase the List size
        double* newbase=(double*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(double));
        if(!newbase) exit(OVERFLOW);
        L.elem=newbase;
        L.listsize+=LISTINCREMENT;
    }
    double* q= L.elem+i-1;
    for(double* p=(L.elem+ListLength_Sq(L)-1);p>=q;--p){   //   INthe same Array the Pointer can do the compare operation.
        *(p+1)=*p;                                                   //   such as : p>=q
    }
    *q=e;
    ++L.length;
    return OK;
}

//Operation: ListDelete
Status ListDelete_Sq(SqList &L,int i,double &e){
    if(i<1||i>L.length) return SORRY;
    double* q=L.elem+i-1;
    e=*q;
    double* p=L.elem+L.length-1;
    for(;q<p;++q){
        *q=*(q+1);
    }

    --L.length;
    return OK;
}    // this operation has a problem : the element *(L.elem+L.length-1) still exist although it index has go out of the range.

//Operation: ListTraverse
void ListTraverse_Sq(SqList L){
    for(int i=1;i<=L.length;i++){
        printf("%f",*(L.elem+i-1));
        printf(" ");
    }
}



#endif //SEQUENCEAP_LIST_SEQUENCEFORM_H

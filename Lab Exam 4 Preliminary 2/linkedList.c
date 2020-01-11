#include "linkedList.h"
#define val(x) ((x)->data)
#define next(x) ((x)->next)

/* Functions will be implemensited here */

void printList(Node *head){
    while (head!=NULL) {
      printf("%d",val(head));
      if(next(head)!=NULL){
        printf("->");
      }else;
      head=next(head);
    }
  printf("\n");
}

void insertEnd(Node** list, int data){
  Node *temp;
  Node *new=(Node*)malloc(sizeof(Node));
  temp=*list;
  next(new)=NULL;
  val(new)=data;
  if(temp!=NULL){
    while (next(temp)!=NULL) {
      temp=next(temp);
    }
    next(temp)=new;
  }else{
   *list=new;
  }
}

int occurrences(Node *head, int value){
  int res=0;
  while (head!=NULL) {
    if(value==val(head)){
      res++;
    }else;
    head=next(head);
  }
    return res;
}

\
i

Node* mergeLists(Node *list1, Node *list2){
  /*Node *temp,*ret;
  if(list1==NULL){
    return list2;
  } else if(list2==NULL){
    return list1;
  }else;
  if(val(list1)>val(list2)){
    temp=list2;
    list2=next(list2);
  }else {
    temp=list1;
    list1=next(list1);
  }
  ret=temp;
  while (list1!=NULL&&list2!=NULL) {
    if(val(list1)<val(list2)){
      next(temp)=list1;
      list1=next(list1);
      temp=next(temp);
    }else{
      next(temp)=list2;
      list2=next(list2);
      temp=next(temp);
    }
  }
  if(list1==NULL){
    next(temp)=list2;
  }else{
    next(temp)=list1;
  }
    return ret;
*/
Node *temp=list1;
while(next(temp)){temp=next(temp);}
next(temp)=list2;
return(insertionSort(list1));
}
Node* revhelp(Node *head,Node *prev){
  if(head==NULL){
    return NULL;
  }else if(next(head)==NULL){
    next(head)=prev;
    return prev;
  }else{
    next(revhelp(next(head),head))=prev;
    return prev;
  }
}
Node* reverse(Node *head){
  Node *tmp=head;

  while (next(tmp)!=NULL) {
    tmp=next(tmp);
  }
    revhelp(head,NULL);
    return tmp;
}
 
int isPalindrome(Node *head){
  int len=0,i=0;
  Node *temp,*temp2;
  temp=head;
  while (temp!=NULL) {
    len++;
    temp=next(temp);
  }
  temp=head;
  temp2=head;
  while (len>1) {
    i=0;
    temp2=temp;
    while (i<len-1) {
      temp2=next(temp2);
      i++;
    }
    if(val(temp2)!=val(temp)){
      return 0;
    }else;
    temp=next(temp);
    len=len-2;
  }
    return 1;
}
Node *insert(Node *head,Node *nod){
  Node *t1;
  if(head){
    t1=next(head);
    next(head)=nod;
    next(nod)=t1;
    return head;
  }else{
    return nod;
  }
}
Node *pick(Node **headp){
  Node *ret;
  if (*headp) {
    ret=*headp;
    *headp=next(*headp);
    next(ret)=NULL;
    return ret;
  }else{
    return NULL;
  }
}
Node* insertionSort(Node *head){
  int i=1;
  Node *ret=NULL;
  Node *res;
  Node *temp;
  if(head==NULL){
    return NULL;
  }else {
    ret=pick(&head);
    res=ret;
    while (head) {
      i=1;
      ret=res;
      temp=pick(&head);
      while(ret){
        if((val(ret)<val(temp))&&val(temp)<(next(ret)?(val(next(ret))):100000)){
          insert(ret,temp);
          i=0;
          break;
        }else;
        ret=next(ret);
      }
      if(i){
        next(temp)=res;
        res=temp;
      }else;
      }
    }
    return res;
  }

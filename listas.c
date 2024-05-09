#include <stdio.h>
#include <stdlib.h>

typedef struct list{
  char *word;
  struct list *next;
}list;

typedef list *pointer_list;

void print_all(pointer_list head);
void print_random(pointer_list head, int n);
void clear_all(pointer_list *head);
void add_word(pointer_list *head);
int get_lenght(pointer_list head);

int main(){
  char charc;
  pointer_list head=NULL;
  int i;
  do{
    printf("\nPresione 'c' para agreagar una palabra, 'l' para imprimir la lista, 's' para borrar todo, 'v' para obtener una palabra al azar\n");
    do{
      charc=getchar();
    }while((charc!='c') && (charc!='l') && (charc!='s') && (charc!='v'));
    if(charc=='c')add_word(&head);
    if(charc=='l')print_all(head);
    if(charc=='v'){
      i = get_lenght(head);
      print_random(head, i);
    }
  }while(charc!='s');
  clear_all(&head);
  return 0;
}

void add_word(pointer_list *head){
  pointer_list p= malloc(sizeof (list));
  p->next=*head;
  printf("\nIngrese la nueva palabra\n");
  char *word=(char *)malloc(10);
  scanf("%s",word);
  p->word=word;
  p->next=*head;
  *head=p;
}

void print_all(pointer_list head){
  int i=1;
  printf("\n");
  while(head!=NULL){
    printf("palabra %d: %s \n", i, head->word);
    head=head->next;
    i++;
  }
}

void clear_all(pointer_list *head){
  pointer_list actual;
  while(*head!=NULL){
    actual=*head;
    *head=(*head)->next;
    free(actual->word);
    free(actual);
  }
}

void print_random(pointer_list head, int n){
  int i = rand() % n;
  for(int j=0;j<i; j++){
    head=head->next;
  }
  printf("\nLa palabra elegida al azar: %s\n", head->word);
}

int get_lenght(pointer_list head){
  int i=0;
  while(head!=NULL){
    head=head->next;
    i++;
  }
  return i;
}

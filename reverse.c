#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node* next;
	int data;
};
void create_ll(struct node **ll, int *arr, int sz){
	struct node *tmp=NULL, *prev=NULL;int i;
	for(i = 0; i < sz; i++) {
		tmp=(struct node *)malloc(sizeof(struct node));
		tmp->next=NULL; tmp->data = arr[i]; 
		if(prev!=NULL) { prev->next=tmp;	prev=tmp;}
		else{*ll=tmp; prev=tmp;}
	}
	return;
}

void reverse_ll(struct node **ll) {
	struct node *first=*ll, *st=NULL, *tmp=NULL;
	int firstm  = 1;
	if(*ll != NULL && (*ll)->next !=NULL) {
		for(tmp=(*ll)->next; tmp!=NULL; tmp=st) {
			st = tmp->next; 
			tmp->next = first;
			if(firstm) {first->next = NULL; firstm = 0;}
			first=tmp;
		}
		(*ll) = first;
	}
	return;
}

void display_ll(struct node **ll){
	struct node *tmp=NULL;
	
	if(ll !=NULL) {printf("\n");
		for(tmp=*ll; tmp!=NULL; tmp=tmp->next) {
			printf("%d, ", tmp->data);
		}
		printf("\n---\n");
	}
	return;
}

int main(){
	struct node* ll=NULL;
	int arr[] = {4, 22, 33, 2, 1,2,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,4};
	create_ll(&ll, arr, sizeof(arr)/sizeof(int)); display_ll(&ll);
	reverse_ll(&ll);display_ll(&ll);
}

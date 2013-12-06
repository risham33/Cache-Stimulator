#include <stdio.h>
#include "sim.h"


int check(int che){/*check if provided input is the power of 2*/
		if(che==1) return 0;
		int temp =2; /*to see if input is a power of 2*/
		int ret =1;		/*return what would be the log of 2*/
		while(temp<che){
			temp = temp*2;
			ret++;		
		}

		if(temp==che){
			return ret;
		}
		return -1;
	
	}

void make(int numset, int assoc, struct node ** head){
		/*so we know that this would be the offset*/
		/*setting number of rows*/
			
		head=(struct node **)malloc(sizeof(struct node*)*numset);
		
		}

int fulladd(unsigned long input, int associates){/*this method will add stuff for fully associates*/
		int i = 0; 
		input = input >> offset; 
		struct node * temp = fullas[i];
		if(temp==NULL){\
			temp = malloc(sizeof(struct node));
			temp->tag = input; 
			temp->frequency = nemcount;
			temp->next = NULL;
			return 1;			
			}
			i++;

		while(i<associates){
			if(temp->next==NULL){
				temp->next = malloc(sizeof(struct node));
				temp = temp->next; 
				temp->tag =input;
				temp->next = NULL;
				temp->frequency = memcount;
				return 1;				
				}
			temp = temp->next;
			i++;			
			}
		
		return 0;
		
		}
	
	int add(unsigned long input, int associates, int numsets, struct node ** head){/*adds a node, if it is full, it will return 0 if added, 1*/
		int i = 0; 
		unsigned long tmp = input;
		tmp = tmp>> offset;
		int index = tmp % numsets;
		tmp = tmp >> check(numsets);
		struct node *temp = head[index];
		if(temp==NULL){
			temp = malloc(sizeof(struct node));
			temp->tag = tmp;
			temp->frequency = memcount;
			totalcap--;
			temp->next = NULL;
			return 1;		
		}
		i++;
		while(i<associates){
			if(temp->next==NULL){
				temp->next= malloc(sizeof(struct node));
				temp= temp->next;
				temp->tag = tmp;
				temp->next= NULL;
				totalcap--;
				temp->frequency =memcount;
				return 1;
				}
				temp= temp->next;
				i++;
			}
				
		
		return 0;

	}
	
	
	int find(int setsize, unsigned long upd, struct node ** head){/*true if it is found and false on if it was not found*/
		unsigned long tmp = upd;
		tmp = tmp>> offset;
		int index = tmp % setsize;
		tmp = tmp >> check(setsize);
		struct node* temp = head[index];
			while (temp!=NULL){
				
					if(temp->tag==tmp){
							
						temp->frequency= memcount;
						
						return 1;
						}
						else{
							temp= temp->next;						
						}
					
				}
			
	return 0;
}

void replacement(unsigned long upd, int numset,int associates,struct node ** head, char*type){
	unsigned long tmp = upd;
	tmp = tmp >> offset;
	int index = tmp % numset; 
	tmp = tmp >> check(numset);
	struct node * temp = head[index]; 
	if(temp == NULL){
		add(upd, numset,associates,head);
		return;
		}
	else{
		if(strcmp(type,"FIFO")==0){/*FIFO replacement*/
			head[index]=head[index]->next;
			free(temp);
			add(upd,associates,numset,head);
			return;	}

		else{/*for LRU*/
			int lowest = temp->frequency;
			struct node * low = temp; 
				while(temp!=NULL){/*finding the least recently used hex*/
					if(temp->frequency < lowest)
						lowest = temp->frequency; 						
						temp= temp->next;					
					}
				temp = head[index];/*so temp equals the head of the file*/
					if(temp->frequency==lowest){/*delete the head*/
						head[index]= head[index]->next;
						free(temp);
						add(upd,associates,numset,head);
						return;					
						}
				else{/*not deleting the head*/
					while(temp->next!=NULL&&temp->next->frequency!=lowest)
						temp= temp->next;/*end of this while loop, temp next would be be the least used*/
					if(temp->next!=NULL){	
						low = temp->next;
						temp->next = temp->next->next;
						free(low);
						add(upd,associates,numset,head);
						return;
					}
					else{
						free(temp);
						add(upd,associates,numset,head);
						return;
						}
					}
			
			}

		}	
	
	}

	int indexret(unsigned long upd, int numsets){
		int index; 
		upd = upd >> offset;
		index = upd % numsets;
		return index;
		}

/*show how to free stuff*/
	

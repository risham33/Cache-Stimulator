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

/*struct node ** make(int numset){
		/*so we know that this would be the offset*/
		/*setting number of rows*/
			
		/*head=malloc(sizeof(struct node*)*numset);*/
	/*	struct node ** head = malloc(sizeof(struct node*)*numset);
		return head;
		//l2 = malloc(sizeof(struct node*)*numset2);
		//l3 = malloc(sizeof(struct node*)*numset3);
		//if(associates>1)
		//	fullas = malloc(sizeof(struct node*));
		
		}*/

int fulladd(unsigned long input, int associate, struct node ** fullas){/*this method will add stuff for fully associates*/
		int i = 0; 
		input = input >> offset; 
		struct node * temp = fullas[i];
		fullas[i]=temp;
		if(temp==NULL){
			temp = malloc(sizeof(struct node));
			fullas[i]=temp;
			temp->tag = input; 
			temp->frequency = memcount;
			temp->next = NULL;
			return 1;			
			}
			i++;

		while(i<associate){
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
	
int addl1(unsigned long input, int associate, int numsets, struct node ** l1){/*adds a node, if it is full, it will return 0 if added, 1*/
		int i = 0; 
		unsigned long tmp = input;
		tmp = tmp>> offset;
		int index = tmp%numsets;
		tmp = tmp>>check(numsets);
			struct node *temp = l1[index];
			l1[index]=temp;
//		printf("%d",index);
		
		if(temp==NULL){
	//	  printf("here!");
		  temp = malloc(sizeof(struct node));
			l1[index]=temp;
			temp->tag = tmp;
			temp->frequency = memcount;
			temp->next = NULL;
			return 1;		
		}
		i++;
		while(i<associate){

		 if(temp->next==NULL){
				temp->next= malloc(sizeof(struct node));
				temp= temp->next;
				temp->tag = tmp;
				temp->next= NULL;
				temp->frequency =memcount;
				return 1;
				}
//		printf("l1 data %lx", temp->tag);			temp= temp->next;
				i++;
			}
				
		
		return 0;

	}
/*int addl2(unsigned long input, int associate, int numsets, struct node ** l2){adds a node, if it is full, it will return 0 if added, 1*/
	/*	int i = 0; 
		unsigned long tmp = input;
		tmp = tmp>> offset;
		int index = tmp % numsets;
		tmp = tmp >> check(numsets);
		struct node *temp = l2[index];
		l2[index]=temp;
//		printf("l2 add %d",index);
		
		if(temp==NULL){
//		  printf("here!");
		  temp = malloc(sizeof(struct node));
			l2[index]=temp;
			temp->tag = tmp;
			temp->frequency = memcount;
			temp->next = NULL;
			return 1;		
		}
		i++;
		while(i<associate){
					 
		 if(temp->next==NULL){
				temp->next= malloc(sizeof(struct node));
				temp= temp->next;
				temp->tag = tmp;
				temp->next= NULL;
				temp->frequency =memcount;
				return 1;
				}
		//		printf("l2 added node: %lx",temp->tag);temp= temp->next;
				i++;
			}
				
		
		return 0;

	}
int addl3(unsigned long input, int associate, int numsets, struct node ** l3){/*adds a node, if it is full, it will return 0 if added, 1*/
	/*	int i = 0; 
		unsigned long tmp = input;
		tmp = tmp>> offset;
		int index = tmp % numsets;
		tmp = tmp >> check(numsets);
		struct node *temp = l3[index];
		l3[index]=temp;
	//	printf("l3 add %d",index);
		
		if(temp==NULL){
		//  printf("here!");
		  temp = malloc(sizeof(struct node));
			l3[index]=temp;
			temp->tag = tmp;
			temp->frequency = memcount;
			temp->next = NULL;
			return 1;		
		}
		i++;
		while(i<associate){
		 	
		 if(temp->next==NULL){
				temp->next= malloc(sizeof(struct node));
				temp= temp->next;
				temp->tag = tmp;
				temp->next= NULL;
				temp->frequency =memcount;
				return 1;
				}
	//			printf("l3 added node: %lx\n",temp->tag); 	temp= temp->next;
				i++;
			}
				
	//	printf("l3 added node: %lx",temp->data); 
		return 0;

	}*/
	
int findl1(int setsize, unsigned long upd, struct node ** l1){/*true if it is found and false on if it was not found*/
		unsigned long tmp = upd;
		tmp = tmp>> offset;
		int index = tmp % setsize;
		tmp = tmp >> check(setsize);
	//	printf("%d",index);
		if(l1[index]!=NULL){
	//	printf("I entered here\n");
		struct node* temp = l1[index];
			while (temp!=NULL){
				
					if(temp->tag==tmp){
							
						temp->frequency= memcount;
						
						return 1;
						}
						else{
							temp= temp->next;						
						}
					
				}
			}
	return 0;
}
/*int findl2(int setsize, unsigned long upd, struct node ** l2){/*true if it is found and false on if it was not found*/
	/*	unsigned long tmp = upd;
		tmp = tmp>> offset;
		int index = tmp % setsize;
		tmp = tmp >> check(setsize);
	//	printf("%d",index);
		if(l2[index]!=NULL){
		struct node* temp = l2[index];
			while (temp!=NULL){
				
					if(temp->tag==tmp){
							
						temp->frequency= memcount;
						
						return 1;
						}
						else{
							temp= temp->next;						
						}
					
				}
			}
	return 0;
}

/*int findl3(int setsize, unsigned long upd, struct node ** l3){/*true if it is found and false on if it was not found*/
	/*	unsigned long tmp = upd;
		tmp = tmp>> offset;
		int index = tmp % setsize;
		tmp = tmp >> check(setsize);
//		printf("%d",index);
		if(l3[index]!=NULL){
		struct node* temp = l3[index];
			while (temp!=NULL){
				
					if(temp->tag==tmp){
							
						temp->frequency= memcount;
						
						return 1;
						}
						else{
							temp= temp->next;						
						}
					
				}
			}
	return 0;
}*/
int findfull(int setsize, unsigned long upd, struct node ** fullas){/*true if it is found and false on if it was not found*/
		unsigned long tmp = upd;
		tmp = tmp>> offset;
		int index = tmp % setsize;
		tmp = tmp >> check(setsize);
	//	printf("%d",index);
		if(fullas[index]!=NULL){
		struct node* temp = fullas[index];
			while (temp!=NULL){
				
					if(temp->tag==tmp){
							
						temp->frequency= memcount;
						
						return 1;
						}
						else{
							temp= temp->next;						
						}
					
				}
			}
	return 0;
}


void replacementl1(unsigned long upd, int numset,int associate,char*type, struct node **l1){
	unsigned long tmp = upd;
	tmp = tmp >> offset;
	int index = tmp % numset; 
	tmp = tmp >> check(numset);
	struct node * temp = l1[index]; 
	if(temp == NULL){
		addl1(upd,associate,numset,l1);
		return;
		}
	else{
		if(strcmp(type,"FIFO")==0){/*FIFO replacement*/
			l1[index]=l1[index]->next;
			free(temp);
			addl1(upd,associate,numset,l1);
			return;	}

		else{/*for LRU*/
			int lowest = temp->frequency;
			struct node * low = temp; 
				while(temp!=NULL){/*finding the least recently used hex*/
					if(temp->frequency < lowest)
						lowest = temp->frequency; 						
						temp= temp->next;					
					}
				temp = l1[index];/*so temp equals the head of the file*/
					if(temp->frequency==lowest){/*delete the head*/
						l1[index]= l1[index]->next;
						free(temp);
						addl1(upd,associate,numset,l1);
						return;					
						}
				else{/*not deleting the head*/
					while(temp->next!=NULL&&temp->next->frequency!=lowest)
						temp= temp->next;/*end of this while loop, temp next would be be the least used*/
					if(temp->next!=NULL){	
						low = temp->next;
						temp->next = temp->next->next;
						free(low);
						addl1(upd,associate,numset,l1);
						return;
					}
					else{
						free(temp);
						addl1(upd,associate,numset,l1);
						return;
						}
					}
			
			}

		}	
	
	}
/*void replacementl2(unsigned long upd, int numset,int associate, char*type, struct node ** l2){
	unsigned long tmp = upd;
	tmp = tmp >> offset;
	int index = tmp % numset; 
	tmp = tmp >> check(numset);
	struct node * temp = l2[index]; 
	if(temp == NULL){
		addl2(upd,associate,numset,l2);
		return;
		}
	else{
		if(strcmp(type,"FIFO")==0){/FIFO replacement*/
	/*		l2[index]=l2[index]->next;
			free(temp);
			addl2(upd,associate,numset,l2);
			return;	}

		else{*for LRU*/
		/*	int lowest = temp->frequency;
			struct node * low = temp; 
				while(temp!=NULL){/*finding the least recently used hex*/
			/*		if(temp->frequency < lowest)
						lowest = temp->frequency; 						
						temp= temp->next;					
					}
				temp = l2[index];/*so temp equals the head of the file*/
				/*	if(temp->frequency==lowest){/*delete the head*/
					/*	l2[index]= l2[index]->next;
						free(temp);
						addl2(upd,associate,numset,l2);
						return;					
						}
				else{/*not deleting the head*/
				/*	while(temp->next!=NULL&&temp->next->frequency!=lowest)
						temp= temp->next;/*end of this while loop, temp next would be be the least used*/
				/*	if(temp->next!=NULL){	
						low = temp->next;
						temp->next = temp->next->next;
						free(low);
						addl2(upd,associate,numset,l2);
						return;
					}
					else{
						free(temp);
						addl2(upd,associate,numset,l2);
						return;
						}
					}
			
			}

		}	
	
	}

void replacementl3(unsigned long upd, int numset,int associate, char*type, struct node ** l3){
	unsigned long tmp = upd;
	tmp = tmp >> offset;
	int index = tmp % numset; 
	tmp = tmp >> check(numset);
	struct node * temp = l3[index]; 
	if(temp == NULL){
		addl3(upd,associate,numset,l3);
		return;
		}
	else{
		if(strcmp(type,"FIFO")==0){/*FIFO replacement*/
		/*	l3[index]=l3[index]->next;
			free(temp);
			addl3(upd,associate,numset,l3);
			return;	}

		else{/*for LRU*/
		/*	int lowest = temp->frequency;
			struct node * low = temp; 
				while(temp!=NULL){/*finding the least recently used hex*/
			/*		if(temp->frequency < lowest)
						lowest = temp->frequency; 						
						temp= temp->next;					
					}
				temp = l3[index];/*so temp equals the head of the file*/
				/*	if(temp->frequency==lowest){/*delete the head*/
					/*	l3[index]= l3[index]->next;
						free(temp);
						addl3(upd,associate,numset,l3);
						return;					
						}
				else{/*not deleting the head*/
					/*while(temp->next!=NULL&&temp->next->frequency!=lowest)
						temp= temp->next;/*end of this while loop, temp next would be be the least used*/
				/*	if(temp->next!=NULL){	
						low = temp->next;
						temp->next = temp->next->next;
						free(low);
						addl3(upd,associate,numset,l3);
						return;
					}
					else{
						free(temp);
						addl3(upd,associate,numset,l3);
						return;
						}
					}
			
			}

		}	
	
	}*/

void replacementfullas(unsigned long upd, int numset,int associate, char*type, struct node** fullas){
	unsigned long tmp = upd;
	tmp = tmp >> offset;
	int index = tmp % numset; 
	tmp = tmp >> check(numset);
	struct node * temp = fullas[index]; 
	if(temp == NULL){
		fulladd(upd,associate,fullas);
		return;
		}
	else{
		if(strcmp(type,"FIFO")==0){/*FIFO replacement*/
			fullas[index]=fullas[index]->next;
			free(temp);
			fulladd(upd,associate,fullas);
			return;	}

		else{/*for LRU*/
			int lowest = temp->frequency;
			struct node * low = temp; 
				while(temp!=NULL){/*finding the least recently used hex*/
					if(temp->frequency < lowest)
						lowest = temp->frequency; 						
						temp= temp->next;					
					}
				temp = fullas[index];/*so temp equals the head of the file*/
					if(temp->frequency==lowest){/*delete the head*/
						fullas[index]= fullas[index]->next;
						free(temp);
						fulladd(upd,associate,fullas);
						return;					
						}
				else{/*not deleting the head*/
					while(temp->next!=NULL&&temp->next->frequency!=lowest)
						temp= temp->next;/*end of this while loop, temp next would be be the least used*/
					if(temp->next!=NULL){	
						low = temp->next;
						temp->next = temp->next->next;
						free(low);
						fulladd(upd,associate,fullas);
						return;
					}
					else{
						free(temp);
						fulladd(upd,associate,fullas);
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
	
void fre(struct node **l1, struct node ** l2, struct node ** l3, struct node ** fullas){
/*show how to free stuff*/

	int i =0;int d;
	struct node * temp;
	struct node * next;
		while(i<numset1){
			temp = l1[i];
				d=0;

				while(d<associates&&temp!=NULL){
						next = temp->next;
						free(temp);
						temp= next;
						d++;					
					}
					i++;	
			}

			free(l1);/*for l1*/
   i =0;
		while(i<numset2){
			temp = l2[i];
				d=0;

				while(d<as2&&temp!=NULL){
						next = temp->next;
						free(temp);
						temp= next;
						d++;					
					}
					i++;	
			}

			free(l2);/*for l2*/
 i =0;
 
 while(i<numset3){
			temp = l3[i];
				d=0;

				while(d<as3&&temp!=NULL){
						next = temp->next;
						free(temp);
						temp= next;
						d++;					
					}
					i++;	
			}

			free(l3);/*for l3*/

i =0;	
			temp = fullas[i];
				d=0;

				while(d<fullasso&&temp!=NULL){
						next = temp->next;
						free(temp);
						temp= next;
						d++;					
					}
						
			

			free(fullas);/*for fully associative*/

	}

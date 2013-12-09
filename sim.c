#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "methods.h"

int help(){/*this will be printed out whem -h is inputed*/
	printf("Welcome, to use this program you would need to learn certain rules\n");
	printf("if you input [-h] like you did now, this help message would print out\nIf you put 1, L1 information will be printed out\nif you put 2, L2 information will be printed out\nif you put 3, L3 information will be printed out\n");
	printf("if you input anything else  all the information about L1, L2, L3 caches and memory will be printed\n");
	printf("your input line should be of this form:\ncache-sim [-h] -l1size <L1 size> -l1assoc <L1 assoc> -l2size <L2 size> -l2assoc <L2 assoc> -l3size <L3 size> -l3assoc <L3 assoc> <block size> <replace alg> <trace file>\nFor replace alg, put either FIFO or LRU\nThank you!");

	return 0;	
	}

int main(int argc, char*argv[]){
	
	if(strcmp(argv[1],"[-h]")==0) {/*help called*/
			help();
			return 0;
		
		}
	
	if(argc!=17){/*if inputs are incorrect*/
			fprintf(stderr,"ERROR: INCORRECT NUMBER OF INPUTS.\n");
			return 0;}
	
	size1 = atoi(argv[3]);/*l1 size*/
	associates = atoi(argv[5]); /*associative of l1*/
	size2 = atoi(argv[7]);/*l2 size*/
	as2 = atoi(argv[9]);/*associative of l2*/
	size3 = atoi(argv[11]);/*l3 size*/
	as3 = atoi(argv[13]);/*associative of l3*/
	block = atoi(argv[14]);/*block size*/

		//printf("%s %s %d %s %d %s %d %s %d %s %d %s %d %d %s %s", argv[1],argv[2],size1,argv[4],associates,argv[6],size2,argv[8],as2,argv[10],size3,argv[12],as3,block,argv[15],argv[16]);




	if(strcmp(argv[2],"-l1size")!=0||size1<0||strcmp(argv[4],"-l1assoc")!=0||associates<1||strcmp(argv[6],"-l2size")!=0||size2<0||strcmp(argv[8],"-l2assoc")!=0||as2<1||strcmp(argv[10],"-l3size")!=0||size3<0||strcmp(argv[12],"-l3assoc")!=0||as3<1||block<1||(strcmp(argv[15],"FIFO")!=0 && strcmp(argv[15],"LRU")!=0)||size1>=size2||size1>=size3||size2>=size3){
		/*if any input is wrong*/
			fprintf(stderr,"ERROR: INCORRECT INPUT\n");
			return 0;
		}
	
	/*CHECK FOR TRACE FILE*/
		FILE *pfi; /*text file open*/
		pfi = fopen(argv[16],"r");

	if(pfi==NULL){/*if the file does not exist*/
			fprintf(stderr,"ERROR: File does not exist!\n");
			return 0;		
		}

		memcount =0;
		unsigned long temp; /*this would store and read hexadecimeals from text*/
		
		if(size1<block || size2<block || size3<block){
			fprintf(stderr,"ERROR: size is smaller than block size\n");
			return 0;
			}
		/*check if it is a power of two*/
			offset = check(block); /*power of 2 for block, also this is how many unit moved to right*/
			numset1 = size1/(associates*block);
			numset2 = size2/(as2*block);
			numset3 = size2/(as3*block);


//printf("%d \n%d \n%d \n%d",check(numset1),check(size2),check(size3),check(size1));
			

			if(offset==-1||check(size1)==-1||check(size2)==-1||check(size3)==-1||check(numset1)==-1||check(numset2)==-1||check(numset3)==-1){
				fprintf(stderr,"ERROR: invalid entry for size\n");
				return 0;
				}

			/*make all the caches also define total capacity management, all the misses, hits, cold misses, l1 miss, l2 miss, hits for all, capacity miss, capacity updates*/
			struct node ** l1 = (struct node **) malloc(sizeof(struct node*)*numset1);
			struct node ** l2 = (struct node **) malloc(sizeof(struct node *)*numset2);
			struct node ** l3 = (struct node **) malloc(sizeof(struct node *)*numset3);
			fullasso = size1/block;
			struct node ** fullas = (struct node **) malloc(sizeof(struct node *)*fullasso);

		/*	if(numset1>1){
			  struct node ** fullas = make(1);
			  fullasso = size1/block;
			}
			else
			  struct node ** fullas;
			*/		
			missesl1 = 0; missesl2 =0; missesl3 = 0; hitsl1 =0 ; hitsl2 =0; hitsl3 = 0 ; coldmiss = 0; coldmiss2 = 0; coldmiss3 = 0;	
		
while(fscanf(pfi,"%lx",&temp)!=EOF){
			memcount++;
			

			if(findl1(numset1,temp,l1)==0){
					missesl1++;/*here replace and storing it to different cache needs to be implemented*/
			//		printf("\nmissesl1 %d\n",missesl1);
					//return 0;
				/*for fully associative cache*/
					if(numset1>1){
				
						if(fulladd(temp,fullasso,fullas)==0){
							capacity++;
							replacementfullas(temp,1,fullasso,argv[15],fullas);}
				//			 printf("capacity %d\n",capacity);
							 //return 0;
						}

												
					if(addl1(temp,associates,numset1,l1)==0){
						/*replacement l1
						printf("add is");*/
						
							replacementl1(temp,numset1,associates,argv[15],l1);					
						}
				
					
					else {coldmiss++;
					}
						
						/*L2*/
						if(findl1(numset2,temp,l2)==0) {
						  
						  
							missesl2++;

							if(addl1(temp,as2,numset2,l2)==0)
								replacementl1(temp,numset2,as2,argv[15],l2);

							else coldmiss2++;	
								
									/*L3*/
							if(findl1(numset3,temp,l3)==0) {
								missesl3++;
							  
								if(addl1(temp,as3,numset3,l3)==0)/*replacement stategy*/
									replacementl1(temp,numset3,as3,argv[15],l3);				
							
							
								else coldmiss3++;
								
							}
								
						else 	hitsl3++;
											
					
				}
						/*L2*/	
				else hitsl2++;

				}
			/*l1*/
			else hitsl1++;
			
			
			}
			
			conflict =0;
			
			if(numset1>1){				
				conflict = missesl1 - capacity - coldmiss;
						}
			else
				capacity = missesl1 - coldmiss;


			fclose(pfi);


printf("%s",argv[1]);

if(atoi(argv[1])==1)
	printf("Memory accesses: %d\nL1 Cache hits: %d\nL1 Cache miss: %d\nL1 Cold misses: %d\nL1 Conflict misses: %d\nL1 Capacity misses: %d",memcount,hitsl1,missesl1,coldmiss,conflict,capacity);
else if(atoi(argv[1])==2)
printf("Memory accesses: %d\nL2 Cache hits: %d\nL2 Cache miss: %d\nL2 Cold misses: %d",memcount,hitsl2,missesl2,coldmiss2);
else if(atoi(argv[1])==3)
printf("Memory accesses: %d\nL3 Cache hits: %d\nL3 Cache miss: %d\nL3 Cold misses: %d",memcount,hitsl3,missesl3,coldmiss3);

else {/*if(strcmp(argv[1],"[-a]")) printf("hello");
	if(strcmp(argv[1],"[-all]")){
			printing*/
			printf("Memory accesses: %d\nL1 Cache hits: %d\nL1 Cache miss: %d\nL2 Cache hits: %d\nL2 Cache miss: %d\nL3 Cache hits: %d\nL3 Cache miss: %d\nL1 Cold misses: %d\nL2 Cold misses: %d\nL3 Cold misses: %d\nL1 Conflict misses: %d\nL1 Capacity misses: %d",memcount,hitsl1,missesl1,hitsl2,missesl2,hitsl3,missesl3,coldmiss,coldmiss2,coldmiss3,conflict,capacity);
			
			
		/*	if(strcmp(argv[1],"[-l1]"))
			  printf("L1 Cache hits: %d\nL1 Cache miss: %d\nL1 Cold misses: %d\nL1 Conflict misses: %d\nL1 Capacity misses: %d",hitsl1,missesl1,coldmiss,conflict,capacity);
		
			if(strcmp(argv[1],"[-l2]"))
			  printf("L2 Cache hits: %d\nL2 Cache miss: %d\nL2 Cold misses: %d",hitsl2,missesl2,coldmiss2);
			
			if(strcmp(argv[1],"[-l3]"))
			  printf("L3 Cache hits: %d\nL3 Cache miss: %d\nL3 Cold misses: %d",hitsl3,missesl3,coldmiss3);
			freeing stuff*/}
		fre(l1,l2,l3,fullas);
		return 0;	
		
		}

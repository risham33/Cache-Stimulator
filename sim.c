#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "methods.h"


int help(){/*this will be printed out whem -h is inputed*/
	printf("Welcome, to use this program you would need to learn certain rules\n");
	printf("if you input [-h] like you did now, this help message would print out\nIf you put 1, L1 information will be printed out\nif you put 2, L2 information will be printed out\nif you put 3, L3 information will be printed out\n");
	printf("if you input anything else  all the information about L1, L2, L3 caches and memory will be printed\n");
	printf("your input line should be of this form:\ncache-sim [-h] -l1size <L1 size> -l1assoc <L1 assoc> -l2size <L2 size> -l2assoc <L2 assoc> -l3size <L3 size> -l3assoc <L3 assoc> <block size> <replace alg> <trace file>\nFor replace alg, put either FIFO or LRU\nyou would you need to enter either direct assoc or assoc:n for <L1,L2,L3 assoc>\nThank you!");

	return 0;	
	}

int main(int argc, char*argv[]){
	
	if(strcmp(argv[1],"[-h]")==0) {/*help called*/
			help();
			return 0;
		
		}
if(argc<15){	
		fprintf(stderr,"ERROR: INCORRECT NUMBER OF INPUTS.\n");
			return 0;}
size1 =0; size2 =0; size3 = 0; associates =0; as2=0; as3=0; numset1=0; numset2=0; numset3=0; 

int i =0; replace = 0;

while(i<argc){ /*scanning values*/
	if(strcmp(argv[i],"-l1size")==0){
		size1 = atoi(argv[i+1]);
		}
	else if(strcmp(argv[i],"-l1assoc")==0){
		
		if(strcmp(argv[i+1],"direct")==0){
			associates = 1;
			}
		else if(strcmp(argv[i+1],"assoc")==0){
			numset1=1;
			}
		else{
			associates = atoi(argv[i+1]+6);
			}
				
		}/*l1 if statements ends*/
	if(strcmp(argv[i],"-l2size")==0){
		size2 = atoi (argv[i+1]);		
		}
	else if(strcmp(argv[i],"-l2assoc")==0){
		if(strcmp(argv[i+1],"direct")==0){
			numset2=1;
			as2 = 1;
			}
		else if(strcmp(argv[i+1],"assoc")==0){
			numset2=1;
			}
		else{
			as2 = atoi(argv[i+1]+6);
			}
		}
	else if(strcmp(argv[i],"-l3size")==0){
		size3 = atoi(argv[i+1]);
		}	
	else if(strcmp(argv[i],"-l3assoc")==0){
		if(strcmp(argv[i+1],"direct")==0){
			as3 = 1;
			}
		else if(strcmp(argv[i+1],"assoc")==0){
			numset3=1;
			}
		else{
			as3 = atoi(argv[i+1]+6);
			}
		block = atoi(argv[i+2]);
	}	
	
	else if(strcmp(argv[i],"FIFO")==0){
		replace =1;
		}
i++;
}

//printf("%d %d ",numset2,as2);

if(block==0){ /*error check*/
			fprintf(stderr,"ERROR: INCORRECT INPUT\n");
			return 0;
	}

if(numset1 == 1){/*number of set for l1 == 1, fully assoc*/
	associates = size1/block;
	} 
else if(associates==1){/*number of set l1 is direct*/
	numset1 = size1/block;
	if(numset1>1)
	fullasso=size1/block;
	}	
else if (associates>1){ /*else its set assoc*/
	numset1 = size1/(block*associates);
	if(numset1>1)	fullasso = size1/block;
	}	
if(numset2==1){/*l2 assoc*/
	as2 = size2/block;
	}
else if(as2==1){/*l2 direct*/
	numset2 = size2/block;
	}
else if (as2>1){/*l2 set assoc*/
		numset2= size2/(block*as2);
	}	
if(numset3==1){/*l3 assoc*/
		as3 = size3/block;
	}
else if(as3==1){/*l3 direct*/
	numset3 = size3/block;
	}
else if (as3>1){/*l3 set assoc*/
	numset3 = size3/(as3*block);
	}	

offset = check(block); /*setting offset*/
totalcapacity = numset1*associates;

		if(numset1==0||numset2==0||numset3==0||associates==0||as2==0||as3==0||check(numset1)==-1||check(numset2)==-1||check(numset3)==-1||offset==-1){
		
		fprintf(stderr,"ERROR: INCORRECT INPUT\n");
			return 0;
		}/*error checking*/
	
	/*CHECK FOR TRACE FILE*/
		FILE *pfi; /*text file open*/
		pfi = fopen(argv[argc-1],"r");

	if(pfi==NULL){/*if the file does not exist*/
			fprintf(stderr,"ERROR: File does not exist!\n");
			return 0;		
		}

		memcount =0;/*keep track of memory accesses*/
		unsigned long long temp; /*this would store and read hexadecimeals from text*/

		if(size1<block || size2<block || size3<block||size1>size2||size2>size3||size1>size3){
			fprintf(stderr,"ERROR: size is smaller \n");
			return 0;
			} /*to see if there is a cache size hierarchy */
			

		
			/*make all the caches also define total capacity management, all the misses, hits, cold misses, l1 miss, l2 miss, hits for all, capacity miss, capacity updates*/
			struct node**  l1 = (struct node **) malloc(sizeof(struct node*)*numset1);
			
				int associat = 0; int num = 0; 
				while(num<numset1){/*l1 memory allocation*/
					associat=1;
					l1[num]=(struct node *) malloc(sizeof(struct node)*associates);
					l1[num][0].frequency = 0;
					l1[num][0].tag = 0;
					while(associat<associates){
						l1[num][associat].frequency=0;					
						l1[num][associat].tag=0;
						associat++;
						}
					num++;
					
					}
		
//printf("%d %d %d %d %d\n",numset2,numset3,as2,as3,fullasso);

			struct node ** l2 = (struct node **) malloc(sizeof(struct node *)*numset2);
					num = 0;
				while(num<numset2){ /*l2 memory allocation*/
					l2[num]=(struct node *)malloc(sizeof(struct node)*as2);
					l2[num][0].frequency = 0;
					l2[num][0].tag=0;
					associat=1;
					while(associat<as2){
						l2[num][associat].frequency = 0;
						l2[num][associat].tag=0;
						associat++;
						//printf("%d\n",associat);
						}
					num++;
					
					}
		
			
		struct node ** l3 = (struct node **) malloc(sizeof(struct node *)*numset3); 
			num=0;
			while(num<numset3){/*for l3 memory location*/
					l3[num]=malloc(sizeof(struct node)*as3);
					l3[num][0].frequency = 0;
					l3[num][0].tag=0;
					associat=1;
					while(associat<as3){
						l3[num][associat].frequency = 0;
						l3[num][associat].tag=0;
						associat++;
						}
					num++;
					
					}
		

			struct node ** fullas = (struct node **) malloc(sizeof(struct node *));
		if(numset1>1){/*memory for fully l1 associate*/
					fullas[0]=malloc(sizeof(struct node)*fullasso);
					fullas[0][0].frequency = 0;
					fullas[0][0].tag=0;
					associat=1;
					while(associat<fullasso){
					fullas[0][associat].frequency = 0;
					fullas[0][associat].tag=0;
				//	printf("%d \n",associat);
					associat++;
						}
							
					}
	
			missesl1 = 0; missesl2 =0; missesl3 = 0; hitsl1 =0 ; hitsl2 =0; hitsl3 = 0 ; coldmiss = 0; coldmiss2 = 0; coldmiss3 = 0;	
			int check = 0; int count= 0; 

while(fscanf(pfi,"%llx",&temp)!=EOF){
			memcount++;
			check = findl1(numset1,temp,associates,l1);
			if(check==1){/*l1 hit and over*/
				hitsl1++;
				continue;				
				}

			else {/*l1 misses*/
					missesl1++;
					check = addl1(temp,l1);
					if(check==1){
						coldmiss++;
						}else{
							
							//if(numset1>1){
								//check = checkspace(l1);

								//if(check==1){
								//	conflict++;}
								//else{
								//	capacity++;}

				//	}
						replacementl1(temp,l1);
							}
						}	
	//	if(totalcapacity==0) count++;


		//if(numset1>1){
		//	check = findfull(temp,fullas);
			//	if(check==0){/*you want to add to fully associate*/	
			//		check = fulladd(temp,fullas);
			//			if(check==0){
			//				capacity++;
				//			replacementfullas(temp,fullas);
					//		}
			//		}
					
	//}
		check = findl1(numset2,temp,as2,l2);

			if(check ==1){/*finiding stuff in l2*/
					hitsl2++;
					continue;
				}
			
			else {
				missesl2++;
				
				check = addl2(temp,l2);

				if(check == 1){
					coldmiss2++;
					}
				else{

					replacementl2(temp,l2);
					}	
			/*	check = findl1(numset3,temp,l3);*/
				}

			check = findl1(numset3,temp,as3,l3);
			
			if(check==1){
				hitsl3++;
				continue;
				}
			
			else{
				missesl3++;

				check = addl3(temp,l3);

				if(check==1){
					coldmiss3++;					
					}
				else{
					replacementl3(temp,l3);
					}
					}
				}

		conflict =0;
			
//		printf("%d",count);
	//	if(numset1>1){				
		//		conflict = missesl1 - capacity - coldmiss;
					//	}
		//else{
			if(numset1==1){
			capacity = missesl1 - coldmiss;
				}

			fclose(pfi);



if(atoi(argv[1])==1){
	printf("Memory accesses: %d\nL1 Cache hits: %d\nL1 Cache miss: %d\nL1 Cold misses: %d\nL1 Conflict misses: %d\nL1 Capacity misses: %d",memcount,hitsl1,missesl1,coldmiss,conflict,capacity);
}


else if(atoi(argv[1])==2){
printf("Memory accesses: %d\nL2 Cache hits: %d\nL2 Cache miss: %d\nL2 Cold misses: %d",memcount,hitsl2,missesl2,coldmiss2);
}

else if(atoi(argv[1])==3){
printf("Memory accesses: %d\nL3 Cache hits: %d\nL3 Cache miss: %d\nL3 Cold misses: %d",memcount,hitsl3,missesl3,coldmiss3);
}

else {printf("Memory accesses: %d\nL1 Cache hits: %d\nL1 Cache miss: %d\nL2 Cache hits: %d\nL2 Cache miss: %d\nL3 Cache hits: %d\nL3 Cache miss: %d\nL1 Cold misses: %d\nL2 Cold misses: %d\nL3 Cold misses: %d\nL1 Conflict misses: %d\nL1 Capacity misses: %d",memcount,hitsl1,missesl1,hitsl2,missesl2,hitsl3,missesl3,coldmiss,coldmiss2,coldmiss3,conflict,capacity);
		}
		fre(l1,l2,l3,fullas); /*freeing memory*/
		return 0;	
		
		}

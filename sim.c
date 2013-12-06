#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "L1.h"




int help(){/*this will be printed out whem -h is inputed*/
	printf("Welcome, to use this program you would need to learn certain rules\n");
	printf("if you input -h like you did now, this help message would print out\n");
	printf("if you input -a all the information about L1, L2, L3 caches will be printed\n");
	printf("if you input -1 all the information about L1 cache would be printed\nand similarly -2 for L2 and -3 for L3\nyour input line should be of this form:\ncache-sim [-h] -l1size <L1 size> -l1assoc <L1 assoc> -l2size <L2 size> -l2assoc <L2 assoc> -l3size <L3 size> -l3assoc <L3 assoc> <block size> <replace alg> <trace file>\nFor replace alg, put either FIFO or LRU\nThank you!");

	return 0;	
	}

int main(int argc, char*argv[]){
	
	if(strcmp(argv[1],"[-h]")==0) {/*help called*/
			help();
			return 0;
		
		}
	fprintf(stderr,"%s",argv[1]);
	if(argc!=16){/*if inputs are incorrect*/
			fprintf(stderr,"ERROR: INCORRECT NUMBER OF INPUTS.");
			return 0;}
	
	size1 = atoi(argv[3]);/*l1 size*/
	associates = atoi(argv[5]); /*associative of l1*/
	size2 = atoi(argv[7]);/*l2 size*/
	as2 = atoi(argv[9]);/*associative of l2*/
	size3 = atoi(argv[11]);/*l3 size*/
	as3 = atoi(argv[13]);/*associative of l3*/
	block = atoi(argv[14]);/*block size*/


	if(strlen(argv[1])!=3||strcmp(argv[2],"-l1size")!=0||size1<0||strcmp(argv[4],"-l1assoc")!=0||associates<1||strcmp(argv[6],"-l2size")!=0||size2<0||strcmp(argv[8],"-l2assoc")!=0||as2<1||strcmp(argv[10],"-l3size")!=0||size3<0||strcmp(argv[12],"-l3assoc")!=0||as3<1||block<=8||(strcmp(argv[15],"FIFO")!=0 && strcmp(argv[15],"LRU")!=0)||size1>=size2||size1>=size3||size2>=size3){
		/*if any input is wrong*/
			fprintf(stderr,"ERROR: INCORRECT INPUT");
			return 0;
		}
	
	/*CHECK FOR TRACE FILE*/
		FILE *pfi; /*text file open*/
		pfi = fopen(argv[16],"r");

	if(pfi==NULL){/*if the file does not exist*/
			fprintf(stderr,"ERROR: File does not exist!");
			return 0;		
		}

		memcount =0;
		unsigned long temp; /*this would store and read hexadecimeals from text*/
		
		if(size1<block || size2<block || size3<block){
			fprintf(stderr,"ERROR: size is smaller than block size");
			return 0;
			}
		/*check if it is a power of two*/
			offset = check(block); /*power of 2 for block, also this is how many unit moved to right*/
			numset1 = size1/(associates*block);
			numset2 = size2/(as2*block);
			numset3 = size2/(as3*block);
			
			if(offset==-1||check(size1)==-1||check(size2)==-1||check(size3)==-1||check(numset1)==-1||check(numset2)==-1||check(numset3)==-1){
				fprintf(stderr,"ERROR: invalid entry for size");
				return 0;
				}

			/*make all the caches also define total capacity management, all the misses, hits, cold misses, l1 miss, l2 miss, hits for all, capacity miss, capacity updates*/
			make(numset1,associates,l1);
			make(numset2,as2,l2);
			make(numset3,as3,l3);

			if(associates==1){/*making fully associative*/
				fullasso = size1/block;
				make(1,fullasso,fullas);
				}
		
		while(fscanf(pfi,"%lx",&temp)!=EOF){
			memcount++;
			if(find(numset1,temp,l1)==0){/*here try to see if you can implement cold misses*/
					missesl1++;/*here replace and storing it to different cache needs to be implemented*/
					continue;
					if(find(numset2,temp,l2)==0) {
						missesl2++;

						if(totalcapacity1==0)capacity++;/*check for capacity miss*/

						if(associates==1){
							
							
							
							}
							
							if(find(numset3,temp,l3)==0) {
							missesl3++;
							if(totalcapacity1==(numset1*associates)&&totalcapacity2==(numset2*as2)&&totalcapacity3==(numset3*as3))
							coldmiss++; 
								if(add(temp,associates,numset1,totalcapacity1,l1)==0){/*replacement stategy*/
													
						}
					}
						else {
						/*could have capacity or conflict miss. try that. and replacement in l2 and l1*/
							hitsl3++;
							replacement(temp,numset1,associates,l1);
							replacement(temp,numset2,as2,l2);
					}
					
				}
				else {
				/*here still capacity or conflict miss check and then replacement in l1*/
				/*call find on everything else too, you want the frequency to increase*/
				
				hitsl2++;}
				}
			else hitsl1++;
			
			
			}
	
	}

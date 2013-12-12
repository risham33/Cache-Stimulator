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


int fulladd(unsigned long long input,struct node ** fullas){/*this method will add stuff for fully associates*/
		int i = 0; 
		unsigned long long tmp = input;
		tmp = tmp >> offset;
		
		tmp = tmp >> check(numset1);
	
		
while(i<fullasso){
		 
			if(fullas[0][i].frequency==0){

				fullas[0][i].tag = tmp;
			
				fullas[0][i].frequency =memcount;
				return 1;
				}
				i++;
			}
				
	
		return 0;


}

int checkspace(struct node ** l1){/*checking if there is space left*/
	
	int i =0;
	int num =0;
	
	while(num<numset1){
		
		while(i<associates){
			
			if(l1[num][i].frequency==0)
				return 1;
			
			
			
			}
	}
return 0;

}



int addl1(unsigned long long input,struct node ** l1){/*adds a node, if it is full, it will return 0 if added, 1*/
		int i = 0; 
		unsigned long long tmp = input;
		tmp = tmp >> offset;
		int index = tmp % numset1;
		tmp = tmp >> check(numset1);
			
	while(i<associates){/*adding*/

		if(l1[index][i].frequency==0){
				
				l1[index][i].tag = tmp;
				l1[index][i].frequency =memcount;
			
				return 1;
				}
						i++;
			}
				
		
		return 0;

	}
int addl2(unsigned long long input,struct node ** l2){/*adds a node, if it is full, it will return 0 if added, 1*/
		int i = 0; 
		unsigned long long tmp = input;
		tmp = tmp >> offset;
		int index = tmp % numset2;
		tmp = tmp >> check(numset2);
			
	while(i<as2){/*adding*/

		if(l2[index][i].frequency==0){
				l2[index][i].tag = tmp;
				l2[index][i].frequency =memcount;
			
				return 1;
				}
						i++;
			}
				
		
		return 0;

	}
int addl3(unsigned long long input,struct node ** l3){/*adds a node, if it is full, it will return 0 if added, 1*/
		int i = 0; 
		unsigned long long tmp = input;
		tmp = tmp >> offset;
		int index = tmp % numset3;
		tmp = tmp >> check(numset3);
			
	while(i<as3){/*adding*/

		if(l3[index][i].frequency==0){
				l3[index][i].tag = tmp;
				l3[index][i].frequency =memcount;
				
				return 1;
				}
						i++;
			}
				

		return 0;

	}	
int findl1(int setsize, unsigned long long int upd, 	int associate, struct node ** l1){/*true if it is found and false on if it was not found*/
		unsigned long long int  tmp = upd;
		tmp = tmp >> offset;
		int index = tmp % setsize;
		tmp = tmp >> check(setsize);
	int i =0;
	while (i<associate){
				
					if(l1[index][i].frequency!=0 && l1[index][i].tag==tmp){
							
						l1[index][i].frequency= memcount;
						
						return 1;
						}
					i++;						
									
				}
	return 0;
}

int findfull(unsigned long long upd, struct node ** fullas){/*true if it is found and false on if it was not found*/
		unsigned long long tmp = upd;
		tmp = tmp >> offset;
		//int index = tmp % setsize;
		tmp = tmp >> check(numset1);
int i =0;

while (i<fullasso){
				
			if(fullas[0][i].frequency!=0 && fullas[0][i].tag==tmp){
							
			fullas[0][i].frequency= memcount;
						
			return 1;
						}
					i++;
					}
	return 0;
}


void replacementl1(unsigned long long upd, struct node **l1){
	unsigned long long tmp = upd;
	tmp = tmp >> offset;
	int index = tmp % numset1; 
	tmp = tmp >> check(numset1);
	int i = 0;
	int d=1;
		if(replace==1){/*FIFO replacement*/
			l1[index][i].frequency =0; 
		
				while(d<associates){
					l1[index][i].tag = l1[index][d].tag;
					l1[index][i].frequency=l1[index][d].frequency;
					i=d; d++;				
					}
			l1[index][i].frequency=0;
			l1[index][i].tag=0;
			addl1(upd,l1);
			return;}

		else{/*for LRU*/
				i=0;
			int lowest = l1[index][i].frequency; 
					while(i<associates){/*finding the least recently used hex*/
						if(l1[index][i].frequency < lowest && l1[index][i].frequency!=0){
							lowest = l1[index][i].frequency;} 						
							i++;
						}
				i=0;
				/*so temp equals the head of the file*/
					if(l1[index][i].frequency==lowest){/*delete the head*/
							l1[index][i].tag = tmp;
							l1[index][i].frequency = memcount;					
							return;					
						}
				else{/*not deleting the head*/
					while(i<associates && l1[index][i].frequency!=lowest){
						i++;}
						l1[index][i].frequency = memcount;
						l1[index][i].tag = tmp;
						return;
					}
					}
			
			}

void replacementl2(unsigned long long upd, struct node **l2){
	unsigned long long tmp = upd;
	tmp = tmp >> offset;
	int index = tmp % numset2; 
	tmp = tmp >> check(numset2);
	int i = 0;
	int d=1;
		if(replace==1){/*FIFO replacement*/
			l2[index][i].frequency =0; 

				while(d<as2){
					l2[index][i].tag = l2[index][d].tag;
					l2[index][i].frequency=l2[index][d].frequency;
					i=d; d++;				
					}
			l2[index][i].frequency=0;
			l2[index][i].tag=0;
			addl2(upd,l2);
			return;}

		else{/*for LRU*/
				i=0;
			int lowest = l2[index][i].frequency;
					while(i<as2){/*finding the least recently used hex*/
						if(l2[index][i].frequency < lowest && l2[index][i].frequency!=0){
							lowest = l2[index][i].frequency;} 						
							i++;
						}
				i=0;
				/*so temp equals the head of the file*/
					if(l2[index][i].frequency==lowest){/*delete the head*/
							l2[index][i].tag = tmp;
							l2[index][i].frequency = memcount;					
							return;					
						}
				else{/*not deleting the head*/
					while(i<as2 && l2[index][i].frequency!=lowest){
						i++;}
						l2[index][i].frequency = memcount;
						l2[index][i].tag = tmp;
						return;
					}
					}
			
			}
void replacementl3(unsigned long long upd, struct node **l3){
	unsigned long long tmp = upd;
	tmp = tmp >> offset;
	int index = tmp % numset3; 
	tmp = tmp >> check(numset3);
	int i = 0;
	int d=1;
		if(replace==1){/*FIFO replacement*/
			l3[index][i].frequency =0; 

				while(d<as3){
					l3[index][i].tag = l3[index][d].tag;
					l3[index][i].frequency=l3[index][d].frequency;
					i=d; d++;				
					}
			l3[index][i].frequency=0;
			l3[index][i].tag=0;
			addl3(upd,l3);
			return;}

		else{/*for LRU*/
				i=0;
			int lowest = l3[index][i].frequency;
					while(i<as3){/*finding the least recently used hex*/
						if(l3[index][i].frequency < lowest && l3[index][i].frequency!=0){
							lowest = l3[index][i].frequency;} 						
							i++;
						}
				i=0;
				/*so temp equals the head of the file*/
					if(l3[index][i].frequency==lowest){/*delete the head*/
							l3[index][i].tag = tmp;
							l3[index][i].frequency = memcount;					
							return;					
						}
				else{/*not deleting the head*/
					while(i<as3 && l3[index][i].frequency!=lowest){
						i++;}
						l3[index][i].frequency = memcount;
						l3[index][i].tag = tmp;
						return;
					}
					}
			
			}			
	
void replacementfullas(unsigned long long upd,struct node** fullas){
	unsigned long long tmp = upd;
	tmp = tmp >> offset;
	
	tmp = tmp >> check(numset1);
	int i =0;int d=1;
	if(replace==1){/*FIFO replacement*/
		//	fullas[0][i].frequency =0; 

				while(d<fullasso){
					fullas[0][i].tag = fullas[0][d].tag;
					fullas[0][i].frequency= fullas[0][d].frequency;
					i = d; d++;			
					
					}
			fullas[0][i].frequency=0;
			fullas[0][i].tag=0;
			fulladd(upd,fullas);
			return;	}

	else{/*for LRU*/
			int lowest = fullas[0][i].frequency;
		
		while(i<fullasso){/*finding the least recently used hex*/
			if(fullas[0][i].frequency < lowest && fullas[0][i].frequency!=0){
				lowest = fullas[0][i].frequency;
					} 						
						i++;					
					}
					
				i=0;/*so this can go to the head of the file*/
				if(fullas[0][i].frequency==lowest){/*delete the head*/
							fullas[0][i].tag = tmp;
							fullas[0][i].frequency = memcount;					
					return;					
						}
				else{/*not deleting the head*/
					while(i<fullasso && fullas[0][i].frequency!=lowest){
						i++;}
						fullas[0][i].frequency = memcount;
						fullas[0][i].tag = tmp;
						return;
					}
				}


	}


int indexret(unsigned long long upd, int numsets){
		int index; 
		upd = upd >> offset;
		index = upd % numsets;
		return index;
		}
	
void fre(struct node **l1, struct node ** l2, struct node ** l3, struct node ** fullas){
/*show how to free stuff*/
	struct node * temp;
	int i =0;//int d;
	
	while(i<numset1){
			//d=associates-1;

			//while(d>=0){
					//temp = &l1[i][d];
						free(l1[i]);
						//d--;					
					//}
					i++;	
			}

		i =0;
		while(i<numset2){
			
				//d=as2-1;

				/*while(d>=0){
					temp = &l2[i][d];
					free(temp);
						d--;					
					}*/
					free(l2[i]);
					i++;	
			}

			/*for l2*/
 i =0;
 
 while(i<numset3){
			//d=as3-1;

				/*while(d>=0){
						temp = &l3[i][d];
						free(temp);
						d--;					
					}*/
					free(l3[i]);
					i++;	
			}

			/*for l3*/

i =0;	
			//d=fullasso-1;

				/*while(d>=0){
					temp = &fullas[0][d];
						free(temp);
						d--;					
					}*/
				free(fullas[0]);		
			

		/*for fully associative*/

	}

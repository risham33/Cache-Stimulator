	
struct node{

unsigned long int tag;
int frequency;
struct node* next;

};	

/*global declare*/
/*struct node ** l1;L1 cache*/
//struct node ** l2;
//struct node ** l3;
//struct node ** fullas; 
int memcount;
int offset;
int associates;/*how many you can have, so number of colomns*/
int fullasso;
int missesl1;
int missesl2;
int missesl3; /*this is for all the misses for the return type*/
int hitsl1;
int hitsl2;
int hitsl3;/*hits that were made*/
int capacity;
int conflict;
int numset1;
int numset2;
int numset3;
int size1;
int size2 ;/*l2 size*/
int as2;/*associative of l2*/
int size3;/*l3 size*/
int as3;/*associative of l3*/
int block; 
int coldmiss;
int coldmiss2;
int coldmiss3;

/*void make();
*/int check(int che);
int fulladd(unsigned long input, int associate,struct node ** fullas);
int addl1(unsigned long input, int associate, int numset, struct node ** l1);
/*int addl2(unsigned long input, int associate, int numset);
int addl3(unsigned long input, int associate, int numset);*/
int findl1(int setsize, unsigned long upd,struct node ** l1);
/*int findl2(int setsize, unsigned long upd);
int findl3(int setsize, unsigned long upd);
*/int findfull(int setsize, unsigned long upd, struct node ** fullas);
void replacementl1(unsigned long upd, int numset,int associate, char*type, struct node ** l1);
/*void replacementl2(unsigned long upd, int numset,int associate, char*type);
void replacementl3(unsigned long upd, int numset,int associate, char*type);
*/void replacementfullas(unsigned long upd, int numset,int associate, char*type, struct node ** fullas);
int indexret(unsigned long upd, int numsets);
void fre(struct node ** l1, struct node ** l2, struct node ** l3, struct node ** fullas);

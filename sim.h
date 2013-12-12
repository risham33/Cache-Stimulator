	
struct node{

unsigned long long tag;
int frequency;
//struct node* next;

};	


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
int replace;
int totalcapacity;
int check(int che);
int fulladd(unsigned long long input,struct node ** fullas);

int addl1(unsigned long long input,struct node ** l1);
int addl2(unsigned long long input,struct node ** l2);
int addl3(unsigned long long input,struct node ** l3);
int findl1(int setsize, unsigned long long upd,int associate,struct node ** l1);
int findfull(unsigned long long upd, struct node ** fullas);
void replacementl1(unsigned long long upd,struct node ** l1);
void replacementl2(unsigned long long upd,struct node ** l2);
void replacementl3(unsigned long long upd,struct node ** l3);
void replacementfullas(unsigned long long upd,struct node ** fullas);
int indexret(unsigned long long upd, int numsets);
void fre(struct node ** l1, struct node ** l2, struct node ** l3, struct node ** fullas);

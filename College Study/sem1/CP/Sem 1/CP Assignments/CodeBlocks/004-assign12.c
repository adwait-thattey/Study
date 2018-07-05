#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>



typedef struct Cost {

    float mrp;
    float discount;
    float charges;

}COST;

typedef struct Item {

    int proID;
    char name[21]; /*1 extra space for '\0'*/
    int type;
    char make[13]; /*1 extra space for '\0'*/
    float starrate;
    COST cst;

}ITEM;

char NAME[][20] = {"Jeans" , "Deodrant" , "Shampoo" , "Bottle" };
char MAKE[][20] = {"Nayasa" , "Engage" , "ThatCorp"};

char *genRandName(int);
int generateUniqueProId(ITEM *TEMP , int n );
void printRequiredItem(ITEM *item);



ITEM *genDataset(int n) {
    srand((unsigned int)time(NULL));

    ITEM *I;

    I = (ITEM *)malloc(n*sizeof(ITEM));

    for(int i=0;i<n;++i) {

        I[i].proID = generateUniqueProId(I , i);

        strcpy(I[i].name , NAME[(int)rand()%4]);

        I[i].type = rand()%4 ;

        strcpy(I[i].make , MAKE[(int)rand()%3]);
        I[i].starrate = (float)(rand()%6) + (float)(rand()/RAND_MAX);

        I[i].cst.mrp = (float)(rand()%8000 - 200 + 1) + 200 + (float)rand()/RAND_MAX;
        I[i].cst.discount = (float)(rand()%25 + 1) + (float)(rand()/RAND_MAX);
        I[i].cst.charges = (float)(rand()%170 + 30) + (float)(rand()/RAND_MAX);

    }


return I;


}

void printItems(ITEM *item, int n) {
static int i = 1; //Variable declared only for printing the number
if(n<=0) return;

printf("\n\nDetails of Item %d\n",i++);

printRequiredItem(item);

printItems(++item, n-1);



}

void SearchItemByMake(ITEM *item, int n, char *make) {
static int flag =0;
if(n<=0) {
        if(flag==0) printf("\n\nSorry!! No Items found with the required make\n\n");

        return;
}

static int i = 1; //Variable declared only for printing the number

if(strcmpi(item->make,make)==0) {
flag=1;
printf("\nItem no %d has the required Brand \nDetails of Item %d\n",i,i);
printRequiredItem(item);
}

++i;
SearchItemByMake(++item,n-1,make);

}

void printRequiredItem(ITEM *item) {

printf("\nProId = %d\nName = %s\nType = %d\nMake = %s\n Starrate = %f\nMrp = %.2f\nDiscount = %.3f\nCharges = %.3f",item->proID,item->name,item->type,item->make,item->starrate,item->cst.mrp,item->cst.discount,item->cst.charges);
printf("\n------------------------------------------------------------------------------------------------");
return;
}




int generateUniqueProId(ITEM *TEMP , int n ) {

    int x;
    int flag = 0;
    while(flag==0) {
        x = rand()%(1000000 + 1 - 1000) + 1000;
        flag = 1;
        for(int i=0;i<n;++i) {

            if((TEMP[i].proID)==x) {flag=0;break;}

        }

        }
    if(flag==1) return x;
    return 0;
}


int main() {


ITEM *I;

I = genDataset(3);

printItems(I,3);

printf("\n\n");

SearchItemByMake(I,3,"Engage");



/*ITEM *I;

I = (ITEM *)malloc(30*sizeof(ITEM));

for(int i=0;i<30;++i) {

    I[i].proID = generateUniqueProId(I , i);
    printf("%d\n",I[i].proID);

}

*/
/*srand((unsigned int)time(NULL));
//97 122
char *str=(char *)malloc(21*sizeof(char));
str = genRandName(21);
char str2[21];

strcpy(str2,str);


printf("%s",str2);
-*/
return 0;

}

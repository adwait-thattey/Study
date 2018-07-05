#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*

***
Since Rextester takes input beforehand, give the input in the following way.
The first line of the input should be the number which tells the type of input number. Insert the following numbers
1 - Integer
2 - Float
3 - Char
4 - Long Int
5 - Double
6 - Long Double.

The second line should contain the input number.
For Ex: if you want to see representation of 14.5  in float then the input should be 
2
14.5
***
*/


void int_to_binary(unsigned int a){
    // Converts given unsigned int into binary representation
    char len[32];
    int i;
    for(i=0;i<32;i++){
        if(a%2==0)
            len[31-i]=48; // Appointing the ASCII value
        else
            len[31-i]=49;
        a=a/2;


    }
    printf("Your Number Is\n");
    for(i=0;i<32;i+=8){
        // Printing the character stored for ASCII values of 48 and 49
        printf("%c%c%c%c%c%c%c%c ",len[i],len[i+1],len[i+2],len[i+3],len[i+4],len[i+5],len[i+6],len[i+7]);
    }

}

void long_to_binary(unsigned long a){
    char len[64];
    int i;
    for(i=0;i<64;i++){
        if(a%2==0)
            len[63-i]=48;
        else
            len[63-i]=49;
        a=a/2;
    }
    printf("Your Number Is : ");
    for(i=0;i<64;i+=8){
        printf("%c%c%c%c%c%c%c%c ",len[i],len[i+1],len[i+2],len[i+3],len[i+4],len[i+5],len[i+6],len[i+7]);
    }
}


void char_to_binary(int a){
    char len[8];
    int i;
    for(i=0;i<8;i++){
        if(a%2==0)
            len[7-i]=48;
        else
            len[7-i]=49;
        a=a/2;


    }
    printf("Your Character is\n");
    for(i=0;i<7;i+=8){
        printf("%c%c%c%c%c%c%c%c ",len[i],len[i+1],len[i+2],len[i+3],len[i+4],len[i+5],len[i+6],len[i+7]);
    }
}


void convToBinFra(double data,int binary[],int max_no){
   double remainder = data;
    int count=0;
    do {
        remainder = 2 * remainder;
        if (remainder < 1){
            binary[count] = 0;
        }
        else {
            remainder -= 1.0;
            binary[count] = 1;
        }
        count++;
    } while (remainder != 0 && count < max_no);
    int remain = max_no - count;
    int noName = max_no;
    while (remain > 0){
        binary[noName-1] = 0;
        remain--;
        noName--;
    }
}

void convToBin(int data,int binaryI[],int min){
    /*int remainder = 0;
    int base = 1,binary = 0;
    int count=0;
    while (data > 0 && count < 9)
    {
        remainder = data % 2;
        binary = binary + remainder * base;
        data = data / 2;
        base = base * 10;
        count++;
    }
    return binary;*/
    int i;
    for (i = min-1; i > -1; i--){
        if (data % 2 == 1){
            binaryI[i] = 49;
        }
        else {
            binaryI[i] = 48;
        }
        data /= 2;
    }

    i = 0;
    for (i = 0; i < min; i++){
        printf("%c",binaryI[i]);
    }
    printf(" ");
}

void float_to_bin(int binary[],int binaryI[],int expo,int max_no,int min_no){
       
       double num,temp;
        int signed_bit;//exponent_bits;
        printf("Enter the floating Point Number : ");
        scanf("%lf",&num);
        if(num==0.0) {
            printf("0 ");

            convToBin(0, binaryI, min_no);
            convToBinFra(0.0, binary, max_no);
            for (int i = 0; i < max_no; i++)
            {
                printf("%d", binary[i]);
            }
            return;
         }
       
        if (num < 0){
            signed_bit = 1;
            num = -1*num;
        }
        else {
            signed_bit = 0;
        }

        temp = num;

        int count = 0;
        if (temp < 1){
            while (temp < 1){
                temp *= 2.0;
                count--;
            }
        }
        else {
            while (temp > 1){
                temp /= 2.0;
                count++;
            }
            count++;
            temp *= 2.0;
        }


        int biasedExpo;
        biasedExpo = expo + count;

        int gronk;
        
        gronk = (int)temp;
        double fraction = (double)temp - (double)gronk;

        //printf("\n%lf\n", fraction);
        int i;
        convToBinFra(fraction,binary,max_no);

        printf("Your Number Is : ");

        printf("%d ",signed_bit);

        convToBin(biasedExpo,binaryI,min_no);

        for (i = 0; i < max_no; i++){
            printf("%d",binary[i]);
        }

}

int main()
{

    printf("Enter the choice that you want : \n");
    printf("1) Integer  \n2) Float \n3) Character \n4) Long \n5) Double\n6) Long Double \n");

    // Take Any of the 4 choices

    int selection;
    scanf("%d",&selection);
    printf("\n");
    if (selection == 1){
        // To Represent binary form of integers we simply have to write them in
        // 4byte that is 32 bit representation form
        printf("Enter A Number\n");
        int a;
        scanf("%d",&a);
        unsigned int c=a;

        int_to_binary(c);
    }


    if (selection == 2){
        int binary[100];
        int binaryI[10];
        float_to_bin(binary,binaryI,125,23,8);
    }

    if (selection == 3){
        // Writing 8 bit representation of character
        char a2;
        int c2;
        printf("Enter a character\n");
        scanf(" %c",&a2);
        c2 = (int)a2;
        char_to_binary(c2);
    }

    if (selection == 4){
        long a1;
        unsigned long c1;
        printf("enter a long number\n");
        scanf("%ld",&a1);
        c1=a1;

        long_to_binary(c1);
    }
    if (selection == 5){
        int binary[100];
        int binaryI[15];
        float_to_bin(binary,binaryI,1021,52,11);

    }

    if (selection == 6){
        int binary[100];
        int binaryI[16];
        float_to_bin(binary,binaryI,16381,64,15);
    }
    return 0;
}

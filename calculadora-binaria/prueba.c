#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void DecToBin(int num,char * res){

    //char res2[20];
    int i=0;
    int x = num;

    while(x>0){
        x=x/2;
        i++;
    }
    printf("%d\n",i);
    res[i]='\0';
    while(i>0){

        res[i-1]= (num%2) + '0';
        printf("%c",res[i]);
        num=num/2;
        i--;

    }
    //printf("%s\n",res2);
    //strcpy(res,res2);
}
int binToDecima( char * num){
    char * t;
    return strtol(num,&t,2);
}



int main(){


    char xy[32]="";
    DecToBin(1234,xy);
    printf("res: %s",xy);


}

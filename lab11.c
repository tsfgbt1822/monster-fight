/*****************************************************************************
 * CS1050
 * Fall 2021
 * Lab: Lab 11
 * Name: Tori Fischer
 * pawprint: tsfgbt
 * November 12, 2021
 *****************************************************************************/
#include <stdio.h>
#include <string.h>
#include "fight.h"

int main(int argc, char * argv[])
{
    FILE * fp;
    char test1[]="Ahote";
    char test2[]="FrostGiant";
    fp = fopen("monster.csv", "r");

    char * holdName[256];
    char *  holdA1D[256];
    char * holdA2D[256];
    int holdAC=0, holdHP=0, holdHB=0;
    int count=0;

    if(fp!=NULL)
    {
        char ignore[256];
        fgets(ignore,255, fp);

        while(fp && !feof(fp))
        {
            char name[256];
            char attack1d[256];
            char attack2d[256];
            int ac=0, hp=0, hitbonus=0;
            
            if(6==fscanf(fp,"%d,%d,%d,%s,%s,%s",&ac,&hp,&hitbonus, attack1d, attack2d, name))
            {
                if(strcmp(name,test1)==0 || strcmp(name,test2)==0)
                {
                    if(count==0)
                    {
                        holdName=name;
                        holdA1D=attack1d;
                        holdA2D=attack2d;
                        holdAC=ac;
                        holdHP=hp;
                        holdHB=hitbonus;
                    }
                    else
                        Fight(holdName,holdAC, holdHP, holdHB, holdA1D, holdA2D, name, ac, hp, hitbonus, attack1d, attack2d);


                }
            }
        }
        fclose(fp);
    }
    else 
    {
        printf("Error: Could not open file");
    }


    // Uncomment the following line if you want to try a sample fight
    // Fight("JimR",21,900,10,"5d6+5","5d12+5","Lar",5,100,5,"1d6","N/A");
}

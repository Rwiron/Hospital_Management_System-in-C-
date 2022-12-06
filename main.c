#include<stdio.h>
#include<string.h>
struct patient
{
int id;
char name[50];
 char address[50];
    char type_of_addiction[50];
    int tel_of_caregiver;

}p[50];
void record();
void display();
void search();
void sort();
void main()
{
    printf("\t\t\t\t\t\tHOSPITAL MANAGEMENT SYSTEM:\n\n");
     printf("\t\t\t\t\t========================================\n\n\n\n");
    printf("\tWELCOME TO REHABILITATION: \n");
     printf("\t=================================\n");

    int c,a;
    do
    {
        printf("\n\n\t\t\tPRESS:");
        printf("\n\n\t\t\tMAIN MENU");
        printf("\n\n\t\t\t1.record");
        printf("\n\n\t\t\t2.display");
        printf("\n\n\t\t\t3.Search");
        printf("\n\n\t\t\t4.Sort");
        printf("\n\n\t\t\t0.exit\n");
        printf("make a choice====>");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            record();
            break;
        case 2:
            display();
            break;
        case 3:
           // printf("enter your id:");
            //scanf("%d",&a);
            search();
            break;
        case 4:
            printf("data sorted successfully.......");
            break;
        case 0:
            printf("see you!\n");
            break;
        default:
            printf("incorrect:\n");
        }
    }while(c!=0);
}
void record()
{
    int i;
    FILE *m;
    printf("enter id\t name\t address\t types of addiction\t tel of caregiver\n\n");
    scanf("%d%s%s%s%d",&p[i].id,p[i].name,p[i].address,p[i].type_of_addiction,&p[i].tel_of_caregiver);
    m=fopen("good.txt","a");
    fprintf(m,"\n%d\t%s\t%s\t%s\t%d",p[i].id,p[i].name,p[i].address,p[i].type_of_addiction,p[i].tel_of_caregiver);
    fclose(m);

    return;
}
void display()
{
    int i;
    printf("List of Patient:======");
    FILE *dis;
    dis=fopen("good.txt","r");
    while(!feof(dis))
    {
     fscanf(dis,"\n%d\t%s\t%s\t%s\t%d\n",&p[i].id,p[i].name,p[i].address,p[i].type_of_addiction,&p[i].tel_of_caregiver);
    // i++;
    printf("\n%d\t%s\t%s\t%s\t%d\n",p[i].id,p[i].name,p[i].address,p[i].type_of_addiction,p[i].tel_of_caregiver);

    }
    fclose(dis);
    return;
    //scanf("%d%s",&p[i].id,p[i].name);
    //printf("%d%s",p[i].id,p[i].name);
}
void search()
{
    int i;

    printf("Search Patient:");

    FILE *srch;
struct patient p;
    printf("enter id ...");
    scanf("%d",&i);
    srch=fopen("good.txt","r");
    while(!feof(srch))
    {
        fscanf(srch,"%d%s%s%s%d",&p.id,&p.name,&p.address,&p.type_of_addiction,&p.tel_of_caregiver);
          if(p.id==i)

    {
        printf("patient corresponding to your id %d\tis\t%s\taddress is %s\t type of addiction is %s\t and the level of addiction is%d",p.id,p.name,p.address,p.type_of_addiction,p.tel_of_caregiver);
        fclose(srch);
        return;
    }}

    printf("no patient found try again");
}
void sort()
{
struct patient temp;
int i, j=0,u;
FILE *sr;
sr=fopen("good.txt","r");
while(!feof(sr))
{
    fscanf(sr," %d\t%s\n",&p[j].id,p[j].name);
    j++;
}
for(i=0;i<j-1;i++)
 {
     for(u=0;u<j-1-i;u++)
     {
         if(p[u].id<p[u+1].id)
         {
             temp = p[u];
             p[u] = p[u+1];
             p[u+1] = temp;

         }
     }
 }
 printf("\nTHE SORTED LIST OF patient==============================================================================================================\n\n");
 for(u=0;u<j;u++)
 {
     printf("\n%s\id are by[%d] | %s\tname are [%s]\n",p[u].id,p[u].name);
 }
 fclose(sr);

    return;
}


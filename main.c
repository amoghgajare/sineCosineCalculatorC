#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define PI 3.1415
float power(float x,int n);
int fac(int n);

int main()
{
   int i,sign=1,m;
   FILE *hist;
   hist=fopen("history.txt","a");
   char ans='y',ch;
   float angrad,angdeg;
   float sine=0.0,cosine=0.0;
   while(1)
   {
   start:
   printf("1 : Do a calculation\n2 : View History of Calculations\n3 : Exit\n");
   scanf("%d",&m);
   if(m==1)
   {
   while(ans=='y')
   {
   printf("Enter angle in degrees : ");
   scanf("%f",&angdeg);
   angrad=(PI*angdeg)/180;

   for (i=1;i<30;i=i+2)
   {
   sine=sine+((sign*power(angrad,i))/fac(i));
   sign=-sign;
   }
   sign=1;
   for(i=0;i<30;i=i+2)
   {
   cosine=cosine+((sign*power(angrad,i))/fac(i));
   sign=-sign;
   }
   printf("\nsin %f%c = %f\ncos %f%c = %f\n",angdeg,248,sine,angdeg,248,cosine);
   hist=fopen("history.txt","a");
   fprintf(hist,"Angle = %f\nsin %f = %f\ncos %f = %f\n",angdeg,angdeg,sine,angdeg,cosine);
   fclose(hist);
   printf("\n\nDo you want to do another calculation? y/n\n\n");
   ans=getch();
   system("cls");
   }
   }
   else if(m==2)
   {
    hist=fopen("history.txt","r");
    while((ch=fgetc(hist))!=EOF)
    {
    printf("%c",ch);
    }
    fclose(hist);
   }
   else if(m==3)
   {
       return 0;
   }
   else
   {
       system("cls");
       printf("Invalid Input....Try again\n\n");
       goto start;
   }
   }
    return 0;
}
int fac(int n)
{
if (n<2)
    {return 1;}
else
    {return(n*fac(n-1));}
}
float power(float x,int n)
{
if (n==0){return 1;}
else if(n==1){return x;}
else{return (x*power(x,n-1));}
}

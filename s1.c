#include <stdio.h>
void Insert();
void Display();
void Search();
void Delete();
void Update();
void Topper();
FILE *fp;
FILE *f;
FILE *fp1;
struct student
{
   int roll;
   char name[100],l_name[100];
   float marks[3];
   float total;
   float pr;
}s1;
int main()
{
   int choice;
   char ch;
   labal:
   printf("\n...MENU....  ");
   printf("\n 1.Insert ");
   printf("\n 2.Display ");
   printf("\n 3.Search");
   printf("\n 4.Delete");
   printf("\n 5.Update");
   printf("\n 6.Topper");
   printf("\n Enter your choice ");
   scanf("%d",&choice);
   switch(choice)
   {
      case 1:
      Insert();
      break;
      case 2:
      Display();
      break;
      case 3:
      Search();
      break;
      case 4:
      Delete();
      break;
      case 5:
      Update();
      break;
      case 6:
      Topper();
      break;
   }
   getchar();
   printf("\n Do You Want To Continue(Y/N)");
   scanf("%c",&ch);
   if(ch == 'Y' || ch=='y' )
   {
      goto labal;
   }
   else
   {
      printf("\n Jay Shree Krishna");
   }
return 0;
} 
void Insert()
{
     int size;
     float total,Pr;

            printf("Enetr sudent no of student");
            scanf("%d",&size);
            fp=fopen("student_details.txt","a");
            if(fp == NULL)
            {
               printf("file opening error .....");
            }
            else
            {
               printf("file open successfully");
            }
      for(int i=0 ;i<size ;i++)
      {
            printf("\n Enter your student roll no");
            scanf("%d",&s1.roll);
            printf("\n Enter student first name ");
            scanf("%s",s1.name);
            printf("\n Enter student last name ");
            scanf("%s",s1.l_name);
            printf("\n Enter three subjects marks in format include enter\n");
            scanf("%f",&s1.marks[0]);
            scanf("%f",&s1.marks[1]);
            scanf("%f",&s1.marks[2]);
            s1.total=s1.marks[0]+s1.marks[1]+s1.marks[2];
            s1.pr=s1.total/3;
            fprintf(fp,"\nroll = %d \nfirst name -> %s \nlast name -> %s \nmarks(3 subject)= %f %f %f \nTotal = %f \nParsantage = %f",s1.roll,s1.name,s1.l_name,s1.marks[0],s1.marks[1],s1.marks[2],s1.total,s1.pr);
            
      }
      fclose(fp);
}
// DISPLAY STUDENT DITAILS
void Display()
{
   fp=fopen("student_details.txt","r");
   while((fscanf(fp,"\nroll = %d \nfirst name -> %s \nlast name -> %s \nmarks(3 subject)= %f %f %f \nTotal = %f \nParsantage = %f",&s1.roll,s1.name,s1.l_name,&s1.marks[0],&s1.marks[1],&s1.marks[2],&s1.total,&s1.pr)) != EOF)
   {
      printf("\nRoll  No = %d ",s1.roll);
      printf("\nFirst Name = %s ",s1.name);
      printf("\nLast  Name = %s ",s1.l_name);
      printf("\nMarks = %.2f %.2f %.2f",s1.marks[0],s1.marks[1],s1.marks[2]);
      printf("\nTotal = %.2f",s1.total);
      printf("\nParsantage = %.2f",s1.pr);
   }

   fclose(fp);
}
//  STUDENT SEARCH BY THERE ROLL NUMBER
void Search()
{
   int flag=0;
   int search;     
   printf("\n Enter Your Searcing Student Roll Number");
   scanf("%d",&search);
   fp=fopen("student_details.txt","r");
   if(fp == NULL)
   {
      printf("\n File openi error ....");
   }
   else
    {
      printf("\n File open successfully");
    }
   //fscanf(fp,"\nroll = %d \nfirst name -> %s \nlast name -> %s \nmarks(3 subject)= %f %f %f",&s1.roll,s1.name,s1.l_name,&s1.marks[0],&s1.marks[1],&s1.marks[2]);
     while(fscanf(fp,"\nroll = %d \nfirst name -> %s \nlast name -> %s \nmarks(3 subject)= %f %f %f \nTotal = %f \nParsantage = %f",&s1.roll,s1.name,s1.l_name,&s1.marks[0],&s1.marks[1],&s1.marks[2],&s1.total,&s1.pr) != EOF)
      {
         if(search == s1.roll)
         {
            flag=1;
            printf("\nRoll = %d",s1.roll);
            printf("\nName = %s",s1.name);
            printf("\nLast name = %s",s1.l_name);
            printf("\nMarks(3subject) = %f %f %f",s1.marks[0],s1.marks[1],s1.marks[2]);
            printf("\n Total = %f",s1.total);
            printf("\n Parsantage = %f",s1.pr);
         }
        
         
      }
        if(flag == 0 )
         {
            printf("No data found");
         }
         fclose(fp);
}
// DELETE STUDENT BY ROLL NUMBER
void Delete()
{
   int ro,f=0;
   char ch;
   fp=fopen("student_details.txt","r");
   fp1=fopen("delete.txt","w");
   if(fp == NULL || fp1 == NULL)
   {
      printf("\n File opening error");
   }
   else
   {
      printf("\n file open");
   }
   printf("Enetr sudent Roll no");
   scanf("%d",&ro);
   while((fscanf(fp,"\nroll = %d \nfirst name -> %s \nlast name -> %s \nmarks(3 subject)= %f %f %f \nTotal = %f \nParsantage = %f",&s1.roll,s1.name,s1.l_name,&s1.marks[0],&s1.marks[1],&s1.marks[2],&s1.total,&s1.pr)) != EOF)
   {
      if(s1.roll != ro)
      {
         fprintf(fp1,"\nroll = %d \nfirst name -> %s \nlast name -> %s \nmarks(3 subject)= %f %f %f \nTotal = %f \nParsantage = %f",s1.roll,s1.name,s1.l_name,s1.marks[0],s1.marks[1],s1.marks[2],s1.total,s1.pr);
      }
      else 
      {
         f=1;
      }
   }
   fclose(fp1);
   fclose(fp);
   remove("student_details.txt");
rename("delete.txt","student_details.txt");
   if(f == 0)
   {
      printf("\n file record is not found");
   }
   else
   {
      printf("\n record delete successfully");
   }
}
void Update()
{
   int te,temp;
   fp=fopen("student_details.txt","r");
   f=fopen("update.txt","w");
   printf("\n Enter your roll number");
   scanf("%d",&temp);
   if(fp == NULL || f == NULL)
   {
      printf("\n file containg error");
   }
   else
   {
      printf("file open successfully");
   }
   
   printf("\n 1. change first subject marks");
   printf("\n 2. change first and second subject");
   printf("\n 3. change all marks");
   printf("\n Enter your choice");
   scanf("%d",&te);
   while((fscanf(fp,"\nroll = %d \nfirst name -> %s \nlast name -> %s \nmarks(3 subject)= %f %f %f \nTotal = %f \nParsantage = %f",&s1.roll,s1.name,s1.l_name,&s1.marks[0],&s1.marks[1],&s1.marks[2],&s1.total,&s1.pr)) != EOF)
   {
      if(temp == s1.roll)
      {
         if(te == 1)
         {
         printf("\n Enter first subject new marks");
         scanf("%f",&s1.marks[0]);
         }
          if(te == 2)
          {
         printf("\n Enter first subjects new marks");
         scanf("%f",&s1.marks[0]);
         printf("\n Enter second subjects new marks");
         scanf("%f",&s1.marks[1]);
        
          }
          if(te == 3)
          {
         printf("\n Enter first subjects new marks");
         scanf("%f",&s1.marks[0]);
         printf("\n Enter second subjects new marks");
         scanf("%f",&s1.marks[1]);
         printf("\n Enter therd subjects new marks");
         scanf("%f",&s1.marks[2]);
          }
         s1.total=s1.marks[0]+s1.marks[1]+s1.marks[2];
         s1.pr=s1.total/3;
      }
      if(s1.pin == s1.pin)
     {
      printf("re enter pin");
     }
      fprintf(f,"\nroll = %d \nfirst name -> %s \nlast name -> %s \nmarks(3 subject)= %f %f %f \nTotal = %f \nParsantage = %f",s1.roll,s1.name,s1.l_name,s1.marks[0],s1.marks[1],s1.marks[2],s1.total,s1.pr);
      
   }
    fclose(fp);
   fclose(f);
    remove("student_details.txt");
   rename("update.txt","insert_details.txt");
  
  

}
void Topper()
{
   int max=0;
   fp=fopen("student_details.txt","r");
   
   while((fscanf(fp,"\nroll = %d \nfirst name -> %s \nlast name -> %s \nmarks(3 subject)= %f %f %f \nTotal = %f \nParsantage = %f",&s1.roll,s1.name,s1.l_name,&s1.marks[0],&s1.marks[1],&s1.marks[2],&s1.total,&s1.pr)) != EOF)
   {
     // s1.total=0;
      if(s1.total>max)  // 1 100 > 0 = 0=100  
                        // 100= max 2 170 >100
                        // 170 = max 3 560 >170
                        // 560 = max 4 450>560 //last hoy
                        // 560 fix on the max
                        // the selcond loop in condition check if you get the max in the s1.total 
                        // print only thoose student details where there marks inn for in mx\ax
      {
         max=s1.total;
      }
     
   }
  rewind(fp);
while((fscanf(fp,"\nroll = %d \nfirst name -> %s \nlast name -> %s \nmarks(3 subject)= %f %f %f \nTotal = %f \nParsantage = %f",&s1.roll,s1.name,s1.l_name,&s1.marks[0],&s1.marks[1],&s1.marks[2],&s1.total,&s1.pr)) != EOF)
   {
    if(max==s1.total)
      {
         printf("\n Roll no is %d",s1.roll);
         printf("\n Name is %s",s1.name);
         printf("\n Last name %s",s1.l_name);
         printf("\n marks %.2f %.2f %.2f",s1.marks[0],s1.marks[1],s1.marks[2]);
         printf("\n Total = %.2f",s1.total);
         printf("\n Parsantage = %.2f",s1.pr);
         
      }
   }
  // printf("%f",s1.total);
}
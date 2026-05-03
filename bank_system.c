#include<stdio.h>
#include<stdlib.h>
FILE *fp;
FILE *fptr;
FILE *tf;
void add_account();
void display();
void withrawal();
void deposite();
void search();
void money_transfar();
struct bank
{
    char name[100];
    char bname[100];
    int n;
    int pin;
    float Balance;
}s1;
int main()
{
    int choice,f=0;
    char ch;
    labal:
    printf("\n MENUE");
    printf("\n 1.Add Account");
    printf("\n 2.Display account details");
    printf("\n 3.Withrwal ");
    printf("\n 4.Deposite ");
    printf("\n 5.search");
    printf("\n 6.tranfar money");
    printf("\n Enter your choice");
    scanf("%d",&choice);

    switch(choice)  // for choice select in this any on perform the some opration
    {
        case 1:
        add_account();  
        break;
        case 2:
        display();
        break;
        case 3:
        withrawal();
        break;
        case 4:
        deposite();
        break;
        case 5:
        search();
        break;
        case 6:
        money_transfar();
        break;
        default:
        printf("exit...");
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
}
 // add account 
void add_account()
{
  int *ptr,ch,c=0,f=0;
  fp=fopen("add_account.txt","a");
  if(fp == NULL)
  {
    printf("\n file not open");
  }
  else
  {
    printf("\n file is open");
  }
  
  printf("\n Enter your no of account");
  scanf("%d",&ch);
  ptr=(int*)malloc(ch*sizeof(int));
 for(int i=0 ; i<ch; i++)
{
    printf("\n Enter account holder name: ");
    scanf("%s", s1.name);

    printf("\n Enter account number: ");
    scanf("%d", &s1.n);
    
    
    printf("\n Enter Bank name: ");
    scanf("%s", s1.bname);
    
    printf("\n Enter Balance (minimum 2000): ");
    scanf("%f",&s1.Balance);

    printf("\n Enter your secret pin");
    scanf("%d",&s1.pin);

    if(s1.Balance>=2000 && s1.pin >= 4 && s1.n>=9 )
    {
    fprintf(fp,"\nName %s\nNumber %d\nBankName %s\nBalance %f\nPIN %d",s1.name,s1.n,s1.bname,s1.Balance,s1.pin);
    }
    }
    fclose(fp);
}
// display all the account store in the file
void display()
{
    fp=fopen("add_account.txt","r");
    if(fp == NULL)
  {
    printf("\n file not open successfully \n");
  }
  else
  {
    printf("\n file is open successfully \n");
  }
  printf("\n *********  Details of account holder  ******* \n");
   while(fscanf(fp,"\nName %s\nNumber %d\nBankName %s\nBalance %f\nPIN %d",s1.name,&s1.n,s1.bname,&s1.Balance,&s1.pin) != EOF)
   {
      printf("\n 1.Name of Account Holder -> %s",s1.name);
      printf("\n 2. Account Number        -> %d",s1.n);
      printf("\n 3. Bank name             -> %s",s1.bname);
      printf("\n 4. Bank Balance          -> %.2f",s1.Balance);
      printf("\n 5. PIN                   -> %d",s1.pin);
   }
}
// withrawal the monkey from the balance
void withrawal()  
{
  int pin;
  char ch;
  float w;
   fp=fopen("add_account.txt","r");
   fptr=fopen("withrawal.txt","a");
    printf("\n Enter your secret pin");
    scanf("%d",&pin);
   
       printf("\n *********  Details of account holder  ******* \n");
   while(fscanf(fp,"\nName %s\nNumber %d\nBankName %s\nBalance %f\nPIN %d",s1.name,&s1.n,s1.bname,&s1.Balance,&s1.pin) != EOF)
   {
     if(pin == s1.pin)
    {
      printf("\n 1. Name of Account Holder -> %s",s1.name);
      printf("\n 2. Account Number        ->  %d",s1.n);
      printf("\n 3. Bank name             ->  %s",s1.bname);
      printf("\n 4. Bank Balance          ->  %.2f",s1.Balance);
      printf("\n 5. PIN                   ->  %d",s1.pin);
   } 
    
    }
     printf("\n Please confirm details (y/n)");
     scanf(" %c",&ch);
    if(ch == 'y')
    {
    printf("\n How much you withrowal");
    scanf("%f",&w);
    rewind(fp);
      
         while(fscanf(fp,"\n Name %s\nNumber %d\nBankName %s\nBalance %f\nPIN %d",s1.name,&s1.n,s1.bname,&s1.Balance,&s1.pin) != EOF)
   {
      s1.Balance=s1.Balance-w;
      fprintf(fptr,"\n Name %s\nNumber %d\nBankName %s\nBalance %f\nPIN %d",s1.name,s1.n,s1.bname,s1.Balance,s1.pin);
   }
   //printf("cuurent balance = %f ",s1.Balance);
    
    }
   fclose(fp);
     fclose(fptr);
   remove("add_account.txt");
   rename("add_account.txt","withrawal.txt");
   
}
// add the money from balance
void deposite()
{
  float de;
  int pin;
  fp=fopen("add_account.txt","r");
   fptr=fopen("deposite.txt","a");
  printf("\n Plese Enter Your Secrat Pin");
  scanf("%d",&pin);
   while(fscanf(fp,"\nName %s\nNumber %d\nBankName %s\nBalance %f\nPIN %d",s1.name,&s1.n,s1.bname,&s1.Balance,&s1.pin) != EOF)
   {
  if(pin == s1.pin)
  {
    printf(" Enter your amount to you deposite");
    scanf("%f",&de);
    s1.Balance=s1.Balance+de;
  fprintf(fptr,"\n Name %s\nNumber %d\nBankName %s\nBalance %f\nPIN %d",s1.name,s1.n,s1.bname,s1.Balance,s1.pin);
  }
}
   fclose(fp);
     fclose(fptr);
   remove("add_account.txt");
   rename("add_account.txt","deposite.txt");
}
// search the account details by account number
void search()
{
  int search;
  printf("\n Enter your search account number");
  scanf("%d",&search);
  fp=fopen("add_account.txt","r");
  if(fp == NULL)
  {
    printf("\n file not open sucessfully");
  }
  else
  {
    printf("\n file open sucessfully");
  }
    while(fscanf(fp,"\n Name %s\nNumber %d\nBankName %s\nBalance %f\nPIN %d",s1.name,&s1.n,s1.bname,&s1.Balance,&s1.pin) != EOF );
    {
      if(search == s1.n)
      {
        printf("\n 1.Account number = %d ",s1.n);
        printf("\n 2.Account holder name = %s ",s1.name);
        printf("\n 3.Bank name = %s ",s1.bname);
        printf("\n 4.Bank balance = %.2f ",s1.Balance);
        printf("\n 5.PIN = %d",s1.pin);
        
      }
      else
  {
    
    printf("data not found");
  }
  }

  }
void money_transfar()
{
//   tf=fopen("tranfar.txt","w");
//   int pin,tranfar;
//   char ch1,T;
//   float amount;
//   printf("\n Enter your secrat pin");
//   scanf("%d",&pin);
//   fp=fopen("add_account.txt","r");
//   while(fscanf(fp,"\n Name %s\nNumber %d\nBankName %s\nBalance %f\nPIN %d",s1.name,&s1.n,s1.bname,&s1.Balance,&s1.pin) != EOF)
//   {
//     if(pin == s1.pin)
//     {
//         printf("\n 1.Account number = %d ",s1.n);
//         printf("\n 2.Account holder name = %s ",s1.name);
//         printf("\n 3.Bank name = %s ",s1.bname);
//         printf("\n 4.Bank balance = %.2f ",s1.Balance);
//         printf("\n 5.PIN = %d",s1.pin);
      
//     }
    
//   }
//   printf("\n PLEACE CONFORM YOUR DETAILS");
//   scanf(" %c",&ch1);
// //   if(ch1 == 'y'|| ch1 == 'Y')
// //   {
// //     printf("\n Enter account to tranfar");
// //     scanf("%d",&tranfar);
// //     rewind(fp);
// //      while(fscanf(fp,"\n Name %s\nNumber %d\nBankName %s\nBalance %f\nPIN %d",s1.name,&s1.n,s1.bname,&s1.Balance,&s1.pin) != EOF)
// //   {
// //     if(s1.n == tranfar)
// //     {
// //         printf("\n 1.Account number = %d ",s1.n);
// //         printf("\n 2.Account holder name = %s ",s1.name);
// //         printf("\n 3.Bank name = %s ",s1.bname);
// //         printf("\n 4.Bank balance = %.2f ",s1.Balance);
// //         printf("\n 5.PIN = %d",s1.pin);
// //     }
    
// //   }
// // }
//   // rewind(fp);
//   // printf("\n PLEACE CONFORM TRANSFER ACCOUNT DETAILS ");
//   //   scanf(" %c",&T);
//    if(ch1 == 'y' || ch1 == 'Y')
//    {
//     printf("\n Enter your tranfar amount");
//     scanf("%f",&amount);

//     s1.Balance=s1.Balance-amount; 

//    // s1.Balance=amount+s1.Balance;

//     fprintf(tf,"\nName %s\nNumber %d\nBankName %s\nBalance %f\nPIN %d",s1.name,s1.n,s1.bname,s1.Balance,s1.pin);
//    }
  
}  

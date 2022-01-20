#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<ctype.h>
#include<stdbool.h>
#include<string.h>

typedef struct user
{char name[50],type[10];
long long int phno;
float amt;
struct user *next;}user;

bool Is_Empty(user **);
void gotoxy(short ,short );
void initiate(user **);
void terminate(user **);
user *searchbyphno(user **);
void search_display(user **);
void addrecord(user **);
void deleterecord(user **);
void deletedatabase(user **);
void modifyrecord(user **);
void listrecords(user *);
void bill(user **);
void services(user **);
void passwordcheck();




bool Is_Empty(user **h)
{
    if(*h==NULL)
        return 1;
    else
        return 0;
}



void gotoxy(short x, short y)
{
 COORD pos = {x, y};
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}



void initiate(user **h)
{ user *ptr,*prev,u;

  FILE *fp;
  if((fp=fopen("users.bin","ab+"))==NULL)
  {printf("File not able to open\n");
   exit(0);
  }

  else if(fp!=NULL)
  {fseek (fp, 0, SEEK_SET);
   fseek (fp, 0, SEEK_END);
   int size = ftell(fp);
   if(size!=0)
    {
     fseek (fp, 0, SEEK_SET);

        while(fread(&u,sizeof(user),1,fp)==1)
     {ptr=(user *)malloc(sizeof(user));
      strcpy(ptr->name,u.name);
      strcpy(ptr->type,u.type);
      ptr->phno=u.phno;
      ptr->amt=u.amt;
      ptr->next=u.next;
      if(*h==NULL)
      {*h=ptr;
       prev=*h;
       ptr=NULL;
      }
      else
      {prev->next=ptr;
       prev=ptr;
       ptr=NULL;
      }
     }
    }
    fclose(fp);
  }
}



void terminate(user **h)
{
    user *cur,u;
    FILE *fp;
    fp=fopen("users.bin","wb+");
    if(fp==NULL)
        printf("File not able to open\n");
    else
    {cur=*h;
    while(cur!=NULL)
    {strcpy(u.name,cur->name);
      strcpy(u.type,cur->type);
      u.phno=cur->phno;
      u.amt=cur->amt;
      u.next=NULL;
      fwrite(&u,sizeof(user),1,fp);
      fflush(stdin);
      cur=cur->next;
     }
    fclose(fp);}
    system("cls");
    printf("\n HAVE A GOOD DAY!!\n\n");
}



user *searchbyphno(user **h)
{system("cls");
 user *cur;
    long long int pno;
    int k=0;
    printf("Enter User's phone number to be searched...\n");
    scanf("%lli",&pno);
    cur=*h;
    if(!Is_Empty(h))
    {if((*h)->phno==pno)
		{k=1;}
    else
    {cur=cur->next;
        while(cur!=NULL && k==0)
        {if(cur->phno==pno)
        k=1;
        else cur=cur->next;}}
    if(k==0)
    printf("User not found...\n");
    else printf("User found...\n\n");
    return cur ;

  }
}



void search_display(user **h)
{user *ptr=searchbyphno(&(*h));
 if(ptr!=NULL)
 {  printf("-------------------DETAILS----------------------\n\n");
    printf(" NAME:-           %s\n",ptr->name);
    printf(" TYPE:-           %s\n",ptr->type);
    printf(" PHONE NUMBER:-   %lli\n",ptr->phno);
    if(strcmp(ptr->type,"po")==0)
    printf(" PENDING AMOUNT:- %f/-\n\n",ptr->amt);
    else
    printf(" PAID AMOUNT:-    %f/-\n\n",ptr->amt);
    printf("------------------------------------------------\n\n");
 }
}



void addrecord(user **h)
{   system("cls");
    int k=0,j;
    user *ptr,*cur,*prev;
    ptr=(user *)malloc(sizeof(user));
    printf("Enter user's name (FirstName_MiddleName_LastName)...\n");
    scanf(" %s", ptr->name);
    do{ printf("Enter plan type i.e. prepaid/postpaid (pr/po)...\n");
        scanf(" %s", ptr->type);
        if(strcmp(ptr->type,"po")==0)
            j=1;
        else if(strcmp(ptr->type,"pr")==0)
            j=1;
        else
        {printf("Wrong input...Enter again!\n");
         j=0;
        }
    }while(j==0);
    printf("Enter user's phone number...\n");
    scanf("%lli",&ptr->phno);
    if(strcmp(ptr->type,"po")==0)
    printf("Enter amount to be paid later...\n");
    else
    printf("Enter paid amount...\n");
    scanf("%f",&ptr->amt);
    ptr->next=NULL;
    if(*h==NULL)
    *h=ptr;
    else if((*h)->phno<ptr->phno)
    {ptr->next=*h;
     *h=ptr;
    }
    else
    {cur=*h;
    while(cur!=NULL&&k==0)
        {if(cur->phno>ptr->phno)
         {prev=cur;
          cur=cur->next;
         }
         else
         {prev->next=ptr;
          ptr->next=cur;
          k=1;
         }
        }
    if(cur==NULL)
        prev->next=ptr;

    }
}



void deleterecord(user **h)
{   system("cls");
    user *cur,*tmp;
    int f=0;
    long long int pno;
    printf("Enter User's phone number to be deleted...\n");
    scanf("%lli",&pno);
    cur=*h;
    if(!Is_Empty(h))
    {if((*h)->phno==pno)
     {  tmp=*h;
        *h=(*h)->next;
		free(tmp);
		printf("User found and deleted...\n");
     }
     else
     {
      while(cur->next!=NULL&&f==0)
      {if(cur->next->phno==pno)
       {tmp=cur->next;
        cur->next=tmp->next;
        free(tmp);
        printf("User found and deleted...\n");
        f=1;
       }
      else
      cur=cur->next;
      }
      if(f==0)
      {
          printf("User not found...\n");
      }
     }
    }
    else printf(" List empty...\n");
}



void deletedatabase(user **h)
{ system("cls");
    user *cur,*tmp;
    cur=*h;
    while(cur!=NULL)
        {tmp=cur->next;
         free(cur);
         cur=tmp;
        }
    *h=NULL;
    printf("LINKED LIST DATABASE DELETED...\n");
}



void modifyrecord(user **h)
{system("cls");
 user *ptr=searchbyphno(&(*h));

 if(ptr!=NULL)
 {printf("-------------------DETAILS----------------------\n\n");
  printf(" NAME:-           %s\n",ptr->name);
  printf(" TYPE:-           %s\n",ptr->type);
  printf(" PHONE NUMBER:-   %lli\n",ptr->phno);
  if(strcmp(ptr->type,"po")==0)
  printf(" PENDING AMOUNT:- %f/-\n\n",ptr->amt);
  else
  printf(" PAID AMOUNT:-    %f/-\n\n",ptr->amt);
  printf("------------------------------------------------\n\n");
  if(strcmp(ptr->type,"po")==0)
  {if(ptr->amt>0)
   {
        printf("KINDLY CLEAR YOUR PENDING AMOUNT TO MODIFY THIS RECORD...\n");
   }
   else
   {    printf("Enter user's new name...\n");
        scanf(" %s", ptr->name);
        printf("Enter new plan type. i.e. prepaid/postpaid (pr/po)...\n");
        scanf(" %s", ptr->type);
        if(strcmp(ptr->type,"po")==0)
            printf("Enter new amount to be paid later...\n");
        else
            printf("Enter new paid amount...\n");
        scanf("%f",&ptr->amt);
        printf("Record updated...\n");

   }
  }
  else
  {
   printf("Enter user's new name...\n");
   scanf(" %s", ptr->name);
   printf("Enter new plan type. i.e. prepaid/postpaid (pr/po)...\n");
   scanf(" %s", ptr->type);
   if(strcmp(ptr->type,"po")==0)
    printf("Enter new amount to be paid later...\n");
   else
    printf("Enter new paid amount...\n");
   scanf("%f",&ptr->amt);
   printf("Record updated...\n");
  }
 }
}



void listrecords(user *h)
{system("cls");
 user *cur;
 cur=h;

 if(!Is_Empty(&h))
 { printf("\n-------------------DATABASE---------------------\n\n");
   while(cur!=NULL)
   {printf(" NAME:-           %s\n",cur->name);
    printf(" TYPE:-           %s\n",cur->type);
    printf(" PHONE NUMBER:-   %lli\n",cur->phno);
    if(strcmp(cur->type,"po")==0)
    printf(" PENDING AMOUNT:- %f/-\n\n",cur->amt);
    else
    printf(" PAID AMOUNT:-    %f/-\n\n",cur->amt);
    printf("------------------------------------------------\n\n");
    cur=cur->next;
   }
 }
 else printf("\n Empty List...\n");
}



void bill(user **h)
{system("cls");
 float am; char ch;
 user *ptr=searchbyphno(&(*h));
 if(ptr!=NULL)
 {printf("---------------------BILL-----------------------\n\n");
  printf(" NAME:-           %s\n",ptr->name);
  printf(" TYPE:-           %s\n",ptr->type);
  printf(" PHONE NUMBER:-   %lli\n",ptr->phno);
  if(strcmp(ptr->type,"po")==0)
  printf(" PENDING AMOUNT:- %f/-\n\n",ptr->amt);
  else
  printf(" PAID AMOUNT:-    %f/-\n\n",ptr->amt);
  printf("------------------------------------------------\n\n");
  if(strcmp(ptr->type,"po")==0)
  {if(ptr->amt>0)
   {printf("Pay now?(y/n)\n");
   scanf(" %c",&ch);
     if(ch=='y'||ch=='Y')
     {
      {
        printf("Enter amount of payment...\n");
        scanf("%f",&am);
        ptr->amt-=am;
      }
      if(ptr->amt>0)
      {   printf("AMOUNT UPDATED...\n");
          printf("COMPLETE AMOUNT NOT PAID...PLS DO THE NEEDFUL!\n");
      }
      else
      {  printf("COMPLETE AMOUNT PAID...\n");
          printf("THANK YOU FOR USING OUR SERVICES!!\n");
      }
     }
    }
    else
    {
       printf("COMPLETE AMOUNT PAID...\n");
          printf("THANK YOU FOR USING OUR SERVICES!!\n");
    }
   }
   else
   {  printf("COMPLETE AMOUNT PAID...\n");
      printf("THANK YOU FOR USING OUR SERVICES!!\n");
   }
 }
}



void services(user **h)
{system("cls");
 float am; char ch;
 user *ptr=searchbyphno(&(*h));
 if(ptr!=NULL)
 {printf("-------------------DETAILS----------------------\n\n");
  printf(" NAME:-           %s\n",ptr->name);
  printf(" TYPE:-           %s\n",ptr->type);
  printf(" PHONE NUMBER:-   %lli\n",ptr->phno);
  if(strcmp(ptr->type,"po")==0)
  printf(" PENDING AMOUNT:- %f/-\n",ptr->amt);
  else
  printf(" PAID AMOUNT:-    %f/-\n",ptr->amt);
  printf("------------------------------------------------\n\n");
  if(strcmp(ptr->type,"po")==0)
  {if(ptr->amt>0)
   {
        printf("KINDLY CLEAR YOUR PENDING AMOUNT TO AVAIL FURTHER SERVICES...\n");
   }
   else
   {
        printf("Enter amount for which services are to be availed...\n");
        scanf("%f",&am);
        ptr->amt+=am;
        printf("THANK YOU FOR USING OUR SERVICES!!\n");
   }
  }
  else
  {
    printf("Enter amount for which services are to be availed...\n");
    scanf("%f",&am);
    ptr->amt=am;
    printf("THANK YOU FOR USING OUR SERVICES!!\n");
  }
 }
}




void passwordcheck()
{int u,p,count=0,k=0;char passchk[]="telcom123",useridchk[]="Employee1",password[50],userid[50];
char c;
   do{system("cls");password[0]='\0';userid[0]='\0';
    gotoxy(28,8); printf("***************************************************************");
	gotoxy(28,9); printf("*                                                             *");
	gotoxy(28,10);printf("*                            LOGIN                            *");
	gotoxy(28,11);printf("*                           _______                           *");
	gotoxy(28,12);printf("*                                                             *");
	gotoxy(28,13);printf("*                     USER ID :-                              *");
	gotoxy(28,14);printf("*                     PASSWORD :-                             *");
	gotoxy(28,15);printf("*                                                             *");
	gotoxy(28,16);printf("***************************************************************");
    gotoxy(62,13);scanf(" %s",userid);

    gotoxy(62,14);
    c=getch();
    int j=0;
    while(c!=13)
    {  if(c==27)
       exit(0);
      if(c==8 && j!=0)
      {printf("\b");
	 printf(" ");
	 printf("\b");
	 j--;
      }
      else if(c==8 && j==0)
      { ;}
      else
      {printf("*");
	password[j]=c;
	j++;
      }
      c=getch();
   }
   password[j]='\0';
   u=strcmp(userid,useridchk);
   p=strcmp(password,passchk);
   if(u!=0||p!=0)
   {
      gotoxy(30,18);printf("INCORRECT USER ID OR PASSWORD...PRESS ENTER TO TRY AGAIN!");
      count++;
      getch();
   }
   else
   {k=1;}
  }while(count<=4&&k!=1);
  if(count>4&&k!=1)
  {system("cls");
   printf("YOU HAVE TRIED UNSUCCESSFUL FOR 5 TIMES...EXIT PROGRAM AND RESTART TO TRY AGAIN...");
   exit(0);
  }
}



void main()
{   user *head=NULL;
    char ans,a,password[50],passchck[50],userid[50],useridchk[50];
    int choice;


    gotoxy(28,8); printf("***************************************************************");
	gotoxy(28,9); printf("*                                                             *");
	gotoxy(28,10);printf("*      WELCOME TO THE TELECOM BILLING MANAGEMENT SYSTEM!      *");
	gotoxy(28,11);printf("*                                                             *");
	gotoxy(28,12);printf("*                        PRESENTED BY :-                      *");
	gotoxy(28,13);printf("*                       JASHAN DEEP SETHI                     *");
	gotoxy(28,14);printf("*                        APOORV VERMA                         *");
	gotoxy(28,15);printf("*                        ASHWIN NAIR                          *");
	gotoxy(28,16);printf("*                       PRIYANSHU BANSAL                      *");
	gotoxy(28,17);printf("*                                                             *");
	gotoxy(28,18);printf("*                   PRESS ANY KEY TO CONTINUE...              *");
	gotoxy(28,19);printf("*                                                             *");
	gotoxy(28,20);printf("***************************************************************");
    getch();
    passwordcheck();
    initiate(&head);

	do{ system("cls");
        printf("\n   MAIN MENU\n");
        printf("   ---------\n\n");
        printf(" 1. ADD RECORDS...\n\n");
        printf(" 2. DELETE RECORDS...\n\n");
        printf(" 3. DISPLAY ALL RECORDS...\n\n");
        printf(" 4. MODIFY RECORDS...\n\n");
        printf(" 5. SEARCH RECORDS...\n\n");
        printf(" 6. BILLS AND PAYMENTS...\n\n");
        printf(" 7. AVAIL SERVICES...\n\n");
        printf(" 8. DELETE DATABASE...\n\n");
        printf(" 9. EXIT...\n\n");
        printf("ENTER CHOICE...\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: do{addrecord(&head);
                       printf("\nAdd another record?(y/n)\n");
                       scanf(" %c",&a);
                      }while(a=='y'||a=='Y');
                    break;

            case 2: do{deleterecord(&head);
                       printf("\nDelete another record?(y/n)\n");
                       scanf(" %c",&a);
                      }while(a=='y'||a=='Y');
                    break;

            case 3: listrecords(head);
                    break;

            case 4: do{modifyrecord(&head);
                       printf("\nUpdate another record?(y/n)\n");
                       scanf(" %c",&a);
                      }while(a=='y'||a=='Y');
                    break;

            case 5: do{search_display(&head);
                       printf("\nSearch another record?(y/n)\n");
                       scanf(" %c",&a);
                      }while(a=='y'||a=='Y');
                    break;

            case 6: do{bill(&head);
                       printf("\nGenerate bill for another record?(y/n)\n");
                       scanf(" %c",&a);
                      }while(a=='y'||a=='Y');
                    break;

            case 7: do{services(&head);
                       printf("\nAvail services for another user?(y/n)\n");
                       scanf(" %c",&a);
                      }while(a=='y'||a=='Y');
                    break;

            case 8: deletedatabase(&head);
                    break;

            case 9: terminate(&head);
                    exit(0);

            default:system("cls");
                    printf("Wrong choice...\n");


        }
    printf("Back to main menu?(y/n)\n");
    scanf(" %c",&ans);
    }while(ans=='y'||ans=='Y');
    terminate(&head);
}

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct Item
{
     char name[50];
     float rating;
     float price;
     int food_Id_No;
     struct Item *next;
     struct Item *prev;
};

int cust_id=1;
struct Item* head;
struct Item* last;
int Today_custmer=0;
float total_income=0;

struct order_hist
{
	int Customer_ID;
	int items[10][2];
	float amount;
	char date[11];
	struct order_hist *next;
	struct order_hist *prev;
};

struct order_hist* head1;
struct order_hist* last1;

struct Item* getnewNode(char a[],float p,int fin)
{
    struct Item* temp=(struct Item*)malloc(sizeof(struct Item));

    temp->food_Id_No=fin;
    strcpy(temp->name,a);
    temp->rating=4.0;
    temp->price=p;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

void insert(char n[],float p,int fin)
{
     struct Item* temp1=getnewNode(n,p,fin);
	 if(head==NULL)
	 {
	 	head=temp1;
	 	last=temp1;
	 }

    else
	{

	 	temp1->prev=last;
	 	last->next=temp1;
	 	last=temp1;
    }
}

struct order_hist* getnewNode_hist()
{
	struct order_hist* temp=(struct order_hist*)malloc(sizeof(struct order_hist));
	temp->next=temp->prev=NULL;
	return (temp);
}

void Display()
{
	printf("                                                -------------                                            \n");
	printf("-----------------------------------------------------MENU-------------------------------------------------\n");
	printf("                                                -------------                                            \n");
	printf("INDEX   |  ITEM NAME  |   PRICE    |   RATING\n");

    struct Item* temp=head;
    if(head==NULL)
    {
    	printf("Empty");
	}

    while(temp!=NULL)
    {
    	printf("%d\t%s\t%f\t%f\n",temp->food_Id_No,temp->name,temp->price,temp->rating);
    	temp=temp->next;
	}
	printf("---------------------------------------------------------------------------------------------------------\n");
}


int login()
{
      char username[20];
      char userpwd[11]; // for storing password
      int i;

      printf("Enter your User Name : ");
      scanf("%s",username);

      printf("Enter your password : ");
      for(i=0;i<10;i++)
      {
           userpwd[i]=getch();
           printf("*");
      }
      userpwd[i]='\0';


     if(!strcmp(username,"Admin") && !strcmp(userpwd,"dhruvin123"))
     {
          printf("\n\nLogged In Successful\n");
          return 1;
     }

     else
    {
        printf("\n\nIncorrect username or password\n");
        return 0;
    }
}

void order()
{
    int a[10][2];
    int n,j=0,i=0;

    do{
            printf("Please enter the FOOD ID NUMBER OF ITEM AND ITS QUANTITY\n");
            for(i=0;i<2;i++)
            {
                scanf("%d",&a[j][i]);
            }
            j++;
            printf("You want More item?\n1.yes\n2.no");
            scanf("%d",&n);
    }while(n==1);

    float total_amount=0.0;
    char name[25];
    char Date[10];
    printf("Enter your Name : ");
    scanf("%s",name);
    printf("Enter Today's Date : ");
    scanf("%s",Date);
    int k=0;
    printf("\n-------------------------------------------------------------------------------------------------------\n");
    printf("                                          BILL                             \n");

    printf("Name:-%s\n",name);
    printf("Date:-%s\n",Date);

    for(k=0;k<j;k++)
    {
        struct Item* temp=head;
        while(temp->food_Id_No!=a[k][0])
        {
            temp=temp->next;
        }//printf("%f\n",temp->price);

        printf("-------------------------------------------------------------------------------------------------------\n");
        printf("%d\t%s\t%d\t\t%f\n",temp->food_Id_No,temp->name,a[k][1],(a[k][1]*(temp->price)));
        total_amount+=(a[k][1]*(temp->price));
    }

    printf("-------------------------------------------------------------------------------------------------------\n");
    printf("\nTotal Payable Amount is:-\t\t%f\n",total_amount);
    printf("-------------------------------------------------------------------------------------------------------\n");

    struct order_hist* temp2=getnewNode_hist();
    temp2->amount=total_amount;
    temp2->Customer_ID=cust_id++;

    int p,s;

    for(p=0;p<j;p++)
    {
	  	for(s=0;s<2;s++)
	  	{
	  		temp2->items[p][s]=a[p][s];
        }
    }

    if(head1==NULL)
    {
        head1=last1=temp2;
    }

    else
    {
		last1->next=temp2;
		temp2->prev=last1;
		last1=temp2;
    }

    strcpy(temp2->date,Date);

    Today_custmer++;
    total_income+=total_amount;
}


void display_rd_hist()
{
    printf("                                                       -------------                                                 \n");
    printf("\n-----------------------------------------------------ORDER HISTORY-------------------------------------------------\n");
    printf("                                                       -------------                                                 \n");
    printf("SR_NO     DATE      TOTAL AMOUNT\n");

    struct order_hist* temp=head1;
    if(head1==NULL)
    {
    	printf("Empty");
	}

    while(temp!=NULL)
    {
    	printf("%d\t%s\t%f\t\n",temp->Customer_ID,temp->date,temp->amount);
    	temp=temp->next;
	}
}

main()
{
	head=NULL;
	last=NULL;

	insert("Burger   ",99.00,1);
	insert("Pizza    ",235.65,2);
	insert("Hot Cake ",750.00,3);
	insert("Coffee   ",70.50,4);
	insert("Ice-Cream",80.00,5);
	insert("Sandwich ",60.00,6);
	insert("Grill    ",52.50,7);
	insert("Maggi    ",35.00,8);
	insert("Cold Drinks",20.00,9);

    int choice;

    do{
        printf("\n-------------------------------------------------------------------------------");
        printf("\n1....FOOD PART");
        printf("\n2....ADMIN PANEL");
        printf("\n3....EXIT");

        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("");
                int ex;

                do{
                    printf("1.       FOOD LIST\n2.       ORDER\n");
                    int n;
                    scanf("%d",&n);

                    switch(n)
                    {
                        case 1: Display();
                                break;
                        case 2: order();
                                break;
                    }

                    printf("1.FOOD PART \n2.MAIN MENU\n");
					scanf("%d",&ex);
				}while(ex==1);
            break;

            case 2:
                printf("\n");
                int k=login();
                int e;
                if(k==1){

                do{
                    printf("-------------------------------------------------------------------------------------------------------\n");
                    printf("1.     ADD NEW DISH\n");
                    printf("2.     TODAY'S  TOTAL INCOME\n");
                    printf("3.     TODAY TOTAL NO OF CUSTOMER\n");
                    printf("4.     ORDER HISTORY\n");
                    printf("5      LIST OF ITEM\n");
                    printf("\n------------------------------------------------------------------------------------------------------\n");

                    int ch;
                    scanf("%d",&ch);
                    switch(ch)
                    {
                        case 1:
                            printf(" ");
                            float p;
						    int fin;
							char  n[50];

							printf("Enter the name of Item");
							scanf("%s",n);

							printf("Enter the Price of Item");
							scanf("%f",&p);

							printf("Enter the food_id_no of Item");
							scanf("%d",&fin);

							insert(n,p,fin);
                            printf("-------------------------------------------------------------------------------------------------------\n");
					        printf("                 NEW DISH IS ADDED SUCESSFULLY.......\n");
                            printf("-------------------------------------------------------------------------------------------------------\n");
					        printf("\n");
                        break;

                        case 2:
                            printf("-------------------------------------------------------------------------------------------------------\n");
                            printf("        TODAY'S  TOTAL INCOME IS:- %f\n",total_income);
                            printf("-------------------------------------------------------------------------------------------------------\n");
                        break;

                        case 3:
                            printf("-------------------------------------------------------------------------------------------------------\n");
					        printf("        TODAY TOTAL NO OF CUSTOMER VISITED ID:-%d\n",Today_custmer);
                            printf("-------------------------------------------------------------------------------------------------------\n");
                        break;

                        case 4:
                            printf("-------------------------------------------------------------------------------------------------------\n");
					        printf("	                ORDER SUMMARY");
					        printf("-------------------------------------------------------------------------------------------------------\n");
                            display_rd_hist();
                            printf("\n");
                        break;

                        case 5:
                            printf("\n");
                            Display();
                        break;

					}

					printf("1.ADMIN PANEL\n2.MAIN MENU\n");
					scanf("%d",&e);

				}while(e==1);
			}
				break;
        }

    }while(choice!=3);
}

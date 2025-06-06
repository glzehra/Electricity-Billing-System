#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct user{
	char name[50];
	float bill[4];
	char id[7];
	int status;
	int membership;
};
int n=4;
char a[4];
//FUNCTION DECLARATIONS
int scanPass(char *password, int max);
void viewingCurrentBill(struct user customer[100], char *un);
void viewingtaxcalculations(struct user customer[100], char *un);
int checkPassword(const char *password);
void add(struct user customer[100]);
int Display(struct user customer[100]);
int Update(struct user customer[100]);
void penalty(struct user customer[100]);
void discountandinstallments(struct user customer[100], char *un);
void electricityusage(char a[],int size);

//MAIN FUNCTION
int main()
{
	struct user customer[100]={
							{"David",{120.7,123.3,700,890.3}, "k011234" ,1,345},
							{"Sarah",{100.1,153.99,900.9,450.6}, "k011235" ,0,789},
							{"John",{123.45,159.56,893.4,234.6}, "k011236" ,1,980},
							{"Jake",{432.1,986,554.0,829.5}, "k011237" ,1,897}
							};
	int c,x,r,fc;
	char pass[50];
	int max=3;
	char un[8];
	printf("Welcome! Choose your Module from Below:\n");
	printf("1. Admin\n2. Customer\n");
	printf("Enter Your Choice: ");
	scanf("%d",&c);
	if(c==1)
	{
    	if(scanPass(pass,max))
		{
			while(x!=5)
		{
			system("cls");
		printf("1. Add User\n");
		printf("2. Update User Information\n");
		printf("3. Display User Information\n");
		printf("4. View Fine/Penalty Details");
		printf("\n5. Exit\n");
		printf("Your Choice: ");
		scanf("%d",&x);
		switch(x)
	{
		case 1:
			add(customer);
		break;
		case 2:
			Update(customer);
		break;
		case 3:
			Display(customer);
		break;
		case 4:
			penalty(customer);
		break;
		case 5:
			printf("Thankyou for using our application!");
		break;
		default:		
		printf("Invalid Choice");
		break;
	}
	}	
	}
		else
		{
			
			printf("Invalid Password Entered! Program Exiting.");
		}
		
	}
	else if (c==2)
	{
		int i;
		printf("Enter your ID: ");
		scanf("%s",un);
		for(i=0;i<n;i++)
		{
			if(strcmp(un,customer[i].id)==0)
			{
				printf("ID found!\n");
				sleep(2);
		while(x!=5)
		{
			system("cls");
		printf("1. View Your Bill\n");
		printf("2. View Discounts for Membership Users\n");
		printf("3. View Tax Details\n");
		printf("4. Electricity Usage Details\n");
		printf("5. Exit\n");
		printf("Enter Your Choice: ");
		scanf("%d",&x);
	switch(x)
	{
		case 1:
			viewingCurrentBill(customer,un);
		break;
		case 2:
			discountandinstallments(customer,un);
		break;
		case 3:
			viewingtaxcalculations(customer,un);
		break;
		case 4:
			electricityusage(a,4);
			x=0;
		break;
		case 5:
			printf("thankyou!");
		break;
		default:
		printf("Invalid Choice! please try again.");
		break;
	}
		}
		}
		else
			{
				fc++;
				if(fc>=n)
				{
					printf("ID not found! please try again!\n");
				}
			}
}
	}
	else
	{
		printf("Invalid Choice! please try again.");
	}
	return 0;
}
//VIEWING VURRENT BILLS (CUSTOMER)
void viewingCurrentBill(struct user customer[100], char *un)
{
	system("cls");
	int c,i,j;
	for(i=0;i<n;i++)
	{
		if(strcmp(un,customer[i].id)==0)
		{
			printf("1. View Current Bill\n");
			printf("2. View Past 3 Months Bill\n");
			printf("Enter Your Choice: ");
			scanf("%d",&c);
		switch(c)
		{
			case 1:
				printf("Your Current Bill is: $%.2f\n",customer[i].bill[0]);
				printf("Exiting in 5 seconds");
				sleep(5);
			break;
			case 2:
				for(j=0;j<3;j++)
				{
					printf("Bill of Month %d: $%.2f\n",j+1,customer[i].bill[j]);
				}
				printf("Exiting in 5 seconds");
				sleep(5);
			break;
			case 3:
				printf("You Have Successfully Exited The Program");
				break;
			default:
				printf("Invalid Choice");
			break;
		}	
	}
}
		return;
			
}
//VIEW TAX BILLS
void viewingtaxcalculations(struct user customer[100], char *un)
{
	system("cls");
	float generaltax=0.2;
	float tax_bills;
	int i;
	for(i=0;i<10;i++)
	{
		if(strcmp(un,customer[i].id)==0)
	{
		printf("Welcome %s!\n",customer[i].name);
	    tax_bills = customer[i].bill[0] + (customer[i].bill[0]*generaltax);
		printf("Taxes of Your Current Bill are:$%.2f\n",tax_bills);
		printf("NOTE: \n");
		printf("The Tax calculated is 0.2 percent of your Current Bill. \n");
		printf("Exiting in 5 Seconds.");
		sleep(5);
	}
    }
}
//TO CHECK PASSWORD (ADMIN)
int checkPassword(const char *password)
{
	char correctPass[]="123admin";
	return strcmp(correctPass, password)==0?1:0;
}
//ADDUSER
void add(struct user customer[100])
{
	system("cls");
n++;
	struct user *ptr = (struct user*) malloc(n*sizeof(struct user));
	int i;
	FILE *file;
	file=fopen("store.txt","a");
	for(i=0;i<n;i++){
		ptr[i] =customer[i];
	}
	//int i;
	printf("Enter Name of the New Customer: ");
	scanf("%s",ptr[n-1].name);
	printf("Enter New ID of the Customer: ");
	scanf("%s",ptr[n-1].id);
	printf("Enter Membership Number of the customer: ");
	scanf("%d",&ptr[n-1].membership);
	 fprintf(file, "added:\n%s %s %d\n", ptr[n-1].name, ptr[n-1].id, ptr[n-1].membership);
	for(i=0;i<4;i++)
	{
		ptr[n-1].bill[i] = 0;
	}
	ptr[n-1].status = 0;
	printf("You Have Successfully Added a User!\n");
	printf("Your Customer ID is :%s\n",ptr[n-1].id);
	customer[n-1]=ptr[n-1];
	fclose(file);
	free(ptr);
	printf("Exiting in 3 Seconds.");
	sleep(3);
}
//TO DISPLAY (ADMIN)
int Display(struct user customer[100])
{
	system("cls");
	int i;
	FILE *file;
	file=fopen("store.txt","a");
	printf("Billing Details Of All Customers Are: \n");
	printf("USER NUMBER:\tMONTH 1\t\tMONTH 2\t\tMONTH 3\t\tMONTH 4\t\tID\t\tSTATUS\n");
	for(i=0;i<n;i++)
	{
		printf("%s\t\t",customer[i].name);
		printf("$%.2f\t\t$%.2f\t\t$%.2f\t\t$%.2f\t\t",customer[i].bill[0],customer[i].bill[1],customer[i].bill[2],customer[i].bill[3]);
		printf("%s\t\t",customer[i].id);
		printf("%s\n",((customer[i].status)==1)?"Payed":"Unpayed");

	 // Write the customer data to the file
        fprintf(file, "display \n%s %.2f %.2f %.2f %.2f %s %d %d\n", customer[i].name,
                customer[i].bill[0], customer[i].bill[1], customer[i].bill[2],
                customer[i].bill[3], customer[i].id, customer[i].status,
                customer[i].membership);
            }
    fclose(file);
    printf("\nExiting in 5 Seconds.");
	sleep(5);
	return 1;
}
// UPDATE (ADMIN)
int Update(struct user customer[100]) {
	system("cls");
    char un[50];
    int i, c, c1;

    printf("Enter Customer Name: ");
    scanf("%s", un);
    for (i = 0; i < n; i++) {
        if (strcmp(un, customer[i].name) == 0) {
            printf("Customer found!\n");
            printf("1. Bill\n2. Customer ID\n3. Status\n4. Exit\n");
            printf("Choose what you want to update: ");
            scanf("%d", &c);
			
            switch (c) {
                case 1:
                	system("cls");
                    printf("1. Bill Month 1\n2. Bill Month 2\n3. Bill Month 3\n4. Bill Month 4\n");
                    printf("Your Choice: ");
                    scanf("%d", &c1);

                    switch (c1) {
                        case 1:
                        	system("cls");
                            printf("Enter Bill for month 1: $");
                            scanf("%f", &customer[i].bill[0]);
                            printf("Bill Updated!\n");
                            break;
                        case 2:
                        	system("cls");
                            printf("Enter Bill for month 2: $");
                            scanf("%f", &customer[i].bill[1]);
                            printf("Bill Updated!\n");
                            break;
                        case 3:
                        	system("cls");
                            printf("Enter Bill for month 3: $");
                            scanf("%f", &customer[i].bill[2]);
                            printf("Bill Updated!\n");
                            break;
                        case 4:
                        	system("cls");
                            printf("Enter Bill for month 4: $");
                            scanf("%f", &customer[i].bill[3]);
                            printf("Bill Updated!\n");
                            break;
                        default:
                            printf("Invalid choice for updating bill.\n");
                            break;
                    }
                    break;
                case 2:
                	system("cls");
                    printf("Enter new ID: ");
                    scanf("%s", customer[i].id);
                    printf("ID Updated!\n");
                    break;
                case 3:
                	system("cls");
                    printf("Enter status (1 or 0): ");
                    scanf("%d", &customer[i].status);
                    printf("Status Updated!\n");
                    break;
                case 4:
                    break;
                default:
                    printf("Invalid choice.\n");
                    break;
            }

            // Write the updated data to a file
            FILE *file = fopen("store.txt", "a");
            if (file != NULL) {
                fprintf(file, "Name: %s\n", customer[i].name);
                fprintf(file, "ID: %s\n", customer[i].id);
                fprintf(file, "Status: %s\n", (customer[i].status == 0) ? "Payed" : "Unpayed");
                fprintf(file, "Membership: %d\n", customer[i].membership);
                fprintf(file, "Bills: $%.2f $%.2f $%.2f $%.2f\n", customer[i].bill[0], customer[i].bill[1], customer[i].bill[2], customer[i].bill[3]);
                fprintf(file, "----------------------------------------\n");
                fclose(file);
            }
            break;
        }
    }
    printf("Exiting in 5 seconds.");
    sleep(5);
}

//VIEW PENALTY (ADMIN)
void penalty(struct user customer[100]) {
	system("cls");
    char ud[8];
    int i, day;
    float pen = 0;
    float d_pen = 0;

    printf("Enter User ID: ");
    scanf("%7s", &ud);
    FILE *file = fopen("store.txt", "a");

    for (i = 0; i < n; i++) {
        if (strcmp(ud, customer[i].id) == 0) {
            printf("Name of the customer: %s\n", customer[i].name);

            if (customer[i].status == 1) {
                printf("No Penalty! Bill has been paid on time.\n");
                if(file!=NULL){
                	fprintf(file, "Name: %s\n", customer[i].name);
                    fprintf(file, "ID: %s\n", customer[i].id);
                	fprintf(file,"No Penalty! Bill has been paid on time.\n");
				}
            } else {
                printf("How long has the bill been due (days)?: ");
                scanf("%d", &day);
                pen = customer[i].bill[0];
                d_pen = pen + (day * 100);

                printf("The original bill is: $%.2f\n", customer[i].bill[0]);
                printf("The penalty after %d days in the bill is: $%.2f\n", day, d_pen);

                // Write penalty information to a file
                if (file != NULL) {
                    fprintf(file, "Name: %s\n", customer[i].name);
                    fprintf(file, "ID: %s\n", customer[i].id);
                    fprintf(file, "Original Bill: $%.2f\n", customer[i].bill[0]);
                    fprintf(file, "Penalty after %d days: $%.2f\n", day, d_pen);
                    fclose(file);
                }
            }
        }
    }
    printf("Exiting in 5 seconds.\n");
    sleep(5);
}

//DISCOUNT (USER)
void discountandinstallments(struct user customer[100], char *un)
{
	system("cls");
	char m[6];
	float discount;
	int i;
	for(i=0;i<n;i++)
	{
		if(strcmp(un,customer[i].id)==0)
		{
			printf("Welcome %s\n",customer[i].name);
		if(customer[i].membership!=0)
		{
			int duration;
			float discounts;
			if(customer[i].bill[0]>100 && customer[i].bill[0]<500)
			{
				discounts=customer[i].bill[0]-(customer[i].bill[0]*0.10);
				printf("Customer Name: %s\n",customer[i].name);
				printf("Original bill amount: $%.2f\n",customer[i].bill[0]);
		        printf("Discounted amount to pay: $%.2f\n",discounts);
				printf("Status: %s\n",(customer[i].status==0)?"Payed":"Unpayed");
			}
			else if(customer[i].bill[0]>500)
			{
				discounts=customer[i].bill[0]-(customer[i].bill[0]*0.20);
				printf("Customer Name: %s\n",customer[i].name);
				printf("Original bill amount: $%.2f\n",customer[i].bill[0]);
				printf("Discounted amount to pay: $%.2f\n",discounts);
				printf("Status: %s\n",(customer[i].status==0)?"Payed":"Unpayed");	
			}
			else
			{
				discounts=customer[i].bill[0]-(customer[i].bill[0]*0.05);
				printf("Customer Name: %s\n",customer[i].name);
				printf("Original bill amount: $%.2f\n",customer[i].bill[0]);
				printf("Discounted amount to pay: $%.2f\n",discounts);
				printf("Status: %s\n",(customer[i].status==0)?"Payed":"Unpayed");	
			}
			}
			else
			{
				printf("No discounts for users with no Memberships!\n");
			}
			break;
	}
	}
	printf("Exiting in 5 Seconds.");
	sleep(5);
}
//SCANNING PASSWORD(ADMIN)
int scanPass(char *password,int max)
{
	system("cls");
	printf("Welcome Admin!\n");
	printf("Enter the password to get access: ");
	scanf("%s",password);
    if (!checkPassword(password)) 
	{
        if (max>1) 
		{
            printf("Wrong password\nTry again in 2 Seconds.\n");
            sleep(2);
            scanPass(password,max-1);
        } 
		else 
		{
            return 0;
        }
    } 
	else 
	{
        printf("Access granted!\n");
        sleep(1);
        return 1;
    }
}
//ELECTRICITY USAGE DETAILS(CUSTOMER)
void electricityusage(char a[],int size)
{
	system("cls");
	int i;
	printf("A. Air Condition\nF. Fridge\nW. Washing Machine\nL. Lights\nH. Heaters\nC. Ceiling fan\nE. Electric Oven\nT. Television \n");
	printf("What are the the Four (4) appliances from the list that are used most frequently in your house?");
	printf("\nYour Answer: \n");
	for(i=0;i<4;i++)
	{
		scanf(" %c",&a[i]);
	}
	system("cls");
	printf("Your Usage Details are: \n");
	for(i=0;i<4;i++){
		if(a[i]=='A'){
			printf("Air condition: %d%%\n",rand()%100+1);
		}
		if(a[i]=='F'){
			printf("Fridge:%d%%\n",rand()%100+1);
		}
		if(a[i]=='W'){
			printf("Washing machine: %d%%\n",rand()%50+1);
		}
		if(a[i]=='L'){
			printf("lights: %d%%\n",rand()%18+1);
		}
		if(a[i]=='H'){
			printf("Heaters: %d%%\n",rand()%5+1);
		}
		if(a[i]=='C'){
			printf("Ceiling fan: %d%%\n",rand()%30+1);
		}
		if(a[i]=='E'){
			printf("Electric oven: %d%%\n",rand()%10+1);
		}
		if(a[i]=='T'){
			printf("Television: %d%%\n",rand()%100+1);
		}
	}
	printf("Exiting in 3 seconds.");
	sleep(3);
}

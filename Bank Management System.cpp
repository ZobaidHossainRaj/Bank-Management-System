#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
FILE *data,*data1;                                 //Global file declaration.................
char file_name[10],c;

//This function is declared..............
void add(struct account detail);
void view(struct account detail);
void balance(struct account detail);
void update(struct account detail);
void test();
void write();
char test_back(char x);

struct account                                                            //This is a structure declared..............
{
    char name[50],father[50],mother[50],balance[50],pasword[20],birthday[15],pre_address[200];
    char permanent_add[200],phone[10],mobile[15],nationality[20],merital_status[20],email[100];
};

struct account detail;                  //Structure variable declaration..................


//This is user define function.....Execution starts fronm hare........
int main()
{
    int n;
    while(n != 0)
    {
        printf("\n\t **** Welcome to Bank Management System ****");
        printf("\n\n\n\t\t\tMAIN MANU\n\t\t=====================\n\t\t[1] Create account\n\t\t[2] view account\n\t\t[3] Balance check\n\t\t[4] Update Account\n\t\t[5] Delete account\n\t\t[0] Exit\n\t\t=================\n\t\t");
        printf("Enter the choice:");
        scanf("%d",&n);
        if(n == 1)
        {
            add(detail);
        }
        else if(n==2)
        {
            view(detail);
        }
        else if(n == 3)
        {
            balance(detail);
        }
        else if(n == 4)
        {
            update(detail);
        }
        else if(n==5)
        {
            system("cls");
            printf("\n\t\t================================\n\t\t\tDELETE ACCOUNT\n\t\t================================\n\n");
            printf("Enter Account ID:");
            scanf("%s%*c",file_name);
            strcat(file_name,".txt");
            if((data = fopen(file_name,"r")) == NULL)
            {
                system("cls");
                printf("\n\t\t\t\t>>>> Wrong ID! <<<<<\n\n");
                test();
            }
            else
            {
                data = fopen(file_name,"w");
                fclose(data);
                system("cls");
                printf("\n\t\t\tDelete account successfully\n");
                test();
            }
        }
        else if(n == 0)
        {
            system("cls");
            printf("THANKS FOR USING...\n");
            printf("                   ...ZOBAED HOSSEN RAJ\n");
            exit(1);
        }
        else
        {
            system("cls");
            printf("\n\t\t\tWrong input!\n\t\t\tOnly 0-5 is parmitted\n");
            test();
        }
    }
    return 0;
}

///Adding part.....................
void add(struct account detail)
{
    int n1;
    system("cls");
    printf("\n\t\t================================\n\t\t\tCREATE ACCOUNT\n\t\t================================\n\n");
    //Here we open a file...........
    for(;;)
    {
        printf("To exit enter blank space in the ID input\n");
        printf("Enter Account ID:");
        scanf("%*c%[^\n]%*c",file_name);
        c = file_name[0];
        test_back(c);
        strcat(file_name,".txt");
        data = fopen(file_name,"w");

        printf("Name : ");
        scanf("%[^\n]",detail.name);

        printf("Father name : ");
        scanf("%*c%[^\n]",detail.father);

        printf("Mother name : ");
        scanf("%*c%[^\n]",detail.mother);

        printf("Pasword : ");
        scanf("%*c%[^\n]",detail.pasword);

        printf("Balance : ");
        scanf("%*c%[^\n]",detail.balance);

        printf("Birthday : ");
        scanf("%*c%[^\n]",detail.birthday);

        printf("Present address : ");
        scanf("%*c%[^\n]",detail.pre_address);

        printf("Parmanent address : ");
        scanf("%*c%[^\n]",detail.permanent_add);

        printf("Phone : ");
        scanf("%*c%[^\n]",detail.phone);

        printf("Mobile : ");
        scanf("%*c%[^\n]",detail.mobile);

        printf("Nationality : ");
        scanf("%*c%[^\n]",detail.nationality);

        printf("Merital status : ");
        scanf("%*c%[^\n]",detail.merital_status);

        printf("Email : ");
        scanf("%*c%[^\n]",detail.email);

        fprintf(data,"%s\n%s\n%s\n%s\n%s\n",detail.pasword,detail.name,detail.father,detail.mother,detail.balance);
        fprintf(data,"%s\n%s\n%s\n",detail.birthday,detail.pre_address,detail.permanent_add);
        fprintf(data,"%s\n%s\n%s\n%s\n%s\n",detail.phone,detail.mobile,detail.nationality,detail.merital_status,detail.email);
        fclose(data);
        system("cls");
        printf("\n\t\t\tAccount created successfully\n");
        while(1)
        {
            printf("....::Enter choice:\n");
            printf("\t\t\t\t[0] BACK\n");
            scanf("%d",&n1);
            if(n1 == 0)
            {
                system("cls");
                printf("\n\t\t================================\n\t\t\tCREATE ACCOUNT\n\t\t================================\n\n");
                break;
            }
        }
    }
}

///this part is for view............
void view(struct account detail)
{
    int n;
    system("cls");
    printf("\n\t\t================================\n\t\t\tACCOUNT DETAILS\n\t\t================================\n\n");
    while(1)
    {
        printf("To exit enter blank space in the ID input\n");
        printf("Enter Account ID:");
        scanf("%*c%[^\n]",file_name);
        c = file_name[0];
        test_back(c);
        strcat(file_name,".txt");
        if((data = fopen(file_name,"r")) == NULL)
        {
            system("cls");
            printf("\n\t\t\t\t>>>> Wrong ID! <<<<<\n\n");
            test();
            printf("\n\t\t================================\n\t\t\tACCOUNT DETAILS\n\t\t================================\n\n");
        }
        else
        {
            fscanf(data,"%[^\n]%*c%[^\n]%*c%[^\n]%*c%[^\n]%*c%[^\n]",detail.pasword,detail.name,detail.father,detail.mother,detail.balance);
            fscanf(data,"%*c%[^\n]%*c%[^\n]%*c%[^\n]",detail.birthday,detail.pre_address,detail.permanent_add);
            fscanf(data,"%*c%[^\n]%*c%[^\n]%*c%[^\n]%*c%[^\n]%*c%[^\n]",detail.phone,detail.mobile,detail.nationality,detail.merital_status,detail.email);
            printf("==========================================================================\n\n");
            printf("Pasword           : %s\n\n",detail.pasword);
            printf("Name              : %s\n\n",detail.name);
            printf("Father name       : %s\n\n",detail.father);
            printf("Mother name       : %s\n\n",detail.mother);
            printf("Balance           : %sT.K\n\n",detail.balance);
            printf("Birthday          : %s\n\n",detail.birthday);
            printf("present address   : %s\n\n",detail.pre_address);
            printf("Permanent address : %s\n\n",detail.permanent_add);
            printf("Phone             : %s\n\n",detail.phone);
            printf("Mobile            : %s\n\n",detail.mobile);
            printf("Nationality       : %s\n\n",detail.nationality);
            printf("Merital status    : %s \n\n",detail.merital_status);
            printf("Email             : %s \n\n",detail.email);
            printf("==========================================================================\n\n\n");
            fclose(data);
        }
    }
}

///This is for balance check.............
void balance(struct account detail)
{
    int n;
    system("cls");
    printf("\n\t\t================================\n\t\t\tACCOUNT BALANCE\n\t\t================================\n\n");
    while(1)
    {
        printf("To exit enter blank space in the ID input\n");
        printf("Enter Account ID:");
        scanf("%*c%[^\n]",file_name);
        c = file_name[0];
        test_back(c);
        strcat(file_name,".txt");
        if((data = fopen(file_name,"r")) == NULL)
        {
            system("cls");
            printf("\n\t\t\t\t>>>> Wrong ID! <<<<<\n\n");
            test();
            printf("\n\t\t================================\n\t\t\tACCOUNT BALANCE\n\t\t================================\n\n");
        }
        else
        {
            fscanf(data,"%[^\n]%*c%[^\n]%*c%[^\n]%*c%[^\n]%*c%[^\n]",detail.pasword,detail.name,detail.father,detail.mother,detail.balance);
            fscanf(data,"%*c%[^\n]%*c%[^\n]%*c%[^\n]",detail.birthday,detail.pre_address,detail.permanent_add);
            fscanf(data,"%*c%[^\n]%*c%[^\n]%*c%[^\n]%*c%[^\n]%*c%[^\n]",detail.phone,detail.mobile,detail.nationality,detail.merital_status,detail.email);
            printf("==========================================================================\n\n");
            printf("Balance : %s T.K\n\n",detail.balance);
            printf("==========================================================================\n\n\n");
            fclose(data);
        }
    }
}
///This is for update balance........
void update(struct account detail)
{
    system("cls");
    printf("\n\t\t================================\n\t\t\tUPDATE ACCOUNT\n\t\t================================\n\n");
    int n,n1;

    printf("To exit enter blank space in the ID input\n");
    printf("Enter Account ID:");
    scanf("%*c%[^\n]",file_name);
    c = file_name[0];
        test_back(c);
    strcat(file_name,".txt");

    while(n != 0)
    {
        if((data = fopen(file_name,"r")) == NULL)
        {
            system("cls");
            printf("\n\t\t\t\t>>>> Wrong ID! <<<<<\n\n");
            test();
            break;
        }
        else
        {
            fscanf(data,"%[^\n]",detail.pasword);
            fscanf(data,"%*c%[^\n]",detail.name);
            fscanf(data,"%*c%[^\n]",detail.father);
            fscanf(data,"%*c%[^\n]",detail.mother);
            fscanf(data,"%*c%[^\n]",detail.balance);
            fscanf(data,"%*c%[^\n]",detail.birthday);
            fscanf(data,"%*c%[^\n]",detail.pre_address);
            fscanf(data,"%*c%[^\n]",detail.permanent_add);
            fscanf(data,"%*c%[^\n]",detail.phone);
            fscanf(data,"%*c%[^\n]",detail.mobile);
            fscanf(data,"%*c%[^\n]",detail.nationality);
            fscanf(data,"%*c%[^\n]",detail.merital_status);
            fscanf(data,"%*c%[^\n]",detail.email);
            data1 = fopen(file_name,"w");

            printf("\n\n\n\t\t\tSUB MANU\n\t\t=====================\n\t\t");
            printf("[1] Update Balance\n\t\t");
            printf("[2] Update Present Address\n\t\t");
            printf("[3] update Mobile number\n\t\t");
            printf("[4] Update Merital status\n\t\t");
            printf("[5] Update password\n\t\t");
            printf("[0] Save Update\n\t\t");
            printf("=================\n\t\t");
            printf("Enter choice:");
            scanf("%d",&n);

            if(n == 1)
            {
                system("cls");
                printf("\n\t\t================================\n\t\t\tUPDATE BALANCE\n\t\t================================\n\n");
                printf("Enter new balance:");
                scanf("%s",detail.balance);
                system("cls");
                printf("\n\t\t\tUpdate successfully\n");
                test();
                write();
            }
            else if(n == 2)
            {
                system("cls");
                printf("\n\t\t================================\n\t\t\tUPDATE PRESENT ADDRESS\n\t\t================================\n\n");
                printf("Enter new Address:");
                scanf("%*c%[^\n]",detail.pre_address);
                system("cls");
                printf("\n\t\t\tUpdate successfully\n");
                test();
                write();
            }
            else if(n == 3)
            {
                system("cls");
                printf("\n\t\t================================\n\t\t\tUPDATE MOBILE NUMBER\n\t\t================================\n\n");
                printf("Enter new mobile number:");
                scanf("%*c%[^\n]",detail.mobile);
                system("cls");
                printf("\n\t\t\tUpdate successfully\n");
                test();
                write();
            }
            else if(n == 4)
            {
                system("cls");
                printf("\n\t\t================================\n\t\t\tUPDATE MERITAL STATUS\n\t\t================================\n\n");
                printf("Enter new merital status:");
                scanf("%*c%[^\n]",detail.merital_status);
                system("cls");
                printf("\n\t\t\tUpdate successfully\n");
                test();
                write();
            }
            else if(n == 5)
            {
                system("cls");
                printf("\n\t\t================================\n\t\t\tUPDATE PASSWORD\n\t\t================================\n\n");
                printf("Enter new posword:");
                scanf("%*c%[^\n]",detail.pasword);
                system("cls");
                printf("\n\t\t\tUpdate successfully\n");
                test();
                write();
            }
            else if(n == 0)
            {
                system("cls");
            }
            else
            {
                printf("\t\t\tWrong input!\n\t\t\tOnly 0-5 is parmitted\n");
            }

            fprintf(data1,"%s\n",detail.pasword);
            fprintf(data1,"%s\n",detail.name);
            fprintf(data1,"%s\n",detail.father);
            fprintf(data1,"%s\n",detail.mother);
            fprintf(data1,"%s\n",detail.balance);
            fprintf(data1,"%s\n",detail.birthday);
            fprintf(data1,"%s\n",detail.pre_address);
            fprintf(data1,"%s\n",detail.permanent_add);
            fprintf(data1,"%s\n",detail.phone);
            fprintf(data1,"%s\n",detail.mobile);
            fprintf(data1,"%s\n",detail.nationality);
            fprintf(data1,"%s\n",detail.merital_status);
            fprintf(data1,"%s\n",detail.email);
            fclose(data1);
            fclose(data);
        }
    }

}
void write()
{
    printf("\n\t\t================================\n\t\t\tUPDATE ACCOUNT\n\t\t================================\n\n");
}
char test_back(char x)
{
    int n;
    if(isspace(x))
    {
        printf("\n\n....:: Enter choice:\n");
        printf("\n\t\t[1] Main Manu\t\t[0] Exit\n");
        scanf("%d",&n);
        if(n==1)
        {
            system("cls");
            main();
        }
        else if(n==0)
        {
            system("cls");
            printf("THANKS FOR USING...\n");
            printf("                   ...ZOBAED HOSSEN RAJ\n");
            exit(1);
        }
    }
}
void test()
{
    int n1;
    while(1)
    {
        printf("....::Enter choice:\n");
        printf("\t\t\t\t[0] BACK\n");
        scanf("%d",&n1);
        if(n1 == 0)
        {
            system("cls");
            break;
        }
    }
}

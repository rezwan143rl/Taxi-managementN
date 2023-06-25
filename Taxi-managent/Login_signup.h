#define MAX_USER 15
typedef struct
{
    int i;
    char first_name[20];
    char last_name[20];
    char username[30];
    char phn_no[15];
    char pass[15];
} user;

void Admin_login(void)
{
    FILE* Admin;
    user admn;
    char admin_user[30];
    char admin_pass[15];
    Admin = fopen("admpass.txt","r");
    if (Admin == NULL)
    {
        printf("Error opening file.\n");

        //return 1;
    }
    else
        fscanf(Admin,"%s\t%s",admn.username,admn.pass);

      printf("\n");
    printf("Enter your user name:\n");
    scanf("%s",admin_user);
    printf("Enter your password:\n");
    scanf("%s",admin_pass);


    if((strcmp(admin_user,admn.username)==0) &&(strcmp(admin_pass,admn.pass)==0) )
    {
        printf("Login was successful");
        _sleep(3000);
        system("cls");
        int select1;
        printf("choose what you want to do->\n1.customer sign up\n2.change signup data\n3.add car\n4.show list of cars\n");
        scanf("%d",&select1);
        if(select1==1)signup();
        else if(select1==2)change_data();
        else if(select1==3)add();
        else if(select1==4)list();
        else
        {
            printf("error!!!");
            _sleep(3000);
            //return 1;
        }
     system("cls");
    }
     fclose(Admin);
}



void change_data(void)
{
    change_datat();
    FILE* userd;
    user u_data[MAX_USER];
    int record;
    printf("Enter index you want to change-->");
    scanf("%d",&record);
    record--;
    printf("\n");
    do
    {
        printf("Enter your first name-> ");
        scanf("%s",&u_data[record].first_name);

        printf("\nEnter your last name->");
        scanf("%s",&u_data[record].last_name);

        printf("\nEnter your phn no->");
        scanf("%s",&u_data[record].phn_no );

        printf("\nEnter your user name->");
        scanf("%s",&u_data[record].username);

        printf("\nEnter your password->");
        scanf("%s",&u_data[record].pass );

        userd = fopen("passus.txt","a");
        if(userd == 0)
            printf("error!! cannot open file passus.txt\n");
        else
        {

            fprintf(userd,"%s \t %s \t %s \t %s \t %s \n",u_data[record].first_name,u_data[record].last_name,u_data[record].phn_no,u_data[record].username,u_data[record].pass);

        }
        record++;
    }
    while(record<MAX_USER);
    fclose(userd);
    char select3;
    printf("Do you want to change more?(y,n)\n");
    scanf("%c",&select3);
    system("cls");
    if(select3=='y'||select3=='Y')change_data();
    else if(select3=='n'||select3=='N')login_signup();
    system("cls");


}


void signup(void)
{
    signupt();
    FILE* userd;
    user u_data[MAX_USER];
    int record=0;
    do
    {
        printf("Enter your first name-> ");
        scanf("%s",&u_data[record].first_name);

        printf("\nEnter your last name->");
        scanf("%s",&u_data[record].last_name);

        printf("\nEnter your phn no->");
        scanf("%s",&u_data[record].phn_no );

        printf("\nEnter your user name->");
        scanf("%s",&u_data[record].username);

        printf("\nEnter your password->");
        scanf("%s",&u_data[record].pass );
        printf("\n");
        userd = fopen("passus.txt","a");
        if(userd == 0)
            printf("error!! cannot open file passus.txt\n");
        else
        {

            fprintf(userd,"%s \t %s \t %s \t %s \t %s \n",u_data[record].first_name,u_data[record].last_name,u_data[record].phn_no,u_data[record].username,u_data[record].pass);

        }
        record++;
        system("cls");

    }
    while(record<MAX_USER);
    fclose(userd);
    system("cls");


}

void login(void)
{
    label:
    logint();
    user u_data[50];
    char useri[30], passi[15];

    FILE* userd;
    userd = fopen("passus.txt","r");
    if (userd == NULL)
    {
        printf("Error opening file.\n");

        //return 1;
    }


    int read = 0;
    int records=0;

    do
    {

        read =fscanf(userd,"%s \t %s \t %s \t %s \t %s \n",u_data[records].first_name,u_data[records].last_name,u_data[records].phn_no,u_data[records].username,u_data[records].pass);


        if (read == 5) records++;
        if (read != 5 && !feof(userd))
        {
            printf("Fatal error!!! File format incorrect.\n closing the program\n");
            _sleep(4000);
            //return 1;
        }
        if (ferror(userd))
        {
            printf("Error reading file.\n");
            _sleep(4000);
            //return 1;
        }

    }
    while (!feof(userd));





    printf("\n");
    printf("Enter your user name:\n");
    scanf("%s",useri);
    printf("Enter your password:\n");
    scanf("%s",passi);
    int stamp =0;
    for(int i =0; i<MAX_USER; i++)
    {
        if((strcmp(useri,u_data[i].username)==0) &&(strcmp(passi,u_data[i].pass)==0) )stamp=1;
    }

    if(stamp==1)
    {
        printf("login successfull \n wait for few seconds\n");
        _sleep(2000);

    }
    else if(stamp==0)
    {
        printf("the login was unsucessful. try again \n ");

        _sleep(2000);
        system("cls");

        goto label;

    }



    fclose(userd);
    int select4;
    printf("choose->\n1.list\n");
    scanf("%d",&select4);
    if(select4==1)list();

}


void login_signup(void)
{
label:
    car();
    int select;
    printf("Please select one:\n1.admin_login\n2.Customer_login\n");
    scanf("%d",&select);
    system("cls");
    if(select==1)
        {
        Admin_login();
        goto label;
        }
    else if(select==2)
    {
        system("cls");
        login();
        system("cls");

    }
    else
    {
        printf("wrong input. try again in few seconds\n");
        _sleep(2000);
        system("cls");
        goto label;
    }

    system("cls");

}





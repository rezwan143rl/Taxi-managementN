#ifndef ADD_H_INCLUDED
#define ADD_H_INCLUDED
struct car_details //STRUCTURE DECLARATION
{
   char vehicle_name[20];
       char vehicle_model[20];
       char year[20];
       char cost[20];
} s;
void add()
{
    FILE *f;
    char test;
    f = fopen("data.txt", "ab+");
    if (f == 0)
    {
        f = fopen("data.txt", "wb+");
        system("cls");
        printf("Please hold on while we configure your computer");
        printf("/npress any key to continue");
        getch();
    }
    while (1)
    {
        system("cls");
        printf("\n Enter Car Details:");
        printf("\n**************************");
        printf("\n Enter car name:\n");
        scanf("%s", s.vehicle_name);
        fflush(stdin);
        printf("Enter Vehicle_model:\n");
        scanf("%s", s.vehicle_model);
        printf("Enter year:\n");
        scanf("%s", s.year);
        printf("Enter per hour cost:\n");
        scanf("%s", s.cost);
        fflush(stdin);

        fwrite(&s, sizeof(s), 1, f);
        fflush(stdin);
        printf("\n\n1 car has been added!");
        printf("\n Press esc key to exit,  any other key to add another customer detail:");

        test = getch();
        if (test == 27)
            break;
        system("cls");
    }
    fclose(f);
}

#endif // ADD_H_INCLUDED
void exitProgram() {
    char confirm;

    system("cls");
    printf("\n\n\t Are you sure you want to exit? (Y/N): ");
    confirm = getche();

    if (confirm == 'Y' || confirm == 'y') {
        printf("\n\n\t Thank you for using our program!");
        getch();
        login(); // Return to login screen
    } else if (confirm == 'N' || confirm == 'n') {
        return; // Recursive call to main menu
    } else {
        printf("\n\n\t Invalid input! Please try again.");
        getch();
        exitProgram(); // Recursive call to exit function
    }
}

void menu()
{
    int i = 0;

    time_t t;
    time(&t);
    char customername;
    char choice;
    for (i = 0; i < 80; i++)
        printf("-");
    printf("\nCurrent date and time: %s", ctime(&t));
    for (i = 0; i < 80; i++)
        printf("-");
    sleep(10);
    login();
    system("cls");
    while (1)
    {
        system("cls");

        for (i = 0; i < 80; i++)
            printf("-");
        printf("\n");
        printf("  ******************************  |MAIN MENU|  ***************************** \n");
        for (i = 0; i < 80; i++)
            printf("-");
        printf("\n");
        printf("\t\t *Please enter your choice for menu*:");
        printf("\n\n");
        printf(" \n Enter 1 -> Book a car");
        printf("\n------------------------");

        printf("\n------------------------");
        printf(" \n Enter 2 -> Exit");
        printf("\n");
        for (i = 0; i < 80; i++)
            printf("-");

	    for(i=0;i<80;i++)
		printf("-");

		choice=getche();
		choice=toupper(choice);


        switch (choice)
        {
        case '1':
            add();


            break;
        case '2':
                exitProgram(); // Recursive function call
                break;
            default:
                printf("\n\n\t Invalid choice! Please try again.");
                getch();
        }
    }


}



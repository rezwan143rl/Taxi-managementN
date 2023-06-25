#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

void list()
{
    FILE *f;
    int i;
    if ((f = fopen("data.txt", "rb")) == NULL)
        exit(0);
    system("cls");
    printf("Name\t");
    printf("model\t ");
    printf("Year\t ");
    printf("\tcost\t ");

     printf("\n");
    for (i = 0; i < 60; i++)
        printf("-");
    printf("\n");

    while (fread(&s, sizeof(s), 1, f) == 1)
    {
        printf("\n%s", s.vehicle_name);
        printf("\t");
        printf("%s", s.vehicle_model);
        printf("\t ");
        printf("%s", s.year);
        printf("\t\t");
        printf("%s", s.cost);
        printf("\t ");

    }
    fclose(f);
    getch();
}

#endif // LIST_H_INCLUDED


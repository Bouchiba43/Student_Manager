#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct
{
    int id;
    char fullname[50];
    int level;
    float average;

} student;
float average, testlevel;
int i = 0, n = 0, choice, h;
student t[100], aux;
char res[10];


int verif_level(int value) {
    return value >= 1 && value <= 5;
}
int verif_grade(float value) {
    return value >= 0 && value <= 20;
}
int exist_id(student t[100], int n, int value) {
    int s = 1;
    for (int i = 0; i < n; i++)
    {
        if (t[i].id == value)
        {
            s = 0;
        }
    }
    return s;
}
int exist_level(student t[100], int n, int value) {
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i].level == value)
        {
            s = 1;
        }
    }
    return s;
}
int integer_part(float value) {
    int res;
    res = value / 1;
    return res;
}
void add(student t[100])
{
    char bluff;
    printf("\nplease enter\n\n");
    printf("the id:");
    scanf_s("%d", &t[i].id, sizeof(t[i].id));
    while (!exist_id(t, n, t[i].id))
    {
        printf("this id exist.give another id:");
        scanf_s("%d", &t[i].id,sizeof(t[i].id));
        exist_id(t, n, t[i].id);
    }

    printf("full name:");
    scanf_s("%c", &bluff , sizeof(bluff));
    scanf_s("%[^\n]", t[i].fullname,sizeof(t[i].fullname));
    printf("study level:");
    scanf_s("%d", &t[i].level, sizeof(t[i].level));


    while ((!verif_level(t[i].level)))
    {
        printf("Level not valid.Please enter the level:");
        scanf_s("%d", &t[i].level,sizeof(t[i].level));
        verif_level(t[i].level);

    }
    printf("grade:");
    scanf_s("%f", &t[i].average, sizeof(t[i].average));
    while (!verif_grade(t[i].average))
    {
        printf("Grade not valid.Please enter the grade:");
        scanf_s("%f", &t[i].average, sizeof(t[i].average));
        verif_grade(t[i].average);

    }
    i++;
    printf("the student is added successfully");
}
void delete(student t[100], int n) {
    int delete, position;
    printf("Please enter the ID of the student to be deleted:");
    scanf_s("%d", &delete, sizeof(delete));
    while (exist_id(t, n, delete) == 1)
    {
        printf("this id doesn't exist.Give a valid ID:");
        scanf_s("%d", &delete , sizeof(delete));
        exist_id(t, n, delete);
    }
    for (int i = 0; i < n; i++)
    {
        if (delete == t[i].id)
        {
            position = i;
            break;
        }
    }
    for (int i = position; i < n; i++)
    {
        t[i].id = t[i + 1].id;
        t[i].level = t[i + 1].level;
        strcpy(t[i].fullname, t[i + 1].fullname);
        t[i].average = t[i + 1].average;
    }
    printf("the student is deleted successfully");
    i--;
}
void update(student t[100], int n) {
    int id;
    char bluff;
    printf("give the id to update the student:");
    scanf_s("%d", &id, sizeof(id));
    while (exist_id(t, n, id) == 1)
    {
        printf("this id doesn't exist.Give a valid ID:");
        scanf_s("%d", &id , sizeof(id));
        exist_id(t, n, id);
    }
    for (int i = 0; i < n; i++)
    {
        if (id == t[i].id)
        {
            printf("fullname:");
            scanf_s("%c", &bluff , sizeof(bluff));
            scanf_s("%[^\n]", t[i].fullname , sizeof(t[i].fullname));
            printf("study level:");
            scanf_s("%d", &t[i].level, sizeof(t[i].level));
            while (!verif_level(t[i].level))
            {
                printf("Level not valid.Please enter the level:");
                scanf_s("%d", &t[i].level, sizeof(t[i].level));
                verif_level(t[i].level);

            }
            printf("grade:");
            scanf_s("%f", &t[i].average, sizeof(average));
            while (!verif_grade(t[i].average))
            {
                printf("Grade not valid.Please enter the grade:");
                scanf_s("%f", &t[i].average , sizeof(average));
                verif_grade(t[i].average);

            }
        }

    }
    printf("the student is updated successfully");
}
void displaylist(student t[100], int n)
{
    printf("id\tfullname\t\tlevel\tgrade\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t%d\t%f\n", t[i].id, t[i].fullname, t[i].level, t[i].average);
    }
    printf("\n");
}
float calculateAverageByNv(student t[100], int n) {
    float a, s = 0, b = 0;
    int level;
    printf("give the level to calculate the everage:");
    scanf_s("%d", &level, sizeof(level));
    for (int i = 0; i < n; i++)
    {
        if (level == t[i].level)
        {
            s += t[i].average;
            b++;
        }
    }
    a = s / b;
    return a;
}
void findByID(student t[100], int n) {
    int id;
    printf("student id to search:");
    scanf_s("%d", &id, sizeof(id));
    while (exist_id(t, n, id) == 1)
    {
        printf("this id doesn't exist.Give a valid ID:");
        scanf_s("%d", &id , sizeof(id));
        exist_id(t, n, id);
    }
    for (int i = 0; i < n; i++)
    {
        if (id == t[i].id)
        {
            printf("\nid\tfullname\tlevel\tgrade\n");
            printf("%d\t%s\t\t%d\t%f\n", t[i].id, t[i].fullname, t[i].level, t[i].average);

        }

    }

}
void findByLevel(student t[100], int n) {

    int level;
    printf("students level to search:");
    scanf_s("%d", &level, sizeof(level));
    while (exist_level(t, n, level) == 0)
    {
        printf("level doesn't exist.Please enter a valid one:");
        scanf_s("%d", &level,sizeof(level));
        exist_level(t, n, level);
    }
    printf("id\tfullname\tlevel\tgrade\n");
    for (int i = 0; i < n; i++)
    {
        if (t[i].level == level)
        {
            printf("%d\t%s\t\t%d\t%f\n", t[i].id, t[i].fullname, t[i].level, t[i].average);
        }

    }


}
void findByAverage(student t[100], int n) {
    float average;
    int average1, s = 0;
    printf("give everage to search:");
    scanf_s("%f", &average,sizeof(average));
    average1 = integer_part(average);
    printf("id\tfullname\tlevel\tgrade\n");
    for (int i = 0; i < n; i++)
    {
        if (integer_part(t[i].average) == average1)
        {
            printf("%d\t%s\t\t%d\t%f\n", t[i].id, t[i].fullname, t[i].level, t[i].average);
            s += 1;
        }

    }
    if (s == 0)
    {
        printf("no one has this everage!");
    }
}
int interface(int choice)
{
    printf("\nPlease specify the operation to be performed\n 0. Exit the application\n 1. Add a student\n 2. Remove a student\n 3. Update a student\n 4. Display the list of students\n 5. Find a student by ID\n 6. Find students by level\n 7. Find students by average\n 8. Calculate the general average by level\n 9. Sort students");
    printf("\n \nyour choice:");
    scanf_s("%d", &choice,sizeof(choice));
    system("cls");
    switch (choice)
    {
    case 1:

        add(t);
        n += 1;
        printf("\n");

        printf("would you like to return to the main menu?[y/n]:");
        scanf_s("%s", res, sizeof(res));

        while (strcmp(res, "y") != 0 && strcmp(res, "n") != 0) {
            printf("Invalid input. Please enter y or n: ");
            scanf_s("%s", res, sizeof(res));
        }

        if (strcmp(res, "y") == 0) {
            system("cls");
            choice = interface(choice);
        }
        else {
            exit(0);
            system("cls");
        }
        break;


    case 2:

        delete(t, n);
        n -= 1;
        printf("\n");
        printf("would you like to return to the main menu?[y/n]:");
        scanf_s("%s", res, sizeof(res));

        while (strcmp(res, "y") != 0 && strcmp(res, "n") != 0) {
            printf("Invalid input. Please enter y or n: ");
            scanf_s("%s", res, sizeof(res));
        }

        if (strcmp(res, "y") == 0) {
            system("cls");
            choice = interface(choice);
        }
        else {
            exit(0);
            system("cls");
        }
        break;

    case 3:

        update(t, n);
        printf("\n");
        printf("would you like to return to the main menu?[y/n]:");
        scanf_s("%s", res, sizeof(res));

        while (strcmp(res, "y") != 0 && strcmp(res, "n") != 0) {
            printf("Invalid input. Please enter y or n: ");
            scanf_s("%s", res, sizeof(res));
        }

        if (strcmp(res, "y") == 0) {
            system("cls");
            choice = interface(choice);
        }
        else {
            system("cls");
            exit(0);
        }
        break;

    case 4:

        displaylist(t, n);
        printf("would you like to return to the main menu?[y/n]:");
        scanf_s("%s", res, sizeof(res));

        while (strcmp(res, "y") != 0 && strcmp(res, "n") != 0) {
            printf("Invalid input. Please enter y or n: ");
            scanf_s("%s", res, sizeof(res));
        }

        if (strcmp(res, "y") == 0) {
            system("cls");
            choice = interface(choice);
        }
        else {
            system("cls");
            exit(0);
        }

        break;
    case 5:

        findByID(t, n);
        printf("would you like to return to the main menu?[y/n]:");
        scanf_s("%s", res, sizeof(res));

        while (strcmp(res, "y") != 0 && strcmp(res, "n") != 0) {
            printf("Invalid input. Please enter y or n: ");
            scanf_s("%s", res, sizeof(res));
        }

        if (strcmp(res, "y") == 0) {
            system("cls");
            choice = interface(choice);
        }
        else {
            system("cls");
            exit(0);
        }

        break;
    case 6:
        findByLevel(t, n);
        printf("would you like to return to the main menu?[y/n]:");
        scanf_s("%s", res, sizeof(res));

        while (strcmp(res, "y") != 0 && strcmp(res, "n") != 0) {
            printf("Invalid input. Please enter y or n: ");
            scanf_s("%s", res, sizeof(res));
        }

        if (strcmp(res, "y") == 0) {
            system("cls");
            choice = interface(choice);
        }
        else {
            system("cls");
            exit(0);
        }

        break;
    case 7:
        findByAverage(t, n);
        printf("would you like to return to the main menu?[y/n]:");
        scanf_s("%s", res, sizeof(res));

        while (strcmp(res, "y") != 0 && strcmp(res, "n") != 0) {
            printf("Invalid input. Please enter y or n: ");
            scanf_s("%s", res, sizeof(res));
        }

        if (strcmp(res, "y") == 0) {
            system("cls");
            choice = interface(choice);
        }
        else {
            system("cls");
            exit(0);
        }

        break;
    case 8:
        average = calculateAverageByNv(t, n);
        printf("the average of the given level: %f", average);
        printf("\n");
        printf("would you like to return to the main menu?[y/n]:");
        scanf_s("%s", res, sizeof(res));

        while (strcmp(res, "y") != 0 && strcmp(res, "n") != 0) {
            printf("Invalid input. Please enter y or n: ");
            scanf_s("%s", res, sizeof(res));
        }

        if (strcmp(res, "y") == 0) {
            system("cls");
            choice = interface(choice);
        }
        else {
            system("cls");
            exit(0);
        }
        break;
    case 9:
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n - 1; i++)
            {
                if (t[i].level > t[i + 1].level)
                {
                    aux.average = t[i].average;
                    aux.level = t[i].level;
                    aux.id = t[i].id;
                    strcpy(aux.fullname, t[i].fullname);
                    t[i].average = t[i + 1].average;
                    t[i].level = t[i + 1].level;
                    t[i].id = t[i + 1].id;
                    strcpy(t[i].fullname, t[i + 1].fullname);
                    t[i + 1].average = aux.average;
                    t[i + 1].level = aux.level;
                    t[i + 1].id = aux.id;
                    strcpy(t[i + 1].fullname, aux.fullname);
                }
            }
        }
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n - 1; i++)
            {
                if ((t[i].level == t[i + 1].level) && (t[i].average < t[i + 1].average))
                {
                    aux.average = t[i].average;
                    aux.level = t[i].level;
                    aux.id = t[i].id;
                    strcpy(aux.fullname, t[i].fullname);
                    t[i].average = t[i + 1].average;
                    t[i].level = t[i + 1].level;
                    t[i].id = t[i + 1].id;
                    strcpy(t[i].fullname, t[i + 1].fullname);
                    t[i + 1].average = aux.average;
                    t[i + 1].level = aux.level;
                    t[i + 1].id = aux.id;
                    strcpy(t[i + 1].fullname, aux.fullname);
                }
            }
        }

        displaylist(t, n);
        printf("would you like to return to the main menu?[y/n]:");
        scanf_s("%s", res, sizeof(res));;

        while (strcmp(res, "y") != 0 && strcmp(res, "n") != 0) {
            printf("Invalid input. Please enter y or n: ");
            scanf_s("%s", res,sizeof(res));
        }

        if (strcmp(res, "y") == 0) {
            system("cls");
            choice = interface(choice);
        }
        else {
            system("cls");
            exit(0);
        }
        break;
    case 0:
        system("cls");
        return 0;
        break;
    default:
        printf("\nInvalid input.Please enter your choice:\n");
        choice = interface(choice);

    }

}
//principal program 
int main()
{
    choice = interface(choice);
}

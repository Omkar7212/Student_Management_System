#include <stdio.h>

struct Student {
    int id;
    char name[50];
    int age;
    char grade[3];
};

void addStudent() {
    struct Student s;
    FILE *fp = fopen("students.txt", "a");
    if (fp == NULL) {
        printf("Cannot open file.\n");
        return;
    }
    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name (no spaces): ");
    scanf("%s", s.name);
    printf("Enter Age: ");
    scanf("%d", &s.age);
    printf("Enter Grade: ");
    scanf("%s", s.grade);

    fprintf(fp, "%d %s %d %s\n", s.id, s.name, s.age, s.grade);
    fclose(fp);
    printf("Student added successfully.\n");
}

void viewStudents() {
    struct Student s;
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }
    printf("ID\tName\tAge\tGrade\n");
    while (fscanf(fp, "%d %s %d %s", &s.id, s.name, &s.age, s.grade) != EOF) {
        printf("%d\t%s\t%d\t%s\n", s.id, s.name, s.age, s.grade);
    }
    fclose(fp);
}

void generateHTMLReport() {
    struct Student s;
    FILE *fp = fopen("students.txt", "r");
    FILE *html = fopen("report.html", "w");
    if (fp == NULL || html == NULL) {
        printf("Error opening files.\n");
        return;
    }

    // HTML head with linked external CSS
    fprintf(html, "<!DOCTYPE html>\n<html>\n<head>\n<title>Student Report</title>\n");
    fprintf(html, "<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\">\n");
    fprintf(html, "</head>\n<body>\n");
    fprintf(html, "<h2>Student Report</h2>\n<table>\n<tr><th>ID</th><th>Name</th><th>Age</th><th>Grade</th></tr>\n");

    while (fscanf(fp, "%d %s %d %s", &s.id, s.name, &s.age, s.grade) != EOF) {
        fprintf(html, "<tr><td>%d</td><td>%s</td><td>%d</td><td>%s</td></tr>\n", s.id, s.name, s.age, s.grade);
    }

    fprintf(html, "</table>\n</body>\n</html>\n");

    fclose(fp);
    fclose(html);
    printf("HTML report generated as report.html\n");
}

int main() {
    int choice;
    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n2. View Students\n3. Generate HTML Report\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            addStudent();
        else if (choice == 2)
            viewStudents();
        else if (choice == 3)
            generateHTMLReport();
        else if (choice == 4)
            printf("Goodbye!\n");
        else
            printf("Invalid choice.\n");
    } while (choice != 4);

    return 0;
}

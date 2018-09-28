#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Students {
    char studentId[6]; // 6 slot, 1 cái cho ký tự xuống dòng.
    char name[50];
    char phoneNumber[50];
} student;

student listOfStudent[10];
int currentIndex = 0;
FILE *fp;


void addStudent() {
    if (currentIndex > 9) {
        return;
    }
    while (strlen(listOfStudent[currentIndex].studentId) != 5) {
        // ít nhấp làm 1 lần trước khi check.
        printf("Vui long nhap vao ma so sinh vien(5 ky tu): \n");
        fgets(listOfStudent[currentIndex].studentId, 6, stdin); // 1 chỗ cho ký tự null.
        if (!strchr(listOfStudent[currentIndex].studentId, '\n')) {
            while (fgetc(stdin) != '\n');
        }
    }
    // remove ký tự xuống dòng trong name.
    char *pos;
    if ((pos=strchr(listOfStudent[currentIndex].studentId, '\n')) != NULL){
        *pos = '\0';
    }
    printf("Vui long nhap vao ten sinh vien: \n");
    fgets(listOfStudent[currentIndex].name, 50, stdin);
    if (!strchr(listOfStudent[currentIndex].name, '\n')) {
        while (fgetc(stdin) != '\n');
    }
    // remove ký tự xuống dòng trong name.
    *pos;
    if ((pos=strchr(listOfStudent[currentIndex].name, '\n')) != NULL){
        *pos = '\0';
    }
    printf("Vui long nhap vao sdt cua sinh vien: \n");
    fgets(listOfStudent[currentIndex].phoneNumber, 50, stdin);
    if (!strchr(listOfStudent[currentIndex].phoneNumber, '\n')) {
        while (fgetc(stdin) != '\n');
    }
    // remove ký tự xuống dòng trong name.
    if ((pos=strchr(listOfStudent[currentIndex].phoneNumber, '\n')) != NULL){
        *pos = '\0';
    }
    printf("student infor:\n");
    printf("Ma: %s\n", listOfStudent[currentIndex].studentId);
    printf("Ten: %s\n", listOfStudent[currentIndex].name);
    printf("Phone: %s\n", listOfStudent[currentIndex].phoneNumber);
    currentIndex++;
}


void showStudentList() {
    printf("%-20s%-5s%-50s%-5s%-50s\n", "Ma sinh vien", "|", "Ten", "|", "So dien thoai");
    for (int i = 0; i < currentIndex; i++) {
        printf("%-20s%-5s%-50s%-5s%-50s\n",
               listOfStudent[i].studentId,
               "|", listOfStudent[i].name,
               "|", listOfStudent[i].phoneNumber);
    }
}

void saveToFile() {

    fp = fopen("List of Students", "a");
    for (int i = 0; i < currentIndex; i++) {
        fprintf(fp, "%-20.5s %-5s %-30s %-5s %-20d\n", listOfStudent[i].studentId, "|", listOfStudent[i].name, "|",
                listOfStudent[i].phoneNumber);
    }


    fclose(fp);
}

void readFromFile() {

    printf("%-20s %-5s %-30s %-5s %-20s\n", "Ma sinh vien", "|", "Ten", "|", "So dien thoai");
    fp = fopen("List of Students", "r");
    int bufferSize = 500;
    char buffer[bufferSize];
    while (fgets(buffer, bufferSize, fp) != NULL) {
        printf("%s", buffer);
    }
    fclose(fp);

}

int main() {
    int choice;

    while (1 == 1) {
        printf("1. Them moi sinh vien.\n");
        printf("2. Hien thi danh sach sinh vien.\n");
        printf("3. Luu danh sach sinh vien ra file.\n");
        printf("4. Doc danh sach sinh vien tu file.\n");
        printf("5. Thoat chuong trinh.\n");

        printf("Hay nhap vao chuc nang ban muon su dung(1-5): ");
        scanf("%d", &choice);
        fgetc(stdin); // loại bỏ ký tự xuống dòng sau scanf.
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                showStudentList();
                break;
            case 3:
                saveToFile();
                break;
            case 4:
                readFromFile();
                break;
            case 5:
                exit(0);
        }
    }
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "crypto.h"

int main() {
    int menu, shift;
    char text[MAX_TEXT];
    char filename[100];

    while (1) 
    {
        printf("\n====== 텍스트 암호화/복호화 프로그램 ======\n");
        printf("1. 암호화\n");
        printf("2. 복호화\n");
        printf("3. 암호화된 텍스트 파일 저장\n");
        printf("4. 파일에서 텍스트 불러오기\n");
        printf("5. 종료\n");
        printf("메뉴 선택: ");
        scanf("%d", &menu);
        getchar();

        if (menu == 5) 
        {
            printf("프로그램 종료!\n");
            break;
        }

        switch (menu) 
        {
        case 1:
            printf("암호화할 텍스트 입력: ");
            fgets(text, MAX_TEXT, stdin);
            text[strcspn(text, "\n")] = '\0';

            printf("shift 값 입력: ");
            scanf("%d", &shift);
            getchar();

            encrypt(text, shift);
            printf("암호화 결과: %s\n", text);
            break;

        case 2:
            printf("복호화할 텍스트 입력: ");
            fgets(text, MAX_TEXT, stdin);
            text[strcspn(text, "\n")] = '\0';

            printf("shift 값 입력: ");
            scanf("%d", &shift);
            getchar();

            decrypt(text, shift);
            printf("복호화 결과: %s\n", text);
            break;

        case 3:
            printf("저장할 파일명 입력: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = '\0';

            printf("저장할 텍스트 입력: ");
            fgets(text, MAX_TEXT, stdin);
            text[strcspn(text, "\n")] = '\0';

            saveToFile(filename, text);
            break;

        case 4:
            printf("불러올 파일명 입력: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strcspn(filename, "\n")] = '\0';

            loadFromFile(filename, text);
            printf("파일 내용: %s\n", text);
            break;

        default:
            printf("잘못된 입력입니다.\n");
        }
    }

    return 0;
}

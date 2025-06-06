#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_WIDTH 10
#define HME_POS 1
#define BWL_PO (ROOM_WIDTH -2)

int main() {

    printf("****�߿��̿� ����****\n");
    printf("         /\\_/\\\n");
    printf("  /\\\    / o o \\\n");
    printf(" //\\\\\   \\~(*)~/\n");
    printf(" `   \\/    ^ /\n");
    printf("     |  \\|| ||\n");
    printf("     \\ ' || ||\n");
    printf("      \\) ()-())\n");

    printf("�߿����� �̸��� �˶��Դϴ�\n");

    Sleep(500); // 2.5�� ���
    system("cls");

    int soup = 0; //������ ����
    int relationship = 2;// ģ�е�
    int cat = 1;// �����
    int dice;//�ֻ���
    int foot; // ���ڱ�
    int choose = 5;
    int cp = 0; // �ڿ� ����Ʈ 
	int mood = 3; // ���

    srand((unsigned int)time(NULL));

    while (1) {

        printf("==================== �������===================\n");
        printf("������� ���� ����: %d��\n", soup);
        printf("CP: %d ����Ʈ\n", cp);
        printf("������� ����(0~4): %d\n", relationship);
        printf("�˶��� ���(0~3): %d\n", mood);

        switch (mood) {
        case 3: printf("������ �θ��ϴ�.\n"); break;
        case 2: printf("����� ���� ���Դϴ�.\n"); break;
        case 1: printf("�ణ �����������ϴ�.\n"); break;
        case 0: printf("ȭ�� ���� �����ϴ�!\n"); break;
        }

        switch (relationship) {
        case 0: printf("�翡 ���� ������ �Ⱦ��մϴ�.\n"); break;
        case 1: printf("���� ���Ǳ� ����Դϴ�.\n"); break;
        case 2: printf("�׷����� �� ���� �����Դϴ�.\n"); break;
        case 3: printf("�Ǹ��� ����� ���� �ް� �ֽ��ϴ�.\n"); break;
        case 4: printf("���� �������Դϴ�.\n"); break;
        }

        printf("================================================\n");

        int mood_before = mood;
        int mood_threshold = 6 - relationship;
        dice = rand() % 6 + 1;
        printf("%d-%d: �ֻ��� ���� %d�����̸� �׳� ����� �������ϴ�.\n", 6, relationship, mood_threshold);
        printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
        printf("%d��(��) ���Խ��ϴ�.\n", dice);
        if (dice <= mood_threshold) {
            if (mood > 0) {
                mood--;
                printf("�˶��� ����� �������ϴ�: %d->%d\n", mood_before, mood);
            }
            else {
                printf("�˶��� ����� �̹� �־��Դϴ�...\n");
            }
        }
        else {
            printf("�˶��� ���� ����� ������ �� �����ϴ�.\n");
        }


        printf("�˶� �̵�: ����� ģ���Ҽ��� ���� ������ �� Ȯ���� �������ϴ�.\n");
        printf("�ֻ��� ���� %d �̻��̸� ���� ������ �̵��մϴ� \n", 6 - relationship);
        printf("�ֻ����� �����ϴ�. �Ǹ���...\n");

        dice = rand() % 6 + 1;
        printf("%d(��)�� ���Խ��ϴ�.\n", dice);

        foot = cat;

        if (dice >= 6 - relationship) {
            if (cat < BWL_PO)
                cat++;
            printf("���� ������ �����Դϴ�.\n");
        }
        else if (cat != HME_POS) {
            cat--;
        }

        if (cat == BWL_PO) {
            soup++;
            dice = rand() % 3 + 1;
            switch (dice) {
            case 1:
                printf("�˶��� ���ڼ����� ��������ϴ�.\n");
                break;
            case 2:
                printf("�˶��� ����̼����� ��������ϴ�.\n");
                break;
            case 3:
                printf("�˶��� ����ݸ������� ��������ϴ�.\n");
                break;
            }
            printf("������� ���� ����: %d\n", soup);
        }
        if (cat == HME_POS) {
            printf("�˶��� �ڽ��� ������ ������� �����ϴ�.\n");
        }


        for (int i = 0; i < ROOM_WIDTH; i++) {
            printf("#");
        }

        printf("\n");

        for (int i = 0; i < ROOM_WIDTH; i++) {
            if (i == 1)
                printf("H");
            else if (i == 0)
                printf("#");
            else if (ROOM_WIDTH - 1 == i)
                printf("#");
            else if (i == BWL_PO)
                printf("B");
            else
                printf(" ");
        }

        printf("\n");

        for (int i = 0; i < ROOM_WIDTH; i++) {
            if (i == 0)
                printf("#");
            else if (ROOM_WIDTH - 1 == i)
                printf("#");
            else if (i == cat)
                printf("C");
            else if (i == foot)
                printf(".");
            else
                printf(" ");
        }

        printf("\n");

        for (int i = 0; i < ROOM_WIDTH; i++) {
            printf("#");
        }

        printf("\n");



        Sleep(500); //0.5�� ���


        printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?    0. �ƹ��͵� ���� ����    1. �ܾ��ֱ�\n>> ");
        scanf_s("%d", &choose);

        while (choose != 0 && choose != 1) {
            printf(">> ");
            scanf_s("%d", &choose);
        }

        switch (choose) {
        case 0:
            printf("�ƹ��͵� ���� ����\n");
            printf("4/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
            printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
            dice = rand() & 6 + 1;
            printf("%d�� ���Խ��ϴ�.\n", dice);
            if (dice <= 4) {
                printf("ģ�е��� �������ϴ�.\n");
                if (relationship > 0) {
                    relationship--;
                }
            }
            else {
                printf("�����̵� ģ�е��� �������� �ʾҽ��ϴ�.\n");
            }
            break;
        case 1:
            printf("�˶��� ���� �ܾ��־����ϴ�.\n");
            printf("2/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
            printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
            dice = rand() % 6 + 1;
            printf("%d�� ���Խ��ϴ�.\n", dice);
            if (dice >= 5) {
                printf("ģ�е��� �������ϴ�\n");
                if (relationship <= 3) {
                    relationship++;
                }
            }
            else {
                printf("ģ�е��� �״���Դϴ�.\n");
            }
            break;
        }
        printf("���� ģ�е� : %d\n", relationship);
        Sleep(2500);
        system("cls");
    }

    return 0;
}
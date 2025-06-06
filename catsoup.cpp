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
    int hasScratcher = 0; //��ũ��ó O
	int hasTower = 0; //Ÿ�� O
	int posScratcher = -1; //��ũ��ó ��ġ
	int posTower = -1; //Ÿ�� ��ġ
    int last_pos = cat;     // �� �� ����� ��ġ
    int was_home = 0;       // ���� �Ͽ��� ���� �־����� ����
	int hasToyMouse = 0; // �峭�� �� 0
	int hasToyLaser = 0; // �峭�� ������ 0

    srand((unsigned int)time(NULL));

    while (1) {
        //����â ���
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
        //��� 
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
        //�̵�
        foot = cat;
        if (mood == 0) {
            if (cat > HME_POS) {
                cat--;
                printf("����� �ſ� ���� �˶��� ������ ���մϴ�.\n");
            }
            else {
                printf("�˶��� �̹� ���� �ֽ��ϴ�.\n");
            }
        }
        else if (mood == 1) {
            if (!hasScratcher && !hasTower) {
                printf("�˶��� �ɽ������� �� �Ÿ��� ��� ����� �ſ� �������ϴ�.\n");
                if (mood > 0) mood--;
            }
            else {
                int distS = hasScratcher ? abs(cat - posScratcher) : ROOM_WIDTH + 1;
                int distT = hasTower ? abs(cat - posTower) : ROOM_WIDTH + 1;
                int target = (distS <= distT) ? posScratcher : posTower;
                if (cat < target) cat++;
                else if (cat > target) cat--;
                printf("�˶��� �ɽ��ؼ� ���̱ⱸ ������ �̵��մϴ�.\n");
            }
        }
        else if (mood == 2) {
            printf("�˶��� ��� ���� �Ļ��� ���� �ֽ��ϴ�.\n");
        }
        else if (mood == 3) {
            if (cat < BWL_PO) {
                cat++;
                printf("�˶��� ������ �θ��� ������ ���鷯 ���ϴ�.\n");
            }


            else {
                printf("�˶��� �̹� ���� �տ� �ֽ��ϴ�.\n");
            }
        }
        //�ൿ
        if (cat == HME_POS) {
            if (was_home) {
                if (mood < 3) {
                    printf("�˶��� ������ �� ���� �������ϴ�. ����� ���� �������ϴ�: %d->%d\n", mood, mood + 1);
                    mood++;
                }
            }
            was_home = 1;
        }
        else {
            was_home = 0;
        }

        if (cat == BWL_PO) {
            soup++;
            dice = rand() % 3 + 1;
            switch (dice) {
            case 1: printf("�˶��� ���ڼ����� ��������ϴ�.\n"); break;
            case 2: printf("�˶��� ����̼����� ��������ϴ�.\n"); break;
            case 3: printf("�˶��� ����ݸ������� ��������ϴ�.\n"); break;
            }
            printf("������� ���� ����: %d\n", soup);
        }

        if (cat == posScratcher) {
            if (mood < 3) {
                printf("�˶��� ��ũ��ó�� �ܰ� ��ҽ��ϴ�.\n");
                printf("����� ���� ���������ϴ�: %d->%d\n", mood, mood + 1);
                mood++;
            }
        }

        if (cat == posTower) {
            if (mood < 3) {
                int before = mood;
                mood += 2;
                if (mood > 3) mood = 3;
                printf("�˶��� ĹŸ���� �پ�ٴմϴ�.\n");
                printf("����� ���� ���������ϴ�: %d->%d\n", before, mood);
            }
        }
        //�� �׸���
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

        while (1) {
            printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?\n");
            printf("0. �ƹ��͵� ���� ����\n");
            printf("1. �ܾ� �ֱ�\n");

            if (hasToyMouse && hasToyLaser) {
                printf("2. �峭�� ��� ��� �ֱ�\n");
                printf("3. ������ �����ͷ� ��� �ֱ�\n");
            }
            else if (hasToyMouse) {
                printf("2. �峭�� ��� ��� �ֱ�\n");
            }
            else if (hasToyLaser) {
                printf("2. ������ �����ͷ� ��� �ֱ�\n");
            }

            printf(">> ");
            scanf_s("%d", &choose);

            if (hasToyMouse && hasToyLaser) {
                if (choose >= 0 && choose <= 3) break;
            }
            else if (hasToyMouse || hasToyLaser) {
                if (choose >= 0 && choose <= 2) break;
            }
            else {
                if (choose == 0 || choose == 1) break;
            }
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է��� �ּ���.\n");
        }

        dice = rand() % 6 + 1;  // 1~6 �ֻ���

        switch (choose) {
        case 0:  // �ƹ��͵� ���� ����
            if (mood > 0) {
                printf("�˶��� ����� ���������ϴ�: %d->%d\n", mood, mood - 1);
                mood--;
            }
            else {
                printf("�˶��� ����� �̹� �־��Դϴ�: %d\n", mood);
            }
            if (dice <= 5) {
                if (relationship > 0) {
                    printf("������� ���谡 �������ϴ�.\n");
                    relationship--;
                }
            }
            break;

        case 1:  // �ܾ� �ֱ�
            printf("�˶��� ����� �״���Դϴ�: %d\n", mood);
            if (dice >= 5) {
                if (relationship < 4) {
                    relationship++;
                    printf("������� ���谡 ���������ϴ�: %d\n", relationship);
                }
            }
            break;

        case 2:  // �峭�� ��� ��� �ֱ� or ������ ������ �� �ϳ�
            if (hasToyMouse && (choose == 2)) {
                printf("�峭�� ��� �˶��� ��� �־����ϴ�. ");
                if (mood < 3) {
                    printf("�˶��� ����� ���� ���������ϴ�: %d->%d\n", mood, mood + 1);
                    mood++;
                }
                else {
                    printf("�˶��� ����� �ְ��Դϴ�: %d\n", mood);
                }
                if (dice >= 4) {
                    if (relationship < 4) {
                        relationship++;
                        printf("������� ���谡 ���������ϴ�: %d\n", relationship);
                    }
                }
            }
            else if (hasToyLaser && ((choose == 2 && !hasToyMouse) || choose == 3)) {
                int oldMood = mood;
                mood += 2;
                if (mood > 3) mood = 3;
                printf("������ �����ͷ� �˶��� �ų��� ��� �־����ϴ�. �˶��� ����� �� ���������ϴ�: %d->%d\n", oldMood, mood);
                if (dice >= 2) {
                    if (relationship < 4) {
                        relationship++;
                        printf("������� ���谡 ���������ϴ�: %d\n", relationship);
                    }
                }
            }
            break;
        }

        Sleep(2500);
        system("cls");
}
    return 0;
}
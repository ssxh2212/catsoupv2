#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_WIDTH 10
#define HME_POS 1
#define BWL_PO (ROOM_WIDTH -2)

int main() {

    printf("****야옹이와 수프****\n");
    printf("         /\\_/\\\n");
    printf("  /\\\    / o o \\\n");
    printf(" //\\\\\   \\~(*)~/\n");
    printf(" `   \\/    ^ /\n");
    printf("     |  \\|| ||\n");
    printf("     \\ ' || ||\n");
    printf("      \\) ()-())\n");

    printf("야옹이의 이름은 쫀떡입니다\n");

    Sleep(500); // 2.5초 대기
    system("cls");

    int soup = 0; //수프의 개수
    int relationship = 2;// 친밀도
    int cat = 1;// 고양이
    int dice;//주사위
    int foot; // 발자국
    int choose = 5;
    int cp = 0; // 자원 포인트 
	int mood = 3; // 기분
    int hasScratcher = 0; //스크래처 O
	int hasTower = 0; //타워 O
	int posScratcher = -1; //스크래처 위치
	int posTower = -1; //타워 위치
    int last_pos = cat;     // 전 턴 고양이 위치
    int was_home = 0;       // 이전 턴에도 집에 있었는지 여부
	int hasToyMouse = 0; // 장난감 쥐 0
	int hasToyLaser = 0; // 장난감 레이저 0

    srand((unsigned int)time(NULL));

    while (1) {
        //상태창 출력
        printf("==================== 현재상태===================\n");
        printf("현재까지 만든 수프: %d개\n", soup);
        printf("CP: %d 포인트\n", cp);
        printf("집사와의 관계(0~4): %d\n", relationship);
        printf("쫀떡이 기분(0~3): %d\n", mood);

        switch (mood) {
        case 3: printf("골골송을 부릅니다.\n"); break;
        case 2: printf("기분이 좋아 보입니다.\n"); break;
        case 1: printf("약간 예민해졌습니다.\n"); break;
        case 0: printf("화가 많이 났습니다!\n"); break;
        }

        switch (relationship) {
        case 0: printf("곁에 오는 것조차 싫어합니다.\n"); break;
        case 1: printf("간식 자판기 취급입니다.\n"); break;
        case 2: printf("그럭저럭 쓸 만한 집사입니다.\n"); break;
        case 3: printf("훌륭한 집사로 인정 받고 있습니다.\n"); break;
        case 4: printf("집사 껌딱지입니다.\n"); break;
        }

        printf("================================================\n");
        //기분 
        int mood_before = mood;
        int mood_threshold = 6 - relationship;
        dice = rand() % 6 + 1;
        printf("%d-%d: 주사위 눈이 %d이하이면 그냥 기분이 나빠집니다.\n", 6, relationship, mood_threshold);
        printf("주사위를 굴립니다. 또르르...\n");
        printf("%d이(가) 나왔습니다.\n", dice);
        if (dice <= mood_threshold) {
            if (mood > 0) {
                mood--;
                printf("쫀떡의 기분이 나빠집니다: %d->%d\n", mood_before, mood);
            }
            else {
                printf("쫀떡의 기분은 이미 최악입니다...\n");
            }
        }
        else {
            printf("쫀떡은 아직 기분이 괜찮은 것 같습니다.\n");
        }


        printf("쫀떡 이동: 집사와 친밀할수록 냄비 쪽으로 갈 확률이 높아집니다.\n");
        printf("주사위 눈이 %d 이상이면 냄비 쪽으로 이동합니다 \n", 6 - relationship);
        printf("주사위를 굴립니다. 또르륵...\n");

        dice = rand() % 6 + 1;
        printf("%d(이)가 나왔습니다.\n", dice);
        //이동
        foot = cat;
        if (mood == 0) {
            if (cat > HME_POS) {
                cat--;
                printf("기분이 매우 나쁜 쫀떡은 집으로 향합니다.\n");
            }
            else {
                printf("쫀떡은 이미 집에 있습니다.\n");
            }
        }
        else if (mood == 1) {
            if (!hasScratcher && !hasTower) {
                printf("쫀떡은 심심하지만 놀 거리가 없어서 기분이 매우 나빠집니다.\n");
                if (mood > 0) mood--;
            }
            else {
                int distS = hasScratcher ? abs(cat - posScratcher) : ROOM_WIDTH + 1;
                int distT = hasTower ? abs(cat - posTower) : ROOM_WIDTH + 1;
                int target = (distS <= distT) ? posScratcher : posTower;
                if (cat < target) cat++;
                else if (cat > target) cat--;
                printf("쫀떡은 심심해서 놀이기구 쪽으로 이동합니다.\n");
            }
        }
        else if (mood == 2) {
            printf("쫀떡은 기분 좋게 식빵을 굽고 있습니다.\n");
        }
        else if (mood == 3) {
            if (cat < BWL_PO) {
                cat++;
                printf("쫀떡은 골골송을 부르며 수프를 만들러 갑니다.\n");
            }


            else {
                printf("쫀떡은 이미 냄비 앞에 있습니다.\n");
            }
        }
        //행동
        if (cat == HME_POS) {
            if (was_home) {
                if (mood < 3) {
                    printf("쫀떡은 집에서 한 턴을 쉬었습니다. 기분이 조금 나아집니다: %d->%d\n", mood, mood + 1);
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
            case 1: printf("쫀떡이 감자수프를 만들었습니다.\n"); break;
            case 2: printf("쫀떡이 양송이수프를 만들었습니다.\n"); break;
            case 3: printf("쫀떡이 브로콜리수프를 만들었습니다.\n"); break;
            }
            printf("현재까지 만든 수프: %d\n", soup);
        }

        if (cat == posScratcher) {
            if (mood < 3) {
                printf("쫀떡은 스크래처를 긁고 놀았습니다.\n");
                printf("기분이 조금 좋아졌습니다: %d->%d\n", mood, mood + 1);
                mood++;
            }
        }

        if (cat == posTower) {
            if (mood < 3) {
                int before = mood;
                mood += 2;
                if (mood > 3) mood = 3;
                printf("쫀떡은 캣타워를 뛰어다닙니다.\n");
                printf("기분이 제법 좋아졌습니다: %d->%d\n", before, mood);
            }
        }
        //방 그리기
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



        Sleep(500); //0.5초 대기

        while (1) {
            printf("어떤 상호작용을 하시겠습니까?\n");
            printf("0. 아무것도 하지 않음\n");
            printf("1. 긁어 주기\n");

            if (hasToyMouse && hasToyLaser) {
                printf("2. 장난감 쥐로 놀아 주기\n");
                printf("3. 레이저 포인터로 놀아 주기\n");
            }
            else if (hasToyMouse) {
                printf("2. 장난감 쥐로 놀아 주기\n");
            }
            else if (hasToyLaser) {
                printf("2. 레이저 포인터로 놀아 주기\n");
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
            printf("잘못된 입력입니다. 다시 입력해 주세요.\n");
        }

        dice = rand() % 6 + 1;  // 1~6 주사위

        switch (choose) {
        case 0:  // 아무것도 하지 않음
            if (mood > 0) {
                printf("쫀떡의 기분이 나빠졌습니다: %d->%d\n", mood, mood - 1);
                mood--;
            }
            else {
                printf("쫀떡의 기분은 이미 최악입니다: %d\n", mood);
            }
            if (dice <= 5) {
                if (relationship > 0) {
                    printf("집사와의 관계가 나빠집니다.\n");
                    relationship--;
                }
            }
            break;

        case 1:  // 긁어 주기
            printf("쫀떡의 기분은 그대로입니다: %d\n", mood);
            if (dice >= 5) {
                if (relationship < 4) {
                    relationship++;
                    printf("집사와의 관계가 좋아졌습니다: %d\n", relationship);
                }
            }
            break;

        case 2:  // 장난감 쥐로 놀아 주기 or 레이저 포인터 중 하나
            if (hasToyMouse && (choose == 2)) {
                printf("장난감 쥐로 쫀떡과 놀아 주었습니다. ");
                if (mood < 3) {
                    printf("쫀떡의 기분이 조금 좋아졌습니다: %d->%d\n", mood, mood + 1);
                    mood++;
                }
                else {
                    printf("쫀떡의 기분은 최고입니다: %d\n", mood);
                }
                if (dice >= 4) {
                    if (relationship < 4) {
                        relationship++;
                        printf("집사와의 관계가 좋아졌습니다: %d\n", relationship);
                    }
                }
            }
            else if (hasToyLaser && ((choose == 2 && !hasToyMouse) || choose == 3)) {
                int oldMood = mood;
                mood += 2;
                if (mood > 3) mood = 3;
                printf("레이저 포인터로 쫀떡과 신나게 놀아 주었습니다. 쫀떡의 기분이 꽤 좋아졌습니다: %d->%d\n", oldMood, mood);
                if (dice >= 2) {
                    if (relationship < 4) {
                        relationship++;
                        printf("집사와의 관계가 좋아졌습니다: %d\n", relationship);
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
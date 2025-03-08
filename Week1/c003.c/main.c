/*
Programming Studio C003
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findRoom(int persons[5]); 
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc);

int main(){
    char mnames[10][20]; // 남학생명단(최대 10명)
    int mroom[10];       // 남학생명단별 호실 배정 목록
    char wnames[10][20]; // 여학생명단(최대 10명)
    int wroom[10];       // 여학생명단별 호실 배정 목록
    int person[2][5] = {0}; // 2개 층(남학생 1층, 여학생 2층)의 5개 호실의 배정 인원 수 
    int mcount = 0, wcount = 0; // 인원 합계 (남, 여)
    int menu;

    srand(time(0));
    printf("===========================================\n");
    printf("생활관 호실 배정 프로그램\n");
    printf("===========================================\n");

    while (1) {
        printf("메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ");
        scanf("%d", &menu);

        if (menu == 0) break;
        else if (menu == 1) { 
            if (mcount >= 10) {
                printf("정원 초과입니다. 등록불가!\n");
                continue;
            }
            printf("학생 이름은? > ");
            scanf("%s", mnames[mcount]);
            int roomno = findRoom(person[0]); 
            if (roomno == -1) { 
                printf("모든 남학생 방이 꽉 찼습니다. 배정할 수 없습니다.\n");
                continue;
            }
            mroom[mcount] = 100 + roomno;
            printf("%s 학생 %d호실 배정되었습니다.\n", mnames[mcount], mroom[mcount]);
            mcount++;
        }
        else if (menu == 2) {
            if (wcount >= 10) {
                printf("정원 초과입니다. 등록불가!\n");
                continue;
            }
            printf("학생 이름은? > ");
            scanf("%s", wnames[wcount]);
            int roomno = findRoom(person[1]); 
            if (roomno == -1) { 
                printf("모든 여학생 방이 꽉 찼습니다. 배정할 수 없습니다.\n");
                continue;
            }
            wroom[wcount] = 200 + roomno;
            printf("%s 학생 %d호실 배정되었습니다.\n", wnames[wcount], wroom[wcount]);
            wcount++;
        }
    }

    printf("===========================================\n");
    printf("생활관 호실 배정 결과는 다음과 같습니다.\n");
    printf("===========================================\n");
    printReport(mnames, mroom, mcount, wnames, wroom, wcount);

    return 0;
}

// 5개 호실 중 빈 베드가 있는 방을 랜덤으로 찾아 반환하는 함수
int findRoom(int persons[5]){
    int room;
    while (1) {  
        room = rand() % 5;  // 0~4 범위에서 랜덤 값 선택
        if (persons[room] < 2) { // 빈 자리가 있는 경우만 선택
            persons[room]++;  // 해당 호실 인원 증가
            return room + 1; // 1부터 5까지의 호실번호 반환
        }
        // 모든 호실이 꽉 찼다면 -1 반환
        int full = 1;
        for (int i = 0; i < 5; i++) {
            if (persons[i] < 2) {
                full = 0;
                break;
            }
        }
        if (full) return -1;
    }
}

// 생활관 배정 결과를 출력하는 함수
void printReport(char mn[10][20], int mr[10], int mc, char wn[10][20], int wr[10], int wc) {
    printf("남학생 명단 (총 %d명)\n", mc);
    for (int i = 0; i < mc; i++) {
        printf("%d. %s [%d호]\n", i + 1, mn[i], mr[i]);
    }

    printf("\n여학생 명단 (총 %d명)\n", wc);
    for (int i = 0; i < wc; i++) {
        printf("%d. %s [%d호]\n", i + 1, wn[i], wr[i]);
    }

    // 호실별 배정 명단 정리
    char male_rooms[5][50] = {""}; // 남학생 호실 (101~105호)
    char female_rooms[5][50] = {""}; // 여학생 호실 (201~205호)

    for (int i = 0; i < mc; i++) {
        sprintf(male_rooms[(mr[i] % 100) - 1], "%s%s ", male_rooms[(mr[i] % 100) - 1], mn[i]);
    }
    for (int i = 0; i < wc; i++) {
        sprintf(female_rooms[(wr[i] % 100) - 1], "%s%s ", female_rooms[(wr[i] % 100) - 1], wn[i]);
    }

    // 호실별 배정 결과 출력
    printf("\n호실별 배정 명단\n");
    for (int i = 0; i < 5; i++) {
        printf("10%d호: %s\n", i + 1, male_rooms[i]);  // 남학생 호실
    }
    for (int i = 0; i < 5; i++) {
        printf("20%d호: %s\n", i + 1, female_rooms[i]);  // 여학생 호실
    }
}
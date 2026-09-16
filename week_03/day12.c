#include "day12_lib.h"
/* 
	   방향	      단위			 개행	          안전성
puts	출력	문자열 1개		자동 추가	       안전
printf	출력	서식 자유		\n 직접	      서식 문자열만 조심
gets	입력	한 줄			 제거함	           위험, 삭제됨
fgets	입력	한 줄			남김	           안전
scanf	입력	서식/토큰     버퍼에 남김	  %19s 등 폭 지정 필요

puts

문자열 하나만 출력하고 개행을 자동으로 붙입니다
서식 해석을 안 하므로 빠릅니다
%가 들어있어도 그냥 문자로 출력

printf

개행이 필요하면 \n을 직접 넣어야 합니다
숫자, 여러 값, 자릿수 지정(%.2f, %-10s) 전부 가능

gets

한 줄 전체를 읽습니다 (공백 포함)
개행을 읽고 버린 뒤 그 자리에 널 문자를 넣습니다
버퍼 크기를 지정할 방법이 없습니다 → C11에서 표준에서 삭제됐습니다. 실무에선 절대 쓰지 않습니다

scanf("%s", ...)

공백/탭/개행 전까지만 읽습니다. 한 줄이 아니라 토큰 하나
앞쪽 공백은 알아서 건너뜁니다
%19s로 길이 제한을 걸 수 있습니다

홍길동 20을 입력했을 때:

결과
gets(s)			"홍길동 20" (통째로)
scanf("%s", s)	"홍길동" (공백에서 끊김)

*/
#if 0


#define size_ary(x) (sizeof(x) / sizeof((x)[0]))

struct student {
	int   id;
	int* scores;      
	char  name[20];
};


struct student* input_data3(int arrSize, int itemCnt) {

	struct student* stu = malloc(arrSize * sizeof(*stu));
	if (stu == NULL) exit(0);

	for (int i = 0; i < arrSize; ++i) {
		stu[i].scores = malloc(itemCnt * sizeof(*stu[i].scores));
		
		for (int j = 0; j < itemCnt; ++j)
			scanf("%d", &stu[i].scores[j]); 
		scanf("%19s", stu[i].name);
	}
	return stu;


}

void print_data3(const struct student* stu, int arrSize, int itemCnt) {
	for (int i = 0; i < arrSize; ++i) {
		printf("%d", stu[i].id);
		for (int j = 0; j < itemCnt; ++j)
			printf(" %d", stu[i].scores[j]);
		printf(" %s\n", stu[i].name);
	}
}


void free_data(struct student** p, int arrSize) {

	for (int i = 0; i < arrSize; ++i)
		free((*p)[i].scores);

	free(*p);
	*p = NULL;              /* 호출한 쪽의 stu까지 NULL로 — dangling 방지 */
}

int main(void) {
	int arrSize, itemCnt;
	struct student* stu = { 0 };

	(void)freopen("student.txt", "r", stdin);
	(void)scanf("%d %d", &arrSize, &itemCnt);

	stu = input_data3(arrSize, itemCnt);
	if (stu != NULL) {
		print_data3(stu, arrSize, itemCnt);
		free_data(&stu, arrSize);
	}
	return 0;
}
#endif
#if 0
struct student {
	int id;
	int *scores;
	char name[20];
};
int input_data3(struct student a[], int b) {
	for (int i = 0; i < b; ++i) {
		(void)scanf("%d", &a[i].id);

		for (int j = 0; j < 3; ++j) {
			(void)scanf("%d", &a[i].scores[j]);
		}
		(void)scanf("%s", a[i].name);

	}
	return 0;
}
int print_data3(struct student a[], int b) {
	for (int i = 0; i < b; ++i) {
		printf("%d", a[i].id);

		for (int j = 0; j < 3; ++j) {
			printf(" %d", a[i].scores[j]);
		}
		printf(" %s\n", a[i].name);

	}
	return 0;
}
int free_data() {

}


int main(void) {
	struct student *stu = { 0 };
	int arrSize, itemCnt;
	(void)freopen("student.txt", "r", stdin);
	(void)scanf("%d %d", &arrSize, &itemCnt);
	input_data3(stu, SIZE(stu));
	print_data3(stu, SIZE(stu));

	if (stu != NULL) {
		print_data3(stu,arrSize, itemCnt);
		free_data(&stu, itemCnt);
	}

	return 0;
}
#endif
#if 0
struct student {
	int id;
	int scores[3];
	char name[20];
};
int input_data(struct student a [], int b) {
	for (int i = 0; i < b; ++i) {
		(void)scanf("%d", &a[i].id); 

		for (int j = 0; j < 3; ++j){
			(void)scanf("%d", &a[i].scores[j]);
		}
		(void)scanf("%s", a[i].name);
		
	}
	return 0;
}
int print_data(struct student a[], int b) {
	for (int i = 0; i < b; ++i) {
		printf("%d", a[i].id);

		for (int j = 0; j < 3; ++j) {
			printf(" %d", a[i].scores[j]);
		}
		printf(" %s\n", a[i].name);
		
	}
	return 0;
}


int main(void) {
	struct student stu[5] = { 0 };
	(void)freopen("student.txt", "r", stdin);
	
	input_data(stu, SIZE(stu));
	print_data(stu, SIZE(stu));

	return 0;
}
#endif

//구조체 표현 연습
#if 0
struct profile {
	int age;
	double height;
	char* name;
};

struct student {
	struct profile pf;
	int num;
	double grade;
};

int main(void) {
	struct student s1 = { {20,175,"홍길동"},2,4.5 };
	struct student* p = &s1;
	struct student arr[3] = { {{20,175,"홍길동"},2,4.5} };
	
	arr[1] = arr[2] = arr[0];
	

	
	for (int i = 0; i < 3; i++) {
		printf("나이 : %d \n", arr[i].pf.age);
		printf("키 : %.1f \n", arr[i].pf.height);
		printf("이름 : %s \n", arr[i].pf.name);
		printf("학번 : %d \n", arr[i].num);
		printf("학점 : %.1lf \n", arr[i].grade);
	}
	printf("-------------------------------------------------------\n");

	for (int i = 0; i < 3; i++) {
		struct profile* t3 = &arr[i].pf;
		//char* t4 = &arr[i].name;

		printf("나이 : %d \n", t3->age);
		printf("키 : %.1f \n", t3->height);
		printf("이름 : %s \n", t3->name);
		printf("학번 : %d \n", arr[i].num);
		printf("학점 : %.1lf \n", arr[i].grade);
	}
	struct student* parr = arr;
	for (int i = 0; i < 3; i++) {
		printf("나이 : %d \n", (parr+i)->pf.age);
		printf("키 : %.1f \n", parr[i].pf.height);
		printf("이름 : %s \n", parr[i].pf.name);
		printf("학번 : %d \n", parr[i].num);
		printf("학점 : %.1lf \n", parr[i].grade);
	}
	printf("-------------------------------------------------------\n");
	s1.pf.name = "윤소영";
	struct profile t = s1.pf;
	printf("나이 : %d \n", t.age);
	printf("키 : %.1f \n", t.height);
	printf("이름 : %s \n", s1.pf.name);
	printf("학번 : %d \n", s1.num);
	printf("학점 : %.1lf \n", s1.grade);
	printf("-------------------------------------------------------\n");
	struct profile* t2 = &s1.pf;

	printf("나이 : %d \n", t2->age);
	printf("키 : %.1f \n", t2->height);
	printf("이름 : %s \n", s1.pf.name);
	printf("학번 : %d \n", s1.num);
	printf("학점 : %.1lf \n", s1.grade);

	printf("-------------------------------------------------------\n");
	printf("나이 : %d \n", p->pf.age);
	printf("키 : %.1f \n", p->pf.height);
	printf("이름 : %s \n", p->pf.name);
	printf("학번 : %d \n", p->num);
	printf("학점 : %.1lf \n", p->grade);
}

#endif
//구조체 연습
#if 0
struct student {
	int num;
	double grade;
};

int main(void) {
	struct student st = { 3, 4.5 };
	struct student* p = &st;
	struct student st2 = *p;
	printf("%d %.1f\n", st.num, st.grade);
	printf("%d %.1f\n", p->num, p->grade);
	printf("%d %.1f\n", st2.num, st2.grade);
	printf("%d %.1f\n", (*p).num, (*p).grade); // [. > *] 우선순위
	return 0;
}

#endif
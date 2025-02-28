#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

#define MAX_NAME 20
#define MAX_STUDENTS 100

//学生结构体
typedef struct {
	char name[MAX_NAME];
	int id;
	float score;
}Student;

Student students[MAX_STUDENTS];
int count = 0;

//函数声明
void addStudent();
void showAll();
void searchId();
void deleteId();


int main() {
	int choice;
	do
	{
		printf("\n====== 成绩管理系统 =====\n");
		printf("1.添加 2.显示 3.查找 4.删除 0.退出");
		scanf("%d", &choice);
		switch (choice) {
		case 1:addStudent(); break;
		case 2:showAll(); break;
		case 3:searchId(); break;
		case 4:deleteId(); break;
		case 0:printf("再见！\n"); break;
		default:printf("输入错误！\n");

		}
	} while (choice != 0);

	return 0;
}



void addStudent()
{
	if (count >= MAX_STUDENTS)
	{ printf("人数已满！\n");
	return;
	}
	Student s;
	printf("输入学号：");
	scanf("%d", &s.id);

	//检查学号是否重复
	for(int i = 0; i < count; i++){
		if (s.id == students[i].id) {
			printf("学号已存在\n");
			return;
		}
		}
		printf("输入姓名：");
		scanf("%s", s.name);
		printf("输入成绩：");
		scanf("%f", &s.score);

		students[count++] = s;
		printf("添加成功\n");
}

void showAll() {
	if (count == 0)
	{
		printf("没有学生记录。\n");
		return;
	}
	printf("学号\t姓名\t成绩\n");
	for (int i = 0; i < count; i++)
		printf("%d\t%s\t%.2f\n",students[i].id, students[i].name, students[i].score);

}

void searchId() {
	int id;
	printf("请输入要查找的学号");
	scanf("%d", &id);
	for (int i = 0; i < count; i++)
	{
		if (id == students[i].id)
		{
			printf("找到学生，学号：%d，姓名：%s，成绩：%.2f\n");
			return;
		}
	}
	printf("没有找到该学号的学生。\n");

}

void deleteId() {
	int id;
	printf("请输入要删除的学号：");
	scanf("%d", &id);
	for (int i = 0; i < count; i++)
	{
		if (id == students[i].id)
		{
			for (int j = i; j++; j < count-1) {
				students[j] = students[j + 1];
			}
			count--;
			printf("删除成功\n");
			return;
		}

	}
	printf("未找到该学号的学生。\n");

}
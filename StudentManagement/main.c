#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

#define MAX_NAME 20
#define MAX_STUDENTS 100

//ѧ���ṹ��
typedef struct {
	char name[MAX_NAME];
	int id;
	float score;
}Student;

Student students[MAX_STUDENTS];
int count = 0;

//��������
void addStudent();
void showAll();
void searchId();
void deleteId();


int main() {
	int choice;
	do
	{
		printf("\n====== �ɼ�����ϵͳ =====\n");
		printf("1.��� 2.��ʾ 3.���� 4.ɾ�� 0.�˳�");
		scanf("%d", &choice);
		switch (choice) {
		case 1:addStudent(); break;
		case 2:showAll(); break;
		case 3:searchId(); break;
		case 4:deleteId(); break;
		case 0:printf("�ټ���\n"); break;
		default:printf("�������\n");

		}
	} while (choice != 0);

	return 0;
}



void addStudent()
{
	if (count >= MAX_STUDENTS)
	{ printf("����������\n");
	return;
	}
	Student s;
	printf("����ѧ�ţ�");
	scanf("%d", &s.id);

	//���ѧ���Ƿ��ظ�
	for(int i = 0; i < count; i++){
		if (s.id == students[i].id) {
			printf("ѧ���Ѵ���\n");
			return;
		}
		}
		printf("����������");
		scanf("%s", s.name);
		printf("����ɼ���");
		scanf("%f", &s.score);

		students[count++] = s;
		printf("��ӳɹ�\n");
}

void showAll() {
	if (count == 0)
	{
		printf("û��ѧ����¼��\n");
		return;
	}
	printf("ѧ��\t����\t�ɼ�\n");
	for (int i = 0; i < count; i++)
		printf("%d\t%s\t%.2f\n",students[i].id, students[i].name, students[i].score);

}

void searchId() {
	int id;
	printf("������Ҫ���ҵ�ѧ��");
	scanf("%d", &id);
	for (int i = 0; i < count; i++)
	{
		if (id == students[i].id)
		{
			printf("�ҵ�ѧ����ѧ�ţ�%d��������%s���ɼ���%.2f\n");
			return;
		}
	}
	printf("û���ҵ���ѧ�ŵ�ѧ����\n");

}

void deleteId() {
	int id;
	printf("������Ҫɾ����ѧ�ţ�");
	scanf("%d", &id);
	for (int i = 0; i < count; i++)
	{
		if (id == students[i].id)
		{
			for (int j = i; j++; j < count-1) {
				students[j] = students[j + 1];
			}
			count--;
			printf("ɾ���ɹ�\n");
			return;
		}

	}
	printf("δ�ҵ���ѧ�ŵ�ѧ����\n");

}
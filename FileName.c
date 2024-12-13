#include <stdio.h>  
#include <locale.h>  
#include <stdlib.h>  
#define N 100 
#define p 50  

int rand10(int mmax); 
double rand_double(double dmin, double dmax);
int* rand1(int* a, int q, int mmax);  
double* rand_double1(double* b, int q, double dm);

int main() {
	setlocale(LC_ALL, "RUS");
	//1  
	printf("������ �����!\n");
	int m = 1 + rand() % 10;
	int k;
	printf("������� �����:  ");
	scanf_s("%d", &k);
	if (k == m) {
		printf("�������! �� ������� �����!\n");
	}
	else {
		printf("\n���������� �����!\n");
	}
	printf("\n");
	printf("��������: ������/�������/������\n");
	printf("\n");
	int m1 = 1 + rand() % 3;
	int k1;
	printf("��������: \n1 - '������', \n2 - '�������', \n3 - '������'\n");
	scanf_s("%d", &k1);

	if (k1 == m1) {
		printf("�������, �����\n");
	}
	else {
		if ((k1 == 1 && m1 == 2) || (k1 == 2 && m1 == 3) || (k1 == 3 && m1 == 1)) { //������� ��� ������ 
			printf("�� ��������!\n");
		}
		else {
			printf("�� ���������\n");
		}

	}
	printf("\n");
	//2  
	int mmax;
	printf("������� ����� ���������:   ");
	scanf_s("%d", &mmax);
	printf("\n");
	printf("��������� ����� �� 1 �� %d = %d\n", mmax, rand10(mmax));
	printf("\n");

	double dmin, dmax;
	printf("������� ������ ���������:   ");
	scanf_s("%lf", &dmin);
	printf("\n");
	printf("������� ����� ���������:   ");
	scanf_s("%lf", &dmax);
	printf("\n");
	printf("��������� ������������ ����� �� %lf �� %lf = %lf\n", dmin, dmax, rand_double(dmin, dmax));
	printf("\n");

	int a[p];
	printf("��������� ���-�� q ����� �� 1 �� %d =   ", mmax);
	int q;
	printf("\n������� ���-�� ���������:  ");
	scanf_s("%d", &q);
	rand1(a, q, mmax);
	printf("\n\n");

	double b[p];
	double dm;
	printf("������� ����� ���������:  ");
	scanf_s("%lf", &dm);
	printf("\n");
	printf("��������� ������������ ����� �� %lf �� %lf =   ", -dm, dm);
	rand_double1(b, q, dm);
	printf("\n\n");

	//3 
	int min;
	printf("������� ����������� �������� ��������� > 9: ");
	scanf_s("%d", &min);
	int* counter;
	counter = (int*)malloc(min * sizeof(int)); //��������� ������ 
	if (counter == NULL) { //�������� ��������� 
		return 0;
	}

	for (int i = 0; i < min; i++) { //���������� ������� �������� ���������� 
		counter[i] = 0;
	}
	int* array;
	array = (int*)malloc(min * sizeof(int)); //��������� ������ 
	if (array == NULL) { //�������� 
		return 0;
	}
	int q1;
	printf("\n������� �������� ���-�� ��������� � �������:  ");
	scanf_s("%d", &q1);
	rand1(array, q1, min); //���������� ������� ���������� ����������  

	for (int i = 0; i < min; i++) {
		counter[array[i]]++;
	}
	int max_count = 0;
	for (int i = 0; i < min; i++) {
		if (counter[i] > max_count) {
			max_count = counter[i]; //���������� ������������� �������� 
		}
	}
	printf("\n\n");
	printf("�����������\n");
	for (int i = 0; i < min; i++) {
		int x = counter[i] / max_count * q1;
		printf("%2d | ", i + 1);
		for (int j = 0; j < x; j++) {
			printf("*");
		}
		printf("\n");
	}

	free(array);
	free(counter);
}

int rand10(int mmax) { 
	int n = 1 + rand() % mmax;
	return n;
}
double rand_double(double dmin, double dmax) { 
	double n = dmin + 1.f * (dmax - dmin) * rand() / RAND_MAX;
	return n;
}
int* rand1(int* a, int q, int mmax) {
	for (int i = 0; i < q; i++) {
		a[i] = rand10(mmax);
		printf(" %d ", a[i]);
	}
	return 0;
}
double* rand_double1(double* b, int q, double dm) {
	for (int i = 0; i < q; i++) {
		b[i] = rand_double(-dm, dm);
		printf(" %.2lf ", b[i]);
	}
	return 0;

}
#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "time.h"


void StandMassive(int A[], int n)
{
	for (int i = 0; i < n; i++) { printf("El.%d: ", i + 1); scanf_s("%d", &A[i]); }
	printf("Massive: ");
	for (int i = 0; i < n; i++) { printf("%d ", A[i]); }

}
void RandMassive(int A[], int n)
{
	int a, b;
	srand(time(NULL));
	printf("Vvedite granici massiva ot naimens k naibols:\n");
	scanf_s("%d %d", &a, &b);
	for (int i = 0; i < n; i++) { A[i] = a + rand() % (b - a); }
	printf("Massive: \n");
	for (int i = 0; i < n; i++) { printf("%d ", A[i]); }

}
void LinSearch(int A[], int a)
{
	int i = 0, k = 0, val;
	printf("\n");
	printf("Vvedite iskovoe chislo: ");
	scanf_s("%d", &val);
	while ((i < a) && (A[i] != val))
	{
		i++;
		if (i < a)
			k = i;
		else printf("Takogo elementa net!");
	}
	if (a != i)
		printf("Nashel, ego index = %d", k);

}
void BinSearch(int A[], int a)
{
	int l, r, m, f, val;
	l = 0;
	r = a - 1;
	f = 0;
	printf("\n");
	printf("Vvedite iskovoe chislo: ");
	scanf_s("%d", &val);
	while ((l != r) && (!f))
	{
		m = (l + r) / 2;
		if (val > A[m]) l = m + 1;
		else
			if (val < A[m])  r = m - 1;
			else f = 1;
	}
	if (A[m] != val) printf("Takogo elementa net!");
	else printf("Nashel, ego index = %d", m);
}
void BubbleSort(int A[], int a, double Stat1[], int Stat2[])
{
	clock_t start = clock();
	int f, k = 0;
	for (int i = 0; i < a; i++)
		for (int j = 0; j < a - i - 1; j++)
			if (A[j] > A[j + 1]) { f = A[j]; A[j] = A[j + 1]; A[j + 1] = f; k += 3; }
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\n");
	printf("Sort time = %.8f \n", time_spent);
	printf("Kol-vo iterac. - %d", k);
	Stat2[1] = k; Stat1[1] = time_spent;

}
void QS(int A[], int left, int right, double Stat1[], int Stat2[])
{
	int i, j, tmp, k, a, p = 0;
	int mid = (right + left) / 2;
	int val = A[mid];
	i = left;
	j = right;
	a = right + 1;
	clock_t start = clock();
	while (i <= j)
	{
		k = 0; p += 1;
		while (A[i] < val) { i++; p += 1; }
		while (A[j] > val) { j--; p += 1; }
		if (i <= j) { k = -1; tmp = A[i]; A[i] = A[j]; A[j] = tmp; i++; j--; p += 6; }
	}

	if (j > left) QS(A, left, j, Stat1, Stat2);
	if (i < right) QS(A, i, right, Stat1, Stat2);
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\n");
	printf("Sort time = %.8f \n", time_spent);
	printf("Kol-vo iterac. - %d", p);
	Stat1[5] = time_spent; Stat2[5] = p;

}
void VivodOts(int A[], int a)
{
	printf("\n");
	printf("Otsort massive:");
	for (int i = 0; i < a; i++)
		printf("%d ", A[i]);
}
void Vivod(int A[], int a)
{
	printf("\n");
	printf("Massive:");
	for (int i = 0; i < a; i++)
		printf("%d ", A[i]);
}


void TwoBubble(int A[], int a, double Stat1[], int Stat2[])
{
	int f = 1, left = 0, right = a - 1, k = 0, tmp;
	clock_t start = clock();
	while (left <= right)
	{
		for (int i = right; i > left; --i)
		{
			if (A[i - 1] > A[i]) { tmp = A[i]; A[i] = A[i - 1]; A[i - 1] = tmp; k += 3; }
		}
		++left; k++;
		for (int i = left; i < right; ++i)
		{
			if (A[i + 1] < A[i]) { tmp = A[i]; A[i] = A[i + 1]; A[i + 1] = tmp; k += 3; }
		}
		--right; k++;
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\n");
	printf("Sort time = %.8f \n", time_spent); printf("Kol-vo iterac. - %d", k); Stat1[2] = time_spent; Stat2[2] = k;

}

void VstavkaSort(int A[], int a, double Stat1[], int Stat2[])
{
	int j, k = 0;
	clock_t start = clock();
	for (int i = 1; i < a; ++i)
	{
		int tmp = A[i];
		for (j = i - 1; j >= 0 && A[j] > tmp; --j)
		{
			A[j + 1] = A[j]; k++;
		}
		A[j + 1] = tmp; k++;
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\n");
	printf("Sort time = %.8f \n", time_spent); printf("Kol-vo iterac. - %d", k); Stat1[3] = time_spent; Stat2[3] = k;
}
void ViboromSort(int A[], int a, double Stat1[], int Stat2[])
{
	int z = 0;
	clock_t start = clock();
	for (int i = 0; i < a; i++)
	{
		int k = i, tmp;
		for (int j = i - 1; j >= 0; j--)
		{
			if (A[k] < A[j])
			{
				tmp = A[k]; A[k] = A[k - 1]; A[k - 1] = tmp;
				k--; z += 4;
			}
		}
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\n");
	printf("Sort time = %.8f \n", time_spent); printf("Kol-vo iterac. - %d", z); Stat1[4] = time_spent; Stat2[4] = z;
}

void PodschetSort(int A[], int a, double Stat1[], int Stat2[])
{
	int  k, z = 0;
	int S[20000] = { 0 };
	clock_t start = clock();
	for (int i = 0; i < a; i++)
	{
		S[A[i] + 10000]++; z++;
	}
	k = 0; z++;
	for (int i = 0; i <= 20000; i++)
	{
		for (int j = 0; j < S[i]; j++)
		{
			A[k] = i - 10000;
			k++; z += 2;
		}
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\n");
	printf("Sort time = %.f \n", time_spent); printf("Kol-vo iterac. - %d", z); Stat1[6] = time_spent; Stat2[6] = z;
}
void Pere() { printf("\n"); }
void menu()
{
	printf("1.Bubble Sort\n");
	printf("2.Two Bubble Sort\n");
	printf("3.Sort Vstavkami\n");
	printf("4.Sort Viborom\n");
	printf("5.Quick Sort\n");
	printf("6.Podschet Sort\n");
	printf("7.LinSearch\n");
	printf("8.BinSearch\n");
	printf("9. Drygoi massiv\n");
	printf("10.Exit\n");
}
void CopyMass(int A[], int Cop[], int n)
{
	for (int i = 0; i < n; i++) { Cop[i] = A[i]; }
}
void STAT(double Stat1[], int Stat2[])
{
	printf("-------------------------\n");
	for (int i = 1; i < 7; i++)
	{
		switch (i)
		{
		case 1: printf("Bubble: "); break;
		case 2: printf("TwoBubble: "); break;
		case 3: printf("Vstavka: "); break;
		case 4: printf("Vibor: "); break;
		case 5: printf("QS: "); break;
		case 6: printf("Podschet: "); break;
		}
		printf("time - %f  ", Stat1[i]); printf("iter. - %d  ", Stat2[i]);
		printf("\n");
	}
	printf("-------------------------\n");
}
void Proverka(int A[], int n)
{
	int k = 0;
	for (int i = 0; i < n - 1; i++)  if (A[i] > A[i + 1]) k++;
	if (k > 1) printf("Ne otsort!");
	else printf("Otsort!");
}
void emae()
{
	int A[10000] = { 0 };
	int Acopy[10000] = { 0 };
	double Stat1[7] = { 0 };
	int Stat2[7] = { 0 };
	int c = 100;
	int a; int s = 100; int f = 0; double t = 0; int k = 0;
	printf("Vvedite kol-vo elementov massiva: ");
	scanf_s("%d", &a);
	printf("Vibirite tip zadaniya massiva:"); Pere();
	printf("1. Vvod svoego"); Pere();
	printf("2. Random massive"); Pere();
	while ((c != 1) && (c != 2))
	{
		scanf_s("%d", &c);
		switch (c)
		{
		case 1: StandMassive(A, a); break;
		case 2: RandMassive(A, a); break;
		default:
			printf("Takogo varianta net, viberi drygoi!\n");
			Pere();
			break;
		}
	}
	Pere();
	while (s != 10)
	{
		Pere(); Vivod(A, a); Pere(); Pere(); menu(); Pere(); printf("Deistvie? :");
		while (s != 10)
		{
			scanf_s("%d", &s);
			switch (s)
			{
			case 1: CopyMass(A, Acopy, a); BubbleSort(Acopy, a, Stat1, Stat2); VivodOts(Acopy, a); f = 1; Pere(); break;
			case 2: CopyMass(A, Acopy, a); TwoBubble(Acopy, a, Stat1, Stat2); VivodOts(Acopy, a); Pere(); f = 1; break;
			case 3: CopyMass(A, Acopy, a); VstavkaSort(Acopy, a, Stat1, Stat2); VivodOts(Acopy, a); Pere(); f = 1; break;
			case 4: CopyMass(A, Acopy, a); ViboromSort(Acopy, a, Stat1, Stat2); VivodOts(Acopy, a); Pere(); f = 1; break;
			case 5: CopyMass(A, Acopy, a); QS(Acopy, 0, a, Stat1, Stat2); VivodOts(Acopy, a); Pere(); f = 1; break;
			case 6:CopyMass(A, Acopy, a); PodschetSort(Acopy, a, Stat1, Stat2); VivodOts(Acopy, a); Pere(); f = 1; break;
			case 7: LinSearch(A, a); Pere(); break;
			case 8:
				if (f == 1) { BinSearch(Acopy, a); Pere(); }
				else
				{
					printf("Massiv ne otsort!"); s = 100; Pere(); printf("Zanogo"); Pere();
				}
				break;
			case 9: emae(); break;
			case 10:printf("$Exit$"); break;
			default:
				printf("Takogo varianta net, viberi drygoi!\n");
				break;

			}
			if (s == 10)break;
			STAT(Stat1, Stat2);  Pere(); menu(); Pere(); printf("Deistvie? :");

		}
	}


}
int main()
{
	printf("Hello!");
	Pere();
	emae();
}
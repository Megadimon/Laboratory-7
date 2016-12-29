#include <stdio.h>
#include <stdlib.h>
struct CONTRIBUTION
{
	char name[64];
	char cur[32];
	int sum;
	int per;

};

int main(int argc, char* argv[])
{
	int n;
	CONTRIBUTION *pC;
	printf("Number of Investors:\n");
	scanf_s("%d", &n);
	pC = new CONTRIBUTION[n];
	for (int i = 0; i<n; ++i)
	{
		printf("Investors N=%d:\n",i+1);
		printf("Name of bank : ");
		fflush(stdin); gets_s(pC[i].name, 63);
		printf("Currency : ");
		fflush(stdin); gets_s(pC[i].cur, 31);
		printf("Sum : ");
		scanf_s("%d", &pC[i].sum);
		printf("Percent : "); 
		scanf_s("%d", &pC[i].per);

	}
	FILE *pF;
	fopen_s(&pF, "C:\\Programms\\Test\\MyCONTRIBUTION.dat", "wb");
	fwrite(&n, sizeof(int), 1, pF);
	fwrite(pC, sizeof(CONTRIBUTION), n, pF);
	fclose(pF);
	system("pause");
	return 0;
}
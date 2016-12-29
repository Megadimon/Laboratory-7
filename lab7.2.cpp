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
	FILE *pF;
	fopen_s(&pF, "MyCONTRIBUTION.dat", "rb");

	if (pF == 0)
	{
		printf("Error,file not found");
		return 1;
	}
	fread(&n, sizeof(int), 1, pF);
	pC = new CONTRIBUTION[n];
	fread(pC, sizeof(CONTRIBUTION), n, pF);
	fclose(pF);
	for (int i = 0; i<n; ++i)
		printf("%s. %s. %s, %d. %d.\n", pC[i].name,
		pC[i].cur, pC[i].sum, pC[i].per);
	system("pause");
	return 0;
}
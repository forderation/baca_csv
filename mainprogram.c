#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
struct db
{
	char pertanyaan[100];
	char a[100];
	char b[100];
	char c[100];
	char d[100];
	char jawaban;
};

int main()
{
	FILE *import;
	char filename[] = {"database.csv"};
	struct db database[4];
	char temp[100];
	int i = 0;
	char *pointer;
	import = fopen (filename, "r");
	if (import != NULL)
	{
		while (!feof(import) && i<=3)
		{
			if(fgets(temp, 100, (FILE*)import)!=NULL)
			{
                pointer = strtok(temp, ",");
				strcpy(database[i].pertanyaan, pointer);
				pointer = strtok(NULL, ",");
				strcpy(database[i].a, pointer);
				pointer = strtok(NULL, ",");
				strcpy(database[i].b, pointer);
				pointer = strtok(NULL, ",");
				strcpy(database[i].c, pointer);
				pointer = strtok(NULL, ",");
				strcpy(database[i].d, pointer);
				pointer = strtok(NULL, ",");
				database[i].jawaban = *pointer;
				pointer = strtok(NULL, ",");
				i++;
			}
		}
	}
	char opsi;
	do{
        int soal = rand() % 4;
        char jawab;
        printf("%s \npilihan jawaban: \na.%s \nb.%s \nc.%s \nd.%s",database[soal].pertanyaan,database[soal].a,database[soal].b,database[soal].c,database[soal].d);
        printf("\njawab: ");
        scanf(" %c", &jawab);
        if(jawab == database[soal].jawaban){
            printf("anda benar");
        }else{
            printf("anda salah");
        }
        printf("\ncoba lagi (y/t) :");
        scanf(" %c", &opsi);
	}while(opsi == 'y');
	return 0;
}

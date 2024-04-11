#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#pragma warning(disable:4996)

void kodowanie(char* t, char* litery, const char **mors)
{
	int i;

	char** string = (char**)malloc(sizeof(char*) * 255);

	for (i = 0; i < 255; i++)
	string[i] = (char*)malloc(sizeof(char) * 8);
	
    i = 0;
	int j = 0;
	
	while (*t != '\0' && i<87)
	{

		if (*t == litery[i])
		{
			strcpy(string[j], mors[i]);

			printf("%s ", string[j]);

			j++;
			t = t + 1;
			i = 0;
		}
		else
		{
			i++;
		}
	
	}

	for (i = 0; i < 255; i++)
		free(string[i]);

	free(string);
}

char *dekodowanie(char* t, char* litery, const char** mors)
{
	int i = 0;
	int j = 0;
	int k = 0;

	char* string = (char*)malloc(sizeof(char) * 8);
	char slowo[255];

	for (i = 0; t[i] != '\0';)
	{
		j = 0;

		if(i!=0)
		i++;

		
		while (t[i] != ' ' && t[i] != '\0')
		{
			string[j] = t[i];
			i++;
			j++;
		}
		string[j] = '\0';
	
		
		
		for (j = 0;j<87; j++)
		{
			if (strcmp(string, mors[j]) == 0)
			{
				slowo[k] = litery[j];
				k++;
				break;

			}
		}

	}

	free(string);

	slowo[k] = '\0';
		 
	return slowo;
}


int main()
{
	setlocale(LC_ALL, "CP852");
	int n;

		char litery[] = { 'a',165,'b','c',134,'d','e',169,'f','g','h','i','j','k','l',136
	,'m','n',228,'o',162,'p','q','r','s',152,'t','u','v','w','x','y','z',190,171
	,'A',164,'B','C',143,'D','E',168,'F','G','H','I','J','K','L',157,'M','N'
	,227,'O',224,'P','Q','R','S',151,'T','U','V','W','X','Y','Z',189,141,' '
	,'.',',',' ? ',' : ',' - ','0','1','2','3','4','5','6','7','8','9','!','\0' };

	const char* mors[] = {".-",".-.-","-...","-.-.","-.-..","-..",".","..-..","..-.","--."
	,"....","..",".---","-.-",".-..",".-..-","--","-.","--.--","---","---."
	,".--.","--.-",".-.","...","...-...","-","..-","...-",".--","-..-","-.--"
	,"--..","--..-","--..-.",".-",".-.-","-...","-.-.","-.-..","-..",".","..-.."
	,"..-.","--.","....","..",".---","-.-",".-..",".-..-","--","-.","--.--"
	,"---","---.",".--.","--.-",".-.", "...","...-...","-","..-","...-",".--"
	,"-..-","-.--","--..","--..-","--..-.","/",".-.-.-","--..--","..--..","---..."
	,"-....-","-----",".----","..---","...--","....-",".....","-....","--..."
	,"---..","----.","!","\0"};


	printf("kodowanie: (Wybierz 1)\n");
	printf("dekodowanie: (Wybierz 2)\n");
	scanf("%d", &n);
	getchar();
	

	if (n == 1)
	{
		char* t = (char*)malloc(sizeof(char) * 255);
		printf("Podaj slowo do zakodowania: ");
		gets_s(t, 255);
		kodowanie(t, litery, mors);
		free(t);
	}
	else if (n == 2)
	{
		char* t = (char*)malloc(sizeof(char) * 1785);
		printf("Podaj slowo do dekodowania (spacja to '/'): ");
		gets_s(t, 255);
		printf("%s",dekodowanie(t, litery, mors));
		free(t);
	}
	else
	{
		printf("blad wyboru!");
		exit(0);
	}

	
}
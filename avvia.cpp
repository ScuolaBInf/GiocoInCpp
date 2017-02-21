#include<iostream>
#include<windows.h>
using namespace std;

void inserisciTempo(int tempo);

main()
	{
		int tempo = 0;
		FILE* fp = fopen("tempo.txt", "w");
		fprintf(fp, "%d", 0);		
		fclose(fp);	
		system("start gioco.exe");
		while(true)
			{
				inserisciTempo(tempo);
				Sleep(37);
				tempo+=37;
			}
	}

void inserisciTempo(int tempo)
	{
		FILE* fp = fopen("tempo.txt", "w");
		fprintf(fp, "%d", tempo);		
		fclose(fp);		
	}


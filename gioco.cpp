#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h> 
using namespace std;

void interfacciaDiGioco(int, int, char);
int prelevaTempo(FILE* fp);
void fineGioco(char*, int);
void incrementaScore(int& score, int& tempo);

main()
	{
		FILE *fp;
		char lettera;
		int tempo, score, tempoInizio, tempoFine;
		
		tempo = 3000;
		score = 0;		
		srand(time(NULL));
		
		while(true)
			{
				lettera = rand() % 25 + 97;
				interfacciaDiGioco(score, tempo, lettera);
				tempoInizio = prelevaTempo(fp);
				
				if (lettera == getch())
					{
						tempoFine = prelevaTempo(fp);
						if (tempoFine - tempoInizio > tempo)
							fineGioco("\t\t\t\t\tGameOver: TempoScaduto.", score);
						else
							incrementaScore(score, tempo);
					}
				else
					fineGioco("\t\t\t\t\tGameOver: Lettera sbagliata.", score);
			}			
	}

void interfacciaDiGioco(int score, int tempo, char lettera)
	{
		cout << "Score: " << score << endl;
		cout << "Tempo massimo in millisecondi: " << tempo << endl;
		for (int i = 0; i < 10; i++)
			cout << endl;
		cout << "\t\t\t\t\tCarattere da Premere sulla Tastiera: " << lettera << endl;		
	}
	
int prelevaTempo(FILE* fp)
	{
		int tempo;
		fp = fopen("tempo.txt", "r");
		if (fp == NULL)
			{
				throw "NoFile";
			}
		fscanf(fp, "%d", &tempo);
		fclose(fp);		
		return tempo;
	}
	
void fineGioco(char* testo, int score)
	{
		cout << testo << endl;
		cout << "\t\t\t\t\tIl tuo Punteggio e' di: " << score;
		getch();
		system("taskkill /f /im avvia.exe");
		exit(0);		
	}
	
void incrementaScore(int& score, int& tempo)
	{
		score++;
		system("cls");
		tempo-=tempo/90;										
	}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define n_dados 2

int jogadas(int Ndados);

typedef enum {
	LOST = 0,
	WON,
	CONTINUE
} type_game_state;

int main() {
	// gameStatus pode assumir qualquer valor definido em type_game_state, que são: LOST, WON ou CONTINUE.
	// Use gameStatus para definir o estado do seu jogo.
	type_game_state gameStatus;
	char* status_table[3] = { "PERDEU", "GANHOU", "CONTINUA" };
	setlocale(LC_ALL, "Portuguese");
	srand((unsigned int)time(NULL));
	gameStatus = CONTINUE;
	while (gameStatus == CONTINUE) {
		int soma = jogadas(n_dados);
		int n = 1;
		printf("Jogada %d----------\n\n", n);
		if (soma == 7 || soma == 11) {
			gameStatus = WON;
		}
		else {
			if (soma == 2 || soma == 3 || soma == 12) {
				gameStatus = LOST;
			}
		}
		printf("A soma das faces dos dados eh: %d\n\n", soma);
		int ponto = soma;
		while (gameStatus == CONTINUE) {
			n = n++;
			soma = jogadas(n_dados);
			printf("Jogada %d----------\n\n", n);
			printf("O ponto do jogador eh: %d\n", ponto);
			printf("A soma das faces dos dados eh: %d\n\n", soma);
			if (soma == ponto) {
				gameStatus = WON;
			}
			else {
				if (soma == 7) {
					gameStatus = LOST;
				}
			}
		}
		printf("\nO jogador %s\n\n", status_table[gameStatus]);
		int continuar = 1;
		printf("Deseja continuar ? (1)Sim (0)Não ");
		fflush(stdin);
		scanf("%d", &continuar);
		if (continuar == 1) {
			gameStatus = CONTINUE;
			printf("\n");
			system("cls");
		}
	}
	return 0;
}

int jogadas(int Ndados) {
	if (Ndados < 1) return 0;
	else {
		int soma = 0;
		for (int i = 0; i < Ndados; i++) {
			soma = soma + ((rand() % 6) + 1);
		}
		return soma;
	}
}
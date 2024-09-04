#include <stdio.h>

//1Estrutura dados para armazenar a informação dos eventos
typedef struct
{
	char nome[30];
    int dia, mes, ano;
    int diasDuracao, numeroParticipantes;
    float precoBilhete;
} Evento;

//4Funcao para mostrar a informacao de um evento
void mostrarEvento(Evento e)
{
	printf("Nome: %s\n", e.nome);
	printf("Data: %02d-%02d-%04d\n", e.dia, e.mes, e.ano);
	printf("Duracao dias : %d\n", e.diasDuracao);
	printf("Numero de participantes: %d\n", e.numeroParticipantes);
	printf("Preco bilhete: %.2f\n", e.precoBilhete);
}

//5Funcao para mostrar todos os eventos
void mostrarEventos(Evento e[], int n)
{
	//mostrar uma mensagem de erro se não houver nenhum evento
	if (n == 0)
	{
		printf("Nao ha eventos!\n");
		return;
	}

	int i;
	for (i = 0; i < n; i++)
	{
		//chama a funcao mostrarEvento() para cada evento
		printf("=================================\n");
		printf("Evento # %d:\n", i + 1);
		printf("---------------------------------\n");
		mostrarEvento(e[i]);
		printf("---------------------------------\n");
	}
}

//6Funcao para inserir os dados do participante
void inputDate(int* d, int* m, int* a)
{
	printf("\nIntroduza a data do evento [DD-MM-AAAA]: ");
	scanf("%d-%d-%d", d, m, a);
}

//3Funcao para inserir dados e retornar um novo evento do participante
Evento newEvento()
{
	Evento e;
	printf("Introduza o nome do evento: ");
	scanf("%s", e.nome);
	printf("Introduza a data [DD-MM-AAAA]: ");
	scanf("%d-%d-%d", &e.dia, &e.mes, &e.ano);
	printf("Duracao dias: ");
	scanf("%d", &e.diasDuracao);
	printf("Introduza o numero de participantes: ");
	scanf("%d", &e.numeroParticipantes);
	printf("Introduza o preco do bilhete: ");
	scanf("%f", &e.precoBilhete);
	return e;
}

//2Funcao para exibir menu e inserir a escolha do utilizador
int menu()
{
	printf("1. Adicionar novo evento\n");
	printf("2. Mostrar todos os eventos agendados\n");
	printf("3. Mostrar detalhe de evento\n");
	printf("4. Eliminar um evento\n");
	printf("5. Editar um evento\n");
	printf("6. Verificar se uma data esta livre ou reservada\n");
	printf("7. Calcular receita de evento\n");
	printf("8. Comprar bilhete(s)\n");
	printf("9. Determinar record de afluencia\n");
	printf("0. Sair\n");

	printf("\nIntroduza a sua opcao: ");
	int escolha;
	scanf("%d", &escolha);
	return escolha;
}

int main()
{
	// Variaveis locais
	Evento eventos[30];
	int d, m, a;
	int i, numeroDeEventos = 0;

	while (1)
	{
		switch (menu())
		{
		case 1:		// Adiciona um novo evento
			eventos[numeroDeEventos++] = newEvento();
			break;
		case 2:		// Mostra todos os eventos
			mostrarEventos(eventos, numeroDeEventos);
			break;
		case 3:		// Mostra evento numa data introduzida
			inputDate(&d, &m, &a);
			for (i = 0; i < numeroDeEventos; i++)
			{
				if (eventos[i].dia == d && eventos[i].mes == m && eventos[i].ano == a)
				{
					mostrarEvento(eventos[i]);
					break;
				}
				else if (i == numeroDeEventos - 1)
				{
					printf("Nao ha eventos nesta data\n");
				}
			}
			break;
		case 4:		// Elimina um evento
			inputDate(&d, &m, &a);
			for (i = 0; i < numeroDeEventos; i++)
			{
				if (eventos[i].dia == d && eventos[i].mes == m && eventos[i].ano == a)
				{
					int j;

					// Retrocede todos os eventos uma posicao
					for (j = i; j < numeroDeEventos - 1; j++)
						eventos[j] = eventos[j + 1];
					numeroDeEventos--;
					printf("\nEvento eliminado com sucesso\n");
					break;
				}
				else if (i == numeroDeEventos - 1)
				{
					printf("Nao ha eventos nesta data\n");
				}
			}
			break;
		case 5:		// Edita um evento
			inputDate(&d, &m, &a);
			for (i = 0; i < numeroDeEventos; i++)
			{
				if (eventos[i].dia == d && eventos[i].mes == m && eventos[i].ano == a)
				{
					// Inserir os novos dados do participante e guarda o index
					printf("\nIntroduza detalhes do evento\n");
					eventos[i] = newEvento();
					break;
				}
				else if (i == numeroDeEventos - 1)
				{
					printf("Nao ha eventos nesta data\n");
				}
			}
			break;
		case 6:		// Verifica se uma data esta reservada ou nao
			inputDate(&d, &m, &a);
			for (i = 0; i < numeroDeEventos; i++)
			{
				if (eventos[i].dia == d && eventos[i].mes == m && eventos[i].ano == a)
				{
					printf("\nA data introduzida esta reservada\n");
					break;
				}
				else if (i == numeroDeEventos - 1)
				{
					printf("\Data introduzida esta livre\n");
				}
			}
			break;
		case 7:		// Mostra a receita angariada de um evento
			inputDate(&d, &m, &a);
			for (i = 0; i < numeroDeEventos; i++)
			{
				if (eventos[i].dia == d && eventos[i].mes == m && eventos[i].ano == a)
				{
					int num;
					printf("Introduza numero de bilhetes adquiridos: ");
					scanf("%d", &num);
					printf("Total angariado: %.2f\n", num * eventos[i].precoBilhete);
					break;
				}
				else if (i == numeroDeEventos - 1)
				{
					printf("Nao ha eventos nesta data\n");
				}
			}
			break;
		case 8:		// Comprar bilhetes
			inputDate(&d, &m, &a);
			for (i = 0; i < numeroDeEventos; i++)
			{
				if (eventos[i].dia == d && eventos[i].mes == m && eventos[i].ano == a)
				{
					int num;
					printf("Introduza o numero de bilhetes que deseja comprar: ");
					scanf("%d", &num);

					// Mostra o total a ser pago
					printf("\nTotal: %.2f\n", num * eventos[i].precoBilhete);
					break;
				}
				else if (i == numeroDeEventos - 1)
				{
					printf("Nao ha eventos nesta data\n");
				}
			}
			break;
		case 9:		// Determina a afluencia dos participantes
			if (numeroDeEventos != 0)
			{
				// Mostra o evento com mais pessoas
				int max = eventos[0].numeroParticipantes;
				int ind = 0;
				for (i = 1; i < numeroDeEventos; i++)
				{
					if (max < eventos[i].numeroParticipantes)
					{
						max = eventos[i].numeroParticipantes;
						ind = i;
					}
				}
				mostrarEvento(eventos[ind]);
			}
			else
				printf("Nao ha eventos nesta data!\n");
			break;
		case 0:
			// Sair
			return 0;
		}
		printf("\n");
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <ctype.h>
#include "conio.c"

#define HOST "localhost"
#define USER "root"
#define PASS "carmona2017"
#define DB "produtos"

typedef struct{
	char id[2], nome[10],sexo[2];
} retorn;

void ligamysql();

void le(char* nome);

void pulachar( int pula){
        int i;

        for(i=0;i<pula;i++)
            putchar(' ');
    }



int main(void)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT sr;
    COORD consoleSize;

    consoleSize.X = 500; consoleSize.Y = 250;
    sr.Top=sr.Left=0;
    sr.Right=99; sr.Bottom=49;
    SetConsoleWindowInfo(console, TRUE, &sr);
    SetConsoleScreenBufferSize(console, consoleSize);
	int sair = 0,posicao = 0;
	char opcao;

	void cadastros();
	void consultas();


	setlocale(LC_ALL,"portuguese");
	//SetConsoleOutputCP(65001);
	while (sair == 0){
		system("cls");
		textbackground(9);
		pulachar(11);
		printf("MENU");
		pulachar(11);
		gotoxy(1,2);
		pulachar(26);
		gotoxy(1,3);
		printf("CADASTRAR");
		printf("CONSULTAR");
		printf("  SAIR   ");
		printf("--------------------\n\n");
		printf("Digite uma op\xe7ão: ");
		opcao = getch();
		switch(opcao){
			case '1':
				cadastros();
				break;
			case '2':
				consultas();
				break;
			case '3':
				sair = 1;
				break;
			default:
				printf("\nDigite uma alternativa valida!\n");
				system("pause");
		}

	}
   	return 0;
}

void cadastros(){
	int sair = 0;
	void cadastra();
	char opcao;
		system("cls");
		printf("------- Cadastros -------\n");
		printf("1 - Cliente\n");
		printf("2 - Estado\n");
		printf("3 - Tipo\n");
		printf("4 - Categoria\n");
		printf("5 - Produto\n");
		printf("6 - Sair\n");
		printf("-------------------\n\n");
		printf("Digite uma opcao: ");
		opcao = getch();
		switch(opcao){
			case '5':
				cadastra();
				break;
			case '6':
				sair = 1;
				break;
			default:
				system("cls");
				printf("\nDigite uma alternativa valida!\n");
				getch();

		}
}

void consultas(){
	ligamysql();
	return;
}

void cadastra(){
	char descricao[200], serie[5], pedido[5],car ;
	int ano,dia,mes;
	int tipo,estado,cliente,categoria;
	char query[300];
	void enviarcadastro(char* query);


	system("cls");
	printf("Descricao: ______________________________________\n");
	printf("Serie: ____\n");
    le(descricao);

    le(serie);

	printf("N Pedido: ");
	fgets(pedido,5,stdin);
	if(pedido[strlen(pedido) - 1] == '\n')
		pedido[strlen(pedido) - 1] = '\0';
	fflush(stdin);
	printf("Data da encomenda: ");
	scanf("%2d/%2d/%4d",&dia,&mes,&ano);
	sprintf(query,"INSERT INTO produto(descricao,serie,pedido,data_encomenda,data_entrega,id_tipo,id_estado,id_cliente,id_categoria) values('%s','%s','%s','%4d-%02d-%02d'",descricao,serie,pedido,ano,mes,dia);
	printf("Data de entrega: ");
	scanf("%2d/%2d/%4d",&dia,&mes,&ano);
	printf("Tipo de produto: ");
	scanf("%d",&tipo);
	printf("Status da mercadoria: ");
	scanf("%d",&estado);
	printf("Cliente: ");
	scanf("%d",&cliente);
	printf("Categoria do produto: ");
	scanf("%d",&categoria);
	sprintf(query,"%s,'%4d-%02d-%02d','%d','%d','%d','%d');",query,ano,mes,dia,tipo,estado,cliente,categoria);
	system("cls");
	printf("%s",query);
	getch();
	system("cls");
	enviarcadastro(query);
	return;

}
void le(char* nome){

    char caracter,car;
    int aux = 0;
    system("cls");

    do{

        //scanf("%c%c",&car,&caracter);
        caracter = getch();

        printf("%c",caracter);
        //getch();
        /*
        if (caracter != 13){

            switch(caracter){
            case '\x87':
            case '\x80':
                caracter = 'Ç';
                break;
            case '\xc6':
            case '\xc7':
                caracter = 'Ã';
                break;
            case '\xe4':
            case '\xe5':
                caracter = 'Õ';
                break;
            case '\x83':
            case '\xb6':
                caracter = 'Â';
                break;
            case '\xa0':
            case '\xb5':
                caracter = 'Á';
                break;
            case '\xa2':
                caracter = 'Ó';
                break;
            case '\x82':
            case '\x90':
                caracter = 'É';
                break;
            case '\xa1':
            case '\xd6':
                caracter = 'Í';
                break;
            case '\xa3':
            case '\xe9':
                caracter = 'Ú';
                break;
            case '\x93':
            case '\xe2':
                caracter = 'Ô';
                break;
            case '\x85':
            case '\xb7':
                caracter = 'À';
                break;
            default:
                caracter = toupper(caracter);
            }
            nome[aux] = caracter;
            aux++;
        }else
            nome[aux]= '\0';*/

    }while (caracter != 13);
}

void ligamysql(){


	MYSQL conexao;
   	MYSQL_RES *resp;
   	MYSQL_ROW linhas;
   	MYSQL_FIELD *campos;
   	char query[]="SELECT * FROM produto;";
   	int conta; //Contador comum



   mysql_init(&conexao);
   if (mysql_real_connect(&conexao,HOST,USER,PASS,DB,0,NULL,0))
   {
      printf("Conectado com Sucesso!\n");
      if (mysql_query(&conexao,query))
         printf("Erro: %s\n",mysql_error(&conexao));
      else
      {
         resp = mysql_store_result(&conexao);//recebe a consulta
        if (resp) //se houver consulta
        {
           //passa os dados dos campos para a variável campos
           //escreve na tela os nomes dos campos dando
           //um tab somente
           campos = mysql_fetch_fields(resp);
           /*for (conta=0;conta<mysql_num_fields(resp);conta++) {
              printf("%s",(campos[conta]).name);
              getch();
              if (mysql_num_fields(resp)>1)
                  printf("\t");
              }

              printf("\n");   */

              //enquanto retonrnar registros, conta até o
              //número de colunas que a tabela tem e escreve na
              //tela com um tab, depois pula a linha e tenta
              //pegar outro registro
              while ((linhas=mysql_fetch_row(resp)) != NULL)
              {
                 for (conta=0;conta<mysql_num_fields(resp);conta++){
                    printf("%s\t",linhas[conta]);
                }
                    getch();
                 printf("\n");
              }
          }
          mysql_free_result(resp);//limpa a variável do resultado: resp
        }
        mysql_close(&conexao);
   }
   else
   {
      printf("Conexao Falhou\n");
      if (mysql_errno(&conexao))
         printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
   }

	return ;
}

void enviarcadastro(char* query)
{
     MYSQL conexao;
     int res;

     mysql_init(&conexao);
     if ( mysql_real_connect(&conexao, HOST, USER, PASS, DB, 0, NULL, 0) )
     {


        res = mysql_query(&conexao,query);

        if (!res) printf("Registros inseridos %d\n", mysql_affected_rows(&conexao));
        else printf("Erro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));

        mysql_close(&conexao);
    }
    else
    {
        printf("Falha de conexao\n");
        printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
     }
     getch();
}

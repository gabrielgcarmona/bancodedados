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
	int tipo,estado,cliente,categoria;
	char id[5], descricao[200], serie[5], pedido[5], ano_encomenda[5],dia_encomenda[3],mes_encomenda[3],ano_entrega[5],dia_entrega[3],mes_entrega[3];
} retorn;

void ligamysql();
void imprimeMenu();
void le(char* nome);
void printOp(int opcao,int cor);
void pulachar( int pula){
        int i;

        for(i=0;i<pula;i++)
            putchar(' ');
    }

void tamTerminal(int x, int y){
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT sr;
    COORD consoleSize;

    consoleSize.X = x; consoleSize.Y = y;
    sr.Top=sr.Left=0;
    sr.Right=x; sr.Bottom=y;
    SetConsoleWindowInfo(console, TRUE, &sr);
    SetConsoleScreenBufferSize(console, consoleSize);
}

int main(void)
{
	int sair = 0,posicao = 0;
	char opcao;

	void cadastros();
	void consultas();


	setlocale(LC_ALL,"portuguese");
	tamTerminal(26,10);
	//SetConsoleOutputCP(65001);
	imprimeMenu();
	while (sair == 0){
		opcao = getch();
		switch(opcao){
            case 13:
                switch(posicao){
                    case 0:
                        cadastros();
                        break;
                    case 1:
                        consultas();
                        break;
                    case 2:
                        sair = 1;

                }
                break;
            case -32:
                opcao = getch();
                switch(opcao){
                    case '\x48':
                        if(posicao > 0){
                            posicao--;
                        }else
                            posicao = 2;
                        break;
                    case '\x50':
                        if(posicao < 2){
                            posicao++;
                        }else
                            posicao = 0;

                }
		}
		switch(posicao){
            case 0:
                printOp(0,8);
                printOp(1,9);
                printOp(2,9);
                break;
            case 1:
                printOp(0,9);
                printOp(1,8);
                printOp(2,9);
                break;
            case 2:
                printOp(0,9);
                printOp(1,9);
                printOp(2,8);
                break;
		}
	}

   	return 0;
}

void imprimeMenu(){
    textbackground(9);
    system("cls");
    textbackground(8);
    pulachar(11);
    printf("MENU");
    pulachar(12);
    textbackground(9);
    printOp(0,8);
    printOp(1,9);
    printOp(2,9);
    return;

}

void imprimeMenu2(){
    textbackground(9);
    system("cls");
    textbackground(8);
    pulachar(9);
    printf("CADASTROS");
    pulachar(9);
    textbackground(9);
    printOp(3,8);
    printOp(4,9);
    printOp(5,9);
    printOp(6,9);
    printOp(7,9);
    printOp(8,9);
    return;

}

void printOp(int opcao,int cor){
    textbackground(cor);
    switch(opcao){
        case 0:
            gotoxy(10,4);
            printf("CADASTRAR");
            break;
        case 1:
            gotoxy(10,6);
            printf("CONSULTAR");
            break;
        case 2:
            gotoxy(12,8);
            printf("SAIR");
            break;
        case 3:
            gotoxy(11,4);
            printf("PRODUTO");
            break;
        case 4:
            gotoxy(11,5);
            printf("CLIENTE");
            break;
        case 5:
            gotoxy(10,6);
            printf("CATEGORIA");
            break;
        case 6:
            gotoxy(9,7);
            printf("TIPO DE PROD");
            break;
        case 7:
            gotoxy(11,8);
            printf("ESTADO");
            break;
        case 8:
            gotoxy(11,9);
            printf("VOLTAR");
            break;
    }
}

void cadastros(){
	int sair = 0,posicao = 0;
	void cadastra();
	char opcao;
	imprimeMenu2();
	while (sair == 0){
		opcao = getch();
		switch(opcao){
            case 13:
                switch(posicao){
                    case 0:
                        tamTerminal(50,20);
                        imprimeFicha();
                        cadastra();
                        break;
                    case 1:

                        break;
                    case 5:

                        sair = 1;
                        imprimeMenu();
                        posicao = 6;

                }
                break;
            case -32:
                opcao = getch();
                switch(opcao){
                    case '\x48':
                        if(posicao > 0){
                            posicao--;
                        }else
                            posicao = 5;
                        break;
                    case '\x50':
                        if(posicao < 5){
                            posicao++;
                        }else
                            posicao = 0;

                }
		}
		switch(posicao){
            case 0:
                printOp(3,8);
                printOp(4,9);
                printOp(5,9);
                printOp(6,9);
                printOp(7,9);
                printOp(8,9);
                break;
            case 1:
                printOp(3,9);
                printOp(4,8);
                printOp(5,9);
                printOp(6,9);
                printOp(7,9);
                printOp(8,9);
                break;
            case 2:
                printOp(3,9);
                printOp(4,9);
                printOp(5,8);
                printOp(6,9);
                printOp(7,9);
                printOp(8,9);
                break;
            case 3:
                printOp(3,9);
                printOp(4,9);
                printOp(5,9);
                printOp(6,8);
                printOp(7,9);
                printOp(8,9);
                break;
            case 4:
                printOp(3,9);
                printOp(4,9);
                printOp(5,9);
                printOp(6,9);
                printOp(7,8);
                printOp(8,9);
                break;
            case 5:
                printOp(3,9);
                printOp(4,9);
                printOp(5,9);
                printOp(6,9);
                printOp(7,9);
                printOp(8,8);


		}
	}


}

void consultas(){
	ligamysql();
	return;
}

void cadastra(){
    retorn ficha;
	char opcao ;
	int ano,dia,mes;
	int tipo,estado,cliente,categoria;
	char query[300];
	void enviarcadastro(char* query);
    void imprimeFicha();


    imprimeFicha();
    textcolor(7);
    getch();
    le(ficha.descricao);

    le(serie);


	fgets(pedido,5,stdin);
	if(pedido[strlen(pedido) - 1] == '\n')
		pedido[strlen(pedido) - 1] = '\0';
	fflush(stdin);

	scanf("%2d/%2d/%4d",&dia,&mes,&ano);
	sprintf(query,"INSERT INTO produto(descricao,serie,pedido,data_encomenda,data_entrega,id_tipo,id_estado,id_cliente,id_categoria) values('%s','%s','%s','%4d-%02d-%02d','%4d-%02d-%02d','%d','%d','%d','%d');",ficha.descricao,ficha.serie,ficha.pedido,ficha.ano_encomenda,ficha.mes_encomenda,ficha.dia_encomenda,ficha.ano_entrega,ficha.mes_entrega,ficha.dia_entrega,ficha.tipo,ficha.estado,ficha.cliente,ficha.categoria);

	scanf("%2d/%2d/%4d",&dia,&mes,&ano);

	scanf("%d",&tipo);

	scanf("%d",&estado);

	scanf("%d",&cliente);

	scanf("%d",&categoria);
	sprintf(query,"%s,'%4d-%02d-%02d','%d','%d','%d','%d');",query,ano,mes,dia,tipo,estado,cliente,categoria);
	system("cls");
	printf("%s",query);
	getch();
	system("cls");
	enviarcadastro(query);
	return;

}
void imprimeFicha(){
    system("cls");
    textbackground(8);
    pulachar(23);
    printf("FICHA");
    pulachar(23);
    textbackground(9);
    textcolor(15);
    printf("\n\n CATEGORIA DO PRODUTO: ___________________________\n\n");
    printf(" DESCRIÇÃO: ______________________________________\n\n");
	printf(" SÉRIE: ____\n\n");
	printf(" N PEDIDO:____\n\n");
	printf(" DATA DE ENCOMENDA: __/__/____\n\n");
	printf(" DATA DE ENTREGA: __/__/____\n\n");
	printf(" TIPO: [ ]ENCOMENDA    [ ]PRONTA ENTREGA \n\n");
	printf(" STATUS DA MERCADORIA: ___________________________\n\n");
	printf(" CLIENTE: ________________________________________\n\n");
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

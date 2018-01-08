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
int le(char* nome,int maxAux);
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
        case 9:
            gotoxy(20,9);
            printf("SIM");
            break;
        case 10:
            gotoxy(25,9);
            printf("NÃO");
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
                        tamTerminal(50,10);
                        cadCliente();
                        break;
                    case 2:
                        tamTerminal(50,10);
                        cadCategoria();
                        break;
                    case 3:
                        tamTerminal(50,10);
                        cadTipo();
                        break;
                    case 4:
                        tamTerminal(50,10);
                        cadEstado();
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

void cadCliente(){
    char nome[100],ano[5],mes[3],dia[3];
    char query[300],opcao;
    int err=0,sair=0;
INICIO:    system("cls");
    textcolor(15);
    textbackground(8);
    pulachar(22);
    printf("CLIENTE");
    pulachar(22);
    textbackground(9);
    printf("\n\n NOME: ___________________________\n\n");
    printf(" NASCIMENTO: __/__/____\n\n");
    gotoxy(8,3);
    if(le(nome,100))
        goto RETORNAR;
    gotoxy(14,5);
    if(le(dia,2))
        goto RETORNAR;
    gotoxy(17,5);
    if(le(mes,2))
        goto RETORNAR;
    gotoxy(20,5);
    if(le(ano,4))
        goto RETORNAR;
    sprintf(query,"INSERT INTO cliente(nome,nascimento) values('%s','%s-%s-%s');",nome,ano,mes,dia);
    gotoxy(13,7);
    printf("OS DADOS ESTÃO CORRETOS?");
    while(sair == 0){
        switch(err){
            case 0:
                printOp(9,8);
                printOp(10,9);
                break;
            case 1:
                printOp(9,9);
                printOp(10,8);
                break;
        }
        opcao = getch();
        switch(opcao){
            case 13:
                if(err == 1){
                    err = 0;
                    sair = 0;
                    goto INICIO;
                }
                sair = 1;
                break;
            case -32:
                opcao = getch();
                switch(opcao){
                    case '\x4d':
                        if(err < 1 )
                            err++;
                        else
                            err=0;
                        break;
                    case '\x4b':
                        if(err > 0 )
                            err--;
                        else
                            err=1;
                        break;
                }
        }


    }

enviarcadastro(query);
RETORNAR: textcolor(7);
textbackground(9);
imprimeMenu2();
tamTerminal(26,10);

}

void cadCategoria(){
    char nome[30];
    char query[300],opcao;
    int err=0,sair=0;
INICIO1:    system("cls");
    textcolor(15);
    textbackground(8);
    pulachar(21);
    printf("CATEGORIA");
    pulachar(21);
    textbackground(9);
    printf("\n\n NOME: ___________________________\n\n");

    gotoxy(8,3);
    if(le(nome,29))
        goto RETORNAR1;
    sprintf(query,"INSERT INTO categoria(nome) values('%s');",nome);
    gotoxy(13,7);
    printf("OS DADOS ESTÃO CORRETOS?");
    while(sair == 0){
        switch(err){
            case 0:
                printOp(9,8);
                printOp(10,9);
                break;
            case 1:
                printOp(9,9);
                printOp(10,8);
                break;
        }
        opcao = getch();
        switch(opcao){
            case 13:
                if(err == 1){
                    err = 0;
                    sair = 0;
                    goto INICIO1;
                }
                sair = 1;
                break;
            case -32:
                opcao = getch();
                switch(opcao){
                    case '\x4d':
                        if(err < 1 )
                            err++;
                        else
                            err=0;
                        break;
                    case '\x4b':
                        if(err > 0 )
                            err--;
                        else
                            err=1;
                        break;
                }
        }


    }
enviarcadastro(query);
RETORNAR1: textbackground(9);
textcolor(7);
imprimeMenu2();
tamTerminal(26,10);

}

void cadTipo(){
    char nome[30];
    char query[300],opcao;
    int err=0,sair=0;
INICIO2:    system("cls");
    textcolor(15);
    textbackground(8);
    pulachar(18);
    printf("TIPO DE PRODUÇÃO");
    pulachar(17);
    textbackground(9);
    printf("\n\n NOME: ___________________________\n\n");

    gotoxy(8,3);
    if(le(nome,29))
        goto RETORNAR2;
    sprintf(query,"INSERT INTO tipo(nome) values('%s');",nome);
    gotoxy(13,7);
    printf("OS DADOS ESTÃO CORRETOS?");
    while(sair == 0){
        switch(err){
            case 0:
                printOp(9,8);
                printOp(10,9);
                break;
            case 1:
                printOp(9,9);
                printOp(10,8);
                break;
        }
        opcao = getch();
        switch(opcao){
            case 13:
                if(err == 1){
                    err = 0;
                    sair = 0;
                    goto INICIO2;
                }
                sair = 1;
                break;
            case -32:
                opcao = getch();
                switch(opcao){
                    case '\x4d':
                        if(err < 1 )
                            err++;
                        else
                            err=0;
                        break;
                    case '\x4b':
                        if(err > 0 )
                            err--;
                        else
                            err=1;
                        break;
                }
        }


    }

enviarcadastro(query);
RETORNAR2:textcolor(7);
textbackground(9);
imprimeMenu2();
tamTerminal(26,10);

}

void cadEstado(){
    char nome[30];
    char query[300],opcao;
    int err=0,sair=0;
INICIO3:    system("cls");
    textcolor(15);
    textbackground(8);
    pulachar(23);
    printf("ESTADO");
    pulachar(22);
    textbackground(9);
    printf("\n\n NOME: ___________________________\n\n");

    gotoxy(8,3);
    if(le(nome,29))
        goto RETORNAR3;
    sprintf(query,"INSERT INTO estado(nome) values('%s');",nome);
    gotoxy(13,7);
    printf("OS DADOS ESTÃO CORRETOS?");
    while(sair == 0){
        switch(err){
            case 0:
                printOp(9,8);
                printOp(10,9);
                break;
            case 1:
                printOp(9,9);
                printOp(10,8);
                break;
        }
        opcao = getch();
        switch(opcao){
            case 13:
                if(err == 1){
                    err = 0;
                    sair = 0;
                    goto INICIO3;
                }
                sair = 1;
                break;
            case -32:
                opcao = getch();
                switch(opcao){
                    case '\x4d':
                        if(err < 1 )
                            err++;
                        else
                            err=0;
                        break;
                    case '\x4b':
                        if(err > 0 )
                            err--;
                        else
                            err=1;
                        break;
                }
        }


    }

enviarcadastro(query);
RETORNAR3: textcolor(7);
textbackground(9);
imprimeMenu2();
tamTerminal(26,10);

}

void consultas(){
    int consulta;
    retorn* ficha=(retorn*) malloc(sizeof(retorn));

    system("cls");
	consulta = consultaProduto(ficha);
	if(consulta){
        printf("%d Registros encontrados\n",consulta);
        printf("Descrição: %s\n",ficha[0].descricao);
        printf("Data de encomenda: %s/%s/%s\n",ficha[0].dia_encomenda,ficha[0].mes_encomenda,ficha[0].ano_encomenda);
        printf("Data de entrega: %s/%s/%s\n",ficha[0].dia_entrega,ficha[0].mes_entrega,ficha[0].ano_entrega);
        printf("Dados: %02d %02d %02d %02d",ficha[0].tipo,ficha[0].estado,ficha[0].cliente,ficha[0].categoria);
        getch();

	}

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

    gotoxy(13,5);
    le(ficha.descricao,199);
    printf("\n%s",ficha.descricao);
    gotoxy(9,7);
    le(ficha.serie,4);

/*

	sprintf(query,"INSERT INTO produto(descricao,serie,pedido,data_encomenda,data_entrega,id_tipo,id_estado,id_cliente,id_categoria) values('%s','%s','%s','%s-%s-%s','s-%s-%s','%s','%s','%s','%s');",ficha.descricao,ficha.serie,ficha.pedido,ficha.ano_encomenda,ficha.mes_encomenda,ficha.dia_encomenda,ficha.ano_entrega,ficha.mes_entrega,ficha.dia_entrega,ficha.tipo,ficha.estado,ficha.cliente,ficha.categoria);


	enviarcadastro(query);*/
	textcolor(7);
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

int le(char* nome,int maxAux){

    char caracter,car;
    int aux = 0,comeco=1;

    do{
        caracter = getch();
        if (caracter != 13){

            switch(caracter){
            case '\x1b':
                return 1;
                break;
            case '\xe0':
                caracter = getch();
                    switch(caracter){
                        case '\x4b':
                            caracter = '\x08';
                            break;
                    }
                break;
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
            if(caracter != '\x08'){
                nome[aux] = caracter;
                aux++;
                comeco = 0;
            }else

                if (aux > 0){
                    printf("\x08_");
                    aux--;}
                else
                    comeco = 1;
            if (comeco == 0)
                putchar(caracter);
        }else
            nome[aux]= '\0';

    }while (caracter != 13 && aux < maxAux);
    if( aux == maxAux)
        nome[maxAux]='\0';
    return 0;
}

int consultaProduto(retorn* ficha){


	MYSQL conexao;
   	MYSQL_RES *resp;
   	MYSQL_ROW linhas;
   	MYSQL_FIELD *campos;
   	char query[]="SELECT * FROM produto;";
   	int conta = 0,i=0; //Contador comum



   mysql_init(&conexao);
   if (mysql_real_connect(&conexao,HOST,USER,PASS,DB,0,NULL,0))
   {
      if (mysql_query(&conexao,query))
         printf("Erro: %s\n",mysql_error(&conexao));
      else
      {
         resp = mysql_store_result(&conexao);//recebe a consulta
        if (resp) //se houver consulta
        {
           campos = mysql_fetch_fields(resp);

              while ((linhas=mysql_fetch_row(resp)) != NULL)
              {
                  conta++;
                 ficha=(retorn*)realloc(ficha,conta * sizeof(retorn));
                 sprintf(ficha[conta - 1].id,"%s",linhas[0]);
                 sprintf(ficha[conta - 1].descricao,"%s",linhas[1]);
                 sprintf(ficha[conta - 1].serie,"%s",linhas[2]);
                 sprintf(ficha[conta - 1].pedido,"%s",linhas[3]);


                 for(i=0;i<11;i++){
                    switch(i){
                        case 0:case 1:case 2: case 3:
                            ficha[conta - 1].ano_encomenda[i] = linhas[4][i];
                            break;
                        case 4:
                            ficha[conta - 1].ano_encomenda[i] = '\0';
                            break;
                        case 5:case 6:
                            ficha[conta - 1].mes_encomenda[i - 5] = linhas[4][i];
                            break;
                        case 7:
                            ficha[conta - 1].mes_encomenda[i - 5] = '\0';
                            break;
                        case 8:case 9:
                            ficha[conta - 1].dia_encomenda[i - 8] = linhas[4][i];
                            break;
                        case 10:
                            ficha[conta - 1].dia_encomenda[i - 8] = '\0';
                    }
                 }
                 for(i=0;i<11;i++){
                    switch(i){
                        case 0:case 1:case 2: case 3:
                            ficha[conta - 1].ano_entrega[i] = linhas[5][i];
                            break;
                        case 4:
                            ficha[conta - 1].ano_entrega[i] = '\0';
                            break;
                        case 5:case 6:
                            ficha[conta - 1].mes_entrega[i - 5] = linhas[5][i];
                            break;
                        case 7:
                            ficha[conta - 1].mes_entrega[i - 5] = '\0';
                            break;
                        case 8:case 9:
                            ficha[conta - 1].dia_entrega[i - 8] = linhas[5][i];
                            break;
                        case 10:
                            ficha[conta - 1].dia_entrega[i - 8] = '\0';
                    }
                 }
                sscanf(linhas[6],"%d",&ficha[conta - 1].tipo);
                sscanf(linhas[7],"%d",&ficha[conta - 1].estado);
                sscanf(linhas[8],"%d",&ficha[conta - 1].cliente);
                sscanf(linhas[9],"%d",&ficha[conta - 1].categoria);
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

	return conta;
}



void enviarcadastro(char* query)
{
     MYSQL conexao;
     int res;

     mysql_init(&conexao);
     if ( mysql_real_connect(&conexao, HOST, USER, PASS, DB, 0, NULL, 0) )
     {


        res = mysql_query(&conexao,query);

        if (res){
            printf("\nErro na inserção %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
            getch();
        }
        mysql_close(&conexao);
    }
    else
    {
        printf("Falha de conexao\n");
        printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
        getch();
     }

}

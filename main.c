#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

#define HOST "localhost"
#define USER "root"
#define PASS "carmona2017"
#define DB "teste"

int main(void)
{
	int sair = 0;
	char opcao;
	void ligamysql();
	void cadastros();
	void consultas();
	
	
	while (sair == 0){
		system("cls");
		printf("------- Menu -------\n");
		printf("1 - Cadastrar\n");
		printf("2 - Consultar\n");
		printf("3 - Sair\n");
		printf("--------------------\n\n");
		printf("Digite uma opcao: ");
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
		ligamysql();
	}
   	return 0;
}

void cadastros(){
	int sair = 0;
	char opcao;
		system("cls");
		printf("------- Cadastros -------\n");
		printf("1 - Cliente\n");
		printf("2 - Estado\n");
		printf("3 - Tipo\n");
		printf("4 - Produto\n");
		printf("5 - Sair\n");
		printf("-------------------\n\n");
		printf("Digite uma opcao: ");
		opcao = getch();
		switch(opcao){
			case '5':
				sair = 1;
				break;
			default: 
				system("cls");
				printf("\nDigite uma alternativa valida!\n");
				getch();
				
		}
}

void consultas(){
	return;
}
void ligamysql(){
	
	
	   MYSQL conexao; 
   MYSQL_RES *resp;
   MYSQL_ROW linhas;
   MYSQL_FIELD *campos;
   char query[]="SELECT * FROM aprendendo;";
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
           for (conta=0;conta<mysql_num_fields(resp);conta++) {
              printf("%s",(campos[conta]).name);
              getch();
              if (mysql_num_fields(resp)>1)
                  printf("\t");
              }
         
              printf("\n");   

              //enquanto retonrnar registros, conta até o
              //número de colunas que a tabela tem e escreve na
              //tela com um tab, depois pula a linha e tenta
              //pegar outro registro
              while ((linhas=mysql_fetch_row(resp)) != NULL)
              {
                 for (conta=0;conta<mysql_num_fields(resp);conta++)
                    printf("%s",linhas[conta]);
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

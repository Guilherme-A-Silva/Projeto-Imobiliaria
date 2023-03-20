#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <locale.h>
#include "gg.h"
#define STRTAM 40

using namespace std;
int pos;

int IniciarCliente(FILE* Arquivo, CadastroCliente C2[100])
{
	int cont=0;
	Arquivo = fopen ("DadosCliente.bin", "rb");
	if(Arquivo!=NULL)
		while(fread(&C2[cont],sizeof(CadastroCliente),1,Arquivo)!=0) cont++;
    else
	{
		Arquivo = fopen("DadosCliente.bin", "Wb");
		printf("Arquivo criado com sucesso!\n");
	}
	return cont;
}

int IniciarEmpresa(FILE* Arquivo, CadastroEmpresa Emp2[100])
{
	int cont=0;
	Arquivo = fopen ("DadosEmpresa.bin", "rb");
	if(Arquivo!=NULL)
		while(fread(&Emp2[cont],sizeof(CadastroEmpresa),1,Arquivo)!=0) cont++;
    else
	{
		Arquivo = fopen("DadosEmpresa.bin", "Wb");
		printf("Arquivo criado com sucesso!\n");
	}
	return cont;
}
int IniciarImovel(FILE* Arquivo, CadastroImovel Im2[100])
{
	int cont=0;
	Arquivo = fopen ("DadosImovel.bin", "rb");
	if(Arquivo!=NULL)
		while(fread(&Im2[cont],sizeof(CadastroImovel),1,Arquivo)!=0) cont++;
    else
	{ 
		Arquivo = fopen("DadosImovel.bin", "Wb");
		printf("Arquivo criado com sucesso!\n");
	}
	return cont;
}

//==============================================================================
/*
//     FUNÇÕES PARA CLIENTES
*/
//==============================================================================
//     FUNÇÃO DE CADASTRO DE CLIENTES
//==============================================================================
void CadastrarCliente(FILE* Arquivo, CadastroCliente C2[100], int pos)
{
	int i = 0;
	while(i<1){
		i++;
		cout<<"\n ENTRADA DE DADOS DO CLIENTE";
		cout<<" CPF: ";
		cin.ignore();
		cin>>C2[pos+1].cpf_cliente;
		cout<<" SENHA: ";
		cin.ignore();
		cin>>C2[pos+1].senha_cliente;
		cout<<" NOME: ";
		cin.ignore();
		cin.getline(C2[pos+1].nome_cliente,50);
		cout<<" RG: ";
		cin.ignore();
		cin>>C2[pos+1].rg_cliente;
		cout<<" ENDEREÇO(RUA): ";
		cin.ignore();
		cin.getline(C2[pos+1].endereco_rua_cliente,25);
		cout<<" ENDEREÇO(BAIRRO): ";
		cin.ignore();
		cin.getline(C2[pos+1].endereco_bairro_cliente,25);
		cout<<" ENDEREÇO(CIDADE): ";
		cin.ignore();
		cin.getline(C2[pos+1].endereco_cidade_cliente,25);
		cout<<" ENDEREÇO(ESTADO): ";
		cin.ignore();
		cin.getline(C2[pos+1].endereco_estado_cliente,25);
		cout<<" IDADE: ";
		cin.ignore();
		cin>>C2[pos+1].idade_cliente;
	    fwrite(&C2[pos+1],sizeof(CadastroCliente),1,Arquivo);
		}
		fclose(Arquivo);
		
}

//==============================================================================
//     FUNÇÃO PARA EXIBIR DADOS DA STRUCT DE CLIENTES
//==============================================================================
void MostrarDadosCliente(CadastroCliente C0, int pos)
{
	printf("\n CPF = %s",C0.cpf_cliente);
	printf("\n NOME = %s",C0.nome_cliente);
	printf("\n RG = %s",C0.rg_cliente);
	printf("\n RUA = %s",C0.endereco_rua_cliente);
	printf("\n BAIRRO = %s",C0.endereco_bairro_cliente);
	printf("\n CIDADE = %s",C0.endereco_cidade_cliente);
	printf("\n ESTADO = %s \n",C0.endereco_estado_cliente);
}

//==============================================================================
//     FUNÇÃO DE BUSCA DE DADOS DOS CLIENTES
//==============================================================================
int BuscaDadosCliente(FILE* Arquivo, CadastroCliente C2[100], char CPF[12])
{
	int Achou=1;
	int NAchou=-1;
	int pos=0;
	int Tam;
	Tam=IniciarCliente(Arquivo,C2);
	
	while(pos<Tam) {
		if(strcmp(C2[pos].cpf_cliente,CPF)==0) Achou=pos;
	    pos++;
	}
	if(Achou==-1)
	{
		cout<<"\n Registro Inexistente!";
		system("pause");
		return NAchou;
	}
	else
    return Achou;
}

//==============================================================================
//     FUNÇÃO DE EXCLUIR DADOS DE CLIENTES
//==============================================================================
// void ExcluirCliente(FILE* Arquivo, CadastroCliente C2[100], char *CPF, char *cpf_cliente)
// {
// 	int pos, Tam, i;
// 	char *escolha;
// 	Tam=IniciarCliente(Arquivo,C2);
// 	pos=BuscaDadosCliente(Arquivo, C2, CPF);
// 	if(pos!=-1) {
// 		cout<<"\n TEM CERTEZA QUE DESEJA EXCLUIR O REGISTRO COM CPF(S=Sim,N=Não)= "<<CPF<<
// 		cin>>escolha;
// 		if((escolha=='S')||(escolha=='s'))
// 		{
// 			if(pos==0)
// 				for(i=1;i<Tam;i++)
// 					C2(1-1)=C2[i];
// 				else
// 				for(i=1;i<Tam;i++)
// 					if(i>=pos)
// 						C2[i]=C2[i+1];
// 					
// 					Arquivo = fopen ("Dados.bin", "wb");
// 					for(i=0;i<Tam-1;i++)
// 						fwrite(&C2[i],sizeof(CadastroCliente),1,Arquivo);
// 					fclose(Arquivo);
// 		}
// 	}
// }

//==============================================================================
//     FUNÇÃO DE EDITAR DADOS DE CLIENTES
//==============================================================================
int EditarCliente(FILE* Arquivo, CadastroCliente C2[100], char *CPF, char nome_c[50])
{ int pos, Tam,i;
    Tam=IniciarCliente(Arquivo,C2);
	pos=BuscaDadosCliente(Arquivo,C2,CPF);
    strcpy(C2[pos].nome_cliente,nome_c);
	Arquivo = fopen ("DadosCliente.bin", "wb");
	for(i=0;i<Tam;i++)
		fwrite(&C2[i],sizeof(CadastroCliente),1,Arquivo);
	
	fclose(Arquivo);
}

//==============================================================================
/*
//     FUNÇÕES PARA EMPRESA
*/
//==============================================================================
//     FUNÇÃO DE CADASTRO DE EMPRESA
//==============================================================================

void CadastrarEmpresa(FILE* Arquivo, CadastroEmpresa Emp2[100], int pos)
{
    int i = 0;
	while(i<1)
	{
		i++;
		cout<<"\n ENTRADA DE DADOS DO EMPRESA ";
		cout<<" CNPJ: ";
		cin>>Emp2[pos+1].cnpj;
		cout<<" NOME DA EMPRESA: ";
		cin.ignore();
		cin.getline(Emp2[pos+1].nome_empresa,50);
		cout<<" SENHA: ";
		cin.ignore();
		cin>>Emp2[pos+1].senha_emp;
		cout<<" CIDADE: ";
		cin.ignore();
		cin>>Emp2[pos+1].endereco_cidade_emp;
		cout<<" ENDERECO(RUA): ";
		cin.ignore();
		cin.getline(Emp2[pos+1].endereco_rua_emp,25);
		cout<<" ENDERECO(BAIRRO): ";
		cin.ignore();
		cin.getline(Emp2[pos+1].endereco_bairro_emp,25);
		cout<<" ENDERECO(ESTADO): ";
		cin.ignore();
		cin.getline(Emp2[pos+1].endereco_estado_emp,25);
        fwrite(&Emp2[pos+1],sizeof(CadastroEmpresa),1,Arquivo);
	}
	fclose(Arquivo);
}

//==============================================================================
//     FUNÇÃO PARA EXIBIR DADOS DA EMPRESA
//==============================================================================
void MostrarDadosEmpresa(CadastroEmpresa Emp0, int i)
{
	printf("\n CPF = %s",Emp0.cnpj);
	printf("\n NOME = %s",Emp0.nome_empresa);
	printf("\n RUA = %s",Emp0.endereco_rua_emp);
	printf("\n BAIRRO = %s",Emp0.endereco_bairro_emp);
	printf("\n CIDADE = %s",Emp0.endereco_cidade_emp);
	printf("\n ESTADO = %s \n",Emp0.endereco_estado_emp);
}

//==============================================================================
//     FUNÇÃO DE BUSCA DE DADOS DE EMPRESAS
//==============================================================================
int BuscaDadosEmpresa(FILE* Arquivo, CadastroEmpresa Emp2[100], char CNPJ[20])
{
	int Achou=-1;
	int NAchou=-1;
	int pos=0;
	int Tam;
	int TT;
	Tam=IniciarEmpresa(Arquivo,Emp2);
	
	while(pos<Tam) {
		if(strcmp(Emp2[pos].cnpj,CNPJ)==0) Achou=pos;
	    pos++;
	}
	if(Achou==-1)
	{
		cout<<"\n Registro Inexistente!";
		system("pause");
		return NAchou;
	}
	else
    return Achou;
fclose(Arquivo);
}

//==============================================================================
//     FUNÇÃO - MENU DE CADASTRO DE IMÓVEIS
//==============================================================================

int MenuCadastroImoveis() 
{
	int opc6;
	criaMenuLinhaSuperior();
	criaMenuItem(STRTAM," LISTA DE BAIRROS PARA CADASTRO ");
	criaMenuLinhaHorizontal(STRTAM);
	criaMenuItem(STRTAM,"[1] ABOLIÇÃO");
	criaMenuItem(STRTAM,"[2] CENTRO");
	criaMenuItem(STRTAM,"[3] NOVA BETÂNIA");
	criaMenuItem(STRTAM," ESCOLHA UMA OPÇÃO: ");
	criaMenuLinhaRodape(STRTAM);
	scanf("%d",&opc6);
	   	return opc6;
}

//==============================================================================
//     FUNÇÃO PARA CADASTRAR IMÓVEIS
//==============================================================================
void CadastrarImovel(FILE* Arquivo, CadastroImovel Im2[100], int n, int pos)
{
	int opc6;
	int i=0;
	char perg[3];
	while (i < n)
	{
		i++;
		opc6=MenuCadastroImoveis();
		if(opc6==1){
			strcpy(Im2[pos+1].bairro_imovel,"Abolicao");
	
		}
		if(opc6==2){
			strcpy(Im2[pos+1].bairro_imovel,"Centro");
	
		}
		if(opc6==3){
			strcpy(Im2[pos+1].bairro_imovel,"NovaBetania");
	
		}
		cout<<"\n CADASTRO DE DADOS DO IMÓVEL \n";
		// cout<<" BAIRRO: ";
		// cin.ignore();
		// cin.getline(Im2[pos+1].bairro_imovel,25);
		cout<<" RUA: ";
		cin.ignore();
		cin.getline(Im2[pos+1].rua_imovel,25);
		cout<<" INFORME O TIPO DE IMÓVEL: ";
		cin.getline(Im2[pos+1].tipo_imovel,25);
		cout<<" DESEJA VENDER O IMOVEL?: |S PARA SIM E N PARA NÃO| ";
		cin>>perg;
		if(strcmp(perg, "S")==0){
		cout<<" INFORME O PREÇO DE VENDA DO IMÓVEL: ";
		cin.ignore();
		cin>>Im2[pos+1].preco_venda;
		}
		else{
		cout<<" INFORME O PREÇO DO ALUGUEL DO IMÓVEL: ";
		cin.ignore();
		cin>>Im2[pos+1].preco_aluguel;			
		}
		cout<<" INFORME A CONDIÇÃO DO IMÓVEL: ";
		cin.ignore();
		cin.getline(Im2[pos+1].condicao_imovel,25);
		cout<<" QUAL O TAMANHO DO IMÓVEL? | EM METROS QUADRADOS | : ";
		cin>>Im2[pos+1].tamanho_imovel;
		fwrite(&Im2[pos+1],sizeof(CadastroImovel),1,Arquivo);
	}
	fclose(Arquivo);
}

//==============================================================================
//     FUNÇÃO PARA EXIBIR DADOS DA EMPRESA
//==============================================================================
void MostrarDadosImovel(CadastroImovel Im0, int pos)    
{
	printf("\n BAIRRO = %s",Im0.bairro_imovel);
	printf("\n RUA = %s",Im0.rua_imovel);
	printf("\n TIPO DE IMOVEL = %s",Im0.tipo_imovel);
	printf("\n PREÇO DE VENDA OU ALUGUEL DO IMOVEL = %s, %s",Im0.preco_venda,Im0.preco_aluguel);
	printf("\n CONDIÇÃO DO IMOVEL = %s",Im0.condicao_imovel);
	printf("\n TAMANHO DO IMOVEL | EM METROS QUADRADOS | = %s\n",Im0.tamanho_imovel);
}

//==============================================================================
//     FUNÇÃO PARA EDITAR DADOS DA EMPRESA
//==============================================================================
void EditarEmpresa(FILE* Arquivo, CadastroEmpresa Emp2[100], char cnpj[20], char CNPJ[20], char nome_emp[50])
{ 
	int pos, Tam,i;
    Tam=IniciarEmpresa(Arquivo,Emp2);
	pos=BuscaDadosEmpresa(Arquivo,Emp2, CNPJ);
    strcpy(Emp2[pos].nome_empresa,nome_emp);
	Arquivo = fopen ("DadosEmpresa.bin", "wb");
	for(i=0;i<Tam;i++)
		fwrite(&Emp2[i],sizeof(CadastroEmpresa),1,Arquivo);
	
	fclose(Arquivo);
}

//==============================================================================
//     FUNÇÃO DE BUSCA DE DADOS DE IMÓVEIS
//==============================================================================
int BuscaDadosImovel(FILE* Arquivo, CadastroImovel Im2[100], char bairro[25])
{
	int Achou=-1;
	int NAchou=-1;
	int pos=0;
	int Tam;
	int TT;
	Tam=IniciarImovel(Arquivo,Im2);
	
	while(pos<Tam) {
		if(strcmp(Im2[pos].bairro_imovel,bairro)==0) Achou=pos;
	    pos++;
	}
	if(Achou==-1)
	{
		cout<<"\n Registro Inexistente!";
		system("pause");
		return NAchou;
	}
	else
    return Achou;
fclose(Arquivo);
}

//==============================================================================
//     FUNÇÃO PARA BUSCAR POR IMÓVEIS
//==============================================================================
int BuscaBairros(FILE* Arquivo, CadastroImovel Im2[100], char bairro_imovel[25], char bairro[25])
{
	int Achou=-1;
	int NAchou=-1;
	int pos=0;
	int Tam;
	int TT=0;
	Tam=IniciarImovel(Arquivo,Im2);
	
	printf("%s", bairro);
	
	for(int i=0; i<Tam; i++){
		if(strcmp(Im2[i].bairro_imovel,bairro)==0)TT=i;{
		i++;	
		}
		strcpy(bairro_imovel,Im2[TT].bairro_imovel);
	}
	
	while(pos<Tam) {
		if(strcmp(Im2[pos].bairro_imovel,bairro)==0) {
			Achou=pos;
	   	    pos++;
		} 
	}
	if(Achou==-1)
	{
		cout<<"\n NÃO EXISTEM IMÓVEIS REGISTRADOS PARA ESSE BAIRRO! \n";
		system("pause");
		return NAchou;
	}
	else
    return Achou;
fclose(Arquivo);
}

//==============================================================================
//     BORDAS PARA MENU
//==============================================================================

//==============================================================================
//     LINHA SUPERIOR DO MENU
//==============================================================================
void criaMenuLinhaSuperior()
{
	int i;
	printf("%c", 201);
	for(i=0;i<STRTAM;i++)
		printf("%c", 205);
	printf("%c\n", 187);
}

//==============================================================================
//     RODAPÉ DO MENU
//==============================================================================
void criaMenuLinhaRodape(int tamX)
{
	int i;
	printf("%c", 200);
	for(i=0;i<STRTAM;i++)
		printf("%c", 205);
	printf("%c\n", 188);
}

//==============================================================================
//     ADICIONA LINHAS DO MENU
//==============================================================================
void criaMenuItem(int tamX, char str[])
{
	printf("%c", 186);	
	printf("%-*s", tamX,str);	
	printf("%c\n", 186);
}

//==============================================================================
//     ADICIONA LINHAS HORIZONTAIS AO MENU
//==============================================================================
void criaMenuLinhaHorizontal(int tamX)
{
	int i;
	printf("%c", 204);
	for(i=0;i<tamX;i++)
	printf("%c", 205);
	printf("%c\n", 185);
}

//==============================================================================
/*
//     FUNÇÃO - MENUS - EMPRESAS
*/
//==============================================================================

//==============================================================================
//     FUNÇÃO - MENU PARA EMPRESAS
//==============================================================================
int LoginEmpresa(FILE* Arquivo,CadastroEmpresa Emp2[100], char cnpj[20], char senha_emp[20]) 
{
	char login[20], senha[20];
	int Achou=-1, NAchou=-3, TT = 0;
	int Tam, pos=0;
	
	printf("\n LOGIN |EMPRESA| \n");
	printf(" DIGITE SEU CNPJ: "); 
	scanf("%s",&login);
	printf(" DIGITE SUA SENHA: ");
	scanf("%s",&senha);
	
	Tam=IniciarEmpresa(Arquivo, Emp2);
	for(int i=0; i<Tam; i++){
		if(strcmp(Emp2[i].cnpj,login)==0)TT=i;	
	}
	strcpy(cnpj,Emp2[TT].cnpj);
	for(int i=0; i<Tam; i++){
		if(strcmp(Emp2[i].senha_emp,senha)==0)TT=i;	
	}
	strcpy(senha_emp,Emp2[TT].senha_emp);
	if(strcmp(cnpj,login)==0){
		if(strcmp(senha_emp,senha)==0){
			return Achou = 1;
		}
	}else{
		 printf("ACESSO NEGADO!!!");
	     return 0;	
	}
} 

//==============================================================================
//     FUNÇÃO - MENU PRINCIPAL DE EMPRESA
//==============================================================================


int MenuEmpresaOpc() 
{
	int opc5;
	criaMenuLinhaSuperior();
	criaMenuItem(STRTAM," MENU EMPRESA ");
	criaMenuLinhaHorizontal(STRTAM);
	criaMenuItem(STRTAM,"[1] MOSTRAR DADOS");
	criaMenuItem(STRTAM,"[2] EDITAR");
	criaMenuItem(STRTAM,"[3] REGISTRAR IMÓVEIS");
	criaMenuItem(STRTAM,"[4] SAIR DO PROGRAMA");
	criaMenuItem(STRTAM," ESCOLHA UMA OPÇÃO: ");
	criaMenuLinhaRodape(STRTAM);
	scanf("%d",&opc5);
	return opc5;
}

//==============================================================================
//     FUNÇÃO - MENU DE LOGIN PARA EMPRESAS
//==============================================================================
int Menu_Empresa()
{
	int opc4;
	criaMenuLinhaSuperior();
	criaMenuItem(STRTAM," MENU DE CADASTRO E LOGIN |EMPRESA| ");
	criaMenuLinhaHorizontal(STRTAM);
	criaMenuItem(STRTAM,"[1] CADASTRO");
	criaMenuItem(STRTAM,"[2] FAZER LOGIN");
	criaMenuItem(STRTAM," ESCOLHA UMA OPÇÃO: ");
	criaMenuLinhaRodape(STRTAM);
	scanf("%d",&opc4);
	return opc4;
}

//==============================================================================
/*
//     FUNÇÃO - MENUS - CLIENTES
*/
//==============================================================================
//==============================================================================
//     	FUNÇÃO - MENU PARA BUSCA DE IMÓVEIS
//==============================================================================
int MenuImoveis() 
{
	int opc3;
	criaMenuLinhaSuperior();
	criaMenuItem(STRTAM," LISTA DE BAIRROS ");
	criaMenuLinhaHorizontal(STRTAM);
	criaMenuItem(STRTAM,"[1] ABOLIÇÃO");
	criaMenuItem(STRTAM,"[2] CENTRO");
	criaMenuItem(STRTAM,"[3] NOVA BETÂNIA");
	criaMenuItem(STRTAM,"[4] SAIR DO PROGRAMA");
	criaMenuItem(STRTAM," ESCOLHA UMA OPÇÃO: ");
	criaMenuLinhaRodape(STRTAM);
	scanf("%d",&opc3);
	   	return opc3;
}

//==============================================================================
//     FUNÇÃO DE LOGIN - CLIENTE
//==============================================================================
int LoginCliente(FILE* Arquivo, CadastroCliente C2[100], char cpf_cliente[12], char senha_cliente[12]) 
{
	char login[12], senha[12];
	int Achou=-1, NAchou=-3, TT = 0;
	int Tam, pos=0;
	
	Tam=IniciarCliente(Arquivo,C2);
	printf("\n LOGIN |CLIENTE| \n");
	printf("DIGITE SEU CPF: ");
	scanf("%s",&login);
	printf("DIGITE SUA SENHA: ");
	scanf("%s",&senha);
	
	for(int i=0; i<Tam; i++){
		if(strcmp(C2[i].cpf_cliente,login)==0)TT=i;	
	}
	strcpy(cpf_cliente,C2[TT].cpf_cliente);
	for(int i=0; i<Tam; i++){
		if(strcmp(C2[i].senha_cliente,senha)==0)TT=i;	
	}
	strcpy(senha_cliente,C2[TT].senha_cliente);
	if(strcmp(cpf_cliente,login)==0){
		if(strcmp(senha_cliente,senha)==0){
			return Achou = 1;
		}
	}else
	{
	   printf("ACESSO NEGADO!!!");
	   return 0;	
	}
}

//==============================================================================
//     FUNÇÃO - MENU PRINCIPAL DE CLIENTE
//==============================================================================
int MenuClienteOpc() 
{
	int opc2;
	criaMenuLinhaSuperior();
	criaMenuItem(STRTAM," MENU CLIENTE ");
	criaMenuLinhaHorizontal(STRTAM);
	criaMenuItem(STRTAM,"[1] MOSTRAR DADOS");
	criaMenuItem(STRTAM,"[2] EDITAR");
	criaMenuItem(STRTAM,"[3] BUSCAR IMÓVEIS");
	criaMenuItem(STRTAM,"[4] SAIR DO PROGRAMA");
	criaMenuItem(STRTAM," ESCOLHA UMA OPÇÃO: ");
	criaMenuLinhaRodape(STRTAM);
	scanf("%d",&opc2);
	return opc2;
}

//==============================================================================
//     FUNÇÃO - MENU DE LOGIN PARA CLIENTES
//==============================================================================

int Menu_Cliente()
{
	int opc1;
	criaMenuLinhaSuperior();
	criaMenuItem(STRTAM," MENU DE CADASTRO E LOGIN |CLIENTE| ");
	criaMenuLinhaHorizontal(STRTAM);
	criaMenuItem(STRTAM,"[1] CADASTRO");
	criaMenuItem(STRTAM,"[2] FAZER LOGIN");
	criaMenuItem(STRTAM,"[3] SAIR DO PROGRAMA");
	criaMenuItem(STRTAM," ESCOLHA UMA OPÇÃO: ");
	criaMenuLinhaRodape(STRTAM);
	scanf("%d",&opc1);
  	return opc1;
}

//==============================================================================
//     FUNÇÃO - MENU PRINCIPAL
//==============================================================================
int MenuPrincipal()
{
	int opc;
	criaMenuLinhaSuperior();
	criaMenuItem(STRTAM," MENU PRINCIPAL ");
	criaMenuLinhaHorizontal(STRTAM);
	criaMenuItem(STRTAM,"[1] CLIENTE");
	criaMenuItem(STRTAM,"[2] EMPRESA");
	criaMenuItem(STRTAM,"[3] SAIR DO PROGRAMA");
	criaMenuItem(STRTAM," ESCOLHA UMA OPÇÃO: ");
	criaMenuLinhaRodape(STRTAM);
	scanf("%d",&opc);
 	return opc;
}
#ifndef _GG_H
#define _GG_H

//===================================================================
/*
BIBLIOTECAS UTILIZADAS
*/
//===================================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <locale.h>


// ==================================================================
/*
ESTRUTURA DOS DADOS - CADASTRO EMPRESARIAL
*/
// ==================================================================

struct CadastroEmpresa
{
   char nome_empresa[50];
   char cnpj[20];
   char senha_emp[20];
   char endereco_rua_emp[25];
   char endereco_bairro_emp[25];
   char endereco_cidade_emp[25];
   char endereco_estado_emp[25];	
};

// ==================================================================
/*
ESTRUTURA DOS DADOS - CADASTRO IMOVEL
*/
// ==================================================================

struct CadastroImovel
{
	char rua_imovel[25];
	char bairro_imovel[25];
	char tipo_imovel[25];
	char preco_venda[25];
	char preco_aluguel[25];
	char condicao_imovel[25];
	char tamanho_imovel[25];
};

// ==================================================================
/*
ESTRUTURA DOS DADOS - CADASTRO CLIENTE
*/
// ==================================================================

struct CadastroCliente
{
	char nome_cliente[50];
	char rg_cliente[12];
	char cpf_cliente[12];
	char senha_cliente[12];
	char idade_cliente[3];
    char endereco_rua_cliente[25];
    char endereco_bairro_cliente[25];
    char endereco_cidade_cliente[25];
    char endereco_estado_cliente[25];	
};

// ==================================================================
/*
PROTOTIAÇÃO DOS DADOS - CADASTRO CLIENTE
*/
// ==================================================================

void CadastrarCliente(FILE* Arquivo, CadastroCliente C2[100], int pos);
int IniciarCliente(FILE* Arquivo, CadastroCliente C2[100]);
int EditarCliente(FILE* Arquivo, CadastroCliente C2[100], char cpf_cliente[12], char nome_c[50]);
//void ExcluirCliente(FILE* Arquivo, CadastroCliente C2[100], char *CPF, char *cpf_cliente); 
void MostrarDadosCliente(CadastroCliente C0, int i);
int BuscaDadosCliente(FILE* Arquivo, CadastroCliente C2[100], char CPF[12]);
int LoginCliente(FILE* Arquivo, CadastroCliente C2[100], char cpf_cliente[12], char senha_cliente[12]);

// ==================================================================
/*
PROTOTIAÇÃO DOS DADOS - CADASTRO EMPRESA
*/
// ==================================================================

void CadastrarEmpresa(FILE* Arquivo, CadastroEmpresa Emp2[100], int pos);
int IniciarEmpresa(FILE* Arquivo, CadastroEmpresa Emp2[100]);
void EditarEmpresa(FILE* Arquivo, CadastroEmpresa Emp2[100], char *cnpj, char *CNPJ, char *nome_emp);
void ExcluirEmpresa(FILE* Arquivo, CadastroEmpresa Emp2[100], char *cnpj);
void MostrarDadosEmpresa(CadastroEmpresa Emp0, int i);
int BuscaDadosEmpresa(FILE* Arquivo, CadastroEmpresa Emp2[100], char CNPJ[20]);
int LoginEmpresa(FILE* Arquivo,CadastroEmpresa Emp2[100], char cnpj[20], char senha_emp[20]);

// ==================================================================
/*
PROTOTIAÇÃO DOS DADOS - CADASTRO IMOVEL
*/
// ==================================================================

int IniciarImovel(FILE* Arquivo, CadastroImovel Im2[100]);
void CadastrarImovel(FILE* Arquivo, CadastroImovel Im2[100], int n, int pos);
void MostrarDadosImovel(CadastroImovel Im0, int pos);
int BuscaBairros(FILE* Arquivo, CadastroImovel Im2[100], char bairro_imovel[25], char bairro[25]);
int BuscaDadosImovel(FILE* Arquivo, CadastroImovel Im2[100], char bairro[25]);

// ==================================================================
/*
 MENUS
*/
// ==================================================================

void criaMenuLinhaSuperior();
void criaMenuLinhaRodape(int tamX);
void criaMenuItem(int tamX, char str[]);
void criaMenuLinhaHorizontal(int tamX);
int MenuPrincipal();
int Menu_Cliente();
int MenuClienteOpc();
int MenuCadastroImoveis();
int MenuImoveis();
int Menu_Empresa();
int MenuEmpresaOpc();
#endif
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstring>
#include <locale.h>
#include "gg.h"

using namespace std;
CadastroCliente C[100];
CadastroEmpresa Emp[100];
CadastroImovel Im[100];
FILE* Arq;
int TAM;
//-----------------------------------------------------------------------------
//     FUNÇÃO PARA CRIAR UM ARQUIVO
//-----------------------------------------------------------------------------
void AbrirArquivo(char *NomeArq)
{
 Arq = fopen(NomeArq, "ab");
  if(Arq!=NULL) 
 	printf("\n  Arquivo aberto com sucesso!\n");
  
}
int main(int argc, char** argv)
{ 
  char CPF[12],nome_c[50];
  int Achou=-1;
  int pos=0;
  int Tam;
  int i;
  int opc,opc1, opc2, opc3, opc4, opc5;
  char nome_emp[50], CNPJ[20], senha_cliente[12], senha_emp[20], cpf_cliente[12], cnpj[20], bairro[25], bairro_imovel[25];
IniciarCliente(Arq,C);
opc = MenuPrincipal(); //MENU PRINPIPAL
system("cls");
 if(opc==1){
	 opc1 = Menu_Cliente(); //MENU DE CADASTRO E LOGIN
     TAM=IniciarCliente(Arq,C);
     system("cls");
      if(opc1==1){
  	       AbrirArquivo("DadosCliente.bin");	
    	   CadastrarCliente(Arq,C, TAM);
		   fclose(Arq); 
    }
	  else if(opc1==2){
	  	TAM=IniciarCliente(Arq,C); //INICIAR
	  	AbrirArquivo("DadosCliente.bin");
    	Achou = LoginCliente(Arq, C, cpf_cliente, senha_cliente); //CONFIRMAR LOGIN
    	fclose(Arq);
     		if(Achou == 1){
  			   	do{
					 	system("cls"); 
			    opc2 = MenuClienteOpc(); //MENU DE CLIENTE
  			   	  if(opc2==1){
		   	  	    TAM=IniciarCliente(Arq,C);
		   	  	    printf("INSIRA SEU CPF NOVAMENTE: ");
		   	  	    scanf("%s", &CPF);
  			   	  	pos=BuscaDadosCliente(Arq, C, CPF);
                    MostrarDadosCliente(C[pos], pos); //MOSTRAR DADOS CLIENTE
					   }
					   else if(opc2==2){
						   	  cout<<"\n DIGITE O CPF PARA EDITAR O NOME: ";
	 	   	   	   	    	  cin>>CPF;
	 		  	   	    	  cout<<"\n DIGITE O NOVO NOME: ";
	 		  	   	    	  cin.ignore();
	 	   	   	   	    	  cin.getline(nome_c,50);
	 	   	   	   	    	  EditarCliente(Arq, C, CPF, nome_c);
					   }
					   else if(opc2==3){
					   						   	// TAM=IniciarImovel(Arq, Im); //INICIAR IMOVEL
					   	// printf("\n TESTE DE VALOR DE TAM:%d \n", TAM);
					   	// for(i=0;i<TAM;i++)
					   	// MostrarDadosImovel(Im[pos], pos);			   	
                         opc3 = MenuImoveis(); //MENU DE BUSCA DE IMÓVEIS
						         if(opc3==1){
						       	 TAM=IniciarImovel(Arq, Im);
         	                     strcpy(bairro,"Abolicao");
         	                     pos=BuscaDadosImovel(Arq, Im, bairro);
					  	        // pos=BuscaBairros(Arq, Im, bairro_imovel, bairro);
					  	         printf("IMÓVEIS NA ABOLIÇÃO: \n");
					  	         for(i=0;i<TAM;i++)
		  		     			 MostrarDadosImovel(Im[i], pos);
					  	         fclose(Arq);
								 }
					   	         if(opc3==2){
         						 TAM=IniciarImovel(Arq, Im);
					  	         strcpy(bairro,"Centro");
					  	        // printf("INSIRA O BAIRRO QUE SELECIONOU: ");
					  	        // scanf("%s", &bairro);
					  	        pos=BuscaDadosImovel(Arq, Im, bairro);
					  		    // pos=BuscaBairros(Arq, Im, bairro_imovel, bairro);
					  		     printf("\n IMÓVEIS NO CENTRO: \n");
					  		     for(i=0;i<TAM;i++)
		  		     			 MostrarDadosImovel(Im[i], pos);
					  		     fclose(Arq);
									}
					   	         if(opc3==3){
         						 TAM=IniciarImovel(Arq, Im);
						         strcpy(bairro,"NovaBetania");
						         pos=BuscaDadosImovel(Arq, Im, bairro);
						        // pos=BuscaBairros(Arq, Im, bairro_imovel, bairro);
						         printf("\n IMÓVEIS NA NOVA BETÂNIA: \n");
						         for(i=0;i<TAM;i++)
		  		     			 MostrarDadosImovel(Im[i], pos);
								 fclose(Arq);     
							  }  
						}else if(opc2==4){
							printf("SAINDO DO PROGRAMA !!!");
							return 0;
						} 
						system("pause");	        
            		}	while(opc!=3);
			      }
                }
            }else if(opc==2){ 	       
			   TAM=IniciarEmpresa(Arq,Emp);	
			   system("cls");
			   opc4 = Menu_Empresa(); //MENU DE CADASTRO E LOGIN - EMPRESA
			   if(opc4==1) 
			   {
				 //CADASTRO - EMPRESA
				   	AbrirArquivo("DadosEmpresa.bin");	
				   	CadastrarEmpresa(Arq, Emp, pos);
				   	fclose(Arq);
			   }else if(opc4==2){
                 //LOGIN - EMPRESA
				   	AbrirArquivo("DadosEmpresa.bin");	
		   	        IniciarEmpresa(Arq, Emp); //INICIAR
					Achou = LoginEmpresa(Arq, Emp, CNPJ, senha_emp); //CONFIRMAR LOGIN
					fclose(Arq);
					if(Achou == 1){
  	       		    do{
  	       		    	system("cls");
  	                opc5 = MenuEmpresaOpc(); //MENU DE EMPRESA
  	                    if(opc5==1){
  	                	TAM=IniciarEmpresa(Arq,Emp);
		   	  	    	printf("\nINSIRA SEU CNPJ NOVAMENTE: ");
		   	  	        scanf("%s", &CNPJ);
  			   	  	   	pos=BuscaDadosEmpresa(Arq, Emp, CNPJ);
			   	        MostrarDadosEmpresa(Emp[pos], pos); //MOSTRAR DADOS EMPRESA
						  }
				        else if(opc5==2){
			            //EDITAR
			            AbrirArquivo("DadosEmpresa.bin");	
		  	            IniciarEmpresa(Arq,Emp);
			   	        cout<<"\n DIGITE O CNPJ PARA EDITAR O NOME DA EMPRESA: ";
 	   	   	   	        cin>>CNPJ;
 		  	   	        cout<<"\n DIGITE O NOVO NOME DA EMPRESA: ";
 		  	   	        cin.ignore();
 	   	   	   	        cin.getline(nome_emp,50);
 	   	   	   	   	    EditarEmpresa(Arq, Emp, cnpj, CNPJ, nome_emp);
 	   	   	   	   	    fclose(Arq);
						}
			   	   	    else if(opc5==3){
 			   	    	//REGISTRAR IMÓVEIS
 	    		        int n;
 	    		        AbrirArquivo("DadosImovel.bin");
 	    		        cout<<" \nINSIRA A QUANTIDADE DE IMÓVEIS QUE DESEJA INSERIR ";
 	    		        cin>>n;
 			   	   	    CadastrarImovel(Arq, Im, n, pos);
 			   	   	    fclose(Arq);
					    }
					    else{
               	   	     //SAIR
						}
						system("pause");
			           }while(opc5!=4); 
                    }else{
						printf("REGISTRO INEXISTENTE !!!");
					}
                  }
				}else if(opc == 3){
				printf("SAINDO DO PROGRAMA !!!");
				return 0;
		     }
}
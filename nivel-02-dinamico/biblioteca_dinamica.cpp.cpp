#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define TAM_STR 100
#define MAX_LIV 50
#define MAX_EMP 100

typedef struct {
	
	char titulo[TAM_STR];
	char autor[TAM_STR];
	char editora[TAM_STR];
	int edicao;
	int emprestimo; //1 para emprestado, 0 para disponivel
	
}Livro;

typedef struct {
	
	Livro *livro;
	char nomeUsuario[TAM_STR];
	
}Emprestimo;

int main(){
	
	int resp, cont, totalLivros = 0, totalEmprestimos = 0;
	Livro *biblioteca;
	Emprestimo *emprestimos;
	Livro **disponiveis;
	
	biblioteca = (Livro*) calloc(MAX_LIV, sizeof(Livro));
	emprestimos = (Emprestimo*) malloc(MAX_EMP * sizeof(Emprestimo));
	
	if (biblioteca == NULL || emprestimos == NULL){
		cout << "Erro na alocação de memória!";
		return 1;
	}
	
	do{
		
		cout << endl << "====================" << endl
		<< " BIBLIOTECA PARTE 2" << endl
		<< "====================" << endl;
		
		cout << "1- Cadastrar Livro" << endl
		<< "2- Listar Livros" << endl
		<< "3- Fazer Emprestimo" << endl
		<< "4- Listar Emprestimos" << endl
		<< "0- Sair" << endl << endl;
		
		cout << "Digite a opcao: ";
		cin >> resp;
		cin.ignore();
		
		system("cls");
		
		switch (resp) {
			
			case 1:
				
				cout << endl << "=====================" << endl
				<< "  CADASTRO DE LIVRO" << endl
				<< "=====================" << endl;
				
				cout << "Digite o nome do livro: ";
				cin.getline(biblioteca[totalLivros].titulo, TAM_STR);
				
				cout << "Digite o nome do autor: ";
				cin.getline(biblioteca[totalLivros].autor, TAM_STR);
				
				cout << "Digite a editora: ";
				cin.getline(biblioteca[totalLivros].editora, TAM_STR);
				
				cout << "Digite o numero da edicao: ";
				cin >> biblioteca[totalLivros].edicao;
				
				//O calloc ja deixou o livro como disponivel, pois inicia com valor 0
				
				totalLivros++;
				cout << endl << "Livro cadastrado com sucesso!" << endl;
				
				cout << "Pressione qualquer tecla para continuar...";
				cin.ignore();
				cin.get();
				
				system("cls");
				
				break;
				
			case 2:
				
				if(totalLivros < 1){
					cout << "Erro nenhum livro cadastrado!";
					cout << endl << "Pressione qualquer tecla para voltar...";
					cin.get();
					system("cls");
					break;
				}
				
				cout << endl << "=====================" << endl
				<< "LISTAGEM DE LIVROS" << endl
				<< "=====================" << endl;
				
				for (int i = 0; i < totalLivros; i++){
					
					char disponivel[TAM_STR];
					strcpy(disponivel, biblioteca[i].emprestimo == 0 ? "Disponivel" : "Emprestado");
					
					cout << endl << endl << "LIVRO " << i+1 << endl;
					cout << "Titulo do Livro: " << biblioteca[i].titulo << endl
					<< "Autor do Livro: " << biblioteca[i].autor << endl
					<< "Editora: " << biblioteca[i].editora << endl
					<< "Edicao: " << biblioteca[i].edicao << endl
					<< "Status: " << disponivel;
					
				}
				
				cout << endl << "Pressione qualquer tecla para continuar...";
				cin.get();
				system("cls");
				
				break;
				
			case 3:
				
				int resp2;
				
				if (totalLivros < 1){
					cout << "Erro! Nenhum livro cadastrado!";
					cout << endl <<  "Pressione qualquer tecla para continuar...";
					cin.get();
					system("cls");
					break;
				}
				
				cout << endl << "=====================" << endl
				<< "EMPRESTAR LIVRO" << endl
				<< "=====================" << endl;
				
				cont = 0;
				
				disponiveis = (Livro**) calloc(MAX_LIV, sizeof(Livro*));
				
				for (int i = 0; i < totalLivros; i++){
					if(biblioteca[i].emprestimo == 0){
						
						disponiveis[cont] = &biblioteca[i];
						cont++;
						
					}
				}
				
				cout << "Livros Disponiveis: " << endl;
				
				if (cont < 1){
					cout << "Nenhum livro disponivel no momento!";
					cout << "Pressione qualquer tecla para continuar...";
					cin.get();
					system("cls");
					break;
				} 
				else{
					
					for (int i = 0; i < cont; i++){
						
						cout << i+1 << " - " << disponiveis[i]->titulo << endl;
						
					}
					
					cout << endl << "Digite: ";
					cin >> resp2;
					
					disponiveis[resp2-1]->emprestimo = 1;
					
					emprestimos[totalEmprestimos].livro = disponiveis[resp2-1];
					
					cout << "Nome do usuario: ";
					cin.ignore();
					cin.getline(emprestimos[totalEmprestimos].nomeUsuario, TAM_STR);
					totalEmprestimos++;
					
					cout << "Emprestado com sucesso!";
					
				}
				
				free(disponiveis);
				
				cout << endl << "Pressione qualquer tecla para continuar...";
				cin.get();
				system("cls");
				
				break;
				
			case 4:
				
				if(totalEmprestimos < 1){
					cout << "Erro nenhum emprestimo cadastrado!";
					cout << endl << "Pressione qualquer tecla para voltar...";
					cin.get();
					system("cls");
					break;
				}
				
				cout << endl << "=====================" << endl
				<< "LISTAGEM DE EMPRESTIMOS" << endl
				<< "=====================" << endl;
				
				for (int i = 0; i < totalEmprestimos; i++){
					
					cout << endl << "LIVRO " << i+1 << endl;
					cout << "Titulo do Livro: " << emprestimos[i].livro->titulo << endl;
					cout << "Usuario: " << emprestimos[i].nomeUsuario;
					
				}
				
				cout << endl << "Pressione qualquer tecla para continuar...";
				cin.get();
				system("cls");
				
				break;
				
			case 0:
				
				cout << endl << "Saindo do sistema...";
				break;
				
			
		}
		
	}while (resp != 0);
	
	free(emprestimos);
	free(biblioteca);
	
	return 0;
}

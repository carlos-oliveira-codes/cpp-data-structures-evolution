#include <iostream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

#define TAM_MAX 100
#define TAM_STRING 50

typedef struct {
	
	char titulo[TAM_STRING];
	char autor[TAM_STRING];
	char editora[TAM_STRING];
	int edicao;
	
}Livro;

int main(){
	
	Livro biblioteca[TAM_MAX];
	int resp, totalLivros = 0;
	char nd[TAM_STRING];
	
	do{
		
		cout << endl << endl << "====== BIBLIOTECA ======" << endl;
		cout << "(1) Cadastrar Novo Livro" << endl << "(2) Listar Todos os Livros" << endl << "(0) Sair" << endl << "__________________" << endl << "Escolha uma opcao: ";
		cin >> resp;
		system("cls");
		
		switch (resp) {
			case 1:
				cout << endl << "____ Cadastro de Livros ____" << endl;
				cout << "Digite o titulo do livro: ";
				cin.ignore();
				cin.getline(biblioteca[totalLivros].titulo, TAM_STRING);
				
				cout << "Digite o nome do autor: ";
				cin.getline(biblioteca[totalLivros].autor, TAM_STRING);
				
				cout << "Digite a editora: ";
				cin.getline(biblioteca[totalLivros].editora, TAM_STRING);
				
				cout << "Digite a edicao: ";
				cin >> biblioteca[totalLivros].edicao;
				
				totalLivros++;
				
				cout << "Livro Cadastrado com Sucesso!!!" << endl << endl << "Pressione qualquer tecla para continuar...";
				cin.ignore();
				cin.get();
				system("cls");
				break;
			
			case 2:
				
				if(totalLivros < 1){
					cout << "Nenhum Livro cadastrado..." << endl;
					cout << "Pressione qualquer tecla para continuar...";
					cin.ignore();
					cin.get();
					system("cls");
					break;
				}
				
				cout << "______ Listagem da Biblioteca ______" << endl;
				cout << "----------------------------" << endl ;
				
				for (int i = 0; i < totalLivros; i++){
					cout << "Livro " << i+1 << endl;
					cout << "Titulo: " << biblioteca[i].titulo << endl 
					<< "Autor(a): " << biblioteca[i].autor << endl 
					<< "Editora: " << biblioteca[i].editora << endl 
					<< "Edicao: " << biblioteca[i].edicao;
					cout << endl << "----------------------------" ;
				}
				
				cout << endl << "Pressione qualquer tecla para continuar...";
				cin.ignore();
				cin.get();
				system("cls");
				break;
			
			case 0:
			
				cout << endl << "Saindo do Programa...";
				break;
		}
		
		
		
	}while(resp != 0);
	
	return 0;
}

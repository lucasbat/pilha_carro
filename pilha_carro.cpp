/*

Aula Prática Sobre Pilhas
Estrutura de Dados
Discente: Lucas Batista
23-02-2018

Classe em c++ denominadaCarro com os seguintes dados membros:
Frabricante, proprietario, placa e valor. A classe contem os seguintes metodos: contrutor/destrutor,
metodo para solicitar todos os dados, imprimir todos os dados e metodos para retornar todos os dados individualmente.

A funcao principal cadastra carros enquanto o usuario desejar. Faz uma busca por proprietario e placa.

Utilizando pilha para armazenar os dados.


*/

#include<iostream>
#include<string>
#include<stack>
#include<cstdlib>

using namespace std;

class Carro{
	private:
	string fab, prop, placa, valor;

	public:
	Carro(){};
	~Carro(){};
	void set_dados(){
			system("clear"); //no OS Windows use system("cls");
			cout<<"\n===============================\n";
			cout<<" \tPrograma Pilhas";
			cout<<"\n===============================\n\n";

			cin.ignore();
			cout<<"\nDigite Fabricante: ";
				getline(cin,fab);
			cout<<"\nDigite Proprietario: ";
				getline(cin,prop);
			cout<<"\nDigite Placa: ";
				getline(cin,placa);
			cout<<"\nDigite Valor: ";
				getline(cin,valor);
	}
	void print_dados(){
		cout<<"\nFabricante: "<<fab;
		cout<<"\nDigite Proprietario: "<<prop;
		cout<<"\nDigite Placa: "<<placa;
		cout<<"\nDigite Valor: "<<valor;
	}
	string ret_fab(){
		return fab;
	}
	string ret_prop(){
		return prop;
	}
	string ret_placa(){
		return placa;
	}
	string ret_valor(){
		return valor;
	}
};

void menu(){
	system("clear");
	cout<<"\n===============================\n";
	cout<<" \tPrograma Pilhas";
	cout<<"\n===============================\n";

	cout<<"\t\n< 1 > Cadastro";
	cout<<"\t\n< 2 > Listagem Geral";
	cout<<"\t\n< 3 > Consulta Por Proprietario";
	cout<<"\t\n< 4 > Consulta Por Placa";
	cout<<"\t\n< 5 > SAIR\n\n";
}

int main(){
string pro, pla;
char op, resp; //op sera usado em case 1 e op no case 2
int op_menu;
stack <Carro> X, copia;
Carro Y;
	do{
		menu();
		cin>>op_menu;
			switch(op_menu){
				case 1:
						do{
							Y.set_dados();
							X.push(Y);
							cout<<"Deseja inserir outro <s/n>? ";
							cin>>op;
						}while(op=='s');
						cin.ignore();
				break;

				case 2:
					cout<<"\nListagem Geral\n";
						copia=X;
						do{
								while(!copia.empty()){
									copia.top().print_dados();
									cout<<"\n";
									copia.pop();
								}
						cout<<"\nVoltar ao menu principal <s/n> "; cin>>op;
					}while(op=='n' || op=='N');
				break;

				case 3:
					do{
						cin.ignore();
						cout<<"\nDigite o nome do proprietario: ";
					 	getline(cin,pro);
						copia=X;
						while(!copia.empty()){
							if(copia.top().ret_prop()==pro)
								copia.top().print_dados();
							copia.pop();
							cout<<"\n";
						}
						cout<<"\n\nNova consulta <s/n> ? ";
						cin>>op;
					}while(op=='s' || op=='S');
				break;

				case 4:
				do{
					cin.ignore();
					cout<<"\nDigite a placa: ";
					getline(cin,pla);
					copia=X;
					while(!copia.empty()){
						if(copia.top().ret_placa()==pla)
							copia.top().print_dados();
						copia.pop();
					}
					cout<<"\n\nNova consulta <s/n> ? ";
					cin>>op;
				}while(op=='s' || op=='S');
				break;

				default:
				break;
	 		}
	}while(op_menu!=5);
	return 0;
}

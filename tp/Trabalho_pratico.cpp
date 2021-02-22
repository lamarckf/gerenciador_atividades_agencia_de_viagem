#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
using namespace std;

 struct Tcliente
{
	char idcliente[50]; 
	char nome[200];
	char endereco[200];
	char email[200];
	char telefone[50];
};
//
struct Tdestino
{
	char idestino[50];
	char localidadeinicial[200];
	char localidadefinal[200];
	char pais[200];
	char locaisavisitar[50];
	float custo;
	
};
//
struct Tviagem
{
	char idviagem[50];
	int mes;
	int dia;
	char idestino[50];
	int quantidadedeclienteemviagem;
	char clienteemviagem[300][30];
	
};
//

Tcliente *entradadearquivocliente(int *quanticliente)
{
	ifstream arquivocliente("Banco_de_dados_clientes.txt");
	Tcliente *clientearquivo;
	const int tamanholinha = 300;
	char linha [tamanholinha];
	if(!arquivocliente)
	{
		cerr << "Erro ao abrir o banco de dados, ou banco de dados inexistente." << endl;
		return NULL;
	}
	
	arquivocliente.getline(linha, tamanholinha);
	*quanticliente = atoi(linha);
	clientearquivo = new Tcliente[*quanticliente];
	for (int z=0; z< *quanticliente; ++z)
	{
		arquivocliente.getline(linha, tamanholinha);
		strcpy (clientearquivo[z].idcliente, linha); 
		
		arquivocliente.getline(linha, tamanholinha);
		strcpy (clientearquivo[z].nome, linha); 
		
		arquivocliente.getline(linha, tamanholinha);
		strcpy (clientearquivo[z].endereco, linha); 
		
		arquivocliente.getline(linha, tamanholinha);
		strcpy (clientearquivo[z].email, linha); 
		
		arquivocliente.getline(linha, tamanholinha);
		strcpy (clientearquivo[z].telefone, linha); 
	}
	
	arquivocliente.close();
	return clientearquivo;
}
//
Tdestino *entradadearquivodestino(int *quantidestino)
{
	ifstream arquivodestino("Banco_de_dados_destino.txt");
	Tdestino *destinoarquivo;
	const int tamanholinha = 300;
	char linha [tamanholinha];
	if(!arquivodestino)
	{
		cerr << "Erro ao abrir o banco de dados, ou banco de dados inexistente." << endl;
		return NULL;
	}
	
	arquivodestino.getline(linha, tamanholinha);
	*quantidestino = atoi(linha);
	destinoarquivo = new Tdestino[*quantidestino];
	for (int z=0; z< *quantidestino; ++z)
	{
		arquivodestino.getline(linha, tamanholinha);
		strcpy (destinoarquivo[z].idestino, linha); 
		
		arquivodestino.getline(linha, tamanholinha);
		strcpy (destinoarquivo[z].localidadeinicial, linha); 
		
		arquivodestino.getline(linha, tamanholinha);
		strcpy (destinoarquivo[z].localidadefinal, linha);
		
		arquivodestino.getline(linha, tamanholinha);
		strcpy (destinoarquivo[z].pais, linha); 
		
		arquivodestino.getline(linha, tamanholinha);
		strcpy (destinoarquivo[z].locaisavisitar, linha); 
		
		arquivodestino.getline(linha, tamanholinha);
		destinoarquivo[z].custo =atof(linha); 
	}
	
	arquivodestino.close();
	return destinoarquivo;
}
//
Tviagem *entradadearquivoviagem(int *quantiviagem)
{
	ifstream arquivoviagem("Banco_de_dados_viagem.txt");
	Tviagem *viagemarquivo;
	const int tamanholinha = 300;
	char linha [tamanholinha];
	if(!arquivoviagem)
	{
		cerr << "Erro ao abrir o banco de dados, ou banco de dados inexistente." << endl;
		return NULL;
	}
	
	arquivoviagem.getline(linha, tamanholinha);
	*quantiviagem = atoi(linha);
	viagemarquivo = new Tviagem[*quantiviagem];
	
	for (int z=0; z< *quantiviagem; ++z)
	{
		arquivoviagem.getline(linha, tamanholinha);
		strcpy (viagemarquivo[z].idviagem, linha); 
		
		arquivoviagem.getline(linha, tamanholinha);
		viagemarquivo[z].mes = atoi(linha);
		
		arquivoviagem.getline(linha, tamanholinha);
		viagemarquivo[z].dia = atoi(linha);
		
		arquivoviagem.getline(linha, tamanholinha);
		strcpy (viagemarquivo[z].idestino, linha); 
		
		arquivoviagem.getline(linha, tamanholinha);
		viagemarquivo[z].quantidadedeclienteemviagem = atoi(linha);
		for(int y=0; y <viagemarquivo[z].quantidadedeclienteemviagem; y++)
		{
			arquivoviagem.getline(linha, tamanholinha);
			strcpy (viagemarquivo[z].clienteemviagem[y], linha);
			
		}		
		
	}
	
	arquivoviagem.close();
	return viagemarquivo;
}
//

Tcliente entradadecliente()
{ 
	Tcliente t;
	
	cin.ignore();
	cout << "\nID do cliente.\n";
	cin.getline(t.idcliente, 50);
	cout << "\nNome do cliente.\n";
	cin.getline(t.nome, 200);
	cout << "\nEndereco do cliente.\n";
	cin.getline (t.endereco, 200);
	cout << "\nE-mail do cliente.\n";
	gets (t.email);
	cout << "\nTelefone do cliente.\n";
	gets (t.telefone);
	
	return t;
}
Tdestino entradadedestino ()
{
	Tdestino t;
	cin.ignore();
	cout << "\nEntre com a ID do destino."<<endl;
	cin.getline(t.idestino, 50);
	cout << "\nEntre com a localidade inicial."<< endl << "Como mostra no exemplo sempre com a primeira letra maiuscula(EX.: Ouro Preto)"<<endl ;
	cin.getline (t.localidadeinicial, 200);
	cout << "\nEntre com a localidade final."<< endl;
	cin.getline (t.localidadefinal, 200);
	cout << "\nEntre com o pais."<<endl;
	cin.getline (t.pais, 200);
	cout <<"\nEntre com o numero de locais a visitar." << endl;
	cin.getline  (t.locaisavisitar, 50);
	cout <<"\nEntre com o custo igual o exemplo (ex.: 000.00 )"<<endl;
	cin >>  (t.custo);
	cout<< endl;
	return t;
}


int comparar ( Tcliente cliente1, const Tcliente *cliente2, int clientetamanho )
{
	for ( int z=0; z < clientetamanho; z++ )
	{
		
		if ( strcmp(cliente1.idcliente,cliente2[z].idcliente)==0) 
		{	
			return 1;
		}
	}	
	
	return 0;
}
int comparar1 ( Tcliente cliente1, const Tcliente *cliente2, int clientetamanho )
{
	for ( int z=0; z < clientetamanho; z++ )
	{
		
		if ( strcmp(cliente1.idcliente,cliente2[z].idcliente)==0) 
		{	
			return z;
		}
	}	
	
	return -1;
}
int comparardestino ( Tdestino destino1, const Tdestino *destino2, int destinotamanho )
{
	for ( int z=0; z < destinotamanho; z++ )
	{
		
		if ( strcmp(destino1.idestino,destino2[z].idestino)==0) 
		{	
			return 1;
		}
	}	
	
	return 0;
}


//
int main()
{
	int c,d, z, y, w, x, h;
	int fechar;
	Tcliente *clientes=NULL;
	Tcliente entradacliente;
	Tdestino *destinos=NULL;
	Tdestino entradadestino;
	entradadestino.custo=0;
	Tviagem *viagens=NULL;
	Tviagem entradaviagem;
	entradaviagem.dia =0;
	entradaviagem.mes =0;
	int tamanhocliente=0;
	int tamanhodestino=0;
	int tamanhoviagem=0;
	char const auxconfere[50]="Ouro Preto";
	int za=0;
	float testemenor=0;
	float testemaior=0;
	float testemedio=0;
	float mediacliente=0;
	
	fechar = 10;
	y=0;
	
	
	cout << "-- Seja bem vindo ao plano de viagem 2016 --" << endl;
	
	
	
	while (fechar != 0 )
	{
		clientes = entradadearquivocliente(&tamanhocliente);
		destinos = entradadearquivodestino(&tamanhodestino);
		viagens =entradadearquivoviagem(&tamanhoviagem);
		cout<<  "O que deseja fazer? " << endl<< "(1)Opcao cliente." << endl<< "(2)Opcao destino." << endl;
		cout << "(3)Opcao viagem." << endl <<"(4)Zerar banco de dados."<< endl << "Em caso de erro no banco de dados tente zera-los."<< endl ;
		cin >> c;
		
		switch (c)
		{
			case (1):
			{	
				cout << "(1) Para cadastrar um novo cliente." << endl;
				cout << "(2) Para conferir os dados de um cliente."<< endl <<"(3) Para remover um cliente."<< endl <<"(4) Para ver todos os clientes cadastrados." << endl;
				cout << "(5) Para alterar os dados do cliente." << endl;
				cin >> d;
				switch (d)
				{
					case (1):
					{
						cout << endl <<"Digite os dados do cliente." << endl;
						//
						entradacliente = entradadecliente();
						if (comparar (entradacliente, clientes, tamanhocliente))
						{
							cout <<endl << " Cliente existente." << endl;
						}
						else
						{
							ofstream clientes2;
							clientes2.open("Banco_de_dados_clientes.txt");
							if (clientes2.is_open ())
							{
								
								cout << endl <<"Cliente inserido." << endl;
								clientes2 << 1+tamanhocliente << endl;
								
								for ( z=0; z < tamanhocliente; z++ )
								{									
									clientes2 << clientes[z].idcliente << endl;
									clientes2 << clientes[z].nome <<endl ;
									clientes2 << clientes[z].endereco << endl;
									clientes2 << clientes[z].email <<endl;
									clientes2 << clientes[z].telefone << endl;
				
								}
								clientes2 << entradacliente.idcliente<< endl;
								clientes2 << entradacliente.nome<< endl;
								clientes2 << entradacliente.endereco<< endl;
								clientes2 << entradacliente.email<< endl;
								clientes2 << entradacliente.telefone<< endl;
								
								
								
							}
							else 
							{
								cout << "Erro ao acessar o banco de dados." << endl;
								return 0;
							}
							clientes2.close();
						}
						
						break;	
					}
					//
					case(2):
					{
						cout << "Entre com a id do cliente." << endl;

						cin >> entradacliente.idcliente;
						h =  comparar1 (entradacliente, clientes, tamanhocliente);
						if ( h != -1)
							{
								cout << "ID: "<< clientes[h].idcliente << endl;
								cout << "Nome: "<< clientes[h].nome << endl;
								cout << "Endereco: "<< clientes[h].endereco << endl;
								cout << "e-mail: "<< clientes[h].email << endl;
								cout << "Telefone: "<< clientes[h].telefone << endl;
							}
						
						else
						{
							cout<< endl <<"Cliente inexistente."<< endl <<"Confira se digitou corretamente. " << endl;
						}
						break;
					}
					//
					case(3):
					{
						cout << "Entre com a id do cliente." << endl;
						cin >> entradacliente.idcliente;
						if (comparar (entradacliente, clientes, tamanhocliente))
						{					
							for (z=0; z< tamanhoviagem; z++)
							{	
								for (w=0; w <viagens[z].quantidadedeclienteemviagem; w++)
								{
									if ( strcmp(entradacliente.idcliente, &viagens[z].clienteemviagem[w] )==0)
									{
										cout << "Cliente esta em viagem deseja excluir mesmo assim?"<<endl<<"(1)Para sim"<< endl << "(2)Para nao."<<endl;
										cin >> za;	
										if (za == 2)
										{
											cout <<"Cliente nao foi excluido."<<endl;
											break;
										}
										else if (za != 1 && za!=2)
										{
											cout << "Dados invalidos."<<endl;
											break;
										}
									}

								}
							}
							za=1;
							if(za==1)
							{
								ofstream clientes2;
								clientes2.open("Banco_de_dados_clientes.txt");
								if (clientes2.is_open ())
								{
									cout <<endl << "Cliente excluido." << endl;
									clientes2 << tamanhocliente-1 << endl;
									for ( z=0; z < tamanhocliente; z++ )
									{									
										if( strcmp(entradacliente.idcliente,clientes[z].idcliente)!=0)
										{
											clientes2 << clientes[z].idcliente << endl;
											clientes2 << clientes[z].nome <<endl ;
											clientes2 << clientes[z].endereco << endl;
											clientes2 << clientes[z].email <<endl;
											clientes2 << clientes[z].telefone << endl;
										}
									}
								}
								else 
								{
									cout << "Erro ao acessar o banco de dados." << endl;
									return 0;
								}
								clientes2.close();
								
								break;
							}
							
						}
						else 
						{
							cout <<endl << "Cliente inexistente." << endl<<"Confira se digitou corretamente. " << endl;
							break;
						}
						break;
						
					}
					//
					case (4):
					{
						for ( z=0; z < tamanhocliente; z++ )
						{
							cout << "ID: "<< clientes[z].idcliente << endl;
							cout << "Nome: "<< clientes[z].nome << endl;
							cout << "Endereco: "<< clientes[z].endereco << endl;
							cout << "e-mail: "<< clientes[z].email << endl;
							cout << "Telefone: "<<clientes[z].telefone << endl;
						
						}
						if (tamanhocliente == 0 )
						{
							cout<<"Nenhum cliente cadastrado."<<endl;
						}
						
						break;
					}
					//
					case(5):
					{
						cout << "Entre com a id do cliente." << endl;
						cin >> entradacliente.idcliente;
						
						h =  comparar1 (entradacliente, clientes, tamanhocliente);
						if ( h != -1)
						{
							cout << "Deseja alterar quantos dados? "<<endl;
							cin >>x ;
							w=0;
							while ( w < x )
							{
								cout << endl << "Digite:" << endl << "(1)Para alterar o nome do cliente." << endl << "(2)Para alterar o endereco do cliente."<< endl;
								cout << "(3)Para alterar o email do cliente" << endl << "(4)Para alterar o telefone do cliente."<<endl << "(5)Para sair."<<endl;
								cin >> d;
								switch (d)
								{
									case(1):
									{
										cout << endl << "Entre com o novo nome do cliente." <<endl;
										cin >> clientes[h].nome;
										ofstream clientes2;
										clientes2.open("Banco_de_dados_clientes.txt");
										if (clientes2.is_open ())
										{
											cout <<endl << "Cliente alterado." << endl;
											clientes2 << tamanhocliente << endl;
											for ( z=0; z < tamanhocliente; z++ )
											{									
										
												clientes2 << clientes[z].idcliente << endl;
												clientes2 << clientes[z].nome <<endl ;
												clientes2 << clientes[z].endereco << endl;
												clientes2 << clientes[z].email <<endl;
												clientes2 << clientes[z].telefone << endl;
											}
										}
									
										else 
										{
											cout << "Erro ao acessar o banco de dados." << endl;
											return 0;
										}
										clientes2.close();
										w++;
										break;
									}
									case(2):
									{
										cout << endl << "Entre com o novo endereco do cliente." <<endl;
										cin >> clientes[h].endereco;
										ofstream clientes2;
										clientes2.open("Banco_de_dados_clientes.txt");
										if (clientes2.is_open ())
										{
											cout <<endl << "Cliente alterado." << endl;
											clientes2 << tamanhocliente << endl;
											for ( z=0; z < tamanhocliente; z++ )
											{									
										
												clientes2 << clientes[z].idcliente << endl;
												clientes2 << clientes[z].nome <<endl ;
												clientes2 << clientes[z].endereco << endl;
												clientes2 << clientes[z].email <<endl;
												clientes2 << clientes[z].telefone << endl;
											}
										}
									
										else 
										{
											cout << "Erro ao acessar o banco de dados." << endl;
											return 0;
										}
										clientes2.close();
										w++;
										break;
									}
									case(3):
									{
										cout << endl << "Entre com o novo email do cliente." <<endl;
										cin >> clientes[h].email;
										ofstream clientes2;
										clientes2.open("Banco_de_dados_clientes.txt");
										if (clientes2.is_open ())
										{
											cout <<endl << "Cliente alterado." << endl;
											clientes2 << tamanhocliente<< endl;
											for ( z=0; z < tamanhocliente; z++ )
											{									
										
												clientes2 << clientes[z].idcliente << endl;
												clientes2 << clientes[z].nome <<endl ;
												clientes2 << clientes[z].endereco << endl;
												clientes2 << clientes[z].email <<endl;
												clientes2 << clientes[z].telefone << endl;
											}
										}
									
										else 
										{
											cout << "Erro ao acessar o banco de dados." << endl;
											return 0;
										}
										clientes2.close();
										w++;
										break;
									}
									case(4):
									{
										cout << endl << "Entre com o novo telefone do cliente." <<endl;
										cin >> clientes[h].telefone;
										ofstream clientes2;
										clientes2.open("Banco_de_dados_clientes.txt");
										if (clientes2.is_open ())
										{
											cout <<endl << "Cliente alterado." << endl;
											clientes2 << tamanhocliente<< endl;
											for ( z=0; z < tamanhocliente; z++ )
											{									
										
												clientes2 << clientes[z].idcliente << endl;
												clientes2 << clientes[z].nome <<endl ;
												clientes2 << clientes[z].endereco << endl;
												clientes2 << clientes[z].email <<endl;
												clientes2 << clientes[z].telefone << endl;
											}
										}
									
										else 
										{
											cout << "Erro ao acessar o banco de dados." << endl;
											return 0;
										}
										clientes2.close();
										w++;
										break;
									}
									case (5):
									{
										w=d;
										break;
									}
									
									default:
									{
										cout << endl << "Dados incorretos;" << endl;
										break;
									}
								}
								
							}
							break;
						}
						else
						{
							cout<<"Cliente inexistente.\nConfira se digitou corretamente.\n";
						}						
						break;
					}
					//
					default:
					{
						cout << "Dados incorretos." << endl;
						y =1;
						break;
					}
					
					break;
				}
				break;
			}
			//
			case(2):
			{
				cout <<"(1) Para cadastrar um novo destino." << endl << "(2) Para excluir um destino." << endl << "(3) Para alterar os dados de um destino." << endl ;
				cout <<"(4) Para consultar os dados de um destino." << endl << "(5) Para ver todos os destinos cadastrados." << endl;
				cin >> d;
				switch (d)
				{
					case 1:
					{
						cout << "Digite os dados do destino."<<endl;
						entradadestino = entradadedestino();
						if ( strcmp(entradadestino.localidadeinicial,auxconfere)==0)
						{
							if (comparardestino (entradadestino, destinos, tamanhodestino))
							{
								cout <<endl << "Destino existente." << endl<<"Confira se digitou corretamente. " << endl;
							}
							else
							{
								ofstream destinos2;
								destinos2.open("Banco_de_dados_destino.txt");
								if (destinos2.is_open ())
								{
								
									cout << endl <<"Destino inserido." << endl;
									destinos2 << 1+tamanhodestino << endl;
								
									for ( z=0; z < tamanhodestino; z++ )
									{									
										destinos2 << destinos[z].idestino << endl;
										destinos2 << destinos[z].localidadeinicial <<endl ;
										destinos2 << destinos[z].localidadefinal <<endl ;
										destinos2 << destinos[z].pais << endl;
										destinos2 << destinos[z].locaisavisitar <<endl;
										destinos2 << destinos[z].custo << endl;
									}
									destinos2 << entradadestino.idestino<< endl;
									destinos2 << entradadestino.localidadeinicial<< endl;
									destinos2 << entradadestino.localidadefinal<< endl;
									destinos2 << entradadestino.pais<< endl;
									destinos2 << entradadestino.locaisavisitar<< endl;
									destinos2 << entradadestino.custo<< endl;
								}
								else 
								{
									cout << "Erro ao acessar o banco de dados." << endl;
									return 0;
								}
								destinos2.close();
							}
						}
						else 
						{
							cout << "Percurso invalido."<<endl << "Confira se digitou corretamente."<<endl;
						}
						break;
					}
					case (2):
					{
						cout<< "Entre com a id do destino."<<endl;
						cin >> entradadestino.idestino;
						
						if (comparardestino (entradadestino, destinos, tamanhodestino))
						{
							for (z=0; z<tamanhoviagem; z++)
							{
								if ( strcmp(entradadestino.idestino,viagens[z].idestino) ==0)
								{
									cout << "Destino esta sendo usado em uma viagem deseja excluir mesmo assim?"<<endl<<"(1)Para sim"<< endl << "(2)Para nao."<<endl;
									cin >> za;	
									if (za == 2)
									{
										cout <<"Destino nao foi excluido."<<endl;
										break;
									}
									else if (za != 1 && za!=2)
									{
										cout << "Dados invalidos."<<endl;
										break;
									}
								}
							}
							za=1;
							if (za==1)
							{
								ofstream destinos2;
								destinos2.open("Banco_de_dados_destino.txt");
								if (destinos2.is_open ())
								{
								
									cout << endl <<"Destino excluido." << endl;
									destinos2 << tamanhodestino-1 << endl;
									if( strcmp(entradadestino.idestino,destinos[z].idestino)!=0)
									{
										for ( z=0; z < tamanhodestino; z++ )
										{									
											destinos2 << destinos[z].idestino << endl;
											destinos2 << destinos[z].localidadeinicial <<endl ;
											destinos2 << destinos[z].localidadefinal <<endl ;
											destinos2 << destinos[z].pais << endl;
											destinos2 << destinos[z].locaisavisitar <<endl;
											destinos2 << destinos[z].custo << endl;
										}
									}
									break;	
								}	
								else 
								{
									cout << "Erro ao acessar o banco de dados." << endl;
									return 0;
								}
								destinos2.close();
								break;
							}
						}
						else 
						{
							cout <<endl << "Destino inexistente." << endl<<"Confira se digitou corretamente. " << endl;
						}
						break;						
					}
					case(3):
					{
						cout << "Digite a id do destino."<< endl;
						cin >> entradadestino.idestino; 
						for ( z=0; z < tamanhodestino; z++ )
						{
							
							if ( strcmp(entradadestino.idestino,destinos[z].idestino)==0) 
							{	
								h=2;
								break;
							}
						}	
						if ( h != 2)
						{
							cout<<"Destino inexistente."<< endl <<"Confira se digitou corretamente." << endl;
							break;
						}
						else
						{
							
							cout << "Deseja alterar quantos dados? "<<endl;
							cin >>x ;
							w=0;
							while ( w < x )
							{
								cout <<"(1)Para alterar localidade incial."<<endl << "(2)Para alterar localidade final."<< endl << "(3)Para alterar pais." <<endl;
								cout <<"(4)Para alerar a quantidade de locais a visitar."<<endl <<"(5)Para alterar o custo."<<endl<<"(6)Para sair."<<endl;
								cin >> d;
								switch(d)
								{
									case(1):
									{
										cout <<"Digite o local inicial."<<endl;
										cin.getline (destinos[z].localidadeinicial, 200);
										ofstream destinos2;
										destinos2.open("Banco_de_dados_destino.txt");
										if (destinos2.is_open ())
										{
										
											cout << endl <<"Destino inserido." << endl;
											destinos2 << tamanhodestino << endl;
										
											for ( z=0; z < tamanhodestino; z++ )
											{									
												destinos2 << destinos[z].idestino << endl;
												destinos2 << destinos[z].localidadeinicial <<endl ;
												destinos2 << destinos[z].localidadefinal <<endl ;
												destinos2 << destinos[z].pais << endl;
												destinos2 << destinos[z].locaisavisitar <<endl;
												destinos2 << destinos[z].custo << endl;
											}
										
										}
										else 
										{
											cout << "Erro ao acessar o banco de dados." << endl;
											return 0;
										}
										destinos2.close();
										w++;
										break;
									}
									case(2):
									{
										cout <<"Digite o local final."<<endl;
										cin.getline (destinos[z].localidadefinal, 200);
										ofstream destinos2;
										destinos2.open("Banco_de_dados_destino.txt");
										if (destinos2.is_open ())
										{
										
											cout << endl <<"Destino inserido." << endl;
											destinos2 << tamanhodestino << endl;
										
											for ( z=0; z < tamanhodestino; z++ )
											{									
												destinos2 << destinos[z].idestino << endl;
												destinos2 << destinos[z].localidadeinicial <<endl ;
												destinos2 << destinos[z].localidadefinal <<endl ;
												destinos2 << destinos[z].pais << endl;
												destinos2 << destinos[z].locaisavisitar <<endl;
												destinos2 << destinos[z].custo << endl;
											}
										
										}
										else 
										{
											cout << "Erro ao acessar o banco de dados." << endl;
											return 0;
										}
										destinos2.close();
										w++;
										break;
									}
									case(3):
									{
										cout <<"Digite o pais."<<endl;
										cin.getline (destinos[z].pais, 200);
										ofstream destinos2;
										destinos2.open("Banco_de_dados_destino.txt");
										if (destinos2.is_open ())
										{
										
											cout << endl <<"Destino inserido." << endl;
											destinos2 << tamanhodestino << endl;
										
											for ( z=0; z < tamanhodestino; z++ )
											{									
												destinos2 << destinos[z].idestino << endl;
												destinos2 << destinos[z].localidadeinicial <<endl ;
												destinos2 << destinos[z].localidadefinal <<endl ;
												destinos2 << destinos[z].pais << endl;
												destinos2 << destinos[z].locaisavisitar <<endl;
												destinos2 << destinos[z].custo << endl;
											}
										
										}
										else 
										{
											cout << "Erro ao acessar o banco de dados." << endl;
											return 0;
										}
										destinos2.close();
										w++;
										break;
									}
									case(4):
									{
										cout <<"Digite a quantidade de locais a visitar."<<endl;
										cin.getline  (destinos[z].locaisavisitar, 50);
										ofstream destinos2;
										destinos2.open("Banco_de_dados_destino.txt");
										if (destinos2.is_open ())
										{
										
											cout << endl <<"Destino inserido." << endl;
											destinos2 << tamanhodestino << endl;
										
											for ( z=0; z < tamanhodestino; z++ )
											{									
												destinos2 << destinos[z].idestino << endl;
												destinos2 << destinos[z].localidadeinicial <<endl ;
												destinos2 << destinos[z].localidadefinal <<endl ;
												destinos2 << destinos[z].pais << endl;
												destinos2 << destinos[z].locaisavisitar <<endl;
												destinos2 << destinos[z].custo << endl;
											}
										
										}
										else 
										{
											cout << "Erro ao acessar o banco de dados." << endl;
											return 0;
										}
										destinos2.close();
										w++;
										break;
									}
									case(5):
									{
										cout <<"\nEntre com o custo igual o exemplo (ex.: 000.00 )"<<endl; 
										cin >>  (destinos[z].custo);
										ofstream destinos2;
										destinos2.open("Banco_de_dados_destino.txt");
										if (destinos2.is_open ())
										{
										
											cout << endl <<"Destino inserido." << endl;
											destinos2 << tamanhodestino << endl;
										
											for ( z=0; z < tamanhodestino; z++ )
											{									
												destinos2 << destinos[z].idestino << endl;
												destinos2 << destinos[z].localidadeinicial <<endl ;
												destinos2 << destinos[z].localidadefinal <<endl ;
												destinos2 << destinos[z].pais << endl;
												destinos2 << destinos[z].locaisavisitar <<endl;
												destinos2 << destinos[z].custo << endl;
											}
										
										}
										else 
										{
											cout << "Erro ao acessar o banco de dados." << endl;
											return 0;
										}
										destinos2.close();
										w++;
										break;
									}
									case(6):
									{
										w=x;
										break;
									}
									default:
									{
										cout << endl << "Dados incorretos." << endl;
										break;
									}
								}
							}
							
						}
						
						break;
					}
					case(4):
					{
						cout << "Digite a id do destino."<< endl;
						cin >> entradadestino.idestino; 
						
						for ( z=0; z < tamanhodestino; z++ )
						{
							
							if ( strcmp(entradadestino.idestino,destinos[z].idestino)==0) 
							{	
								h=2;
								break;
							}
						}	
						if ( h != 2)
						{
							cout<<"Destino inexistente."<< endl <<"Confira se digitou corretamente." << endl;
							break;
						}
						else
						{
							cout << "ID: "  << destinos[z].idestino<< endl;
							cout << "Localidade inicial: "  <<destinos[z].localidadeinicial<< endl;
							cout << "Localidade final: "  <<destinos[z].localidadefinal<< endl;
							cout << "Pais: "  <<destinos[z].pais<< endl;
							cout << "Numero de locais a visitar: "  <<destinos[z].locaisavisitar<< endl;
							cout << "Custo: "  <<destinos[z].custo<< endl;
						
						}
						break;
					}
					case (5):
					{
						for (z =0; z<tamanhodestino; z++ )
						{
							cout << "ID: "  <<destinos[z].idestino<< endl;
							cout << "Localidade inicial: "  <<destinos[z].localidadeinicial<< endl;
							cout << "Localidade final: "  <<destinos[z].localidadefinal<< endl;
							cout << "Pais: "  <<destinos[z].pais<< endl;
							cout << "Numero de locais a visitar: "  <<destinos[z].locaisavisitar<< endl;
							cout << "Custo: "  <<destinos[z].custo<< endl;
						
						}
						if (tamanhodestino == 0 )
						{
							cout << "Nenhum destino cadastrado."<<endl;
						}
						break;
					}
					default:
					{
						cout << "Dados incorretos." << endl;
						y =1;
						break;
					}
				
				}
				break;
			}
			
			//
			case (3):
			{
				cout<< "(1)Para criar uma nova viagem."<<endl<<"(2)Para excluir uma viagem."<<endl<<"(3)Para alterar os dados de uma viagem."<<endl;
				cout<< "(4)Para consultar os dados de uma viagem."<<endl<<"(5)Para inscrever um cliente em uma viagem."<<endl<<"(6)Para remover um cliente de uma viagem."<<endl;
				cout<< "(7)Para lista de viagens por data."<<endl<<"(8)Para relatorio das viagens."<<endl <<"SOMENTE E POSSIVEL FAZER VIAGEM SEM ESCALA E SEM VOLTA."<< endl;
				cin >> d;
				switch (d)
				{
					case(1):
					{
						cout << "Entre com uma sequencia de caracteres para a id da viagem."<< endl;
						cin.ignore();
						cin >> entradaviagem.idviagem;
						for (z=0; z< tamanhoviagem; z++)
						{
							if ( strcmp(entradaviagem.idviagem,viagens[z].idviagem) ==0)
							{
								cout << "Viagem existente"<<endl;
								c=10;
								break;
							}
						}
						if (c==10)
						{
							break;
						}
						
						cout << "Entre com o mes da viagem em numerais (de 1 a 12) como no exemplo(Ex.: 1 para janeiro)."<<endl;
						cin >> entradaviagem.mes;
						if (entradaviagem.mes <=0 || entradaviagem.mes >=13)
						{
							cout << "Data inexistente."<<endl;
							break;
						}
						cout << "Entre com o dia da viagem."<<endl;
						cin >> entradaviagem.dia;
						if (entradaviagem.dia <=0 || entradaviagem.dia >=32)
						{
							cout << "Data inexistente."<<endl;
							break;
						}
						cout << "Digite a id do destino."<< endl;
						cin >> entradaviagem.idestino; 
						
						for (z=0; z<tamanhodestino; z++)
						{
							if ( strcmp(entradaviagem.idestino,destinos[z].idestino) ==0)
							{
								c=10;
								break;
							}
						}
						if (c!=10)
						{
							cout << "Destino inexiste."<<endl;
							break;
						}
						int xar =0;
						cout << "Deseja cadastrar um cliente agora?"<<endl <<"(1)Para sim" << endl << "(2)Para nao"<<endl;
						cin >> xar;
						if (xar==1)
						{
							cout << "Entre com o id do cliente."<<endl;
							cin.ignore();
							cin >>  entradacliente.idcliente;
								
							if (comparar (entradacliente, clientes, tamanhocliente))
							{
								
							}
							else
							{
								cout << "Cliente inexistente.";
								break;
							}
							for (z=0; z<tamanhoviagem; z++)
							{
								for (w=0; w<viagens[z].quantidadedeclienteemviagem; w++)
								{
									if ( strcmp(entradacliente.idcliente,&viagens[z].clienteemviagem[w]) ==0)
									{
										if (entradaviagem.mes== viagens[z].mes && entradaviagem.dia== viagens[z].dia)
										{
											cout <<"Cliente indisponivel."<<endl;
											w=100;
											break;
										}
									}
								}
							}	
							
							if(w==100)
							{
								break;
							}
						}
						
						
						ofstream viagem2;
						viagem2.open("Banco_de_dados_viagem.txt");
						if (viagem2.is_open ())
						{
						
							cout << endl <<"Viagem inserida." << endl;
							viagem2 << 1+tamanhoviagem << endl;
						
							for ( z=0; z < tamanhoviagem; z++ )
							{									
								viagem2 << viagens[z].idviagem << endl;
								viagem2 << viagens[z].mes <<endl ;
								viagem2 << viagens[z].dia <<endl ;
								viagem2 << viagens[z].idestino << endl;
								viagem2 << viagens[z].quantidadedeclienteemviagem <<endl;
								for (w=0; w< viagens[z].quantidadedeclienteemviagem; w++ )
								{
									viagem2 << viagens[z].clienteemviagem[w] << endl;
								}
							}
							
							viagem2 <<entradaviagem.idviagem << endl;
							viagem2 <<entradaviagem.mes << endl;
							viagem2 <<entradaviagem.dia << endl;
							viagem2 <<entradaviagem.idestino << endl;
							if (xar ==1)
							{
								entradaviagem.quantidadedeclienteemviagem =1;
								viagem2 <<entradaviagem.quantidadedeclienteemviagem << endl;
								viagem2 << entradacliente.idcliente<< endl;
							}
							else
							{
								entradaviagem.quantidadedeclienteemviagem =0;
								viagem2 <<entradaviagem.quantidadedeclienteemviagem << endl;
							}
						}
						else 
						{
							cout << "Erro ao acessar o banco de dados." << endl;
							return 0;
						}
						viagem2.close();
						
						break;
					}
					case(2):
					{
						cout << "Entre com o id da viagem"<<endl;
						cin >>entradaviagem.idviagem;
						for (z=0;z<tamanhoviagem; z++)
						{
							if (strcmp(entradaviagem.idviagem,viagens[z].idviagem) ==0)
							{
								c=15;
							}
						}
						if (c==15)
						{
							ofstream viagem2;
							viagem2.open("Banco_de_dados_viagem.txt");
							if (viagem2.is_open ())
							{
							
								cout << endl <<"Viagem excluida." << endl;
								viagem2 << tamanhoviagem -1 << endl;
							
								for ( z=0; z < tamanhoviagem; z++ )
								{	
									if (strcmp(entradaviagem.idviagem,viagens[z].idviagem) !=0)
									{
										viagem2 << viagens[z].idviagem << endl;
										viagem2 << viagens[z].mes <<endl ;
										viagem2 << viagens[z].dia <<endl ;
										viagem2 << viagens[z].idestino << endl;
										viagem2 << viagens[z].quantidadedeclienteemviagem <<endl;
										for (w=0; w< viagens[z].quantidadedeclienteemviagem; w++ )
										{
											viagem2 << viagens[z].clienteemviagem[w] << endl;
										}
									}
								}
								
								
							}
							else 
							{
								cout << "Erro ao acessar o banco de dados." << endl;
								return 0;
							}
							viagem2.close();
							
							break;
						}
						else 
						{
							cout << "Viagem inexiste."<<endl;
							break;
						}
					}
					case (3):
					{
						cout << "Entre com o id da viagem"<<endl;
						cin >>entradaviagem.idviagem;
						for (z=0;z<tamanhoviagem; z++)
						{
							if (strcmp(entradaviagem.idviagem,viagens[z].idviagem) ==0)
							{
								c=20;
								break;
							}
						}
						if(c==20)
						{
							d=0;
							w=1;
							while (d < w )
							{
								cout << "(1)Para alterar o mes"<< endl<< "(2)Para alterar o dia"<<endl<<"(3)Para alterar a id do destino"<<endl;
								cin.ignore();
								cin >> x;
								switch(x)
								{
									case(1):
									{
										cout << "Digite o novo mes."<<endl;
										cin >> entradaviagem.mes;						
										if (entradaviagem.mes>=1 && entradaviagem.mes <=12)
										{
											viagens[z].mes=entradaviagem.mes;
											ofstream viagem2;
											viagem2.open("Banco_de_dados_viagem.txt");
											if (viagem2.is_open ())
											{
											
												cout << endl <<"Viagem alterada." << endl;
												viagem2 << tamanhoviagem << endl;
											
												for ( z=0; z < tamanhoviagem; z++ )
												{	
													
													viagem2 << viagens[z].idviagem << endl;
													viagem2 << viagens[z].mes <<endl ;
													viagem2 << viagens[z].dia <<endl ;
													viagem2 << viagens[z].idestino << endl;
													viagem2 << viagens[z].quantidadedeclienteemviagem <<endl;
													for (w=0; w< viagens[z].quantidadedeclienteemviagem; w++ )
													{
														viagem2 << viagens[z].clienteemviagem[w] << endl;
													}
													
												}
												
												
											}
											else 
											{
												cout << "Erro ao acessar o banco de dados." << endl;
												return 0;
											}
											viagem2.close();
											
											d++;
										}
										else
										{
											cout << "Datas inexistentes."<<endl;
										}
										break;
									}
									case(2):
									{
										cout << "Digite o novo dia."<<endl;
										cin >> entradaviagem.dia;			
										if (entradaviagem.dia>=1 && entradaviagem.dia<=31)
										{
											viagens[z].dia=entradaviagem.dia;
											ofstream viagem2;
											viagem2.open("Banco_de_dados_viagem.txt");
											if (viagem2.is_open ())
											{
											
												cout << endl <<"Viagem alterada." << endl;
												viagem2 << tamanhoviagem << endl;
											
												for ( z=0; z < tamanhoviagem; z++ )
												{	
													
													viagem2 << viagens[z].idviagem << endl;
													viagem2 << viagens[z].mes <<endl ;
													viagem2 << viagens[z].dia <<endl ;
													viagem2 << viagens[z].idestino << endl;
													viagem2 << viagens[z].quantidadedeclienteemviagem <<endl;
													for (y=0; w< viagens[z].quantidadedeclienteemviagem; w++ )
													{
														viagem2 << viagens[z].clienteemviagem[y] << endl;
													}
													
												}
												
												
											}
											else 
											{
												cout << "Erro ao acessar o banco de dados." << endl;
												return 0;
											}
											viagem2.close();
											d++;
											
										}
										else 
										{
											cout << "Datas inexistentes."<<endl;
										}
										
									}
									case (3):
									{
										int b=0;
										cout << "Digite o novo destino."<<endl;
										cin.ignore();
										cin.getline(entradaviagem.idestino, 50);										
										for (y=0; y<tamanhodestino; y++)
										{
											if ( strcmp(entradaviagem.idestino,destinos[z].idestino) ==0)
											{
												b = 40;
											}
										}
										if (b==40)
										{
											strcpy (viagens[z].idestino,entradaviagem.idestino);
											ofstream viagem2;
											viagem2.open("Banco_de_dados_viagem.txt");
											if (viagem2.is_open ())
											{
											
												cout << endl <<"Viagem alterada." << endl;
												viagem2 << tamanhoviagem << endl;
											
												for ( z=0; z < tamanhoviagem; z++ )
												{	
													
													viagem2 << viagens[z].idviagem << endl;
													viagem2 << viagens[z].mes <<endl ;
													viagem2 << viagens[z].dia <<endl ;
													viagem2 << viagens[z].idestino << endl;
													viagem2 << viagens[z].quantidadedeclienteemviagem <<endl;
													for (y=0; y< viagens[z].quantidadedeclienteemviagem; y++ )
													{
														viagem2 << viagens[z].clienteemviagem[y] << endl;
													}
													
												}
												
												
											}
											else 
											{
												cout << "Erro ao acessar o banco de dados." << endl;
												return 0;
											}
											viagem2.close();
											
											d++;
										}
										else
										{
											cout <<"Destino invalido."<<endl;
											
										}
										break;
									}
									default:
									{
										cout << "Dados incorretos." << endl;
									}
									break;
								}
							}
							
						}
						else 
						{
							cout << "Viagem inexistente."<<endl;
							break;
						}
						y=0;
						break;
					}
					case(4):
					{
						cout << "Entre com o id da viagem."<<endl;
						cin >> entradaviagem.idviagem;
						for (z=0; z< tamanhoviagem; z++)
						{
							if (strcmp(entradaviagem.idviagem,viagens[z].idviagem) ==0)
							{
								c=20;
								break;
							}
						}
						if (c==20)
						{
							cout <<"Id da viagem " <<viagens[z].idviagem << endl;
							cout <<"Mes "<<viagens[z].mes<< endl;
							cout << "Dia "<<viagens[z].dia<< endl;
							cout << "Id destino "<<viagens[z].idestino<<endl;
							cout << "Ha "<< viagens[z].quantidadedeclienteemviagem << " clientes nesta viagem."<<endl;
							for (w=0; w<viagens[z].quantidadedeclienteemviagem; w++ )
							{
								cout << "Cliente " << w+1 << " = " << viagens[z].clienteemviagem[w] << endl;
							}
							break;
						}
						else 
						{
							cout << "Viagem inexistente."<<endl;
							break;
						}
						break;
					}
					case (5):
					{
						cout << "Entre com o id da viagem."<<endl;
						cin >> entradaviagem.idviagem;
						for (z=0; z< tamanhoviagem; z++)
						{
							if (strcmp(entradaviagem.idviagem,viagens[z].idviagem) ==0)
							{
								c=20;
								break;
							}
							
						}
						if (c==20)
						{
							cout << "Entre com o id do cliente" << endl;
							cin >>entradacliente.idcliente;
							if (comparar (entradacliente, clientes, tamanhocliente))
							{
								for (z=0; z<tamanhoviagem; z++)
								{
									for(w=0;w<viagens[z].quantidadedeclienteemviagem; w++)
									{
										if ( strcmp(entradacliente.idcliente,&viagens[z].clienteemviagem[w]) ==0)
										{
											if (entradaviagem.mes== viagens[z].mes && entradaviagem.dia== viagens[z].dia)
											{
												cout <<"Cliente indisponivel."<<endl;
												w=100;
												break;
											}
										}
									}
									if (w==100)
									{
										break;
									}
								}
								if (w==100)
								{
									break;
								}
							}
							else
							{
								cout << "Cliente inexistente.";
								break;
							}
							
							ofstream viagem2;
							viagem2.open("Banco_de_dados_viagem.txt");
							if (viagem2.is_open ())
							{
							
								cout << endl <<"Cliente inserido." << endl;
								viagem2 << tamanhoviagem << endl;
							
								for ( z=0; z < tamanhoviagem; z++ )
								{	
									if (strcmp(entradaviagem.idviagem,viagens[z].idviagem) !=0)
									{
										viagem2 << viagens[z].idviagem << endl;
										viagem2 << viagens[z].mes <<endl ;
										viagem2 << viagens[z].dia <<endl ;
										viagem2 << viagens[z].idestino << endl;
										viagem2 << viagens[z].quantidadedeclienteemviagem <<endl;
										for (w=0; w< viagens[z].quantidadedeclienteemviagem; w++ )
										{
											viagem2 << viagens[z].clienteemviagem[w] << endl;
										}
									}
								}
								for ( z=0; z < tamanhoviagem; z++ )
								{	
									if (strcmp(entradaviagem.idviagem,viagens[z].idviagem) ==0)
									{
										viagem2 << viagens[z].idviagem << endl;
										viagem2 << viagens[z].mes <<endl ;
										viagem2 << viagens[z].dia <<endl ;
										viagem2 << viagens[z].idestino << endl;
										viagem2 << viagens[z].quantidadedeclienteemviagem + 1 <<endl;
										for (w=0; w< viagens[z].quantidadedeclienteemviagem; w++ )
										{
											viagem2 << viagens[z].clienteemviagem[w] << endl;
										}
										viagem2 <<entradacliente.idcliente<<endl;
									}
								}
								
							}
							else 
							{
								cout << "Erro ao acessar o banco de dados." << endl;
								return 0;
							}
							viagem2.close();
						
							
							break;
						}
						else
						{
							cout << "Viagem inexistente."<<endl;
							break;
						}
					}
					
					case (6):
					{
						cout << "Entre com o id da viagem."<<endl;
						cin >> entradaviagem.idviagem;
						for (z=0; z< tamanhoviagem; z++)
						{
							if (strcmp(entradaviagem.idviagem,viagens[z].idviagem) ==0)
							{
								c=20;
								break;
							}
						}
						if (c==20)
						{
							cout << "Entre com o id do cliente" << endl;
							cin.ignore();
							cin >>entradacliente.idcliente;
							for(w=0; w<viagens[z].quantidadedeclienteemviagem; w++)
							{
								if ( strcmp(entradacliente.idcliente,&viagens[z].clienteemviagem[w]) ==0)
								{
									y=300;
									for (w=w; w<viagens[z].quantidadedeclienteemviagem; w++)
									{
										strcpy(&viagens[z].clienteemviagem[w],&viagens[z].clienteemviagem[w+1]) ;
									}
									viagens[z].quantidadedeclienteemviagem-=1;
									break;
								}
							}
						}
						if (y==300)
						{
							ofstream viagem2;
							viagem2.open("Banco_de_dados_viagem.txt");
							if (viagem2.is_open ())
							{
							
								cout << endl <<"Cliente removido." << endl;
								viagem2 << tamanhoviagem << endl;
							
								for ( z=0; z < tamanhoviagem; z++ )
								{	
									viagem2 << viagens[z].idviagem << endl;
									viagem2 << viagens[z].mes <<endl ;
									viagem2 << viagens[z].dia <<endl ;
									viagem2 << viagens[z].idestino << endl;
									viagem2 << viagens[z].quantidadedeclienteemviagem <<endl;
									for (w=0; w< viagens[z].quantidadedeclienteemviagem; w++ )
									{
										viagem2 << viagens[z].clienteemviagem[w] << endl;
									}
								}
								
							}
							else 
							{
								cout << "Erro ao acessar o banco de dados." << endl;
								return 0;
							}
							viagem2.close();
							
							y=0;
							break;
						}
						else 
						{
							cout <<"Cliente inexistente." <<endl;
							break;
						}
						break;
						
					}
					case (7):
					{
						if (tamanhoviagem == 0)
						{
							cout << "Nao ha viagens cadastradas"<<endl;
						}
						else
						{
							int b=0;
							
							for (w=0; w < 12; w++)
							{
								for (y=0; y <= 31; y++)
								{
									for (z=0; z<tamanhoviagem; z++ )
									{
										if(viagens[z].mes == w)
										{
											if (viagens[z].dia==y)
											{
												cout <<"Id da viagem " <<viagens[z].idviagem << endl;
												cout <<"Mes "<<viagens[z].mes<< endl;
												cout << "Dia "<<viagens[z].dia<< endl;
												cout << "Id destino "<<viagens[z].idestino<<endl;
												cout << "Ha "<< viagens[z].quantidadedeclienteemviagem << " clientes nesta viagem."<<endl;
												for (b=0; b<viagens[z].quantidadedeclienteemviagem; b++ )
												{
													cout << "Cliente " << b+1 << " = " << viagens[z].clienteemviagem[b] <<"." << endl;
												}
												cout <<endl;
											}
										}									
									}
								}
								
							}
							y=0;
							break;
						}
						break;
					}
					case(8):
					{
						cout <<"Ha " << tamanhoviagem << " viagens cadastradas. " << endl;
						if(tamanhoviagem!=0)
						{
							testemenor = 100000000;
							testemaior = 0;
						}
						for (z=0; z<tamanhoviagem; z++)
						{
							for (w=0; w<tamanhodestino; w++)
							{
								if ( strcmp(viagens[z].idestino, destinos[w].idestino) ==0) 
								{
									if(testemenor>= destinos[w].custo)
									{
										testemenor = destinos[w].custo;
									}
								}
							}
						}
						cout<< fixed<< setprecision(2) <<"O menor valor de viagem e: R$ "<< testemenor<< "." <<endl;
						
						for (z=0; z<tamanhoviagem; z++)
						{
							for (w=0; w<tamanhodestino; w++)
							{
								if ( strcmp(viagens[z].idestino, destinos[w].idestino) ==0) 
								{
									if(testemaior<= destinos[w].custo)
									{
										testemaior = destinos[w].custo;
									}
								}
							}
						}
						
						cout<< fixed<< setprecision(2) <<"O maior valor de viagem e: R$ "<< testemaior << "." <<endl;
						
						for (z=0; z<tamanhoviagem; z++)
						{
							for (w=0; w<tamanhodestino; w++)
							{
								if ( strcmp(viagens[z].idestino, destinos[w].idestino) ==0) 
								{
									testemedio += destinos[w].custo;
									
								}
							}
						}
						testemedio= testemedio/tamanhoviagem;
						cout<< fixed<< setprecision(2) <<"O valor medio das viagens e: R$ "<< testemedio << "." <<endl;
						
						cout << "Numero total de clientes: " << tamanhocliente <<"." <<endl;
						for(z=0; z<tamanhoviagem; z++)
						{
							mediacliente+= viagens[z].quantidadedeclienteemviagem;
						}
						mediacliente= mediacliente/tamanhoviagem;
						cout<< fixed<< setprecision(2) <<"Numero medio de clientes em viagem: "<< mediacliente << "."<<endl;
						break;
					}
					//
					default:
					{
						cout << "Dados incorretos." << endl;
						y =1;
						break;
					}
					//
				}
				break;
			}
			//
			case(4):
			{
				cout << "(1)Para zerar o banco de dados de clientes"<<endl<< "(2)Para zerar o banco de dados de destino"<<endl<< "(3)Para zerar o banco de dados de viagem"<<endl<< "(4)Para zerar todos os bancos de dados"<<endl;
				cin >> d;
				switch(d)
				{
					case (1):
					{
						ofstream clientes2;
						clientes2.open("Banco_de_dados_clientes.txt");
						clientes2.close();
						cout << "Banco de dados de clientes foi excluido."<< endl;
						break;
					}
					case(2):
					{
						ofstream destinos2;
						destinos2.open("Banco_de_dados_destino.txt");
						destinos2.close();
						cout <<"Banco de dados de destino foi excluido."<< endl;
						break;
					}
					case(3):
					{
						ofstream viagem2;
						viagem2.open("Banco_de_dados_viagem.txt");
						viagem2.close();
						cout <<"Banco de dados de viagem foi excluido."<< endl;
						break;
					}
					
					case(4):
					{
						ofstream clientes2;
						clientes2.open("Banco_de_dados_clientes.txt");
						clientes2.close();
						
						ofstream destinos2;
						destinos2.open("Banco_de_dados_destino.txt");
						destinos2.close();
					
					
						ofstream viagem2;
						viagem2.open("Banco_de_dados_viagem.txt");
						viagem2.close();
						cout <<"Todos os banco de dados foram excluidos."<<endl;
						break;
					}
					default:
					{
						cout << "Dados incorretos." << endl ;
						y=1;
						break;
					}
					
				}
				break;
			}
			//
			default:
			{
				cout << "Dados incorretos." << endl ;
				y=1;
				break;
			}
			//
		}
		
		fechar =100;
		delete [] clientes;
		delete [] destinos;
		delete [] viagens;
		
		if (y!=1)
		{
			while (fechar != 0 && fechar !=1)
			{
				cout << endl << "Deseja fechar o programa?" << endl<<"(0)Para sim." << endl <<"(1)Para nao." << endl;
				cin >> fechar;
				if (fechar!=1 && fechar!=0)
				{
					cout << "Dados incorretos." << endl ; 
				}
			}
		}
	}
	
	
	return 0;
}
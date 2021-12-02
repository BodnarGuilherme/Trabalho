#include <iostream>
#include <fstream>


// Estrutura de Aluno
struct Aluno {
	std::string nome;
	std::string matricula;
	float aep1;
	float prova1;
	float aep2;
	float prova2;
	float sub;
	float media;
	std::string status;
} typedef Aluno;

// Estrutura de alunos na memoria (array de Aluno)
Aluno alunos[100];

/**
* Esta fun��o � chamada para exibir o menu
* na tela do usu�rio e retornar a op��o 
* selecionada
* retorna o char digitada pelo usu�rio
*/
char menu ();

/*
* Esta fun��o ir� realizar a leitura do arquivo
* com as informa��es e converter o texto
* para a estrutura em memoria dos alunos
*/
bool realizaLeituraArquivo();

/**
* Esta fun��o � chamada para permitir 
* o cadastro de um Aluno, retorna
* true caso o cadastro tenha ocorrido com sucesso
* ou false caso acontecer um problema
*/
bool cadastraAluno (Aluno);

/**
* Esta fun��o esta sendo usada
* para teste do "esqueleto do projeto"
*/
void teste ();

#include "funcoes.h"

char menu () {	
	char escolha = ' ';
	std::cout << "\n==============================";
	std::cout << "\n=======PROJETO FINAL==========";
	std::cout << "\n==============================";
	std::cout << "\n==SELECIONE UMA OPCAO ABAIXO==";
	std::cout << "\n=========DIGITE A LETRA=======";
	std::cout << "\n==========T - TESTE===========";
	std::cout << "\n==========L - LEITURA===========";
	std::cout << "\n==========F - FINALIZA========\n";
	std::cin >> escolha;
	system("cls");
	return escolha;
}

bool cadastraAluno (Aluno aluno) {
	std::ofstream arquivo;
	arquivo.open("database.csv", std::fstream::app);
	
	if (!arquivo.is_open()) {
		std::cout << "Houve um erro ao abrir o arquivo!\n";
		return false;	
	}
	
	arquivo << aluno.nome << ";" 
			<< aluno.matricula << ";"
			<< aluno.aep1 << ";"
			<< aluno.prova1 << ";"
			<< aluno.aep2 << ";"
			<< aluno.prova2 << ";"
			<< aluno.sub << ";"
			<< aluno.media << ";"
			<< aluno.status << "\n";
	
	arquivo.close();
	return true;
}


bool realizaLeituraArquivo () {
	std::ifstream arquivo;
	arquivo.open("database.csv");
	if (!arquivo.is_open()) {
		std::cout << "Houve um erro ao abrir o arquivo!\n";
		return false;	
	}
	
	std::string linha;
	int indexAluno = 0;
	while (std::getline(arquivo, linha)) {
//		std::cout << linha << "\n"; string == array char
		int coluna = 0;
		int controleColuna = 0;
		std::string conteudo = "";
		for (int i = 0; i < linha.size(); i++) {
			if (coluna == 1 && controleColuna == 0)  {
				alunos[indexAluno].nome = conteudo;	
				conteudo = "";
				controleColuna = 1;
			} else if (coluna == 2 && controleColuna == 1) {
				alunos[indexAluno].matricula = conteudo;	
				conteudo = "";
				controleColuna = 2;
			}
			if (linha[i] == ';') {
				coluna++;				
				continue;
			}
			conteudo.push_back(linha[i]);					
		}
		indexAluno++;
	}
	arquivo.close();
	
	// teste
	for (int i = 0; i < 100; i++) {
		std::cout << "Aluno n " << i+1 << "\n";
		std::cout << "Nome: " << alunos[i].nome << "\n";
		std::cout << "Matricula: " << alunos[i].matricula << "\n";
	}
	
	return true;
}

void teste () {
	Aluno alunoTeste;
	alunoTeste.nome = "Aluno Teste";
	alunoTeste.matricula = "1234";
	alunoTeste.aep1 = 1.3;
	alunoTeste.prova1 = 5.2;
	alunoTeste.aep2 = 1.8;
	alunoTeste.prova2 = 6.2;
	alunoTeste.media = 0;
	alunoTeste.sub = 0;
	alunoTeste.status = "nao calculado";
	
	if (cadastraAluno (alunoTeste)) {
		std::cout << "Aluno teste cadastrado\n";
	} else {
		std::cout << "Erro ao cadastrar aluno teste\n";
	}
}

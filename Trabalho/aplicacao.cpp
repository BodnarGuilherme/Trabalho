#include "funcoes.cpp"

int main () {
	char opcao = ' ';
	do {
	   opcao = menu();	
	   switch (opcao) {
	   		case 'T':
	   			teste();
	   		break;
	   		case 'L':
	   			realizaLeituraArquivo();
	   		break;
	   		case 'F':
	   			std::cout << "Finalizando aplicacao...\n";
	   		break;
	   		// demais funcoes deverão ser chamadas aqui
	   		default:
	   			std::cout << "Opcao invalida\n Tente Novamente!\n";
	   }
	} while(opcao != 'F');	
}

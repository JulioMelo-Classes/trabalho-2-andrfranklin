#include "../include/canaltexto.h"

using namespace std;


/*! 
* Construtor para a classe CanalTexto
* @param string nome
*/
CanalTexto::CanalTexto(string nome_){
	nome = nome_;
}

/*! 
* método que devolve o nome do CanalTexto
* @return nome do CanalTexto
*/
string CanalTexto::getNome(){
	return nome;
}
#include "../include/canaltexto.h"
#include "../include/mensagem.h"
#include "../include/usuario.h"

using namespace std;

/*! 
* Construtor para a classe CanalTexto
* @param string nome
*/
CanalTexto::CanalTexto(string nome_)
{
	nome = nome_;
}

/*! 
* método que devolve o nome do CanalTexto
* @return nome do CanalTexto
*/
string CanalTexto::getNome()
{
	return nome;
}

/*! 
* Adiciona mensagem em um canal de texto
* @param Mensagem Um objeto do tipo mensagem
*/
void CanalTexto::adicionaMensagem(Mensagem m){
	mensagens.push_back(m);
}

/*! 
* Adiciona mensagem em um canal de texto
* @param string Um nome do canal de texto
* @param Mensagem Um objeto do tipo mensagem
*/
string CanalTexto::listaMensagens(vector<Usuario> usuarios){
	string result = "";
	int count  = 0;
	for (auto it = mensagens.begin(); it != mensagens.end(); it++)
	{
		string nome = "";
		for (auto itU = usuarios.begin(); itU != usuarios.end(); itU++)
		{
			if(it->enviadaPor == itU->getId()){
				nome = itU->nome;
			}
		}
		
		result += nome + "<" + it->datahora + ">" + it->conteudo;
		count++;
	}
	
	if(count == 0){
		return "Sem mensagens para exibir";
	}

	return result;
}
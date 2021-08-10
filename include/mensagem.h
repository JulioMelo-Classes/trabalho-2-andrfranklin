#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <string>

class Mensagem
{
	/*
		TODO implementação dos atributos e métodos
	*/

	/*! 
 	 * atributos públicos da classe Mensagem
	 */
	public:
		std::string datahora;
		int enviadaPor;
		std::string conteudo;

	public:
	/*! 
 	 	 * Construtor para a classe Mensagem
		 * @param id do usuário que envia a mensagem
		 * @param string mensagem com o texto da mensagem
	 	 */
		Mensagem(int id, std::string mensagem);
};

#endif

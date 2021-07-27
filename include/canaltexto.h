#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include <vector>
#include <string>

#include "mensagem.h"


class CanalTexto{
	/*
		TODO implementação dos atributos e métodos
	*/

	/*! 
 	 * atributos privados da classe CanalTexto
	 */
	private:
		std::string nome;
		std::vector<Mensagem> mensagens;

	public:
		/*! 
 	 	 * Construtor para a classe CanalTexto
		 * @param string nome
	 	 */
		CanalTexto(std::string nome_){
			nome = nome_;
		}

		/*! 
 	 	 * método que devolve o nome do CanalTexto
		 * @return nome do CanalTexto
	 	 */
		std::string getNome(){
			return nome;
		}

};

#endif

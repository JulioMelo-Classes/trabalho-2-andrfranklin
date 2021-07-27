#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include <vector>
#include <string>

#include "mensagem.h"


class CanalTexto{
	/*
		TODO implementação dos atributos e métodos
	*/
	private:
		std::string nome;
		std::vector<Mensagem> mensagens;

	public:
		CanalTexto(std::string nome_){
			nome = nome_;
		}

		std::string getNome(){
			return nome;
		}

};

#endif

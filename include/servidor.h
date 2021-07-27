#ifndef SERVIDOR_H
#define SERVIDOR_H

#include<vector>
#include<string>
#include<iostream>


#include "canaltexto.h"

class Servidor{
	/*
		TODO implementação dos atributos e métodos
	*/

	private:
		int usuarioDonoId;
		std::string nome;
		std::string descricao;
		std::string codigoConvite;
		std::vector<CanalTexto> canaisTexto;
		std::vector<int> participantesIDs;

	public:
		Servidor(int id, std::string nome_){
			usuarioDonoId = id,
			nome = nome_;
		}

		int getUsuarioDonoId(){
			return usuarioDonoId;
		}

		void setNome(std::string nome_){
			nome = nome_;
		}

		std::string getNome(){
			return nome;
		}

		void setDescricao(std::string desc){
			descricao = desc;
		}

		std::string getDescricao(){
			return descricao;
		}

		void setCodigoConvite(std::string code){
			codigoConvite = code;
		}

		std::string getCodigoConvite(){
			return codigoConvite;
		}

		void addCanal(CanalTexto canal){
			canaisTexto.push_back(canal);
		}

		void listaCanais(){
			for(CanalTexto c : this->canaisTexto){
				std::cout<< c.getNome() << std::endl;
			}
		}

		bool verificaID(int id){
			for(auto it = this->participantesIDs.begin(); it != this->participantesIDs.end(); it++){
				if(*it == id){
					return true;
				}
			}

			return false;
		}

};

#endif

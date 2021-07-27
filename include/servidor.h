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


	/*! 
 	 * atributos privados da classe Servidor
	 */
	private:
		int usuarioDonoId;
		std::string nome;
		std::string descricao;
		std::string codigoConvite;
		std::vector<CanalTexto> canaisTexto;
		std::vector<int> participantesIDs;

	/*! 
 	 * atributos públicos da classe Servidor
	 */
	public:

		/*! 
 	 	 * Construtor para a classe Servidor
		 * @param int id que representa o id do usuário dono so servidor
		 * @param int nome que indica o nome do servidor
	 	 */
		Servidor(int id, std::string nome_){
			usuarioDonoId = id,
			nome = nome_;
		}


		/*! 
 	 	 * Método que retorna o id do usuário dono do servidor
		 * @return int com o id do usuário dono do servidor
	 	 */
		int getUsuarioDonoId(){
			return usuarioDonoId;
		}

		/*! 
 	 	 * Método muda o nome do servidor
		 * @param string nome que indica o novo nome
	 	 */
		void setNome(std::string nome_){
			nome = nome_;
		}

		/*! 
 	 	 * Método que retorna o nome do servidor
		 * @return string com o nome do servidor
	 	 */
		std::string getNome(){
			return nome;
		}

		/*! 
 	 	 * Método muda a descricao do servidor
		 * @param string desc que indica a nova descricao
	 	 */
		void setDescricao(std::string desc){
			descricao = desc;
		}

		/*! 
 	 	 * Método que retorna a descricao do servidor
		 * @return string com a descricao do servidor
	 	 */
		std::string getDescricao(){
			return descricao;
		}

		/*! 
 	 	 * Método muda o código de convite do servidor
		 * @param string code que indica o novo código de convite
	 	 */
		void setCodigoConvite(std::string code){
			codigoConvite = code;
		}

		/*! 
 	 	 * Método que retorna o codigo de convite do servidor
		 * @return string com o codigo de convite do servidor
	 	 */
		std::string getCodigoConvite(){
			return codigoConvite;
		}

		/*! 
 	 	 * Método que adiciona um novo canal de texto ao servidor
		 * @param objeto CanalTexto canal que indica o novo canal a ser adionado
	 	 */
		void addCanal(CanalTexto canal){
			this->canaisTexto.push_back(canal);
		}

		/*! 
 	 	 * Método que lista o nome dos canais de texto cadastrados no servidor
	 	 */
		void listaCanais(){
			for(CanalTexto c : this->canaisTexto){
				std::cout<< c.getNome() << std::endl;
			}
		}

		/*! 
 	 	 * Método que verifica se um usuário é participante do servidor
		 * @param int id que indica o id do usuário para a verificação
		 * @return booleano verdadeiro se o id estiver dentro do vetor de participantes
	 	 */
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

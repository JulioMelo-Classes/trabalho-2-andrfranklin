#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <vector>
#include <string>
#include <iostream>

#include "canaltexto.h"
#include "usuario.h"

class Servidor
{
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
	Servidor(int id, std::string nome_);

	/*! 
 	 	 * Método que retorna o id do usuário dono do servidor
		 * @return int com o id do usuário dono do servidor
	 	 */
	int getUsuarioDonoId();

	/*! 
 	 	 * Método muda o nome do servidor
		 * @param string nome que indica o novo nome
	 	 */
	void setNome(std::string nome_);

	/*! 
 	 	 * Método que retorna o nome do servidor
		 * @return string com o nome do servidor
	 	 */
	std::string getNome();

	/*! 
 	 	 * Método muda a descricao do servidor
		 * @param string desc que indica a nova descricao
	 	 */
	void setDescricao(std::string desc);

	/*! 
 	 	 * Método que retorna a descricao do servidor
		 * @return string com a descricao do servidor
	 	 */
	std::string getDescricao();

	/*! 
 	 	 * Método muda o código de convite do servidor
		 * @param string code que indica o novo código de convite
	 	 */
	void setCodigoConvite(std::string code);

	/*! 
 	 	 * Método que retorna o codigo de convite do servidor
		 * @return string com o codigo de convite do servidor
	 	 */
	std::string getCodigoConvite();

	/*! 
 	 	 * Método que adiciona um novo canal de texto ao servidor
		 * @param objeto CanalTexto canal que indica o novo canal a ser adionado
	 	 */
	void addCanal(CanalTexto canal);

	/*! 
 	 	 * Método que lista o nome dos canais de texto cadastrados no servidor
	 	 */
	std::string listaCanais();

	/*! 
 	 	 * Método que verifica se um usuário é participante do servidor
		 * @param int id que indica o id do usuário para a verificação
		 * @return booleano verdadeiro se o id estiver dentro do vetor de participantes
	 	 */
	bool verificaID(int id);

	/*! 
 	 	 * Método adiciona um participante ao vetor de participantes do servidor
		 * @param int id que representa o id do usuário
	 	 */
	void addParticipante(int id);

	/*! 
 	 	 * Método remove um participante do vetor de participantes do servidor
		 * @param int id que representa o id do usuário
	 	 */
	void removeParticipante(int id);

	/*! 
 	 	 * Método lista os participantes do servidor
     	 * @param Vector Um vetor de usuários cadastrados no sistema
		 * @return Uma string com os nomes dos participantes do servidor
	 	 */
	std::string listaParticipantes(std::vector<Usuario> usuarios);

	/*! 
 	 	 * busca canal de texto
     	 * @param string Um nome do canal de texto
		 * @return um boolean verdadeiro se o canal existir no servidor
	 	 */
	bool verificaCanalTexto(std::string nome);

	/*! 
 	 	 * busca canal de texto
		 * @param int id do usuário que escreve a mensagem
		 * @param string Um nome do canal de texto
		 * @param string uma mensagem para o canal
	 	 */
	void adicionaMensagem(int id, std::string canal, string m);

	/*! 
 	 	 * busca canal de texto
     	 * @param string Um nome do canal de texto
		 * @return uma string com todas as mensagens do canal
	 	 */
	std::string listaMensagens(std::string canal, std::vector<Usuario> usuarios);
};

#endif

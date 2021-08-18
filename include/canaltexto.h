#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include <vector>
#include <string>

#include "mensagem.h"
#include "usuario.h"

/*
CP2 ok

Documentação, vou considerar 80% já que faltou documentar os atribuitos
*/
class CanalTexto
{
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
		CanalTexto(std::string nome_);

		/*! 
 	 	 * método que devolve o nome do CanalTexto
		 * @return nome do CanalTexto
	 	 */
		std::string getNome();

		/*! 
 	 	 * Adiciona mensagem em um canal de texto
		 * @param Mensagem Um objeto do tipo mensagem
	 	 */
		void adicionaMensagem(Mensagem m);

		/*! 
 	 	 * Retorna todas as mensagens do canal
		 * @return as mensagens do canal
	 	 */
		std::string listaMensagens(std::vector<Usuario> usuarios);

};

#endif

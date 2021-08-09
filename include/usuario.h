#ifndef USUARIO_H
#define USUARIO_H

#include<string>

class Usuario{
	/*
		TODO implementação dos atributos e métodos
	*/

	/*! 
 	 * atributos privados da classe Usuario
	 */
	public:
		std::string nome;

	/*! 
 	 * atributos privados da classe Usuario
	 */
	private:
		int id;
		std::string email;
		std::string senha;

	public:
		/*! 
 	 	 * Construtor para a classe Usuario, que não recebe parametros
	 	 */
		Usuario();


		/*! 
 	 	 * Construtor para a classe Usuario
		 *
		 * @param int id_ um identificador único do usuário no sistema
		 * @param string nome_ indicando o nome do usuario
		 * @param string email_ indicando o email do usuario
		 * @param string senha_ indicando a senha do usuario
	 	 */
		Usuario(int id_,std::string nome_, std::string email_,std::string senha_);

		/*! 
 	 	 * Método que retorna um inteiro com o valor do id do usuário
	 	 */
		int getId();


		/*! 
 	 	 * Método que altera o email do usuario
		 *
		 * @param string email_ indicando o novo email do usuario
	 	 */
		void updateEmail(std::string email_);

		/*! 
 	 	 * Método que retorna uma string com o valor do email do usuario
	 	 */
		std::string getEmail();


		/*! 
 	 	 * Método que altera a senha do usuario
		 *
		 * @param string senha_ indicando a nova senha_ do usuario
	 	 */
		void updateSenha(std::string senha_);

		/*! 
 	 	 * Método que retorna uma string com o valor da senha do usuario
	 	 */
		std::string getSenha();

};

#endif

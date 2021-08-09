#include "../include/usuario.h"

using namespace std;

/*! 
 * Construtor para a classe Usuario, que não recebe parametros
 */
Usuario::Usuario(){}

/*! 
 * Construtor para a classe Usuario
 *
 * @param int id_ um identificador único do usuário no sistema
 * @param string nome_ indicando o nome do usuario
 * @param string email_ indicando o email do usuario
 * @param string senha_ indicando a senha do usuario
 */
Usuario::Usuario(int id_, string nome_, string email_, string senha_) {
  id = id_;
  nome = nome_;
  email = email_;
  senha = senha_;
}

/*! 
 * Método que retorna um inteiro com o valor do id do usuário
 */
int Usuario::getId() {
  return id;
}

/*! 
 * Método que altera o email do usuario
 *
 * @param string email_ indicando o novo email do usuario
 */
void Usuario::updateEmail(string email_) {
  email = email_;
}

/*! 
 * Método que retorna uma string com o valor do email do usuario
 */
string Usuario::getEmail() {
  return email;
}

/*! 
 * Método que altera a senha do usuario
 *
 * @param string senha_ indicando a nova senha_ do usuario
 */
void Usuario::updateSenha(string senha_) {
  senha = senha_;
}

/*! 
 * Método que retorna uma string com o valor da senha do usuario
 */
string Usuario::getSenha() {
  return senha;
}
#include "../include/servidor.h"
#include "../include/usuario.h"

#include <vector>

using namespace std;
/*! 
 * Construtor para a classe Servidor
 * @param int id que representa o id do usuário dono so servidor
 * @param int nome que indica o nome do servidor
 */
Servidor::Servidor(int id, string nome_)
{
  usuarioDonoId = id;
  nome = nome_;
}

/*! 
 * Método que retorna o id do usuário dono do servidor
 * @return int com o id do usuário dono do servidor
 */
int Servidor::getUsuarioDonoId()
{
  return usuarioDonoId;
}

/*! 
 * Método muda o nome do servidor
 * @param string nome que indica o novo nome
 */
void Servidor::setNome(string nome_)
{
  nome = nome_;
}

/*! 
 * Método que retorna o nome do servidor
 * @return string com o nome do servidor
 */
string Servidor::getNome()
{
  return nome;
}

/*! 
 * Método muda a descricao do servidor
 * @param string desc que indica a nova descricao
 */
void Servidor::setDescricao(string desc)
{
  descricao = desc;
}

/*! 
 * Método que retorna a descricao do servidor
 * @return string com a descricao do servidor
 */
string Servidor::getDescricao()
{
  return descricao;
}

/*! 
 * Método muda o código de convite do servidor
 * @param string code que indica o novo código de convite
 */
void Servidor::setCodigoConvite(string code)
{
  codigoConvite = code;
}

/*! 
 * Método que retorna o codigo de convite do servidor
 * @return string com o codigo de convite do servidor
 */
string Servidor::getCodigoConvite()
{
  return codigoConvite;
}

/*! 
 * Método que adiciona um novo canal de texto ao servidor
 * @param objeto CanalTexto canal que indica o novo canal a ser adionado
 */
void Servidor::addCanal(CanalTexto canal)
{
  canaisTexto.push_back(canal);
}

/*! 
 * Método que lista o nome dos canais de texto cadastrados no servidor
 * @return string com o nome dos canais do servidor
 */
string Servidor::listaCanais()
{
  string result = "";
  for (CanalTexto c : canaisTexto)
  {
    result += c.getNome() + "\n";
  }
  return result;
}

/*! 
 * Método que verifica se um usuário é participante do servidor
 * @param int id que indica o id do usuário para a verificação
 * @return booleano verdadeiro se o id estiver dentro do vetor de participantes
 */
bool Servidor::verificaID(int id)
{
  for (auto it = participantesIDs.begin(); it != participantesIDs.end(); it++)
  {
    if (*it == id)
    {
      return true;
    }
  }

  return false;
}

/*! 
  * Método adiciona um participante ao vetor de participantes do servidor
  * @param int id que representa o id do usuário
  */
void Servidor::addParticipante(int id)
{
  participantesIDs.push_back(id);
}

/*! 
* Método remove um participante do vetor de participantes do servidor
* @param int id que representa o id do usuário
*/
void Servidor::removeParticipante(int id)
{
  for (auto it = participantesIDs.begin(); it < participantesIDs.end(); it++)
  {
    if (*it == id)
    {
      participantesIDs.erase(it);
    }
  }
}

/*! 
* Método lista os participantes do servidor
* @param Vector Um vetor de usuários cadastrados no sistema
* @return Uma string com os nomes dos participantes do servidor
*/

string Servidor::listaParticipantes(vector<Usuario> usuarios) //poderia usar uma referencia para evitar cópias desnecessárias!
{
  string result = "";
  for (auto itP = participantesIDs.begin(); itP != participantesIDs.end(); itP++)
  {
    for (auto itU = usuarios.begin(); itU != usuarios.end(); itU++)
    {
      if (itU->getId() == *itP)
      {
        result += itU->nome + "\n";
      }
    }
  }
  return result;
}

/*! 
* busca canal de texto
* @param string Um nome do canal de texto
* @return um boolean verdadeiro se o canal existir no servidor
*/
bool Servidor::verificaCanalTexto(std::string nome)
{
  for (auto it = canaisTexto.begin(); it != canaisTexto.end(); it++)
  {
    if (it->getNome() == nome)
    {
      return true;
    }
  }

  return false;
}

/*! 
* busca canal de texto
* @param int id do usuário que escreve a mensagem
* @param string Um nome do canal de texto
* @param string uma mensagem para o canal
*/
void Servidor::adicionaMensagem(int id, string canal, string mensagem){
  for (auto it = canaisTexto.begin(); it != canaisTexto.end(); it++)
  {
    if (it->getNome() == canal)
    {
      Mensagem m(id, mensagem);
      it->adicionaMensagem(m);
    }
  }
  
}

/*! 
* busca canal de texto
* @param string Um nome do canal de texto
* @return uma string com todas as mensagens do canal
*/

/*
No caso em que o canal não existe este método causa um comportamento indefinido quebrando efetivamente o programa
Dá para você verificar se fizer um list-messages de um usuário que está em um servidor mas não está em algum canal
*/
string Servidor::listaMensagens(std::string canal, vector<Usuario> usuarios){
  for (auto it = canaisTexto.begin(); it != canaisTexto.end(); it++)
  {
    if (it->getNome() == canal)
    {
      return it->listaMensagens(usuarios);
    }
  }
}
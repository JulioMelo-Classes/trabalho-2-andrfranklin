#include "../include/servidor.h"

#include <vector>

using namespace std;
/*! 
 * Construtor para a classe Servidor
 * @param int id que representa o id do usuário dono so servidor
 * @param int nome que indica o nome do servidor
 */
Servidor::Servidor(int id, string nome_) {
  usuarioDonoId = id;
  nome = nome_;
}

/*! 
 * Método que retorna o id do usuário dono do servidor
 * @return int com o id do usuário dono do servidor
 */
int Servidor::getUsuarioDonoId() {
  return usuarioDonoId;
}

/*! 
 * Método muda o nome do servidor
 * @param string nome que indica o novo nome
 */
void Servidor::setNome(string nome_) {
  nome = nome_;
}

/*! 
 * Método que retorna o nome do servidor
 * @return string com o nome do servidor
 */
string Servidor::getNome() {
  return nome;
}

/*! 
 * Método muda a descricao do servidor
 * @param string desc que indica a nova descricao
 */
void Servidor::setDescricao(string desc) {
  descricao = desc;
}

/*! 
 * Método que retorna a descricao do servidor
 * @return string com a descricao do servidor
 */
string Servidor::getDescricao() {
  return descricao;
}

/*! 
 * Método muda o código de convite do servidor
 * @param string code que indica o novo código de convite
 */
void Servidor::setCodigoConvite(string code) {
  codigoConvite = code;
}

/*! 
 * Método que retorna o codigo de convite do servidor
 * @return string com o codigo de convite do servidor
 */
string Servidor::getCodigoConvite() {
  return codigoConvite;
}

/*! 
 * Método que adiciona um novo canal de texto ao servidor
 * @param objeto CanalTexto canal que indica o novo canal a ser adionado
 */
void Servidor::addCanal(CanalTexto canal) {
  canaisTexto.push_back(canal);
}

/*! 
 * Método que lista o nome dos canais de texto cadastrados no servidor
 */
void Servidor::listaCanais() {
  for (CanalTexto c: canaisTexto) {
    cout << c.getNome() << endl;
  }
}

/*! 
 * Método que verifica se um usuário é participante do servidor
 * @param int id que indica o id do usuário para a verificação
 * @return booleano verdadeiro se o id estiver dentro do vetor de participantes
 */
bool Servidor::verificaID(int id) {
  for (auto it = participantesIDs.begin(); it != participantesIDs.end(); it++) {
    if (*it == id) {
      return true;
    }
  }

  return false;
}


/*! 
 	 	 * Método adiciona um participante ao vetor de participantes do servidor
		 * @param int id que representa o id do usuário
	 	 */
		void Servidor::addParticipante(int id){
			int idResult = participantesIDs.find(id);

			if(idR)
		}

		/*! 
 	 	 * Método remove um participante do vetor de participantes do servidor
		 * @param int id que representa o id do usuário
	 	 */
		void removeParticipante(int id){

		}
#include "../include/mensagem.h"

#include <time.h>
#include <ctime> 

using namespace std;

/*! 
* Construtor para a classe Mensagem
* @param id do usuário que envia a mensagem
* @param string mensagem com o texto da mensagem
*/
Mensagem::Mensagem(int id, string mensagem){
    time_t dh;
    time(&dh);
    datahora = ctime(&dh);    
    conteudo = mensagem;
    enviadaPor = id;
}
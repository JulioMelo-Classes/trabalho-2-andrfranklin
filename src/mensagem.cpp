#include "../include/mensagem.h"

#include <time.h>
#include <ctime> 

using namespace std;

Mensagem::Mensagem(int id, string mensagem){
    time_t dh;
    time(&dh);
    datahora = ctime(&dh);    
    conteudo = mensagem;
    enviadaPor = id;
}
#include "../include/sistema.h"
#include "../include/usuario.h"
#include "../include/servidor.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

/* COMANDOS */
string Sistema::quit() {
  return "Saindo...";
}

string Sistema::create_user (const string email, const string senha, const string nome) {

	for(auto it = usuarios.begin(); it != usuarios.end(); it++){
		if(it->getEmail() == email){
			return "Usuário já existe!";
		}
	}

	int id = usuarios.size()+1;
	Usuario u(id,nome, email, senha);
	usuarios.push_back(u);

  return "Usuario criado com sucesso";
}

string Sistema::login(const string email, const string senha) {
	Usuario u;
	for(auto it = usuarios.begin(); it != usuarios.end(); it++){
		if(it->getEmail() == email){
			u = *it;
			break;
		}

		if(it+1 == usuarios.end()){
			return "Usuário ou Senha inválidos";
		}
	}

	for(auto it = usuariosLogados.begin(); it != usuariosLogados.end(); it++){
		if(it->first == u.getId()){
			return "Usuario já está logado";
		}
	}

	if(u.getEmail() == email && u.getSenha() == senha){
		usuariosLogados.insert(u.getId(),{});
		string mensagem = "Logado como " + u.getEmail();
  	return mensagem;
	}else{
		return "Usuário ou Senha inválidos";
	}
	

}

string Sistema::disconnect(int id) {

	Usuario u;
	for(auto it = usuarios.begin(); it != usuarios.end(); it++){
		if(it->getId() == id){
			u = *it;
			break;
		}

		if(it+1 == usuarios.end()){
			return "Não está conectado";
		}
	}


	for(auto it = usuariosLogados.begin(); it != usuariosLogados.end(); it++){
		if(it->first == id){
			usuariosLogados.erase(id);
			string mensagem = "Desconectando usuário " + u.getEmail();
			return mensagem;
		}
	}

  return "Não está conectado";
}

string Sistema::create_server(int id, const string nome) {
	auto it = usuariosLogados.find(id);

	if(it == usuariosLogados.end()){
		return "Acesso negado";
	}

	for(auto its = servidores.begin(); its != servidores.end(); its++){
		if(its->getNome() == nome){
			return "Já existe um servidor com esse nome";
		}
	}

	Servidor s(id, nome);
	servidores.push_back(s);

  return "Servidor criado";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {
	auto it = usuariosLogados.find(id);

	if(it == usuariosLogados.end()){
		return "Acesso negado";
	}

	for(auto it = servidores.begin(); it != servidores.end(); it++){
		if(it->getNome() == nome){
			if(it->getUsuarioDonoId() == id){
				it->setDescricao(descricao);
				string mensagem = "Descrição do servidor " + nome + "' modificada!";
				return mensagem;
			}else{
				return "Você não pode alterar a descrição de um servidor que não foi criado por você";
			}
		}
	}

  return "Servidor '" + nome + "' não existe";
}

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {
  return "set_server_invite_code NÃO IMPLEMENTADO";
}

string Sistema::list_servers(int id) {
  return "list_servers NÃO IMPLEMENTADO";
}

string Sistema::remove_server(int id, const string nome) {
  return "remove_server NÃO IMPLEMENTADO";
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
  return "enter_server NÃO IMPLEMENTADO";
}

string Sistema::leave_server(int id, const string nome) {
  return "leave_server NÃO IMPLEMENTADO";
}

string Sistema::list_participants(int id) {
  return "list_participants NÃO IMPLEMENTADO";
}

string Sistema::list_channels(int id) {
  return "list_channels NÃO IMPLEMENTADO";
}

string Sistema::create_channel(int id, const string nome) {
  return "create_channel NÃO IMPLEMENTADO";
}

string Sistema::enter_channel(int id, const string nome) {
  return "enter_channel NÃO IMPLEMENTADO";
}

string Sistema::leave_channel(int id) {
  return "leave_channel NÃO IMPLEMENTADO";
}

string Sistema::send_message(int id, const string mensagem) {
  return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages(int id) {
  return "list_messages NÃO IMPLEMENTADO";
}




/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */

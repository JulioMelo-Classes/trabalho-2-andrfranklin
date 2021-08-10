#include "../include/sistema.h"
#include "../include/usuario.h"
#include "../include/servidor.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

/* COMANDOS */
string Sistema::quit()
{
	return "Saindo...";
}

/*
A1.2 ok
*/

/*! 
 * Função que realiza um cadastro de um usuário
 * @param string nome indicando o nome do usuario
 * @param string email indicando o email do usuario
 * @param string senha indicando a senha do usuario
 * 
 * @return Uma string informando o resultado da operação de criação
 */
string Sistema::create_user(const string email, const string senha, const string nome)
{

	for (auto it = usuarios.begin(); it != usuarios.end(); it++)
	{
		if (it->getEmail() == email)
		{
			return "Usuário já existe!";
		}
	}

	int id = usuarios.size();
	Usuario u(id, nome, email, senha);
	usuarios.push_back(u);

	return "Usuario criado com sucesso";
}

/*
A1.3 ok
*/

/*! 
 * Função que realiza o login de um usuário
 * @param string email indicando o email do usuario
 * @param string senha indicando a senha do usuario
 * 
 * @return string informando o resultado da operação de criação
 */
string Sistema::login(const string email, const string senha)
{
	Usuario u;
	for (auto it = usuarios.begin(); it != usuarios.end(); it++)
	{
		if (it->getEmail() == email)
		{
			u = *it;
			break;
		}

		if (it + 1 == usuarios.end())
		{
			return "Usuário ou Senha inválidos";
		}
	}

	for (auto it = usuariosLogados.begin(); it != usuariosLogados.end(); it++)
	{
		if (it->first == u.getId())
		{
			return "Usuario já está logado";
		}
	}

	if (u.getEmail() == email && u.getSenha() == senha)
	{
		usuariosLogados.insert({u.getId(), {"", ""}});
		string mensagem = "Logado como " + u.getEmail();
		return mensagem;
	}
	else
	{
		return "Usuário ou Senha inválidos";
	}
}

/*
A2.1 ok
*/

/*! 
 * Função que realiza o logOut de um usuário logado
 * @param id indicando um usuário logado
 * 
 * @return Uma string informando o resultado da operação de criação
 */
string Sistema::disconnect(int id)
{

	auto user = usuariosLogados.find(id);

	if (user == usuariosLogados.end())
	{
		return "O usuário não está conectado";
	}
	else
	{
		Usuario u;
		for (auto it = usuarios.begin(); it != usuarios.end(); it++)
		{
			if (it->getId() == id)
			{
				u = *it;
				break;
			}
		}
		usuariosLogados.erase(user);
		string mensagem = "Desconectando usuário " + u.getEmail();
		return mensagem;
	}

	return "O id informado é inválido";
}

/*
A2.2 ok
*/

/*! 
 * Função que realiza a criaçao de um servidor
 * @param int id indicando um usuário logado
 * @param string nome indicando o nome do novo servidor
 * 
 * @return Uma string informando o resultado da operação de criação
 */
string Sistema::create_server(int id, const string nome)
{
	auto user = usuariosLogados.find(id);

	if (user == usuariosLogados.end())
	{
		return "O usuário não está logado";
	}

	for (auto it = servidores.begin(); it != servidores.end(); it++)
	{
		if (it->getNome() == nome)
		{
			return "Já existe um servidor com esse nome";
		}
	}

	Servidor s(id, nome);
	servidores.push_back(s);

	return "Servidor criado";
}

/*
A2.3 ok
*/

/*! 
 * Função que realiza a mudança da descrição de um servidor
 * @param int id indicando um usuário logado
 * @param string nome indicando o nome do servidor
 * @param string descricao indicando a nova descrição do servidor
 * 
 * @return Uma string informando o resultado da operação de criação
 */
string Sistema::set_server_desc(int id, const string nome, const string descricao)
{
	auto user = usuariosLogados.find(id);

	if (user == usuariosLogados.end())
	{
		return "O usuário não está logado";
	}

	for (auto it = servidores.begin(); it != servidores.end(); it++)
	{
		if (it->getNome() == nome)
		{
			if (it->getUsuarioDonoId() == id)
			{
				it->setDescricao(descricao);
				return "Descrição do servidor " + nome + "' modificada!";
				;
			}
			else
			{
				return "Você não pode alterar a descrição de um servidor que não foi criado por você";
			}
		}
	}

	return "Servidor '" + nome + "' não existe";
}

/*
A2.4 ok
*/

/*! 
 * Função que realiza a mudança do codigo de um servidor
 * @param int id indicando um usuário logado
 * @param string nome indicando o nome do servidor
 * @param string codigo indicando o novo código do servidor
 * 
 * @return Uma string informando o resultado da operação de criação
 */
string Sistema::set_server_invite_code(int id, const string nome, const string codigo)
{

	auto user = usuariosLogados.find(id);
	if (user == usuariosLogados.end())
	{
		return "O usuário não está logado";
	}

	for (auto it = servidores.begin(); it != servidores.end(); it++)
	{
		if (it->getNome() == nome)
		{
			if (it->getUsuarioDonoId() == id)
			{
				if (codigo == "")
				{
					it->setCodigoConvite("");
					return "Código de convite do servidor '" + nome + "' removido!";
				}
				else
				{
					it->setCodigoConvite(codigo);
					return "Código de convite do servidor '" + nome + "' modificado!";
				}
			}
			else
			{
				return "Você não tem permissão para realizar esta operação";
			}
		}
	}

	return "servidor " + nome + " não encontrado";
}

/*
A2.5 ok
*/

/*! 
 * Função que lista todos os servidores do sistema
 * @param int id indicando um usuário logado
 * 
 * @return Uma string informando o resultado da operação de criação
 */
string Sistema::list_servers(int id)
{
	auto user = usuariosLogados.find(id);
	if (user == usuariosLogados.end())
	{
		return "O usuário não está logado";
	}

	string result = "";
	for (auto it = servidores.begin(); it != servidores.end(); it++)
	{
		result += it->getNome() + "\n";
	}
	return result;
}

/*
A2.6 ok
*/

/*! 
 * Função que realiza a exclusão de um servidor
 * @param int id indicando um usuário logado e dono do servidor
 * @param string nome indicando o nome do servidor
 * 
 * @return Uma string informando o resultado da operação de criação
 */
string Sistema::remove_server(int id, const string nome)
{
	auto user = usuariosLogados.find(id);

	if (user == usuariosLogados.end())
	{
		return "O usuário não está logado";
	}

	for (auto it = servidores.begin(); it != servidores.end(); it++)
	{
		if (it->getNome() == nome)
		{
			if (it->getUsuarioDonoId() == id)
			{
				servidores.erase(it);

				for (auto it = usuariosLogados.begin(); it != usuariosLogados.end(); it++)
				{
					if (it->second.first == nome)
					{
						it->second.first = "";
						it->second.second = "";
					}
				}

				return "Servidor '" + nome + "' removido!";
			}
			else
			{
				return "Você não é o dono do servidor '" + nome + "'";
			}
		}
	}

	return "Servidor '" + nome + "' não encontrado";
}


/*! 
 * Função que realiza a entrada de um usuário logado em um servidor
 * @param int id indicando um usuário logado
 * @param string nome indicando o nome do servidor
 * @param string codigo indicando o código do servidor
 * 
 * @return Uma string informando o resultado da operação de criação
 */
string Sistema::enter_server(int id, const string nome, const string codigo)
{
	auto user = usuariosLogados.find(id);
	if (user == usuariosLogados.end())
	{
		return "O usuário não está logado";
	}

	for (auto it = servidores.begin(); it != servidores.end(); it++)
	{
		if (it->getNome() == nome)
		{
			if (it->getCodigoConvite() != "")
			{
				if (codigo != "")
				{
					if (it->getCodigoConvite() == codigo)
					{
						if (!it->verificaID(id))
						{
							it->addParticipante(id);
							user->second.first = nome;
							return "Entrou no servidor com sucesso";
						}
						else
						{
							return "O usuário já participa deste servidor";
						}
					}
					else
					{
						return "Código de convite inválido";
					}
				}
				else
				{
					return "Servidor requer código de convite";
				}
			}
			else
			{
				if (!it->verificaID(id))
				{
					it->addParticipante(id);
					user->second.first = nome;
					return "Entrou no servidor com sucesso";
				}
				else
				{
					return "O usuário já participa deste servidor";
				}
			}
		}
	}
	return "Servidor não encontrado";
}


/*! 
 * Função que realiza a saída de um usuário logado de um servidor
 * @param int id indicando um usuário logado
 * @param string nome indicando o nome do servidor
 * 
 * @return Uma string informando o resultado da operação de criação
 */
string Sistema::leave_server(int id, const string nome)
{
	auto user = usuariosLogados.find(id);
	if (user == usuariosLogados.end())
	{
		return "O usuário não está logado";
	}

	for (auto it = servidores.begin(); it != servidores.end(); it++)
	{
		if (it->getNome() == nome)
		{
			if (it->verificaID(id))
			{
				it->removeParticipante(id);
				if (user->second.first == it->getNome())
				{
					user->second.first = "";
					user->second.second = "";
				}
				return "Saindo do servidor '" + it->getNome() + "'";
			}
			else
			{
				return "Você não é participante deste servidor";
			}
		}
	}

	return "Servidor '" + nome + "' não encontrado";
}


/*! 
 * Função que lista os participantes de um servidor que o usuário logado está visualizando
 * @param int id indicando um usuário logado
 * 
 * @return Uma string informando o resultado da operação de criação
 */
string Sistema::list_participants(int id)
{
	auto user = usuariosLogados.find(id);
	if (user == usuariosLogados.end())
	{
		return "O usuário não está logado";
	}

	for (auto it = servidores.begin(); it != servidores.end(); it++)
	{
		if (it->getNome() == user->second.first)
		{
			return it->listaParticipantes(usuarios);
		}
		
	}
		
	return "Você não está visualizando nenhum servidor";
}


/*! 
 * Função que lista os canais de um servidor que o usuário logado está visualizando
 * @param int id indicando um usuário logado
 * 
 * @return Uma string informando o resultado da operação de criação
 */
string Sistema::list_channels(int id)
{
	auto user = usuariosLogados.find(id);
	if (user == usuariosLogados.end())
	{
		return "O usuário não está logado";
	}

	for (auto it = servidores.begin(); it != servidores.end(); it++)
	{
		if (it->getNome() == user->second.first)
		{
			return it->listaCanais();
		}
	}

	return "O usuário não está visualizando nenhum servidor"
}


/*! 
 * Função que cria um canal em um servidor que o usuário logado e dono do servidor está visualizando
 * @param int id indicando um usuário logado
 * @param string nome indicando o nome do servidor
 * 
 * @return Uma string informando o resultado da operação de criação
 */
string Sistema::create_channel(int id, const string nome)
{
	auto user = usuariosLogados.find(id);
	if (user == usuariosLogados.end())
	{
		return "O usuário não está logado";
	}

	for (auto it = servidores.begin(); it != servidores.end(); it++)
	{
		if(it->getNome() == user->second.first){
			if (it->getUsuarioDonoId() == id)
			{
				if (!it->verificaCanalTexto(nome))
				{
					CanalTexto c(nome);
					servidores.push_back(c);
					return "Canal de texto '" + nome + "' criado";
				}else
				{
					return "O canal de texto '" + nome + "' já exite";
				}	
			}else
			{
				return "Você não é o dono do servidor";
			}
		}
	}

	return "O usuário não está visualizando nenhum servidor";	
}


/*! 
 * Função que adiciona um usuário logado e cadastrado em um servidor em um canal do mesmo servidor
 * @param int id indicando um usuário logado
 * @param string nome indicando o nome do servidor
 * 
 * @return Uma string informando o resultado da operação de criação
 */
string Sistema::enter_channel(int id, const string nome)
{
	auto user = usuariosLogados.find(id);
	if (user == usuariosLogados.end())
	{
		return "O usuário não está logado";
	}

	for (auto it = servidores.begin(); it != servidores.end(); it++)
	{
		if(it->getNome() == user->second.first){
			if (it->verificaID(id))
			{
				if (it->verificaCanalTexto(nome))
				{
					user->second.second = nome;
					return "Entrou no canal '" + nome + "'";
				}else
				{
					return "Canal '" + nome + "' não existe";
				}
			}else{
				return "Você não é um participante deste canal";
			}	
		}
	}
	return "Você não está visualizando nenhum servidor";
}


/*! 
 * Função que remove um usuário logado e cadastrado em um servidor de um canal do mesmo servidor
 * @param int id indicando um usuário logado
 * 
 * @return Uma string informando o resultado da operação de criação
 */
string Sistema::leave_channel(int id)
{
	auto user = usuariosLogados.find(id);
	if (user == usuariosLogados.end())
	{
		return "O usuário não está logado";
	}

	if (user->second.second != "")
	{
		user->second.second = "";
		return "Saindo do canal";
	}
	
	
	return "Você não está visualizando nenhum canal";
}


/*! 
 * Função que adiciona uma mensagem em um canal de um servidor que um usuário logado está visualizando
 * @param int id indicando um usuário logado
 * @param string mensagem indicando o texto da nova mensagem
 * 
 * @return Uma string informando o resultado da operação de criação
 */
string Sistema::send_message(int id, const string mensagem)
{
	auto user = usuariosLogados.find(id);
	if (user == usuariosLogados.end())
	{
		return "O usuário não está logado";
	}

	if (user->second.second == "")
	{
		return "O usuário não está em um canal de texto";
	}

	for (auto it = servidores.begin(); it != servidores.end(); it++)
	{
		if(it->getNome() == user->second.first){
			it->adicionaMensagem(id, user->second.second, mensagem);
			return "Usuario adicionou uma nova mensagem";
		}
	}
	
	
	return "send_message NÃO IMPLEMENTADO";
}

/*! 
 * Função que lista as mensagem de um canal de um servidor que um usuário logado está visualizando
 * @param int id indicando um usuário logado
 * 
 * @return Uma string informando o resultado da operação de criação
 */
string Sistema::list_messages(int id)
{
	auto user = usuariosLogados.find(id);
	if (user == usuariosLogados.end())
	{
		return "O usuário não está logado";
	}

	for(auto it = servidores.begin(); it != servidores.end(); it++){
		if(it->getNome() == user->second.first){
			return it->listaMensagens(user->second.second,usuarios);
		}
	}
	// return "list_messages NÃO IMPLEMENTADO";
}

/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */

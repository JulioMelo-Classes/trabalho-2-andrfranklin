#ifndef USUARIO_H
#define USUARIO_H

#include<string>

/*
Classe usuário CP1 70%
Removi 30% pois você implementou tudo no .h
*/

class Usuario{
	/*
		TODO implementação dos atributos e métodos
	*/

	public:
		std::string nome;

	private:
		int id;
		std::string email;
		std::string senha;

	public:
		Usuario(){}

		Usuario(int id_,std::string nome_, std::string email_,std::string senha_){
			id = id_;
			nome = nome_;
			email = email_;
			senha = senha_;
		}

		int getId(){
			return id;
		}

		void updateEmail(std::string email_){
			email = email_;
		}

		std::string getEmail(){
			return email;
		}

		void updateSenha(std::string senha_){
			senha = senha_;
		}

		std::string getSenha(){
			return senha;
		}

};

#endif

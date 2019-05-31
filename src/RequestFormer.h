/*
* Khomenko Jane
* Mail: tyryry221@gmail.com
* Github: JaneKKTTme
* Date: 14.03.19
*/

#ifndef REQUEST_FORMER_H
#define REQUEST_FORMER_H

#include "../include/rapidjson/document.h"
#include "../include/rapidjson/writer.h"
#include <string>
#include <queue>
#include "ServerConnector.h"
#include "LogPrinter.h"

struct Material {
	std::string title;
	std::string unions;
	double price;
};

struct Purchase {
	std::string title;
	int quantity;
	double cost;
};

struct Buying {
	std::string title;
	int quantity;
	double cost;
};

struct ShoppingList{
	int purchase_id;
	double total_cost;
	std::string status;
	std::queue <Buying> purchase;
};

struct Evaluation {
	std::string id;
	std::string evaluation;
};

class RequestFormer {
private:
	std::string _name;
	std::string _last_name;
	std::string _middle_name;
	std::string _number;
	std::string _password;
	std::string _type;
	std::string _foreman_number;
	static ServerConnector _sc;

	/*
	*set_new_user() - need for more comfortable using in registration process.
	*/
	void set_new_user(std::string& name, std::string& last_name,
		std::string& middle_name, std::string& number,
		std::string& password, std::string& type, std::string& foreman_number);

	/*
	*enter_old_user() - need for more comfortable using in entrance process.
	*/
	void enter_old_user(std::string& number, std::string& password);

	/*
	*to_json() - generate JSON request by rapidjson.
	*It uses in another methods - to_enter() and to_register().
	*/
	rapidjson::Document to_json(std::string request);

	/*
	*serialize() - make JSON request more suitable and useful for working with server.
	*This method is nessesary in process of formation request.
	*/
	template <typename Writer>
	void serialize(Writer& writer) const;

public:
	RequestFormer();

	~RequestFormer();

	/*
	*This method calls ServerConnector object to connect to server by static method.
	*/
	static void connect_to_server();

	/*
	*This method closes connection by static method of ServerConnector class.
	*/
	static void disconnect();

	/*
	*to_register() - register a new user's account.
	*The method returns nothing.
	*If such user has already existed or some data is not in suitable format,
	*can throw "Such user already exists", "Password is too short" or
	*"Number of foreman is not right" of type const char *.
	*/
	static void to_register(std::string name, std::string last_name, std::string middle_name,
		std::string number, std::string password, std::string type,
		std::string foreman_number);

	/*
	*to_enter() - enter to user's account. The method returns nothing.
	*If such user exists or his password is wrong,
	*can throw "User does not exist" or "Password is failed" of type const char *.
	*/
	static void to_enter(std::string number, std::string password, 
					std::string& name, std::string& last_name,
					std::string& middle_name, std::string& type,
					std::queue <std::string>& clients_numbers);

	/*
	*to_get_materials() - send all of materials to foreman.
	*Сreate JSON request to server, receive answer, parse it and return the queue of materials.
	*Else it can throw that such objects do not exist.
	*/
	static std::queue <Material> to_get_materials();

	/*
	*to_send_materials() - choose materials for purchase and send it to server.
	*Create JSON file from purchase and send it to server.
	*/
	static void to_send_purchase(std::string foreman_number, std::string client_number, 
					double total_cost, std::queue <Purchase> table);

	/*
	*to_show_purchses() - show all purchases to user.
	*Create JSON request to server, receive answer, parse it and return the queue of purchases.
	*Else it can throw that no purshase exists.
	*/
	static std::queue <ShoppingList> to_show_purchases(std::string foreman_number, 
					std::string client_number);

	/*
	*to_send_evaluations() - send evaluations of purchases to server.
	*Create JSON file from parameters and send it to server.
	*/
	static void to_send_evaluations(std::string client_number, std::queue <Evaluation> table);

};

#endif // REQUEST_FORMER_H

#pragma once

#include "Service.h"
#include "UserService.h"
#include <string>
#include "Tutorial.h"

using std::string;

class UI {
private:
	AdminService& service;
	Service& userService;
public:
	UI(AdminService& service, Service& userService);
	void printOptionsAdmin();
	void printOptionsUser();
	void menuUser();
	void menuAdmin();
	void mainMenu();
	void printAllTutorials();
	void printTutorial(Tutorial tutorial);
};
#include "UI.h"
#include "DynamicArray.h"
#include "Service.h"
#include "UserService.h"

#include <iostream>

int main()
{
	Repository repository;
	AdminService adminService(repository);
	Service userService(repository);
	UI ui(adminService, userService);
	ui.mainMenu();
}
#pragma once

#include "Repository.h"
#include "Tutorial.h"

using std::string;

class AdminService {
private:
	Repository& service;
public:
	AdminService(Repository& service);
	void addTutorial(string& title, string& presenter, const string& link, int numberOfLikes, int minutes, int seconds);
	void removeTutorial(string title);
	void updateTutorial(string title, int newNumberLikes);
	DynamicArray<Tutorial> getAll();
};

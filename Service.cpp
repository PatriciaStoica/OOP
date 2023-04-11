#include "Service.h"
using std::string;

AdminService::AdminService(Repository& service) :service(service)
{
}

void AdminService::addTutorial(string& title, string& presenter,const string& link, int numberOfLikes, int minutes, int seconds)
{
	Tutorial newTutorial(title, presenter, minutes, seconds, numberOfLikes, link);
	this->service.add(newTutorial);
}

void AdminService::removeTutorial(string title)
{
	int position = -1;
	for (int i = 0; i < this->service.size(); i++)
	{
		if (this->service.findTutorial(i).getTitle() == title)
		{
			position = i;
			return;
		}
	}
	if (position == -1)
		throw std::exception("Tutorial not found");
	else
		this->service.remove(this->service.findTutorial(position));
}

void AdminService::updateTutorial(string title, int newNumberLikes)
{
	int position = -1;
	for (int i = 0; i < this->service.size(); i++)
	{
		if (this->service.findTutorial(i).getTitle() == title)
		{
			position = i;
			return;
		}
	}

	if (position == -1)
		throw std::exception("Tutorial not found");
	else
	{
		Tutorial tutorial = this->service.findTutorial(position);
		tutorial.setLikes(newNumberLikes);
	}
	
}

DynamicArray<Tutorial> AdminService::getAll()
{
	return this->service.getAll();
}


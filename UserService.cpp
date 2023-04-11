#include "UserService.h"

Service::Service(Repository& service): service(service)
{
}

DynamicArray<Tutorial> Service::getTutorialWithGivenPresenter(string givenPresenter)
{
	DynamicArray<Tutorial> tutorialsInDatabase = this->service.getAll();
	if (givenPresenter == "")
		return tutorialsInDatabase;

	DynamicArray<Tutorial> tutorialsWithGivenPresenter;

	for (int i = 0; i < tutorialsInDatabase.size(); i++)
	{
		Tutorial tutorial = this->service.findTutorial(i);
		if (tutorial.getPresenter() == givenPresenter)
			tutorialsWithGivenPresenter.addDynamicArray(tutorial);
	}

	return tutorialsWithGivenPresenter;
}

DynamicArray<Tutorial> Service::getAllTutorialsFromService()
{
	return this->service.getAll();
}

void Service::addTutorialToWatchList(Tutorial tutorial)
{
	this->watchList.add(tutorial);
}

DynamicArray<Tutorial> Service::getWatchList()
{
	return this->watchList.getAll();
}

void Service::deleteTutorialFromWatchList(Tutorial tutorial)
{
	this->watchList.remove(tutorial);
}

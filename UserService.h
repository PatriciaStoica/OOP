#pragma once

#include "DynamicArray.h"
#include "Repository.h"
#include "Tutorial.h"

#include <string>

class Service {
private:
	Repository& service;
	Repository watchList;
public:
	Service(Repository& service);
	DynamicArray<Tutorial> getTutorialWithGivenPresenter(string givenPresenter);
	DynamicArray<Tutorial> getAllTutorialsFromService();
	void addTutorialToWatchList(Tutorial tutorial);
	DynamicArray<Tutorial> getWatchList();
	void deleteTutorialFromWatchList(Tutorial tutorial);
};

#include <iostream>
#include <string>

#include "Tutorial.h"

Tutorial::Tutorial()
{
	this->title = "";
	this->presenter = "";
	this->link = "";
	this->numberLikes = 0;
	this->d.minutes = 0;
	this->d.seconds = 0;
}

Tutorial::Tutorial(string& title, string& presenter, int minutes, int seconds, int numberLikes, const string& link)
{
	this->title = title;
	this->presenter = presenter;
	this->link = link;
	this->numberLikes = numberLikes;
	duration d;
	d.minutes = minutes;
	d.seconds = seconds;
	this->d = d;
}

Tutorial::~Tutorial() = default;

Tutorial::Tutorial(const Tutorial& other)
{
	this->title = other.title;
	this->presenter = other.presenter;
	duration d;
	d.minutes = other.d.minutes;
	d.seconds = other.d.seconds;
	this->link = other.link;
	this->numberLikes = other.numberLikes;
}

Tutorial& Tutorial::operator=(const Tutorial& other)
{
	Tutorial newTutorial(other);
	this->title = newTutorial.title;
	this->presenter = newTutorial.presenter;
	duration d;
	d.minutes = newTutorial.d.minutes;
	d.seconds = newTutorial.d.seconds;
	this->link = newTutorial.link;
	this->numberLikes = newTutorial.numberLikes;

	return *this;
}

bool Tutorial::operator==(const Tutorial& other)
{
	return (this->presenter == other.presenter);
}

void Tutorial::setTitle(const string& newTitle)
{
	this->title = newTitle;
}

void Tutorial::setPresenter(const string& newPresenter)
{
	this->presenter = newPresenter;
}

void Tutorial::setDuration(int newMinutes, int newSeconds)
{
	this->d.minutes = newMinutes;
	this->d.seconds = newSeconds;
}

void Tutorial::setLikes(int newNumberLikes)
{
	this->numberLikes = numberLikes;
}

void Tutorial::setLink(const string& newLink)
{
	this->link = newLink;
}


string Tutorial::getTitle() const
{
	return this->title;
}

string Tutorial::getPresenter() const
{
	return this->presenter;
}

Tutorial::duration Tutorial::getDuration()
{
	return this->d;
}

int Tutorial::getNumberLikes()
{
	return this->numberLikes;
}

string Tutorial::getLink() const
{
	return this->link;
}
#include "UI.h"
#include "Tutorial.h"
#include "Service.h"
#include "DynamicArray.h"

#include <iostream>

using namespace std;

UI::UI(AdminService& service, Service& userService): service(service), userService(userService)
{
}

void UI::printOptionsAdmin()
{
	cout << "1. Add tutorial\n";
	cout << "2. Delete a tutorial\n";
	cout << "3. Update a tutorial\n";
	cout << "4. Exit\n";
}

void UI::printOptionsUser()
{
	cout << "1. Add tutorial to watch list\n";
	cout << "2. Delete a tutorial from watch list\n";
	cout << "3. Continue\n";
	cout << "4. Exit\n";
}

void UI::menuUser()
{
	string option;
	while (1)
	{
		printOptionsUser();
		int i = 0;
		DynamicArray<Tutorial> tutorials = this->userService.getAllTutorialsFromService();
		while (i < tutorials.size())
		{
			Tutorial tutorial = tutorials[i];
			printTutorial(tutorial);
			getline(cin, option);
			if (option == "1")
			{
				this->userService.addTutorialToWatchList(tutorial);
				cout << "Do you like this tutorial ?\n";
				string yesNo;
				cin >> yesNo;
				if (yesNo == "yes")
				{
					this->service.updateTutorial(tutorial.getTitle(), tutorial.getNumberLikes() + 1);
				}
			}
			else if (option == "2")
			{
				this->userService.deleteTutorialFromWatchList(tutorial);
			}
			else if (option == "3")
				continue;
			else if (option == "4")
				break;
			i++;
			if (i == tutorials.size())
				i = 0;
		}
	}
}

void UI::menuAdmin()
{
	int option;
	while (1)
	{
		printOptionsAdmin();
		cin >> option;
		if (option == 1)
		{
			string title, presenter, link;
			int likes, minutes, seconds;
			cout << "Enter title: ";
			cin.ignore();
			getline(cin, title);
			cout << title << endl;;
			cout << "Enter presenter: ";
			//cin.ignore();
			getline(cin, presenter);
			cout << presenter << endl;
			cout << "Enter link: ";
			getline(cin, link);
			cout << link << endl;
			cout << "Enter number of likes: ";
			cin >> likes;
			cout << likes << endl;;
			cout << "Enter number minutes: ";
			cin >> minutes;
			cout << minutes << endl;;
			cout << "Enter number of seconds: ";
			cin >> seconds;
			cout << seconds << endl;
			
			try
			{
				this->service.addTutorial(title, presenter, link, likes, minutes, seconds);
				cout << "Tutorial was added successfully";
			}
			catch (std::exception& thrownException)
			{
				cout << thrownException.what();
			}
		}
		else if (option == 2)
		{
			string title;
			cout << "Enter title: ";
			getline(cin, title);
			try
			{
				this->service.removeTutorial(title);
				cout << "Tutorial was deleted successfully!";
			}
			catch (std::exception& e)
			{
				cout << e.what();
			}
		}
		else if (option == 3)
		{
			string title;
			int numberOfLikes;
			cout << "Enter tutorial title: ";
			getline(cin, title);
			cout << "Enter new number of likes: ";
			cin >> numberOfLikes;
			try
			{
				this->service.updateTutorial(title, numberOfLikes);
			}
			catch (std::exception& e)
			{
				cout << e.what();
			}
		}
		else if (option == 4)
			return;
	}
}

void UI::mainMenu()
{
	int option;
	while (1)
	{
		cout << "1. Admin mode\n";
		cout << "2. User mode\n";
		cout << "3. Exit\n";
		cout << "Enter option: ";
		cin >> option;
		//cin.ignore();
		if (option == 1)
		{
			menuAdmin();
		}
		else if (option == 2)
		{
			menuUser();
		}
		else if(option == 3)
			return;
	}
}

void UI::printAllTutorials()
{
	DynamicArray<Tutorial> tutorials = this->service.getAll();
	if (tutorials.size() == 0)
		cout << "There are no tutorials available at the moment\n";
	for (int i = 0; i < tutorials.size(); i++)
	{
		Tutorial tutorial = tutorials[i];
		printTutorial(tutorial);
	}
}

void UI::printTutorial(Tutorial tutorial)
{
	cout << endl;
	cout << "Title: " << tutorial.getTitle()<<"\n";
	cout << "Presenter: " << tutorial.getPresenter()<<"\n";
	cout << "Duration: " << tutorial.getDuration().minutes << " " << tutorial.getDuration().seconds<<"\n";
	cout << "Link: " << tutorial.getLink()<<"\n";
	cout << "Number of likes: " << tutorial.getNumberLikes() <<"\n\n";
}

#include <iostream>
#include <windows.h> //used for windows api commands.
#include <string>

int main() {
	int batch_count = 0;
	std::string date = "";
	int previous_batch = 0;
	std::string current_batch = "";
	const int lengthOfDate = 6;

	std::cout << "What date are we creating these folders for? YYMMDD - Format. \n";
	std::cin >> date;
	while (date.length() > lengthOfDate || date.length() < lengthOfDate) //Input validation - string length making sure its a valid date.
	{
		std::cout << "That is an invalid date, try again\n";
		std::cin >> date;
	}

	std::cout << "I will create the folders for the date inputted, how many batches do you expect today?\n";
	std::cin >> batch_count;

	std::cout << "Okay, last question. What was the ID of the last batch created?\n";
	std::cin >> previous_batch;

	if (CreateDirectoryA(date.c_str(), NULL))
	{
		std::cout << "The folder for the inputted date has been created.";
		//for loop iterating the same amount of times as the batch count.
		for (int x = 1; x < batch_count; x++)
		{
			current_batch = std::to_string(previous_batch + x); //we want to create a folder for the next batch.
			std::string createdDirectory = "C:\\Coding\\Code\\Folder Creation for LifeBrite\\" + date + "\\" + date + "_";
			std::string batch_folder = createdDirectory + current_batch;

			CreateDirectoryA(batch_folder.c_str(), NULL);
			std::cout << "Folder #" + x;
			std::cout << " created...";
		}
	}
	else if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		std::cout << "This folder already exists! I will only create batch subfolders for this date";
	}

	else
	{
		// Failed to create directory.
		std::cout << "This folder already exists! Create directory failed.";
	}
}
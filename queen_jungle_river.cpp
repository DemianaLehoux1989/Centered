//including relevant libraries
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

//declaring global variables
std::string appName = "Mindfulness and Meditation";
int userCount = 0;
std::vector<std::string> meditationInstructions;

//declaring necessary classes
class User
{
  private:
    int userID;
    std::string userName;
    std::vector<std::string> meditationHistory;
    int meditationTime;
  public:
    void setUserID(int id);
    void setUserName(std::string name);
    void recordMeditationTime(int time);
    int getUserID();
    std::string getUserName();
    std::vector<std::string> getMeditationHistory();
    int getMeditationTime();
};

//implementing/defining necessary functions
int User::getUserID(){
	return userID;
}

std::string User::getUserName(){
	return userName;
}

std::vector<std::string> User::getMeditationHistory(){
	return meditationHistory;
}

int User::getMeditationTime(){
	return meditationTime;
}

void User::setUserID(int id){
	userID = id;
}

void User::setUserName(std::string name){
	userName = name;
}

void User::recordMeditationTime(int time){
	meditationHistory.push_back(std::to_string(time));
	meditationTime += time;
}

//function to print meditation instructions
void printMeditationInstructions(){
	for(int i=0; i<meditationInstructions.size(); i++){
		std::cout << meditationInstructions[i] << std::endl;
	}
}

//function to start the meditation session
void startMeditationSession(User user){
	std::cout << "Welcome " << user.getUserName() << ", let's start the meditation session" << std::endl;
	std::cout << "We will be meditating for 10 minutes" << std::endl;
	std::cout << "Starting now..." << std::endl;
	
	//meditation session
	int duration = 10 * 60; //duration in seconds
	while(duration > 0){
		//counting down every 10 seconds
		int count = 0;
		while(count < 10){
			duration--;
			count++;
			std::cout << duration << " seconds left." << std::endl;
			sleep(1);
		}
		std::cout << "Focus on your breath now..." << std::endl;
		sleep(10);
	}

	//recording the meditation time
	int meditationTime = 10 * 60;
	user.recordMeditationTime(meditationTime);

	std::cout << "Meditation session ended." << std::endl; 
	std::cout << "You have been meditating for " << user.getMeditationTime() << " seconds." << std::endl;  
}

//function to register a new user
void registerUser(){
	std::string name;
	std::cout << "Please enter your name: ";
	std::getline(std::cin, name);

	userCount++;

	User user;
	user.setUserID(userCount);
	user.setUserName(name);

	std::cout << "You have successfully registered to " << appName << std::endl;
	startMeditationSession(user);
}

//main function
int main(){
	//populate meditation instructions
	meditationInstructions.push_back("1. Sit comfortably with your back straight and your eyes closed");
	meditationInstructions.push_back("2. Observe your breath. Feel the air moving through your nose or mouth as you inhale and exhale");
	meditationInstructions.push_back("3. When your mind wanders, gently bring it back to your breath");
	meditationInstructions.push_back("4. Don't judge your thoughts; just acknowledge them and focus back to your breath");
	meditationInstructions.push_back("5. Take your time and enjoy the process");

	std::cout << "Welcome to " <<  appName << ", an app for workplace wellness" << std::endl;
	std::cout << "Are you a new user (yes/no)? ";
	std::string response;
	std::getline(std::cin, response);

	if(response == "yes"){
		registerUser();
	}else if(response == "no"){
		std::cout << "You are already registered" << std::endl;
		std::cout << "Do you want to start the meditation session (yes/no)? ";
		std::string response2;
		std::getline(std::cin, response2);

		if(response2 == "yes"){
			std::cout << "Let's start by reading the meditation instructions: " << std::endl;
			printMeditationInstructions();
			startMeditationSession(User());
		}else{
			std::cout << "Come back later and practice mindfulness and meditation with us!" << std::endl;
		}
	}

	return 0;
}
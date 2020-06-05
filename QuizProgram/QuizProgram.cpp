// QuizProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Class to create objects containing question data
class Question {
public:
    // The question description
    std::string description;
    // The actual question
    std::string question;
    // The correct answer
    std::string correctAnswer;
    // The possible answers, stored in an list
    std::vector<std::string> answers;
    // Store whether the user got the answer correct or not
    bool result;
};

// Class to handle quiz events
class QuizModel {
public:
    // The number of questions in the quiz
    int numQuestions;
    // List of question objects to be used in the current quiz
    std::vector<Question> questionList;
    // The Quiz Topic
    std::string topic;

    // Read the quiz data from a file and save it to an array
    void GetQuizData() {
        // Set the size of the questionList
        questionList.resize(numQuestions);

        // Open the file containing the quiz data
        std::ifstream QuizFile(topic);
    }
};

// MAIN ROUTINE
int main()
{
    // Create instance of QuizModel
    QuizModel quiz;

    std::cout << "-------QWERTYQUIZ CONSOLE-------" << "\nDeveloped in C++ by QwertyGroup.";

    bool run = true;
    // Get the Quiz Topic
    while (run) {
        std::cout << "\n\n\n1. Physics\n2.General Knowledge\nChose a Topic: ";
        // Get user response
        std::cin >> quiz.topic;

        // Convert topic string to lower case
        for (int i = 0; i < quiz.topic.length(); i++) {
            quiz.topic[i] = tolower(quiz.topic[i]);
        }

        // Check user input
        if (quiz.topic == "1" || quiz.topic == "physics") {
            quiz.topic = "Physics";
            run = false;
        }
        else if (quiz.topic == "2" || quiz.topic == "general knowledge") {
            quiz.topic = "General Knowledge";
            run = false;
        }
        else {
            // Display an error and loop back to start
            std::cout << "\nOops.. looks like the that's not quite right. Try again:";
        }
    }
    run = true;
    // Get the number of questions
    while (run) {
        // Store the number of questions as a string
        std::string numQuestions;

        std::cout << "\nEnter the number of questions (Must be between 1 and 15): ";
        // Get user response
        std::cin >> numQuestions;

        // Check user response
        try {
            // Convert the string to an int
            quiz.numQuestions = std::stoi(numQuestions);

            // Check the size of the int
            if (quiz.numQuestions > 0 && quiz.numQuestions < 16) {
                run = false;
            }
            else {
                // Display an error and loop back to the start of the loop
                std::cout << "Oops.. looks like that's not quite right. Try again:";
            }
        }
        catch (...) {
            // Display an error and loop back to the start of the loop
            std::cout << "Oops.. looks like that's not quite right. Try again:";
        }
    }

    std::cout << "\n\nTopic: " << quiz.topic << "\nNumber of Questions: " << quiz.numQuestions << "\n\n";

    return 0;
}
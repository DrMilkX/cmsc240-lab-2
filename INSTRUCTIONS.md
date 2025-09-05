# Lab 2 - ExpertBot

ChatGPT is a pretty general and knowledgable chatbot -- but it isn't an *EXPERT* on everything. And there's a severe lack of AI chatbots with a specific expertise on a given topic! That's where you come in! You're going to make a chatbot that is an expert on a topic of your choice. 

The user can ask it almost anything and it should have an accurate answer. Essentially, if a trivia question comes up based on the particular topic, your chatbot should be able to answer it. You will also need to do some research to provide these accurate answers and to make sure your bot isn't giving your user misinformation.

## Code

[expertbot.cpp](expertbot.cpp) is given as a starter code file. You can use this file and change also the name if you want -- just remember to state how to compile and run it in the README! In it there are 2 functions: 
- `int main` -- the main function
- `int random` -- returns a random value between a minimum and maximum integer (for use with the default response)

You can make as many additional functions as you want or change the default code, so long as it's commented and compiles without errors!

## Rules

- You are allowed to use any resource so long as it follows the course syllabus and any external resource is cited in both the code (as a comment) and the README.md file.
- Only built-in libraries are allowed. Your program should not and cannot use anything that must be installed from an external source.
- Only one .cpp file is allowed! No header files, object files, or additional .cpp files -- just expertbot.cpp.

## Example

[ScottBot](scottbot), an expert on the Scott Pilgrim series, is given as an example executable chatbot. You can run it with the command `./scottbot`
Try asking it things like "What is Clash at Demonhead?", "Who is Scott", "Where is Second Cup", "When did the video game release?"

## Rubric ( 100 Points total )

### Bot Functionality

| Points | Criteria |
| :----: | :------- |
| **5 pts** | Give your chatbot an introduction where it says it's name and what it's an expert on |
| **5 pts** | Ask for the user's name and save it as a variable |
| **2 pts** | Have the user end the conversation with a keyword or phrase that says goodbye to the user |
| **8 pts** | Have 4 'Where' based answers (2 pts each) |
| **8 pts** | Have 4 'Who' based answers (2 pts each) |
| **8 pts** | Have 4 'What' based answers (2 pts each) |
| **8 pts** | Have 4 'When' based answers (2 pts each) |
| **8 pts** | Have 4 'fun facts' about the topic (2 pts each) |
| **3 pts** | Have the bot create a themed emoji or image based on the topic when asked 'Show me a picture' |
| **5 pts** | If the chatbot doesn't understand the input, have it say so and default to either randomly having the user ask about another subcategory or providing a randomly selected fun fact | 
| **5 pts** | Have the bot provide an external link to another resource in at least 5 of its responses | 
| **5 pts** | Each answer is a complete sentence with a minimum of 4 words. |

**(70 points total)**


### Code

| Points | Criteria |
| :----: | :------- |
| **2 pts** | Name, date, and program description |
| **3 pts** | A `void` return function that formats and prints the output of the bot's text with the bot's name in square brackets |
| **3 pts** | A `string` return function that formats the input of the user's text with the user's name in square brackets and returns the input text given |
| **3 pts** | Links to references for each "fact" given by the bot as a comment (if applicable) |
| **4 pts** | Code is commented, clear, and concise (e.g. functions and large sections of code have comments describing what they do, variables are properly named using self-documenting identifiers) |
| **5 pts** | Code compiles without errors |

**(20 points total)**

### README.md

| Points | Criteria |
| :----: | :------- |
| **2 pts** | Name, date, and program description |
| **2 pts** | Section on how to compile and run the chatbot |
| **2 pts** | Section with all of the keyword commands used for the chatbot (all of the "who", "what", "when", "where" and their keywords for answers) |
| **1 pts** | Section on example usage with the chatbot (does not have to be fully extensive or show every answer) |
| **1 pts** | Section with a list of references used and any generative AI chat conversations used to develop the bot |

**(10 points total)**


### Bonus Challenge

- Add a **trivia game** feature where the bot asks a series of 5 randomly selected questions based ONLY on the previous answers it gave in that session. Clear the screen of any text before starting this game. Have the bot score the user based on how many questions they get correct.

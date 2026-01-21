/* 
    Code by M Charity
    Date: 9/4/2025
    Program Description:
        This is an expert chatbot. Who is an expert
        on the subject of the Scott Pilgrim series.
*/


#include <iostream>         // for cout, cin, endl
#include <stdlib.h>         // for rand, srand
#include <time.h>           // for time (seeding rand)
using namespace std;


// ----- GLOBAL VARIABLES AND FUNCTIONS ----- //

string USER_NAME = "User";
string goodbye_command = "exit";

// random number generator function
int random(int min, int max){
    return rand() % (max - min + 1) + min;
}

// shows output for the bot
void botOut(string message){
    cout << "[Scott Bot]: " << message << endl;
}

string lowercase(string str){
    for (int i = 0; i < str.length(); i++){
        str[i] = tolower(str[i]);
    }
    return str;
}

// checks if a sub string is in a string
bool inStr(string str, string sub){
    return lowercase(str).find(lowercase(sub)) != string::npos;
}

// gets input from the user and formats it appropriately
string userIn(){
    string user_input = "";
    cout << "[" << USER_NAME << "]: ";
    getline(cin, user_input);
    return user_input;
}

// define function prototypes
string whatQ(string question);
string whenQ(string question);
string whereQ(string question);
string whoQ(string question);
string funfact();
void pic();
string defaultQ();

// ----- MAIN FUNCTION ----- //

int main(){

    srand(time(NULL)); // seed the random number generator (so that it's different each time)

    // introduction
    botOut("Hey! I'm ScottBot, the expert on everything Scott Pilgrim! What's your name?");
    USER_NAME = userIn();
    botOut("Nice to meet you, " + USER_NAME + "! Ask me anything about Scott Pilgrim or type '" + goodbye_command + "'  to leave.");

    string user_input = lowercase(userIn());

    while(user_input != goodbye_command){
        // determine type of question and respond accordingly
        if (inStr(user_input, "what")){
            botOut(whatQ(user_input));
        }else if (inStr(user_input, "when")){
            botOut(whenQ(user_input));
        }else if (inStr(user_input, "where")){
            botOut(whereQ(user_input));
        }else if (inStr(user_input, "who")){
            botOut(whoQ(user_input));
        }else if (inStr(user_input, "fun fact")){
            botOut(funfact());
        }else if (user_input == "Show me a picture" || user_input == "picture" || user_input == "pic"){
            pic();
        }else{
            botOut(defaultQ());
        }
        
        user_input = userIn();
    }
    botOut("It was nice chatting with you, " + USER_NAME + "! See you later!");

    return 0;
}

// ---- DEFINE FUNCTIONS HERE ----- //

string whatQ(string question){
    string answer = "";
    if (inStr(question, "sex bob-omb")){
        answer = "Sex Bob-Omb is a fictional band from the Scott Pilgrim series composed of Scott Pilgrim, Stephen Stills, and Kim Pine. "
            "The name is based off of a portmanteau of the Sex Pistols and Super Mario Bob-ombs.";
    }else if (inStr(question, "bass")){
        answer = "Scott uses a red Rickenbacker 4001 (4003 in the movie) bass guitar in the series. Here is the Wikipedia article about it! https://en.wikipedia.org/wiki/Rickenbacker_4001";
    }else if (inStr(question, "sword") || inStr(question, "katana")){
        answer = "Scott Pilgrim uses a katana sword in the series. He first acquires the Power of Love after defeating Roxy Richter, one of Ramona's evil exes. He then upgrades it to the Power of Self-Respect/Understanding while fighting Gideon Graves.";
    }else if(inStr(question, "clash at demonhead")){
        answer = "Clash at Demonhead is a fictional band in the Scott Pilgrim series. The band is led by Envy Adams, Scott Pilgrim's ex-girlfriend. "
            "The band's name is a reference to the NES game Clash at Demonhead.";
    }else{
        answer = defaultQ();
    }
    return answer;
}

string whenQ(string question){
    string answer = "";
    if (inStr(question, "published") || inStr(question, "book")){
        answer = "The Scott Pilgrim series was published from 2004 to 2010 with 6 volumes.";
    }else if (inStr(question, "movie")){
        answer = "The Scott Pilgrim movie was released in 2010.\n Here is a link to the trailer page! https://www.youtube.com/watch?v=7wd5KEaOtm4";
    }else if (inStr(question, "game")){
        answer = "The Scott Pilgrim vs. the World The Video Game was originally released in 2010 and re-released in 2021."
                 "\n Here is a link to the Steam page: https://store.steampowered.com/app/2215260/Scott_Pilgrim_vs_The_World_The_Game__Complete_Edition/";
    }else if(inStr(question, "tv show")){
        answer = "Scott Pilgrim Takes Off was released on Netflix in 2023.";
    }else{
        answer = defaultQ();
    }
    return answer;
}

string whereQ(string question){
    string answer = "";
    if (inStr(question, "setting") || inStr(question, "take place")){
        answer = "The Scott Pilgrim series is set in Toronto, Canada.";
    }else if (inStr(question, "lee's palace")){
        answer = "Lee's Palace was a real music venue located in Toronto, Canada. It is featured in the Scott Pilgrim series as the venue for the Clash at Demonhead concert.";
    }else if(inStr(question, "subspace")){
        answer = "Subspace is a fictional dimension that Ramona Flowers travels through using various portals around Toronto -- including one out of Scott's head.";
    }else if(inStr(question, "second cup")){
        answer = "Second Cup is a real Canadian coffee shop chain. Stacey Pilgrim and Julie Powers both work at the Second Cup in the series.";
    }else{
        answer = defaultQ();
    }
    return answer;
}

string whoQ(string question){
    string answer = "";
    if (inStr(question, "evil exes") || inStr(question, "evil X")){
        answer = "The Evil Exes are Ramona Flowers' seven evil ex-boyfriends who Scott Pilgrim must defeat in order to date her. "
            "They are Matthew Patel, Lucas Lee, Todd Ingram, Roxy Richter, Kyle & Ken Katayanagi (the Katayanagi Twins), and Gideon Graves.";
    }else if(inStr(question, "ramona flowers")){
        answer = "Ramona Flowers is Scott Pilgrim's love interest in the series. She is American and works as a delivery girl for Amazon.ca. She has the ability to travel through subspace and wields a hammer as a weapon.";
    }else if(inStr(question, "scott pilgrim")){
        answer = "Scott Pilgrim is the main character of the series. He is a 23-year-old slacker and bassist for the band Sex Bob-Omb.";
    }else if(inStr(question, "knives chau")){
        answer = "Knives Chau is a 17-year-old high school student who dates Scott Pilgrim at the beginning of the series. She is a big fan of Scott and is very skilled with a katana.";
    }else{
        answer = defaultQ();
    }
    return answer;
}

string funfact(){
    int randIndex = random(1,4);
    string fact = "";
    if (randIndex == 1){
        fact = "Fun Fact: The character of Scott Pilgrim was named after the song by the Canadian girl band Plumtree! The song was also featured on the soundtrack! \n Here is a link to the song: https://open.spotify.com/track/0lVvrtbTlHCbyaUCwxsEoR";
    }else if (randIndex == 2){
        fact = "Fun Fact: Many of the shirts worn by Scott are band shirts of the Smashing Pumpkins. This is because the initials of the band matches Scott's initials (SP).";
    }else if (randIndex == 3){
        fact = "Fun Fact: The actor who played Scott Pilgrim in the movie, Michael Cera, can also play the bass in real life! All of the other actors in the band Sex Bob-Omb had to learn how to play their instruments for the movie.";
    }else{
        fact = "Fun Fact: Anamanaguchi, the band who created the soundtrack for the Scott Pilgrim vs. the World video game, also created the soundtrack for the Scott Pilgrim Takes Off TV show!";
    }
    return fact;
}

void pic(){
    cout << "⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ " << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣷⡒⠶⢶⣤⣤⣤⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣷⡄⠀⠀⠀⠀⠀⠀⠉⠉⠛⠛⠓⠦⢤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⠀⠀⠀⠀⢀⣀⣀⣀⣤⠤⠤⠶⠶⠶⠶⠿⠿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠛⠶⣤⣀⠀⢶⣄⡀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠋⠉⠋⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠷⣼⡈⢳⣄" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠃⠠⢹" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠨" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠏⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⡄⠀⠀⣦⠀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⣿⡆⠀⠀⠀⠀⠀⠀⠀⠀⣴⠃⠀⠀⠀⠀⠀⠀⣀⣴⣶⠟⣿⠃⠀⢀⡟⠀⣼⠀⠀⠀⠀⢻⡀⠀⠀⠀⠀⠀⠀" << endl;
    cout << "⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢻⠦⣤⣘⣿⡆⡀⠀⠀⠀⠀⠀⣼⠁⠀⠀⢀⣠⣴⣾⠿⠛⠉⠀⣸⠇⠀⢀⣾⡇⢠⣿⣧⡀⠀⠀⢸⣷⠀⠀⠰⠀⠀⠀" << endl;
    cout << "⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣧⠀⠉⠉⠙⠂⠀⠀⠀⠀⣸⠁⣀⣴⡾⠿⠋⠉⠀⠀⠀⢀⣰⡏⠀⣠⣾⠏⣧⢸⡁⠻⣷⡀⠀⢸⡻⣷⡀⠀⠀⢠⠀" << endl;
    cout << "⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣄⠀⠀⠀⠀⠀⠀⡤⠴⣿⣾⣿⣿⣿⣿⣿⣶⣶⣶⣶⣿⣏⣴⡾⠋⠁⠀⣿⣾⣿⣶⣿⣿⣦⣼⣿⣿⣷⡀⠀⢸⡇" << endl;
    cout << "⡇⠀⠀⠀⣀⡤⠖⠒⢤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣄⠀⠀⠀⠀⡼⠃⠀⠉⣭⠟⠛⠛⠛⠛⠛⠛⢿⣿⢿⠟⠁⠀⠀⠀⠀⠛⠛⢻⡿⠟⠛⠛⠛⠛⢿⣿⣿⣄⢸⣷" << endl;
    cout << "⣇⡠⠴⠛⠀⠀⠀⠀⠀⠈⠙⠓⠶⠤⣤⣄⣀⣀⣀⠀⠀⠀⠀⠀⢻⣦⡀⠀⢸⠃⠀⠀⡾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠻⣄⠀⠀⠀⠀⠀⠀⠀⣴⠋⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣧⡿" << endl;
    cout << "⡏⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠙⠒⠒⢒⣲⡿⠃⣰⡇⠀⣠⣾⠁⠀⠀⠀⠀⠀⣀⡀⠀⠀⠀⢻⡄⠀⠀⠀⠀⠀⣼⠁⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠘⣿⢿" << endl;
    cout << "⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⢿⣦⣤⣠⣿⡷⠿⣥⣿⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⢸⡇⠀⠀⠀⠀⢠⡇⠀⠀⠀⠀⢸⣿⡇⠀⠀⠀⠀⠀⢸⣯" << endl;
    cout << "⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢹⡇⢰⡇⠈⣿⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠀⣸⡇⠀⠀⠀⠀⠻⡆⠀⠀⠀⠀⠈⠉⠀⠀⠀⠀⠀⠀⢸⢿" << endl;
    cout << "⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣇⠈⢷⣠⡏⢷⡀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡿⠁⠀⢀⠀⠀⠀⢷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡟⢼" << endl;
    cout << "⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⣆⠀⢹⠁⠀⠙⠶⣤⣀⣀⣀⣀⣠⠾⠋⠀⠰⠞⠛⠃⠀⠀⠈⠳⣤⣀⠀⠀⠀⠀⠀⢀⣀⡴⠋⢀⡀" << endl;
    cout << "⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠷⣾⡄⠀⠀⠀⠀⠀⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠓⠒⠒⠚⠋⠁⠀⠀⣸⠛" << endl;
    cout << "⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣷⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡿⣶" << endl;
    cout << "⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣷⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡟⠁⣸" << endl;
    cout << "⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⣦⣄⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⠏⣠⠞⠉" << endl;
    cout << "⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠻⢷⣦⣤⣀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣴⡾⠟⣻⡿⠟⠁⠀⠀" << endl;
    cout << "⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠙⠻⠿⠿⠷⣶⣶⣶⣶⣶⠶⠾⠿⣿⡟⠉⠁⠀⠀⠁⠀⠀⠀⠀⠀" << endl;
    cout << "⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣤⣤⣴⣾⡇⠀⠀⠀⠀⠀⠀⢻⣷⠶⠶⣶⠶⠶⠶⠶⠶⣶⣤" << endl;
    cout << "⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣶⠿⠛⠛⠋⠉⠉⢧⡀⠙⠻⠦⣤⣤⣤⡤⠶⠛⢁⣤⠾⠋⠀⠀⠀⠀⠀⠀⠘" << endl;
    cout << "⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⢏⠀⠀⠀⠀⠀⠀⠀⠀⠙⠳⠦⢤⣤⣤⣤⠤⠶⠾⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⢰" << endl;
    cout << "⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⢻⡇⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡰⠋" << endl;
    cout << "⡅⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⢀⣿⠋⠈⣇⠀⠀⠀⠀⣿⠛⠛⠛⠛⠛⠛⠛⣻⣟⠛⠛⠛⠛⠒⠒⠛⢻⡿⠀⠀⠀⡴⠃⠀" << endl;
    cout << "⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⠏⠀⠀⠘⡇⠀⠀⠀⠹⣆⠀⠀⡖⠒⢠⡼⠁⠘⣆⠀⢠⠤⠤⠤⡼⠋⠀⠀⠀⣼⠁⠀⠀" << endl;
    cout << "⢇⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣴⣿⣀⣤⣄⣀⣯⣀⣤⣄⣀⣹⣦⣀⣷⣦⣏⣀⣀⣀⣨⣦⣼⣤⣤⣾⣁⣀⣀⣀⣼⣅⣀⣀⣀" << endl;
}

string defaultQ(){
    string response =  "I'm not sure how to answer that. ";
    if (random(1,2) == 1){
        response += "Ask me about ";
        string topics[10] = {"the Evil Exes", "Scott's bass", "Sex Bob-omb", "subspace", "the movie", "the game", "the TV show", "the clash at demonhead", "Ramona Flowers", "Knives Chau"};
        response += topics[random(0,9)] + "!";
    }else{
        response += "But here's a fun fact instead!\n" + funfact();
    }

    return response;
}




// ----- END OF PROGRAM ----- //
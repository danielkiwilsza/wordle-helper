/* -------------------------------- */
/* Wordle Helper by Daniel Kiwilsza */
/* -------------------------------- */

#include <vector>
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string correctletter;
    std::string wrongspot;
    std::string wrongletter;
    std::string line;
    std::vector<std::string> words;

    unsigned int listcounter = 0;
    unsigned int lettercounter = 0;
    unsigned int wronglettercounter = 0;
    unsigned int wrongspotcounter = 0;

    int wrong = 0;
    int attempts = 0;
    int found = 0;

    std::vector<std::string> checklist;


    //open text file with 5-letter words and save into a vector
    std::ifstream myfile ("words.txt");

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            words.push_back(line);
        }

        myfile.close();
    }
    else
    {
        //if text file isn't available, close program
        std::cout << "Unable to open file." << std::endl;
        myfile.close();

        return 1;
    }

    //print out number of words in vector
    std::cout << "Word list size: " << words.size() << std::endl;


    //only loop through 5 times because there are a max of 6 guesses in Wordle and first guess can be any word
    while (attempts < 5)
    {
        //ask user to input letters that are in the correct spot (green letters)
        //replace invalid letters with hyphens and user should only input 5 characters
        do
        {
            std::cout << "\nEnter characters that are in the correct spot:" << std::endl;
            std::cin >> correctletter;
        }
        while (correctletter.length() !=5);

        //ask user to input letters that are in the word but not in the right spot (yellow letters)
        //replace invalid letters with hyphens and user should only input 5 characters
        do
        {
            std::cout << "\nEnter characters that are in the incorrect spot:" << std::endl;
            std::cin >> wrongspot;
        }
        while (wrongspot.length() !=5);

        //ask user to input letters that are not in the word (grey letters)
        std::cout << "\nEnter characters that are not in the word:" << std::endl;
        std::cin >> wrongletter;
        std::cout << std::endl;


        //iterate through list of 5-letter words
        while (listcounter < words.size())
        {
            std::string s = words.at(listcounter);

            //reset 'wrong' parameter that determines if word is valid
            wrong = 0;

            //iterate through the letters of the word
            for (lettercounter = 0; lettercounter < s.size(); lettercounter++)
            {
                //check for green letters
                if (correctletter.at(lettercounter) != '-')
                {
                    //if a letter of the word doesn't match a green letter in the same spot
                    if (correctletter.at(lettercounter) != s.at(lettercounter))
                    {
                        //word is invalid
                        wrong = 1;
                    }
                }
                else
                {
                    //check if letter is any of the gray letters
                    for (wronglettercounter = 0; wronglettercounter < wrongletter.size(); wronglettercounter++)
                    {
                        if (s.at(lettercounter) == wrongletter.at(wronglettercounter))
                        {
                            //word is invalid
                            wrong = 1;
                        }
                    }
                }
            }


            //iterate through 'wrongspot' to make sure none of the letters in the word match and reside in the same spots as the yellow letters
            for (wrongspotcounter = 0; wrongspotcounter < wrongspot.size(); wrongspotcounter++)
            {
                if (wrongspot.at(wrongspotcounter) == s.at(wrongspotcounter))
                {
                    //word is invalid
                    wrong = 1;
                }
            }


            if (wrongspot != "-----")
            {
                //iterate through 'wrongspot' again to make sure each valid letter is satisfied
                for (wrongspotcounter = 0; wrongspotcounter < wrongspot.size(); wrongspotcounter++)
                {
                    if (wrongspot.at(wrongspotcounter) != '-')
                    {
                        found = 0;

                        //compare the one character from 'wrongspot' to all the letters in the word
                        for (lettercounter = 0; lettercounter < s.size(); lettercounter++)
                        {
                            //if a letter from 'wrongspot' is found in the word and it's not in the same position as the letter in the word,
                            //then the character from 'wrongspot' is satisfied
                            if ((s.at(lettercounter) == wrongspot.at(wrongspotcounter)) && (wrongspotcounter != lettercounter))
                            {
                                found = 1;
                            }
                        }

                        //if we never matched the character from 'wrongspot', word is invalid
                        if (!found)
                        {
                            wrong = 1;
                        }
                    }
                }
            }
            else
            {
                //set 'found' to 1 because we have no characters to match for each word
                found = 1;
            }


            //word is valid if 'wrong' isn't set to 1
            if (!wrong)
            {
                //put into a vector that will be displayed for the user later
                checklist.push_back(s);
            }

            //increment the list counter
            listcounter++;
        }


        //print out all valid words
        for (listcounter = 0; listcounter < checklist.size(); listcounter++)
        {
            std::cout << checklist.at(listcounter) << std::endl;
        }

        std::cout << "\nNumber of words: " << checklist.size() << std::endl;

        //clear vector
        checklist.clear();

        //increment number of attempts and loop back
        attempts++;
    }

    return 0;
}
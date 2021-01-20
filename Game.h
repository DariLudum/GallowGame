#pragma once

#include <Windows.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>

class Game
{
    bool MainFlag;

    std::string Encrypt(std::string toEncrypt)
    {
        const char Key[5] = { 'E', 'N', 'I', 'A', 'C' };
        std::string Output{ toEncrypt };

        for (int i{ 0 }; i < toEncrypt.size(); ++i)
        {
            Output[i] = toEncrypt[i] ^ Key[i % (sizeof(Key) / sizeof(char))];
        }
        return Output;
    }

    void Draw(int Player)
    {
        if (Player == 5)
             {
                 std::cout << std::endl << std::endl;
                 std::cout << "  +--------+         " << std::endl;
                 std::cout << "  |        |         " << std::endl;
                 std::cout << "  |                  " << std::endl;
                 std::cout << "  |                  " << std::endl;
                 std::cout << "  |                  " << std::endl;
                 std::cout << "  |                  " << std::endl;
                 std::cout << "  |                  " << std::endl;
                 std::cout << "  ===================" << std::endl;
             }   
        else if (Player == 4)
        {
            std::cout << std::endl << std::endl;
            std::cout << "  +--------+         " << std::endl;
            std::cout << "  |        |         " << std::endl;
            std::cout << "  |        0         " << std::endl;
            std::cout << "  |        |         " << std::endl;
            std::cout << "  |                  " << std::endl;
            std::cout << "  |                  " << std::endl;
            std::cout << "  |                  " << std::endl;
            std::cout << "  ===================" << std::endl;
        }
        else if (Player == 3)
        {
            std::cout << std::endl << std::endl;
            std::cout << "  +--------+         " << std::endl;
            std::cout << "  |        |         " << std::endl;
            std::cout << "  |        0         " << std::endl;
            std::cout << "  |       /|         " << std::endl;
            std::cout << "  |                  " << std::endl;
            std::cout << "  |                  " << std::endl;
            std::cout << "  |                  " << std::endl;
            std::cout << "  ===================" << std::endl;
        }
        else if (Player == 2)
        {
            std::cout << std::endl << std::endl;
            std::cout << "  +--------+         " << std::endl;
            std::cout << "  |        |         " << std::endl;
            std::cout << "  |        0         " << std::endl;
            std::cout << "  |       /|\\       " << std::endl;
            std::cout << "  |                  " << std::endl;
            std::cout << "  |                  " << std::endl;
            std::cout << "  |                  " << std::endl;
            std::cout << "  ===================" << std::endl;
        }
        else if (Player == 1)
        {
            std::cout << std::endl << std::endl;
            std::cout << "  +--------+         " << std::endl;
            std::cout << "  |        |         " << std::endl;
            std::cout << "  |        0         " << std::endl;
            std::cout << "  |       /|\\       " << std::endl;
            std::cout << "  |       /          " << std::endl;
            std::cout << "  |                  " << std::endl;
            std::cout << "  |                  " << std::endl;
            std::cout << "  ===================" << std::endl;
        }
        else if (Player == 0)
        {
            std::cout << std::endl << std::endl;
            std::cout << "  +--------+         " << std::endl;
            std::cout << "  |        |         " << std::endl;
            std::cout << "  |        @         " << std::endl;
            std::cout << "  |       /|\\       " << std::endl;
            std::cout << "  |       / \\       " << std::endl;
            std::cout << "  |                  " << std::endl;
            std::cout << "  |                  " << std::endl;
            std::cout << "  ===================" << std::endl;
        }
    }

        void Menu()
        {
            while (MainFlag)
            {
                std::cout << "(Set word before starting game)" << std::endl;
                std::cout << "\n[1] Start game." << std::endl;
                std::cout << "\n[2] Add word." << std::endl;
                std::cout << "\n[3] Add random word." << std::endl;
                std::cout << "\n[4] Delete word." << std::endl;
                std::cout << "\n[?] Any other key to exit." << std::endl;

                uint16_t Choice;
                std::cin >> Choice;
                system("cls");

                if (Choice == 1)
                {
                    std::ifstream InCounter;
                    uint16_t Count{ 0 };

                    InCounter.open("EncryptedWord.txt");

                    if (InCounter.is_open())
                    {
                        std::string Lines;

                        while (getline(InCounter, Lines))
                        {
                            Count++;
                        }

                    }

                    InCounter.close();

                    uint16_t RandomNumber = 1 + rand() % (Count);
                    std::ifstream File;
                    std::string Line;

                    File.open("EncryptedWord.txt");

                    if (File.is_open())
                    {
                        uint16_t  SearchValue{ 1 };
                        while (getline(File, Line))
                        {
                            if (RandomNumber == SearchValue)
                            {
                                break;
                            }
                            else
                            {
                                SearchValue++;
                            }
                        }
                    }

                    Line = Encrypt(Line);

                    bool Step{ 0 };

                    uint16_t Player1{ 6 };
                    uint16_t Player2{ 6 };
                    uint16_t Attempts{ 0 };
                    uint16_t StartTime = clock();

                    std::string Buffer;
                    std::string Player1_Word;
                    std::string Player2_Word;

                    for (int i{ 0 }; i < Line.length(); ++i)
                    {
                        Buffer.push_back('?');
                    }

                    while (Player1 != 0 || Player2 !=0)
                    {
                        ++Attempts;

                        for (int i{ 0 }; i < Buffer.length(); ++i)
                        {
                            std::cout << " " << Buffer[i] << " ";
                        }

                        if (Step == 0)
                        {
                            bool FlagOfSearch{ 0 };
                            bool FlagOfEnd{ 0 };
                            char Symbol;
 
                            std::cout << "\nPlayer 1, enter letter: ";
                            std::cin >> Symbol;
                         
                            for (int i{ 0 }; i < Line.length(); ++i)
                            {
                                if (Line[i] == Symbol)
                                {
                                    Player1_Word.push_back(Symbol);
                                    FlagOfSearch = 1;
                                    Line[i] = '0';
                                    Buffer[i] = Symbol;
                                }
                            }

                            if (!FlagOfSearch)
                            {
                                Player1--;
                                Draw(Player1);
                            }

                            for (int i{ 0 }; i < Line.length(); ++i)
                            {
                                if (Line[i] != '0') FlagOfEnd = 1;
                            }

                            if (!FlagOfEnd)
                            {
                                std::cout << "\nPlayer 1 wins!" << std::endl;
                                break;
                            }
                        }

                        else
                        {
                            bool FlagOfSearch{ 0 };
                            bool FlagOfEnd{ 0 };
                            char Symbol;

                            std::cout << "\nPlayer 2, enter letter: ";
                            std::cin >> Symbol;
                           
                            for (int i{ 0 }; i < Line.length(); ++i)
                            {
                                if (Line[i] == Symbol)
                                {
                                    Player2_Word.push_back(Symbol);
                                    FlagOfSearch = 1;
                                    Line[i] = '0';
                                    Buffer[i] = Symbol;
                                }
                            }

                            if (!FlagOfSearch)
                            {
                                Player2--;
                                Draw(Player2);
                            }

                            for (int i{ 0 }; i < Line.length(); ++i)
                            {
                                if (Line[i] != '0') FlagOfEnd = 1;
                            }

                            if (!FlagOfEnd)
                            {
                                std::cout << "\nPlayer 2 wins!" << std::endl;
                                break;
                            }
                        }

                        Step = !Step;

                        if (Player1 == 0) std::cout << "\nPlayer 1 lost." << std::endl;
                        if (Player2 == 0) std::cout << "\nPlayer 2 lost." << std::endl;
                    }

                    File.close();
                    
                    uint16_t EndTime = clock();
                    uint16_t SearchTime = EndTime - StartTime;

                    std::cout << "\nNumber of attempts: " << Attempts << std::endl;
                    std::cout << "Player 1 letters: " << Player1_Word << std::endl;
                    std::cout << "Player 2 letters: " << Player2_Word << std::endl;
                    std::cout << "\Game time: " << SearchTime / 1000 << " seconds." << std::endl;

                    Sleep(9000); system("cls");
                }

                else if (Choice == 2)
                {
                    std::ofstream File;
                    std::string Word;

                    std::cin.get();
                    std::getline(std::cin, Word);

                    Word = Encrypt(Word);

                    File.open("EncryptedWord.txt", std::ios_base::app);
                    if (File.is_open()) File << Word;

                    system("cls");
                }

                else if (Choice == 3)
                {

                system("ping itstep.org");
                Sleep(1000); system("cls");
                }

                else if (Choice == 4)
                { 
                std::remove("EncryptedWord.txt"); system("cls");
                std::cout << "Encrypted word deleted." << std::endl;
                Sleep(2000); system("cls");
                }

                else
                {
                    MainFlag = 0;
                }
            }
        }

public:

    Game()
    {
        MainFlag = 1;
    }

    void Execute()
    {
        Menu();
    }

};

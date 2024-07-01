#include <iostream>
#include <ctime>
#include <vector>
#include <Windows.h>
#include <sstream>
#include <algorithm>
#include <set>
#include <iomanip>
#include <cstdlib>
#include <map>

// ╔═══╗   ╔═══╗   ╔═══╗   ╔═══╗   ╔═══╗
const std::string up = "\xE2\x95\x94\xE2\x95\x90\xE2\x95\x90\xE2\x95\x90\xE2\x95\x97\t\xE2\x95\x94\xE2\x95\x90\xE2\x95\x90\xE2\x95\x90\xE2\x95\x97\t\xE2\x95\x94\xE2\x95\x90\xE2\x95\x90\xE2\x95\x90\xE2\x95\x97\t\xE2\x95\x94\xE2\x95\x90\xE2\x95\x90\xE2\x95\x90\xE2\x95\x97\t\xE2\x95\x94\xE2\x95\x90\xE2\x95\x90\xE2\x95\x90\xE2\x95\x97";

// ╚═══╝   ╚═══╝   ╚═══╝   ╚═══╝   ╚═══╝
const std::string down = "\xE2\x95\x9A\xE2\x95\x90\xE2\x95\x90\xE2\x95\x90\xE2\x95\x9D\t\xE2\x95\x9A\xE2\x95\x90\xE2\x95\x90\xE2\x95\x90\xE2\x95\x9D\t\xE2\x95\x9A\xE2\x95\x90\xE2\x95\x90\xE2\x95\x90\xE2\x95\x9D\t\xE2\x95\x9A\xE2\x95\x90\xE2\x95\x90\xE2\x95\x90\xE2\x95\x9D\t\xE2\x95\x9A\xE2\x95\x90\xE2\x95\x90\xE2\x95\x90\xE2\x95\x9D";

// ╔═══╗   ╔═══╗
const std::string upHand = "\xE2\x95\x94\xE2\x95\x90\xE2\x95\x90\xE2\x95\x90\xE2\x95\x97\t\xE2\x95\x94\xE2\x95\x90\xE2\x95\x90\xE2\x95\x90\xE2\x95\x97";

// ╚═══╝   ╚═══╝
const std::string downHand = "\xE2\x95\x9A\xE2\x95\x90\xE2\x95\x90\xE2\x95\x90\xE2\x95\x9D\t\xE2\x95\x9A\xE2\x95\x90\xE2\x95\x90\xE2\x95\x90\xE2\x95\x9D";


// Flags for changing the console color
const char* RESET = "\033[0m";
const char* BLACK_TEXT = "\033[30m";
const char* RED_TEXT = "\033[31m";
const char* GREEN_TEXT = "\033[32m";
const char* YELLOW_TEXT = "\033[33m";
const char* BLUE_TEXT = "\033[34m";
const char* MAGENTA_TEXT = "\033[35m";
const char* CYAN_TEXT = "\033[36m";
const char* WHITE_TEXT = "\033[37m";

const char* BLACK_BACKGROUND = "\033[40m";
const char* RED_BACKGROUND = "\033[41m";
const char* GREEN_BACKGROUND = "\033[42m";
const char* YELLOW_BACKGROUND = "\033[43m";
const char* BLUE_BACKGROUND = "\033[44m";
const char* MAGENTA_BACKGROUND = "\033[45m";
const char* CYAN_BACKGROUND = "\033[46m";
const char* WHITE_BACKGROUND = "\033[47m";

enum suit
{
    worms,
    spades,
    crosses,
    diamonds
};

std::string suitToString(suit colour)
{
    switch (colour)
    {
        case worms:
            return "\xe2\x99\xa5";
            break;
        case spades:
            return "\xe2\x99\xa4";
            break;
        case crosses:
            return "\xe2\x99\xa7";
            break;
        case diamonds:
            return "\xe2\x99\xa6";
            break;
        default:
            break;
    }
}

class Card
{
private:
   int merit;

   suit colour;

public:

    int getMerit()
    {
        return merit;
    }

    suit getColour()
    {
        return colour;
    }

    Card(int merit, suit colour)
    {
        this->colour = colour;
        this->merit = merit;
    }

    void print()
    {
        std::cout << suitToString(colour) << merit << std::endl;
    }

    bool operator<(const Card& rhs) const noexcept
    {
        return this->merit < rhs.merit; 
    }

    bool operator==(const Card& rhs) const noexcept
    {
        return this->merit == rhs.merit && this->colour == rhs.colour;
    }
};

class Deck
{
private:
    std::vector<int> merits = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    
    std::vector<Card> cards{};

public:

    Deck()
    {
        for (int i = suit::worms; i <= suit::diamonds; i++)
        {
            for (int j = 0; j < merits.size(); j++)
            {
                cards.push_back(Card(merits[j], (suit)i));
            }
        }
    }

    std::vector<Card> sevenCards()
    {
        std::vector<Card> table{};

        while (table.size() != 7)
        {
            int i = rand() % 52;

            if (std::find(table.begin(), table.end(), cards[i]) == table.end())
                table.push_back(cards[i]);
        }

        return table;
    }

    void printTable(std::vector<Card>& table)
    {
        std::string suitStr = "";

        std::string meritStr = "";
        int merit = 0;

        std::string prefix = "";

        auto end = table.end();
        end--;
        end--;

        std::cout << up << std::endl;

        for (auto i = table.begin(); i != end; i++)
        {
            auto card = *i;
            suit suit = card.getColour();
            suitStr = suitToString(suit);

            if (suit == suit::worms || suit == suit::diamonds)
                prefix = RED_TEXT;
            else
                prefix = CYAN_TEXT;

            std::cout << "\xE2\x95\x91" << prefix << suitStr << RESET << "  \xE2\x95\x91\t";
        }

        std::cout << std::endl;

        for (auto i = table.begin(); i != end; i++)
        {
            auto card = *i;
            merit = card.getMerit();

            switch (merit)
            {
                case 10:
                    meritStr = "X";
                    break;
                case 11:
                    meritStr = "J";
                    break;
                case 12:
                    meritStr = "Q";
                    break;
                case 13:
                    meritStr = "K";
                    break;
                case 14:
                    meritStr = "A";
                    break;
                default:
                    meritStr = std::to_string(merit);
                    break;
            }

            std::cout << "\xE2\x95\x91 " << meritStr << " \xE2\x95\x91\t";
        }

        std::cout << std::endl;

        for (auto i = table.begin(); i != end; i++)
        {
            auto card = *i;
            suit suit = card.getColour();
            suitStr = suitToString(suit);

            if (suit == suit::worms || suit == suit::diamonds)
                prefix = RED_TEXT;
            else
                prefix = CYAN_TEXT;

            std::cout << "\xE2\x95\x91  " << prefix << suitStr << RESET << "\xE2\x95\x91\t";
        }

        std::cout << std::endl;

        std::cout << down << std::endl;

        std::cout << upHand << std::endl;

        for (auto i = end; i != table.end(); i++)
        {
            auto card = *i;
            suit suit = card.getColour();
            suitStr = suitToString(suit);

            if (suit == suit::worms || suit == suit::diamonds)
                prefix = RED_TEXT;
            else
                prefix = CYAN_TEXT;

            std::cout << "\xE2\x95\x91" << prefix << suitStr << RESET << "  \xE2\x95\x91\t";
        }

        std::cout << std::endl;

        for (auto i = end; i != table.end(); i++)
        {
            auto card = *i;
            merit = card.getMerit();

            switch (merit)
            {
            case 10:
                meritStr = "X";
                break;
            case 11:
                meritStr = "J";
                break;
            case 12:
                meritStr = "Q";
                break;
            case 13:
                meritStr = "K";
                break;
            case 14:
                meritStr = "A";
                break;
            default:
                meritStr = std::to_string(merit);
                break;
            }

            std::cout << "\xE2\x95\x91 " << meritStr << " \xE2\x95\x91\t";
        }

        std::cout << std::endl;

        for (auto i = end; i != table.end(); i++)
        {
            auto card = *i;
            suit suit = card.getColour();
            suitStr = suitToString(suit);

            if (suit == suit::worms || suit == suit::diamonds)
                prefix = RED_TEXT;
            else
                prefix = CYAN_TEXT;

            std::cout << "\xE2\x95\x91  " << prefix << suitStr << RESET << "\xE2\x95\x91\t";
        }

        std::cout << std::endl << downHand << std::endl;
    }

    void print()
    {
        for (int i = 0; i < cards.size(); i++)
        {
            cards[i].print();
        }
    }
};

class Dealer
{
private:
    void printResult(std::vector<Card>& table)
    {
        if (isFlashRoyal(table))
        {
            std::cout << "Flash royal" << std::endl;
            return;
        }

        if (isStraightFlash(table))
        {
            std::cout << "Straight flash" << std::endl;
            return;
        }

        if (isKare(table))
        {
            std::cout << "Kare" << std::endl;
            return;
        }

        if (isFullHouse(table))
        {
            std::cout << "Full house" << std::endl;
            return;
        }

        if (isFlash(table))
        {
            std::cout << "Flash" << std::endl;
            return;
        }

        if (isStraight(table))
        {
            std::cout << "Straight" << std::endl;
            return;
        }

        if (isSet(table))
        {
            std::cout << "Set" << std::endl;
            return;
        }

        if (isTwoPair(table))
        {
            std::cout << "Two pair" << std::endl;
            return;
        }

        if (isPair(table))
        {
            std::cout << "Pair" << std::endl;
            return;
        }

        std::cout << "Senior hand" << std::endl;
    }

    bool isPair(std::vector<Card>& table)
    {
        for (auto i = table.begin(); i != table.end() - 1; i++)
        {
            Card card = *i;
            for (auto j = i + 1; j != table.end(); j++)
            {
                Card secondCard = *j;
                if (card.getMerit() == secondCard.getMerit())
                    return true;
            }
        }

        return false;
    }

    bool isTwoPair(std::vector<Card>& table)
    {
        int count = 0;
        for (auto i = table.begin(); i != table.end() - 1; i++)
        {
            Card card = *i;
            for (auto j = i + 1; j != table.end(); j++)
            {
                Card secondCard = *j;
                if (card.getMerit() == secondCard.getMerit())
                    count++;
            }
        }

        return count >= 2;
    }

    bool isSet(std::vector<Card>& table)
    {
        for (auto i = table.begin(); i != table.end() - 2; i++)
        {
            Card card = *i;
            for (auto j = i + 1; j != table.end() - 1; j++)
            {
                Card secondCard = *j;
                
                for (auto k = j + 1; k != table.end(); k++)
                {
                    Card thirdCard = *k;

                    /*card.print();
                    secondCard.print();
                    thirdCard.print();
                    std::cout << "###" << std::endl;*/

                    if (card.getMerit() == secondCard.getMerit() && card.getMerit() == thirdCard.getMerit())
                        return true;
                }
            }
        }

        return false;
    }

    bool isKare(std::vector<Card>& table)
    {
        for (auto i = table.begin(); i != table.end() - 3; i++)
        {
            Card card = *i;
            for (auto j = i + 1; j != table.end() - 2; j++)
            {
                Card secondCard = *j;

                for (auto k = j + 1; k != table.end() - 1; k++)
                {
                    Card thirdCard = *k;

                    for (auto l = k + 1; l != table.end(); l++)
                    {
                        Card fourthCard = *l;

                        /*card.print();
                        secondCard.print();
                        thirdCard.print();
                        fourthCard.print();
                        std::cout << "###" << std::endl;*/

                        if (card.getMerit() == secondCard.getMerit() && card.getMerit() == thirdCard.getMerit() 
                            && card.getMerit() == fourthCard.getMerit())
                            return true;
                    }
                }
            }
        }

        return false;
    }

    bool isFlash(std::vector<Card>& table)
    {
        std::map<suit, int> countSuit;

        for (int i = 0; i < table.size(); i++)
        {
            suit suit = table[i].getColour();

            if (countSuit.find(suit) != countSuit.end())
                countSuit[suit] += 1;
            else
                countSuit.insert(std::make_pair(suit, 1));
            
        }

        for (auto pair : countSuit)
        {
            if (pair.second >= 5)
                return true;
        }

        return false;
    }

    bool isFullHouse(std::vector<Card>& table)
    {
        std::map<int, int> countMerit;

        for (int i = 0; i < table.size(); i++)
        {
            int merit = table[i].getMerit();

            if (countMerit.find(merit) != countMerit.end())
                countMerit[merit] += 1;
            else
                countMerit.insert(std::make_pair(merit, 1));
        }

        int two = 0;
        int three = 0; 

        for (auto i : countMerit)
        {
            if (i.second == 2)
                two += 1;
            else if (i.second >= 3)
                three += 1;
        }

        if (two > 0 && three > 0 || three > 1)
            return true;

        return false;
    }

    bool isStraight(std::vector<Card>& table)
    {
        std::sort(table.begin(), table.end());

        bool flag = false;

        for (int i = 0; i < 3 && !flag; i++)
        {
            for (int j = i + 1; j < 5 + i; j++)
            {
                flag = true; 
                if (table[j].getMerit() - table[j - 1].getMerit() != 1)
                {
                    flag = false;
                    break;
                }

            }
        }
        

        return flag;
    }

    bool isStraightFlash(std::vector<Card>& table)
    {
        std::sort(table.begin(), table.end());

        bool flag = false;

        for (int i = 0; i < 3; i++)
        {
            for (int j = i + 1; j < 5 + i; j++)
            {
                flag = true;
                if (table[j].getMerit() - table[j - 1].getMerit() != 1)
                {
                    flag = false;
                    break;
                }


            }

            if (flag)
            {
                if (table[i].getColour() == table[i + 1].getColour() &&
                    table[i].getColour() == table[i + 2].getColour() &&
                    table[i].getColour() == table[i + 3].getColour() &&
                    table[i].getColour() == table[i + 4].getColour())
                    return true;
            }
        }

        return false;


    }

    bool isFlashRoyal(std::vector<Card>& table)
    {
        std::sort(table.begin(), table.end());

        bool flag = false;

        for (int i = 0; i < 3; i++)
        {
            for (int j = i + 1; j < 5 + i; j++)
            {
                flag = true;
                if (table[j].getMerit() - table[j - 1].getMerit() != 1)
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                if (table[i].getColour() == table[i + 1].getColour() &&
                    table[i].getColour() == table[i + 2].getColour() &&
                    table[i].getColour() == table[i + 3].getColour() &&
                    table[i].getColour() == table[i + 4].getColour())
                {
                    if (table[i].getMerit() == 10 && table[i + 4].getMerit() == 14)
                        return true;
                }
            }
        }

        return false;
    }

public:
    void endGame(std::vector<Card>& table)
    {
        printResult(table);
    }

    void testEndGame(std::vector<Card>& table)
    {
        Deck deck = Deck();
        
        if (isFlashRoyal(table))
        {
            deck.printTable(table);

            printResult(table);
        }
        
    }
};
void test()
{
    Deck deck = Deck();
    Dealer dealer = Dealer();

    std::vector<Card> testTable{};

    for (int i = 0; i < 100000; i++)
    {
        testTable = deck.sevenCards();
        dealer.testEndGame(testTable);

    }

    //dealer.endGame(testTable);
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    srand(time(0));

    Deck deck = Deck();
    Dealer dealer = Dealer();

    while (true)
    {
        std::vector<Card> table = deck.sevenCards();

        deck.printTable(table);
        dealer.endGame(table);

        std::cout << "Next >> any keys | End >> e: ";

        char choice = ' ';
        std::cin >> choice;

        std::cout << std::endl;
        if (choice == 'e')
            break;
    }
}

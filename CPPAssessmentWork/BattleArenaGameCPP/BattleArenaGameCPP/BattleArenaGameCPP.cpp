// BattleArenaGameCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Character.cpp"

int takeDamage(int damage, int enemyTypeID, int playerTypeID)
{
    //I'm going to include 3 types, melee, magic, and sneaky which will work with melee beating sneaky, sneaky beating magic, and magic beating melee
    //super effective
    if ((enemyTypeID == 2 && playerTypeID == 1) || (enemyTypeID == 3 && playerTypeID == 2) || (enemyTypeID == 1 && playerTypeID == 3))
    {
        return damage * 2;
    }
    else if ((enemyTypeID == 1 && playerTypeID == 2) || (enemyTypeID == 2 && playerTypeID == 3) || (enemyTypeID == 3 && playerTypeID == 1)) //not very effective
    {
        return damage / 2;
    }
    else
    {
        return damage;
    }
    return 0; //default
}
//action one using a unit to attack an enemy
int attackAction(Character attacker)
{
    //this should return a random number between max damage and min damage
    std::cout << attacker.name << " attacks their enemy with a " << attacker.type << " attack!" << std::endl;
    return rand() % attacker.maxDamage + attacker.minDamage;
}
//action two using a turn to heal an ally. Enemies cannot do this!
int healAction(Character target)
{
    std::cout << target.name << " has been healed!" << std::endl;
    return target.maxHealth / 4;
}
//this will display the teams to the console
void displayTeams(Character enemyArr[], Character playerArr[])
{
    std::cout << "Enemy team:" << std::endl;
    for(int i=0;i<3;++i)
    {
        std::cout<<enemyArr[i].name<< " health: "<< enemyArr[i].currentHealth<<std::endl;
    }
    std::cout << "Player's team:" << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        std::cout << playerArr[i].name << " health: " << playerArr[i].currentHealth << std::endl;
    }
}
void arraySort(Character charArr[], int size)
{
    bool sorted = false;
    while (!sorted) {
        int count = 0; //this will be used to make sure the array is sorted, if it goes through the entire array without needing to swap two spots then it has been solved
        for (int i = 0; i < size - 1; i++)
        {
            if (charArr[i].currentHealth < charArr[i + 1].currentHealth)
            {
                Character tempCharacter = charArr[i];
                charArr[i] = charArr[i + 1];
                charArr[i + 1] = tempCharacter;
            }else
            {
                count++;
            }
        }
        if (count == size - 1)
        {
            sorted = true;
        }
    }
}
void playerTurn(Character playerTeam[], Character enemyTeam[])
{
    //basic temp variable setup
    std::string input;
    Character activeUnit;
    bool turnOver = false;
    bool attack = false;
    bool heal = false;
    bool actionTime = false; // this will let me know when an active unit has been selected
    while (!turnOver)
    {
        int count = 0;
        if (!actionTime) //select your character
        {
            std::cout << "Please select which unit you want to use this turn. (enter their name, spelling matters)" << std::endl;
            std::cin >> input;
            for (int i = 0; i < 3; ++i)
            {
                if (playerTeam[i].name == input && playerTeam[i].currentHealth > 0)
                {
                    activeUnit = playerTeam[i];
                    actionTime = true;
                }
                else
                {
                    count++;
                }
            }
            if (count == 3)
            {
                std::cout << "That character is either dead or not on your team." << std::endl;
                count = 0;
            }
        } else //this should only activate if the player has an activeUnit
        {
            if (attack || heal)
            {
                if(attack) //this will let the player choose an enemy to attack and attack them.
                {
                    std::cout << "Enter the name of the enemy you'd like to attack" << std::endl;
                    std::cin >> input;
                    for (int i = 0; i < 3; ++i)
                    {
                        if (enemyTeam[i].name == input && enemyTeam[i].currentHealth > 0)
                        {
                            enemyTeam[i].currentHealth-=takeDamage(attackAction(activeUnit),activeUnit.typeID,enemyTeam[i].typeID);
                            if(enemyTeam[i].currentHealth<0)
                            {
                                enemyTeam[i].currentHealth = 0;
                            }
                            return;
                        }
                        else
                        {
                            count++;
                        }
                    }
                    if (count == 3)
                    {
                        std::cout << "That character is either dead or not on the enemy team." << std::endl;
                        count = 0;
                    }
                }else if(heal) //this will have the player select the ally to heal and then call heal then exit this method
                {
                    std::cout << "Enter the name of the ally you'd like to heal" << std::endl;
                    std::cin >> input;
                    for (int i = 0; i < 3; ++i)
                    {
                        if (playerTeam[i].name == input && playerTeam[i].currentHealth > 0)
                        {
                            healAction(playerTeam[i]);
                            return;
                        }
                        else
                        {
                            count++;
                        }
                    }
                    if (count == 3)
                    {
                        std::cout << "That character is either dead or not on your team." << std::endl;
                        count = 0;
                    }
                }
            }
            else 
            {
                //select what to do, I forgot how to iterate through a string to set it all to lower case and saw I was almost out of time so I skipped it
                std::cout << "Would you like to attack or heal? (Enter a/attack or h/heal only accepts lowercase" << std::endl;
                std::cin >> input;
                if (input == "attack" || input == "a")
                {
                    attack = true;
                }
                else if (input == "heal" || input == "h")
                {
                    heal = true;
                }
            }
            
            
        }
    }
}//end of player turn
void enemyTurn(Character playArr[], Character enArr[])
{
    Character activeUnit = enArr[0]; //this should always be the enemy with the most health very basic ai coding here
    //the enemies only get to attack so they will only attack the strongest player unit to show off the sorter
    playArr[0].currentHealth -= takeDamage(attackAction(activeUnit), activeUnit.typeID, playArr[0].typeID);
    if (playArr[0].currentHealth < 0)
    {
        playArr[0].currentHealth = 0;
    }
}
bool checkWin(Character playArr[], Character enArr[])
{
    //I'm going to manually check I've spent too long on this game sorry I overscoped by a lot more then I thought an hour ago!
    if(playArr[0].currentHealth==0 && playArr[1].currentHealth == 0 && playArr[2].currentHealth == 0)
    {
        std::cout << "The enemy team has won!" << std::endl;
        return true;
    }
    if (enArr[0].currentHealth == 0 && enArr[1].currentHealth == 0 && enArr[2].currentHealth == 0)
    {
        std::cout << "The player team has won!" << std::endl;
        return true;
    }
    return false; //default
}
int main()
{
    //basic gameplay variable setup
    bool isOver = false;
    srand(time(NULL));
    //array setup
    Character enemyTeam[3];
    Character playerTeam[3];
    //character setups
    enemyTeam[0].name = "jimmy";
    enemyTeam[1].name = "timmy";
    enemyTeam[2].name = "billy";

    playerTeam[0].name = "hobbes";
    playerTeam[1].name = "pug";
    playerTeam[2].name = "joe";
    //a loop to give the rest of the stats to each team
    for(int i =0; i<3; ++i)
    {
        //enemy setup
        enemyTeam[i].maxHealth = 100;
        enemyTeam[i].currentHealth = enemyTeam[i].maxHealth;
        enemyTeam[i].typeID = i+1;
        enemyTeam[i].minDamage = rand() % 10 + 1;
        enemyTeam[i].maxDamage = rand() % enemyTeam[i].minDamage*2 + 1;

        //player setup
        playerTeam[i].maxHealth = 100;
        playerTeam[i].currentHealth = playerTeam[i].maxHealth;
        playerTeam[i].typeID = i+1;
        playerTeam[i].minDamage = rand() % 10 + 1;
        playerTeam[i].maxDamage = rand() % playerTeam[i].minDamage * 2 + 1;
    }
    //finaly step of character setup
    for (int i = 0; i < 3; ++i)
    {
        switch (enemyTeam[i].typeID)
        {
        case 1:
            enemyTeam[i].type = "melee";
            break;
        case 2:
            enemyTeam[i].type = "magic";
            break;
        case 3:
            enemyTeam[i].type = "sneaky";
            break;
        }
        switch (playerTeam[i].typeID)
        {
        case 1:
            playerTeam[i].type = "melee";
            break;
        case 2:
            playerTeam[i].type = "magic";
            break;
        case 3:
            playerTeam[i].type = "sneaky";
            break;
        }
    }
    //initial sort!
    arraySort(enemyTeam, 3);
    arraySort(playerTeam, 3);
    //main game loop
    while(!isOver)
    {
        //start display
        displayTeams(enemyTeam, playerTeam);
        //player turn
        playerTurn(playerTeam, enemyTeam);
        //enemy turn
        enemyTurn(playerTeam,enemyTeam);
        //sort arrays
        arraySort(enemyTeam, 3);
        arraySort(playerTeam, 3);
        //check for a win
        isOver = checkWin(playerTeam, enemyTeam);
    }
    return 0;
}



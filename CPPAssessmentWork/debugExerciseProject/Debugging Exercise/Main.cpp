// A Debugging Exercise by Marc Chee (marcc@aie.edu.au)
// 18/12/2016

// Marines are trying to "de-bug" an area (haha . . . haha)
// However something's up with this code . . . figure out what's going wrong
// When you're finished, there should be no compiler errors or warnings
// The encounter should also run and finish correctly as per the rules in the comments

// In many cases there are differences between what's in otherwise identical sections
// for Marines and Zerglings. It's good to be able to tell what the differences are
// and why they might be important.

// What's efficient and inefficient? Why?
// What uses more memory and what doesn't? Why?

// Last modified by Terry Nguyen (terryn@aie.edu.au)
// 10/09/2019

#include <iostream>
#include "Marine.h"
#include "Zergling.h"

using std::cout;
using std::endl;

int main()
{
	Marine squad[10];
	Zergling swarm[20];

	cout << "A squad of marines approaches a swarm of Zerglings and opens fire! The Zerglings charge!" endl;
	// Attack each other until only one team is left alive
	while (marineAlive() || zerglingAlive(swarm)) // If anyone is left alive to fight . . .
	{
		if (marineAlive()) // if there's at least one marine alive
		{
			for (size_t i = 0; i < squadSize; i++) // go through the squad
			{
				// each marine will attack the first zergling in the swarm
				cout << "A marine fires for " << squad[i].attack() << " damage. " << endl;
				int damage = squad[i].attack();
				swarm[0].takeDamage(damage);
				if (!swarm[0].isAlive()) // if the zergling dies, it is marked as such
				{
					cout << "The zergling target dies." << endl;
				}
			}
		}
		if (zerglingAlive(swarm)) // if there's at least one zergling alive
		{
			for (size_t i = 0; i < squadSize; i++) // loop through zerglings
			{
				cout << "A zergling attacks for " << i->attack() << " damage." << endl;
				squad[0]takeDamage(i->attack());
				if (squad[0]->isAlive())
				{

				}
				else
					cout << "The marine succumbs to his wounds." << endl;
					cout << "There are ??? marines left." << endl;
					
			}
		}
	}

	// Once one team is completely eliminated, the fight ends and one team wins
	cout << "The fight is over. ";
	if (marineAlive())
	{
		cout << "The Marines win." << endl;
	} else 
		cout << "The Zerg win." << endl;
	}
}

// Is there a Marine Alive?
bool marineAlive()
{
	return false;
}

// Is there a zergling Alive
bool zerglingAlive(Zergling * swarmArr, size_t arrSize)
{
	return false;
}

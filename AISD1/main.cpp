#include <iostream>
#include "stack.h"

#define INCREASE_SWITCH 'z'
#define DECREASE_SWITCH 'o'
#define PUSH_CARS 'w'
#define POP_CARS 'j'

#define RAIL_SWITCH_SIZE 10
using namespace std;

int main()
{
	char command;
	int temp, numberOFTracks, numberofCars, commandArg, numberOfCommands, currentTrack = 0;
	Stack railSwitch(RAIL_SWITCH_SIZE);
	Stack** tracks;

	cin >> numberOFTracks;
	tracks = new Stack*[numberOFTracks];

	for (int i = 0; i < numberOFTracks; i++)
	{
		cin >> numberofCars;
		tracks[i] = new Stack(512 + numberofCars);
		for (int q = 0; q < numberofCars; q++)
		{
			cin >> temp;
			tracks[i]->pushToPosition(temp, numberofCars - q -1);
		}
	}
	
	currentTrack = 0;
	cin >> numberOfCommands;
	for (int i = 0; i < numberOfCommands; i++)
	{
		cin >> command;
		cin >> commandArg;
		switch (command)
		{
			case INCREASE_SWITCH:
				currentTrack += commandArg % numberOFTracks;
				if (currentTrack >= numberOFTracks)
					currentTrack -= numberOFTracks;
				break;
			case DECREASE_SWITCH:
				currentTrack -= commandArg % numberOFTracks;
				if (currentTrack < 0)
					currentTrack += numberOFTracks;
				break;
			case POP_CARS:
				for (int q = 0; q < commandArg; q++)
				{
					if (!railSwitch.isEmpty() && !(tracks[currentTrack]->isFull()))
						tracks[currentTrack]->push(railSwitch.pop());
				}
				break;
			case PUSH_CARS:
				for (int q = 0; q < commandArg; q++)
				{
					if (!railSwitch.isFull() && !(tracks[currentTrack]->isEmpty()))
						railSwitch.push(tracks[currentTrack]->pop());
				}
				break;
			default:
				break;
		}
	}

	cout << railSwitch.getSize();
	while(!railSwitch.isEmpty())
		cout << " " << railSwitch.pop();
	cout << endl;
	for (int i = 0; i < numberOFTracks; i++)
	{
		cout << tracks[currentTrack]->getSize();
		while(!(tracks[currentTrack]->isEmpty()))
			cout << " " << tracks[currentTrack]->pop();
		cout << endl;
		currentTrack++;
		if (currentTrack >= numberOFTracks)
			currentTrack = 0;
	}
	for(int i = 0; i < numberOFTracks; i++)
		delete tracks[i];
	delete[] tracks;
	return 0;
}
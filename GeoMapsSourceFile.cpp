#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
const int maxMapSize = 9;//Used to define array sizes
const int mapArrayBound = maxMapSize - 1;
const int numOfChoices = 6;
const int mountainPassageNumber = 1;
void readMap(string userMapChoice,int userChoice);
int userChoiceFunction(int userChoice, string userMapChoice);
string mapChoice(string userMapChoice);
void choiceProcess(int userChoice, string userMapChoice);
void mountainPassage(int mapArrayPath[maxMapSize][maxMapSize]);
void mapRotation(int mapArray[maxMapSize][maxMapSize]);
void lakeFlooding(int mapArray[maxMapSize][maxMapSize]);
void Flooding(int startLocationX, int startLocationY, int lakeDepth, int mapFloodArray[maxMapSize][maxMapSize], string floodArray[maxMapSize][maxMapSize]);
void DisplayLakeFunction(string floodArray[maxMapSize][maxMapSize]);
int quitProgram();

int main()
{
	int userChoice=0;
	string userMapChoice = "map2.txt";
	userChoice = userChoiceFunction(userChoice, userMapChoice);
	choiceProcess(userChoice, userMapChoice);


}

int userChoiceFunction(int userChoice, string userMapChoice)
{
	cout << "Welcome!" << endl;
	cout << "Please choose one of the following options to proceed:" << endl;
	cout << "1.Choose a map file to load in the program.Default map is: \n>";
	cout << userMapChoice << endl;
	cout << "2.Load map into the program." << endl;
	cout << "3.Get mountain passage for the current map!" << endl;
	cout << "4.Rotate the map. " << endl;
	cout << "5.Flood the map." << endl;
	cout << "6.Close the program!" << endl;
	do
	{
		cout << "Please enter your choice '1', '2','3','4' or '5':\n>";
		cin >> userChoice;
	} while (userChoice<1||userChoice>6);
	
	return(userChoice);

}

void choiceProcess(int userChoice, string userMapChoice)
{
	while (userChoice < numOfChoices)
	{
		if (userChoice == 1)
		{
			userMapChoice = mapChoice(userMapChoice);
		}
		else if (userChoice == 2)
		{
			readMap(userMapChoice, userChoice);
		}
		else if (userChoice == 3)
		{
			readMap(userMapChoice, userChoice);
		}
		else if (userChoice == 4)
		{
			readMap(userMapChoice, userChoice);
		}
		else if (userChoice == 5)
		{
			readMap(userMapChoice, userChoice);
		}
		else
		{
			quitProgram();
		}
		userChoice = userChoiceFunction(userChoice, userMapChoice);
	}
}

string mapChoice(string userMapChoice)
{
	while (userMapChoice != "map1" || userMapChoice != "map2" || userMapChoice != "map3")
	{
		cout << "Please choose one of the following maps 'map1', 'map2' or 'map3':\n>";
		cin >> userMapChoice;
		if (userMapChoice == "map1" || userMapChoice == "map2" || userMapChoice == "map3") break;
	}

	//Validation of map choice
	if (userMapChoice == "map1")userMapChoice = "map1.txt";
	else if (userMapChoice == "map2")userMapChoice = "map2.txt";
	else if (userMapChoice == "map3")userMapChoice = "map3.txt";

	cout << "Map chosen succefully returning to main menu!" << endl;
	//returning map choice
	return userMapChoice;
	system("Pause");
}

void readMap(string userMapChoice,int userChoice )
{
	ifstream mapFile;
	mapFile.open(userMapChoice);

	int temporaryArray[maxMapSize][maxMapSize];
	if (!mapFile.is_open())
	{
		cout << "Error file not open!" << endl;
	}
	if (mapFile.is_open())
	{
		cout << "Map file opened!. Reading data from file!" << endl;
		while (!mapFile.eof())
		{
			for (int i = 0; i < maxMapSize; i++)
			{
				for (int j = 0; j < maxMapSize; j++)
				{
					mapFile >> temporaryArray[i][j];
				}
			}
		}
	}
	mapFile.close();
	int mapArray[maxMapSize][maxMapSize];
	for (int i = 0; i < maxMapSize; i++)
	{
		for (int j = 0; j < maxMapSize; j++)
		{
			mapArray[i][j] = temporaryArray[i][mapArrayBound-j];
		}
	}
	if(userChoice==2)
	{
		cout << "Displaying data from file:" << endl;
		for (int i = 0; i < maxMapSize; i++)
		{
			for (int j = 0; j < maxMapSize; j++)
			{
				cout << mapArray[i][mapArrayBound-j] << " ";
			}
			cout << endl;
		}
	}
	if (userChoice == 3)
	{
		mountainPassage(temporaryArray);
	}
	if (userChoice == 4)
	{
		mapRotation(mapArray);
	}
	if (userChoice == 5)
	{
		lakeFlooding(mapArray);
	}
	
	system("Pause");
	
}

void mountainPassage(int mapArrayPath[maxMapSize][maxMapSize])
{
	int coordinateChoice = 0;
	cout << "Please enter a coordinate between '0' and '8':\n>";
	cin >> coordinateChoice;
	int mountainPassageArray=0;
	cout << "Checking for easier path close to your coordinate!" << endl;
	cout << "Your safest mountain passage is:\n>";
	for (int i = 0; i < maxMapSize; i++)
	{
		if		(mapArrayPath[coordinateChoice][i] > mapArrayPath[coordinateChoice+1][i] )coordinateChoice++;
		else if (mapArrayPath[coordinateChoice][i] > mapArrayPath[coordinateChoice-1][i] )coordinateChoice--;
		mountainPassageArray = mapArrayPath[coordinateChoice][i];
		cout << mountainPassageArray << " ";
	}
	
	cout << endl;
}

void mapRotation(int mapArray[maxMapSize][maxMapSize])
{
	int userRotationChoice = 0;
	int diagonalMapRotation[maxMapSize][maxMapSize];
	cout << "Choose the way you would like to rotate the map:" << endl;
	cout << "1.Rotate the map by 90 degrees." << endl;
	cout << "2.Rotate the map vertically." << endl;
	cout << "3.Flip the map diagonally." << endl;
	cout << "Please choose one of the following options:\n>";
	cin >> userRotationChoice;
	if (userRotationChoice == 1)
	{
		for (int i = 0; i < maxMapSize; i++)
		{
			for (int j = 0; j < maxMapSize; j++)
			{
				cout<< mapArray[mapArrayBound-j][mapArrayBound-i]<<" ";
			}
			cout << endl;
		}
	}
	if (userRotationChoice == 2)
	{
		for (int i = 0; i < maxMapSize; i++)
		{
			for (int j = 0; j < maxMapSize; j++)
			{
				cout << mapArray[mapArrayBound-i][mapArrayBound-j] << " ";
			}
			cout << endl;
		}
	}
	if (userRotationChoice == 3)
	{
		for (int i = 0; i < maxMapSize; i++)
		{
			for (int j = 0; j < maxMapSize; j++)
			{
				diagonalMapRotation[i][j] = mapArray[i][mapArrayBound- j];
			}
		}
		for (int i = 0; i < maxMapSize; i++)
		{
			for (int j = 0; j < maxMapSize; j++)
			{
				if (i != j)
				{
					diagonalMapRotation[i][j] = diagonalMapRotation[mapArrayBound- i][mapArrayBound- j];
				}

			}
		}
		for (int i = 0; i < maxMapSize; i++)
		{
			for (int j = 0; j < maxMapSize; j++)
			{
				cout << diagonalMapRotation[i][j] << " ";
			}
			cout << endl;
		}
	}
}

void lakeFlooding(int mapArray[maxMapSize][maxMapSize])
{
	cout << "1.Continue to flood lake with default values." << endl;
	cout << "2.Contunue by entering custom coordinates for the lake." << endl;

	int userChoiceCoordinates = 0;
	cout << "Enter your choice:\n>";
	cin >> userChoiceCoordinates;

	if (userChoiceCoordinates == 1)
	{
		int startLocationX = 4;

		int startLocationY = 4;

		int lakeDepth = 300;

		string floodArray[maxMapSize][maxMapSize];
		int mapFloodArray[maxMapSize][maxMapSize];
		for (int i = 0; i < maxMapSize; i++)
		{
			for (int j = 0; j < maxMapSize; j++)
			{
				mapFloodArray[i][j] = mapArray[i][j];
			}
		}
		cout << "Creating the lake for you with default values:" << endl;
		cout << "Starting X: 4" << endl;
		cout << "Starting Y: 4" << endl;
		cout << "LakeDepth: 300" << endl;
		cout << "Lake:                                ^" << endl;
		Flooding(startLocationX, startLocationY, lakeDepth, mapFloodArray, floodArray);
		return;
	}
	else if (userChoiceCoordinates == 2);
	{
		int mapFloodArray[maxMapSize][maxMapSize];
		for (int i = 0; i < maxMapSize; i++)
		{
			for (int j = 0; j < maxMapSize; j++)
			{
				mapFloodArray[i][j] = mapArray[i][j];
			}
		}
		int startLocationX = 4;

		int startLocationY = 4;

		int lakeDepth = 300;
		string lakeDepthValue;

		cout << "Please input a starting flood location for the lake and press 'Enter' to continue." << endl;

		cout << "Starting X position:\n>";
		cin >> startLocationX;

		cout << "Starting Y position:\n>";
		cin >> startLocationY;

		cout << "Lake depth:\n>";
		cin >> lakeDepth;



		string floodArray[maxMapSize][maxMapSize];
		cout << "Creating the lake for you with custom values:" << endl;
		cout << "Starting X: " <<startLocationX;
		cout << endl;
		cout << "Starting Y: " << startLocationY;
		cout << endl;
		cout << "LakeDepth: " << lakeDepth;
		cout << endl;
		cout << "Lake:                                ^" << endl;
		Flooding(startLocationX, startLocationY, lakeDepth, mapFloodArray, floodArray);
	}
}

void Flooding(int startLocationX,int startLocationY,int lakeDepth,int mapFloodArray[maxMapSize][maxMapSize], string floodArray[maxMapSize][maxMapSize])
{
	
	bool floodedAreaOne = true;
	bool floodedAreaTwo = true;
	bool floodedAreaThree = true;
	bool floodedAreaFour = true;
	
	for (int i = 0; i < maxMapSize; i++)
	{
		for (int j = 0; j < maxMapSize; j++)
		{
			floodArray[i][j] = to_string(mapFloodArray[i][j]);
		}
	}

	if (mapFloodArray[startLocationX][startLocationY] > lakeDepth)
	{
		floodedAreaOne = false;
		floodedAreaTwo = false;
		floodedAreaThree = false;
		floodedAreaFour = false;
	}
	//X+ Y+
	for (int i = startLocationX; i < maxMapSize; i++)
		{
			for (int j = startLocationY; j < maxMapSize; j++)
			{
				if (mapFloodArray[j][i] <= lakeDepth && floodedAreaOne == true)
				{
					floodArray[j][i] = "000";
				}
				if (floodArray[j][i] == "000")
				{
					if (mapFloodArray[j + 1][i] <= lakeDepth && mapFloodArray[j][i + 1] > lakeDepth && mapFloodArray[j + 1][i + 1] > lakeDepth && mapFloodArray[j - 1][i + 1] > lakeDepth && mapFloodArray[j + 1][i] > lakeDepth) floodedAreaOne = false;
				}
			}
		}
	//X- Y-
	for (int i = startLocationX; i > -1; i--)
		{
			for (int j = startLocationY; j > -1; j--)
			{
				if (mapFloodArray[j][i] <= lakeDepth && floodedAreaTwo == true)
				{
					floodArray[j][i] = "000";
				}
				if (floodArray[j][i] == "000")
				{
					if (mapFloodArray[j+1][i] <= lakeDepth && mapFloodArray[j + 1][i-1]>lakeDepth && mapFloodArray[j][i - 1] > lakeDepth && mapFloodArray[j - 1][i] > lakeDepth &&mapFloodArray[j - 1][i - 1] > lakeDepth)  floodedAreaTwo = false;
				}
			}
		}	
	//X+ Y-
	for (int i = startLocationX; i < maxMapSize; i++)
	{
		for (int j = startLocationY; j > -1; j--)
		{
			if (mapFloodArray[j][i] <= lakeDepth && floodedAreaThree == true)
			{
				floodArray[j][i] = "000";
			}
			if (floodArray[j][i] == "000")
			{
				if (mapFloodArray[j - 1][i] <= lakeDepth && mapFloodArray[j ][i + 1] > lakeDepth && mapFloodArray[j - 1][i] > lakeDepth && mapFloodArray[j - 1][i+1] > lakeDepth && mapFloodArray[j + 1][i + 1] > lakeDepth) floodedAreaThree = false;
			}
		}
	}
	//X- Y+
	for (int i = startLocationX; i > -1; i--)
		{
			for (int j = startLocationY; j < maxMapSize; j++)
			{
				if (mapFloodArray[j][i] <= lakeDepth && floodedAreaFour == true)
				{
					floodArray[j][i] = "000";
				}
				if (floodArray[j][i] == "000")
				{
					if (mapFloodArray[j-1][i] <= lakeDepth && mapFloodArray[j-1][i-1] > lakeDepth && mapFloodArray[j][i - 1] > lakeDepth && mapFloodArray[j + 1][i - 1] > lakeDepth && mapFloodArray[j + 1][i] > lakeDepth)  floodedAreaFour = false;
				}
			}
		}	
	DisplayLakeFunction(floodArray);
}

void DisplayLakeFunction(string floodArray[maxMapSize][maxMapSize])
{
	//Display algorithm
	for (int i = 0; i < maxMapSize; i++)
	{
		for (int j = 0; j < maxMapSize; j++)
		{
			cout << floodArray[i][mapArrayBound - j] << " ";
		}
		cout << " | " << i;
		cout << endl;
	}
	cout << "<";
	for (int i = 0; i < maxMapSize; i++)
	{
		cout << "----";
	}
	cout << "X";
	cout << endl;
	for (int i = 0; i < maxMapSize; i++)
	{
		cout << " " << mapArrayBound - i << "  ";
	}
	cout << endl;
}

int quitProgram()
{
	return 0;
}
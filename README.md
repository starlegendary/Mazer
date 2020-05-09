# Mazer
*Game Coding Project C++*

## Team member:
* Shum Pui Yin Bill 3035687443
* Yeung Wing Pan Stacie 3035691004

## Story Background: 
*Once upon a time, there was a mythic monster who hunted and ate humans. Unfortunately, you are being caught. 
“HAWWWWW…...”
The monster is now awake. RUN…
… Or DIE
According to the tale your father told you, you know that there is only one exit in the maze and there are items and other people being caught in the maze, they can either help you or hurt you or kill you so focus...*

# Game Rules:
* Player needs to escape from the maze or kill the monster to win the game.
* Monster chases the player.
* If Monster caught the player(same room as player), the player fight with it.
* If the player is not dead (health <= 0), the player return the initial position (Starting Room).
* If player want to move to next room, the HP of player will be reduced.
* The amount of player's HP reduced is the number which is marked in each door.
* The player can increase the personal status through different items in different room.

# Game Element:
## Maze
* A N-maze is formed by N^2 number of rooms
* Each room has 4 doors.
* Each room includes random items.
* Door - allow use to go from one room to another
* Starting room - initial position of player
* Ending room - the exit of the maze

## Player
* Goal -  Escape from the maze or kill the monster
* Health (HP) - Default: S x 4 ( S = size of map). if this value is equal to zero, game over.
* Damage - equal to the size of map.
* Visibility - euqal to 1.
* Walk - move to another room.
* Use Item  - use the item which can change the personal status.

## Monster
* Goal - Catch the Player
* Health Point -  equal to S x 16 ( S = size of map).
* Damage - equal to  S x 2 ( S = size of map).
* Visibility - can only move 1 space a round (shortest path algorithm)

## Items
* Accelerator-Front
* Accelerator-Back
* Accelerator-Left
* Accelerator-Right
* Potion(HP +5)
* Bandage(HP +5)
* Potion(HP +10)
* First Aid Kit(HP +10)
* Knife(DMG +10)
* Sword(DMG +20)
* Detector(V +1)
* NULL


# Feature Implemented:

* Generation of random game sets or events: 
Random items are placed in each room and random door values(reduce the HP of player) are marked in each room.
Relevant function: random_item(int) , add_door(rooms& ,int), setup_doors_items(vector<vector<rooms>>&,int).
  
* Data structures for storing game status:
Storing the status of the map, the positions, HP value, damage, items and other data of the player and monster.

* Dynamic memory management:
For each round,  the status of the map, the positions, HP value, damage, items and other data of the player and monster keeps updating. 

* File input/output (e.g., for loading/saving game status):
If items are used, the game will load the file which stored the function of controlling items.

* Program codes in multiple files:
The main file is responsible for controlling game, management of user input and output of the game. 
How to use items, fighting process with monster and the movement of player in the game are clustered in isolated files. 

* Proper indentation and naming styles
* In-code documentation

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
## Maze
* A N-maze is formed by N^2 number of rooms
* Each room has 4 doors.
* Each room includes random items and events
* Door - allow use to go from one room to another
* Starting room - initial position of player
* Ending room - the exit of the maze

## Knight (controlled by player)
* Goal -  Find the exit out of the maze
* Health (HP)  - if this value is equal to zero, game over.
* Damage (D)  - zero
* Move (M) (-1 HP) 
  * Walk (-1HP) - move to another room 
  * Get Item  (-1 HP) - get the item in the room
  * Use Item (-1 HP) - use the item in the room

## Monster
* Goal - Catch the knight
* Health (HP) - infinite
* Damage (D) - infinite
* Move (M) (-1 HP) - can only move 1 space a round (shortest path algorithm)

## Items
* Magic Detector - show the distance between the player and the monster
* Food - distract the monster from given position
* Others

## Events:
* Meeting NPCs
* Finding Bodies
* Others

# Feature Implemented:
* Generation of random game sets or events: 
Random events may occur which can affect the player’s status. 
For example : items/ NPCs in different room and the effect of items
* Data structures for storing game status:
Storing the status of the map, the positions, HP value, damage, items and other data of the player and monster.
* Dynamic memory management:
For each round,  the status of the map, the positions, HP value, damage, items and other data of the player and monster keeps updating. 
* File input/output (e.g., for loading/saving game status):
If random events occur, the game will load the file which stored the data of these events. The game progress can be saved in a file.
* Program codes in multiple files:
The main file is responsible for controlling events, management of user input and output of the game. The events in the game are clustered in isolated files. Also, the status should be stored in another file so that they can be called when needed.
* Proper indentation and naming styles
* In-code documentation

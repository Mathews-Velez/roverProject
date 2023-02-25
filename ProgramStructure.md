## app layers of interactions

## flow of app
pick a grid
(connect) to a rover , initialize a rover and pass it a grid object
initialize the rover controller with the rover as an arg
launch the UI
give user access to the rover controller

## area
- a grid will hold a certain amount of tiles where each tile object can be of 3 possible types 1. ore deposit 2. sedentary rock 3. vacant space
- the grid layout will be stored with a 2d array where the first index is the row and the second one is the column
- will have 3 separate arrays that will each store the coordinates of the 3 types of spaces

## tile
- a tile object can be of 3 different sub-types
	- an ore deposit which can be sampled (obstacle)
	- a sedentary rock (obstacle)
	- vacant area (not an obstacle)
- we will have a tile interface that will be implemented by our 3 tile types

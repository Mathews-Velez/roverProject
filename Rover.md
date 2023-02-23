## Error handling
- when a request is made, generate a "sending command to rover"
- when a request is successful "command was sucessfully compiled"
- when a request is rejected "command compilation unsucessful" followed by a descriptive error code and summerization"
Note: this will only be checking for actual sytax errors, other errors will be thrown later if they are hardware related errors.

- for every 3 invalid command that is sent the rover will increase in heat until it forces a cooldown period for 1 minute
	- IDEA: possible minigame to avoid the cooldown by finding the pid of the command handler to force the handler to reset instead of waiting for the process to reach a stackoverflow from running 3 invalid commands and from a bug in the code cause it to rerun all 3 of them 
### commands
- will have 5 separate commands:
	- move (mv)
		- forward (fwd)
			- example usage: mv fwd [step(s)]
			- each "step" has a distance equal to the length of the rover (5 feet)
		- reverse (rev)
			- example usage: mv rev [step(s)]
			- each "step" has a distance equal to the length of the rover (5 feet)
				- power (pwr)
					- example usage: mv rev([0-100])
					- the int passed as an arg indicated the amount of power should be passed to the wheel motors 
		- rotate (rot)
			- example usage: mv rot (-)[0-90-180-360]
			- the rover can only rotate in 90 degree blocks
	- scan (sc)
		- will return a grid radius of 2 tiles showing us if it sees any obstacles in the given area
	- mine (mn)
	- sample (sp)
	- analyze (az)
## Function
- when a rover object is initialized it will be expecting 2 different input types; name, and map layout.
- map layout will be used as a reference when the rover chooses to; move, mine, sample
### Movement


## Gameplay
#### mining 
- highly unstable minerals on a remote planet, each mineral will have to be mined with different variations of heat, drill bit type, and drill force intensity. To know the parameters of each substance the player will have to consult the manual provided stating the ideal settings and parameters for each mineral. If the mineral cannot be found then the player will also have the option to "sample" the mineral and then do an "integrity test" on the mineral to find out the ideal settings for the mineral to be mined.
#### exploration
- navigate maze-like areas where the rover has landed to retrieve minerals and sample unknown ones.

### Components
- the rover will have parts that can get damaged over time or require repairs to prevent full EOS (End Of Service) for the rover ex; tire can get damaged if 
### parts for the rover
- dc motor
  - emulates a dc motor and have a similar interface 
  - only takes in an int (0-255) power
  - depending on the the power it it told to pull, it will more battery
- proximity sensor
  - used to make a scan around the rover
   - depending on the level (1-3)
   - returns more detailed scan
   - (1) detect obstacle
   - (2) detect obstacle, identify obstacle
   - (3) detect obstacle, identify obstacle, check if it's an ore we already know and than return the ore type
- drill device
  - responsible for extracting an ore for an ore deposit
  - takes in 4 parameters when getting activated, (drill bit type, heat temp target, drill force intensity)
- sampler
 - a highly sophisticated piece of engineering winning the award for having the lowest budget (beating the second contender (Issac's opusmagnus) by 0.10$) and  most effective operation time that uses a small device that has an aluminum sphere that holds all the drill bits at differetn angles  attached to a metallic rod that fluxtuates eratically in heat settings and intensity. While it was proven to be effective to extract most of the ores we tested with. We sadly lost one of our esteemed colleagues Issac while he attempted to "test the machine's integrity" with a metal bat.


- will be used to communicate between the rover and the user
- after every command is sent, the user will be alerted if the rover received the command.
- the controller will behave similar to how a compiler behaves.
- the controller will be responsible for catching typos and and syntax errors but will not be able to catch run time errors until it is sent to the rover and we get a response from the rover after it recompiles the code after it receives it.
- the game lore will explain that there is a size limit to the amount of information that can be sent to the rover across the given distance so to save space it's better to send the code uncompiled and then compiled and ran on the rover . After that we will receive whether or not the code compiled successfully on the rover or not.
- when the terminal is first open we should have 3 possible menus;(1) directly link to the rover and send it commands with rover.[action] type instructions.
(2) script  maker
- will be responsible for parsing and processing .syn script code (short for snynapses)
(3) diagnostics check
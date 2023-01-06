# rockpaperscissors
Rock paper scissors game in C++

This game an interface that can be used to implement different types of user interface including command line. Used enums to reduce some string comparisons.

Game class handles the overall flow of the game. It allows all players to play their turn and repeat the flow up to n rounds before fetching and displaying the final score. It can handle any game of similar turn based game play.

RockPaperScissors class contains the core logic of the game. It creates the player objects, calculates scores, decides the winner, creates a leaderboard etc.

RockPaperScissorsPlayer class is a base class which is inherited by AI and RealPlayer classes. Both AI and RealPlayer can play its turn, however they need different logic. So it made sense to override some functions. The split of these classes is useful when porting the game into multiplayer mode.

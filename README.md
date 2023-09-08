
## Yahtzee Simulator: Personal Project
### Functionality:

This simulator allows a player to build upon their Yahtzee skills by allowing the player to play an entire round of Yahtzee.
It bounds players to the classic rules. It also handles all category calculations, so players can focus on the game,
rather than arithmatic


### Purpose:

The project is an attempt to replicate one of my family's favorite games, Yahtzee, in software.
My ultimate goal for this project has been do do everything correctly. For example, I've taken the time to go through each
of the core classes of the project and fully build them out while also keeping in mind future use cases.

I've also been using it to expand upon what I've learned in my classes, and I've been going back and changing things
as I learn ways to design them better. For example, one thing that I desperately need to fix once I have the time
is my searching algorithm for the full house scoring category.


### Future Plans

While I completed this project back in August, I've been going back into it periodically to fix things up/add improvements.
Below is a partial list of the things I'd like to add to the project as my schedule allows:
- Ability to play against a 2nd player
- Ability to play against a NPC (logic for this built with linear optimizaiton?)
- Adding a non-command line UI (probably with JS, but that's still up in the air)
- Clean up the algorithms behind my calculator functions
- I somehow missed that constructors should set member instance variables, so I need to fix that rip
- Add instructions, examples, and test cases to Git for others to easily play


### Misc Background Info:

I began this project in July on a different repository. This project has been my first attempt at using Git,
and, while exploring how Git works, I made some mistakes that made it easier for me to just start scratch from a new repo.
That's why it looks like I've just recently started working on this project.

I'm fully aware that the terminal UI situation is a little messy, and it could use with more error checking.
I chose not to spend more time on that because I know that later down the line, I want to build a non-command line based
UI. I've set myself up pretty well for this by ensuring my frontend and backend are kept in very distinct classes.

# Wordle Helper
Program that aids you in playing Wordle on Hard Mode. Uses your inputs (green, yellow and grey letters) to display all the valid (dictionary) words you can use for your next guess. For the first two input lines, use hyphens ("-") for letters that don't correspond to green or yellow letters. For the third input line, type in the characters that don't belong in the word.

**_Use lowercases letters only._**

Serves as an exercise in C++ loops, string manipulation and I/O. Not intended for public use but more as a showcase of coding ability.

## Example

The Wordle is **STEAD**.

Enter your first guess into Wordle. Let's use the word **SHINE**.

> 🟩⬛⬛⬛🟨

In the Wordle Helper, type these as your input lines:

`s----`

`----e`

`hin`

A list of 263 words should be displayed. Pick one of these words and enter it into Wordle. Let's use **SWEPT**.

> 🟩⬛🟩⬛🟨

In the Wordle Helper, type these as your input lines:

`s-e--`

`----t`

`hinwp`

A list of 24 words should be displayed. Pick one of these words and enter it into Wordle. Let's use **STEAK**.

> 🟩🟩🟩🟩⬛

In the Wordle Helper, type these as your input lines:

`stea-`

`-----`

`hinwpk`

A list of 3 words should be displayed. Pick one of these words and enter it into Wordle. Let's use **STEAD**. From this, we'll see that we picked the correct word and completed the Wordle.

> 🟩🟩🟩🟩🟩

## Potential Improvements

For the third input line, allow characters entered from previous guesses to carry over to the next guess (allows the user to not have to put in the same characters each time).

When displaying valid words, order words based on popularity / frequency used.

Update the code to allow for Easy Mode play.

Conduct tests to check if words containing more than one of the same letter end up being displayed correctly in the list of valid words.

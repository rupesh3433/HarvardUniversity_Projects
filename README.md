# Harvard University Projects

Welcome to my repository for the Harvard University projects completed as part of the CS50: Introduction to Computer Science course!

## Week 0 - Scratch Game

### Spacecraft Game
- **Description:** This project is a simple spacecraft game created using Scratch. Navigate the spacecraft through space, avoiding obstacles and collecting points.
- **File:** [week0_HarvardUniversity_scratchGame.sb3](week0-scratch-project.sb3)

## Week 1 - C Language Projects

### Cash
- **Description:** Implement a program that calculates the minimum number of coins required to give a user change.
- **File:** [cash.c](week1-c-project/cash/cash.c)

### Credit
- **Description:** Implement a program that determines whether a provided credit card number is valid, and if so, which company issued it.
- **File:** [credit.c](week1-c-project/credit/credit.c)

### Mario - Less Comfortable
- **Description:** Implement a program that prints a half-pyramid of a specified height using hashes (`#`) for blocks.
- **File:** [mario.c](week1-c-project/mario-less/mario.c)

### Mario - More Comfortable
- **Description:** Implement a program that prints a pyramid of a specified height using hashes (`#`) for blocks.
- **File:** [mario.c](week1-c-project/mario-more/mario.c)

### Me
- **Description:** Implement a simple "hello world" program.
- **File:** [hello.c](week1-c-project/me/hello.c)

## Week 2 - C Language Projects

### Caesar Cipher
- **Description:** Implement a program that encrypts messages using Caesar's cipher.
- **File:** [caesar.c](week2-c-project/caesar/caesar.c)

### Readability
- **Description:** Implement a program that computes the approximate grade level needed to comprehend some text.
- **File:** [readability.c](week2-c-project/readability/readability.c)

### Scrabble
- **Description:** Implement a program that calculates the score of a given word in Scrabble.
- **File:** [scrabble.c](week2-c-project/scrabble/scrabble.c)

### Substitution Cipher
- **Description:** Implement a program that encrypts messages using a substitution cipher.
- **File:** [substitution.c](week2-c-project/substitution/substitution.c)

## Week 3 - Algorithms

### Sorting Algorithms Analysis 
- **Description:**
   ->In this question, I conducted an analysis of three different sorting algorithms: selection sort, bubble sort, and merge sort by examining the behavior of three compiled C programs (sort1, sort2, sort3) on various input datasets.

   ->After downloading and extracting the provided distribution code, I ran each sorting program on different types of input files (e.g., sorted, reversed, random) to observe their performance characteristics.

   ->Through this analysis, I determined that sort1 implements bubble sort, identified by its quadratic time complexity and slower performance on reversed input.

   ->sort2 was identified as merge sort due to its efficient O(n log n) performance across all input types.

   ->Lastly, sort3 exhibited the characteristics of selection sort, showing inefficiency (O(n^2)) and slowdown with larger datasets or reversed lists.

### Plurality
- **Description:** Implement a program that runs a plurality election, where each voter selects one candidate and the candidate with the most votes wins.
- **Algorithm:** 
  1. **Initialize Data Structures:** Set up an array to store candidates and their vote counts.
  2. **Vote Function:** Implement a function to record a vote for a candidate by name. If the name matches one of the candidates, increase their vote count.
  3. **Print Winner Function:** Implement a function to determine and print the candidate(s) with the most votes.
  4. **Handle Edge Cases:** Ensure the program can handle elections with up to 9 candidates, invalid votes, and ties between candidates.
- **Use Cases:** Plurality elections are commonly used in various voting scenarios, including political elections, boardroom decisions, and online polls.

### Runoff
- **Description:** Implement a program that runs a runoff election, allowing voters to rank their preferred candidates. If no candidate has a majority of first-choice votes, an instant runoff takes place until a winner is determined.
- **Algorithm:** 
  1. **Initialize Data Structures:** Set up arrays to store voter rankings and candidate information.
  2. **Vote Function:** Record votes by rank order for each candidate.
  3. **Tabulate Function:** Calculate the number of first-choice votes for each candidate.
  4. **Eliminate Function:** Remove the candidate with the fewest votes and redistribute their votes to the next preferred candidate.
  5. **Repeat Until Majority:** Continue the process until a candidate has more than half of the votes.
- **Use Cases:** Runoff elections are used in political elections, particularly in jurisdictions that require majority support for a candidate to win.

### Tideman
- **Description:** Implement a program that runs a Tideman election, where voters rank candidates in order of preference. The Tideman method determines a "Condorcet winner" if one exists or selects a winner based on a series of pairwise comparisons.
- **Algorithm:** 
  1. **Initialize Data Structures:** Set up arrays and matrices to store voter preferences, pairs of candidates, and the locked graph.
  2. **Record Preferences:** Record pairwise preferences between each pair of candidates based on voter rankings.
  3. **Add Pairs:** Create pairs of candidates where one is preferred over the other.
  4. **Sort Pairs:** Sort the pairs in decreasing order of victory strength.
  5. **Lock Pairs:** Lock pairs into the candidate graph, ensuring no cycles are created.
  6. **Print Winner:** Determine the source of the graph (i.e., the candidate with no edges pointing to them) and declare them the winner.
- **Use Cases:** Tideman elections are used to select winners in scenarios where pairwise comparisons between candidates are relevant, such as award nominations, committee selections, and organizational decisions.
## Getting Started

To view and run the projects in this repository, follow these steps:

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/rupesh3433/HarvardUniversity_Projects.git

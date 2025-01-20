# Quiz Program

This is a simple console-based quiz program written in C. It allows users to take quizzes on various subjects, track their scores, and store their results in a file. The program provides an interactive menu for the user to select different courses or quizzes.

## Features
- Multiple-choice quiz format
- User score tracking
- Option to retry quizzes
- Stores results in a text file (`score.txt`)
- Displays feedback after each quiz

## Requirements
- C Compiler (e.g., GCC, Clang)
- Basic knowledge of C programming to understand and modify the code

## How to Run

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/mhashir3743/Quiz-Game.git
    ```

2. Navigate to the project directory:

    ```bash
    cd quizGame
    ```

3. Compile the program using your C compiler:

    ```bash
    gcc -o quizGame quizGame.c
    ```

4. Run the program:

    ```bash
    ./quizGame
    ```

## Functions

- **homescreen()**: Displays the main menu where the user can choose between different courses or quizzes.
- **start_game()**: Allows the user to select a quiz from available courses and begin playing.
- **pf_quiz()**: Handles the questions and answer validation for the quiz related to a specific course.
- **save_score()**: Saves the user's score to a text file (`score.txt`).
- **get_score()**: Reads and displays the saved score from the file.

## Example Output



Do you want to continue? (Y/N)
Known Issues
The program uses gets(), which is considered unsafe. It is recommended to replace it with fgets() for better safety (future improvements).
The program is written for console-based interaction only and does not have a graphical user interface (GUI).
License
This project is licensed under the MIT License - see the LICENSE file for details.

Acknowledgements
C Programming Language by Dennis Ritchie
Open source libraries for standard I/O handling

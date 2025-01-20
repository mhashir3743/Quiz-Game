// Header Files
#include<stdio.h>
#include<conio.h> //getch()
#include<stdlib.h> //system cls and exit(1)

//Function Decelration
void homescreen();
void start_game();
void show_record();
void help();
void pf_quiz();
void ict_quiz();
void calculus_quiz();
void physics_quiz();
void english_quiz();

int main()
{
    system("cls");//clear screen
    char name[20];// Getting Player name at start of the game
    printf("\nRegister Your Name: ");
    gets(name); // need spacing also like chanchal ratnani

    // storing name in the files
    FILE *f = fopen("score.txt", "w"); // writing mod
    fprintf(f,"==========================================================================================\n");
    fprintf(f, "\t\t\t\tPlayer Name: %s\n", name);
    fprintf(f,"==========================================================================================\n");
    fclose(f);

    homescreen();
    return 0;
}
void homescreen()
{
    system("cls");//clear screen
    printf("\n\t\t\t------------------------------------------------------------------");
    printf("\n\t\t\t Welcome to the Quiz Game");
    printf("\n\t\t\t------------------------------------------------------------------");

    printf("\n\t\t\t  Test your knowledge in this exciting quiz!");
    printf("\n\t\t\t------------------------------------------------------------------");
    printf("\n\t\t\t  => Press 'S' to start the game");
    printf("\n\t\t\t  => Press 'V' to view the score");
    printf("\n\t\t\t  => Press 'H' for help");
    printf("\n\t\t\t  => Press 'Q' to quit");
    printf("\n\t\t\t------------------------------------------------------------------\n");
    char choice; //declare variable choice
    scanf(" %c", &choice); // Use scanf() to get a single character input.
    if (choice=='S'||choice=='s')
	{
 	    start_game();
	}
    else if (choice=='V'||choice=='v')
	{
	    show_record(); //calling show record function
	    getch(); // holding the screen
        homescreen();
	}
    else if (choice=='H'||choice=='h')
	{
	    help();  // Call the help function.
	    getch();  // Wait for a keypress using getch().  //holding
        homescreen();
	}
	else if (choice=='Q'||choice=='q')
    {
        exit(1); //terminate the program
    }
}
void start_game()
{
  system("cls");
  printf("Please select the quiz you'd like to take:");
  printf("\n--> Press 1 for the 'PF Quiz'");
  printf("\n--> Press 2 for the 'ICT Quiz'");
  printf("\n--> Press 3 for the 'Calculus Quiz'");
  printf("\n--> Press 4 for the 'Physics Quiz'");
  printf("\n--> Press 5 for the 'English Quiz'");
  printf("\n--> Press H for the back to 'Home Screen'\n");
  char course_choice; //variable declartion
  scanf(" %c", &course_choice); //user input

    switch (course_choice)
    {
        case '1':
            pf_quiz();
            break;
        case '2':
            ict_quiz();
            break;
        case '3':
            calculus_quiz();
            break;
        case '4':
            physics_quiz();
            break;
        case '5':
            english_quiz();
            break;
        case 'H': case 'h':
            homescreen();
            break;
        default:
            system("cls");
            printf("\nWrong Input");
            printf("\nPlease press 1 to 5 to attempt quiz and H for Home Screen");
            getch();
            start_game();
            break;
    }


}

void pf_quiz()
{
    int pf_correct_ans = 0;

    for (int i = 1; i <= 5; i++)
        {
        system("cls");
        printf("\nQ%d) ", i);

        char correct_answer; //declare varibale

        switch (i)
        {
            case 1:
                printf("In C, what is the purpose of the scanf function?");
                printf("\n\nA. Display output on the screen\nB. Read input from the keyboard\nC. Perform mathematical calculations\nD. Create a loop structure\n");
                scanf("%s",&correct_answer);
                if (correct_answer=='B'||correct_answer=='b')
                    {
			    printf("\n\nCorrect!!");
			    pf_correct_ans++;
			    getch();
			    break;
			    }
			    else
		       {
		           printf("\n\nWrong!!! The correct answer is B. Read input from the keyboard");
		           getch();
		           break;
		       }
            case 2:
                printf("Which of the following is not valid C variable name?");
                printf("\n\nA. int number;\nB. float rate;\nC. int variable-count;\nD. int $main;\n");
                scanf("%s",&correct_answer);
                 if (correct_answer=='D'||correct_answer=='d')
			  {
			    printf("\n\nCorrect!!");
			    pf_correct_ans++;
			    getch();
			    break;
			 }
			 else
		       {
		           printf("\n\nWrong!!! The correct answer is D. int $main");
		           getch();
		       break;
		       }
            case 3:
                printf("What is an example of iteration in C?");
                printf("\nA. for\nB. while\nC. Do-while\nD. All of the mentioned");
                scanf("%s",&correct_answer);
                  if (correct_answer=='D'||correct_answer=='d')
			   {
			    printf("\n\nCorrect!!");
			    pf_correct_ans++;
			    getch();
			    break;
			  }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is D. All of the mentioned");
		           getch();
		       break;
		       }
            case 4:
                printf("What is #include <stdio.h>?");
                printf("\nA. preprocessor directive\nB. inclusion directive\nC. File inclusion directive\nD. None of the mentioned\n");
                scanf("%s",&correct_answer);
                  if (correct_answer=='A'||correct_answer=='a')
			  {
			    printf("\n\nCorrect!!");
			    pf_correct_ans++;
			    getch();
			    break;
			 }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is A. preprocessor directive ");
		           getch();
		       break;
		       }
            case 5:
                printf("Which of the following is an exit controlled loop?");
                printf("\nA. While loop\nB. For loop\nC. do-while loop\nD. None of the above");
                scanf("%s",&correct_answer);
                  if (correct_answer=='C'||correct_answer=='c')
			  {
			    printf("\n\nCorrect!!");
			    pf_correct_ans++;
			    getch();
			    break;
			 }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is C. do-while loop");
		           getch();
		       break;
		       }
            default:
                break;
        }

    }
    system("cls");

    printf("\n\tYou have given %d correct ans out of 5 in PF Quiz", pf_correct_ans);
    int pf_score = pf_correct_ans * 2; // each question is of 2 marks
    FILE *f = fopen("score.txt", "a"); // append mode
    fprintf(f, "Player has Scored %d marks out of 10 marks in PF Quiz\n", pf_score);
    fclose(f);
    printf("\n\n\nPress any key to attempt another quiz\n");
    getch();
    start_game();
}

void ict_quiz()
{
    int ict_correct_ans = 0;

    for (int i = 1; i <= 5; i++) {
        system("cls");
        printf("\nQ%d) ", i);

        char correct_answer;

        switch (i) {
            case 1:
                printf("URL stands for");
                printf("\n\nA. Universal Resource Location\nB. Universal Response Locator\nC. Unified Response Location\nD. Uniform Resource Locator\n");
                scanf("%s",&correct_answer);
                  if (correct_answer=='D'||correct_answer=='d')
			  {
			    printf("\n\nCorrect!!");
			    ict_correct_ans++;
			    getch();
			    break;
			 }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is D. Uniform Resource Locator");
		           getch();
		       break;
		       }
            case 2:
                printf("Which one of the following is NOT a web browser?");
                printf("\n\nA. Firefox\nB. Facebook\nC. Chrome\nD. Safari\n");
                scanf("%s",&correct_answer);
                 if (correct_answer=='B'||correct_answer=='b')
			  {
			    printf("\n\nCorrect!!");
			    ict_correct_ans++;
			    getch();
			    break;
			 }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is B. facebook");
		           getch();
		       break;
		       }
            case 3:
                printf("A parallel port is most often used by a");
                printf("\n\nA. (a) Mouse\nB. (b) Monitor\nC. printer\nD. External storage device\n");
                scanf("%s",&correct_answer);
                 if (correct_answer=='C'||correct_answer=='c')
			  {
			    printf("\n\nCorrect!!");
			    ict_correct_ans++;
			    getch();
			    break;
			 }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is C. Printer");
		           getch();
		       break;
		       }
            case 4:
                printf("ENIAC was");
                printf("\n\nA. an electronic computer\nB. an engine\nC. a memory device\nD. an electronic calculator");
                scanf("%s",&correct_answer);
                if (correct_answer=='A'||correct_answer=='a')
                    {
                        printf("\n\nCorrect!!");
                        ict_correct_ans++;
                        getch();
                        break;
                    }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is B. an electronic computer ");
		           getch();
		       break;
		       }
            case 5:
                printf("Which of the following is not an input device");
                printf("\n\nA. Microphone\nB. Keyboard\nC. Joystick\nD. Monitor\n");
                scanf("%s",&correct_answer);
                 if (correct_answer=='D'||correct_answer=='d')
			  {
			    printf("\n\nCorrect!!");
			    ict_correct_ans++;
			    getch();
			    break;
			 }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is D. Monitor");
		           getch();
		       break;
		       }
           default:
                break;
        }
    }

    system("cls");

    printf("\n\tYou have given %d correct ans out of 5 in ICT Quiz", ict_correct_ans);


    int ict_score = ict_correct_ans * 2; // each question is of 2 marks

    FILE *f = fopen("score.txt", "a"); // append mode
    fprintf(f, "Player has Scored %d marks out of 10 marks in ICT Quiz\n", ict_score);
    fclose(f);
    printf("\n\n\nPress any key to attempt another quiz\n");
    getch();
    start_game();
}

void calculus_quiz() {
    int calculus_correct_ans = 0;

    for (int i = 1; i <= 5; i++) {
        system("cls");
        printf("\nQ%d) ", i);

        char correct_answer;
        char user_answer;

        switch (i) {
            case 1:
                printf("What is the limit of sin(θ)/θ when θ approaches zero?");
                printf("\n\nA. 1\nB. sin(θ)\nC. 0\nD. None of these\n");
                scanf("%s",&correct_answer);
                 if (correct_answer=='A'||correct_answer=='a')
			  {
			    printf("\n\nCorrect!!");
			    calculus_correct_ans++;
			    getch();
			    break;
			 }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is A. 1");
		           getch();
		       break;
		       }
            case 2:
                printf("When f(x) = 3×2, then F(x) is equals to?");
                printf("\n\nA. x^3 + C\nB. 6x + C\nC. 6x\nD. x^3\n");
                scanf("%s",&correct_answer);
                  if (correct_answer=='A'||correct_answer=='a')
			  {
			    printf("\n\nCorrect!!");
			    calculus_correct_ans++;
			    getch();
			    break;
			 }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is A. x^3");
		           getch();
		       break;
		       }

            case 3:
                printf("What is required for full determination of an anti-differentiated function?");
                printf("\n\nA. Its real-world application\nB. What its value is at (0, 0)\nC. A boundary condition\nD. A lot of luck");
                scanf("%s",&correct_answer);
                  if (correct_answer=='C'||correct_answer=='c')
			  {
			    printf("\n\nCorrect!!");
			    calculus_correct_ans++;
			    getch();
			    break;
			 }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is C. A boundary condition ");
		           getch();
		       break;
		       }
            case 4:
                printf("The interval in which the Lagrange's theorem is applicable for the function f(x) = 1/x is");
                printf("\n\nA. [-3, 3]\nB. [-2, 2]\nC. [2, 3]\nD. [-1, 1]\n");
                scanf("%s",&correct_answer);
                  if (correct_answer=='C'||correct_answer=='c')
			  {
			    printf("\n\nCorrect!!");
			    calculus_correct_ans++;
			    getch();
			    break;
			 }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is C. [2,3]");
		           getch();
		       break;
		       }
            case 5:
                printf("What will be the types of errors that are related to differentials?");
                printf("\n\nA. Relative, Controllable\nB. Controllable, Natural\nC. Human, Absolute\nD. Absolute, Relative\n");
                scanf("%s",&correct_answer);
                  if (correct_answer=='D'||correct_answer=='d')
			  {
			    printf("\n\nCorrect!!");
                calculus_correct_ans++;
			    getch();
			    break;
			 }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is D. Absolute, Relative");
		           getch();
		       break;
		       }
            default:
                break;
        }

    }

    system("cls");

    printf("\n\tYou have given %d correct ans out of 5 in Calculus Quiz", calculus_correct_ans);

    int calculus_score = calculus_correct_ans * 2; // each question is of 2 marks
    FILE *f = fopen("score.txt", "a"); // append mode
    fprintf(f, "Player has Scored %d marks out of 10 marks in Calculus Quiz\n", calculus_score);
    fclose(f);

    printf("\n\n\nPress any key to attempt another quiz\n");
    getch();
    start_game();
}

void physics_quiz() {
    int physics_correct_ans = 0;

    for (int i = 1; i <= 5; i++) {
        system("cls");
        printf("\nQ%d) ", i);

        char correct_answer;
        char user_answer;

        switch (i) {
            case 1:
                printf("The ideal fluid which is a hypothetical fluid should contain _?");
                printf("\n\nA. Zero Viscosity Only\nB. Zero Compressibility Only\nC. Zero Viscosity & Zero Compressibility\nD. None of the above\n");
                scanf("%s",&correct_answer);
                 if (correct_answer=='C'||correct_answer=='c')
			  {
			    printf("\n\nCorrect!!");
                physics_correct_ans++;
			    getch();
			    break;
			 }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is C. Zero Viscosity & Zero Compressibility");
		           getch();
		       break;
		       }

            case 2:
                printf("Joule/kg is the S.I unit of which of these physical quantities?");
                printf("\n\nA. Entropy\nB. Permittivity of free space\nC. Latent heat\nD. Gas constant\n");
                scanf("%s",&correct_answer);
                  if (correct_answer=='C'||correct_answer=='c')
			  {
			    printf("\n\nCorrect!!");
                physics_correct_ans++;
			    getch();
			    break;
			 }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is C. Latent heat");
		           getch();
		       break;
		       }

            case 3:
                printf("Which of the following are Polar vectors?");
                printf("\n\nA. Displacement\nB. Force\nC. Both a and b\nD. None\n");
                scanf("%s",&correct_answer);
                  if (correct_answer=='C'||correct_answer=='c')
			  {
			    printf("\n\nCorrect!!");
                physics_correct_ans++;
			    getch();
			    break;
			 }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is C. Both a and b");
		           getch();
		       break;
		       }
            case 4:
                printf("What is the work done by centripetal force in case of Uniform Circular Motion?");
                printf("\n\nA. 1 joule\nB. 0 joule\nC. Depends on the magnitude of Force\nD. None of the above\n");
                scanf("%s",&correct_answer);
                  if (correct_answer=='B'||correct_answer=='b')
			  {
			    printf("\n\nCorrect!!");
                physics_correct_ans++;
			    getch();
			    break;
			 }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is B. 0 Joule ");
		           getch();
		       break;
		       }
            case 5:
                printf("What do you call the phenomenon when Moon blocks the light coming from a star?");
                printf("\n\nA. Eclipse\nB. Occultation\nC. Transit\n D. Blockage\n");
                scanf("%s",&correct_answer);
                  if (correct_answer=='B'||correct_answer=='b')
			  {
			    printf("\n\nCorrect!!");
                physics_correct_ans++;
			    getch();
			    break;
			 }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is B. Occultation");
		           getch();
		       break;
		       }
            default:
                break;
        }

}

    system("cls");

    printf("\n\tYou have given %d correct ans out of 5 in Physics Quiz", physics_correct_ans);


    int physics_score = physics_correct_ans * 2; // each question is of 2 marks

    FILE *f = fopen("score.txt", "a"); // append mode
    fprintf(f, "Player has Scored %d marks out of 10 marks in Physics Quiz\n", physics_score);
    fclose(f);
    printf("\n\n\nPress any key to attempt another quiz\n");
    getch();
    start_game();
}

void english_quiz() {
    int english_correct_ans = 0;

    for (int i = 1; i <= 5; i++) {
        system("cls");
        printf("\nQ%d) ", i);

        char correct_answer;
        char user_answer;

        switch (i) {
            case 1:
                printf("Synonym Goal is?");
                printf("\n\nA. Purpose\nB. Quod\nC. Objective\nD. None of these\n");
                scanf("%s",&correct_answer);
                  if (correct_answer=='B'||correct_answer=='b')
			  {
			    printf("\n\nCorrect!!");
                english_correct_ans++;
			    getch();
			    break;
			 }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is B. Quod");
		           getch();
		       break;
		       }
            case 2:
                printf("They have been living in Switzerland__seven years.");
                printf("\n\nA. for\nB. since\nC. during\nD. between\n");
                scanf("%s",&correct_answer);
                  if (correct_answer=='A'||correct_answer=='a')
			  {
			    printf("\n\nCorrect!!");
                english_correct_ans++;
			    getch();
			    break;
			 }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is A. for");
		           getch();
		       break;
		       }
            case 3:
                printf("Select the word which is spelled correctly");
                printf("\n\nA. Benefited\nB. benifited\nC. benifitted\nD. None of these\n");
                scanf("%s",&correct_answer);
                  if (correct_answer=='A'||correct_answer=='a')
			  {
			    printf("\n\nCorrect!!");
                english_correct_ans++;
			    getch();
			    break;
			 }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is A. benefited");
		           getch();
		       break;
		       }
            case 4:
                printf("A person living permanently in a certain place.");
                printf("\n\nA. Resident\nB. Native\nC. Domicile\nD. Subject\n");
                scanf("%s",&correct_answer);
                  if (correct_answer=='C'||correct_answer=='c')
			  {
			    printf("\n\nCorrect!!");
                english_correct_ans++;
			    getch();
			    break;
			 }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is C. Domicile");
		           getch();
		       break;
		       }
            case 5:
                printf("Choose the correct spellings");
                printf("\n\nA. Qoloquial\nB. coloquial\nC. Colloqial\nD. ColloQuial\n");
                scanf("%s",&correct_answer);
                  if (correct_answer=='D'||correct_answer=='d')
			  {
			    printf("\n\nCorrect!!");
                english_correct_ans++;
			    getch();
			    break;
			 }
		else
		       {
		           printf("\n\nWrong!!! The correct answer is D. ColloQuial");
		           getch();
		       break;
		       }
            default:
                break;
        }

    }

    system("cls");

    printf("\n\tYou have given %d correct ans out of 5 in English Quiz", english_correct_ans);

    int english_score = english_correct_ans * 2; // each question is of 2 marks
    FILE *f = fopen("score.txt", "a"); // append mode
    fprintf(f, "Player has Scored %d marks out of 10 marks in English Quiz\n", english_score);
    fclose(f);
    printf("\n\n\nPress any key to attempt another quiz\n");
    getch();
    start_game();
}

void show_record()
{
    system("cls");
    FILE *file = fopen("score.txt", "r"); //reading mod
    char c; // variable to help to read from file
    while ((c = getc(file)) != EOF) {   //EOF = End Of File   //getc= read from file
        putchar(c); // print on conosle
    }
    // Close the file
    fclose(file);
}
void help()
{
    system("cls");
    printf("\n\t\t\t------------------------------------------------------------------");
    printf("\n\t\t\t                          Quiz Game Help                        ");
    printf("\n\t\t\t------------------------------------------------------------------");

    printf("\n\n1. The Quiz Game has multiple categories: PF, ICT, Calculus, Physics, and English.");
    printf("\n2. You can select a quiz category by entering the corresponding number.");
    printf("\n3. Answer each question by entering the letter corresponding to your choice.");
    printf("\n4. For example, if you want to choose option A, enter 'A' or 'a' when prompted.");
    printf("\n5. After completing a quiz, your score will be displayed.");
    printf("\n6. Your total score will be recorded in the 'score.txt' file.");
    printf("\n\nPress any key to go back to the Home Screen.");
}
#include <stdio.h>
#include <string.h>

void clrscr()				//A function to clear the terminal/cmd window.
{
    system("@cls||clear");
}

char equalsignorecase(char char1, char char2) { //Returns 1 if the characters are equal, ignoring case.
    if ('Z'-char1 == 'Z'-char2 || 'z'-char1 == 'Z'-char2 || 'Z'-char1 == 'z'-char2) { //Chars are also integers and the letters of the alphabet are next to eachother. We can compare the chars using their numeric value.
        return 1;
    }
    return 0;
}

void print_wrong_letters(int guesses, char wrong_letters[]) { //It is nice if the user knows what it has already guessed.
    printf("Wrong letters: "); //Say "wrong numbers" without \n so that the next message is on the same line.
    if (guesses) { //If there are any guesses, list them.
        for (int letter_index = 0; letter_index < guesses; letter_index ++) { //Loop through the wrong guesses.
            printf("%c  ", wrong_letters[letter_index]); //Print the wrong guesses.
        }
    } else { //If there aren't any wrong guesses, just say "None" to make it clear to the user.
        printf("None");
    }
    printf("\n"); //End with a newline.
}


void hangman(int i){			//A function that prints the hanged man ascii art according to how many wrong guesses the user has made.
        clrscr();           		//Command to clear screen, if it doesn't work, use the commented line bellow.
        //printf(" \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n");
        switch (i){
        case 0:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| | | / \n| |/ \n| | \n| | | \n| | \n| | \n| | | \n| | \n| | \n| | | \n| | \n|=========|_`-' `-' |===| \n|=|=======\ \       '=|=| \n| |        \ \        | | \n: :         \ \       : : \n. .          `'       . . \n");
            break;
        case 1:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| | | /        ||.-''. \n| |/         |/  _  \ \n| |          ||  `/,| \n| |          (\\`_.' \n| | | \n| | \n| | \n| | \n| | \n| | \n| | \n| | \n| | \n|=========|_`-' `-' |===| \n|=|=======\ \       '=|=| \n| |        \ \        | | \n: :         \ \       : : \n. .          `'       . . \n");
            break;
        case 2:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| |/ /       || \n| | /        ||.-''. \n| |/         |/  _  \ \n| |          ||  `/,| \n| |          (\\`_.' \n| |         .-`--'. \n| |           . .    \n| |          |   |    \n| |          | . |     \n| |          |   |      \n| | \n| | \n| | \n| | \n| | \n|=========|_`-' `-' |===| \n|=|=======\ \       '=|=| \n| |        \ \        | | \n: :         \ \       : : \n. .          `'       . . \n");
            break;
        case 3:
            printf("___________.._______ \n| .__________))______| \n| | / /      || \n| |/ /       || \n| | /        ||.-''. \n| |/         |/  _  \ \n| |          ||  `/,| \n| |          (\\`_.' \n| |         .-`--'. \n| |        /Y . .    \n| |       // |   |    \n| |      //  | . |     \n| |     ')   |   |      \n| | \n| | \n| | \n| | \n| | \n|=========|_`-' `-' |===| \n|=|=======\ \       '=|=| \n| |        \ \        | | \n: :         \ \       : : \n. .          `'       . . \n");
            break;
        case 4:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| |/ /       || \n| | /        ||.-''. \n| |/         |/  _  \ \n| |          ||  `/,| \n| |          (\\`_.' \n| |         .-`--'. \n| |        /Y . . Y\ \n| |       // |   | \\ \n| |      //  | . |  \\ \n| |     ')   |   |   (` \n| | \n| | \n| | \n| | \n| | \n|=========|_`-' `-' |===| \n|=|=======\ \       '=|=| \n| |        \ \        | | \n: :         \ \       : : \n. .          `'       . . \n");
            break;
        case 5:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| |/ /       || \n| | /        ||.-''. \n| |/         |/  _  \ \n| |          ||  `/,| \n| |          (\\`_.' \n| |         .-`--'. \n| |        /Y . . Y\ \n| |       // |   | \\ \n| |      //  | . |  \\ \n| |     ')   |   |   (` \n| |          ||    \n| |          ||    \n| |          ||    \n| |          ||    \n| |         / |    \n==========|_`-' `-' |===| \n|=|=======\ \       '=|=| \n| |        \ \        | | \n: :         \ \       : : \n. .          `'       . . \n");
            break;
        case 6:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| |/ /       || \n| | /        ||.-''. \n| |/         |/  _  \ \n| |          ||  `/,| \n| |          (\\`_.' \n| |         .-`--'. \n| |        /Y . . Y\ \n| |       // |   | \\ \n| |      //  | . |  \\ \n| |     ')   |   |   (` \n| |          || || \n| |          || || \n| |          || || \n| |          || || \n| |         / | | \\ \n==========|_`-' `-' |===| \n|=|=======\ \       '=|=| \n| |        \ \        | | \n: :         \ \       : : \n. .          `'       . . \n");
            break;
}       }

int main()
{
    char word[20];			//Used to store the user word. Most words are less than 20 characters so the default size is 20.
    char stars[20];			//A string full of * that are replaced upon the user entering the right letter of the word.
    char wrong_guesses[6];     //Show the user the letters they got wrong.
    int counter = 0;			//A counter to use in the for loops.
    int len;				//len is the length of the word entered.
    char ch;				//ch is a temporary character variable.
    int strikes=0;			//strikes counts how many wrong characters the user has guessed.
    int trigger = 0;			//The trigger variable serves as a flag in the for loops bellow.
    int wincounter=0;			//wincounter keeps track of the number of correct guesses.
    int i;				//Another counter variable to be used in for loops.

    //Ascii Art
    printf(" _                                             \n");
    printf("| |                                            \n");
    printf("| |__   __ _ _ __   __ _ _ __ ___   __ _ _ __  \n");
    printf("| '_ \\ / _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n");
    printf("| | | | (_| | | | | (_| | | | | | | (_| | | | | \n");
    printf("|_| |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_| \n");
    printf("                    __/ |                      \n");
    printf("                   |___/  \n");


    printf("\n\nEnter a word:");			//Ask the user to enter a word.
    scanf("%20s", &word);
    len = strlen(word);					//Make len equal to the length of the word.

    clrscr();						//To clear the screen, if function doesn't work properly, use the commented line bellow instead.
    /*printf(" \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n");*/


    //Fill the stars string with * according to the input word length (len)
    for(counter=0; counter<len; counter++)
    {
        stars[counter]='*';
    }


    stars[len]='\0';					//Insert the terminating string character at the end of the stars string.


    //Enter main program loop where guessing and checking happens. 26 is for 20 maximum characters + 6 strike characters.
    for(counter = 0; counter<26; counter++)
    {
        hangman(strikes);			    	//Print the hangman ascii art according to how many wrong guesses the user has made.

        if(strikes==6)				    	//If the user makes 6 wrong guesses it means that he lost.
        {
            printf("\n\nThe word was: %s\n", word);
            printf("\n\nYou lose.\n");
            break;
        }

        printf("\n\n\n");
        print_wrong_letters(strikes, wrong_guesses);
        printf("\n\n%s", stars);			//Print the stars string (i.e: h*ll* for hello).

        if(wincounter==len)			    	//If the number of correct guesses matches the length of the word it means that the user won.
        {
            printf("\n\nThe word was: %s\n", word);
            printf("\nYou win!\n");
            break;
        }

	printf("\n\nGuess a letter:");			//Have the user guess a letter.
        scanf(" %c",&ch);

        for(i=0; i<len; i++)            		//Run through the string checking the characters.
        {
            if(equalsignorecase(word[i], ch)) //Check if the guess is correct.
            {
                stars[i]=ch;		    		//If the guess is correct, replace it in the stars string.
                trigger++;			   	//If a character the user entered matches one of the initial word, change the trigger to a non zero value.
                wincounter++;		    		//Increase the number of correct guesses.
            }
        }

        if(trigger==0)
        {
            wrong_guesses[strikes] = ch;    //If the guess is not correct, add the character to the wrong guesses.
            strikes++;				    	//If the trigger is not a non zero value, increase the strikes counter because that means that the user input character didn't match any character of the word.
        }

        trigger = 0;				    	//Set the trigger to 0 again so the user can guess a new character.
    }
    printf("\nPress Enter to exit.");
    fflush(stdin);
    while(getchar()!='\n');
    getchar(); // wait for ENTER
    
    return 0;
}

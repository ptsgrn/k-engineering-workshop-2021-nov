/**
 * @file q4.cpp
 * @author Patsagorn Yuenyong (patsagorn.yue@pccbr.ac.th)
 * @brief DOOR - minigame for question number 4.
 * @version 0.1
 * @date 2021-11-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// set game header
const char *doorclosed = "\n"
  "          __________\n"
  "         |  __  __  |\n"
  "         | |  ||  | |\n"
  "         | |  ||  | |\n"
  "         | |__||__| |\n"
  "         |  __  __()|\n"
  "         | |  ||  | |\n"
  "         | |  ||  | |\n"
  "         | |  ||  | |\n"
  "         | |  ||  | |\n"
  "         | |__||__| |\n"
  "         |__________|\n"
  "\n";

const char *dooropen = "\n"
  "   /|\n"
  "  / |\n"
  " /__|______\n"
  "|  __  __  |\n"
  "| |  ||  | |   here's a mop, just in case you forgot to bring one\n"
  "| |  ||  | |     you can use it to clean the floor, but\n"
  "| |__||__| |__\\     you can't use it to clean the door.\n"
  "|  __  __()|   \\     Surprised? This is treasures.\n"
  "| |  ||  | |    \\\n"
  "| |  ||  | |     \\\n"
  "| |  ||  | |     (\\)\n"
  "| |__||__| |     )((\n"
  "|__________|     ))))\n"
    "\n";


// get number of digit that right in number and position
int getRightPosition(int guess[3], int answer[3]) {
  int count = 0;
  for (int i = 0; i < 3; i++) {
    if (guess[i] == answer[i]) {
      count++;
    }
  }
  return count;
}

// get number of digit that right in number but wrong position
int getRightNumber(int guess[3], int answer[3]) {
  int count = 0;
  // for each digit in guess
  for (int i = 0; i < 3; i++) {
    // for each digit in answer
    // bulk check if guess[i] is in answer
    for (int j = 0; j < 3; j++) {
      if (guess[i] == answer[j]) {
        count++;
      }
    }
  }
  // subtract the number of right position
  return count - getRightPosition(guess, answer);
}

void guess(int password[3]){
  // start gussing
  int g1, g2, g3;
  // keep track of the number of guesses
  // and no more than 11 guesses
  int numberOfGuess = 0;
  int maxGuess = 11;
  // keep track of guess for shame
  int guesses[maxGuess][3];

  // some tutorial for user
  printf("[Text on the door] > \"Number '258' is good for your first try! I will not count it in your guesses.\"\n");
  printf("YOU > 2 5 8\nDONT FORGOT TO SEPERATE IT WITH SPACE!\n");

  // Yes, I know this is not a good way to do this
  // but I don't want to do this feature for now.
  int firstGuess[3] = {2, 5, 8};
  printf("door said > %d right %d wrong so far.\n------------- Now your turn!\n", getRightPosition(firstGuess, password), getRightNumber(firstGuess, password));
  // start loop and check if password is guessed, if so, end loop
  while (numberOfGuess < maxGuess && getRightPosition(firstGuess, password) != 3) {
    printf("YOU > ");
    // get guess from user
    scanf("%d %d %d", &g1, &g2, &g3);
    // store guess in array
    int guess[3] = {g1, g2, g3};
    // check if match our free guess
    if (g1 == 2 && g2 == 5 && g3 == 8){ 
      printf(" > It is free, taked.\n");
      continue;
    };
    // check if guess is correct
    if (g1 == password[0] && g2 == password[1] && g3 == password[2]) {
      printf("door said > %d right %d wrong so far.\n", getRightPosition(guess, password), getRightNumber(guess, password));
      printf(" > The door is opened and you get the treasure!\n%s\n > Have you ever check your genius? You might have 120+ IQ\n", dooropen);
      if (numberOfGuess <= 4) printf(" > You're lucky that you can guess the password in %d guesses.\n", numberOfGuess+1);
      break;
    } else {
      // tell user how many right and wrong
      printf("door said > %d right %d wrong so far.\n", getRightPosition(guess, password), getRightNumber(guess, password));
    }
    // add guess to guesses for tracking
    guesses[numberOfGuess][0] = g1;
    guesses[numberOfGuess][1] = g2;
    guesses[numberOfGuess][2] = g3;
    // indexing
    numberOfGuess++;
  }
  if (g1 != password[0] || g2 != password[1] || g3 != password[2]) {
    // if password is not guessed yet, do this
    printf(" > The day passed by and your luck is not here.\n%s\n > You're guessed %d times.\n > The right password is %d %d %d\n", doorclosed , numberOfGuess + 1, password[0], password[1], password[2]);
    // print all guesses
    printf(" > All your guesses are:\n");
    for (int i = 0; i < numberOfGuess; i++) {
      // print each guess, seperated by space, as when user input
      printf("   %d %d %d\n", guesses[i][0], guesses[i][1], guesses[i][2]);
    }
    printf(" > You're not a genius.\n > Better luck next time.\n");
  }
};

int main() {
  // random seed
  srand(time(NULL));
  // save password to array
  int password[3] = {rand() % 10, rand() % 10, rand() % 10};

  const char *instructions = " > OMG, THE SECREAT DOOR IS LOCKED >:(\n\n"
    "- The door's password is consist of a number that have 3 digits, and you\n  "
      "have to guess it.\n"
    "- But with some ✨magic✨ of someone-who-no-one-care, the door will tell\n  "
      "you something like \"1 right 2 wrong so far.\". I don't know what does\n  "
      "it mean, but you can guess this.\n";
  printf("\n > You have found that the treasures is just behind the secret door.\n > Look...\n%s\n%s\n", doorclosed, instructions);
  // push the number to the guess function
  guess(password);
  return 0;
}
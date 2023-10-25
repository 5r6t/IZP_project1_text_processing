///////////////////////////////
// Name:    Jaroslav Mervart //
// xlogin:  xmervaj00        //
// File:    keyfilter.c      //
///////////////////////////////

#include <stdio.h>
#include <stdbool.h>
#include <string.h> 
#include <ctype.h> 

void toUpp(char  *str) 
{ //convert characters in string to uppercase
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

void HandleUserInput(char *userInput, const char *input) 
{ //for copying strings with uppercase conversion
    strncpy(userInput, input, strlen(input)); 
    userInput[strlen(input)] = '\0'; 
    toUpp(userInput); 
}

void emptyString() 
{
  char buffer[101];
  bool printedChars[128] = {false}; // ASCII has 127 characters

  while (fgets(buffer, sizeof(buffer), stdin)) 
  {
    toUpp(buffer);
    char addressChar = buffer[0]; // store first letter in buffer 
    int lett = (int)addressChar;  // convert char. to ASCII value

    if (lett > 0 && lett <128) {
      printedChars[lett]= true;   // if char. belongs to ASCII, mark true in bool array
      }
  }

  fprintf(stdout, "Enable: ");
  for (int i = 0; i < 128; i++) {
    if (printedChars[i]) {
      fprintf(stdout, "%c", (char)i);
    }
  }
  putchar('\n');
}

void enableString (char **argv)
{
  char buffer[101]; // used for storing addresses during processing with a terminating character
  char userInput[100] = "";
  char foundOutput[101] = "";	// reserved for a single address to be printed in Found

  bool printedChars[128] = { false };	

  int counter = 0;	// counts the number of matched addresses

  HandleUserInput (userInput, argv[1]);
  int len = strlen (userInput);

  while (fgets (buffer, sizeof (buffer), stdin))
  {
    if (buffer[0] != '\0')
	  {
	  toUpp (buffer);	

	  if ((strstr (buffer, userInput) == buffer))
	    {	// if the user input can be found in the address
	    int charIndex = (int) buffer[len];	// get ascii value of character
	    printedChars[charIndex] = true;	// Mark this character as "true" in the bool array
	    counter++;
	    HandleUserInput (foundOutput, buffer); // only for cases if counter == 1 (found)
	    }
	  }
  }

  if (counter > 1) 
  { // more than 1 address matched
    fprintf (stdout, "Enable: ");
    for (int i = 0; i < 128; i++) 
    {
	    if (printedChars[i]) {
	      fprintf (stdout, "%c", (char) i);
	    }
	  }
    fprintf (stdout, "\n");
  }

  else if (counter == 1) 
  { // a single address has been matched
    fprintf (stdout, "Found: %s", foundOutput);
    }

  else {
    fprintf (stdout, "Not found\n");
    }
}

int main (int argc, char **argv)
{ 
  if (argc == 1) 
    { //no arguments given
      emptyString ();
    }
  else if (argc == 2) 
    { //one argument given
      enableString (argv);
    }
  else if (argc > 2) 
    { 
      fprintf (stderr, "Too much arguments!");
    }

  return 0;
}
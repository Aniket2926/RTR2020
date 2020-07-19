#include <stdio.h>

//macros

#define MAX_STRING_LENGTH 512
#define SPACE ' '
#define FULLSTOP '.'
#define COMMA ','
#define EXCLAMATION '!'
#define QUESTION_MARK '?'

int main(void) 
{ 
    //function prototype
    int MyStrlen(char[]); 
    char MyToUpper(char);


    //variable declarations 
    char chArray[MAX_STRING_LENGTH], chArray_CapitalizedFirstLetterOfEveryWord [MAX_STRING_LENGTH]; // A Character Array Is A String
    int iStringLength;
    int i, j;
 
    //code
 
    // *** STRING INPUT ***
    printf("\n\n"); 
    printf("Enter A String : \n\n"); 
    gets_s(chArray, MAX_STRING_LENGTH);
    
    iStringLength = MyStrlen(chArray); j = 0;
    for (i = 0; i < iStringLength; i++)
    {
        if (i == 0)     //First Letter Of Any Sentence Must Be A CAPITAL LETTER  
            chArray_CapitalizedFirstLetterOfEveryWord[j] = MyToUpper(chArray[i]);
        else  if (chArray[i] == SPACE) //First Letter Of Every Word In The Sentence Must Be A CAPITAL LETTER. Words Are Separated By Spaces. 
            {   
                chArray_CapitalizedFirstLetterOfEveryWord[j] = chArray[i]; 
                chArray_CapitalizedFirstLetterOfEveryWord[j + 1] = MyToUpper(chArray [i + 1]);
         
                //SINCE, ALREADY TWO CHARACTERS (AT INDICES 'i' AND i + 1 HAVE BEEN CONSIDERED IN THIS else-if BLOCK...WE ARE EXTRA-INCREMENTING 'i' AND 'j' BY 1
                j++; 
                i++; 
            }
        
            else if ((chArray[i] == FULLSTOP || chArray[i] == COMMA || chArray[i] == EXCLAMATION || chArray[i] == QUESTION_MARK) && (chArray[i] != SPACE)) //First Letter Of Every Word After Punctuation Mark, In The Sentence Must Be A CAPITAL LETTER. Words Are Separated By Punctuations.
                {
                    chArray_CapitalizedFirstLetterOfEveryWord[j] = chArray[i];   
                    chArray_CapitalizedFirstLetterOfEveryWord[j + 1] = SPACE;  
                    chArray_CapitalizedFirstLetterOfEveryWord[j + 2] = MyToUpper(chArray[i + 1]);
                    // SINCE, ALREADY TWO CHARACTERS (AT INDICES 'i' AND i + 1 HAVE BEEN CONSIDERED IN THIS else-if BLOCK...WE ARE EXTRA-INCREMENTING 'i' BY 1  
                    // SINCE, ALREADY THREE CHARACTERS (AT INDICES 'j' AND (j + 1) AND (j + 2) HAVE BEEN CONSIDERED IN THIS else-if BLOCK...WE ARE EXTRAINCREMENTING 'j' BY 2   
                    j = j + 2;   i++;
        }
            else   
            chArray_CapitalizedFirstLetterOfEveryWord[j] = chArray[i];
        j++;
               
    }
        chArray_CapitalizedFirstLetterOfEveryWord[j] = '\0';

        // *** STRING OUTPUT ***
        printf("\n\n");
        printf("String Entered By You Is : \n\n");
        printf("%s\n", chArray);
       
        printf("\n\n");
        printf("String After Capitalizing First Letter Of Every Word : \n\n");
        printf("%s\n", chArray_CapitalizedFirstLetterOfEveryWord);


        getch();
        return(0);
    }
    int MyStrlen(char str[]) 
    {
        //variable declarations 
        int j; 
        int string_length = 0;
 
        //code 
        // *** DETERMINING EXACT LENGTH OF THE STRING, BY DETECTING THE FIRST OCCURENCE OF NULL-TERMINATING CHARACTER ( \0 ) ***
        for (j = 0; j < MAX_STRING_LENGTH; j++)
        { 
            if (str[j] == '\0')  
                break; 
            else  
                string_length++;
        } 
        return(string_length);
    }
    char MyToUpper(char ch) 
    { 
        //variable declaration 
        int num; int c;
     
        //code
     
        // ASCII VALUE OF 'a' (97) - ASCII VALUE OF 'A' (65) = 32 // THIS SUBTRACTION WILL GIVE THE EXACT DIFFERENCE BETWEEN THE UPPER AND LOWER CASE COUNTERPARTS OF EACH LETTER OF THE ALPHABET 
        // IF THIS DIFFERENCE IS SUBTRACTED FROM THE ASCII VALUE OF A LOWER CASE LETTER, THE RESULTANT ASCII VALUE WILL BE THAT OF ITS UPPER CASE COUNTERPART, HENCE, HELPING US TO FIND ITS UPPER CASE LETTER !!!
        // ASCII VALUES OF 'a' to 'z' => 97 TO 122 // ASCII VALUES OF 'A' to 'Z' => 65 TO 90
        num = 'a' - 'A';
        if ((int)ch >= 97 && (int)ch <= 122)
        { 
            c = (int)ch - num;  return((char)c);
        }
        else 
            return(ch);
    }


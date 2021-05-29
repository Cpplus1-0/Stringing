#include <iostream>

using namespace std;

int strength(string str);
int findAlpha(char alpha, string str);
bool strequal(string one, string two);
string streverse(string str);
string strjoin(string one, string two);
int isSubbed(string one, string two, bool &affix);
bool compound(string str);
int splitindex(string word);
string stringslice(string word, int start, int end);

int main()
{
    cout << "This program computes some basic string operations. " << endl << endl;

    cout << "(1) Calculate the length of a string " << endl;
    cout << "(2) Calculate the number of character occurences in a string " << endl;
    cout << "(3) Check if a string is a substring of another string and return the indices in which the substring occurs. " << endl;
    cout << "(4) Implementation of the concept of prefix and suffix in a string " << endl;
    cout << "(5) Join two strings " << endl;
    cout << "(6) Reverse the arrangement of the characters in a string " << endl;
    cout << "(7) Check if two strings are equal " << endl;
    cout << "(8) Proof of formula using 'r' as the function that reverses a string " << endl;
    cout << "\tLet A = Dog, B = Cat (AB)^r = (B)^r(A)^r" << endl;
    cout << "\t(DogCat)^r = (Cat)^r(Dog)^r = taCgoD" << endl;

    cout << endl << "Enter your choice: ";
    int choice;
    cin >> choice;

    cout << endl << endl;
    string word;

    if(choice != 8)
    {
        cout << "Enter " << ( (choice > 2 && choice != 6) ? "1st" : "a") << " string: ";
        cin >> word;
    }
    else
    {
        cout << "Enter a compound word: ";
        for(cin >> word; !compound(word); cin >> word)
            cout << endl << "Sorry! The word you have entered is not compound. " << endl << "Make sure to capitalize the first letter for both words in the compound word. Please try again. " << endl << "Example: [FootBall]" << endl << endl << "Enter another compound word: ";

        cout << endl;
    }

    string wordup = "";

    if(choice > 2 && choice != 6 && choice != 8)
    {
        cout << "Enter 2nd string: ";
        cin >> wordup;
    }

    int count, counter, index = 0;
    char alpha;
    bool affix;
    string finale;

    switch(choice)
    {
        case 1:
            cout << endl << "The length of the string '" << word << "' : " << strength(word);

            break;

        case 2:
            cout << "Enter a character: ";
            cin >> alpha;

            counter = findAlpha(alpha, word);

            cout << endl;
            if(counter)
                cout << "The character '" << alpha << "' occurs " << counter << ( counter == 1 ? " time" : " times" ) << " in the string '" << word << "'." << endl;
            else
                cout << "The character '" << alpha << "' does not occur at all in the string '" << word << "'.";

            break;

        case 3:
            index = isSubbed(word, wordup, affix);
            cout << endl << "The substring '" << wordup << "' occurs on the indices: [" << (index - 1) << " - " << (index + strength(wordup) - 2) << "] on the string '" << word << "'" << endl;

            break;

        case 4:
            index = isSubbed(word, wordup, affix);
            cout << endl << "The substring '" << wordup << "' is a ";
            if( (index + strength(wordup) - 1) == strength(word) )
                cout << "suffix";
            else if( index == 1 )
                cout << "prefix";
            else
                cout << "neither prefix nor suffix";

            cout << " of the string '" << word << "'" << endl << endl;

            break;

        case 5:
            cout << "The following strings '" << word << "' & '" << wordup << "' concatenated yield: " << strjoin(word, wordup) << endl;
            break;

        case 6:
            cout << "The reverse order of the string '" << word << "' is: " << streverse(word);
            break;

        case 7:
            cout << endl << "The two strings are " << ( strequal(word, wordup) ? "" : " not ") << "equal. " << endl;
            break;

        case 8:
            index = splitindex(word);

            finale = word;

            wordup = stringslice(word, 0, index);
            word = stringslice(word, index, strength(word));
            cout << "*************************************************************************" << endl;
            cout << endl << "Separating the compound word into a prefix 'p' and suffix 's': " << endl;
            cout << "Prefix: " << wordup << endl;
            cout << "Suffix: " << word << endl;

            cout << endl << "Reversing the prefix and suffix individually as (p)^r and (s)^r" << endl;
            wordup = streverse(wordup);
            cout << "(p)^r: " << wordup << endl;

            word = streverse(word);
            cout << "(s)^r: " << word << endl;

            cout << endl << "Combining the suffix and prefix in that order as (s)^r(p)^r: " << strjoin(word, wordup) << endl;

            cout << endl << "Reversing the original compound word as (ps)^r: ";
            cout << streverse(finale);

            cout << endl << endl << "As we can see both of the strings are equal through both approaches. " << endl;
            cout << "Hence, the formula/equality has been proven as (ps)^r = (s)^r(p)^r " << endl << endl;

            cout << "*************************************************************************" << endl;
            break;

        default:
            cout << "Sorry! There is an error in your choice of input. " << endl;
    }

    cout << endl;

    return 0;
}

//Find string length
int strength(string str)
{
    int count = 0;
    for(char alpha = str[count]; alpha != '\0'; alpha = str[count++]);

    return count-1;
}

//Find specific character in string and calculate the number of its occurences
int findAlpha(char alpha, string str)
{
    int count, counter = 0;
    for(char temp = str[count]; str[count] != '\0'; temp = str[count++])
        if(str[count] == alpha)
            counter++;

    return counter;
}

//Reverse the order the alphabets in a string
string streverse(string str)
{
    int stringenth = strength(str);
    char temp ;
    for(int count = 0; count < (stringenth / 2); count++)
    {
        temp = str[count];
        str[count] = str[stringenth - count - 1];
        str[stringenth - count - 1] = temp;
    }

    return str;
}

//Check if two strings are equal
bool strequal(string one, string two)
{
    if(strength(one) != strength(two) )
        return false;

    int stringenth = strength(one);

    for(int count = 0; count < stringenth; count++)
        if(one[count] != two[count])
            return false;

    return true;
}

//Joining two strings into one
string strjoin(string one, string two)
{
    char * charray = new char[strength(one) + strength(two)];

    int count;
    for(count = 0; count < strength(one); count++)
        charray[count] = one[count];

    int counter = count;
    count = 0;
    while(count < strength(two) )
        charray[counter++] = two[count++];

    charray[counter] = '\0';

    return charray;
}

int isSubbed(string one, string two, bool &affix)
{
    int counter, count = 0;
    int index = -1;
    affix = false;

    while( count < strength(one) )
    {
        if(two[counter++] == one[count++])
        {
            if(counter == strength(two))
                affix = true;
            else
            {
                if(counter == 1)
                    index = count;

                continue;
            }
        }
        else
            counter = 0;
    }

    if(!affix)
        index = -1;

    return index;
}

bool compound(string str)
{
    int capcount = 0;

    for(int count = 0; count < strength(str); count++)
        if(str[count] > 64 && str[count] < 91)
            capcount++;

    if(capcount == 2)
        return true;

    return false;
}

int splitindex(string word)
{
    for(int count = 1; count < strength(word); count++)
        if(word[count] > 64 && word[count] < 91)
            return count;
}

string stringslice(string word, int start, int end)
{
    int counter = 0;
    char * charray = new char[end - start];
    for(int count = start; count < end; count++)
        charray[counter++] = word[count];

    charray[counter] = '\0';

    return charray;
}

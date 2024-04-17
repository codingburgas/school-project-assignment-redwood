#include "../Headers/Test.h"
#include "../Headers/Quiz.h"
#include "../Headers/Photos.h"
#include "../Headers/MenuStatsTest.h"
#include "../Headers/Start.h"
#include "raylib.h"

bool ShowTest = false;
int Count = 0; // Count if you have answered 20 questions
int TotalResult = 0;

int SizeAllResults = 0;
string PossibleQuestions[50]
{
        "Value of pi rounded to two decimal places?",
    "Solve for x: 2x + 5 = 15",
    "Square root of 64?",
    "Type of triangle with angles 45, 45, and 90?",
    "Sum of interior angles of a hexagon?",
    "Author of 'Romeo and Juliet'?",
    "Synonym for 'beautiful'?",
    "Noun in 'The cat chased the mouse'?",
    "Example of a conjunction?",
    "Literary device in 'time flies'?",
    "Capital city of France?",
    "Longest river in the world?",
    "Largest desert in the world?",
    "Least populous continent?",
    "Capital city of Australia?",
    "Composer of 'Moonlight Sonata'?",
    "Instrument with highest pitch?",
    "Meaning of 'forte' in music?",
    "Known as 'King of Pop'?",
    "Famous deaf composer?",
    "Discoverer of America in 1492?",
    "Year American Civil War ended?",
    "First female Prime Minister of UK?",
    "Year World War I began?",
    "First President of USA?",
    "Value of 5 squared?",
    "Perimeter of rectangle: length 8, width 4?",
    "Next number in sequence: 1, 4, 9, 16, ...?",
    "Value of 3 factorial (3!)?",
    "Degrees in a right angle?",
    "Plural form of 'child'?",
    "Author of Harry Potter series?",
    "Figurative language in 'quiet as a mouse'?",
    "Proper noun?",
    "Past tense of 'sing'?",
    "Largest ocean by area?",
    "Country with Great Barrier Reef?",
    "Capital city of Japan?",
    "Mountain range on northern border of India?",
    "Largest country by land area?",
    "Composer of 'Four Seasons'?",
    "Lowest male singing voice type?",
    "Term for gradual increase in volume in music?",
    "Instrument family of clarinet?",
    "Composer of '1812 Overture'?",
    "First female astronaut in space?",
    "First permanent English settlement in North America?",
    "First emperor of Rome?",
    "Year Berlin Wall fell?",
    "First woman to win a Nobel Prize?"
};
string PossibleAnswers[50][4] =
{
        {"3.14", "3.16", "3.12", "3.18"},
        {"x = 5", "x = 7", "x = 8", "x = 10"},
        {"6", "8", "10", "12"},
        {"Equilateral", "Isosceles", "Scalene", "Right"},
        {"360", "540", "720", "900"},
        {"William Shakespeare", "Jane Austen", "Charles Dickens", "Emily Bronte"},
        {"Ugly", "Pretty", "Plain", "Average"},
        {"Cat", "Chased", "The", "Mouse"},
        {"And", "House", "Run", "Quickly"},
        {"Simile", "Metaphor", "Hyperbole", "Personification"},
        {"Berlin", "London", "Paris", "Madrid"},
        {"Nile", "Amazon", "Yangtze", "Mississippi"},
        {"Sahara", "Gobi", "Antarctic", "Arabian"},
        {"Africa", "Asia", "Australia", "Antarctica"},
        {"Sydney", "Canberra", "Melbourne", "Brisbane"},
        {"Wolfgang Amadeus Mozart", "Ludwig van Beethoven", "Johann Sebastian Bach", "Franz Schubert"},
        {"Piano", "Violin", "Flute", "Trombone"},
        {"Slowly", "Loud", "Soft", "Fast"},
        {"Michael Jackson", "Elvis Presley", "Madonna", "Prince"},
        {"Wolfgang Amadeus Mozart", "Ludwig van Beethoven", "Johann Sebastian Bach", "Frederic Chopin"},
        {"Christopher Columbus", "Ferdinand Magellan", "Vasco da Gama", "Marco Polo"},
        {"1863", "1865", "1870", "1875"},
        {"Margaret Thatcher", "Theresa May", "Angela Merkel", "Indira Gandhi"},
        {"1914", "1917", "1920", "1923"},
        {"George Washington", "John Adams", "Thomas Jefferson", "Abraham Lincoln"},
        {"25", "36", "49", "64"},
        {"16", "24", "32", "40"},
        {"25", "36", "49", "64"},
        {"3", "6", "9", "12"},
        {"45", "90", "180", "360"},
        {"Children", "Childs", "Childen", "Childer"},
        {"J.K. Rowling", "J.R.R. Tolkien", "George R.R. Martin", "Suzanne Collins"},
        {"Simile", "Metaphor", "Hyperbole", "Personification"},
        {"cat", "city", "Monday", "car"},
        {"sang", "singed", "sanged", "sings"},
        {"Atlantic", "Indian", "Pacific", "Arctic"},
        {"Australia", "Brazil", "Indonesia", "Mexico"},
        {"Tokyo", "Beijing", "Seoul", "Bangkok"},
        {"Andes", "Himalayas", "Alps", "Rockies"},
        {"Russia", "Canada", "China", "United States"},
        {"Antonio Vivaldi", "Ludwig van Beethoven", "Johann Sebastian Bach", "Wolfgang Amadeus Mozart"},
        {"Baritone", "Tenor", "Alto", "Bass"},
        {"Diminuendo", "Forte", "Crescendo", "Decrescendo"},
        {"Brass", "Percussion", "String", "Woodwind"},
        {"Pyotr Ilyich Tchaikovsky", "Franz Liszt", "Igor Stravinsky", "Johannes Brahms"},
        {"Sally Ride", "Valentina Tereshkova", "Mae Jemison", "Christa McAuliffe"},
        {"Jamestown", "Plymouth", "Roanoke", "St. Augustine"},
        {"Augustus", "Julius Caesar", "Nero", "Constantine"},
        {"1985", "1989", "1991", "1993"},
        {"Marie Curie", "Rosa Parks", "Mother Teresa", "Malala Yousafzai"}
};
int Random = rand() % 50 + 1; //Variable to choose a random question and answers for the exam
int Index = 0; // Index used in answers 2D array
int TrueAnswersA[50] = {1, 4, 6, 8, 9, 11, 12, 14, 16, 19, 21, 23, 25, 28, 31, 33, 34, 36, 38, 40, 43, 45, 47, 49};
int TrueAnswersB[50] = {2, 3, 7, 10, 13, 15, 17, 18, 20, 22, 24, 26, 29, 30, 32, 35, 37, 39, 41, 44, 46, 48, 50};
int TrueAnswersC[2] = {27,42};
int TrueAnswersD[2] = {5,49};

double AllResults[100]; // Store all scores in this array
int IndexAllResults = 0;
void Test()
{
    srand(time(NULL));
    
    
    if (ShowTest)
    {
        DrawTexture(TestBackground, 0, 0, RAYWHITE);
        if (Count <= 20)
        {
            // Draw qustion and answers
            DrawText((const char*)PossibleQuestions[Random - 1].data(), 80, 100, 45, BLACK); // Convert the string that stores the question to const char* by casting its core char array
            DrawText((const char*)PossibleAnswers[Random - 1][Index].data(), 210, 250, 50, BLACK);
            DrawText((const char*)PossibleAnswers[Random - 1][++Index].data(), 210, 370, 50, BLACK);
            DrawText((const char*)PossibleAnswers[Random - 1][++Index].data(), 210, 500, 50, BLACK);
            DrawText((const char*)PossibleAnswers[Random - 1][++Index].data(), 210, 600, 50, BLACK);

            //Draw answer buttons
            DrawTexture(OptionA, 80, 230, RAYWHITE);
            DrawTexture(OptionB, 85, 350, RAYWHITE);
            DrawTexture(OptionC, 90, 465, RAYWHITE);
            DrawTexture(OptionD, 95, 580, RAYWHITE);
            
            bool HoverOnA = CheckCollisionPointRec(GetMousePosition(), { 80,230,(float)OptionA.width,(float)OptionA.height });
            bool HoverOnB = CheckCollisionPointRec(GetMousePosition(), { 85,350,(float)OptionB.width,(float)OptionB.height });
            bool HoverOnC = CheckCollisionPointRec(GetMousePosition(), { 90,465,(float)OptionC.width,(float)OptionC.height });
            bool HoverOnD = CheckCollisionPointRec(GetMousePosition(), { 95,580,(float)OptionD.width,(float)OptionD.height });

            
            if (HoverOnA && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                for (int each : TrueAnswersA)
                {
                    if (each == Random)
                    {
                        TotalResult++;
                        Random = rand() % 50 + 1;
                        Count++;
                        break;
                    }
                }
                
                Random = rand() % 50 + 1;
                Count++;
                Index = 0; //Reset index for getting question and answers' values
            }
            if (HoverOnB && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                for (int each : TrueAnswersB)
                {
                    if (each == Random)
                    {
                        TotalResult++;
                        Random = rand() % 50 + 1;
                        Count++;
                        break;
                    }
                }
                
                Random = rand() % 50 + 1;
                Count++;
                Index = 0; //Reset index for getting question and answers' values
            }
            if (HoverOnC && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                
                for( int each : TrueAnswersC)
                {
                    if (each == Random)
                    {
                        TotalResult++;
                        Random = rand() % 50 + 1;
                        Count++;
                        break;
                    }   
                }
                
                Random = rand() % 50 + 1;
                Count++;
                Index = 0; //Reset index for getting question and answers' values
            }
            if (HoverOnD && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                for (int each : TrueAnswersD)
                {
                    if (each == Random)
                    {
                        TotalResult++;
                        Random = rand() % 50 + 1;
                        Count++;
                        break;
                    }
                }
                
                Random = rand() % 50 + 1;
                Count++;
            }
            Index = 0; //Reset index for getting question and answers' values
        }
        else
        {
            //Calculate and output your total score
            string Score = to_string(static_cast<int>(static_cast<float>(TotalResult) / 20 * 100)) + "%";
 

            DrawText("Total Score:", 195, 30, 150, BLACK);

            DrawText((const char*)Score.data(), 480, 300,200, BLACK);
            DrawTexture(ReturnButton, 10, 10, RAYWHITE);
            
            if (TotalResult <= 50)
            {
                DrawText("Try Again!", 390, 520, 100, RED);
            }
            else if (TotalResult >= 50 && TotalResult <= 64)
            {
                DrawText("Nice!", 390, 520, 100, RED);
            }
            else if (TotalResult >= 64 && TotalResult <= 73)
            {
                DrawText("Good job!", 390, 520, 100, RED);
            }
            else if (TotalResult >= 73 && TotalResult <= 89)
            {
                DrawText("Well done!", 390, 520, 100, RED);
            }
            else
            {
                DrawText("Excellent!", 390, 520, 100, RED);
            }

            //Return to the menu if you have finished and clicked return
            bool HovOnReturn = CheckCollisionPointRec(GetMousePosition(), { 10,10,(float)ReturnButton.width,(float)ReturnButton.height });
            if (HovOnReturn && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                ShowTest = false; // Go back to the menu
                AllResults[IndexAllResults++] = static_cast<double>(TotalResult) / 20 * 100; // Store all scores in this vector
                TotalResult = 0; // Reset the result to use it again
                Count = 0; // Reset the counter
                
                SizeAllResults++;
            }
            if (HovOnReturn)
            {
                DrawTexture(ReturnButton, 10, 10, GREEN);
            }
        }
    }
}
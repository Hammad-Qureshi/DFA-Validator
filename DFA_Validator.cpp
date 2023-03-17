#include <iostream>
#include <string>
using namespace std;

class dfa
{
public:
int d[10][10], final[10];                                                // final = position of final state/states       d[10][10] = is for transitions  
char alphabets[10];                                                      // can be anything(which makes up a string/language)
int no_states = 0, no_alphabets = 0, no_finals = 0;                      // no_states = total states , no_alpha = total alpha , no_finals  = total final states

    void features()
    {
        do
        {
            cout << "\nEnter number of states (max 10): ";                   // input the total number of states
            cin >> no_states;

            if(no_states > 10 || no_states < 1)
            {
                cout << "Enter size within the limit.\n";
            }

        } while( no_states > 10 || no_states < 1 );

        do
        {
            cout << "Enter number of alphabets (max 10): ";             // input total number of alphabets
            cin >> no_alphabets;

            if (no_alphabets > 10 || no_alphabets < 1)
            {
                cout << "\nEnter size within the limit.\n";
            }

        } while (no_alphabets > 10 || no_alphabets < 1);

        cout << endl;

        for (int i = 0; i < no_alphabets; i++)                          // alphabet for language
        {
            cout << "-Enter your alphabet no." << i+1 << " : ";
            cin >> alphabets[i];           
        }

        do
        {
            cout << "\nEnter number of final states (max 10): ";        //  total number of final states
            cin >> no_finals;

            if (no_finals > 10 || no_finals < 1 || no_finals > no_states)
            {
                cout << "\n * Enter size within the limit. *\n";
            }

        } while (no_finals > 10 || no_finals < 1 || no_finals > no_states);

        cout << endl;

        for (int i = 0; i < no_finals; i++)
        {
            do
            {
                cout << "-Enter your final State no." << i << " : ";            // final states position
                cin >> final[i];

                if (final[i] > no_states-1)
                {
                    cout << "\n * Final State can't be greater than no. of states. :) *" << endl << endl;
                    cout << "   ";
                    system("pause");
                    cout << endl;
                }

            } while (final[i] > no_states-1);
        }

        cout << "\nNow Enter Transitions \n";                                   // transitions of alphabets
        for (int i = 0; i < no_states; i++)
        {
            for (int j = 0; j < no_alphabets; j++)
            {
                do
                {
                    cout << "(q" << i << "," << alphabets[j] << ") : ";
                    cin >> d[i][j];

                    if (d[i][j] > no_states)
                    {
                        cout << "\n* the entered state doesn't exist *" << endl << endl;
                    }
                    
                } while (d[i][j] > no_states);
                
            }
        }
    }
    
    int next(int i, int a)                                                      // change the transition states if the alphabets condition is fullfilled
    {
        return d[i][a];
    }

    void run()
    {
        system("cls");
        cout << "Intital state : 0" << endl;
        dfa A;
        A.features();
        string temp = "1";
        while (temp != "-1")
        {
        recheck:
            cout << "\nEnter String to check : ";
            string s;
            cin >> s;
            int state = 0;
            cout << "Intital state : 0" << endl;
            for (int i = 0; i < s.length(); i++)
            {
                int alpha;
                cout << s[i] << endl;
                for (int j = 0; j < A.no_alphabets; j++)
                {
                    alpha = -1;
                    if (s[i] == A.alphabets[j])
                    {
                        alpha = j;
                        break;
                    }
                }
                if (s[i] == '^')
                { 
                    state = 0;
                    break;
                }
                if (alpha == -1)
                {
                    cout << "\nWrong Alphabet caught" << endl;
                    goto recheck;
                }
                
                state = A.next(state, alpha);
                cout << s[i] << "," << state << endl;
            }
            for (int i = 0; i < A.no_finals; i++)
            {
                if (state == A.final[i])
                {
                    cout << "String Accepted";
                    goto accepted;
                }
            }
            cout << "String Rejected";
        accepted:

        restring:
            cout << "\n\nenter -1 to exit or 1 to continue : ";
            cin >> temp;

            if (temp == "-1")
            {
                system("exit");
            }
            else if (temp == "1")
            {
                goto recheck;
            }
            else
            {
                cout << "\n* Please select a correct option. *" << endl;
                system("pause");
                goto restring;
            }
            
        }
    }
};

int main()
{
    system("CLS");
    cout << "\t\t\t------------------------------------------\n";
    cout << "\t\t\tDeterministic Finite Automata Validator\n";
    cout << "\t\t\t------------------------------------------\n\n\n";

    system("pause");

    dfa A;
    A.run();

    return 0;
}
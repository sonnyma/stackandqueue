
#include "Scanner.h"
#include "Stack.h" // GENERIC STACK

#include <iostream>
using namespace std;

int main()
{
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack; // 2x Stacks of type Token

    t = S.getnext();

    while (t.tt != eof || opstack.isEmpty() == 0)  // while not end of file and not empty
    {
        Token result;
        if (t.tt == integer)                       // if integer put it into numstack, get next token
        {
            numstack.push(t);
            t = S.getnext();
        }
        else if (t.tt == lptok)                    // if "(" put it into opstack, get next token
        {
            opstack.push(t);
            t = S.getnext();
        }
        else if (t.tt == rptok)
        {
            if (opstack.peek().tt == lptok)        // if ")" and top of opstack is "(" remove "(" from opstack
            {
                opstack.pop();
                t = S.getnext();
            }
            else                                   // if ")" and top of opstack is not "(", calculate top two numstack and top opstack result
            {
                int temp1 = numstack.pop().val;
                int temp2 = numstack.pop().val;
                TokenType temp3 = opstack.pop().tt;
                switch (temp3)
                {
                case pltok:
                    result.val = (temp2 + temp1);
                    break;
                case mitok:
                    result.val = (temp2 - temp1);
                    break;
                case asttok:
                    result.val = (temp2 * temp1);
                    break;
                case slashtok:
                    result.val = (temp2 / temp1);
                    break;
                default:
                    cout << "Invalid operation." << endl;
                }
                numstack.push(result);
            }
        }
        else if (t.tt == pltok || t.tt == mitok || t.tt == eof) 
        { // if "+", "-" or end of file, and opstack is not empty and top is either "+","-","*", or "/", calculate top two numstack and top opstack result
            if (opstack.isEmpty() == 0 && (opstack.peek().tt == pltok || opstack.peek().tt == mitok || opstack.peek().tt == asttok || opstack.peek().tt == slashtok))
            {
                int temp1 = numstack.pop().val;
                int temp2 = numstack.pop().val;
                TokenType temp3 = opstack.pop().tt;
                switch (temp3)
                {
                case pltok:
                    result.val = (temp2 + temp1);
                    break;
                case mitok:
                    result.val = (temp2 - temp1);
                    break;
                case asttok:
                    result.val = (temp2 * temp1);
                    break;
                case slashtok:
                    result.val = (temp2 / temp1);
                    break;
                default:
                    cout << "Invalid operation." << endl;
                }
                numstack.push(result);
            }
            else // if "+", "-" or end of file, and opstack is  empty or top is not "+","-","*", or "/", put operator into opstack and get next token
            {
                opstack.push(t);
                t = S.getnext();
            }
        }
        else if (t.tt == asttok || t.tt == slashtok)
        {
            if (opstack.isEmpty() == 0 && (opstack.peek().tt == asttok || opstack.peek().tt == slashtok)) // if "*" or "/", and opstack is not empty and top of opstack is "*" or "/", calculate top two number stack and top operation stack result 
            {
                int temp1 = numstack.pop().val;
                int temp2 = numstack.pop().val;
                TokenType temp3 = opstack.pop().tt;
                switch (temp3)
                {
                case pltok:
                    result.val = (temp2 + temp1);
                    break;
                case mitok:
                    result.val = (temp2 - temp1);
                    break;
                case asttok:
                    result.val = (temp2 * temp1);
                    break;
                case slashtok:
                    result.val = (temp2 / temp1);
                    break;
                default:
                    cout << "Invalid operation." << endl;
                }
                numstack.push(result);
            }
            else // if "*" or "/", and opstack is empty or top of opstack is not "*" or "/", put token into opstack and get next token
            {
                opstack.push(t);
                t = S.getnext();
            }
        }
    }
    return 0;
}

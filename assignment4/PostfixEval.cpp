#include <string>
#include <cctype>
#include "array/Stack.h"
#include "linked/Stack.h"

int evaluatePostfix(std::string expr, Stack &stack)
{
   for (int i = 0; i < expr.length(); i++)
   {
      if (isdigit(expr[i]))
      {
         int digit = expr[i] - '0';
         stack.push(digit);
      }
      else if (expr[i] == '+' || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
      {
         char operation = expr[i];
         int num2 = stack.pop();
         int num1 = stack.pop();
         int result;
         switch (operation)
         {
         case '+':
            result = num1 + num2;
            break;
         case '-':
            result = num1 - num2;
            break;
         case '*':
            result = num1 * num2;
            break;
         case '/':
            result = num1 / num2;
            break;
         default:
            break;
         }
         stack.push(result);
      }
      else
      {
         return -999;
         break;
      }
   }
   return stack.pop();
}
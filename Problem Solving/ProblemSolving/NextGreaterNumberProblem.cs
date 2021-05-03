using ProblemSolving.Interface;
using System;
using System.Collections.Generic;
using System.Linq;

namespace ProblemSolving
{
    public class NextGreaterNumberProblem : IProblemSolve
    {
        public object SolveProblem(params object[] parameters)
        {
            try
            {
                if (parameters == null) throw new Exception("The number shouldn't be null");
                else if (parameters.Length > 1) throw new Exception("Wrong number of arguments");
                else if (parameters[0] is string)
                {
                    var number = parameters[0].ToString();
                    if (!number.All(Char.IsDigit))
                    {
                        throw new Exception("Invalid number");
                    }
                }

                var param1 = Convert.ToInt32(parameters[0]);

                return NextGreaterNumber(param1);
            }
            catch (Exception ex)
            {
                throw ex;
            }
        }

        private int NextGreaterNumber(int previousNumber)
        {
            GetArray(previousNumber, out int[] arr, out int endIndex);
            int d = 0;
            int x = -1;
            int resultedNumber = 0;
            for (int j = endIndex - 1; j > 0; j--)
            {
                if (arr[j] > arr[j - 1])
                {
                    x = j - 1;
                    d = arr[j - 1];
                    break;
                }
            }
            if (x < 0) return previousNumber;
            GetRightmostSmallest(d, x + 1, endIndex, arr, out int y);
            SwapNum(ref arr[x], ref arr[y]);
            Array.Sort(arr, x+1, endIndex-(x+1));
            for (int i = 0; i < endIndex; i++)
            {
                resultedNumber += arr[i] * Convert.ToInt32(Math.Pow(10, endIndex - i - 1));
            }
            return resultedNumber;
        }

        private void GetRightmostSmallest(int d, int startIndex, int endIndex, int[] arr, out int y)
        {
            y = startIndex;
            for (int i = startIndex; i < endIndex; i++)
            {
                if (arr[startIndex] > d && arr[i] < arr[y])
                    y = i;
            }
        }
        private void SwapNum(ref int x, ref int y)
        {

            int tempswap = x;
            x = y;
            y = tempswap;
        }
        private void GetArray(int number, out int[] arr, out int endIndex)
        {
            List<int> numList = new List<int>();
            endIndex = 0;
            while (number != 0)
            {
                numList.Add(number % 10);
                number = number / 10;
                endIndex++;
            }
            arr = numList.ToArray();
            Array.Reverse(arr);
        }
    }
}

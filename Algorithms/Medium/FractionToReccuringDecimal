/*
166. Fraction to Recurring Decimal

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers are possible, return any of them.

It is guaranteed that the length of the answer string is less than 104 for all the given inputs.
*/


class Solution {
public:
    std::string fractionToDecimal(int numerator, int denominator)
    {
        if (!numerator)
        {
            return "0";
        }

        long n = labs(numerator);
        long d = labs(denominator);

        std::string result {};

        if (numerator > 0 ^ denominator > 0)
        {
            result += '-';
        }
        result += std::to_string(n / d);
        long fr = n % d;

        if (fr == 0)
            return result;
        else
            result.push_back('.');

        std::unordered_map<long, int> umap;

        while (fr)
        {
            if (umap.find(fr) != umap.end())
            {
                result.insert(umap[fr], "(");
                result += ')';
                break;
            }
            umap[fr] = result.size();
            fr *= 10;
            result += std::to_string(fr / d);
            fr %= d;
        }

        return result;
    }
};

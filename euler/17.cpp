#include <iostream>
#include <vector>
#include <string>

const std::string s1 = "one";
const std::string s2 = "two";
const std::string s3 = "three";
const std::string s4 = "four";
const std::string s5 = "five";
const std::string s6 = "six";
const std::string s7 = "seven";
const std::string s8 = "eight";
const std::string s9 = "nine";

const std::string s10 = "ten";
const std::string s11 = "eleven";
const std::string s12 = "twelve";
const std::string s13 = "thirteen";
const std::string s14 = "fourteen";
const std::string s15 = "fifteen";
const std::string s16 = "sixteen";
const std::string s17 = "seventeen";
const std::string s18 = "eighteen";
const std::string s19 = "nineteen";

const std::string s20 = "twenty";
const std::string s30 = "thirty";
const std::string s40 = "forty";
const std::string s50 = "fifty";
const std::string s60 = "sixty";
const std::string s70 = "seventy";
const std::string s80 = "eighty";
const std::string s90 = "ninety";

const std::string hundred = "hundred";
const std::string thousand = "thousand";

const std::string and_ = "and";

int countTen(const std::string& numStr)
{
    int sum = 0;
    sum += 10 * numStr.size();
    sum += s1.size();
    sum += s2.size();
    sum += s3.size();
    sum += s4.size();
    sum += s5.size();
    sum += s6.size();
    sum += s7.size();
    sum += s8.size();
    sum += s9.size();
    return sum;
}

int countHundred(const std::string& numStr)
{
    int sum = 0;

    if (numStr != "") {
        // <numStr> hundred [and]
        sum += 100 * numStr.size();
        sum += 100 * hundred.size();
        sum += 99 * and_.size();
    }

    sum += countTen("");

    sum += s10.size();
    sum += s11.size();
    sum += s12.size();
    sum += s13.size();
    sum += s14.size();
    sum += s15.size();
    sum += s16.size();
    sum += s17.size();
    sum += s18.size();
    sum += s19.size();

    sum += countTen(s20);
    sum += countTen(s30);
    sum += countTen(s40);
    sum += countTen(s50);
    sum += countTen(s60);
    sum += countTen(s70);
    sum += countTen(s80);
    sum += countTen(s90);

    return sum;
}

int main()
{
    int sum = 0;
    sum += countHundred("");
    sum += countHundred(s1);
    sum += countHundred(s2);
    sum += countHundred(s3);
    sum += countHundred(s4);
    sum += countHundred(s5);
    sum += countHundred(s6);
    sum += countHundred(s7);
    sum += countHundred(s8);
    sum += countHundred(s9);

    sum += s1.size();
    sum += thousand.size();

    std::cout << sum << std::endl;
    return 0;
}
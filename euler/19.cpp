#include <iostream>

int main()
{
    int daysFromBeginning = 0;
    int count = 0;
    for (int year = 1900; year <= 2000; ++year) {
        for (int month = 1; month <= 12; ++month) {
            if (year >= 1901) {
                if (daysFromBeginning % 7 == 6) {
                    // std::cout << year << "." << month << std::endl;
                    ++count;
                }
            }
            if (month == 4 or month == 6 or month == 9 or month == 11) {
                daysFromBeginning += 30;
            } else if (month == 2) {
                bool leap = false;
                if (year % 400 == 0) {
                    leap = true;
                } else {
                    if (year % 100 != 0 and year % 4 == 0) {
                        leap = true;
                    }
                }
                if (leap) {
                    daysFromBeginning += 29;
                } else {
                    daysFromBeginning += 28;
                }
            } else {
                daysFromBeginning += 31;
            }

        }
    }
    std::cout << count << std::endl;
    return 0;
}
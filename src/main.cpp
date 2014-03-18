#include "Cut.hpp"
#include "Print.hpp"
#include "Total.hpp"
#include <iostream>

int
main(int, char**)
{
    using namespace std;
    using namespace companies101;

    Company c =
            {"Acme Corporation", {
                {"Research", {
                    {"Craig", "Redmond", 123456},
                    {"Erik" , "Utrecht", 12345 },
                    {"Ralf" , "Koblenz", 1234  },
                }},
                {"Development", {
                    {"Ray", "Redmond", 234567},
                }, {
                    {"Dev1", {
                        {"Klaus", "Boston", 23456},
                    }, {
                        {"Dev1.1", {
                            {"Karl", "Riga"     , 2345},
                            {"Joe" , "Wifi City", 2344},
                        }}
                    }}
                }}
            }};
    print(c);
    cout << total(c) << '\n';
    cut(c);
    cout << total(c) << '\n';

    return 0;
}


#include "Cut.hpp"
#include "FlatCompany.hpp"
#include "Total.hpp"
#include <iostream>

int
main(int, char**)
{
    using namespace std;
    using namespace companies101;

    FlatCompany   fc("Acme Corporation", { 
                         {"Craig", "Redmond"  , 123456},
                         {"Erik" , "Utrecht"  , 12345 },
                         {"Ralf" , "Koblenz"  , 12342 },
                         {"Ray"  , "Redmond"  , 234567},
                         {"Klaus", "Boston"   , 23456 },
                         {"Karl" , "Riga"     , 2345  },
                         {"Joe"  , "Wifi City", 2344  },
                     });
    NestedCompany nc =
            {
                "Acme Corporation",
                {
                    {
                        "Research",
                        {
                            {"Craig", "Redmond", 123456},
                            {"Erik" , "Utrecht", 12345 },
                            {"Ralf" , "Koblenz", 1234  },
                        }
                    },
                    {
                        "Development",
                        {
                            {"Ray", "Redmond", 234567},
                        },
                        {
                            {
                                "Dev1",
                                {
                                    {"Klaus", "Boston", 23456},
                                },
                                {
                                    {
                                        "Dev1.1",
                                        {
                                            {"Karl", "Riga"     , 2345},
                                            {"Joe" , "Wifi City", 2344},
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            };

    cout << total(nc) << '\n';
    cut(nc);
    cout << total(nc) << '\n';

    return 0;
}


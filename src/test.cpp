#include "Equal.hpp"
#include "Operations.hpp"
#include "Persistence.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <boost/property_tree/json_parser.hpp>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Fixtures
#include <boost/test/unit_test.hpp>
using namespace companies101;

struct Fixture {
    Company sample;

    Fixture() :
        sample("Acme Corporation", {
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
            }) {}
};


static constexpr double       EXPECTED_CUT    = 199873.5,
                              EXPECTED_MEDIAN = 57106.7,
                              EXPECTED_TOTAL  = 399747.0;
static constexpr unsigned int EXPECTED_DEPTH  = 3;


static std::string
slurp(const std::string& file)
{
    std::stringstream ss;
    std::ifstream     fs(file);
    ss << fs.rdbuf();
    return ss.str();
}


BOOST_FIXTURE_TEST_SUITE(Companies101, Fixture)

BOOST_AUTO_TEST_CASE(Equal)  { BOOST_CHECK(sample == sample);                           }
BOOST_AUTO_TEST_CASE(Depth)  { BOOST_CHECK_EQUAL(depth(sample),  EXPECTED_DEPTH);       }
BOOST_AUTO_TEST_CASE(Total)  { BOOST_CHECK_CLOSE(total(sample),  EXPECTED_TOTAL,  .01); }
BOOST_AUTO_TEST_CASE(Median) { BOOST_CHECK_CLOSE(median(sample), EXPECTED_MEDIAN, .01); }

BOOST_AUTO_TEST_CASE(Cut)
{
    cut(sample);
    BOOST_CHECK_CLOSE(total(sample), EXPECTED_CUT, .01);
}

BOOST_AUTO_TEST_CASE(Parsing)
{
    using namespace boost::property_tree;
    ptree tree = unparse(sample);
    std::stringstream ss;
    json_parser::write_json(ss, tree);

    BOOST_REQUIRE_EQUAL(ss.str(), slurp("sample.json"));

    json_parser:: read_json(ss, tree);
    BOOST_CHECK(parseCompany(tree) == sample);
}

BOOST_AUTO_TEST_SUITE_END()


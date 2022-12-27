#include <gtest.h>
#include "../LIBS/lib_parser/parser.h"

TEST(ParserTest, can_calculate) {
	Parser parser("21 + 12 / 100 + 30 - (20 + 30) * 100");

	EXPECT_EQ(-4948.88, parser.calculate());
}

TEST(ParserTest, can_transform_into_postfix) {
	Parser parser("21 + 12 / 100 + 30 - (20 + 30) * 100");

	EXPECT_EQ("21 12 100 /+30 +20 30 +100 *-", parser.getPostfix());
}

TEST(ParserTest, can_solve_brackets) {
	Parser parser("20 * (5+15)");

	EXPECT_EQ(400, parser.calculate());
}

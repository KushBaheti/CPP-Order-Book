#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include "Order.h"
#include "MatchingEngine.h"

using ::testing::SizeIs;
using ::testing::IsEmpty;

TEST(MatchingEngineTestSuite, AddOrderWhenOppositeBookIsEmpty) {
    MatchingEngine engine;
    Order order = Order("trader", "stock", 10, true);
    engine.run(order);
    EXPECT_EQ(engine.orderBook.buyBook["stock"][0], order);
}

TEST(MatchingEngineTestSuite, MatchEqualOrdersOfOppositeSides) {
    MatchingEngine engine;
    Order buyOrder = Order("buyTrader", "stock", 10, true);
    engine.run(buyOrder);
    Order sellOrder = Order("sellTrader", "stock", 10, false);
    engine.run(sellOrder);
    EXPECT_THAT(engine.orderBook.buyBook["stock"], IsEmpty());
    EXPECT_THAT(engine.orderBook.sellBook["stock"], IsEmpty());
}

TEST(MatchingEngineTestSuite, MatchPartialOrdersOfOppositeSides) {
    MatchingEngine engine;
    Order buyOrder = Order("buyTrader", "stock", 10, true);
    engine.run(buyOrder);
    Order sellOrder = Order("sellTrader", "stock", 5, false);
    engine.run(sellOrder);
    EXPECT_EQ(engine.orderBook.buyBook["stock"][0], Order("buyTrader", "stock", 5, true));
    EXPECT_THAT(engine.orderBook.sellBook["stock"], IsEmpty());
}

TEST(MatchingEngineTestSuite, MatchMultiplePartialOrdersOfOppositeSides) {
    MatchingEngine engine;
    Order sellOrder = Order("sellTrader", "G", 300, false);
    engine.run(sellOrder);
    Order buyOrder1 = Order("buyTrader1", "G", 200, true);
    engine.run(buyOrder1);
    Order buyOrder2 = Order("buyTrader2", "G", 200, true);
    engine.run(buyOrder2);
    EXPECT_EQ(engine.orderBook.buyBook["G"][0], Order("buyTrader2", "G", 100, true));
    EXPECT_THAT(engine.orderBook.sellBook["G"], IsEmpty());
}

TEST(MatchingEngineTestSuite, MatchMultipleOrdersOfOppositeSides) {
    MatchingEngine engine;
    Order sellOrder1 = Order("sellTrader1", "H", 200, false);
    engine.run(sellOrder1);
    Order sellOrder2 = Order("sellTrader2", "H", 200, false);
    engine.run(sellOrder2);
    Order sellOrder3 = Order("sellTrader3", "H", 200, false);
    engine.run(sellOrder3);
    Order buyOrder = Order("buyTrader", "H", 600, true);
    engine.run(buyOrder);
    EXPECT_THAT(engine.orderBook.buyBook["G"], SizeIs(0));
    EXPECT_THAT(engine.orderBook.sellBook["G"], SizeIs(0));
}

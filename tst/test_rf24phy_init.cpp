/********************************************************************************
*   File Name:
*   
*
*   Description:
*
*
*   2019 | Brandon Braun | brandonbraun653@gmail.com
********************************************************************************/

/* Interface Under Test Includes */
#include <RF24Phy/RF24Phy.hpp>

/* Test Driver Includes */
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <Chimera/mock/spi.hpp>


using ::testing::AtLeast;
using ::testing::_;

TEST(try1, test1)
{
  SPIMock spi;

  Chimera::SPI::Setup setup;

  EXPECT_CALL( spi, testfunc())
    .Times(AtLeast(1));

  EXPECT_CALL( spi, deInit())
    .Times(AtLeast(1));

  EXPECT_CALL( spi, init(_))
    .Times(AtLeast(1));

  ASSERT_EQ(1, 1);
}
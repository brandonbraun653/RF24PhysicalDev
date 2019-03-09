/********************************************************************************
* File Name:
*   test_rf24phy_init.cpp
*
* Description:
*   Tests the initialization function of a RF24Phy::Phy object.
*
* 2019 | Brandon Braun | brandonbraun653@gmail.com
********************************************************************************/

/* Interface Under Test Includes */
#include <RF24Phy/RF24Phy.hpp>

/* Test Driver Includes */
#include <gtest/gtest.h>
#include <gmock/gmock.h>
//#include <Chimera/mock/spi.hpp>

#include <Chimera/spi.hpp>
#include <Chimera/gpio.hpp>


using ::testing::AtLeast;
using ::testing::Exactly;
using ::testing::_;
using ::testing::Mock;

TEST(RF24PhyTest_begin, normalOperation)
{
  /*------------------------------------------------
  Initialize test objects
  ------------------------------------------------*/
  Chimera::Mock::SPIMock spi;
  Chimera::Mock::GPIOMock gpio;

  RF24Phy::Phy radio(&spi, &gpio);

  /*------------------------------------------------
  Set up expectations
  ------------------------------------------------*/
  EXPECT_CALL(spi, setChipSelectControlMode(_))
    .Times(AtLeast(1));

  EXPECT_CALL(spi, setChipSelect(_))
    .Times(Exactly(2));

  EXPECT_CALL(gpio, setMode(_, _))
    .Times(Exactly(1));

  EXPECT_CALL(gpio, setState(_))
    .Times(AtLeast(1));

  /*------------------------------------------------
  Call FUT
  ------------------------------------------------*/
  bool result = radio.begin();

  EXPECT_EQ( result, true );
  EXPECT_EQ( result, radio.isInitialized() );
}

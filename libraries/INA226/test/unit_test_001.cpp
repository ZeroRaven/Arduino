//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2021-05-18
// PURPOSE: unit tests for the INA226 library
//          https://github.com/RobTillaart/INA226
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual);               // a == b
// assertNotEqual(unwanted, actual);            // a != b
// assertComparativeEquivalent(expected, actual);    // abs(a - b) == 0 or (!(a > b) && !(a < b))
// assertComparativeNotEquivalent(unwanted, actual); // abs(a - b) > 0  or ((a > b) || (a < b))
// assertLess(upperBound, actual);              // a < b
// assertMore(lowerBound, actual);              // a > b
// assertLessOrEqual(upperBound, actual);       // a <= b
// assertMoreOrEqual(lowerBound, actual);       // a >= b
// assertTrue(actual);
// assertFalse(actual);
// assertNull(actual);

// // special cases for floats
// assertEqualFloat(expected, actual, epsilon);    // fabs(a - b) <= epsilon
// assertNotEqualFloat(unwanted, actual, epsilon); // fabs(a - b) >= epsilon
// assertInfinity(actual);                         // isinf(a)
// assertNotInfinity(actual);                      // !isinf(a)
// assertNAN(arg);                                 // isnan(a)
// assertNotNAN(arg);                              // !isnan(a)

#include <ArduinoUnitTests.h>


#include "INA226.h"



unittest_setup()
{
  fprintf(stderr, "\n INA226_LIB_VERSION: %s\n", (char *) INA226_LIB_VERSION);
}

unittest_teardown()
{
}


unittest(test_constructor)
{

  INA226 INA(0x40);
  
  assertTrue(INA.begin());
  assertTrue(INA.isConnected());
}


unittest(test_constants)
{
  assertEqual(0x8000, INA226_SHUNT_OVER_VOLTAGE);
  assertEqual(0x4000, INA226_SHUNT_UNDER_VOLTAGE);
  assertEqual(0x2000, INA226_BUS_OVER_VOLTAGE);
  assertEqual(0x1000, INA226_BUS_UNDER_VOLTAGE);
  assertEqual(0x0800, INA226_POWER_OVER_LIMIT);
  assertEqual(0x0400, INA226_CONVERSION_READY);

  assertEqual(0x0010, INA226_ALERT_FUNCTION_FLAG);
  assertEqual(0x0008, INA226_CONVERSION_READY_FLAG);
  assertEqual(0x0004, INA226_MATH_OVERFLOW_FLAG);
  assertEqual(0x0002, INA226_ALERT_POLARITY_FLAG);
  assertEqual(0x0001, INA226_ALERT_LATCH_ENABLE_FLAG);
}


unittest(test_core_functions)
{
  INA226 INA(0x40);
  // assertTrue(INA.begin());

  fprintf(stderr, "need mock up\n");
  /*
  fprintf(stderr, "%f\n", INA.getShuntVoltage());
  fprintf(stderr, "%f\n", INA.getBusVoltage());
  fprintf(stderr, "%f\n", INA.getPower());
  fprintf(stderr, "%f\n", INA.getCurrent());
  */
}


unittest(test_configuration)
{
  INA226 INA(0x40);
  // assertTrue(INA.begin());

  // only errors can be tested
  assertFalse(INA.setAverage(8));
  assertFalse(INA.setAverage(255));

  assertFalse(INA.setBusVoltageConversionTime(8));
  assertFalse(INA.setBusVoltageConversionTime(255));

  assertFalse(INA.setShuntVoltageConversionTime(8));
  assertFalse(INA.setShuntVoltageConversionTime(255));
}


unittest(test_calibration)
{
  INA226 INA(0x40);
  // assertTrue(INA.begin());

  // only errors can be tested
  assertFalse(INA.setMaxCurrentShunt(30));
  assertFalse(INA.setMaxCurrentShunt(0.0009));
  assertFalse(INA.setMaxCurrentShunt(0));
  assertFalse(INA.setMaxCurrentShunt(-1));

  assertFalse(INA.setMaxCurrentShunt(10, 0));
  assertFalse(INA.setMaxCurrentShunt(10, 0.0009));
}


unittest(test_setMode)
{
  INA226 INA(0x40);
  // assertTrue(INA.begin());

  // only errors can be tested
  assertFalse(INA.setMode(8));
  assertFalse(INA.setMode(255));
  assertFalse(INA.setMode(-1));
  /*
  assertTrue(INA.shutDown());
  assertTrue(INA.setModeShuntTrigger());
  assertTrue(INA.setModeBusTrigger());
  assertTrue(INA.setModeShuntBusTrigger());
  assertTrue(INA.setModeShuntContinuous());
  assertTrue(INA.setModeBusContinuous());
  assertTrue(INA.setModeShuntBusContinuous());
  */
}


unittest_main()

// --------

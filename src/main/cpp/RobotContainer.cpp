// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <units/angle.h>
#include <cstdlib>
#include <math.h>
#include "rev/CANSparkMax.h"

double curve_function(double x, double scale)
{
  return (scale != 0 && x != 100) ? (powf(2.718, -(scale / 10)) + powf(2.718, (abs(x * 127) - 127) / 10) * (1 - powf(2.718, -(scale / 10)))) * x : x; // a ternerary to improve performance
}
double curve_function2(double x, double scale)
{
  return (scale != 0 && x != 1) ? powf(2.178, ((std::abs(x * 127) - 127) * scale / 1000.0)) * x : x; // a ternerary to improve performance
}

RobotContainer::RobotContainer() : con{0}
{
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();

  printf("something");

  // Set up default drive command
  m_drive.SetDefaultCommand(frc2::RunCommand(
      [this]
      {
        m_drive.TankDrive(curve_function2(con.GetLeftY(), 12) * -12.0, curve_function2(con.GetRightY(), 8) * -12.0);
        frc::SmartDashboard::PutString("DB/String 0", std::to_string(con.GetLeftY()));
      },
      {&m_drive}));
  Button startedPressing;
  Button stoppedPressing;
  double pressedTime = 0;
  double stoppedTime = 0;
  arm.SetDefaultCommand(frc2::RunCommand(
      [this, &startedPressing, &stoppedPressing, &pressedTime, &stoppedTime]
      {
        // new code __________________________________ untested code
        if (startedPressing(con.GetR1Button()))
        {
          pressedTime = frc::GetTime().value();
        }
        if (stoppedPressing(!con.GetR1Button()))
        {
          stoppedTime = frc::GetTime().value();
        }

        if (con.GetR1Button())
        {
          arm.Lift((frc::GetTime().value() < pressedTime + 0.5) ? 3 : 1.2); // basically if-else
        }
        else
        {
          arm.Lift((frc::GetTime().value() < stoppedTime + 0.5) ? -1 : -0.3); // basically if-else
        }
        // __________________________________________________

        // old code
          // arm.Lift((con.GetR1Button()) ? 1.2 : -0.3);

        arm.Intake((con.GetR2Axis() + 1) * -8);
      },
      {&arm}));
}

void RobotContainer::ConfigureButtonBindings()
{
  // Configure your button bindings here
}

void RobotContainer::DisablePIDSubsystems()
{
}

frc2::Command *RobotContainer::GetAutonomousCommand()
{
  // Runs the chosen command in autonomous
  return new frc2::InstantCommand([] {});
}

// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/Command.h>
#include <frc2/command/ConditionalCommand.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/ParallelRaceGroup.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/WaitCommand.h>
#include <frc2/command/WaitUntilCommand.h>
#include <frc/motorcontrol/PWMSparkMax.h>

#include <frc/PS4Controller.h>

#include "Constants.h"
#include "subsystems/DriveSubsystem.h"
#include "subsystems/ArmSubsystem.h"
#include "util/Button.h" // was toggleable

namespace ac = AutoConstants;

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();
 
  /**
   * Disables all ProfiledPIDSubsystem and PIDSubsystem instances.
   * This should be called on robot disable to prevent integral windup.
   */
  void DisablePIDSubsystems();

  frc2::Command* GetAutonomousCommand();

 private:
  // The driver's controller
  // frc::PS4Controller m_driverController{OIConstants::kDriverControllerPort};
  frc::PS4Controller con;

  // The robot's subsystems and commands are defined here...

  // The robot's subsystems
  DriveSubsystem m_drive;
  ArmSubsystem arm;

  AutonomousCommand m_autonomousCommand ;

  // The chooser for the autonomous routines

  void ConfigureButtonBindings();
};

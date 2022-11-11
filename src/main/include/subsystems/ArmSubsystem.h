// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/Encoder.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/motorcontrol/PWMSparkMax.h>
#include <frc2/command/Subsystem.h>
#include <frc/motorcontrol/MotorControllerGroup.h>

#include <units/voltage.h>

#include <ctre/Phoenix.h>
#include "rev/CANSparkMax.h"

#include "Constants.h"

class ArmSubsystem : public frc2::Subsystem
{
public:
    ArmSubsystem();

    /**
     * Will be called periodically whenever the CommandScheduler runs.
     */
    void Periodic() override;

    // Subsystem methods go here.

    /**
     * Lifts the main arm with a given voltage
     *
     * @param voltage the voltage to send to the SparkMax Esc
     */
    void Lift(double voltage);

    /**
     * Spins the rubber bit with a given voltage
     *
     * @param voltage the voltage to send to the SparkMax Esc
     */
    void Intake(double voltage);

private:
    // Components (e.g. motor controllers and sensors) should generally be
    // declared private and exposed only through public methods.

    // The motor controllers
    ctre::phoenix::motorcontrol::can::WPI_VictorSPX spinny;
    rev::CANSparkMax lifty;
};

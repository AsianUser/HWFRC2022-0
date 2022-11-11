#include "subsystems/ArmSubsystem.h"

ArmSubsystem::ArmSubsystem()
    : lifty{6, rev::CANSparkMax::MotorType::kBrushless}, spinny{7} {}

void ArmSubsystem::Periodic()
{
    // Implementation of subsystem periodic method goes here.
}

void ArmSubsystem::Lift(double voltage)
{
    // set motor voltages
    lifty.SetVoltage(units::volt_t{voltage});
}

void ArmSubsystem::Intake(double voltage)
{
    // set motor voltages
    spinny.SetVoltage(units::volt_t{voltage});
}
#include "commands/AutonomousCommands.h";
#include <frc/Timer.h>

AutonomousCommand::AutonomousCommand(ArmSubsystem *arm) : m_arm{arm} // defining the subsystem
{
}
void AutonomousCommand::Execute()
{
    if (frc::Timer::GetMatchTime().value() >= 10)
        m_arm->Intake(-12);
    else
        m_arm->Intake(0);
};
bool AutonomousCommand::IsFinished()
{
    return (frc::Timer::GetMatchTime().value() < 5);
};
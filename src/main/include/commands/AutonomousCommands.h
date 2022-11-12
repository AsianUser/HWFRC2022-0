#pragma once // just do all the includes once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/ArmSubsystem.h"

class AutonomousCommand
        :public frc2:: CommandHelper<frc2::CommandBase, AutonomousCommand> {
    
    public:

        explicit AutonomousCommand (ArmSubsystem* arm) ;
    
    }
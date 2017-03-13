#include "CommandBase.h"

#include <Commands/Scheduler.h>

#include "Subsystems/DriveBase.h"

// Initialize a single static instance of all of your subsystems. The following
// line should be repeated for each subsystem in the project.
//std::unique_ptr<DriveBase> CommandBase::exampleSubsystem = std::make_unique<DriveBase>();

DriveBase* CommandBase::driveBase = NULL;
//GyroCorrection* CommandBase::gyroCorrection = NULL;

std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();

CommandBase::CommandBase(const std::string &name) :frc::Command(name) {

}

void CommandBase::init()
{
	CommandBase::driveBase = new DriveBase();
	//CommandBase::oi = new OI();
	//CommandBase::gyroCorrection = new GyroCorrection();
}

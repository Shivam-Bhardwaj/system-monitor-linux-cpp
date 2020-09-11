#include "system.h"

#include <unistd.h>

#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"
#include "processor.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

// Return the system's CPU
Processor &System::Cpu() { return cpu_; }

// Return a container composed of the system's processes
vector<Process> &System::Processes() {
  UpdateProcesses();
  return processes_;
}

// TO DO: Return the system's kernel identifier (string)
std::string System::Kernel() { return LinuxParser::Kernel(); }

// TO DO: Return the system's memory utilization
float System::MemoryUtilization() { return LinuxParser::MemoryUtilization(); }

// TO DO: Return the operating system name
std::string System::OperatingSystem() { return LinuxParser::OperatingSystem(); }

// TO DO: Return the number of processes actively running on the system
int System::RunningProcesses() { return LinuxParser::RunningProcesses(); }

// TO DO: Return the total number of processes on the system
int System::TotalProcesses() { return LinuxParser::TotalProcesses(); }

// TO DO: Return the number of seconds since the system started running
long int System::UpTime() { return LinuxParser::UpTime(); }

void System::UpdateProcesses() {
  processes_.clear();
  for (int pid : LinuxParser::Pids()) {
    UpdateProcess(pid);
  }
  sort(processes_.begin(), processes_.end());
}

void System::UpdateProcess(int pid) {
  Process process(pid);
  processes_.emplace_back(process);
}

#include "process.h"

#include <unistd.h>

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// Return this process's ID
int Process::Pid() { return _pid; }

// Return this process's CPU utilization
float Process::CpuUtilization() { return _cpuUtilization; }

// Return the command that generated this process
string Process::Command() { return _command; }

// Return this process's memory utilization
string Process::Ram() { return _ram; }

// Return the user (name) that generated this process
string Process::User() { return _user; }

// Return the age of this process (in seconds)
long int Process::UpTime() { return _upTime; }

// Overloading the "less than" comparison operator for Process objects

bool Process::operator<(Process const &a) const {
  if (_cpuUtilization > a._cpuUtilization)
    return true;
  else
    return false;
}

Process::Process(int pid) {
  _pid = pid;
  _user = LinuxParser::User(_pid);
  _command = LinuxParser::Command(_pid);
  _ram = LinuxParser::Ram(_pid);
  _upTime = LinuxParser::UpTime(_pid);
  _cpuUtilization = LinuxParser::CpuUtilization(_pid);
}

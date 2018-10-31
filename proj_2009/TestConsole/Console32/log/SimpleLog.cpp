#include "SimpleLog.h"
#include <time.h>  
#include <fstream>


SimpleLog* SimpleLog::instance = nullptr;
SimpleLog::SimpleLog(void) 
{
  current_log_type = LOG_TYPE_DEBUG | LOG_TYPE_INFO | LOG_TYPE_WARNING | LOG_TYPE_ERROR;
}

SimpleLog::~SimpleLog(void) 
{
  if (instance == nullptr) return; 
  delete this;
}

void SimpleLog::save_log(int log_type, const std::string& data) 
{
  if ((current_log_type & log_type) == 0) return;

  time_t tt = time(0);  
  char time_format[255] = {0};  
  strftime(time_format, sizeof(time_format), "%Y-%m-%d %H:%M:%S ", localtime(&tt));

  const std::string log_info = std::string(time_format).append(type_string(log_type)).append(" ").append(data);
  std::ofstream myFile;
  myFile.open(log_path.c_str(), std::ios::app);
  myFile.write(log_info.c_str(), log_info.size());
  myFile << std::endl;
  myFile.close();
}

void SimpleLog::config_log_file_path(const std::string file_path) {
  log_path = file_path;
}

void SimpleLog::config_log_type(int type) {
  current_log_type = type;
}

std::string SimpleLog::type_string(int type) 
{
  switch (type)
  {
  case LOG_TYPE_DEBUG : 
	  return "DEBUG"; 
	  break;
  case LOG_TYPE_INFO : 
	  return "INFO"; 
	  break;
  case LOG_TYPE_WARNING : 
	  return "WARNING"; 
	  break;
  case LOG_TYPE_ERROR : 
	  return "ERROR"; 
	  break;
  }

  return "";
}

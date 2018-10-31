#ifndef SIMPLE_LOG_H_9BB1907A_6178_49AD_8525_C892710EFC20
#define SIMPLE_LOG_H_9BB1907A_6178_49AD_8525_C892710EFC20
#include <string>

#define LOG_TYPE_DEBUG  1
#define LOG_TYPE_INFO   2
#define LOG_TYPE_WARNING  4
#define LOG_TYPE_ERROR  8

#ifndef nullptr
#define nullptr 0
#endif

class SimpleLog {
public:
  SimpleLog(void);
  ~SimpleLog(void);

  static SimpleLog* getInstance() {
  if (instance == nullptr) {
    instance = new SimpleLog();
  }
  return instance;
  }

  void save_log(int log_type, const std::string& data);

  void config_log_file_path(const std::string file_path);

  void config_log_type(int type);

protected:
  std::string type_string(int type);

private:
  static SimpleLog* instance;
  int current_log_type;
  std::string log_path;
};

#endif
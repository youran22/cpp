// SouthgnssTestProtoJson.cpp : 定义控制台应用程序的入口点。

#include <tchar.h>
#include <string>
#include <direct.h>
#include <fstream>
#include "google\protobuf\util\json_util.h"
#include "../common/conv/GlobalData.h"
//#include "../SouthgnssTestProtoJson/message3/MessageJkConfig.pb.h"
//#include "../SouthgnssJudge3/proto/MessageKm3Config.pb.h"
#include "message3/MessageJkConfig.pb.h"
#include "message3/MessageKm3Config.pb.h"


void message_to_json(google::protobuf::Message& message, const std::string &pathIn, const std::string &pathOut)
{
	//读取文件
  std::ifstream is(pathIn.c_str(), std::ios::in|std::ios::binary);
  message.ParseFromIstream(&is);
  is.close();

  std::string json;
  google::protobuf::util::JsonOptions printJsonoptions; printJsonoptions.always_print_primitive_fields = true;
  google::protobuf::util::MessageToJsonString(message, &json, printJsonoptions);

  std::ofstream os(pathOut.c_str(), std::ios::out|std::ios::binary);
  os.write(json.c_str(), json.length());

  os.close();
}

void creat_coreinfo_json(const std::string &pathIn, const std::string &pathOut)
{
  OPMessage::CoreInfo message;
  message_to_json(message, pathIn, pathOut);
}

void creat_km3judge_json(const std::string &pathIn, const std::string &pathOut)
{
  OPMessage::Km3Judge message;
  message_to_json(message, pathIn, pathOut);
}

int test_protojson()
{
  char _cwd[1000];
  std::string workdir = _getcwd(_cwd, sizeof(_cwd)) + std::string("\\..\\..\\TestData\\");
  std::string pathInCore = workdir + "config.pta";
  std::string pathOutCore = workdir + "_pat_config.json";

  creat_coreinfo_json(pathInCore, pathOutCore);

  std::string pathInKm3 = workdir + "km3judge.pta";
  std::string pathOutKm3 = workdir + "_pat_km3duge.json";

  creat_km3judge_json(pathInKm3, pathOutKm3);
	return 0;
}


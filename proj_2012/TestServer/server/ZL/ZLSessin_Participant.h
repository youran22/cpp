#pragma once

#include "boost/asio.hpp"
#include "ZLPacket.h"

class ZLSessin_Participant
{
public:
	virtual ~ZLSessin_Participant() {}
	virtual void deliver(const ZLPacket& msg) = 0; //������Ҫ����
};

typedef boost::shared_ptr<ZLSessin_Participant> session_participant_ptr;
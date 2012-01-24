#include "Network.h"

using namespace OS;
using namespace UAV;

Network::Network(const IPAddress bindAddress)
	: bindAddress(bindAddress)
{

}

bool Network::sendImage(const Image & image)
{
	// TODO: send image
	return true;
}

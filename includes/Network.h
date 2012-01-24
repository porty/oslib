#pragma once

#include "Image.h"
#include "macros.h"
#include "IPAddress.h"

#include <stdint.h>

namespace UAV
{
	class Network
	{
	public:

		/**
		 * Create a new network object.
		 *
		 * @param The IP address to bind to
		 */
		Network(const OS::IPAddress bindAddress);

		/**
		 * Send the specified image to the host specified in the settings.
		 *
		 * @param image The image stuffs to send
		 * @return True if worked, false otherwise
		 */
		// TODO: bool return value is fairly dodgy - maybe throw exceptions??
		bool sendImage(const Image & image);

		const OS::IPAddress & getBindAddress() const { return bindAddress; }

	private:
		/**
		 * The IP address that all network stuffs will be locally bound to.
		 */
		const OS::IPAddress bindAddress;

	private: // not to be implemented
		NO_COPY_CONSTRUCTOR(Network);
		NO_ASSIGNMENT_OPERATOR(Network);
	};
}

#pragma once

namespace OS
{
	/**
	 * Atomically incrementable/decrementable 32-bit integer.
	 *
	 * @author Shorty
	 */
	class AtomicInt32
	{
	public:
		/**
		 * Create atomic int with default value of 0.
		 */
		AtomicInt32(): value(0) {}

		/**
		 * Create atomic int with a given start value.
		 */
		AtomicInt32(unsigned long start): value(start) {}

		/**
		 * Increment and return the result atomically.
		 */
		unsigned long operator ++();

		/**
		 * Decrement and return the result atomically.
		 */
		unsigned long operator --();

	private:
		/** The value. */
		volatile unsigned long value;
	};
}

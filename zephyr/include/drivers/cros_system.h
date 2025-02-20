/* Copyright 2021 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**
 * @file
 * @brief Public API for cros system drivers
 */

#ifndef ZEPHYR_INCLUDE_DRIVERS_CROS_SYSTEM_H_
#define ZEPHYR_INCLUDE_DRIVERS_CROS_SYSTEM_H_

/**
 * @brief cros system Interface
 * @defgroup cros_system_interface cros system Interface
 * @ingroup io_interfaces
 * @{
 */

#include <kernel.h>
#include <device.h>

/**
 * @brief system_reset_cause enum
 * Identify the reset cause.
 */
enum system_reset_cause {
	/* the reset is triggered by VCC power-up */
	POWERUP = 0,
	/* the reset is triggered by external VCC1 reset pin */
	VCC1_RST_PIN = 1,
	/* the reset is triggered by ICE debug reset request */
	DEBUG_RST = 2,
	/* the reset is triggered by watchdog */
	WATCHDOG_RST = 3,
	/* unknown reset type */
	UNKNOWN_RST,
};

/**
 * @typedef cros_system_get_reset_cause_api
 * @brief Callback API for getting reset cause instance.
 * See cros_system_get_reset_cause() for argument descriptions
 */
typedef int (*cros_system_get_reset_cause_api)(const struct device *dev);

/**
 * @typedef cros_system_soc_reset_api
 * @brief Callback API for soc-reset instance.
 * See cros_system_soc_reset() for argument descriptions
 */
typedef int (*cros_system_soc_reset_api)(const struct device *dev);

/**
 * @typedef cros_system_hibernate_api
 * @brief Callback API for entering hibernate state (lowest EC power state).
 * See cros_system_hibernate() for argument descriptions
 */
typedef int (*cros_system_hibernate_api)(const struct device *dev,
					 uint32_t seconds,
					 uint32_t microseconds);

/**
 * @typedef cros_system_chip_vendor_api
 * @brief Callback API for getting the chip vendor.
 * See cros_system_chip_vendor() for argument descriptions
 */
typedef const char *(*cros_system_chip_vendor_api)(const struct device *dev);

/**
 * @typedef cros_system_chip_name_api
 * @brief Callback API for getting the chip name.
 * See cros_system_chip_name() for argument descriptions
 */
typedef const char *(*cros_system_chip_name_api)(const struct device *dev);

/**
 * @typedef cros_system_chip_revision_api
 * @brief Callback API for getting the chip revision.
 * See cros_system_chip_revision() for argument descriptions
 */
typedef const char *(*cros_system_chip_revision_api)(const struct device *dev);

/** @brief Driver API structure. */
__subsystem struct cros_system_driver_api {
	cros_system_get_reset_cause_api get_reset_cause;
	cros_system_soc_reset_api soc_reset;
	cros_system_hibernate_api hibernate;
	cros_system_chip_vendor_api chip_vendor;
	cros_system_chip_name_api chip_name;
	cros_system_chip_revision_api chip_revision;
};

/**
 * @brief Get the chip-reset cause
 *
 * @param dev Pointer to the device structure for the driver instance.
 *
 * @retval non-negative if successful.
 * @retval Negative errno code if failure.
 */
__syscall int cros_system_get_reset_cause(const struct device *dev);

static inline int z_impl_cros_system_get_reset_cause(const struct device *dev)
{
	const struct cros_system_driver_api *api =
		(const struct cros_system_driver_api *)dev->api;

	if (!api->get_reset_cause) {
		return -ENOTSUP;
	}

	return api->get_reset_cause(dev);
}

/**
 * @brief reset the soc
 *
 * @param dev Pointer to the device structure for the driver instance.
 *
 * @retval no return if successful.
 * @retval Negative errno code if failure.
 */
__syscall int cros_system_soc_reset(const struct device *dev);

static inline int z_impl_cros_system_soc_reset(const struct device *dev)
{
	const struct cros_system_driver_api *api =
		(const struct cros_system_driver_api *)dev->api;

	if (!api->soc_reset) {
		return -ENOTSUP;
	}

	return api->soc_reset(dev);
}

/**
 * @brief put the EC in hibernate (lowest EC power state).
 *
 * @param dev Pointer to the device structure for the driver instance.
 * @param seconds Number of seconds before EC enters hibernate state.
 * @param microseconds Number of micro-secs before EC enters hibernate state.

 * @retval no return if successful.
 * @retval Negative errno code if failure.
 */
__syscall int cros_system_hibernate(const struct device *dev, uint32_t seconds,
				    uint32_t microseconds);

static inline int z_impl_cros_system_hibernate(const struct device *dev,
					       uint32_t seconds,
					       uint32_t microseconds)
{
	const struct cros_system_driver_api *api =
		(const struct cros_system_driver_api *)dev->api;

	if (!api->hibernate) {
		return -ENOTSUP;
	}

	return api->hibernate(dev, seconds, microseconds);
}

/**
 * @brief Get the chip vendor.
 *
 * @param dev Pointer to the device structure for the driver instance.
 * @retval Chip vendor string if successful.
 * @retval Null string if failure.
 */
__syscall const char *cros_system_chip_vendor(const struct device *dev);

static inline const char *
z_impl_cros_system_chip_vendor(const struct device *dev)
{
	const struct cros_system_driver_api *api =
		(const struct cros_system_driver_api *)dev->api;

	if (!api->chip_vendor) {
		return "";
	}

	return api->chip_vendor(dev);
}

/**
 * @brief Get the chip name.
 *
 * @param dev Pointer to the device structure for the driver instance.
 * @retval Chip name string if successful.
 * @retval Null string if failure.
 */
__syscall const char *cros_system_chip_name(const struct device *dev);

static inline const char *z_impl_cros_system_chip_name(const struct device *dev)
{
	const struct cros_system_driver_api *api =
		(const struct cros_system_driver_api *)dev->api;

	if (!api->chip_name) {
		return "";
	}

	return api->chip_name(dev);
}

/**
 * @brief Get the chip revision.
 *
 * @param dev Pointer to the device structure for the driver instance.
 * @retval Chip revision string if successful.
 * @retval Null string if failure.
 */
__syscall const char *cros_system_chip_revision(const struct device *dev);

static inline const char *
z_impl_cros_system_chip_revision(const struct device *dev)
{
	const struct cros_system_driver_api *api =
		(const struct cros_system_driver_api *)dev->api;

	if (!api->chip_revision) {
		return "";
	}

	return api->chip_revision(dev);
}

/**
 * @}
 */
#include <syscalls/cros_system.h>
#endif /* ZEPHYR_INCLUDE_DRIVERS_CROS_SYSTEM_H_ */

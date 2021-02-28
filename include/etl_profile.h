#ifndef __ETL_PROFILE_H__
#define __ETL_PROFILE_H__

#define ETL_VERBOSE_ERRORS
#define ETL_CHECK_PUSH_POP

// Arudino itself does not support STL, we use
// the reverse engineered version of STL from ETL.
#define ETL_NO_STL

#define ETL_TARGET_OS_FREERTOS // Placeholder. Not currently utilised in the ETL
#define ETL_TARGET_DEVICE_ARM  // Placeholder. Not currently utilised in the ETL

#endif

/* See LICENSE file for license and copyright information */

#ifndef GIRARA_SETTINGS_H
#define GIRARA_SETTINGS_H

#include "types.h"

/**
 * Adds an additional entry in the settings list
 *
 * @param session The used girara session
 * @param name The name of the setting
 * @param value The value of the setting
 * @param type The type of the setting
 * @param init_only Will only available on initialization
 * @param description Description of the setting
 * @param callback Function that is called when the setting changes
 * @param data Arbitary data that can be used by callbacks
 * @return TRUE No error occured
 * @return FALSE An error occured
 */
bool girara_setting_add(girara_session_t* session, const char* name, void* value, girara_setting_type_t type, bool init_only, const char* description, girara_setting_callback_t callback, void* data);

/**
 * Sets the value of a setting
 *
 * @param session The used girara session
 * @param name The name of the setting
 * @param value The new value of the setting
 * @return TRUE No error occured
 * @return FALSE An error occured
 */
bool girara_setting_set(girara_session_t* session, const char* name, void* value);

/**
 * Retreives the value of a setting. The returned value needs to be freed with
 * g_free.
 *
 * @param session The used girara session
 * @param name The name of the setting
 * @return Value of the setting
 * @return NULL An error occured
 */
void* girara_setting_get(girara_session_t* session, const char* name);

/**
 * Find a setting.
 *
 * @param session The girara session
 * @param name name of the setting
 * @return the setting or NULL if it doesn't exist
 */
girara_setting_t* girara_setting_find(girara_session_t* session, const char* name);

/**
 * Get the setting's name.
 *
 * @param setting The setting
 * @return the setting's name
 */
const char* girara_setting_get_name(girara_setting_t* setting);

/**
 * Get the setting's value.
 *
 * @param setting The setting
 * @return pointer to the value, this has to freed with g_free when you're done
 */
void* girara_setting_get_value(girara_setting_t* setting);

/**
 * Get the setting's value.
 *
 * @param setting The setting
 * @return the value
 */
girara_setting_type_t girara_setting_get_type(girara_setting_t* setting);

/**
 * Set the setting's value. If session is NULL, the setting's callback won't be
 * called.
 *
 * @param session The girara session
 * @param setting The setting
 * @param value The new value
 */
void girara_setting_set_value(girara_session_t* session, girara_setting_t* setting, void* value);


#endif

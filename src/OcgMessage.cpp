/*
 * OcgMessage.cpp
 *
 *  Created on: Jul 19, 2015
 *      Author: felix
 */

#include <OcgMessage.hpp>

#include <assert.h>
#include <stdio.h>

namespace meteor {
	namespace ocg {
		BODY_FIELDS_MAP_INIT_BEGIN(lookup_request)
		BODY_FIELDS_MAP_INIT_ADD_FIELD(lookup_request, type_of_service)
		BODY_FIELDS_MAP_INIT_ADD_FIELD(lookup_request, protocol_type)
		BODY_FIELDS_MAP_INIT_END

		BODY_FIELDS_MAP_INIT_BEGIN(lookup_response) BODY_FIELDS_MAP_INIT_ADD_FIELD(lookup_response, status)
		BODY_FIELDS_MAP_INIT_ADD_FIELD(lookup_response, lookup_reject_code)
		BODY_FIELDS_MAP_INIT_ADD_FIELD(lookup_response, reason)
		BODY_FIELDS_MAP_INIT_ADD_FIELD(lookup_response, primary_ip)
		BODY_FIELDS_MAP_INIT_ADD_FIELD(lookup_response, primary_port)
		BODY_FIELDS_MAP_INIT_ADD_FIELD(lookup_response, secondary_ip)
		BODY_FIELDS_MAP_INIT_ADD_FIELD(lookup_response, secondary_port)
		BODY_FIELDS_MAP_INIT_END
	}
}
